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

    auto step {bools::mkOr(sp.trans())};

    const auto err = do_kind ? mbp::int_qe(sp.err()) : sp.err();

    init->collectVars(vars);
    step->collectVars(vars);
    err->collectVars(vars);
    for (const auto &var: vars) {
        theory::apply(var, [&](const auto &var) {
            using T = decltype(theory::theory(var));
            if (var->isProgVar()) {
                pre_to_post.insert<T>(var, var->postVar());
            } else if (var->isPostVar()) {
                pre_to_post.insert<T>(var->progVar(), var);
            }
        });
    }

    Renaming last_s;
    while (true) {
        if (Config::Analysis::model) {
            renamings.emplace_back(last_s);
        }
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
        for (const auto &p: pre_to_post) {
            theory::apply(p, [&](const auto &p) {
                const auto &[pre,post] {p};
                using T = decltype(theory::theory(pre));
                s.insert<T>(pre, last_s.get<T>(post));
                s.insert<T>(post, T::next(pre->getDimension()));
            });
        }
        for (const auto &var: vars) {
            theory::apply(var, [&](const auto &var) {
                using T = decltype(theory::theory(var));
                if (var->isTempVar()) {
                    s.insert<T>(var, T::next(var->getDimension()));
                }
            });
        }
        ++depth;
        if (!approx && do_kind) {
            kind->add(last_s(!err));
            kind->add(last_s(step));
            kind->push();
            kind->add(s(err));
            if (kind->check() == SmtResult::Unsat) {
                if (Config::Analysis::log) {
                    std::cout << "forward k-induction" << std::endl;
                }
                winner = Winner::KIND;
                return SmtResult::Sat;
            }
            kind->pop();
            bkind->add(s(!init));
            bkind->add(last_s(step));
            if (bkind->check() == SmtResult::Unsat) {
                if (Config::Analysis::log) {
                    std::cout << "backward k-induction" << std::endl;
                }
                winner = Winner::BKIND;
                return SmtResult::Sat;
            }
        }
        solver->add(last_s(step));
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
    const auto step {bools::mkOr(sp.trans())};
    switch (winner) {
        case Winner::BMC: {
            std::vector<Bools::Expr> res{sp.init()};
            Bools::Expr last{sp.init()};
            for (unsigned i = 0; i + 1 < depth; ++i) {
                const auto &s1{renamings.at(i)};
                last = last && s1(step);
                Renaming s2;
                for (const auto &p: pre_to_post) {
                    theory::apply(p, [&](const auto &p) {
                        const auto &[pre,post] {p};
                        using T = decltype(theory::theory(pre));
                        if (pre->isProgVar()) {
                            s2.insert<T>(s1.get<T>(post), pre);
                            s2.insert<T>(pre, T::next(pre->getDimension()));
                        }
                    });
                }
                res.push_back(s2(last));
            }
            return to_safety.transform_model(bools::mkOr(res));
        }
        case Winner::KIND:
        case Winner::BKIND: {
            throw std::invalid_argument("models for k-induction are not yet supported");
        }
    }
}


ITSSafetyCex BMC::get_cex() const {
    SafetyCex res {sp};
    const auto candidates = sp.trans();
    const auto model {solver->model()};
    std::optional<Bools::Expr> last;
    for (size_t i = 0; i < depth; ++i) {
        const auto current {model.composeBackwards(renamings.at(i))};
        const auto it{std::find_if(candidates.begin(), candidates.end(), [&](const auto &c) {
            return res.try_step(current, c);
        })};
        if (it == candidates.end()) {
            throw std::logic_error("get_cex failed");
        }
        last = *it;
    }
    res.set_final_state(model.composeBackwards(renamings.at(depth)));
    return to_safety.transform_cex(res);
}
