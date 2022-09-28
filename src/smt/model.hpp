#pragma once

#include "expression.hpp"
#include "subs.hpp"

class Model
{
public:

    Model();
    Model(VarMap<Num> &vars, BoolVarMap<bool> &constants);

    Num get(const Var &var) const;
    bool get(const BoolVar &var) const;
    bool contains(const Var &var) const;
    bool contains(const BoolVar &var) const;
    Subs toSubs() const;

    friend std::ostream& operator<<(std::ostream &s, const Model &e);

private:

    VarMap<Num> vars;
    BoolVarMap<bool> constants;

};
