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

ABMC::ABMC(const ITSPtr& its):
    its(its),
    trace_var(ArithVar::next()),
    cex(its) {
    vars.insert(trace_var);
    cells.insert(trace_var);
    vars.insert(n);
    cells.insert(n);
    solver->enableModels();
    vars.insertAll(its->getVars());
    cells.insertAll(its->getCells());
    for (const auto &var: vars) {
        pre_to_post.insert(var, theory::next(var));
    }
    last_orig_clause = 0;
    for (const auto &r : its->getAllTransitions()) {
        rule_map.emplace(r->getId(), r);
        last_orig_clause = std::max(last_orig_clause, r->getId());
    }
    std::vector<Bools::Expr> inits;
    for (const auto &idx: its->getInitialTransitions()) {
        assert(!its->isSinkTransition(idx));
        inits.push_back(encode_transition(idx));
    }
    solver->add(bools::mkOr(inits));

    std::vector<Bools::Expr> steps;
    for (const auto &r: its->getAllTransitions()) {
        if ((its->isInitialTransition(r) && !its->isSimpleLoop(r)) || its->isSinkTransition(r)) {
            continue;
        }
        steps.push_back(encode_transition(r));
    }
    step = bools::mkOr(steps);

    std::vector<Bools::Expr> queries;
    for (const auto &idx: its->getSinkTransitions()) {
        if (!its->isInitialTransition(idx)) {
            queries.push_back(encode_transition(idx));
        }
    }
    query = bools::mkOr(queries);
}

