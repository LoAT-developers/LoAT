#pragma once

#include "itheory.hpp"
#include "arithlit.hpp"
#include "thset.hpp"
#include "literal.hpp"

#include <variant>
#include <vector>

template <IBaseTheory... Th>
class Conjunction : public std::vector<std::variant<typename Th::Lit...>> {

    using T = BaseTheory<Th...>;
    using Lit = typename T::Lit;

public:
    // inherit constructors of base class
    using std::vector<typename T::Lit>::vector;

    bool isLinear() const {
        return std::all_of(this->begin(), this->end(), [](const auto &lit){
            return std::visit([](const auto &lit){
                return lit.isLinear();
            }, lit);
        });
    }

    void collectVars(theories::VarSet<Th...> &vars) const {
        for (const auto &lit: *this) {
            theories::collectVars<Th...>(lit, vars);
        }
    }

    theories::VarSet<Th...> vars() const {
        theories::VarSet<Th...> res;
        collectVars(res);
        return res;
    }

};

template <IBaseTheory... Th>
std::ostream& operator<<(std::ostream &s, const Conjunction<Th...> &l) {
    return s << mkAnd(l);
}

template <IBaseTheory... Th>
Conjunction<Th...> operator&&(const Conjunction<Th...> &fst, const Conjunction<Th...> &snd) {
    Conjunction<Th...> res(fst);
    res.insert(res.end(), snd.begin(), snd.end());
    return res;
}

template <IBaseTheory... Th>
Conjunction<Th...> operator&&(const Conjunction<Th...> &fst, const ArithLit &snd) {
    Conjunction res(fst);
    res.push_back(snd);
    return res;
}
