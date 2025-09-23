#pragma once

#include "exprmap.hpp"
#include "theory.hpp"
#include "subs.hpp"

class LValueSubs: public ExprMap<Arith::Lval, Arith::Expr, Arrays<Arith>::Lval, Arith::Expr, Bools::Lval, Bools::Expr> {

public:

    static LValueSubs build(const Arith::Lval&, const Arith::Expr&);

    void collectVars(VarSet&) const;
    LValueSubs concat(const Subs&) const;
    LValueSubs concat(const Renaming&) const;
    LValueSubs compose(const LValueSubs&) const;
    Bools::Lval at(const Bools::Lval&) const;
    Arith::Lval at(const Arith::Lval&) const;
    Arrays<Arith>::Lval at(const Arrays<Arith>::Lval&) const;
    bool isPoly() const;
    VarSet coDomainVars() const;

};

size_t hash_value(const LValueSubs&);
bool operator==(const LValueSubs&, const LValueSubs&);
