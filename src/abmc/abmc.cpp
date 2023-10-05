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
#include "z3.hpp"
#include "cvc5.hpp"
#include "rule.hpp"
#include "dependencygraph.hpp"
#include "linearizingsolver.hpp"
#include "z3inclin.hpp"

using namespace Config::ABMC;

ABMC::ABMC(ITSProblem &its):
    its(its),
    trace_var(NumVar::next()) {
    switch (Config::Analysis::smtSolver) {
    case Config::Analysis::Z3:
        solver = std::unique_ptr<Smt<IntTheory, BoolTheory>>(new Z3<IntTheory, BoolTheory>(smt::default_timeout));
        break;
    case Config::Analysis::CVC5:
        solver = std::unique_ptr<Smt<IntTheory, BoolTheory>>(new CVC5<IntTheory, BoolTheory>());
        break;
    case Config::Analysis::Z3Lin:
        solver = std::unique_ptr<Smt<IntTheory, BoolTheory>>(new LinearizingSolver<IntTheory, BoolTheory>(smt::default_timeout));
        break;
    case Config::Analysis::Z3IncLin:
        solver = std::unique_ptr<Smt<IntTheory, BoolTheory>>(new Z3IncLin<IntTheory, BoolTheory>());
        break;
    }
    vars.insert(trace_var);
    vars.insert(n);
    solver->enableModels();
}

bool ABMC::is_orig_clause(const TransIdx idx) const {
    return idx->getId() <= last_orig_clause;
}

bool ends_with_square(const std::vector<int> &w) {
    const auto it {w.rbegin()};
    const auto size {w.size()};
    const auto max_length {size / 2};
    auto start {it};
    auto end {it};
    for (auto length = 1u; length <= max_length; ++length) {
        ++end;
        if (std::equal(start, end, end)) {
            return true;
        }
    }
    return false;
}

bool ABMC::is_redundant(const std::vector<int> &ww) const {
    auto it {ww.begin()};
    const auto size {ww.size() / 2};
    for (auto i = 0u; i < size; ++i, ++it) {
        auto h {history.find(*it)};
        if (h != history.end()) {
            auto next {it};
            ++next;
            if (h->second.size() == size - 1 && std::equal(h->second.begin(), h->second.end(), next)) {
                return true;
            }
        }
    }
    return false;
}

std::optional<unsigned> ABMC::has_looping_suffix(unsigned start, std::vector<int> &lang) {
    const auto last {trace.back()};
    for (unsigned pos = start; pos > 0; --pos) {
        lang.push_back(get_language(pos));
        if (ends_with_square(lang)) {
            if (Config::Analysis::log) std::cout << "skipping square " << lang << std::endl;
            return {};
        } else {
            if (Config::Analysis::log) std::cout << lang << " does not have a square" << std::endl;
        }
        const auto &imp {trace[pos]};
        if (dependency_graph.hasEdge(last, imp)) {
            std::vector<int> ll{lang.begin(), lang.end()};
            ll.insert(ll.end(), lang.begin(), lang.end());
            if (is_redundant(ll)) {
                if (Config::Analysis::log) std::cout << "skipping redundant loop" << std::endl;
            } else {
                return pos;
            }
        }
    }
    return {};
}

int ABMC::get_language(unsigned i) {
    const auto imp {trace[i]};
    if (is_orig_clause(imp.first)) {
        const auto res {lang_map.emplace(imp, next)};
        if (res.second) {
            ++next;
        }
        return res.first->second;
    } else {
        return lang_map.at({imp.first, {}});
    }
}

