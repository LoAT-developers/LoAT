#include "itssafetycex.hpp"
#include "vector.hpp"
#include "smtfactory.hpp"

#include <cassert>

void ITSSafetyCex::do_step(const RulePtr& trans, const ModelPtr &next) {
    if (!is_known(trans)) {
        throw std::logic_error("adding unknown rule " + toString(trans->getId()) + " to cex");
    }
    m_states.push_back(next);
    m_transitions.push_back(trans);
}

void ITSSafetyCex::set_initial_state(const ModelPtr &m) {
    assert(m_transitions.empty());
    m_states.clear();
    m_states.push_back(m);
}

std::ostream& operator<<(std::ostream &s, const ITSSafetyCex &cex) {
    const auto derived {cex.get_used_rules()};
    if (!derived.empty()) {
        s << "\n\nrules:" << std::endl;
        for (const auto &[t,kind]: derived) {
            s << "\t" << *t << std::endl;
            switch (kind) {
                case ProofStepKind::ORIG: {
                    s << "\t\toriginal rule" << std::endl;
                    break;
                }
                case ProofStepKind::IMPLICANT: {
                    s << "\t\t-" << t << "-> is subset of -" << cex.implicants.at(t).in() << "->\n";
                    break;
                }
                case ProofStepKind::ACCEL: {
                    s << "\t\t-" << t << "-> is subset of -" << cex.accel.at(t).in() << "->^+" << std::endl;
                    break;
                }
                case ProofStepKind::RESOLVENT: {
                    s << "\t\t" << "chain(";
                    auto first{true};
                    for (const auto &r : cex.resolvents.at(t).in()) {
                        if (first) {
                            s << r;
                            first = false;
                        } else {
                            s << ", " << r;
                        }
                    }
                    s << ") = " << t << std::endl;
                    break;
                }
                case ProofStepKind::RECURRENT_SET: {
                    s << "\t\tguard(" << t << ") is a recurrent set of " << cex.recurrent_set.at(t) << std::endl;
                    break;
                }
            }
        }
        s << "\ncounterexample:" << std::endl;
        VarSet prog_vars;
        for (size_t i = 0; i < cex.m_transitions.size(); ++i) {
            const auto &trans{cex.m_transitions.at(i)};
            auto vars{trans->vars()};
            s << "\t" << cex.m_states.at(i)->toString(prog_vars) << "\n\t-" << trans->getId() << "->\n";
        }
        s << "\terr";
    }
    return s;
}

size_t ITSSafetyCex::num_states() const {
    return m_states.size();
}

ModelPtr ITSSafetyCex::get_state(const size_t i) const {
    return m_states.at(i);
}

ITSSafetyCex::ITSSafetyCex(const ITSPtr p_its): ITSCex(p_its->getAllTransitions()), m_its(p_its) {}

size_t ITSSafetyCex::num_transitions() const {
    return m_transitions.size();
}

RulePtr ITSSafetyCex::get_transition(const size_t i) const {
    return m_transitions.at(i);
}

std::vector<std::pair<RulePtr, ProofStepKind>> ITSSafetyCex::get_used_rules() const {
    return ITSCex::get_used_rules(m_transitions);
}

Bools::Expr ITSSafetyCex::instantiate_pre(const ModelPtr m) const {
    LitSet res;
    for (const auto &x: m_its->getVars()) {
        if (theory::isProgVar(x)) {
            theory::apply(
                x,
                [&](const Arrays<Arith>::Var &x) {
                    if (x->dim() > 0) {
                        throw std::invalid_argument("recurrent sets are not supported for arrays");
                    }
                    res.insert(arith::mkEq(arrays::readConst(x), arith::mkConst(m->eval(arrays::readConst(x)))));
                }, [&](const Bools::Var &x) {
                    res.insert(bools::mk(x, m->get(x)));
                });
        }
    }
    return bools::mkAnd(res);
}

Bools::Expr ITSSafetyCex::instantiate_post(const RulePtr t, const ModelPtr m) const {
    BoolExprSet res;
    for (const auto &x: m_its->getVars()) {
        if (theory::isProgVar(x)) {
            theory::apply(
                x,
                [&](const Arrays<Arith>::Var &x) {
                    if (x->dim() > 0) {
                        throw std::invalid_argument("recurrent sets are not supported for arrays");
                    }
                    const auto post = arrays::readConst(t->getUpdate().get(x));
                    res.insert(bools::mkLit(arith::mkEq(post, arith::mkConst(m->eval(post)))));
                }, [&](const Bools::Var &x) {
                    const auto post = t->getUpdate().get(x);
                    res.insert(Bools::mkEq(post, m->eval(post) ? top() : bot()));
                });
        }
    }
    return bools::mkAnd(res);
}

