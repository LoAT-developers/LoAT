#include "abmc.hpp"
#include "theory.hpp"
#include "rulepreprocessing.hpp"
#include "smtfactory.hpp"
#include "loopacceleration.hpp"
#include "config.hpp"
#include "vector.hpp"
#include "rule.hpp"
#include "dependencygraph.hpp"

using namespace Config::ABMC;

ABMC::ABMC(ITSProblem &its):
    its(its),
    trace_var(ArithVar::next()) {
    vars.insert(trace_var);
    vars.insert(n);
    solver->enableModels();
}

bool ABMC::is_orig_clause(const TransIdx idx) const {
    return idx->getId() <= last_orig_clause;
}

bool ends_with_square(const std::vector<int> &w) {
    const auto start{w.rbegin()};
    const auto size{w.size()};
    const auto max_length{size / 2};
    auto end{start};
    for (auto length = 1u; length <= max_length; ++length) {
        ++end;
        if (std::equal(start, end, end)) {
            return true;
        }
    }
    return false;
}

bool ABMC::is_redundant(const std::vector<int> &ww) const {
    auto it{ww.begin()};
    const auto size{ww.size() / 2};
    for (auto i = 0u; i < size; ++i, ++it) {
        auto h{history.find(*it)};
        if (h != history.end()) {
            auto next{it};
            ++next;
            if (h->second.size() == size - 1 && std::equal(h->second.begin(), h->second.end(), next)) {
                return true;
            }
        }
    }
    return false;
}

