#pragma once

#include <optional>

#include "arithexpr.hpp"

using RelSet = linked_hash_set<ArithLit>;

struct Bounds {
    linked_hash_set<ExprPtr> upperBounds {};
    linked_hash_set<ExprPtr> lowerBounds {};

    linked_hash_set<ExprPtr> equalities() const {
        linked_hash_set<ExprPtr> res;
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

    ArithLit(const ExprPtr lhs);

    ExprPtr lhs() const;
    bool isPoly() const;
    bool isLinear(const std::optional<linked_hash_set<NumVarPtr>> &vars = std::optional<linked_hash_set<NumVarPtr>>()) const;
    void getBounds(const NumVarPtr n, Bounds &res) const;

    bool isTriviallyTrue() const;
    bool isTriviallyFalse() const;
    void collectVars(linked_hash_set<NumVarPtr> &res) const;
    bool has(const NumVarPtr) const;
    ArithLit subs(const ArithSubs &map) const;
    linked_hash_set<NumVarPtr> vars() const;

    template <typename P>
    bool hasVarWith(P predicate) const {
        return l->hasVarWith(predicate);
    }

    std::size_t hash() const;

    static ArithLit mkGeq(const ExprPtr x, const ExprPtr y);
    static ArithLit mkLeq(const ExprPtr x, const ExprPtr y);
    static ArithLit mkGt(const ExprPtr x, const ExprPtr y);
    static ArithLit mkLt(const ExprPtr x, const ExprPtr y);

    friend ArithLit operator!(const ArithLit &x);
    friend std::ostream& operator<<(std::ostream &s, const ArithLit &e);

    std::pair<std::optional<ExprPtr>, std::optional<ExprPtr>> getBoundFromIneq(const NumVarPtr) const;

private:

    /**
     * Given any relation, checks if the relation is trivially true or false,
     * by checking if rhs-lhs is a numeric value. If unsure, returns none.
     * @return true/false if the relation is trivially valid/invalid
     */
    std::optional<bool> checkTrivial() const;

    ExprPtr l;

};

template<>
struct std::hash<ArithLit> {
    std::size_t operator()(const ArithLit& x) const noexcept {
        return x.hash();
    }
};

size_t hash_value(const ArithLit &rel);
