#include "bmc.hpp"
#include "theory.hpp"
#include "smtfactory.hpp"
#include "config.hpp"
#include "renaming.hpp"
#include "intmbp.hpp"

BMC::BMC(const ITSPtr& p_its, const bool p_do_kind) :
    m_to_safety(p_its),
    sp(m_to_safety.transform()),
    m_init(p_do_kind ? mbp::int_qe(sp.init()) : sp.init()),
    m_step(bools::mkOr(sp.trans())),
    m_err(p_do_kind ? mbp::int_qe(sp.err()) : sp.err()),
    m_do_kind(p_do_kind) {}

void BMC::init() {
    const auto logic = max({Smt::chooseLogic(sp.init()), Smt::chooseLogic(m_step), Smt::chooseLogic(sp.err())});
    m_solver = SmtFactory::modelBuildingSolver(logic);
    m_kind = SmtFactory::modelBuildingSolver(logic);
    m_bkind = SmtFactory::modelBuildingSolver(logic);
    if (Config::Analysis::log) {
        std::cout << "safety problem:\n" << sp << std::endl;
    }
    m_solver->add(m_init);
    if (m_do_kind) {
        m_bkind->add(m_init);
    }
    m_init->collectVars(m_vars);
    m_step->collectVars(m_vars);
    m_err->collectVars(m_vars);
    for (const auto &var: m_vars) {
        theory::apply(
            var,
            [&](const auto& var) {
                if (var->isProgVar()) {
                    m_pre_to_post.insert(var, var->postVar());
                } else if (var->isPostVar()) {
                    m_pre_to_post.insert(var->progVar(), var);
                }
            });
    }
}

std::optional<SmtResult> BMC::do_step() {
    if (Config::Analysis::model) {
        m_renamings.emplace_back(m_last_s);
    }
    m_solver->push();
    m_solver->add(m_err->renameVars(m_last_s));
    switch (m_solver->check()) {
        case SmtResult::Sat:
            return SmtResult::Unsat;
        case SmtResult::Unknown:
            if (Config::Analysis::log && !m_approx) {
                std::cout << "got unknown from SMT solver -- approximating" << std::endl;
            }
            m_approx = true;
            break;
        case SmtResult::Unsat: {
        }
    }
    m_solver->pop();
    Renaming s;
    for (const auto &p: m_pre_to_post) {
        theory::apply(
            p,
            [&](const auto &p) {
                const auto &[pre, post]{p};
                using T = decltype(theory::theory(pre));
                s.insert(pre, m_last_s.get(post));
                s.insert(post, T::next(post->dim()));
            });
    }
    for (const auto &var: m_vars) {
        theory::apply(
            var,
            [&](const auto &var) {
                using T = decltype(theory::theory(var));
                if (var->isTempVar()) {
                    s.insert(var, T::next(var->dim()));
                }
            });
    }
    ++m_depth;
    if (!m_approx && m_do_kind) {
        m_kind->add(!m_err->renameVars(m_last_s));
        m_kind->add(m_step->renameVars(m_last_s));
        m_kind->push();
        m_kind->add(m_err->renameVars(s));
        if (m_kind->check() == SmtResult::Unsat) {
            if (Config::Analysis::log) {
                std::cout << "forward k-induction" << std::endl;
            }
            m_winner = Winner::KIND;
            return SmtResult::Sat;
        }
        m_kind->pop();
        m_bkind->add(!m_init->renameVars(s));
        m_bkind->add(m_step->renameVars(m_last_s));
        if (m_bkind->check() == SmtResult::Unsat) {
            if (Config::Analysis::log) {
                std::cout << "backward k-induction" << std::endl;
            }
            m_winner = Winner::BKIND;
            return SmtResult::Sat;
        }
    }
    m_solver->add(m_step->renameVars(m_last_s));
    if (m_solver->check() == SmtResult::Unsat) {
        if (m_approx) {
            return SmtResult::Unknown;
        }
        return SmtResult::Sat;
    }
    if (Config::Analysis::log) {
        std::cout << "depth: " << m_depth << std::endl;
    }
    m_last_s = s;
    return SmtResult::Unknown;
}

ITSModel BMC::get_model() {
    const auto step {bools::mkOr(sp.trans())};
    switch (m_winner) {
        case Winner::BMC: {
            std::vector res{sp.init()};
            Bools::Expr last{sp.init()};
            for (unsigned i = 0; i + 1 < m_depth; ++i) {
                const auto &s1{m_renamings.at(i)};
                last = last && step->renameVars(s1);
                Renaming s2;
                for (const auto &p: m_pre_to_post) {
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
            return m_to_safety.transform_model(bools::mkOr(res));
        }
        case Winner::KIND:
        case Winner::BKIND: {
            throw std::invalid_argument("models for k-induction are not yet supported");
        }
    }
    throw std::logic_error("model requested, but SAT was neither proved by BMC nor by k-induction");
}

ITSSafetyCex BMC::get_cex() {
    SafetyCex res {sp};
    const auto candidates = sp.trans();
    const auto model {m_solver->model()};
    for (size_t i = 0; i < m_depth; ++i) {
        auto current {model->composeBackwards(m_renamings.at(i))};
        const auto it{std::ranges::find_if(candidates, [&](const auto &c) {
            return res.try_step(current, c);
        })};
        if (it == candidates.end()) {
            throw std::logic_error("get_cex failed");
        }
    }
    res.set_final_state(model->composeBackwards(m_renamings.at(m_depth)));
    return m_to_safety.transform_cex(res);
}
