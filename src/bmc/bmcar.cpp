#include "bmcar.hpp"

#include "theory.hpp"
#include "smtfactory.hpp"
#include "config.hpp"
#include "renaming.hpp"
#include "intmbp.hpp"
#include "trl.hpp"

void BMCAR::initialize() {
    const auto logic = max({Smt::chooseLogic(sp.init()), Smt::chooseLogic(step), Smt::chooseLogic(sp.err())});
    solver = SmtFactory::modelBuildingSolver(logic);
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
    solver->add(init);
}

BMCAR::BMCAR(const SafetyProblem& sp, const ArithVarPtr loc_var) :
    sp(sp),
    init(sp.init()),
    err(sp.err()),
    step(bools::mkOr(sp.trans())),
    loc_var(loc_var) {
    initialize();
}

BMCAR::BMCAR(const ITSPtr& its) :
    to_safety(its),
    sp(to_safety->transform()),
    init(sp.init()),
    err(sp.err()),
    step(bools::mkOr(sp.trans())),
    loc_var(its->getLocVar()) {
    initialize();
}

Bools::Expr BMCAR::encode_transition(const Bools::Expr trans, const Int id) const {
    return trans && bools::mkLit(arith::mkEq(id_var, arith::mkConst(id)));
}

void BMCAR::restart() {
    if (Config::Analysis::log) {
        std::cout << "***** Restart *****" << std::endl;
    }
    while (depth > 0) {
        solver->pop();
        --depth;
    }
}

bool BMCAR::sample() {
    std::vector<Bools::Expr> all_abstractions;
    for (const auto& a: abstractions | std::views::values) {
        all_abstractions.emplace_back(bools::mkAnd(a));
    }
    for (const auto& l: learned) {
        all_abstractions.emplace_back(l);
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

void BMCAR::build_abstraction() {
    BoolExprSet new_abstractions;
    for (const auto& [id,a]: abstractions) {
        new_abstractions.insert(encode_transition(bools::mkAnd(a), id));
    }
    abstraction = bools::mkOr(new_abstractions);
}

SmtResult BMCAR::refine() {
    const auto model = solver->model();
    solver->push();
    BoolExprSet assumptions;
    std::unordered_map<Bools::Expr, std::pair<Int, Bools::Expr>> assumption_to_refinement;
    for (unsigned i = 0; i < depth; ++i) {
        const auto subs = get_renaming(i);
        const auto renamed_id_var = id_var->renameVars(subs);
        const auto id = model->get(renamed_id_var);
        solver->add(bools::mkLit(arith::mkEq(renamed_id_var, arith::mkConst(id))));
        const auto abstraction = abstractions.at(id);
        for (const auto concretization = transitions.at(id); const auto& c: concretization) {
            if (!abstraction.contains(c)) {
                const auto assumption = c->renameVars(subs);
                assumptions.insert(assumption);
                assumption_to_refinement.emplace(assumption, std::pair{id, c});
            }
        }
    }
    switch (const auto &[sat,core] = solver->check_with_assumptions(assumptions); sat) {
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
                if (abstractions.contains(id)) {
                    abstractions.at(id).insert(refinement);
                }
                if (Config::Analysis::log) {
                    std::cout << id << ": " << refinement << std::endl;
                }
            }
            build_abstraction();
            solver->pop();
            return SmtResult::Sat;
        }
    }
    throw std::logic_error("unreachable");
}

Renaming BMCAR::get_renaming(const unsigned i) {
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

bool BMCAR::is_transitive() {
    const auto snd = get_renaming(1);
    return SmtFactory::check(abstraction && abstraction->renameVars(snd) && !abstraction->renameVars(two_steps)) == SmtResult::Unsat;
}

SafetyProblem BMCAR::build_approx_sp() {
    SafetyProblem res;
    res.set_init(init);
    res.set_err(err);
    for (const auto& a: abstractions | std::views::values) {
        res.add_transition(bools::mkAnd(a));
    }
    for (const auto& [pre,post]: pre_to_post) {
        res.add_pre_var(pre);
        res.add_post_var(post);
    }
    return res;
}

SmtResult BMCAR::analyze() {
    if (Config::Analysis::log) {
        std::cout << "safety problem:\n" << sp << std::endl;
    }
    std::unordered_set<Int> transitions;
    auto changed = false;
    while (true) {
        auto last_s = get_renaming(depth);
        solver->push();
        solver->add(err->renameVars(last_s));
        switch (solver->check()) {
            case SmtResult::Sat: {
                assert(completeness_threshold == 0);
                if (const auto res = refine(); res != SmtResult::Sat) {
                    return res;
                }
                changed = true;
                solver->pop();
                restart();
                continue;
            }
            case SmtResult::Unknown:
                return SmtResult::Unknown;
            case SmtResult::Unsat: {
                if (depth > 1 && is_transitive()) {
                    if (Config::Analysis::log) {
                        std::cout << "***** Transitive *****" << std::endl;
                    }
                    return SmtResult::Sat;
                }
                if (transitions.size() < depth && changed) {
                    if (Config::Analysis::log) {
                        std::cout << "***** Loop *****" << std::endl;
                    }
                    changed = false;
                    const auto sp = build_approx_sp();
                    if (TRL trl{sp, loc_var, Config::trp}; trl.analyze() == SmtResult::Sat) {
                        learned = trl.get_learned_transitions();
                        completeness_threshold = trl.get_depth();
                        abstraction = abstraction || bools::mkOr(learned);
                        restart();
                        continue;
                    }
                }
                solver->pop();
            }
        }
        if (depth > completeness_threshold && completeness_threshold > 0) {
            return SmtResult::Sat;
        }
        if (sample()) {
            if (completeness_threshold > 0) {
                learned.clear();
                completeness_threshold = 0;
                build_abstraction();
            }
            restart();
            continue;
        }
        solver->push();
        solver->add(abstraction->renameVars(last_s));
        if (solver->check() == SmtResult::Unsat) {
            return SmtResult::Sat;
        }
        ++depth;
        transitions.clear();
        const auto model = solver->model();
        for (size_t i = 0; i < depth; ++i) {
            transitions.insert(model->get(id_var->renameVars(get_renaming(i))));
        }
        if (Config::Analysis::log) {
            std::cout << "depth: " << depth << std::endl;
        }
    }
}