std::optional<unsigned> ABMC::has_looping_suffix(unsigned start, std::vector<int> &lang) {
    const auto last{trace.back()};
    for (unsigned pos = start; pos > 0; --pos) {
        lang.push_back(get_language(pos));
        if (ends_with_square(lang)) {
            if (Config::Analysis::log) std::cout << "skipping square " << lang << std::endl;
            return {};
        } else {
            if (Config::Analysis::log) std::cout << lang << " does not have a square" << std::endl;
        }
        const auto &imp{trace[pos]};
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
    const auto imp{trace[i]};
    if (is_orig_clause(imp.first)) {
        const auto res{lang_map.emplace(imp, next)};
        if (res.second) {
            ++next;
        }
        return res.first->second;
    } else {
        return lang_map.at(imp);
    }
}

std::pair<Rule, Model> ABMC::build_loop(const int backlink) {
    std::vector<Rule> rules;
    for (size_t i = backlink; i < trace.size(); ++i) {
        rules.emplace_back(trace[i].first->withGuard(trace[i].second).renameVars(subsTmp.at(i)));
    }
    const auto loop {Preprocess::chain(rules)};
    const auto s {subsProg.at(backlink)};
    auto vars {loop.vars()};
    s.collectCoDomainVars(vars);
    auto model {solver->model(vars).composeBackwards(s)};
    const auto imp {model.syntacticImplicant(loop.getGuard())};
    const auto implicant {loop.withGuard(imp)};
    if (Config::Analysis::log) {
        std::cout << "found loop of length " << (trace.size() - backlink) << ":\n" << implicant << std::endl;
    }
    return {implicant, model};
}

Bools::Expr ABMC::build_blocking_clause(const int backlink, const Loop &loop) {
    if (!blocking_clauses || loop.prefix > 1 || loop.period > 1 || !loop.deterministic) {
        return top();
    }
    const auto orig {loop.idx->subs(Subs::build<Arith>(n, arith::mkConst(1)))};
    const auto length{depth - backlink + 1};
    // we must not start another iteration of the loop in the next step,
    // so we require that we either use the learned transition,
    // or some implicant of the loop is violated
    VarSet pre_v;
    VarSet post_v;
    for (const auto &[x, y] : post_vars) {
        pre_v.insert(x);
        post_v.insert(y);
    }
    const auto not_trans {!encode_transition(&orig, false)};
    std::vector<Bools::Expr> pre;
    const auto s_next {subs_at(depth + 1).project(pre_v).compose(
            subs_at(depth + length).project(post_v))};
    pre.push_back(theory::mkEq(theory::toExpr(s_next.get(trace_var)), arith::mkConst((*shortcut)->getId())));
    pre.push_back(s_next(not_trans));
    // we must not start another iteration of the loop after using the learned transition in the next step
    std::vector<Bools::Expr> post;
    post.push_back(theory::mkNeq(theory::toExpr(s_next.get(trace_var)), arith::mkConst((*shortcut)->getId())));
    const auto s_next_next {subs_at(depth + 2).project(pre_v).compose(
            subs_at(depth + length + 1).project(post_v))};
    post.push_back(s_next_next(not_trans));
    const auto not_covered{s_next(!loop.covered)};
    return not_covered || (bools::mkOr(pre) && bools::mkOr(post));
}

TransIdx ABMC::add_learned_clause(const Rule &accel, const unsigned backlink) {
    const auto idx{its.addLearnedRule(accel, trace.at(backlink).first, trace.back().first)};
    rule_map.emplace(idx->getId(), idx);
    return idx;
}

std::optional<ABMC::Loop> ABMC::handle_loop(int backlink, const std::vector<int> &lang) {
    const auto update_subs = [&](const TransIdx loop) {
        subs_at(depth + 1);
        const auto new_vars {loop->vars()};
        for (const auto &x: new_vars) {
            if (theory::isTempVar(x) && !vars.contains(x)) {
                const auto next {theory::next(x)};
                subs[depth + 1].insert(x, next);
                subsTmp[depth + 1].insert(x, next);
            }
        }
    };
    auto [loop, sample_point] {build_loop(backlink)};
    auto &map {cache.emplace(lang, std::unordered_map<Bools::Expr, std::optional<Loop>>()).first->second};
    for (const auto &[imp, loop]: map) {
        if (sample_point.eval<Bools>(imp)) {
            if (Config::Analysis::log) std::cout << "cache hit" << std::endl;
            if (loop) {
                shortcut = loop->idx;
                update_subs(loop->idx);
                return loop;
            } else {
                return {};
            }
        }
    }
    auto simp {Preprocess::preprocessRule(loop).value_or(loop)};
    const auto nonterm_to_query = [this](const Rule &rule, const acceleration::Result &accel_res) {
        if (Config::Analysis::tryNonterm() && accel_res.nonterm != bot()) {
            query = query || accel_res.nonterm;
            if (Config::Analysis::log) {
                std::cout << "found certificate of non-termination\n" << accel_res.nonterm << std::endl;
            }
        }
    };
    if (Config::Analysis::tryNonterm() && !nonterm_cache.contains(lang)) {
        const AccelConfig config {.tryNonterm = true, .tryAccel = false, .n = n};
        const auto accel_res {LoopAcceleration::accelerate(simp, config)};
        nonterm_to_query(simp, accel_res);
        nonterm_cache.emplace(lang);
    }
    const auto deterministic{simp.isDeterministic()};
    if (Config::Analysis::safety() && !deterministic) {
        if (Config::Analysis::log) std::cout << "not accelerating non-deterministic loop" << std::endl;
    } else if (Config::Analysis::safety() && simp.getUpdate() == simp.getUpdate().concat(simp.getUpdate())) {
        if (Config::Analysis::log) std::cout << "acceleration would yield equivalent rule" << std::endl;
    } else if (Config::Analysis::safety() && simp.getUpdate().empty()) {
        if (Config::Analysis::log) std::cout << "trivial looping suffix" << std::endl;
    } else {
        if (Config::Analysis::log && simp.getId() != loop.getId()) {
            std::cout << "simplified loop:\n" << simp << std::endl;
        }
        const AccelConfig config {.tryNonterm = Config::Analysis::tryNonterm(), .n = n};
        const auto accel_res {LoopAcceleration::accelerate(simp, config)};
        nonterm_to_query(simp, accel_res);
        if (accel_res.accel) {
            auto simplified {Preprocess::preprocessRule(accel_res.accel->rule).value_or(accel_res.accel->rule)};
            if (simplified.getUpdate() != simp.getUpdate() && simplified.isPoly()) {
                const auto new_idx{add_learned_clause(simplified, backlink)};
                shortcut = new_idx;
                history.emplace(next, lang);
                lang_map.emplace(Implicant(new_idx, new_idx->getGuard()), next);
                ++next;
                const Loop loop{
                    .idx = new_idx,
                    .prefix = accel_res.prefix,
                    .period = accel_res.period,
                    .covered = accel_res.accel->covered,
                    .deterministic = deterministic};
                map.emplace(accel_res.accel->covered, loop);
                if (Config::Analysis::log) {
                    std::cout << "accelerated rule, idx " << new_idx->getId() << "\n" << simplified << std::endl;
                }
                update_subs(new_idx);
                return loop;
            }
        }
    }
    map.emplace(top(), std::optional<Loop>());
    return {};
}

Bools::Expr ABMC::encode_transition(const TransIdx idx, const bool with_id) {
    const auto up {idx->getUpdate()};
    std::vector<Bools::Expr> res {idx->getGuard()};
    if (with_id) {
        res.emplace_back(theory::mkEq(trace_var, arith::mkConst(idx->getId())));
    }
    for (const auto &x: vars) {
        if (theory::isProgVar(x)) {
            res.push_back(theory::mkEq(theory::toExpr(post_vars.at(x)), up.get(x)));
        }
    }
    return bools::mkAnd(res);
}

void ABMC::unknown() {
    const auto str = Config::Analysis::safety() ? "unknown" : "MAYBE";
    std::cout << str << std::endl;
}

void ABMC::unsat() {
    const auto str = Config::Analysis::safety() ? "unsat" : "NO";
    std::cout << str << std::endl;
}

void ABMC::sat() {
    const auto str = Config::Analysis::safety() ? "sat" : "MAYBE";
    std::cout << str << std::endl;
}

void ABMC::build_trace() {
    trace.clear();
    std::vector<Subs> run;
    std::optional<Implicant> prev;
    for (unsigned d = 0; d <= depth; ++d) {
        const auto s {subs.at(d)};
        const auto vars = d == 0 ? this->vars : s.coDomainVars();
        const auto m {solver->model(vars).composeBackwards(s)};
        const auto rule {rule_map.at(m.get<Arith>(trace_var))};
        const auto imp {m.syntacticImplicant(rule->getGuard())};
        if (Config::Analysis::log) {
            auto run_vars {rule->getUpdate().domain()};
            run_vars.insert(n);
            run_vars.insert(trace_var);
            run.push_back(m.project(run_vars).toSubs());
        }
        const Implicant i {rule, imp};
        if (prev) {
            dependency_graph.addEdge(*prev, i);
        }
        prev = i;
        trace.emplace_back(rule, imp);
    }
    if (Config::Analysis::log) {
        std::cout << "trace:" << std::endl << trace;
        std::cout << "run:" << std::endl;
        for (const auto &s : run) {
            std::cout << s << std::endl;
        }
    }
}

const Renaming &ABMC::subs_at(const unsigned i) {
    while (subs.size() <= i) {
        Renaming s, sTmp, sProg;
        for (const auto &var : vars) {
            const auto &post_var{post_vars.at(var)};
            const auto current {subs.back().get(post_var)};
            const auto next {theory::next(post_var)};
            s.insert(var, current);
            s.insert(post_var, next);
            if (theory::isTempVar(var)) {
                sTmp.insert(var, current);
                sTmp.insert(post_var, next);
            } else {
                sProg.insert(var, current);
                sProg.insert(post_var, next);
            }
        }
        subs.push_back(s);
        subsTmp.push_back(sTmp);
        subsProg.push_back(sProg);
    }
    return subs.at(i);
}

SmtResult ABMC::analyze() {
    vars.insertAll(its.getVars());
    for (const auto &var: vars) {
        post_vars.emplace(var, theory::next(var));
    }
    last_orig_clause = 0;
    for (const auto &r : its.getAllTransitions()) {
        rule_map.emplace(r.getId(), &r);
        last_orig_clause = std::max(last_orig_clause, r.getId());
    }
    std::vector<Bools::Expr> inits;
    for (const auto &idx: its.getInitialTransitions()) {
        if (its.isSinkTransition(idx)) {
            switch (SmtFactory::check(idx->getGuard())) {
            case SmtResult::Sat:
                unsat();
                return SmtResult::Unsat;
            case SmtResult::Unknown:
                if (Config::Analysis::log) {
                    std::cout << "got unknown from SMT solver -- approximating" << std::endl;
                }
                approx = true;
                break;
            case SmtResult::Unsat: {}
            }
        } else {
            inits.push_back(encode_transition(idx));
        }
    }
    solver->add(bools::mkOr(inits));

    std::vector<Bools::Expr> steps;
    for (const auto &r: its.getAllTransitions()) {
        if (its.isInitialTransition(&r) || its.isSinkTransition(&r)) {
            continue;
        }
        steps.push_back(encode_transition(&r));
    }
    const auto step {bools::mkOr(steps)};

    std::vector<Bools::Expr> queries;
    for (const auto &idx: its.getSinkTransitions()) {
        if (!its.isInitialTransition(idx)) {
            queries.push_back(idx->getGuard());
        }
    }
    query = bools::mkOr(queries);

    while (true) {
        const auto &s{subs_at(depth + 1)};
        solver->push();
        solver->add(s(query));
        switch (solver->check()) {
        case SmtResult::Sat:
            build_trace();
            unsat();
            return SmtResult::Unsat;
        case SmtResult::Unknown:
            if (Config::Analysis::log && !approx) {
                std::cout << "got unknown from SMT solver -- approximating" << std::endl;
            }
            approx = true;
            break;
        case SmtResult::Unsat: {}
        }
        solver->pop();
        if (!shortcut) {
            if (Config::Analysis::model) {
                transitions.emplace_back(step);
            }
            solver->add(s(step));
        } else {
            if (Config::Analysis::model) {
                transitions.emplace_back(encode_transition(*shortcut, false) || step);
            }
            solver->add(s(encode_transition(*shortcut) || step));
        }
        ++depth;
        Bools::Expr blocking_clause {top()};
        switch (solver->check()) {
        case SmtResult::Unsat:
            if (approx) {
                return SmtResult::Unknown;
            } else {
                sat();
                return SmtResult::Sat;
            }
        case SmtResult::Sat: {
            shortcut.reset();
            build_trace();
            std::vector<int> lang;
            if (Config::Analysis::log) std::cout << "starting loop handling" << std::endl;
            const auto backlink = has_looping_suffix(trace.size() - 1, lang);
            if (backlink) {
                const auto loop{handle_loop(*backlink, lang)};
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
        if (blocking_clause != top()) {
            solver->add(blocking_clause);
        }
    }
}

ITSModel ABMC::get_model() const {
    std::vector<Bools::Expr> inits;
    for (const auto &t: its.getInitialTransitions()) {
        inits.push_back(t->getGuard());
    }
    const auto init {bools::mkOr(inits)};
    std::vector<Bools::Expr> res{init};
    Bools::Expr last{init};
    for (unsigned i = 0; i + 1 < depth; ++i) {
        const auto s1{subs.at(i)};
        last = last && s1(transitions.at(i));
        Renaming s2;
        for (const auto &[pre,post]: post_vars) {
            if (theory::isProgVar(pre)) {
                s2.insert(s1.get(post), pre);
                s2.insert(pre, theory::next(pre));
            }
        }
        res.push_back(s2(last));
    }
    ITSModel model;
    const auto m {bools::mkOr(res)};
    for (const auto &l: its.getLocations()) {
        model.set_invariant(l, Subs::build<Arith>(its.getLocVar(), arith::mkConst(l))(m));
    }
    model.set_invariant(its.getInitialLocation(), top());
    return model;
}

std::ostream &operator<<(std::ostream &s, const std::vector<Implicant> &trace) {
    for (const auto &imp : trace) {
        s << imp << std::endl;
    }
    return s;
}
