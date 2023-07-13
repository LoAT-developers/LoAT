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
#include "z3_opt.hpp"
#include "z3.hpp"

const bool ABMC::max_smt {false};
const bool ABMC::optimize {false};

ABMC::ABMC(const ITSProblem &its):
    its(its),
    vars(its.getVars()),
    trace_var(NumVar::next()),
    objective_var(NumVar::next()){
    if (max_smt || optimize) {
        solver = std::make_unique<Z3Opt<IntTheory, BoolTheory>>(smt::default_timeout);
        if (optimize) {
            solver->add_objective(objective_var);
        }
    } else {
        solver = std::make_unique<Z3<IntTheory, BoolTheory>>(smt::default_timeout);
    }
    vars.insert(trace_var);
    for (const auto &var: vars) {
        post_vars.emplace(var, expr::next(var));
    }
    solver->enableModels();
}

bool ABMC::is_orig_clause(const TransIdx idx) const {
    return idx <= last_orig_clause;
}

std::optional<unsigned> ABMC::has_looping_suffix(unsigned start, std::optional<Automaton> &lang) {
    const auto last_clause = trace.back();
    for (int pos = start, length = trace.size() - pos; pos >= lookback + length; --pos, ++length) {
        const auto &idx {trace[pos]};
        if (!lang) {
            lang = get_language(pos);
        } else {
            lang->concat(get_language(pos));
        }
        if (its.areAdjacent(last_clause, idx)) {
            const auto length {trace.size() - pos};
            auto prev_lang {get_language(pos - 1)};
            auto upos = static_cast<unsigned>(pos);
            for (int prev_pos = pos - 2; prev_pos + length >= upos; --prev_pos) {
                prev_lang.concat(get_language(prev_pos));
            }
            std::cout << "lang: " << lang->to_string() << std::endl;
            std::cout << "prev lang: " << prev_lang.to_string() << std::endl;
            if (lang->to_string() == prev_lang.to_string()) {
                return upos;
            }
        }
    }
    return {};
}

Automaton ABMC::get_language(unsigned i) {
    const auto idx {trace[i]};
    if (is_orig_clause(idx)) {
        const auto rule {its.getRule(idx)};
        const auto model {solver->model(rule.subs(subs[i]).vars()).toSubs()};
        const auto imp {rule.getGuard()->implicant(expr::compose(subs[i], model))};
        if (!imp) {
            throw std::logic_error("model, but no implicant");
        }
        return red.get_singleton_language(idx, BExpression::buildAndFromLits(*imp)->conjunctionToGuard());
    } else {
        return *red.get_language(idx);
    }
}

