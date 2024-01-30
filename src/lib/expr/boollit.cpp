#include "boollit.hpp"

#include <stdexcept>
#include <ostream>
#include <boost/functional/hash.hpp>
#include <functional>

BoolLit::BoolLit(const BoolVar &var, bool negated): var(var), negated(negated) {}

bool BoolLit::isNegated() const {
    return negated;
}

bool BoolLit::isPoly() const {
    return true;
}

bool BoolLit::isLinear() const {
    return true;
}

BoolVar BoolLit::getBoolVar() const {
    return var;
}

BoolLit BoolLit::normalize() const {
    return *this;
}

bool BoolLit::isTriviallyTrue() const {
    return false;
}

bool BoolLit::isTriviallyFalse() const {
    return false;
}

bool BoolLit::isWellformed() const {
    return true;
}

void BoolLit::collectVars(std::unordered_set<BoolVar> &res) const {
    res.insert(var);
}

BoolLit operator!(const BoolLit &l) {
    return BoolLit(l.getBoolVar(), !l.isNegated());
}

std::size_t BoolLit::hash() const {
    std::size_t seed {0};
    boost::hash_combine(seed, negated);
    boost::hash_combine(seed, var.hash());
    return seed;
}

std::ostream& operator<<(std::ostream &s, const BoolLit &l) {
    if (l.isNegated()) {
        s << "!";
    }
    return s << l.getBoolVar();
}
