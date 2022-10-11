#pragma once

#include "theory.hpp"

class Guard : public std::vector<Lit> {
public:
    // inherit constructors of base class
    using std::vector<Lit>::vector;
    void collectVariables(VarSet &res) const;
    Guard subs(const ThSubs &sigma) const;

    /**
     * Returns true iff all guard terms are relational without the use of !=
     */
    bool isWellformed() const;
    bool isLinear() const;

    friend Guard operator&(const Guard &fst, const Guard &snd);
    friend Guard operator&(const Guard &fst, const Lit &snd);

};

std::ostream& operator<<(std::ostream &s, const Guard &l);