std::pair<Rule, Subs> ABMC::build_loop(const int backlink) {
    std::optional<Rule> loop;
    Subs var_renaming;
    for (int i = trace.size() - 1; i >= backlink; --i) {
        const auto idx {trace[i]};
        const auto rule {its.getRule(idx)};
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
    expr::collectCoDomainVars(var_renaming, vars);
    const auto model {expr::compose(var_renaming, solver->model(vars).toSubs())};
    const auto imp {loop->getGuard()->implicant(model)};
    if (!imp) {
        throw std::logic_error("model, but no implicant");
    }
    const auto implicant {loop->withGuard(BExpression::buildAndFromLits(*imp))};
    if (Config::Analysis::log) {
        std::cout << "found loop of length " << (trace.size() - backlink) << ":" << std::endl;
        ITSExport::printRule(implicant, std::cout);
        std::cout << std::endl;
    }
    return {implicant, model};
}

TransIdx ABMC::add_learned_clause(const Rule &accel, const unsigned backlink) {
    return its.addLearnedRule(accel, trace.at(backlink), trace.back());
}

bool ABMC::handle_loop(int backlink, Automaton lang) {
    auto [loop, sample_point] {build_loop(backlink)};
    if (is_orig_clause(trace.back()) || !red.is_redundant(lang)) {
        const auto simp {Preprocess::preprocessRule(loop)};
        if (Config::Analysis::reachability() && simp->getUpdate() == expr::concat(simp->getUpdate(), simp->getUpdate())) {
            // The learned     return is_orig_clause(idx) ?  : ;clause would be trivially redundant w.r.t. the looping suffix (but not necessarily w.r.t. a single clause).
            // Such clauses are pretty useless, so we do not store them.
            if (Config::Analysis::log) std::cout << "acceleration would yield equivalent rule" << std::endl;
        } else {
            if (Config::Analysis::log && simp) {
                std::cout << "simplified loop:" << std::endl;
                ITSExport::printRule(*simp, std::cout);
                std::cout << std::endl;
            }
            if (Config::Analysis::reachability() && simp->getUpdate().empty()) {
                if (Config::Analysis::log) std::cout << "trivial looping suffix" << std::endl;
            } else {
                AccelConfig config {.allowDisjunctions = false, .tryNonterm = Config::Analysis::tryNonterm()};
                const auto accel_res {LoopAcceleration::accelerate(*simp, sample_point, config)};
                if (accel_res.accel) {
                    auto simplified = Preprocess::preprocessRule(accel_res.accel->rule);
                    if (simplified->getUpdate() != simp->getUpdate() && simplified->isPoly()) {
                        const auto new_idx {add_learned_clause(*simplified, backlink)};
                        n = *accel_res.n;
                        vars.insert(*n);
                        post_vars.emplace(*n, NumVar::next());
                        shortcut = encode_transition(new_idx);
                        if (Config::Analysis::log) {
                            std::cout << "learned clause:" << std::endl;
                            std::cout << *simplified << std::endl;
                        }
                        red.transitive_closure(lang);
                        red.mark_as_redundant(lang);
                        red.set_language(new_idx, lang);
                        return true;
                    }
                }
            }
        }
    }
    return false;
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
    if (Config::Analysis::log) {
        std::cout << "initial ITS" << std::endl;
        its.print(std::cout);
    }
    const auto res {Preprocess::preprocess(its)};
    if (Config::Analysis::log && res) {
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
    solver->add(BExpression::buildOr(inits));

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
        if (Config::Analysis::log) {
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
        solver->push();
        solver->add(query->subs(s));
        switch (solver->check()) {
        case SmtResult::Sat:
            std::cout << "unsat" << std::endl;
            return;
        case SmtResult::Unknown:
            if (Config::Analysis::log && !approx) {
                std::cout << "got unknown from SMT solver -- approximating" << std::endl;
            }
            approx = true;
            break;
        case SmtResult::Unsat: {}
        }
        solver->pop();
        if (shortcut->isTriviallyTrue()) {
            solver->add(step->subs(s));
        } else {
            const auto sc {shortcut->subs(s)};
            if (max_smt) {
                solver->add_soft(sc);
            }
            if (optimize) {
                objective = objective + *n;
                solver->add(sc | (expr::mkEq(*n, 0) & step->subs(s)));
            } else {
                solver->add(sc | step->subs(s));
            }
        }
        if (optimize) {
            solver->push();
            solver->add(expr::mkEq(objective_var, objective));
        }
        subs.push_back(s);
        switch (solver->check()) {
        case SmtResult::Unsat:
            if (!approx) {
                std::cout << "sat" << std::endl;
            }
            return;
        case SmtResult::Sat: {
            shortcut = True;
            trace.clear();
            const auto model {solver->model(trace_vars).toSubs().get<IntTheory>()};
            for (const auto &s: subs) {
                trace.push_back(s.get<IntTheory>(trace_var).subs(model).toNum().to_int());
            }
            if (Config::Analysis::log) {
                std::cout << "trace: " << trace << std::endl;
            }
            auto lang {std::optional<Automaton>()};
            for (auto backlink = has_looping_suffix(trace.size() - 1, lang);
                 backlink;
                 backlink = has_looping_suffix(*backlink - 1, lang)) {
                if (handle_loop(*backlink, *lang)) {
                    lookback = trace.size();
                    break;
                }
            }
            break;
        }
        case SmtResult::Unknown:
            shortcut = True;
            trace.clear();
        }
        if (optimize) {
            solver->pop();
        }
    }

}

void ABMC::analyze(const ITSProblem &its) {
    ABMC(its).analyze();
}
