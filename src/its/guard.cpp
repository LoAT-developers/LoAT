#include "guard.hpp"
#include "boolexpr.hpp"

void Guard::collectVariables(VarSet &res) const {
    for (const Rel &rel : *this) {
        rel.collectVariables(res);
    }
}

Guard Guard::subs(const ExprSubs &sigma) const {
    Guard res;
    for (const Rel &rel: *this) {
        res.push_back(rel.subs(sigma));
    }
    return res;
}

bool Guard::isWellformed() const {
    return std::all_of(begin(), end(), [](const Rel &rel) {
        return !rel.isNeq();
    });
}

bool Guard::isLinear() const {
    return std::all_of(begin(), end(), [](const Rel &rel) {
        return rel.isLinear();
    });
}

bool operator<(const Guard &m1, const Guard &m2);

std::ostream& operator<<(std::ostream &s, const Guard &l) {
    return s << buildAnd(l);
}

Guard operator&(const Guard &fst, const Guard &snd) {
    Guard res(fst);
    res.insert(res.end(), snd.begin(), snd.end());
    return res;
}

Guard operator&(const Guard &fst, const Rel &snd) {
    Guard res(fst);
    res.push_back(snd);
    return res;
}
