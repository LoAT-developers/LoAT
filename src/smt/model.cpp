#include "model.hpp"

Model::Model(VarMap<Num> &vars, BoolVarMap<bool> &constants): vars(vars), constants(constants) {}

Model::Model() {}

Num Model::get(const Var &var) const {
    return vars.at(var);
}

bool Model::get(const BoolVar &var) const {
    return constants.at(var);
}

bool Model::contains(const Var &var) const {
    return vars.count(var) > 0;
}

bool Model::contains(const BoolVar &var) const {
    return constants.find(var) != constants.end();
}

Subs Model::toSubs() const {
    Subs res;
    for (const auto &e: vars) {
        res.put(e.first, e.second);
    }
    for (const auto &e: constants) {
        res.put(e.first, e.second ? True : False);
    }
    return res;
}

std::ostream& operator<<(std::ostream &s, const Model &e) {
    if (!e.vars.empty() && !e.constants.empty()) {
        s << "variables:" << std::endl;
    }
    for (const auto &p: e.vars) {
        s << " " << p.first << "=" << p.second;
    }
    s << std::endl;
    if (!e.vars.empty() && !e.constants.empty()) {
        s << "constants:" << std::endl;
    }
    for (const auto &p: e.constants) {
        s << " " << p.first << "=" << p.second;
    }
    s << std::endl;
    return s;
}
