#pragma once

#include <optional>

#include "numexpression.hpp"

using RelSet = linked_hash_set<Rel>;

struct Bounds {
    linked_hash_set<Expr> upperBounds {};
    linked_hash_set<Expr> lowerBounds {};
    linked_hash_set<Expr> equalities {};
};

std::ostream& operator<<(std::ostream &s, const RelSet &set);

class Rel {

private:

    friend auto operator<=>(const Rel &x, const Rel &y) = default;
    friend bool operator==(const Rel &x, const Rel &y) = default;

public:

    class InvalidRelationalExpression: std::exception { };

    enum RelOp {lt, leq, gt, geq, eq, neq};

    Rel(const Expr &lhs, RelOp op, const Expr &rhs);

    Expr lhs() const;
    Expr rhs() const;
    Rel expand() const;
    bool isPoly() const;
    bool isLinear(const std::optional<linked_hash_set<NumVar>> &vars = std::optional<linked_hash_set<NumVar>>()) const;
    bool isIneq() const;
    bool isEq() const;
    bool isNeq() const;
    bool isGZeroConstraint() const;
    bool isStrict() const;
    bool isOctagon() const;
    bool isWellformed() const;
    void getBounds(const NumVar &n, Bounds &res, const SolvingLevel level = ResultMapsToInt) const;

    bool isTriviallyTrue() const;
    bool isTriviallyFalse() const;
    void collectVars(linked_hash_set<NumVar> &res) const;
    bool has(const Expr &pattern) const;
    Rel subs(const ExprSubs &map) const;
    std::string toString() const;
    RelOp relOp() const;
    linked_hash_set<NumVar> vars() const;

    template <typename P>
    bool hasVarWith(P predicate) const {
        return l.hasVarWith(predicate) || r.hasVarWith(predicate);
    }

    /**
     * Given an inequality, transforms it into one of the form lhs > 0
     * @note assumes integer arithmetic to translate e.g. >= to >
     */
    Rel makeRhsZero() const;
    Rel toLeq() const;
    Rel toGt() const;

    Rel toL() const;
    Rel toG() const;
    Rel normalize() const;

    std::size_t hash() const;

    static Rel buildEq(const Expr &x, const Expr &y);
    static Rel buildNeq(const Expr &x, const Expr &y);
    static Rel buildGeq(const Expr &x, const Expr &y);
    static Rel buildLeq(const Expr &x, const Expr &y);
    static Rel buildGt(const Expr &x, const Expr &y);
    static Rel buildLt(const Expr &x, const Expr &y);

    friend Rel operator!(const Rel &x);
    friend std::ostream& operator<<(std::ostream &s, const Rel &e);

    std::pair<std::optional<Expr>, std::optional<Expr>> getBoundFromIneq(const NumVar &N, const SolvingLevel level = ResultMapsToInt) const;

private:

    /**
     * Given any relation, checks if the relation is trivially true or false,
     * by checking if rhs-lhs is a numeric value. If unsure, returns none.
     * @return true/false if the relation is trivially valid/invalid
     */
    std::optional<bool> checkTrivial() const;
    Rel toIntPoly() const;

    Expr l;
    Expr r;
    RelOp op;

};

template<>
struct std::hash<Rel> {
    std::size_t operator()(const Rel& x) const noexcept {
        return x.hash();
    }
};

size_t hash_value(const Rel &rel);
