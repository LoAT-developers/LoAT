#include "bmc.hpp"
#include "theory.hpp"
#include "smtfactory.hpp"
#include "config.hpp"
#include "renaming.hpp"
#include "intmbp.hpp"

BMC::BMC(const ITSPtr& its, const bool do_kind) :
    to_safety(its),
    sp(to_safety.transform()),
    step(bools::mkOr(sp.trans())),
    do_kind(do_kind) {
    const auto logic = max({Smt::chooseLogic(sp.init()), Smt::chooseLogic(step), Smt::chooseLogic(sp.err())});
    solver = SmtFactory::modelBuildingSolver(logic);
    kind = SmtFactory::modelBuildingSolver(logic);
    bkind = SmtFactory::modelBuildingSolver(logic);
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

    const auto step {bools::mkOr(sp.trans())};

    const auto err = do_kind ? mbp::int_qe(sp.err()) : sp.err();

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

    Renaming last_s;
    while (true) {
        if (Config::Analysis::model) {
            renamings.emplace_back(last_s);
        }
        solver->push();
        solver->add(err->renameVars(last_s));
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
        for (const auto &p: pre_to_post) {
            theory::apply(
                p,
                [&](const auto& p) {
                    const auto& [pre, post] {p};
                    using T = decltype(theory::theory(pre));
                    s.insert(pre, last_s.get(post));
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
        ++depth;
        if (!approx && do_kind) {
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
        solver->add(step->renameVars(last_s));
        if (solver->check() == SmtResult::Unsat) {
            if (approx) {
                return SmtResult::Unknown;
            }
            return SmtResult::Sat;
        }
        if (Config::Analysis::log) {
            std::cout << "depth: " << depth << std::endl;
        }
        last_s = s;
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