std::tuple<Rule, Subs, bool> ABMC::build_loop(const int backlink) {
    std::optional<Rule> loop;
    Subs var_renaming;
    bool nested {false};
    for (int i = trace.size() - 1; i >= backlink; --i) {
        const auto imp {trace[i]};
        nested |= is_orig_clause(imp.first);
        const auto rule {imp.first
                            ->withGuard(imp.second)
                            .subs(Subs::build<IntTheory>(n, subs.at(i).get<IntTheory>(n)))};
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
    const auto implicant {loop->withGuard(*imp)};
    if (Config::Analysis::log) {
        std::cout << "found loop of length " << (trace.size() - backlink) << ":" << std::endl;
        ITSExport::printRule(implicant, std::cout);
        std::cout << std::endl;
    }
    return {implicant, model, nested};
}

BoolExpr ABMC::build_blocking_clause(const int backlink, const Loop &loop) {
    if (!blocking_clauses || loop.prefix > 1 || loop.period > 1 || (Config::Analysis::reachability() && !loop.deterministic)) {
        return BoolExpr();
    }
    // we must not start another iteration of the loop in the next step,
    // so we require that we either use the learned transition,
    // or some implicant of the loop is violated
    BoolExprSet pre;
    const auto s {subs_at(depth + 1)};
    const auto not_covered {!loop.covered->subs(s)};
    pre.insert(BExpression::buildTheoryLit(Rel::buildEq(s.get<IntTheory>(trace_var), (*shortcut)->getId())));
    pre.insert(not_covered);
    unsigned long length {depth - backlink + 1};
    for (unsigned i = 0; i < length; ++i) {
        const auto &[rule, implicant] {trace[backlink + i]};
        const auto s_current {subs_at(depth + i + 1)};
        const auto s_next {subs_at(depth + i + 2)};
        pre.insert(implicant->negation()->subs(s_current));
        for (const auto x: vars) {
            if (expr::isProgVar(x)) {
                pre.insert(expr::mkNeq(s_next.get(x), expr::subs(rule->getUpdate().get(x), s_current)));
            }
        }
    }
    // we must not start another iteration of the loop after using the learned transition in the next step
    BoolExprSet post;
    post.insert(BExpression::buildTheoryLit(Rel::buildNeq(s.get<IntTheory>(trace_var), (*shortcut)->getId())));
    post.insert(not_covered);
    for (unsigned i = 0; i < length; ++i) {
        const auto &[rule, implicant] {trace[backlink + i]};
        const auto s_current {subs_at(depth + i + 2)};
        const auto s_next {subs_at(depth + i + 3)};
        post.insert(implicant->negation()->subs(s_current));
        for (const auto x: vars) {
            if (expr::isProgVar(x)) {
                pre.insert(expr::mkNeq(s_next.get(x), expr::subs(rule->getUpdate().get(x), s_current)));
            }
        }
    }
    return BExpression::buildOr(pre) & BExpression::buildOr(post);
}

TransIdx ABMC::add_learned_clause(const Rule &accel, const unsigned backlink) {
    const auto idx {its.addLearnedRule(accel, trace.at(backlink).first, trace.back().first)};
    rule_map.emplace(idx->getId(), idx);
    return idx;
}

std::optional<ABMC::Loop> ABMC::handle_loop(int backlink, const std::vector<int> &lang) {
    auto [loop, sample_point, nested] {build_loop(backlink)};
    const auto it {cache.find(lang)};
    if (it != cache.end()) {
        for (const auto &[imp, loop]: it->second) {
            if (imp->subs(sample_point)->isTriviallyTrue()) {
                if (Config::Analysis::log) std::cout << "cache hit" << std::endl;
                if (loop) {
                    shortcut = loop->idx;
                    return loop;
                } else {
                    return {};
                }
            }
        }
    }
    const auto simp {Preprocess::preprocessRule(loop)};
    const auto deterministic {simp->isDeterministic()};
    if (nested && !deterministic) {
        if (Config::Analysis::log) std::cout << "not accelerating non-deterministic, nested loop" << std::endl;
    } else if (Config::Analysis::reachability() && simp->getUpdate() == expr::concat(simp->getUpdate(), simp->getUpdate())) {
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
            AccelConfig config {.approx = Config::Analysis::safety() ? Approx::OverApprox : Approx::UnderApprox, .tryNonterm = Config::Analysis::tryNonterm(), .n = n};
            const auto accel_res {LoopAcceleration::accelerate(*simp, sample_point, config)};
            if (accel_res.accel) {
                auto simplified = Preprocess::preprocessRule(accel_res.accel->rule);
                if (simplified->getUpdate() != simp->getUpdate() && simplified->isPoly()) {
                    const auto new_idx {add_learned_clause(*simplified, backlink)};
                    shortcut = new_idx;
                    history.emplace(next, lang);
                    lang_map.emplace(Implicant(new_idx, {}), next);
                    ++next;
                    const Loop loop {.idx = new_idx,
                                    .prefix = accel_res.prefix,
                                    .period = accel_res.period,
                                    .covered = accel_res.accel->covered,
                                    .deterministic = deterministic};
                    auto &map {cache.emplace(lang, std::map<BoolExpr, std::optional<Loop>>()).first->second};
                    map.emplace(accel_res.accel->covered, loop);
                    ITSProof sub_proof, acceleration_proof;
                    acceleration_proof.storeSubProof(simp.getProof());
                    acceleration_proof.ruleTransformationProof(*simp, "Loop Acceleration", accel_res.accel->rule);
                    acceleration_proof.storeSubProof(accel_res.accel->proof);
                    sub_proof.concat(acceleration_proof);
                    sub_proof.concat(simplified.getProof());
                    proof.majorProofStep("Accelerate", sub_proof, its);
                    if (Config::Analysis::log) {
                        std::cout << "accelerated rule, idx " << new_idx->getId() << std::endl;
                        ITSExport::printRule(*simplified, std::cout);
                        std::cout << std::endl;
                    }
                    return loop;
                }
            }
        }
    }
    auto &map {cache.emplace(lang, std::map<BoolExpr, std::optional<Loop>>()).first->second};
    map.emplace(top(), std::optional<Loop>());
    return {};
}

