#include "bmc.hpp"
#include "theory.hpp"
#include "smtfactory.hpp"
#include "config.hpp"
#include "renaming.hpp"
#include "intmbp.hpp"
#include "trl.hpp"

BMC::BMC(const ITSPtr& its, const bool do_kind) :
    to_safety(its),
    sp(to_safety.transform()),
    init(do_kind ? mbp::int_qe(sp.init()) : sp.init()),
    err(do_kind ? mbp::int_qe(sp.err()) : sp.err()),
    step(bools::mkOr(sp.trans())),
    abstraction(bot()),
    do_kind(do_kind) {
    const auto logic = max({Smt::chooseLogic(sp.init()), Smt::chooseLogic(step), Smt::chooseLogic(sp.err())});
    solver = SmtFactory::modelBuildingSolver(logic);
    kind = SmtFactory::modelBuildingSolver(logic);
    bkind = SmtFactory::modelBuildingSolver(logic);
    solver->add(init);
    if (do_kind) {
        bkind->add(init);
    }
    init->collectVars(vars);
    step->collectVars(vars);
    err->collectVars(vars);
    for (const auto &var: vars) {
        theory::apply(
            var,
            [&](const auto& var) {
                if (var->isProgVar()) {
                    pre_to_post.insert(var, var->postVar());
                } else if (var->isPostVar()) {
                    pre_to_post.insert(var->progVar(), var);
                }
            });
    }
    renamings.emplace_back();
    Renaming snd = get_renaming(1);
    for (const auto &[_,p]: pre_to_post) {
        theory::apply(
            p,
            [&](const auto& p) {
                two_steps.insert(p, snd.get(p));
            });
    }
}

Bools::Expr BMC::encode_transition(const Bools::Expr trans, const Int id) {
    return trans && bools::mkLit(arith::mkEq(id_var, arith::mkConst(id)));
}

void BMC::restart() {
    if (Config::Analysis::log) {
        std::cout << "***** Restart *****" << std::endl;
    }
    while (depth > 0) {
        solver->pop();
        --depth;
    }
}

bool BMC::sample() {
    std::vector<Bools::Expr> all_abstractions;
    for (const auto& a: abstractions | std::views::values) {
        all_abstractions.emplace_back(bools::mkAnd(a));
    }
    const auto no_abstraction = !bools::mkOr(all_abstractions);
    const auto subs = get_renaming(depth);
    solver->push();
    solver->add(step->renameVars(subs));
    solver->add(no_abstraction->renameVars(subs));
    if (solver->check() == SmtResult::Sat) {
        const auto model = solver->model();
        solver->pop();
        const auto trans = mbp::int_cvp(step, model->composeBackwards(subs), Config::TRPConfig::IntMbp);
        const auto children = trans->isAnd() ? trans->getChildren() : BoolExprSet{trans};
        abstractions.emplace(next_id, BoolExprSet());
        transitions.emplace(next_id, children);
        abstraction = abstraction || encode_transition(top(), next_id);
        ++next_id;
        if (Config::Analysis::log) {
            std::cout << "***** Sample *****" << std::endl;
            std::cout << trans << std::endl;
        }
        return true;
    }
    solver->pop();
    return false;
}

SmtResult BMC::refine() {
    const auto model = solver->model();
    BoolExprSet assumptions;
    std::unordered_map<Bools::Expr, std::pair<Int, Bools::Expr>> assumption_to_refinement;
    for (unsigned i = 0; i < depth; ++i) {
        const auto subs = get_renaming(i);
        const auto id = model->get(id_var->renameVars(subs));
        const auto abstraction = abstractions.at(id);
        const auto concretization = transitions.at(id);
        for (const auto& c: concretization) {
            if (!abstraction.contains(c)) {
                const auto assumption = c->renameVars(subs);
                assumptions.insert(assumption);
                assumption_to_refinement.emplace(assumption, std::pair{id, c});
            }
        }
    }
    const auto &[sat,core] = solver->check_with_assumptions(assumptions);
    switch (sat) {
        case SmtResult::Sat: {
            return SmtResult::Unsat;
        }
        case SmtResult::Unknown: {
            return SmtResult::Unknown;
        }
        case SmtResult::Unsat: {
            if (Config::Analysis::log) {
                std::cout << "***** Refine *****" << std::endl;
            }
            for (const auto& c: core) {
                const auto &[id, refinement] = assumption_to_refinement.at(c);
                abstractions.at(id).insert(refinement);
                if (Config::Analysis::log) {
                    std::cout << id << ": " << refinement << std::endl;
                }
            }
            BoolExprSet new_abstractions;
            for (const auto& [id,a]: abstractions) {
                new_abstractions.insert(encode_transition(bools::mkAnd(a), id));
            }
            abstraction = bools::mkOr(new_abstractions);
            return SmtResult::Sat;
        }
    }
    throw std::logic_error("unreachable");
}

