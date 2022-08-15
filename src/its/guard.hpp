#ifndef GUARD_HPP
#define GUARD_HPP

#include "rel.hpp"

class Guard : public std::vector<Rel> {
public:
    // inherit constructors of base class
    using std::vector<Rel>::vector;
    void collectVariables(VarSet &res) const;
    Guard subs(const Subs &sigma) const;

    /**
     * Returns true iff all guard terms are relational without the use of !=
     */
    bool isWellformed() const;
    bool isLinear() const;

    friend Guard operator&(const Guard &fst, const Guard &snd);
    friend Guard operator&(const Guard &fst, const Rel &snd);

};

std::ostream& operator<<(std::ostream &s, const Guard &l);

#endif // GUARD_HPP
