#include "abmc.hpp"
#include "chain.hpp"
#include "expr.hpp"
#include "preprocessing.hpp"
#include "rulepreprocessing.hpp"
#include "smtfactory.hpp"
#include "loopacceleration.hpp"
#include "config.hpp"
#include "export.hpp"
#include "vector.hpp"

const bool ABMC::log {false};

ABMC::ABMC(const ITSProblem &its):
    its(its),
    vars(its.getVars()),
    trace_var(NumVar::next()) {
    vars.insert(trace_var);
    for (const auto &var: vars) {
        post_vars.emplace(var, expr::next(var));
    }
    z3.enableModels();
}

bool ABMC::is_orig_clause(const TransIdx idx) const {
    return idx <= last_orig_clause;
}

std::optional<unsigned> ABMC::has_looping_suffix(unsigned start) {
    if (trace.empty()) {
        return {};
    }
    const auto last_clause = trace.back();
    std::vector<long> sequence;
    for (int pos = start; pos >= lookback; --pos) {
        const auto &idx {trace[pos]};
        if (its.areAdjacent(last_clause, idx)) {
            auto upos = static_cast<unsigned>(pos);
            bool looping = upos < trace.size() - 1 || is_orig_clause(idx);
            if (looping) {
                return upos;
            }
        }
    }
    return {};
}

std::tuple<Rule, Subs, ABMC::Key> ABMC::build_loop(const int backlink) {
    std::optional<Rule> loop;
    Subs var_renaming;
    std::vector<unsigned> run;
    for (int i = trace.size() - 1; i >= backlink; --i) {
        const auto idx {trace[i]};
        const auto rule {its.getRule(idx)};
        run.push_back(idx);
        if (loop) {
            const auto [chained, sigma] {Chaining::chain(rule, *loop)};
            loop = chained;
            var_renaming = expr::compose(sigma, var_renaming);
        } else {
            loop = rule;
        }
        var_renaming = expr::compose(subs[i].project(rule.vars()), var_renaming);
    }
    auto vars {loop->vars()};
    var_renaming = var_renaming.project(vars);
    expr::collectCoDomainVars(var_renaming, vars);
    const auto model {expr::compose(var_renaming, z3.model(vars).toSubs())};
    const auto imp {loop->getGuard()->implicant(model)};
    if (!imp) {
        throw std::logic_error("model, but no implicant");
    }
    const auto implicant {loop->withGuard(BExpression::buildAndFromLits(*imp))};
    if (log) {
        std::cout << "found loop of length " << (trace.size() - backlink) << ":" << std::endl;
        ITSExport::printRule(implicant, std::cout);
        std::cout << std::endl;
    }
    return {implicant, model, {run, *imp}};
}

TransIdx ABMC::add_learned_clause(const Rule &accel, const unsigned backlink) {
    return its.addLearnedRule(accel, trace.at(backlink), trace.back());
}

bool ABMC::handle_loop(int backlink) {
    const auto [loop, sample_point, key] {build_loop(backlink)};
    auto it {cache.find(key)};
    if (it == cache.end()) {
        const auto simp {Preprocess::preprocessRule(loop)};
        if (Config::Analysis::reachability() && simp->getUpdate() == expr::concat(simp->getUpdate(), simp->getUpdate())) {
            // The learned clause would be trivially redundant w.r.t. the looping suffix (but not necessarily w.r.t. a single clause).
            // Such clauses are pretty useless, so we do not store them.
            if (log) std::cout << "acceleration would yield equivalent rule" << std::endl;
        } else {
            if (log && simp) {
                std::cout << "simplified loop:" << std::endl;
                ITSExport::printRule(*simp, std::cout);
                std::cout << std::endl;
            }
            if (Config::Analysis::reachability() && simp->getUpdate().empty()) {
                if (log) std::cout << "trivial looping suffix" << std::endl;
            } else {
                AccelConfig config {.allowDisjunctions = false, .tryNonterm = Config::Analysis::tryNonterm()};
                const auto accel_res {LoopAcceleration::accelerate(*simp, sample_point, config)};
                if (accel_res.accel) {
                    auto simplified = Preprocess::preprocessRule(accel_res.accel->rule);
                    if (simplified->getUpdate() != simp->getUpdate() && simplified->isPoly()) {
                        const auto new_idx {add_learned_clause(*simplified, backlink)};
                        vars.insert(*accel_res.n);
                        post_vars.emplace(*accel_res.n, NumVar::next());
                        it = cache.emplace(key, new_idx).first;
                        if (log) {
                            std::cout << "learned clause:" << std::endl;
                            std::cout << *simplified << std::endl;
                        }
                    }
                }
            }
        }
    }
    if (it == cache.end()) {
        it = cache.emplace(key, std::optional<TransIdx>()).first;
    } else if (it->second) {
        shortcuts.emplace_back(encode_transition(*it->second));
    }
    return it->second.has_value();
}