Renaming BMC::get_renaming(const unsigned i) {
    if (i < renamings.size()) {
        return renamings.at(i);
    }
    assert(i == renamings.size());
    Renaming last = renamings.back();
    Renaming s;
    for (const auto &p: pre_to_post) {
        theory::apply(
            p,
            [&](const auto& p) {
                const auto& [pre, post] {p};
                using T = decltype(theory::theory(pre));
                s.insert(pre, last.get(post));
                s.insert(post, T::next(post->dim()));
            });
    }
    for (const auto& var : vars) {
        theory::apply(
            var,
            [&](const auto& var) {
                using T = decltype(theory::theory(var));
                if (var->isTempVar()) {
                    s.insert(var, T::next(var->dim()));
                }
            });
    }
    s.insert(id_var->var(), Arrays<Arith>::next(0));
    renamings.emplace_back(s);
    return s;
}

bool BMC::is_transitive() {
    Renaming snd = get_renaming(1);
    return SmtFactory::check(abstraction && abstraction->renameVars(snd) && !abstraction->renameVars(two_steps)) == SmtResult::Unsat;
}

ITSPtr BMC::build_approx_its() {
    auto res = std::make_shared<ITSProblem>();
    const auto init_loc = res->addLocation();
    res->setInitialLocation(init_loc);
    const auto err_loc = res->addLocation();
    res->setSinkLocation(err_loc);
    const auto inv_loc = res->addLocation();
    const auto loc_var = res->getLocVar();
    {
        Subs up;
        up.update(loc_var, arith::mkConst(inv_loc));
        auto guard = init;
        guard = guard && bools::mkLit(arith::mkEq(loc_var, arith::mkConst(init_loc)));
        const auto init_rule = Rule::mk(guard, up);
        res->addRule(init_rule, init_loc);
    }
    {
        Subs up;
        up.update(res->getLocVar(), arith::mkConst(err_loc));
        auto guard = err;
        guard = guard && bools::mkLit(arith::mkEq(loc_var, arith::mkConst(inv_loc)));
        const auto err_rule = Rule::mk(guard, up);
        res->addRule(err_rule, inv_loc);
    }
    for (const auto& a: abstractions | std::views::values) {
        Subs up {pre_to_post};
        auto guard = bools::mkAnd(a);
        guard = guard && bools::mkLit(arith::mkEq(loc_var, arith::mkConst(inv_loc)));
        const auto rule = Rule::mk(guard, up);
        res->addRule(rule, inv_loc);
    }
    return res;
}

