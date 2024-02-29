#include "theory.hpp"
#include "literal.hpp"

namespace theory {

std::string getName(const Var &var) {
    return std::visit([](const auto &var){return var->getName();}, var);
}

bool isTempVar(const Var &var) {
    return std::visit([](const auto &var){return var->isTempVar();}, var);
}

bool isProgVar(const Var &var) {
    return !isTempVar(var);
}

Var next(const Var &var) {
    return std::visit([](const auto x) {return Var(decltype(x)::element_type::next());}, var);
}

ThExpr toExpr(const Var &var) {
    return TheTheory::varToExpr(var);
}

void collectVars(const ThExpr &expr, VarSet &vars) {
    std::visit(Overload{
                   [&vars](const ArithExprPtr expr) {
                       expr->collectVars(vars.get<ArithVarPtr>());
                   },
                   [&vars](const BoolExpr expr) {
                       expr->collectVars(vars);
                   }
               }, expr);
}

VarSet vars(const ThExpr &e) {
    VarSet res;
    collectVars(e, res);
    return res;
}

VarSet vars(const Subs &e) {
    VarSet res;
    collectVars(e, res);
    return res;
}

void collectVars(const Subs &subs, VarSet &vars) {
    for (const auto &[x,y]: subs) {
        vars.insert(x);
        theory::collectVars(y, vars);
    }
}

VarSet coDomainVars(const Subs &subs) {
    VarSet res;
    collectCoDomainVars(subs, res);
    return res;
}

void collectVariables(VarSet &res, const Lit &e) {
    theories::collectVars<Arith, Bools>(e, res);
}

VarSet variables(const Lit &e) {
    return theories::vars<Arith, Bools>(e);
}

bool isTriviallyTrue(const Lit &lit) {
    return theories::isTriviallyTrue<Arith, Bools>(lit);
}

Lit negate(const Lit &lit) {
    return theories::negate<Arith, Bools>(lit);
}

BoolExpr mkEq(const ThExpr &e1, const ThExpr &e2) {
    return std::visit(
        Overload {
            [&e2](const ArithExprPtr &e1) {
                return bools::mkAndFromLits(
                    std::vector<Lit>{arith::mkGeq(e1, std::get<ArithExprPtr>(e2)),
                                     arith::mkLeq(e1, std::get<ArithExprPtr>(e2))});
            },
            [&e2](const BoolExpr lhs) {
                const auto rhs = std::get<BoolExpr>(e2);
                return (lhs && rhs) || ((!lhs) && (!rhs));
            }
        }, e1);
}

BoolExpr mkNeq(const ThExpr &e1, const ThExpr &e2) {
    return std::visit(
        Overload {
            [&e2](const ArithExprPtr &e1) {
                return bools::mkOrFromLits(
                    std::vector<Lit>{arith::mkGt(e1, std::get<ArithExprPtr>(e2)),
                                     arith::mkLt(e1, std::get<ArithExprPtr>(e2))});
            },
            [&e2](const BoolExpr lhs) {
                const auto rhs = std::get<BoolExpr>(e2);
                return (lhs && (!rhs)) || ((!lhs) && rhs);
            }
        }, e1);
}

Arith theory(const ArithVarPtr&) {
    return arith::t;
}

Bools theory(const BoolVarPtr&) {
    return bools::t;
}

Arith theory(const ArithExprPtr&) {
    return arith::t;
}

Bools theory(const BoolExpr&) {
    return bools::t;
}

template <size_t I = 0>
inline bool isLinearImpl(const Lit &lit) {
    if constexpr (I < std::variant_size_v<ThExpr>) {
        if (lit.index() == I) {
            return std::get<I>(lit).isLinear();
        }
        return isLinearImpl<I+1>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

bool isLinear(const Lit &lit) {
    return isLinearImpl<0>(lit);
}

template <size_t I = 0>
inline bool isPolyImpl(const Lit &lit) {
    if constexpr (I < std::variant_size_v<ThExpr>) {
        if (lit.index() == I) {
            return std::get<I>(lit).isPoly();
        }
        return isPolyImpl<I+1>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

bool isPoly(const Lit &lit) {
    return isPolyImpl<0>(lit);
}

Subs impliedEqualities(const BoolExpr e) {
    Subs res;
    std::vector<BoolExpr> todo;
    const auto find_elim = [](const BoolExpr &c) {
        std::optional<BoolVarPtr> elim;
        const auto vars {c->vars().template get<BoolVarPtr>()};
        for (const auto &x: vars) {
            if (x->isTempVar()) {
                if (elim) {
                    return std::optional<BoolVarPtr>{};
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
                    const BoolExpr cand {bools::mkOr(grandChildren)};
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
                            const BoolExpr cand {bools::mkAnd(grandChildren)};
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

}

std::ostream& operator<<(std::ostream &s, const Var &e) {
    std::visit([&s](const auto &e){s << theory::getName(e);}, e);
    return s;
}

std::ostream& operator<<(std::ostream &s, const ThExpr &e) {
    std::visit([&s](const auto &e){s << e;}, e);
    return s;
}

std::ostream& operator<<(std::ostream &s, const Lit &e) {
    std::visit([&s](const auto &e){s << e;}, e);
    return s;
}
