#pragma once

#include <optional>

#include "arithexpr.hpp"

using RelSet = linked_hash_set<ArithLit>;

struct Bounds {
    linked_hash_set<ArithExprPtr> upperBounds {};
    linked_hash_set<ArithExprPtr> lowerBounds {};

    linked_hash_set<ArithExprPtr> equalities() const {
        linked_hash_set<ArithExprPtr> res;
        for (const auto &b: lowerBounds) {
            if (upperBounds.contains(b)) {
                res.insert(b);
            }
        }
        return res;
    }

};

std::ostream& operator<<(std::ostream &s, const RelSet &set);

class ArithLit {

private:

    friend auto operator<=>(const ArithLit &x, const ArithLit &y) = default;
    friend bool operator==(const ArithLit &x, const ArithLit &y) = default;

public:

    class InvalidRelationalExpression: std::exception { };

    ArithLit(const ArithExprPtr lhs);

    ArithExprPtr lhs() const;
    bool isPoly() const;
    bool isLinear(const std::optional<linked_hash_set<ArithVarPtr>> &vars = std::optional<linked_hash_set<ArithVarPtr>>()) const;
    void getBounds(const ArithVarPtr n, Bounds &res) const;

    bool isTriviallyTrue() const;
    bool isTriviallyFalse() const;
    void collectVars(linked_hash_set<ArithVarPtr> &res) const;
    bool has(const ArithVarPtr) const;
    ArithLit subs(const ArithSubs &map) const;
    linked_hash_set<ArithVarPtr> vars() const;

    template <typename P>
    bool hasVarWith(P predicate) const {
        return l->hasVarWith(predicate);
    }

    std::size_t hash() const;

    friend ArithLit operator!(const ArithLit &x);
    friend std::ostream& operator<<(std::ostream &s, const ArithLit &e);

    std::pair<std::optional<ArithExprPtr>, std::optional<ArithExprPtr>> getBoundFromIneq(const ArithVarPtr) const;

private:

    /**
     * Given any relation, checks if the relation is trivially true or false,
     * by checking if rhs-lhs is a numeric value. If unsure, returns none.
     * @return true/false if the relation is trivially valid/invalid
     */
    std::optional<bool> checkTrivial() const;

    ArithExprPtr l;

};

template<>
struct std::hash<ArithLit> {
    std::size_t operator()(const ArithLit& x) const noexcept {
        return x.hash();
    }
};

size_t hash_value(const ArithLit &rel);

namespace arith {

ArithLit mkGeq(const ArithExprPtr x, const ArithExprPtr y);
ArithLit mkLeq(const ArithExprPtr x, const ArithExprPtr y);
ArithLit mkGt(const ArithExprPtr x, const ArithExprPtr y);
ArithLit mkLt(const ArithExprPtr x, const ArithExprPtr y);

}
