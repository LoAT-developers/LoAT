#include "expr.hpp"

namespace expr {

std::string getName(const Var &var) {
    return std::visit([](const auto &var){return var.getName();}, var);
}

bool isTempVar(const Var &var) {
    return std::visit([](const auto &var){return var.isTempVar();}, var);
}

bool isProgVar(const Var &var) {
    return !isTempVar(var);
}

Var next(const Var &var) {
    return std::visit(Overload{
                          [](const NumVar&) {
                              return Var(NumVar::next());
                          },
                          [](const BoolVar&) {
                              return Var(BoolVar::next());
                          }
                      }, var);
}

ThExpr toExpr(const Var &var) {
    return TheTheory::varToExpr(var);
}

ThExpr subs(const ThExpr &expr, const Subs &subs) {
    return std::visit(Overload{
                          [&subs](const Expr &expr) {
                              return ThExpr(expr.subs(subs.get<IntTheory>()));
                          },
                          [&subs](const BoolExpr expr) {
                              return ThExpr(expr->subs(subs));
                          }
                      }, expr);
}

void collectVars(const ThExpr &expr, VarSet &vars) {
    std::visit(Overload{
                   [&vars](const Expr &expr) {
                       expr.collectVars(vars.get<NumVar>());
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
    return theory::first<IntTheory, BoolTheory>(p);
}

ThExpr second(const Pair &p) {
    return theory::second<IntTheory, BoolTheory>(p);
}

VarSet vars(const Subs &e) {
    VarSet res;
    collectVars(e, res);
    return res;
}

void collectVars(const Subs &subs, VarSet &vars) {
    for (const auto &p: subs) {
        vars.insert(first(p));
        expr::collectVars(second(p), vars);
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
    literal::collectVars<IntTheory, BoolTheory>(e, res);
}

VarSet variables(const Lit &e) {
    return literal::vars<IntTheory, BoolTheory>(e);
}

bool isTriviallyTrue(const Lit &lit) {
    return literal::isTriviallyTrue<IntTheory, BoolTheory>(lit);
}

Lit negate(const Lit &lit) {
    return literal::negate<IntTheory, BoolTheory>(lit);
}

BoolExpr subs(const Lit &lit, const Subs &s) {
    return literal::subs<IntTheory, BoolTheory>(lit, s);
}

BoolExpr mkEq(const ThExpr &e1, const ThExpr &e2) {
    return std::visit(
                Overload{
                    [&e2](const Expr &e1){
                        return BExpression::buildTheoryLit(Rel::buildEq(e1, std::get<Expr>(e2)));
                    },
                    [&e2](const BoolExpr &lhs){
                        const auto rhs = std::get<BoolExpr>(e2);
                        return (lhs & rhs) | ((!lhs) & (!rhs));
                    }
                }, e1);
}

BoolExpr mkNeq(const ThExpr &e1, const ThExpr &e2) {
    return std::visit(
        Overload{
            [&e2](const Expr &e1){
                return BExpression::buildTheoryLit(Rel::buildNeq(e1, std::get<Expr>(e2)));
            },
            [&e2](const BoolExpr &lhs){
                const auto rhs = std::get<BoolExpr>(e2);
                return (lhs & (!rhs)) | ((!lhs) & rhs);
            }
        }, e1);
}

}

std::ostream& operator<<(std::ostream &s, const Var &e) {
    std::visit([&s](const auto &e){s << expr::getName(e);}, e);
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
