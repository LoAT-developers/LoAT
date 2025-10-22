#pragma once

#include <memory>
#include <string>

#include "notnull.hpp"
#include "conshash.hpp"
#include "sexpresso.hpp"
#include "exprfwd.hpp"

class BoolVar;

using BoolVarPtr = cpp::not_null<std::shared_ptr<const BoolVar>>;

namespace bools {
    BoolVarPtr mkVar(int idx);
}

class BoolVar: std::enable_shared_from_this<BoolVar> {

friend BoolVarPtr bools::mkVar(int idx);

    static int last_prog_idx;
    static int last_tmp_idx;

    int idx;

    struct CacheEqual {
        bool operator()(const std::tuple<int> &args1, const std::tuple<int> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<int> &args) const noexcept;
    };
    static ConsHash<BoolVar, BoolVar, CacheHash, CacheEqual, int> cache;

public:

    explicit BoolVar(int idx);
    ~BoolVar();

    std::string getName() const;

    int getIdx() const;

    static BoolVarPtr next();

    static BoolVarPtr nextProgVar();

    BoolVarPtr postVar() const;

    BoolVarPtr progVar() const;

    bool isTempVar() const;

    bool isProgVar() const;

    bool isPostVar() const;

    std::size_t hash() const;

    sexpresso::Sexp to_smtlib() const;

    static unsigned dim();

    BoolExprPtr subs(const Subs&) const;

};

std::ostream& operator<<(std::ostream &s, const BoolVarPtr& e);

template<>
struct std::hash<BoolVar> {
    std::size_t operator()(const BoolVar& x) const noexcept {
        return x.hash();
    }
};

size_t hash_value(const BoolVar &x);