SmtResult BMC::analyze() {
    if (Config::Analysis::log) {
        std::cout << "safety problem:\n" << sp << std::endl;
    }

    std::unordered_set<Int> transitions;
    auto initial_phase = true;
    auto changed = false;
    while (true) {
        auto last_s = get_renaming(depth);
        solver->push();
        solver->add(err->renameVars(last_s));
        switch (solver->check()) {
            case SmtResult::Sat:
                if (Config::Analysis::abstraction_refinement) {
                    const auto res = refine();
                    if (res != SmtResult::Sat) {
                        return res;
                    }
                    changed = true;
                    solver->pop();
                    restart();
                    last_s = get_renaming(depth);
                    break;
                }
                return SmtResult::Unsat;
            case SmtResult::Unknown:
                return SmtResult::Unknown;
            case SmtResult::Unsat: {
                if (Config::Analysis::abstraction_refinement) {
                    if (depth > 1 && is_transitive()) {
                        if (Config::Analysis::log) {
                            std::cout << "***** Transitive *****" << std::endl;
                        }
                        return SmtResult::Sat;
                    }
                    if ((initial_phase && transitions.size() < depth) || (!initial_phase && changed)) {
                        if (Config::Analysis::log) {
                            std::cout << "***** Loop *****" << std::endl;
                        }
                        const auto its = build_approx_its();
                        Config::Analysis::abstraction_refinement = false;
                        TRL trl{its, Config::trp};
                        if (trl.analyze() == SmtResult::Sat) {
                            return SmtResult::Sat;
                        }
                        Config::Analysis::abstraction_refinement = true;
                        initial_phase = false;
                        changed = false;
                    }
                }
                solver->pop();
            }
        }
        const auto s = get_renaming(depth + 1);
        if (do_kind) {
            kind->add(!err->renameVars(last_s));
            kind->add(step->renameVars(last_s));
            kind->push();
            kind->add(err->renameVars(s));
            if (kind->check() == SmtResult::Unsat) {
                if (Config::Analysis::log) {
                    std::cout << "forward k-induction" << std::endl;
                }
                winner = Winner::KIND;
                return SmtResult::Sat;
            }
            kind->pop();
            bkind->add(!init->renameVars(s));
            bkind->add(step->renameVars(last_s));
            if (bkind->check() == SmtResult::Unsat) {
                if (Config::Analysis::log) {
                    std::cout << "backward k-induction" << std::endl;
                }
                winner = Winner::BKIND;
                return SmtResult::Sat;
            }
        }
        if (Config::Analysis::abstraction_refinement && sample()) {
            restart();
        } else {
            const auto do_step = Config::Analysis::abstraction_refinement ? abstraction : step;
            solver->push();
            solver->add(do_step->renameVars(last_s));
            if (solver->check() == SmtResult::Unsat) {
                return SmtResult::Sat;
            }
            ++depth;
            if (Config::Analysis::abstraction_refinement && initial_phase) {
                transitions.clear();
                const auto model = solver->model();
                for (size_t i = 0; i < depth; ++i) {
                    transitions.insert(model->get(id_var->renameVars(get_renaming(i))));
                }
            }
        }
        if (Config::Analysis::log) {
            std::cout << "depth: " << depth << std::endl;
        }
    }
}

ITSModel BMC::get_model() const {
    const auto step {bools::mkOr(sp.trans())};
    switch (winner) {
        case Winner::BMC: {
            std::vector res{sp.init()};
            Bools::Expr last{sp.init()};
            for (unsigned i = 0; i + 1 < depth; ++i) {
                const auto &s1{renamings.at(i)};
                last = last && step->renameVars(s1);
                Renaming s2;
                for (const auto &p: pre_to_post) {
                    theory::apply(
                        p,
                        [&](const auto& p) {
                            const auto& [pre, post] {p};
                            using T = decltype(theory::theory(pre));
                            if (pre->isProgVar()) {
                                s2.insert(s1.get(post), pre);
                                s2.insert(pre, T::next(pre->dim()));
                            }
                        });
                }
                res.push_back(last->renameVars(s2));
            }
            return to_safety.transform_model(bools::mkOr(res));
        }
        case Winner::KIND:
        case Winner::BKIND: {
            throw std::invalid_argument("models for k-induction are not yet supported");
        }
    }
    throw std::logic_error("model requested, but SAT was neither proved by BMC nor by k-induction");
}

ITSSafetyCex BMC::get_cex() const {
    SafetyCex res {sp};
    const auto candidates = sp.trans();
    const auto model {solver->model()};
    for (size_t i = 0; i < depth; ++i) {
        auto current {model->composeBackwards(renamings.at(i))};
        const auto it{std::ranges::find_if(candidates, [&](const auto &c) {
            return res.try_step(current, c);
        })};
        if (it == candidates.end()) {
            throw std::logic_error("get_cex failed");
        }
    }
    res.set_final_state(model->composeBackwards(renamings.at(depth)));
    return to_safety.transform_cex(res);
}
