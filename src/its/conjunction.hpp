#pragma once

#include "itheory.hpp"
#include "rel.hpp"

#include <variant>
#include <vector>

template <ITheory... Th>
class Conjunction : public std::vector<std::variant<typename Th::Lit...>> {

    using T = Theory<Th...>;
    using Lit = typename T::Lit;

public:
    // inherit constructors of base class
    using std::vector<typename T::Lit>::vector;

    void collectVariables(theory::VarSet<Th...> &res) const {
        for (const Lit &lit : *this) {
            res.collectVars(lit);
        }
    }

    /**
     * Returns true iff all guard terms are relational without the use of !=
     */
    bool isWellformed() const {
        return std::all_of(this->begin(), this->end(), [](const auto &lit){
            return std::visit([](const auto &lit){
                return lit.isWellformed();
            }, lit);
        });
    }

    bool isLinear() const {
        return std::all_of(this->begin(), this->end(), [](const auto &lit){
            return std::visit([](const auto &lit){
                return lit.isLinear();
            }, lit);
        });
    }

};

template <ITheory... Th>
std::ostream& operator<<(std::ostream &s, const Conjunction<Th...> &l) {
    return s << buildAnd(l);
}

template <ITheory... Th>
Conjunction<Th...> operator&(const Conjunction<Th...> &fst, const Conjunction<Th...> &snd) {
    Conjunction<Th...> res(fst);
    res.insert(res.end(), snd.begin(), snd.end());
    return res;
}

template <ITheory... Th>
Conjunction<Th...> operator&(const Conjunction<Th...> &fst, const Rel &snd) {
    Conjunction res(fst);
    res.push_back(snd);
    return res;
}
