#include "theory.hpp"

#include <boost/algorithm/string.hpp>

Bools::Expr top() {
    return BoolExpr::top();
}

Bools::Expr bot() {
    return BoolExpr::bot();
}

namespace bools {

Bools::Expr mkLit(const Lit &lit) {
    return BoolExpr::mkLit(lit);
}

}

namespace theory {
    std::string getName(const Var &var) {
        return std::visit([](const auto &var){return var->getName();}, var);
    }

    bool isTempVar(const Var &var) {
        return std::visit([](const auto &var){return var->isTempVar();}, var);
    }

    bool isTempCell(const Cell &var) {
        return std::visit([](const auto &var){return var->isTempVar();}, var);
    }

    bool isProgVar(const Var &var) {
        return std::visit([](const auto &var){return var->isProgVar();}, var);
    }

    bool isProgCell(const Cell &var) {
        return std::visit([](const auto &var){return var->isProgVar();}, var);
    }

    Expr toExpr(const Var& var) {
        return theory::apply(
            var,
            [](const Bools::Var& var) {
                return Expr(bools::mkLit(bools::mk(var)));
            },
            [](const auto& var) {
                return Expr(var);
            });
    }

    bool isPostVar(const Var &var) {
        return std::visit([](const auto &var){return var->isPostVar();}, var);
    }

    bool isPostCell(const Cell &var) {
        return std::visit([](const auto &var){return var->isPostVar();}, var);
    }

    Var next(const Var &var) {
        return std::visit([](const auto& x) {return Var(theory(x).next(x->dim()));}, var);
    }

    Var postVar(const Var &var) {
        return std::visit([]<typename X>(const X& x) {return Var(x->postVar());}, var);
    }

    Var progVar(const Var &var) {
        return std::visit([]<typename X>(const X& x) {return Var(x->progVar());}, var);
    }

    Type to_type(const Expr &x) {
        return std::visit(
            Overload{
                [](const Arith::Expr &) {
                    return Type::Int;
                },
                [](const Bools::Expr &) {
                    return Type::Bool;
                },
                [](const Arrays<Arith>::Expr &) {
                    return Type::Int;
                }},
            x);
    }

    Type to_type(const Var &x) {
        return std::visit(
            Overload{
                [&](const Bools::Var &) {
                    return Type::Bool;
                },
                [&](const Arrays<Arith>::Var &) {
                    return Type::IntArray;
                }},
            x);
    }

    Type to_type(const std::string &x) {
        if (boost::iequals(x, "int")) {
            return Type::Int;
        }
        if (boost::iequals(x, "bool")) {
            return Type::Bool;
        }
        throw std::invalid_argument("unknown type");
    }

    std::string abbrev(const Type t) {
        switch (t) {
        case Type::Bool: return "b";
        case Type::Int: return "i";
        default: throw std::invalid_argument("unknown type");
        }
    }

    sexpresso::Sexp to_smtlib(const Lit &l) {
        return std::visit([&](const auto& x) {return x->to_smtlib();}, l);
    }

    sexpresso::Sexp to_smtlib(const Expr &e) {
        return std::visit([&](const auto& x) {return x->to_smtlib();}, e);
    }

    void collectVars(const Expr& expr, VarSet& vars) {
        theory::apply(
            expr,
            [&](const Bools::Expr& expr) {
                expr->collectVars(vars);
            },
            [&](const auto& expr) {
                expr->collectVars(vars.get<Arrays<Arith>::Var>());
            });
    }

    VarSet vars(const Expr &e) {
        VarSet res;
        collectVars(e, res);
        return res;
    }

    Bools::Expr mkEq(const Expr &e1, const Expr &e2) {
        return std::visit(
            Overload {
                [&](const Arith::Expr& e1) {
                    return bools::mkLit(arith::mkEq(e1, std::get<Arith::Expr>(e2)));
                },
                [&](const Bools::Expr& lhs) {
                    const auto rhs = std::get<Bools::Expr>(e2);
                    return Bools::mkEq(lhs, rhs);
                },
                [&](const Arrays<Arith>::Expr& e1) {
                    return bools::mkLit(arrays::mkEq<Arith>(e1, std::get<Arrays<Arith>::Expr>(e2)));
                }
            }, e1);
    }

    Bools::Expr mkNeq(const Expr &e1, const Expr &e2) {
        return std::visit(
            Overload {
                [&](const Arith::Expr& e1) {
                    return bools::mkLit(arith::mkNeq(e1, std::get<Arith::Expr>(e2)));
                },
                [&](const Bools::Expr& lhs) {
                    const auto rhs = std::get<Bools::Expr>(e2);
                    return !Bools::mkEq(lhs, rhs);
                },
                [&](const Arrays<Arith>::Expr& e1) {
                    return bools::mkLit(arrays::mkNeq<Arith>(e1, std::get<Arrays<Arith>::Expr>(e2)));
                }
            }, e1);
    }

    Bools theory(const Bools::Var&) {
        return bools::t;
    }

    Arrays<Arith> theory(const Arrays<Arith>::Var&) {
        return arrays::arith;
    }

    Arith theory(const Arith::Expr&) {
        return arith::t;
    }

    Bools theory(const Bools::Expr&) {
        return bools::t;
    }

    Arrays<Arith> theory(const Arrays<Arith>::Expr&) {
        return arrays::arith;
    }

    template <size_t I = 0>
    bool isLinearImpl(const Lit &lit) {
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
    bool isPolyImpl(const Lit &lit) {
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

    void collectVars(const Lit& lit, VarSet& s) {
        theory::apply(
            lit,
            [&](const Bools::Lit& lit) {
                return lit->collectVars(s.get<Bools::Var>());
            },
            [&](const auto& lit) {
                return lit->collectVars(s.get<Arrays<Arith>::Var>());
            });
    }

    VarSet vars(const Lit &lit) {
        VarSet res;
        collectVars(lit, res);
        return res;
    }

    void collectCells(const Lit& lit, CellSet& s) {
        theory::apply(
            lit,
            [&](const Bools::Lit& lit) {
                return lit->collectVars(s.get<Bools::Var>());
            },
            [&](const auto& lit) {
                return lit->collectCells(s.get<ArithVarPtr>());
            });
    }

    CellSet cells(const Lit& lit) {
        CellSet res;
        collectCells(lit, res);
        return res;
    }

    template <size_t I = 0>
    bool isTriviallyTrueImpl(const Lit &lit) {
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
    bool isTriviallyFalseImpl(const Lit &lit) {
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
    Lit negateImpl(const Lit &lit) {
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
    void simplifyAndImpl(LitSet &lits) {
        if constexpr (I < num_theories) {
            using Th = std::tuple_element_t<I, Theories>;
            if constexpr (!std::is_same_v<Th, Bools>) {
                if (auto &ls {lits.get<typename Th::Lit>()}; !ls.empty()) {
                    (*ls.begin())->simplifyAnd(ls);
                }
            }
            simplifyAndImpl<I+1>(lits);
        }
    }

    void simplifyAnd(LitSet &lits) {
        return simplifyAndImpl(lits);
    }

    std::ostream& operator<<(std::ostream& s, const Type& e) {
        switch (e) {
        case Type::Bool: {
            return s << "Bool";
        }
        case Type::Int: {
            return s << "Int";
        }
        case Type::IntArray: {
            return s << "Int[]";
        }
        default: {
            throw std::invalid_argument("unknown type");
        }
        }
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
