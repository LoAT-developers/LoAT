#pragma once

#include <optional>
#include <unordered_set>

#include "numexpression.hpp"

using RelSet = std::unordered_set<Rel>;
template <class T> using RelMap = std::unordered_map<Rel, T>;

struct Bounds {
    std::unordered_set<Expr> upperBounds;
    std::unordered_set<Expr> lowerBounds;
    std::optional<Expr> equality;
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
    bool isLinear(const std::optional<std::unordered_set<NumVar>> &vars = std::optional<std::unordered_set<NumVar>>()) const;
    bool isIneq() const;
    bool isEq() const;
    bool isNeq() const;
    bool isGZeroConstraint() const;
    bool isStrict() const;
    bool isOctagon() const;
    bool isWellformed() const;
    void getBounds(const NumVar &n, Bounds &res) const;

    /**
     * @return Moves all addends containing variables to the lhs and all other addends to the rhs, where the given parameters are consiedered to be constants.
     */
    Rel splitVariableAndConstantAddends(const std::set<NumVar> &params = {}) const;
    bool isTriviallyTrue() const;
    bool isTriviallyFalse() const;
    void collectVars(std::unordered_set<NumVar> &res) const;
    bool has(const Expr &pattern) const;
    Rel subs(const ExprSubs &map) const;
    std::string toString() const;
    RelOp relOp() const;
    std::unordered_set<NumVar> vars() const;

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

    std::pair<std::optional<Expr>, std::optional<Expr>> getBoundFromIneq(const NumVar &N) const;

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
