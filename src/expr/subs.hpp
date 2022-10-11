#pragma once

#include "boolsubs.hpp"

class Subs
{

    ThSubs thSubs;
    BoolSubs boolSubs;

public:

    Subs();

    template<INonBoolTheory Th>
    Subs(const typename Th::Var &key, const typename Th::Expr &val): thSubs(key, val) {}

    Subs(const BoolVar &key, const BoolExpr &val);
    Subs(const ThSubs &thSubs, const BoolSubs &boolSubs);

    void collectVars(VarSet &vars) const;
    unsigned hash() const;
    void put(const BoolVar &var, const BoolExpr &val);

    template<INonBoolTheory Th>
    void put(const typename Th::Var &var, const typename Th::Expression &val) {
        thSubs.put(var, val);
    }

    ThExpr get(const Var &var) const;
    BoolExpr get(const BoolVar &var) const;
    ThSubs& getThSubs();
    BoolSubs& getBoolSubs();
    const ThSubs& getThSubs() const;
    const BoolSubs& getBoolSubs() const;
    ThSubs::Iterator find(const ThVar& v) const;
    BoolSubs::const_iterator find(const BoolVar& v) const;
    bool isEnd(const std::variant<ThSubs::Iterator, BoolSubs::const_iterator> &it) const;
    BoolExpr operator()(const BoolExpr &e) const;

    template <class S>
    S operator()(const S &e) const {
        return thSubs.subs(e);
    }

    Subs compose(const Subs& that) const;
    Subs concat(const Subs& that) const;
    bool changes(const Var &var) const;
    bool changes(const BoolVar &var) const;
    bool empty() const;
    size_t size() const;
    int compare(const Subs &that) const;
    Subs project(const VarSet &evars) const;
    void erase(const Var &var);
    void erase(const BoolVar &var);
    bool isLinear() const;
    bool isPoly() const;

};

std::ostream& operator<<(std::ostream &s, const Subs &e);
bool operator==(const Subs &s1, const Subs &s2);
bool operator<(const Subs &s1, const Subs &s2);
