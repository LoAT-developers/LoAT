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
using VS = VarSet;
using Subs = theory::Subs<IntTheory, BoolTheory>;
using S = Subs;

extern TheTheory theTheory;

extern const BoolExpr True;
extern const BoolExpr False;

const BoolExpr buildAnd(const std::vector<Lit> &xs);

const BoolExpr buildAnd(const std::vector<BoolExpr> &xs);

namespace theory {

std::string getName(const Var &var);

Var first(const Subs<IntTheory, BoolTheory>::Pair &p);

ThExpr second(const Subs<IntTheory, BoolTheory>::Pair &p);

template <ITheory Th>
BoolExpr transform(const BExpr<Th> &e) {
    static const std::function<BoolExpr(const typename Theory<Th>::Lit&)> mapper = [](const auto &lit) {
        return std::visit([](const auto &rel) -> BoolExpr {return buildTheoryLit<IntTheory, BoolTheory>(rel);}, lit);
    };
    return e->map(mapper);
}

const BoolExpr buildTheoryLit(const Lit &lit);

const VS vars(const ThExpr &e);

BoolExpr subs(const Lit &lit, const S &s);

}

bool operator==(const ThExpr &e, const ThVar &var);

bool operator==(const ThExpr &e1, const ThExpr &e2);

std::ostream& operator<<(std::ostream &s, const Lit &e);

std::ostream& operator<<(std::ostream &s, const Var &e);

std::ostream& operator<<(std::ostream &s, const ThExpr &e);
