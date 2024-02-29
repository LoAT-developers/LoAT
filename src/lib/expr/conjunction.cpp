#include "conjunction.hpp"
#include "string.hpp"

bool Conjunction::isLinear() const {
    return std::all_of(this->begin(), this->end(), [](const auto &lit){
        return std::visit([](const auto &lit){
            return lit.isLinear();
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
    return s << bools::mkAndFromLits(l);
}

Conjunction operator&&(const Conjunction &fst, const Conjunction &snd) {
    Conjunction res(fst);
    res.insert(res.end(), snd.begin(), snd.end());
    return res;
}

Conjunction Conjunction::fromBoolExpr(const BExpr &e) {
    if (!e->isConjunction()) {
        throw std::invalid_argument(toString(e) + " is not a conjunction");
    }
    const auto lits {e->lits()};
    return Conjunction{lits.begin(), lits.end()};
}