Bools::Expr ITSSafetyCex::instantiate_tmp(const Bools::Expr b, const ModelPtr m, const CellSet& keep) const {
    Subs subs;
    for (const auto &x: b->cells()) {
        if (theory::isTempCell(x) && !keep.contains(x)) {
            theory::apply(
                x,
                [&](const Bools::Var &x) {
                    subs.put(x, m->get(x) ? top() : bot());
                }, [&](const ArrayReadPtr<Arith> &x) {
                    subs.update(x, arith::mkConst(m->eval(x)));
                });
        }
    }
    return b->subs(subs);
}

void ITSSafetyCex::complete_recurrent_set(ITSRecurrentSet& rs, const RulePtr rule, const ModelPtr model, const bool with_start) const {
    assert(model->eval(rule->getGuard()));
    const auto src = model->get(ITSProblem::loc_var());
    const auto dst = model->eval(ITSProblem::loc_var()->subs(rule->getUpdate()));
    if (resolvents.contains(rule)) {
        const auto ri = resolvents.at(rule);
        const auto& in = ri.in();
        const auto models = ri.transform_model(model);
        for (int i = ri.size() - 1; i >= 0; --i) {
            complete_recurrent_set(rs, in.at(i), models.at(i), with_start || i > 0);
        }
    } else if (accel.contains(rule)) {
        const auto ai = accel.at(rule);
        const auto& already_reached = rs.get(dst);
        Renaming ren;
        ren.insert(ai.n()->var(), arrays::nextConst<Arith>()->var());
        const auto renamed = rule->renameVars(ren);
        const CellSet keep {ai.n()};
        const auto applicable = instantiate_tmp(renamed->getGuard(), model, keep)->renameVars(ren);
        const auto bounded = bools::mkLit(arith::mkLeq(ai.n(), arith::mkConst(model->get(ai.n()))))->renameVars(ren);
        for (const auto b: already_reached) {
            const auto reachable = instantiate_tmp(b->subs(rule->getUpdate()), model, keep)->renameVars(ren);
            rs.add(src, BoolExprSet{applicable, reachable, bounded});
        }
        complete_recurrent_set(rs, ai.in(), model, with_start);
    } else if (recurrent_set.contains(rule)) {
        complete_recurrent_set(rs, recurrent_set.at(rule), model, with_start);
    } else if (implicants.contains(rule)) {
        const auto ti = implicants.at(rule);
        complete_recurrent_set(rs, ti.in(), ti.transform_model(model), with_start);
    } else {
        rs.add(rule);
        if (with_start) {
            const auto applicable = instantiate_tmp(rule->getGuard(), model);
            const auto& already_reached = rs.get(dst);
            for (const auto& b: already_reached) {
                const auto reachable = instantiate_tmp(b->subs(rule->getUpdate()), model);
                rs.add(src, BoolExprSet{applicable, reachable});
            }
        }
    }
}

ITSRecurrentSet ITSSafetyCex::to_recurrent_set() const {

    ITSRecurrentSet res;

    for (unsigned i = 0; i < m_transitions.size(); ++i) {
        const auto t = m_transitions.at(i);
        const auto from = m_states.at(i);
        const auto src = from->eval(ITSProblem::loc_var());
        if (recurrent_set.contains(t)) {
            res.add(src, instantiate_tmp(t->getGuard(), from));
        } else {
            const auto to = m_states.at(i+1);
            const auto dst = to->eval(ITSProblem::loc_var());
            if (accel.contains(t)) {
                const auto reached = instantiate_pre(to);
                const auto reachable = instantiate_tmp(instantiate_post(m_transitions.at(i), from), from);
                const auto applicable = instantiate_tmp(t->getGuard(), from);
                // the final value is in the recurrent set
                res.add(dst, reached);
                // all values that can reach the final value are in the recurrent set
                res.add(src, applicable && reachable);
            } else {
                const auto lhs_reached = instantiate_pre(from);
                const auto rhs_reached = instantiate_pre(to);
                res.add(src, lhs_reached);
                res.add(dst, rhs_reached);
            }
        }
        complete_recurrent_set(res, t, m_states.at(i), false);
    }
    res.simplify();
    return res;
}
