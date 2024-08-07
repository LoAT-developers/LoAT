#pragma once

#include <optional>

#include "arithexpr.hpp"
#include "arithsubs.hpp"

enum class BoundKind {
    Lower, Upper, Equality
};

struct Bound {
    friend bool operator==(const Bound&, const Bound&) = default;
    const ArithExprPtr bound;
    const BoundKind kind;
};

std::size_t hash_value(const Bound&);

// represents a costraint of the form: (factor * x) % modulo = res
struct Divisibility {
    friend bool operator==(const Divisibility&, const Divisibility&) = default;
    const Int factor;
    const Int modulo;
    const ArithExprPtr res;
};

std::size_t hash_value(const Divisibility&);

class ArithLit;

using ArithLitPtr = cpp::not_null<std::shared_ptr<const ArithLit>>;

namespace arith {

ArithLitPtr mkEq(const ArithExprPtr x, const ArithExprPtr y);
ArithLitPtr mkNeq(const ArithExprPtr x, const ArithExprPtr y);
ArithLitPtr mkGeq(const ArithExprPtr x, const ArithExprPtr y);
ArithLitPtr mkLeq(const ArithExprPtr x, const ArithExprPtr y);
ArithLitPtr mkGt(const ArithExprPtr x, const ArithExprPtr y);
ArithLitPtr mkLt(const ArithExprPtr x, const ArithExprPtr y);

}

class ArithLit {

private:

    friend ArithLitPtr operator!(const ArithLitPtr &x);
    friend std::ostream& operator<<(std::ostream &s, const ArithLitPtr &e);
    friend ArithLitPtr arith::mkEq(const ArithExprPtr x, const ArithExprPtr y);
    friend ArithLitPtr arith::mkNeq(const ArithExprPtr x, const ArithExprPtr y);
    friend ArithLitPtr arith::mkGeq(const ArithExprPtr x, const ArithExprPtr y);
    friend ArithLitPtr arith::mkLeq(const ArithExprPtr x, const ArithExprPtr y);
    friend ArithLitPtr arith::mkGt(const ArithExprPtr x, const ArithExprPtr y);
    friend ArithLitPtr arith::mkLt(const ArithExprPtr x, const ArithExprPtr y);

    enum class Kind {Gt, Eq, Neq};

    class InvalidRelationalExpression: std::exception { };

    struct CacheEqual {
        bool operator()(const std::tuple<ArithExprPtr, Kind> &args1, const std::tuple<ArithExprPtr, Kind> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<ArithExprPtr, Kind> &args) const noexcept;
    };
    static ConsHash<ArithLit, ArithLit, CacheHash, CacheEqual, ArithExprPtr, Kind> cache;

    static ArithLitPtr mk(const ArithExprPtr lhs, const Kind kind);

public:

    ArithLit(const ArithExprPtr lhs, const Kind kind);

    ArithExprPtr lhs() const;
    bool isPoly() const;
    bool isLinear(const std::optional<linked_hash_set<ArithVarPtr>> &vars = std::nullopt) const;
    void getBounds(const ArithVarPtr n, linked_hash_set<Bound> &res) const;
    void getDivisibility(const ArithVarPtr n, linked_hash_set<Divisibility> &res) const;
    std::optional<std::pair<ArithExprPtr, Int>> isDivisibility() const;
    std::optional<Divisibility> isDivisibility(const ArithVarPtr n) const;
    std::optional<ArithExprPtr> getEquality(const ArithVarPtr n) const;
    void propagateEquality(ArithSubs &subs, const std::function<bool(const ArithVarPtr &)> &allow) const;

    bool isTriviallyTrue() const;
    bool isTriviallyFalse() const;
    void collectVars(linked_hash_set<ArithVarPtr> &res) const;
    bool has(const ArithVarPtr) const;
    bool isGt() const;
    bool isEq() const;
    bool isNeq() const;
    ArithLitPtr subs(const ArithSubs &map) const;
    linked_hash_set<ArithVarPtr> vars() const;

    template <typename P>
    bool hasVarWith(P predicate) const {
        return l->hasVarWith(predicate);
    }

    std::size_t hash() const;
    bool eval(const linked_hash_map<ArithVarPtr, Int>&) const;
    sexpresso::Sexp to_smtlib() const;

    static void simplifyAnd(linked_hash_set<ArithLitPtr> &lits);
    static void simplifyOr(linked_hash_set<ArithLitPtr> &lits);

private:

    /**
     * Given any relation, checks if the relation is trivially true or false,
     * by checking if rhs-lhs is a numeric value. If unsure, returns none.
     * @return true/false if the relation is trivially valid/invalid
     */
    std::optional<bool> checkTrivial() const;

    ArithExprPtr l;
    Kind kind;

};

template<>
struct std::hash<ArithLit> {
    std::size_t operator()(const ArithLit& x) const noexcept {
        return x.hash();
    }
};

size_t hash_value(const ArithLit &rel);

using ArithLitSet = linked_hash_set<ArithLitPtr>;

std::ostream& operator<<(std::ostream &s, const ArithLitSet &set);
