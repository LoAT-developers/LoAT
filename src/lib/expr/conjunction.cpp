#include "conjunction.hpp"
#include "theories.hpp"
#include "literal.hpp"

bool Conjunction::isLinear() const {
    return std::all_of(this->begin(), this->end(), [](const auto &lit){
        return std::visit([](const auto &lit){
            return lit.isLinear();
        }, lit);
    });
}

void Conjunction::collectVars(VS &vars) const {
    for (const auto &lit: *this) {
        theories::collectVars<Arith, Bools>(lit, vars);
    }
}

Conjunction::VS Conjunction::vars() const {
    VS res;
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
