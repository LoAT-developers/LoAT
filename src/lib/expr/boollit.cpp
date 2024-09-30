#include "boollit.hpp"
#include "optional.hpp"

#include <stdexcept>
#include <ostream>
#include <boost/functional/hash.hpp>
#include <functional>

ConsHash<BoolLit, BoolLit, BoolLit::CacheHash, BoolLit::CacheEqual, BoolVarPtr, bool> BoolLit::cache {};

bool BoolLit::CacheEqual::operator()(const std::tuple<BoolVarPtr, bool> &args1, const std::tuple<BoolVarPtr, bool> &args2) const noexcept {
    return args1 == args2;
}

size_t BoolLit::CacheHash::operator()(const std::tuple<BoolVarPtr, bool> &args) const noexcept {
    size_t seed {42};
    boost::hash_combine(seed, std::get<0>(args));
    boost::hash_combine(seed, std::get<1>(args));
    return seed;
}

BoolLitPtr bools::mk(const BoolVarPtr var, bool negated) {
    return BoolLit::cache.from_cache(var, negated);
}

BoolLit::BoolLit(const BoolVarPtr var, bool negated): var(var), negated(negated) {}

BoolLit::~BoolLit() {
    cache.erase(var, negated);
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

BoolLitPtr operator!(const BoolLitPtr &l) {
    return bools::mk(l->getBoolVar(), !l->isNegated());
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

std::ostream& operator<<(std::ostream &s, const BoolLitPtr &l) {
    if (l->isNegated()) {
        s << "!";
    }
    return s << l->getBoolVar();
}

bool BoolLit::eval(const linked_hash_map<BoolVarPtr, bool> &model) const {
    return map<bool, bool>(model.get(var), [&](const auto &b) {
        return negated != b;
    }).value_or(false);
}

sexpresso::Sexp BoolLit::to_smtlib() const {
    sexpresso::Sexp res;
    if (negated) {
        res.addChild("not");
    }
    res.addChild(var->getName());
    return res;
}

BoolLitPtr BoolLit::renameVars(const bool_var_map &map) const {
    const auto it {map.left.find(var)};
    if (it == map.left.end()) {
        return cpp::assume_not_null(shared_from_this());
    } else {
        return bools::mk(it->second, negated);
    }
}