BoolExpr ABMC::encode_transition(const TransIdx idx) {
    const auto up {idx->getUpdate()};
    std::vector<BoolExpr> res {idx->getGuard()};
    res.emplace_back(BExpression::buildTheoryLit(Rel::buildEq(trace_var, idx->getId())));
    for (const auto &x: vars) {
        if (expr::isProgVar(x)) {
            res.push_back(expr::mkEq(expr::toExpr(post_vars.at(x)), up.get(x)));
        }
    }
    return BExpression::buildAnd(res);
}

void ABMC::unknown() {
    std::cout << "unknwon" << std::endl;
    proof.result("unknown");
    proof.print();
}

void ABMC::unsat() {
    const auto str = Config::Analysis::safety() ? "unknown" : "unsat";
    std::cout << str << std::endl;
    proof.append("reached error location at depth " + std::to_string(depth));
    proof.result(str);
    proof.print();
}

void ABMC::sat() {
    std::cout << "sat" << std::endl;
    proof.append(std::to_string(depth) + "-fold unrolling of the transition relation is unsatisfiable");
    proof.result("sat");
    proof.print();
}

void ABMC::build_trace() {
    trace.clear();
    const auto model {solver->model().toSubs()};
    std::vector<Subs> run;
    std::optional<Implicant> prev;
    for (unsigned d = 0; d <= depth; ++d) {
        const auto s {subs.at(d)};
        const auto rule {rule_map.at(s.get<IntTheory>(trace_var).subs(model.get<IntTheory>()).toNum().to_int())};
        const auto comp {expr::compose(s, model)};
        const auto imp {rule->getGuard()->implicant(comp)};
        auto vars {rule->getUpdate().domain()};
        vars.insert(n);
        vars.insert(trace_var);
        run.push_back(comp.project(vars));
        if (!imp) {
            throw std::logic_error("model, but no implicant");
        }
        const Implicant i {rule, *imp};
        if (prev) {
            dependency_graph.addEdge(*prev, i);
        }
        prev = i;
        trace.emplace_back(rule, *imp);
    }
    if (Config::Analysis::log) {
        std::cout << "trace:" << std::endl << trace;
        std::cout << "run:" << std::endl;
        for (const auto &s: run) {
            std::cout << s << std::endl;
        }
    }
}

const Subs& ABMC::subs_at(const unsigned i) {
    while (subs.size() <= i) {
        Subs s;
        for (const auto &var: vars) {
            const auto &post_var {post_vars.at(var)};
            s.put(var, subs.back().get(post_var));
            s.put(post_var, expr::toExpr(expr::next(post_var)));
        }
        subs.push_back(s);
    }
    return subs.at(i);
}

