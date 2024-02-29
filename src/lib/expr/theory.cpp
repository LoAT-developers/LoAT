#include "theory.hpp"

const BoolExprPtr top() {
    return BoolExpr::top();
}

const BoolExprPtr bot() {
    return BoolExpr::bot();
}

namespace bools {

Bools::Expr mkLit(const TheTheory::Lit &lit) {
    return BoolExpr::mkLit(lit);
}

Bools::Expr mkAndFromLits(const std::initializer_list<Lit> &lits) {
    return BoolExpr::mkAndFromLits(lits);
}

}

namespace theory {

constexpr size_t num_theories {std::tuple_size_v<TheTheory::Theories>};

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
                   [&vars](const BoolExprPtr expr) {
                       expr->collectVars(vars);
                   }
               }, expr);
}

VarSet vars(const ThExpr &e) {
    VarSet res;
    collectVars(e, res);
    return res;
}

BoolExprPtr mkEq(const ThExpr &e1, const ThExpr &e2) {
    return std::visit(
        Overload {
            [&e2](const ArithExprPtr &e1) {
                return bools::mkAndFromLits(
                    std::vector<Lit>{arith::mkGeq(e1, std::get<ArithExprPtr>(e2)),
                                     arith::mkLeq(e1, std::get<ArithExprPtr>(e2))});
            },
            [&e2](const BoolExprPtr lhs) {
                const auto rhs = std::get<BoolExprPtr>(e2);
                return (lhs && rhs) || ((!lhs) && (!rhs));
            }
        }, e1);
}

BoolExprPtr mkNeq(const ThExpr &e1, const ThExpr &e2) {
    return std::visit(
        Overload {
            [&e2](const ArithExprPtr &e1) {
                return bools::mkOrFromLits(
                    std::vector<Lit>{arith::mkGt(e1, std::get<ArithExprPtr>(e2)),
                                     arith::mkLt(e1, std::get<ArithExprPtr>(e2))});
            },
            [&e2](const BoolExprPtr lhs) {
                const auto rhs = std::get<BoolExprPtr>(e2);
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

Bools theory(const BoolExprPtr&) {
    return bools::t;
}

template <size_t I = 0>
inline bool isLinearImpl(const Lit &lit) {
    if constexpr (I < num_theories) {
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
    if constexpr (I < num_theories) {
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

template<std::size_t I = 0>
inline void collectVarsImpl(const Lit &lit, VarSet &s) {
    if constexpr (I < num_theories) {
        if (lit.index() == I) {
            return std::get<I>(lit).collectVars(s.template get<I>());
        } else {
            return collectVarsImpl<I+1>(lit, s);
        }
    } else {
        throw std::logic_error("unknown theory");
    }
}


void collectVars(const Lit &lit, VarSet &s) {
    collectVarsImpl<0>(lit, s);
}

VarSet vars(const Lit &lit) {
    VarSet res;
    collectVars(lit, res);
    return res;
}

template <size_t I = 0>
inline bool isTriviallyTrueImpl(const Lit &lit) {
    if constexpr (I < num_theories) {
        if (lit.index() == I) {
            return std::get<I>(lit).isTriviallyTrue();
        }
        return isTriviallyTrueImpl<I+1>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

bool isTriviallyTrue(const Lit &lit) {
    return isTriviallyTrueImpl<0>(lit);
}

template <size_t I = 0>
inline bool isTriviallyFalseImpl(const Lit &lit) {
    if constexpr (I < num_theories) {
        if (lit.index() == I) {
            return std::get<I>(lit).isTriviallyFalse();
        }
        return isTriviallyFalseImpl<I+1>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

bool isTriviallyFalse(const Lit &lit) {
    return isTriviallyFalseImpl<0>(lit);
}

template <size_t I = 0>
inline Lit negateImpl(const Lit &lit) {
    if constexpr (I < num_theories) {
        if (lit.index() == I) {
            return !std::get<I>(lit);
        }
        return negateImpl<I+1>(lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

Lit negate(const Lit &lit) {
    return negateImpl<0>(lit);
}

size_t hash(const Lit lit) {
    return std::visit(
        Overload {
            [](const auto &lit) {
                return lit.hash();
            }
        }, lit);
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
