#include "boollit.hpp"
#include "optional.hpp"

#include <stdexcept>
#include <ostream>
#include <boost/functional/hash.hpp>
#include <functional>

BoolLit::BoolLit(const BoolVarPtr var, bool negated): var(var), negated(negated) {}

bool BoolLit::isNegated() const {
    return negated;
}

bool BoolLit::isPoly() const {
    return true;
}

bool BoolLit::isLinear() const {
    return true;
}

BoolVarPtr BoolLit::getBoolVar() const {
    return var;
}

bool BoolLit::isTriviallyTrue() const {
    return false;
}

bool BoolLit::isTriviallyFalse() const {
    return false;
}

void BoolLit::collectVars(linked_hash_set<BoolVarPtr> &res) const {
    res.insert(var);
}

BoolLit operator!(const BoolLit &l) {
    return BoolLit(l.getBoolVar(), !l.isNegated());
}

std::size_t BoolLit::hash() const {
    std::size_t seed {0};
    boost::hash_combine(seed, negated);
    boost::hash_combine(seed, var);
    return seed;
}

size_t hash_value(const BoolLit &lit) {
    return lit.hash();
}

std::ostream& operator<<(std::ostream &s, const BoolLit &l) {
    if (l.isNegated()) {
        s << "!";
    }
    return s << l.getBoolVar();
}

bool BoolLit::eval(const linked_hash_map<BoolVarPtr, bool> &model) const {
    return map<bool, bool>(model.get(var), [&](const auto &b) {
        return negated != b;
    }).value_or(false);
}
