#include "bmc.hpp"
#include "theory.hpp"
#include "smtfactory.hpp"
#include "config.hpp"
#include "renaming.hpp"
#include "intmbp.hpp"

BMC::BMC(ITSPtr its, const bool do_kind): to_safety(its), do_kind(do_kind) {
    sp = to_safety.transform();
}

SmtResult BMC::analyze() {
    if (Config::Analysis::log) {
        std::cout << "safety problem:\n" << sp << std::endl;
    }
    const auto init = do_kind ? mbp::int_qe(sp.init()) : sp.init();
    solver->add(init);
    if (do_kind) {
        bkind->add(init);
    }

    // auto step {bools::mkOr(sp.trans())};
    auto step {top()};
    if (do_kind) {
        std::vector<Bools::Expr> disjuncts;
        for (const auto &x: sp.trans()) {
            disjuncts.emplace_back(mbp::int_qe(x));
        }
        step = bools::mkOr(disjuncts);
    } else {
       step = bools::mkOr(sp.trans());
    }

    const auto err = do_kind ? mbp::int_qe(sp.err()) : sp.err();

    init->collectVars(vars);
    step->collectVars(vars);
    err->collectVars(vars);
    for (const auto &var: vars) {
        if (theory::isProgVar(var)) {
            pre_to_post.insert(var, theory::postVar(var));
        } else if (theory::isPostVar(var)) {
            pre_to_post.insert(theory::progVar(var), var);
        }
    }

    Renaming last_s;
    while (true) {
        solver->push();
        solver->add(last_s(err));
        switch (solver->check()) {
        case SmtResult::Sat:
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
        Renaming s;
        for (const auto &[pre,post]: pre_to_post) {
            s.insert(pre, last_s.get(post));
            s.insert(post, theory::next(post));
        }
        for (const auto &var: vars) {
            if (theory::isTempVar(var)) {
                s.insert(var, theory::next(var));
            }
        }
        if (Config::Analysis::model) {
            renamings.emplace_back(last_s);
        }
        if (do_kind) {
            kind->add(last_s(!err));
            kind->add(last_s(step));
            kind->push();
            kind->add(s(err));
            if (kind->check() == SmtResult::Unsat) {
                if (Config::Analysis::log) {
                    std::cout << "forward k-induction" << std::endl;
                }
                return SmtResult::Sat;
            }
            kind->pop();
            bkind->add(s(!init));
            bkind->add(last_s(step));
            if (bkind->check() == SmtResult::Unsat) {
                if (Config::Analysis::log) {
                    std::cout << "backward k-induction" << std::endl;
                }
                return SmtResult::Sat;
            }
        }
        solver->add(last_s(step));
        ++depth;
        if (solver->check() == SmtResult::Unsat) {
            if (approx) {
                return SmtResult::Unknown;
            } else {
                return SmtResult::Sat;
            }
        }
        if (Config::Analysis::log) {
            std::cout << "depth: " << depth << std::endl;
        }
        last_s = s;
    }
}

ITSModel BMC::get_model() const {
    // std::vector<Bools::Expr> steps;
    // std::vector<Bools::Expr> inits;
    // for (const auto &t: its->getAllTransitions()) {
    //     if (its->isInitialTransition(t)) {
    //         inits.push_back(t->getGuard());
    //         continue;
    //     }
    //     if (its->isSinkTransition(t)) {
    //         continue;
    //     }
    //     std::vector<Bools::Expr> conjuncts;
    //     conjuncts.emplace_back(t->getGuard());
    //     const auto &up {t->getUpdate()};
    //     for (const auto &[pre,post]: pre_to_post) {
    //         if (theory::isProgVar(pre)) {
    //             conjuncts.push_back(theory::mkEq(theory::toExpr(post), up.get(pre)));
    //         }
    //     }
    //     steps.push_back(bools::mkAnd(std::move(conjuncts)));
    // }
    // const auto step {bools::mkOr(steps)};
    // const auto init {bools::mkOr(inits)};
    // std::vector<Bools::Expr> res{init};
    // Bools::Expr last{init};
    // for (unsigned i = 0; i + 1 < depth; ++i) {
    //     const auto &s1{renamings.at(i)};
    //     last = last && s1(step);
    //     Renaming s2;
    //     for (const auto &[pre,post]: pre_to_post) {
    //         if (theory::isProgVar(pre)) {
    //             s2.insert(s1.get(post), pre);
    //             s2.insert(pre, theory::next(pre));
    //         }
    //     }
    //     res.push_back(s2(last));
    // }
    // ITSModel model;
    // const auto m {bools::mkOr(res)};
    // for (const auto &l: its->getLocations()) {
    //     model.set_invariant(l, Subs::build<Arith>(its->getLocVar(), arith::mkConst(l))(m));
    // }
    // model.set_invariant(its->getInitialLocation(), top());
    // return model;
}


ITSCex BMC::get_cex() const {
    // ITSCex res(its);
    // const auto model {solver->model()};
    // std::optional<RulePtr> last;
    // res.set_initial_state(model.composeBackwards(renamings.front()));
    // for (size_t i = 0; i <= depth; ++i) {
    //     const auto current {model.composeBackwards(renamings.at(i + 1))};
    //     const auto candidates = last ? its->getSuccessors(*last) : its->getInitialTransitions();
    //     const auto it{std::find_if(candidates.begin(), candidates.end(), [&](const auto &c) {
    //         return res.try_step(c, current);
    //     })};
    //     if (it == candidates.end()) {
    //         throw std::logic_error("get_cex failed");
    //     }
    //     last = *it;
    // }
    // const auto candidates {its->getSinkTransitions()};
    // const auto it{std::find_if(candidates.begin(), candidates.end(), [&](const auto &c) {
    //     return res.try_final_transition(c);
    // })};
    // if (it == candidates.end()) {
    //     throw std::logic_error("get_cex failed");
    // }
    // return res;
}