void ABMC::analyze() {
    if (Config::Analysis::log) {
        std::cout << "initial ITS" << std::endl;
        its.print(std::cout);
    }
    proof.majorProofStep("Initial ITS", ITSProof(), its);
    const auto res {Preprocess::preprocess(its)};
    if (res) {
        proof.concat(res.getProof());
        if (Config::Analysis::log) {
            std::cout << "Simplified ITS" << std::endl;
            ITSExport::printForProof(its, std::cout);
        }
    }
    vars.insertAll(its.getVars());
    for (const auto &var: vars) {
        post_vars.emplace(var, expr::next(var));
    }
    last_orig_clause = 0;
    for (const auto &r: its.getAllTransitions()) {
        rule_map.emplace(r.getId(), &r);
        last_orig_clause = std::max(last_orig_clause, r.getId());
    }
    std::vector<BoolExpr> inits;
    for (const auto &idx: its.getInitialTransitions()) {
        if (its.isSinkTransition(idx)) {
            switch (SmtFactory::check(idx->getGuard())) {
            case SmtResult::Sat:
                unsat();
                return;
            case SmtResult::Unknown:
                if (Config::Analysis::log) {
                    std::cout << "got unknown from SMT solver -- approximating" << std::endl;
                }
                approx = true;
                if (Config::Analysis::safety()) {
                    unknown();
                    return;
                }
                break;
            case SmtResult::Unsat: {}
            }
        } else {
            inits.push_back(encode_transition(idx));
        }
    }
    solver->add(BExpression::buildOr(inits));

    std::vector<BoolExpr> steps;
    for (const auto &r: its.getAllTransitions()) {
        if (its.isInitialTransition(&r) || its.isSinkTransition(&r)) {
            continue;
        }
        steps.push_back(encode_transition(&r));
    }
    const auto step {BExpression::buildOr(steps)};

    std::vector<BoolExpr> queries;
    for (const auto &idx: its.getSinkTransitions()) {
        if (!its.isInitialTransition(idx)) {
            queries.push_back(idx->getGuard());
        }
    }
    const auto query {BExpression::buildOr(queries)};

    while (true) {
        const auto &s {subs_at(depth + 1)};
        solver->push();
        solver->add(query->subs(s));
        switch (solver->check()) {
        case SmtResult::Sat:
            build_trace();
            unsat();
            return;
        case SmtResult::Unknown:
            if (Config::Analysis::log && !approx) {
                std::cout << "got unknown from SMT solver -- approximating" << std::endl;
            }
            if (Config::Analysis::safety()) {
                unknown();
                return;
            }
            approx = true;
            break;
        case SmtResult::Unsat: {}
        }
        solver->pop();
        if (!shortcut) {
            solver->add(step->subs(s));
        } else {
            solver->add((encode_transition(*shortcut) | step)->subs(s));
        }
        ++depth;
        BoolExpr blocking_clause;
        switch (solver->check()) {
        case SmtResult::Unsat:
            if (!approx) {
                sat();
            }
            return;
        case SmtResult::Sat: {
            shortcut.reset();
            build_trace();
            std::vector<int> lang;
            if (Config::Analysis::log) std::cout << "starting loop handling" << std::endl;
            const auto backlink = has_looping_suffix(trace.size() - 1, lang);
            if (backlink) {
                const auto loop {handle_loop(*backlink, lang)};
                if (loop) {
                    blocking_clause = build_blocking_clause(*backlink, *loop);
                }
            }
            if (Config::Analysis::log) std::cout << "done with loop handling" << std::endl;
            break;
        }
        case SmtResult::Unknown:
            shortcut.reset();
            trace.clear();
        }
        if (Config::Analysis::log) {
            std::cout << "depth: " << depth << std::endl;
        }
        if (blocking_clause) {
            solver->add(blocking_clause);
        }
    }
}

void ABMC::analyze(ITSProblem &its) {
    ABMC(its).analyze();
}

std::ostream& operator<<(std::ostream &s, const std::vector<Implicant> &trace) {
    for (const auto &imp: trace) {
        s << imp << std::endl;
    }
    return s;
}
