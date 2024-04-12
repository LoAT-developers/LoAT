#pragma once

#include <optional>

#include "arithexpr.hpp"
#include "arithsubs.hpp"

class Bounds {

private:

    ArithExprSet rUpperBounds {};
    ArithExprSet rLowerBounds {};
    ArithExprSet rEqualities {};
    ArithExprSet iUpperBounds {};
    ArithExprSet iLowerBounds {};
    ArithExprSet iEqualities {};

public:

    void addUpperBound(const ArithExprPtr e);
    void addLowerBound(const ArithExprPtr e);
    void addEquality(const ArithExprPtr e);

    const ArithExprSet& realUpperBounds() const;
    const ArithExprSet& realLowerBounds() const;
    const ArithExprSet& realEqualities() const;

    const ArithExprSet& integralUpperBounds() const;
    const ArithExprSet& integralLowerBounds() const;
    const ArithExprSet& integralEqualities() const;

    Bounds intersect(const Bounds &that) const;
    bool empty() const;

};

class ArithLit;

namespace arith {

ArithLit mkEq(const ArithExprPtr x, const ArithExprPtr y);
ArithLit mkNeq(const ArithExprPtr x, const ArithExprPtr y);
ArithLit mkGeq(const ArithExprPtr x, const ArithExprPtr y);
ArithLit mkLeq(const ArithExprPtr x, const ArithExprPtr y);
ArithLit mkGt(const ArithExprPtr x, const ArithExprPtr y);
ArithLit mkLt(const ArithExprPtr x, const ArithExprPtr y);

}

class ArithLit {

private:

    friend auto operator<=>(const ArithLit &x, const ArithLit &y) = default;
    friend bool operator==(const ArithLit &x, const ArithLit &y) = default;

    friend ArithLit arith::mkEq(const ArithExprPtr x, const ArithExprPtr y);
    friend ArithLit arith::mkNeq(const ArithExprPtr x, const ArithExprPtr y);
    friend ArithLit arith::mkGeq(const ArithExprPtr x, const ArithExprPtr y);
    friend ArithLit arith::mkLeq(const ArithExprPtr x, const ArithExprPtr y);
    friend ArithLit arith::mkGt(const ArithExprPtr x, const ArithExprPtr y);
    friend ArithLit arith::mkLt(const ArithExprPtr x, const ArithExprPtr y);

    friend ArithLit operator!(const ArithLit &x);
    friend std::ostream& operator<<(std::ostream &s, const ArithLit &e);

    enum class Kind {Gt, Eq, Neq};

public:

    class InvalidRelationalExpression: std::exception { };

    ArithLit(const ArithExprPtr lhs, const Kind kind);

    ArithExprPtr lhs() const;
    bool isPoly() const;
    bool isLinear(const std::optional<linked_hash_set<ArithVarPtr>> &vars = std::nullopt) const;
    void getBounds(const ArithVarPtr n, Bounds &res) const;

    bool isTriviallyTrue() const;
    bool isTriviallyFalse() const;
    void collectVars(linked_hash_set<ArithVarPtr> &res) const;
    bool has(const ArithVarPtr) const;
    bool isGt() const;
    bool isEq() const;
    bool isNeq() const;
    ArithLit subs(const ArithSubs &map) const;
    linked_hash_set<ArithVarPtr> vars() const;

    template <typename P>
    bool hasVarWith(P predicate) const {
        return l->hasVarWith(predicate);
    }

    std::size_t hash() const;
    bool eval(const linked_hash_map<ArithVarPtr, Int>&) const;

    std::pair<std::optional<ArithExprPtr>, std::optional<ArithExprPtr>> getBoundFromIneq(const ArithVarPtr) const;

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

using ArithLitSet = linked_hash_set<ArithLit>;

std::ostream& operator<<(std::ostream &s, const ArithLitSet &set);
