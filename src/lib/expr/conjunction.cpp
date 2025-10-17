#include "conjunction.hpp"
#include "string.hpp"

bool Conjunction::isLinear() const {
    return std::all_of(this->begin(), this->end(), [](const auto &lit){
        return std::visit([](const auto &lit){
            return lit->isLinear();
        }, lit);
    });
}

void Conjunction::collectVars(VarSet &vars) const {
    for (const auto &lit: *this) {
        theory::collectVars(lit, vars);
    }
}

VarSet Conjunction::vars() const {
    VarSet res;
    collectVars(res);
    return res;
}

std::ostream& operator<<(std::ostream &s, const Conjunction &l) {
    return s << bools::mkAnd(l);
}

Conjunction operator&&(const Conjunction &fst, const Conjunction &snd) {
    Conjunction res(fst);
    for (const auto &x: snd) {
        res.insert(x);
    }
    return res;
}

Conjunction Conjunction::fromBoolExpr(const Bools::Expr &e) {
    if (!e->isConjunction()) {
        throw std::invalid_argument(toString(e) + " is not a conjunction");
    }
    Conjunction res;
    e->collectLits(res);
    return res;
}

size_t hash_value(const Conjunction &c) {
    return boost::hash_unordered_range(c.begin(), c.end());
}
