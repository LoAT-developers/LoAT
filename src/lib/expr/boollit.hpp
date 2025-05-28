#pragma once

#include "var.hpp"
#include "linkedhashset.hpp"
#include "linkedhashmap.hpp"
#include "notnull.hpp"

#include <boost/bimap.hpp>
#include <boost/bimap/unordered_set_of.hpp>

class Empty{};

using BoolVar = TVar<theory::Type::Bool, Empty>;
using BoolVarPtr = BoolVar::ptr;
using bool_var_map = boost::bimap<boost::bimaps::unordered_set_of<BoolVarPtr>, boost::bimaps::unordered_set_of<BoolVarPtr>>;

class BoolLit;

using BoolLitPtr = cpp::not_null<std::shared_ptr<const BoolLit>>;

namespace bools {
    BoolLitPtr mk(const BoolVarPtr var, bool negated = false);
}

class BoolLit: public std::enable_shared_from_this<BoolLit> {

    friend BoolLitPtr bools::mk(const BoolVarPtr var, bool negated);

    BoolVarPtr var;
    bool negated;

    struct CacheEqual {
        bool operator()(const std::tuple<BoolVarPtr, bool> &args1, const std::tuple<BoolVarPtr, bool> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<BoolVarPtr, bool> &args) const noexcept;
    };
    static ConsHash<BoolLit, BoolLit, CacheHash, CacheEqual, BoolVarPtr, bool> cache;

public:

    BoolLit(const BoolVarPtr var, bool negated);
    ~BoolLit();
    bool isNegated() const;
    bool isPoly() const;
    bool isLinear() const;
    BoolVarPtr getBoolVar() const;
    void collectVars(linked_hash_set<BoolVarPtr> &res) const;
    bool isTriviallyTrue() const;
    bool isTriviallyFalse() const;
    std::size_t hash() const;
    bool eval(const linked_hash_map<BoolVarPtr, bool> &model) const;
    sexpresso::Sexp to_smtlib() const;
    BoolLitPtr renameVars(const bool_var_map &map) const;

};

namespace bools {

BoolVarPtr mkVar(const int idx);

}

BoolLitPtr operator!(const BoolLitPtr &l);

std::ostream& operator<<(std::ostream &s, const BoolLitPtr &e);

template<>
struct std::hash<BoolLit> {
    std::size_t operator()(const BoolLit& x) const noexcept {
        return x.hash();
    }
};

size_t hash_value(const BoolLit &lit);
