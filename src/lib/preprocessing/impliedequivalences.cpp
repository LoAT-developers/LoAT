#include "impliedequivalences.hpp"
#include "subs.hpp"

Subs impliedEquivalences(const Bools::Expr& e) {
    Subs res;
    std::vector<Bools::Expr> todo;
    const auto find_elim = [](const Bools::Expr &c) {
        std::optional<Bools::Var> elim;
        for (const auto vars {c->vars().get<Bools::Var>()}; const auto &x: vars) {
            if (x->isTempVar()) {
                if (elim) {
                    return std::optional<Bools::Var>{};
                }
                elim = x;
            }
        }
        return elim;
    };
    if (e->isAnd()) {
        const auto children {e->getChildren()};
        for (const auto &c: children) {
            if (c->isOr()) {
                if (const auto elim {find_elim(c)}) {
                    auto grandChildren {c->getChildren()};
                    auto lit {bools::mkLit(bools::mk(*elim))};
                    bool positive {grandChildren.contains(lit)};
                    if (!positive) {
                        lit = !lit;
                        if (!grandChildren.contains(lit)) {
                            continue;
                        }
                    }
                    grandChildren.erase(lit);
                    // we have     lit \/  cand
                    // search for !lit \/ !cand
                    if (const Bools::Expr cand {bools::mkOr(grandChildren)}; children.contains(!lit || !cand)) {
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
            if (const auto children {current->getChildren()}; children.size() == 2) {
                for (const auto &c: children) {
                    if (c->isAnd()) {
                        if (const auto elim {find_elim(c)}) {
                            auto grandChildren {c->getChildren()};
                            auto lit {bools::mkLit(bools::mk(*elim))};
                            bool positive {grandChildren.contains(lit)};
                            if (!positive) {
                                lit = !lit;
                                if (!grandChildren.contains(lit)) {
                                    continue;
                                }
                            }
                            grandChildren.erase(lit);
                            if (const Bools::Expr cand {bools::mkAnd(grandChildren)}; children.contains(!lit && !cand)) {
                                // we have (lit /\ cand) \/ (!lit /\ !cand), i.e., lit <==> cand
                                res.put(*elim, positive ? cand : !cand);
                            }
                        }
                    }
                }
            }
        } else if (current->isTheoryLit()) {
            if (const auto lit {*current->getTheoryLit()}; std::holds_alternative<Bools::Lit>(lit)) {
                const auto &bool_lit {std::get<Bools::Lit>(lit)};
                if (const auto var {bool_lit->getBoolVar()}; var->isTempVar()) {
                    res.put(var, bool_lit->isNegated() ? bot() : top());
                }
            }
        }
    }
    return res;
}