bool ABMC::is_orig_clause(const RulePtr& idx) const {
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

bool ABMC::is_redundant(const std::vector<int> &w) const {
    auto it{w.begin()};
    const auto size{w.size() / 2};
    for (auto i = 0u; i < size; ++i, ++it) {
        if (auto h{history.find(*it)}; h != history.end()) {
            auto next{it};
            ++next;
            if (h->second.size() == size - 1 && std::equal(h->second.begin(), h->second.end(), next)) {
                return true;
            }
        }
    }
    return false;
}

std::optional<unsigned> ABMC::has_looping_suffix(const unsigned start, std::vector<int> &lang) {
    const auto last{trace.back()};
    for (unsigned pos = start; pos > 0; --pos) {
        lang.push_back(get_language(pos));
        if (ends_with_square(lang)) {
            if (Config::Analysis::log) std::cout << "skipping square " << lang << std::endl;
            return {};
        }
        if (Config::Analysis::log) std::cout << lang << " does not have a square" << std::endl;
        if (const auto &imp{trace[pos]}; dependency_graph.hasEdge(last, imp)) {
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

int ABMC::get_language(const unsigned i) {
    if (const auto imp{trace[i]}; is_orig_clause(imp.first)) {
        const auto [it, changed]{lang_map.emplace(imp, next)};
        if (changed) {
            ++next;
        }
        return it->second;
    } else {
        return lang_map.at(imp);
    }
}

std::pair<RulePtr, ModelPtr> ABMC::build_loop(const int backlink) const {
    std::vector<RulePtr> rules;
    for (size_t i = backlink; i < trace.size(); ++i) {
        rules.emplace_back(trace[i].first->withGuard(trace[i].second)->renameVars(subsTmp.at(i)));
    }
    const auto loop {Preprocess::chain(rules)};
    const auto s {subsProg.at(backlink)};
    auto model {solver->model()->composeBackwards(s)};
    const auto imp {model->syntacticImplicant(loop->getGuard())};
    const auto implicant {loop->withGuard(imp)};
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
    for (const auto &[x, y] : pre_to_post) {
        pre_v.insert(x);
        post_v.insert(y);
    }
    const auto not_trans {!encode_transition(orig, false)};
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

void ABMC::add_learned_clause(const RulePtr& accel, const unsigned backlink) {
    its->addLearnedRule(accel, trace.at(backlink).first, trace.back().first);
    rule_map.emplace(accel->getId(), accel);
}

std::optional<ABMC::Loop> ABMC::handle_loop(const unsigned backlink, const std::vector<int> &lang) {
    const auto update_subs = [&](const RulePtr& loop) {
        subs_at(depth + 1);
        for (const auto new_vars {loop->vars()}; const auto &x: new_vars) {
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
        if (sample_point->eval(imp)) {
            if (Config::Analysis::log) std::cout << "cache hit" << std::endl;
            if (loop) {
                shortcut = loop->idx;
                update_subs(loop->idx);
                return loop;
            }
            return {};
        }
    }
    auto simp {Preprocess::preprocessRule(loop)};
    auto success {false};
    const auto nonterm_to_query = [&](const acceleration::Result &accel_res) {
        if (Config::Analysis::tryNonterm() && accel_res.nonterm != bot()) {
            const auto q {its->addQuery(accel_res.nonterm, trace.at(backlink).first)};
            rule_map.emplace(q->getId(), q);
            if (Config::Analysis::model) {
                cex.add_recurrent_set(loop, q);
            }
            success = true;
            query = query || encode_transition(q);
            if (Config::Analysis::log) {
                std::cout << "found certificate of non-termination\n" << accel_res.nonterm << std::endl;
            }
        }
    };
    if (Config::Analysis::tryNonterm() && !nonterm_cache.contains(lang)) {
        const AccelConfig config {true, false, Config::Accel::non_linear, n, its->getCost(simp)};
        const auto accel_res {LoopAcceleration::accelerate(simp, config)};
        nonterm_to_query(accel_res);
        nonterm_cache.emplace(lang);
    }
    std::optional<Loop> res {};
    auto covered {top()};
    if (const auto deterministic{simp->isDeterministic()}; Config::Analysis::safety() && !deterministic) {
        if (Config::Analysis::log) std::cout << "not accelerating non-deterministic loop" << std::endl;
    } else if (Config::Analysis::safety() && simp->getUpdate() == simp->getUpdate().compose(simp->getUpdate())) {
        if (Config::Analysis::log) std::cout << "acceleration would yield equivalent rule" << std::endl;
    } else if (Config::Analysis::safety() && simp->getUpdate().empty()) {
        if (Config::Analysis::log) std::cout << "trivial looping suffix" << std::endl;
    } else {
        if (Config::Analysis::log && simp->getId() != loop->getId()) {
            std::cout << "simplified loop:\n" << simp << std::endl;
        }
        const AccelConfig config {Config::Analysis::tryNonterm(), true, Config::Accel::non_linear, n, its->getCost(simp)};
        const auto accel_res {LoopAcceleration::accelerate(simp, config)};
        nonterm_to_query(accel_res);
        if (accel_res.accel) {
            if (auto simplified {Preprocess::preprocessRule(accel_res.accel->rule)}; simplified->getUpdate() != simp->getUpdate()) {
                success = true;
                add_learned_clause(simplified, backlink);
                if (Config::Analysis::model) {
                    cex.add_accel(loop, simplified);
                }
                shortcut = simplified;
                history.emplace(next, lang);
                lang_map.emplace(Implicant(simplified, simplified->getGuard()), next);
                ++next;
                res = {
                    .idx = simplified,
                    .prefix = accel_res.prefix,
                    .period = accel_res.period,
                    .covered = accel_res.accel->covered,
                    .deterministic = deterministic};
                covered = accel_res.accel->covered;
                if (Config::Analysis::log) {
                    std::cout << "accelerated rule, idx " << simplified->getId() << "\n" << simplified << std::endl;
                }
                update_subs(simplified);
            }
        }
    }
    if (success && Config::Analysis::model) {
        if (backlink + 1 == trace.size()) {
            if (const auto rule {trace.back().first}; rule != loop) {
                cex.add_implicant(rule, loop);
            }
        } else {
            std::vector<RulePtr> rules;
            for (size_t i = backlink; i < trace.size(); ++i) {
                if (const auto &[rule, guard]{trace.at(i)}; rule->getGuard() == guard) {
                    rules.emplace_back(rule);
                } else {
                    const auto imp{rule->withGuard(guard)};
                    cex.add_implicant(rule, imp);
                    rules.emplace_back(imp);
                }
            }
            cex.add_resolvent(rules, loop);
        }
    }
    map.emplace(covered, res);
    return res;
}

Bools::Expr ABMC::encode_transition(const RulePtr& idx, const bool with_id) {
    const auto up {idx->getUpdate()};
    std::vector res {idx->getGuard()};
    if (with_id) {
        res.emplace_back(theory::mkEq(trace_var, arith::mkConst(idx->getId())));
    }
    for (const auto& x : cells) {
        theory::apply(
            x,
            [&](const Arrays<Arith>::Cell& x) {
                const auto tmp{Arith::next()};
                if (x->isProgVar()) {
                    res.push_back(bools::mkLit(arrays::mkElemEq(pre_to_post(x), tmp)));
                    res.push_back(bools::mkLit(arrays::mkElemEq(up.get(x), tmp)));
                }
            },
            [&](const auto& x) {
                using T = decltype(theory::theory(x));
                if (x->isProgVar()) {
                    res.push_back(theory::mkEq(T::cellToExpr(pre_to_post(x)), up.get(x)));
                }
            });
    }
    return bools::mkAnd(res);
}

void ABMC::build_trace() {
    trace.clear();
    std::vector<Valuation> run;
    std::optional<Implicant> prev;
    for (unsigned d = 0; d <= depth; ++d) {
        const auto s {subs.at(d)};
        const auto vars = d == 0 ? this->vars : s.coDomainVars();
        auto m {solver->model()->composeBackwards(s)};
        const auto rule {rule_map.at(m->get(trace_var))};
        const auto imp {m->syntacticImplicant(rule->getGuard())};
        if (Config::Analysis::log) {
            auto run_cells {rule->cells()};
            run_cells.insert(n);
            run_cells.insert(trace_var);
            Valuation val;
            for (const auto& cell : run_cells) {
                theory::apply(cell, [&](const auto& cell) {
                    val.put(cell, m->get(cell));
                });
            }
            RUN.push_back(val);
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
            const auto &post_var{pre_to_post.get(var)};
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

std::optional<SmtResult> ABMC::do_step() {
    ++depth;
    const auto &s{subs_at(depth)};
    solver->push();
    solver->add(s(query));
    switch (solver->check()) {
        case SmtResult::Sat:
            build_trace();
            return SmtResult::Unsat;
        case SmtResult::Unknown:
            if (Config::Analysis::log && !approx) {
                std::cout << "got unknown from SMT solver -- approximating" << std::endl;
            }
            approx = true;
            break;
        case SmtResult::Unsat:
            break;
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
    Bools::Expr blocking_clause{top()};
    switch (solver->check()) {
        case SmtResult::Unsat: {
            if (approx) {
                return SmtResult::Unknown;
            }
            return SmtResult::Sat;
        }
    case SmtResult::Sat: {
            shortcut.reset();
            build_trace();
            std::vector<int> lang;
            if (Config::Analysis::log)
                std::cout << "starting loop handling" << std::endl;
            if (const auto backlink = has_looping_suffix(trace.size() - 1, lang)) {
                if (const auto loop{handle_loop(*backlink, lang)}) {
                    blocking_clause = build_blocking_clause(*backlink, *loop);
                }
            }
            if (Config::Analysis::log)
                std::cout << "done with loop handling" << std::endl;
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
    return {};
}

ITSModel ABMC::get_model() {
    std::vector<Bools::Expr> inits;
    Renaming post_to_pre;
    Renaming init_renaming;
    for (const auto &x: its->getVars()) {
        if (theory::isProgVar(x)) {
            init_renaming.insert(x, theory::next(x));
        }
    }
    for (const auto &t: its->getInitialTransitions()) {
        std::vector conjuncts {init_renaming(t->getGuard())};
        const auto &up {t->getUpdate()};
        for (const auto& [x,_] : init_renaming) {
            theory::apply(x, [&](const auto& x) {
                using T = decltype(theory::theory(x));
                conjuncts.emplace_back(theory::mkEq(theory::toExpr(x), init_renaming(up.get<T>(x))));
            });
        }
        inits.emplace_back(bools::mkAnd(conjuncts));
    }
    const auto init {bools::mkOr(inits)};
    std::vector res{init};
    Bools::Expr last{init};
    for (unsigned i = 0; i + 1 < depth; ++i) {
        const auto s1{subs.at(i)};
        last = last && s1(transitions.at(i));
        Renaming s2;
        for (const auto &[pre,post]: pre_to_post) {
            if (theory::isProgVar(pre)) {
                s2.insert(s1.get(post), pre);
                s2.insert(pre, theory::next(pre));
            }
        }
        res.push_back(s2(last));
    }
    ITSModel model;
    const auto m {bools::mkOr(res)};
    for (const auto &l: its->getLocations()) {
        model.set_invariant(l, Subs::build<Arith>(its->getLocVar(), arith::mkConst(l))(m));
    }
    model.set_invariant(its->getInitialLocation(), top());
    return model;
}

ITSSafetyCex ABMC::get_cex() {
    const auto model {solver->model()};
    auto valuation {model->toValuation(cells)};
    cex.set_initial_state(valuation.composeBackwards(subs.front()));
    for (size_t i = 0; i < depth; ++i) {
        const auto r {subs.at(i + 1)};
        CellSet renamed_cells;
        for (const auto& c : cells) {
            theory::apply(c, [&](const auto& c) {
                renamed_cells.insert(r(c));
            });
        }
        valuation = model->toValuation(renamed_cells);
        const auto current {valuation.composeBackwards(r)};
        if (const auto trans {trace.at(i).first}; !cex.try_step(trans, current)) {
            throw std::logic_error("get_cex failed");
        }
    }
    if (!cex.try_final_transition(trace.back().first)) {
        throw std::logic_error("get_cex failed");
    }
    return cex;
}

std::ostream &operator<<(std::ostream &s, const std::vector<Implicant> &trace) {
    for (const auto &imp : trace) {
        s << imp << std::endl;
    }
    return s;
}
