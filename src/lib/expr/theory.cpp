#include "theory.hpp"

const Bools::Expr top() {
    return BoolExpr::top();
}

const Bools::Expr bot() {
    return BoolExpr::bot();
}

namespace bools {

Bools::Expr mkLit(const Lit &lit) {
    return BoolExpr::mkLit(lit);
}

Bools::Expr mkAndFromLits(const std::initializer_list<Lit> &lits) {
    return BoolExpr::mkAndFromLits(lits);
}

}

namespace theory {

std::string getName(const Var &var) {
    return std::visit([](const auto &var){return var->getName();}, var);
}

bool isTempVar(const Var &var) {
    return std::visit([](const auto &var){return var->isTempVar();}, var);
}

bool isProgVar(const Var &var) {
    return std::visit([](const auto &var){return var->isProgVar();}, var);
}

bool isPostVar(const Var &var) {
    return std::visit([](const auto &var){return var->isPostVar();}, var);
}

Var next(const Var &var) {
    return std::visit([](const auto x) {return Var(decltype(x)::element_type::next());}, var);
}

Var postVar(const Var &var) {
    return std::visit([](const auto x) {return Var(decltype(x)::element_type::postVar(x));}, var);
}

Var progVar(const Var &var) {
    return std::visit([](const auto x) {return Var(decltype(x)::element_type::progVar(x));}, var);
}

Expr toExpr(const Var &var) {
    return TheTheory::varToExpr(var);
}

void collectVars(const Expr &expr, VarSet &vars) {
    std::visit(Overload{
                   [&vars](const Arith::Expr expr) {
                       expr->collectVars(vars.get<Arith::Var>());
                   },
                   [&vars](const Bools::Expr expr) {
                       expr->collectVars(vars);
                   }
               }, expr);
}

VarSet vars(const Expr &e) {
    VarSet res;
    collectVars(e, res);
    return res;
}

Bools::Expr mkEq(const Expr &e1, const Expr &e2) {
    return std::visit(
        Overload {
            [&e2](const Arith::Expr &e1) {
                return bools::mkLit(arith::mkEq(e1, std::get<Arith::Expr>(e2)));
            },
            [&e2](const Bools::Expr lhs) {
                const auto rhs = std::get<Bools::Expr>(e2);
                return (lhs && rhs) || ((!lhs) && (!rhs));
            }
        }, e1);
}

Bools::Expr mkNeq(const Expr &e1, const Expr &e2) {
    return std::visit(
        Overload {
            [&e2](const Arith::Expr &e1) {
                return bools::mkLit(arith::mkNeq(e1, std::get<Arith::Expr>(e2)));
            },
            [&e2](const Bools::Expr lhs) {
                const auto rhs = std::get<Bools::Expr>(e2);
                return (lhs && (!rhs)) || ((!lhs) && rhs);
            }
        }, e1);
}

Arith theory(const Arith::Var) {
    return arith::t;
}

Bools theory(const Bools::Var) {
    return bools::t;
}

Arith theory(const Arith::Expr) {
    return arith::t;
}

Bools theory(const Bools::Expr) {
    return bools::t;
}

template <size_t I = 0>
inline bool isLinearImpl(const Lit &lit) {
    if constexpr (I < num_theories) {
        if (lit.index() == I) {
            return std::get<I>(lit)->isLinear();
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
            return std::get<I>(lit)->isPoly();
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
            return std::get<I>(lit)->collectVars(s.template get<I>());
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
            return std::get<I>(lit)->isTriviallyTrue();
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
            return std::get<I>(lit)->isTriviallyFalse();
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

size_t hash(const Lit &lit) {
    return std::visit(
        Overload {
            [](const auto &lit) {
                return lit->hash();
            }
        }, lit);
}

template <size_t I = 0>
inline void simplifyAndImpl(LitSet &lits) {
    if constexpr (I < num_theories) {
        using Th = std::tuple_element_t<I, Theories>;
        if constexpr (!std::is_same_v<Th, Bools>) {
            auto &ls {lits.get<typename Th::Lit>()};
            if (!ls.empty()) {
                (*ls.begin())->simplifyAnd(ls);
            }
        }
        simplifyAndImpl<I+1>(lits);
    }
}

void simplifyAnd(LitSet &lits) {
    return simplifyAndImpl(lits);
}

template <size_t I = 0>
inline void simplifyOrImpl(LitSet &lits) {
    if constexpr (I < num_theories) {
        using Th = std::tuple_element_t<I, Theories>;
        if constexpr (!std::is_same_v<Th, Bools>) {
            auto &ls {lits.get<typename Th::Lit>()};
            if (!ls.empty()) {
                (*ls.begin())->simplifyOr(ls);
            }
        }
        simplifyOrImpl<I+1>(lits);
    }
}

void simplifyOr(LitSet &lits) {
    simplifyOrImpl(lits);
}

}

std::ostream& operator<<(std::ostream &s, const Var &e) {
    std::visit([&s](const auto &e){s << theory::getName(e);}, e);
    return s;
}

std::ostream& operator<<(std::ostream &s, const Expr &e) {
    std::visit([&s](const auto &e){s << e;}, e);
    return s;
}

std::ostream& operator<<(std::ostream &s, const Lit &e) {
    std::visit([&s](const auto &e){s << e;}, e);
    return s;
}
