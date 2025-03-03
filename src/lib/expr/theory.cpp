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
    return theory::apply(var, [](const auto &var){return var->getName();});
}

bool isTempVar(const Var &var) {
    return theory::apply(var, [](const auto &var){return var->isTempVar();});
}

bool isProgVar(const Var &var) {
    return theory::apply(var, [](const auto &var){return var->isProgVar();});
}

bool isPostVar(const Var &var) {
    return theory::apply(var, [](const auto &var){return var->isPostVar();});
}

Var next(const Type t, const unsigned dimension) {
    switch (t) {
        case Type::Int: return Arith::next(dimension);
        case Type::Bool: return Bools::next(dimension);
    }
}

Var postVar(const Var &var) {
    return theory::apply(var, [](const auto x) {return Var(x->postVar());});
}

Var progVar(const Var &var) {
    return theory::apply(var, [](const auto x) {return Var(x->progVar());});
}

Expr toExpr(const Var &var) {
    return TheTheory::varToExpr(var);
}

Expr toExpr(const Const &c) {
    return TheTheory::constToExpr(c);
}

ArrayType to_type(const Expr &x) {
    return theory::apply(
        x,
        [](const Arith::Expr &) {
            return ArrayType(Type::Int, 0);
        },
        [](const Bools::Expr &) {
            return ArrayType(Type::Bool, 0);
        });
}

ArrayType to_type(const Var &x) {
    return theory::apply(x, [](const auto &x) {
        return x->get_type();
    });
}

std::optional<Var> is_var(const Expr &x) {
    using opt = std::optional<Var>;
    return theory::apply(x, [&](const auto &e) {
        if (const auto &x{e->isVar()}) {
            return opt{*x};
        } else {
            return opt{};
        }
    });
}

sexpresso::Sexp to_smtlib(const Lit &l) {
    return theory::apply(l, [&](const auto x) {return x->to_smtlib();});
}

sexpresso::Sexp to_smtlib(const Expr &e) {
    return theory::apply(e, [&](const auto x) {return x->to_smtlib();});
}

void collectVars(const Expr &expr, VarSet &vars) {
    theory::apply(
        expr,
        [&](const Arith::Expr expr) {
            expr->collectVars(vars.get<Arith::Var>());
        },
        [&](const Bools::Expr expr) {
            expr->collectVars(vars);
        });
}

VarSet vars(const Expr &e) {
    VarSet res;
    collectVars(e, res);
    return res;
}

Bools::Expr mkEq(const Expr &e1, const Expr &e2) {
    return theory::apply(
        e1,
        [&e2](const Arith::Expr &e1) {
            return bools::mkLit(arith::mkEq(e1, std::get<Arith::Expr>(e2)));
        },
        [&e2](const Bools::Expr lhs) {
            const auto rhs = std::get<Bools::Expr>(e2);
            return (lhs && rhs) || ((!lhs) && (!rhs));
        });
}

Bools::Expr mkNeq(const Expr &e1, const Expr &e2) {
    return theory::apply(
        e1,
        [&](const Arith::Expr &e1) {
            return bools::mkLit(arith::mkNeq(e1, std::get<Arith::Expr>(e2)));
        },
        [&](const Bools::Expr lhs) {
            const auto rhs = std::get<Bools::Expr>(e2);
            return (lhs && (!rhs)) || ((!lhs) && rhs);
        });
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
    return theory::apply(lit, [](const auto &lit) {
        return lit->hash();
    });
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

}

std::ostream& operator<<(std::ostream &s, const Var &e) {
    theory::apply(e, [&s](const auto &e){s << theory::getName(e);});
    return s;
}

std::ostream& operator<<(std::ostream &s, const Expr &e) {
    theory::apply(e, [&s](const auto &e){s << e;});
    return s;
}

std::ostream& operator<<(std::ostream &s, const Lit &e) {
    theory::apply(e, [&s](const auto &e){s << e;});
    return s;
}

std::ostream& theory::operator<<(std::ostream &s, const theory::Type &e) {
    switch (e) {
        case theory::Type::Int:
            s << "Int";
            break;
        case theory::Type::Bool:
            s << "Bool";
            break;
    }
    return s;
}
