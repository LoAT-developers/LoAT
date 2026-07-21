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
    solver(SmtFactory::solver(its->hasArrays() ? Logic::QF_AEA : Logic::QF_EA)),
    cex(its) {}

void ABMC::init() {
    vars.insert(trace_var->var());
    cells.insert(trace_var);
    vars.insert(n->var());
    cells.insert(n);
    solver->enableModels();
    vars.insertAll(its->getVars());
    cells.insertAll(its->getCells());
    for (const auto& var : vars) {
        theory::apply(
            var,
            [&](const auto& var) {
                using T = decltype(theory::theory(var));
                pre_to_post.insert(var, T::next(var->dim()));
            });
    }
    last_orig_clause = 0;
    for (const auto &r : its->getAllTransitions()) {
        rule_map.emplace(r->getId(), r);
        last_orig_clause = std::max(last_orig_clause, r->getId());
    }
    std::vector<Bools::Expr> inits;
    for (const auto &idx: its->getInitialTransitions()) {
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

static bool ends_with_square(const std::vector<int> &w) {
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
    const auto [rule, imp] = trace[i];
    if (is_orig_clause(rule)) {
        const auto [it, changed]{lang_map.emplace(imp, next)};
        if (changed) {
            ++next;
        }
        return it->second;
    }
    return lang_map.at(rule);
}

std::pair<RulePtr, ModelPtr> ABMC::build_loop(const int backlink) const {
    std::vector<RulePtr> loop_rules;
    for (size_t i = backlink; i < trace.size(); ++i) {
        loop_rules.emplace_back(trace[i].second->renameVars(subsTmp.at(i)));
    }
    const auto s {subsProg.at(backlink)};
    auto model {solver->model()->composeBackwards(s)};
    auto loop = Preprocess::chain(loop_rules)->syntacticImplicant(model);
    if (Config::Analysis::log) {
        std::cout << "found loop of length " << (trace.size() - backlink) << ":\n";
        std::cout << *loop << std::endl;
    }
    return {loop, model};
}

Bools::Expr ABMC::build_blocking_clause(const int backlink, const Loop &loop) {
    if (!blocking_clauses) {
        return top();
    }
    const auto orig {loop.idx->subs(Subs::build(n->var(), arrays::update(n, arith::one())))};
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
    pre.push_back(
        bools::mkLit(
            arith::mkEq(
                trace_var->renameVars(s_next),
                arith::mkConst((*shortcut)->getId()))));
    pre.push_back(not_trans->renameVars(s_next));
    // we must not start another iteration of the loop after using the learned transition in the next step
    std::vector<Bools::Expr> post;
    post.push_back(bools::mkLit(arith::mkNeq(arrays::readConst(s_next.get(trace_var->var())), arith::mkConst((*shortcut)->getId()))));
    const auto s_next_next {subs_at(depth + 2).project(pre_v).compose(subs_at(depth + length + 1).project(post_v))};
    post.push_back(not_trans->renameVars(s_next_next));
    const auto not_covered{!loop.covered->renameVars(s_next)};
    return not_covered || (bools::mkOr(pre) && bools::mkOr(post));
}

void ABMC::add_learned_clause(const RulePtr& accel, const unsigned backlink) {
    its = its->addLearnedRule(accel, trace.at(backlink).first, trace.back().first);
    rule_map.emplace(accel->getId(), accel);
}

std::optional<ABMC::Loop> ABMC::handle_loop(const unsigned backlink, const std::vector<int> &lang) {
    const auto update_subs = [&](const RulePtr& loop) {
        subs_at(depth + 1);
        for (const auto new_vars{loop->vars()}; const auto& x : new_vars) {
            theory::apply(
                x,
                [&](const auto& x) {
                    using T = decltype(theory::theory(x));
                    if (x->isTempVar() && !vars.contains(x)) {
                        const auto next{T::next(x->dim())};
                        subs[depth + 1].insert(x, next);
                        subsTmp[depth + 1].insert(x, next);
                    }
                });
        }
    };
    auto [loop, sample_point] {build_loop(backlink)};
    auto& map{cache.emplace(lang, std::unordered_map<Bools::Expr, std::optional<Loop>>()).first->second};
    for (const auto& [imp, loop] : map) {
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
    auto loop_to_simp = std::make_shared<RulePreprocessor>(loop);
    auto simp= loop_to_simp->process();
    auto success{false};
    const auto nonterm_to_query = [&](const acceleration::Result& accel_res) {
        if (Config::Analysis::tryNonterm() && accel_res.nonterm != bot()) {
            const auto q = Rule::mk(accel_res.nonterm, Subs());
            its = its->addQuery(q, trace.at(backlink).first);
            rule_map.emplace(q->getId(), q);
            if (Config::Analysis::model) {
                cex.add_recurrent_set(simp, q);
            }
            success = true;
            query = query || encode_transition(q);
            if (Config::Analysis::log) {
                std::cout << "found certificate of non-termination\n" << accel_res.nonterm << std::endl;
            }
        }
    };
    if (Config::Analysis::tryNonterm() && !nonterm_cache.contains(lang)) {
        const AccelConfig config{true, false, Config::Accel::non_linear, Config::Accel::arrays, n, its->getCost(simp)};
        const auto accel_res{LoopAcceleration::accelerate(simp, sample_point, config)};
        nonterm_to_query(accel_res);
        nonterm_cache.emplace(lang);
    }
    std::optional<Loop> res{};
    auto covered{top()};
    if (Config::Analysis::safety() && simp->hasNonTrivialNondeterminism()) {
        if (Config::Analysis::log) std::cout << "not accelerating non-deterministic loop" << std::endl;
    } else if (Config::Analysis::safety() && simp->getUpdate() == simp->getUpdate().compose(simp->getUpdate())) {
        if (Config::Analysis::log) std::cout << "acceleration would yield equivalent rule" << std::endl;
    } else if (Config::Analysis::safety() && simp->getUpdate().empty()) {
        if (Config::Analysis::log) std::cout << "trivial looping suffix" << std::endl;
    } else {
        if (Config::Analysis::log && simp->getId() != loop->getId()) {
            std::cout << "simplified loop:\n" << simp << std::endl;
        }
        const AccelConfig config{
            Config::Analysis::tryNonterm(), true, Config::Accel::non_linear, Config::Accel::arrays, n, its->getCost(simp)
        };
        const auto accel_res{LoopAcceleration::accelerate(simp, sample_point, config)};
        nonterm_to_query(accel_res);
        if (accel_res.accel) {
            auto accel_to_simplified = std::make_shared<RulePreprocessor>(accel_res.accel->rule);
            if (auto simplified = accel_to_simplified->process(); simplified->getUpdate() != simp->getUpdate()) {
                success = true;
                add_learned_clause(simplified, backlink);
                if (Config::Analysis::model) {
                    cex.add_accel(ITSCex::AccelInfo(simp, n, accel_res.accel->rule));
                    cex.add_implicant(ITSCex::TransformationInfo(accel_res.accel->rule, accel_to_simplified, simplified));
                }
                shortcut = simplified;
                history.emplace(next, lang);
                lang_map.emplace(simplified, next);
                ++next;
                res = {
                    .idx = simplified,
                    .prefix = accel_res.prefix,
                    .period = accel_res.chaining_info->size(),
                    .covered = accel_res.accel->covered
                };
                covered = accel_res.accel->covered;
                if (Config::Analysis::log) {
                    std::cout << "accelerated rule, idx " << simplified->getId() << "\n" << *simplified << std::endl;
                }
                update_subs(simplified);
            }
        }
    }
    if (success) {
        if (Config::Analysis::model) {
            if (simp != loop) {
                cex.add_implicant(ITSCex::TransformationInfo(loop, loop_to_simp, simp));
            }
            if (backlink + 1 == trace.size()) {
                if (const auto rule{trace.back().first}; rule != loop) {
                    cex.add_implicant(ITSCex::TransformationInfo(rule, loop));
                }
            } else {
                std::vector<RulePtr> rules;
                std::vector<Renaming> subs;
                for (size_t i = backlink; i < trace.size(); ++i) {
                    if (const auto& [rule, imp]{trace.at(i)}; rule == imp) {
                        rules.emplace_back(rule);
                    } else {
                        cex.add_implicant(ITSCex::TransformationInfo(rule, imp));
                        rules.emplace_back(imp);
                    }
                    subs.emplace_back(subsTmp.at(i));
                }
                cex.add_resolvent(ITSCex::ResolventInfo(rules, subs, loop));
            }
        }
        map.emplace(covered, res);
        return res;
    }
    return std::nullopt;
}

Bools::Expr ABMC::encode_transition(const RulePtr& idx, const bool with_id) {
    const auto up {idx->getUpdate()};
    std::vector res {idx->getGuard()};
    if (with_id) {
        res.emplace_back(Arith::mkEq(trace_var, arith::mkConst(idx->getId())));
    }
    for (const auto& x : vars) {
        theory::apply(
            x,
            [&](const auto& x) {
                using T = decltype(theory::theory(x));
                if (x->isProgVar()) {
                    res.push_back(T::mkEq(T::varToExpr(pre_to_post.get(x)), up.get(x)));
                }
            });
    }
    return bools::mkAnd(res);
}

void ABMC::build_trace() {
    trace.clear();
    std::vector<ModelPtr> run;
    std::optional<Implicant> prev;
    for (unsigned d = 0; d <= depth; ++d) {
        const auto s {subs.at(d)};
        auto m {solver->model()->composeBackwards(s)};
        const auto rule {rule_map.at(m->get(trace_var))};
        const auto imp {rule->syntacticImplicant(m)};
        if (Config::Analysis::log) {
            run.push_back(m);
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
            std::cout << s->toString(cells) << std::endl;
        }
        std::cout << "full run:" << std::endl;
        for (const auto &s : run) {
            std::cout << s->toString(vars) << std::endl;
        }
    }
}

const Renaming &ABMC::subs_at(const unsigned i) {
    while (subs.size() <= i) {
        Renaming s, sTmp, sProg;
        for (const auto &var : vars) {
            theory::apply(
                var,
                [&](const auto& var) {
                    using T = decltype(theory::theory(var));
                    const auto& post_var{pre_to_post.get(var)};
                    const auto current{subs.back().get(post_var)};
                    const auto next{T::next(var->dim())};
                    s.insert(var, current);
                    s.insert(post_var, next);
                    if (var->isTempVar()) {
                        sTmp.insert(var, current);
                        sTmp.insert(post_var, next);
                    }
                    else {
                        sProg.insert(var, current);
                        sProg.insert(post_var, next);
                    }
                });
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
    solver->add(query->renameVars(s));
    switch (solver->check()) {
        case SmtResult::Sat:
            build_trace();
            return SmtResult::Unsat;
        case SmtResult::Unknown:
            if (Config::Analysis::log) {
                if (Config::Analysis::fail_early) {
                    std::cout << "got unknown from SMT solver -- giving up" << std::endl;
                } else if (!approx) {
                    std::cout << "got unknown from SMT solver -- approximating" << std::endl;
                }
            }
            if (Config::Analysis::fail_early) {
                return SmtResult::Unknown;
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
        solver->add(step->renameVars(s));
    } else {
        if (Config::Analysis::model) {
            transitions.emplace_back(encode_transition(*shortcut, false) || step);
        }
        solver->add((encode_transition(*shortcut) || step)->renameVars(s));
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
    case SmtResult::Unknown: {
            if (Config::Analysis::log) {
                solver->print(std::cout);
                std::cout << "got unknown from SMT solver -- ";
                if (depth == 1 || Config::Analysis::fail_early) {
                    std::cout << "giving up" << std::endl;
                    return SmtResult::Unknown;
                }
                std::cout << "restarting" << std::endl;
            }
            shortcut.reset();
            trace.clear();
            depth = 0;
        }
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
    return {its, depth};
}

ITSSafetyCex ABMC::get_cex() {
    const auto model{solver->model()};
    cex.set_initial_state(model->composeBackwards(subs.front()));
    for (size_t i = 0; i <= depth; ++i) {
        const auto r{subs.at(i + 1)};
        const auto current{model->composeBackwards(r)};
        const auto trans{trace.at(i).first};
        cex.do_step(trans, current);
    }
    return cex;
}

std::ostream &operator<<(std::ostream &s, const std::vector<Implicant> &trace) {
    for (const auto &imp : trace) {
        s << imp << std::endl;
    }
    return s;
}
