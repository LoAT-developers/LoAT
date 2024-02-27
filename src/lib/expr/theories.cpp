#include "theories.hpp"

namespace theories {

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

ThExpr subs(const ThExpr &expr, const Subs &subs) {
    return std::visit(Overload{
                          [&subs](const ExprPtr expr) {
                              return ThExpr(subs.get<Arith>()(expr));
                          },
                          [&subs](const BoolExpr expr) {
                              return ThExpr(expr->subs(subs));
                          }
                      }, expr);
}

void collectVars(const ThExpr &expr, VarSet &vars) {
    std::visit(Overload{
                   [&vars](const ExprPtr expr) {
                       expr->collectVars(vars.get<NumVarPtr>());
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

Var first(const Pair &p) {
    return theory::first<Arith, Bools>(p);
}

ThExpr second(const Pair &p) {
    return theory::second<Arith, Bools>(p);
}

VarSet vars(const Subs &e) {
    VarSet res;
    collectVars(e, res);
    return res;
}

void collectVars(const Subs &subs, VarSet &vars) {
    for (const auto &[x,y]: subs) {
        vars.insert(x);
        theories::collectVars(y, vars);
    }
}

Subs compose(const Subs &fst, const Subs &snd) {
    Subs res;
    composeImpl(fst, snd, res);
    return res;
}

Subs concat(const Subs &fst, const Subs &snd) {
    Subs res;
    concatImpl(fst, snd, res);
    return res;
}

VarSet coDomainVars(const Subs &subs) {
    VarSet res;
    collectCoDomainVars(subs, res);
    return res;
}

void collectVariables(VarSet &res, const Lit &e) {
    literal::collectVars<Arith, Bools>(e, res);
}

VarSet variables(const Lit &e) {
    return literal::vars<Arith, Bools>(e);
}

bool isTriviallyTrue(const Lit &lit) {
    return literal::isTriviallyTrue<Arith, Bools>(lit);
}

Lit negate(const Lit &lit) {
    return literal::negate<Arith, Bools>(lit);
}

BoolExpr subs(const Lit &lit, const Subs &s) {
    return literal::subs<Arith, Bools>(lit, s);
}

BoolExpr mkEq(const ThExpr &e1, const ThExpr &e2) {
    return std::visit(
        Overload {
            [&e2](const ExprPtr &e1) {
                return BExpression::mkAndFromLits(
                    std::vector<Lit>{ArithLit::mkGeq(e1, std::get<ExprPtr>(e2)),
                                     ArithLit::mkLeq(e1, std::get<ExprPtr>(e2))});
            },
            [&e2](const BoolExpr lhs) {
                const auto rhs = std::get<BoolExpr>(e2);
                return (lhs & rhs) | ((!lhs) & (!rhs));
            }
        }, e1);
}

BoolExpr mkNeq(const ThExpr &e1, const ThExpr &e2) {
    return std::visit(
        Overload {
            [&e2](const ExprPtr &e1) {
                return BExpression::mkOrFromLits(
                    std::vector<Lit>{ArithLit::mkGt(e1, std::get<ExprPtr>(e2)),
                                     ArithLit::mkLt(e1, std::get<ExprPtr>(e2))});
            },
            [&e2](const BoolExpr lhs) {
                const auto rhs = std::get<BoolExpr>(e2);
                return (lhs & (!rhs)) | ((!lhs) & rhs);
            }
        }, e1);
}

Arith theory(const NumVarPtr&) {
    return arith::t;
}

Bools theory(const BoolVarPtr&) {
    return bools::t;
}

}

std::ostream& operator<<(std::ostream &s, const Var &e) {
    std::visit([&s](const auto &e){s << theories::getName(e);}, e);
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
