#include "impliedequalities.hpp"

Subs impliedEqualities(const Bools::Expr e) {
    Subs res;
    std::vector<Bools::Expr> todo;
    const auto find_elim = [](const Bools::Expr &c) {
        std::optional<Bools::Var> elim;
        const auto vars {c->vars().template get<Bools::Var>()};
        for (const auto &x: vars) {
            if (x->isTempVar()) {
                if (elim) {
                    return std::optional<Bools::Var>{};
                } else {
                    elim = x;
                }
            }
        }
        return elim;
    };
    if (e->isAnd()) {
        const auto children {e->getChildren()};
        for (const auto &c: children) {
            if (c->isOr()) {
                const auto elim {find_elim(c)};
                if (elim) {
                    auto grandChildren {c->getChildren()};
                    auto lit {bools::mkLit(BoolLit(*elim))};
                    bool positive {grandChildren.contains(lit)};
                    if (!positive) {
                        lit = !lit;
                        if (!grandChildren.contains(lit)) {
                            continue;
                        }
                    }
                    grandChildren.erase(lit);
                    const Bools::Expr cand {bools::mkOr(grandChildren)};
                    // we have     lit \/  cand
                    // search for !lit \/ !cand
                    if (children.contains((!lit) || (!cand))) {
                        // we have (lit \/ cand) /\ (!lit \/ !cand), i.e., lit <==> !cand
                        res.put(*elim, positive ? !cand : cand);
                    }
                }
            }
        }
        todo.insert(todo.end(), children.begin(), children.end());
    } else {
        todo.push_back(e);
    }
    for (const auto &current: todo) {
        if (current->isOr()) {
            const auto children {current->getChildren()};
            if (children.size() == 2) {
                for (const auto &c: children) {
                    if (c->isAnd()) {
                        const auto elim {find_elim(c)};
                        if (elim) {
                            auto grandChildren {c->getChildren()};
                            auto lit {bools::mkLit(BoolLit(*elim))};
                            bool positive {grandChildren.contains(lit)};
                            if (!positive) {
                                lit = !lit;
                                if (!grandChildren.contains(lit)) {
                                    continue;
                                }
                            }
                            grandChildren.erase(lit);
                            const Bools::Expr cand {bools::mkAnd(grandChildren)};
                            if (children.contains((!lit) && (!cand))) {
                                // we have (lit /\ cand) \/ (!lit /\ !cand), i.e., lit <==> cand
                                res.put(*elim, positive ? cand : !cand);
                            }
                        }
                    }
                }
            }
        } else if (current->isTheoryLit()) {
            const auto lit {*current->getTheoryLit()};
            if (std::holds_alternative<BoolLit>(lit)) {
                const auto &bool_lit {std::get<BoolLit>(lit)};
                const auto var {bool_lit.getBoolVar()};
                if (var->isTempVar()) {
                    res.put(var, bool_lit.isNegated() ? bot() : top());
                }
            }
        }
    }
    return res;
}
