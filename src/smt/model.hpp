#ifndef MODEL_HPP
#define MODEL_HPP

#include "boolexpr.hpp"

class Model
{
public:

    Model(VarMap<GiNaC::numeric> vars, std::map<unsigned int, bool> constants);

    GiNaC::numeric get(const Var &var) const;
    bool get(unsigned int id) const;
    bool contains(const Var &var) const;
    bool contains(unsigned int id) const;
    Subs toSubs() const;

    friend std::ostream& operator<<(std::ostream &s, const Model &e);

private:

    VarMap<GiNaC::numeric> vars;
    std::map<unsigned int, bool> constants;

};

#endif // MODEL_HPP
