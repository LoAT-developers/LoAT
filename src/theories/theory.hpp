#pragma once

#include "itheory.hpp"
#include "inttheory.hpp"
#include "booltheory.hpp"


#include <boost/functional/hash.hpp>
#include <variant>

using TheTheory = Theory<IntTheory, BoolTheory>;
using TheSubs = TheorySubs<IntTheory, BoolTheory>;
using BoolExpr = BExpr<IntTheory, BoolTheory>;
using QFormula = QuantifiedFormula<IntTheory, BoolTheory>;
using BoolExprSet = BoolExpressionSet<IntTheory, BoolTheory>;
using Guard = Conjunction<IntTheory, BoolTheory>;
using Lit = TheTheory::Lit;
using Var = TheTheory::Var;
using ThExpr = TheSubs::Expression;
using ThVar = TheSubs::Var;
using Theories = TheTheory::Theories;
using ThSubs = TheSubs::Subs;
using VarSet = theory::VarSet<IntTheory, BoolTheory>;
using Subs = theory::Subs<IntTheory, BoolTheory>;

const BoolExpr True = BoolExpression<IntTheory, BoolTheory>::True;
const BoolExpr False = BoolExpression<IntTheory, BoolTheory>::False;

const BoolExpr buildAnd(const std::vector<Lit> &xs) {
    BoolExprSet lits;
    for (const auto &lit: xs) {
        lits.insert(buildTheoryLit<IntTheory, BoolTheory>(lit));
    }
    return buildAnd(lits);
}

const BoolExpr buildAnd(const std::vector<BoolExpr> &xs) {
    BoolExprSet lits;
    for (const auto &lit: xs) {
        lits.insert(lit);
    }
    return buildAnd(lits);
}

namespace theory {

std::string getName(const Var &var) {
    return getName<IntTheory, BoolTheory>(var);
}

Var first(const Subs<IntTheory, BoolTheory>::Pair &p) {
    return first<IntTheory, BoolTheory>(p);
}

ThExpr second(const Subs<IntTheory, BoolTheory>::Pair &p) {
    return second<IntTheory, BoolTheory>(p);
}

template <ITheory Th>
BoolExpr transform(const BExpr<Th> &e) {
    static const std::function<BoolExpr(const typename Theory<Th>::Lit&)> mapper = [](const auto &lit) {
        return std::visit([](const auto &rel) -> BoolExpr {return buildTheoryLit<IntTheory, BoolTheory>(rel);}, lit);
    };
    return e->map(mapper);
}

const BoolExpr buildTheoryLit(const Lit &lit) {
    return BoolExpr(new BoolTheoryLit<IntTheory, BoolTheory>(lit));
}

}

bool operator==(const ThExpr &e, const ThVar &var) {
    return std::visit(Overload{
                          [](const Expr &e, const NumVar &var) {return e.equals(var);},
                          [](const BoolExpr &e1, const BoolVar &e2) {return e1 == e2;},
                          [](const auto &e, const auto &var) {return false;},
                      }, e, var);
}

bool operator==(const ThExpr &e1, const ThExpr &e2) {
    return std::visit(Overload{
                          [](const Expr &e1, const Expr &e2) {return e1.equals(e2);},
                          [](const BoolExpr &e1, const BoolExpr &e2) {return e1 == e2;},
                          [](const auto &e1, const auto &e2) {return false;}
                      }, e1, e2);
}

std::ostream& operator<<(std::ostream &s, const Lit &e) {
    std::visit([&s](const auto &e){s << e;}, e);
    return s;
}

std::ostream& operator<<(std::ostream &s, const Var &e) {
    std::visit([&s](const auto &e){s << theory::getName(e);}, e);
    return s;
}

std::ostream& operator<<(std::ostream &s, const ThExpr &e) {
    std::visit([&s](const auto &e){s << e;}, e);
    return s;
}
