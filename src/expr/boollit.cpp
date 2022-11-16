#include "boollit.hpp"

#include <stdexcept>
#include <boost/functional/hash.hpp>

BoolLit::BoolLit(const BoolVar &var, bool negated): var(var), negated(negated) {}

std::string BoolLit::toRedlog() const {
    throw std::logic_error("unsupported operation");
}

unsigned BoolLit::hash() const {
    std::size_t seed = 0;
    boost::hash_combine(seed, var.hash());
    boost::hash_combine(seed, negated);
    return seed;
}

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

int BoolLit::compare(const BoolLit &that) const {
    if (negated && !that.negated) {
        return 1;
    }
    if (!negated && that.negated) {
        return -1;
    }
    return var.compare(that.var);
}

BoolLit BoolLit::normalize() const {
    return *this;
}

bool BoolLit::isTriviallyTrue() const {
    return false;
}

bool BoolLit::isWellformed() const {
    return true;
}

void BoolLit::collectVars(std::set<BoolVar> &res) const {
    res.insert(var);
}

bool BoolLit::implies(const BoolLit &that) const {
    return *this == that;
}

bool operator<(const BoolLit &l1, const BoolLit &l2) {
    return l1.compare(l2) < 0;
}

bool operator==(const BoolLit &l1, const BoolLit &l2) {
    return l1.compare(l2) == 0;
}

BoolLit operator!(const BoolLit &l) {
    return BoolLit(l.getBoolVar(), !l.isNegated());
}

std::ostream& operator<<(std::ostream &s, const BoolLit &l) {
    if (l.isNegated()) {
        s << "!";
    }
    return s << l.getBoolVar();
}
