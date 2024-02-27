#pragma once

#include <optional>

#include "numexpression.hpp"

using RelSet = linked_hash_set<Rel>;

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

class Rel {

private:

    friend auto operator<=>(const Rel &x, const Rel &y) = default;
    friend bool operator==(const Rel &x, const Rel &y) = default;

public:

    class InvalidRelationalExpression: std::exception { };

    Rel(const ExprPtr lhs);

    ExprPtr lhs() const;
    bool isPoly() const;
    bool isLinear(const std::optional<linked_hash_set<NumVarPtr>> &vars = std::optional<linked_hash_set<NumVarPtr>>()) const;
    void getBounds(const NumVarPtr n, Bounds &res) const;

    bool isTriviallyTrue() const;
    bool isTriviallyFalse() const;
    void collectVars(linked_hash_set<NumVarPtr> &res) const;
    bool has(const NumVarPtr) const;
    Rel subs(const ExprSubs &map) const;
    linked_hash_set<NumVarPtr> vars() const;

    template <typename P>
    bool hasVarWith(P predicate) const {
        return l->hasVarWith(predicate);
    }

    std::size_t hash() const;

    static Rel buildGeq(const ExprPtr x, const ExprPtr y);
    static Rel buildLeq(const ExprPtr x, const ExprPtr y);
    static Rel buildGt(const ExprPtr x, const ExprPtr y);
    static Rel buildLt(const ExprPtr x, const ExprPtr y);

    friend Rel operator!(const Rel &x);
    friend std::ostream& operator<<(std::ostream &s, const Rel &e);

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
struct std::hash<Rel> {
    std::size_t operator()(const Rel& x) const noexcept {
        return x.hash();
    }
};

size_t hash_value(const Rel &rel);