BoolExpr ABMC::encode_transition(const TransIdx idx) {
    const Rule r {its.getRule(idx)};
    const auto up {r.getUpdate()};
    std::vector<BoolExpr> res {r.getGuard()};
    res.emplace_back(BExpression::buildTheoryLit(Rel::buildEq(trace_var, idx)));
    for (const auto &x: vars) {
        if (expr::isProgVar(x)) {
            res.push_back(expr::mkEq(expr::toExpr(post_vars.at(x)), up.get(x)));
        }
    }
    return BExpression::buildAnd(res);
}

void ABMC::analyze() {
    if (log) {
        its.print(std::cout);
    }
    const auto res {Preprocess::preprocess(its)};
    if (log && res) {
        res.print();
    }
    last_orig_clause = *its.getAllTransitions().rbegin();
    std::vector<BoolExpr> inits;
    for (const auto &idx: its.getInitialTransitions()) {
        if (its.isSinkTransition(idx)) {
            switch (SmtFactory::check(its.getRule(idx).getGuard())) {
            case SmtResult::Sat:
                std::cout << "unsat" << std::endl;
                return;
            case SmtResult::Unknown:
                approx = true;
                break;
            case SmtResult::Unsat: {}
            }
        } else {
            inits.push_back(encode_transition(idx));
        }
    }
    z3.add(BExpression::buildOr(inits));

    std::vector<BoolExpr> steps;
    for (const auto &idx: its.getAllTransitions()) {
        if (its.isInitialTransition(idx) || its.isSinkTransition(idx)) {
            continue;
        }
        steps.push_back(encode_transition(idx));
    }
    const auto step {BExpression::buildOr(steps)};

    std::vector<BoolExpr> queries;
    for (const auto &idx: its.getSinkTransitions()) {
        if (!its.isInitialTransition(idx)) {
            const auto r {its.getRule(idx)};
            queries.push_back(r.getGuard());
        }
    }
    const auto query {BExpression::buildOr(queries)};

    unsigned depth {1};
    VarSet trace_vars;
    trace_vars.insert(trace_var);
    trace_vars.insert(post_vars.at(trace_var));
    while (true) {
        if (log) {
            std::cout << "depth: " << depth << std::endl;
            ++depth;
        }
        Subs s;
        for (const auto &var: vars) {
            const auto &post_var {post_vars.at(var)};
            s.put(var, subs.back().get(post_var));
            const auto next {expr::next(post_var)};
            if (var == Var(trace_var)) {
                trace_vars.insert(next);
            }
            s.put(post_var, expr::toExpr(next));
        }
        z3.push();
        z3.add(query->subs(s));
        switch (z3.check()) {
        case SmtResult::Sat:
            std::cout << "unsat" << std::endl;
            return;
        case SmtResult::Unknown:
            approx = true;
            break;
        case SmtResult::Unsat: {}
        }
        z3.pop();
        shortcuts.emplace_back(step);
        z3.add(BExpression::buildOr(shortcuts)->subs(s));
        switch (z3.check()) {
        case SmtResult::Unsat:
            if (!approx) {
                std::cout << "sat" << std::endl;
            }
            return;
        case SmtResult::Sat: {
            shortcuts.clear();
            trace.clear();
            const auto model {z3.model(trace_vars).toSubs().get<IntTheory>()};
            for (const auto &s: subs) {
                trace.push_back(s.get<IntTheory>(trace_var).subs(model).toNum().to_int());
            }
            for (auto backlink = has_looping_suffix(trace.size() - 1);
                 backlink;
                 backlink = has_looping_suffix(*backlink - 1)) {
                if (handle_loop(*backlink)) {
                    lookback = trace.size();
                    break;
                }
            }
            break;
        }
        case SmtResult::Unknown:
            shortcuts.clear();
            trace.clear();
        }
        subs.push_back(s);
    }

}

void ABMC::analyze(const ITSProblem &its) {
    ABMC(its).analyze();
}
