#pragma once

#include "expression.hpp"
#include "boolsubs.hpp"

class Subs
{

    ExprSubs exprSubs;
    BoolSubs boolSubs;

public:

    Subs();
    Subs(const Var &key, const Expr &val);
    Subs(const BoolVar &key, const BoolExpr &val);
    Subs(const ExprSubs &exprSubs, const BoolSubs &boolSubs);

    void collectVars(BoolVarSet &vars) const;
    void collectVars(VarSet &vars) const;
    unsigned hash() const;
    void put(const Var &var, const Expr &val);
    void put(const BoolVar &var, const BoolExpr &val);
    Expr get(const Var &var) const;
    BoolExpr get(const BoolVar &var) const;
    ExprSubs& getExprSubs();
    BoolSubs& getBoolSubs();
    const ExprSubs& getExprSubs() const;
    const BoolSubs& getBoolSubs() const;
    ExprSubs::const_iterator find(const Var& v) const;
    BoolSubs::const_iterator find(const BoolVar& v) const;
    BoolExpr operator()(const BoolExpr &e) const;
    Expr operator()(const Expr &e) const;
    Rel operator()(const Rel &e) const;
    Subs compose(const Subs& that) const;
    Subs concat(const Subs& that) const;
    bool changes(const Var &var) const;
    bool changes(const BoolVar &var) const;
    bool empty() const;
    size_t size() const;
    int compare(const Subs &that) const;
    Subs project(const VarSet &evars, const BoolVarSet &bvars) const;
    void erase(const Var &var);
    void erase(const BoolVar &var);

};

std::ostream& operator<<(std::ostream &s, const Subs &e);
bool operator==(const Subs &s1, const Subs &s2);
bool operator<(const Subs &s1, const Subs &s2);
