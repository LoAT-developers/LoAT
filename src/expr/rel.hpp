#pragma once

#include "numexpression.hpp"

using RelSet = std::set<Rel>;
template <class T> using RelMap = std::map<Rel, T>;

struct Bounds {
    std::set<Expr> upperBounds;
    std::set<Expr> lowerBounds;
    option<Expr> equality;
};

std::ostream& operator<<(std::ostream &s, const RelSet &set);

class Rel {
public:

    class InvalidRelationalExpression: std::exception { };

    enum RelOp {lt, leq, gt, geq, eq, neq};

    Rel(const Expr &lhs, RelOp op, const Expr &rhs);

    Expr lhs() const;
    Expr rhs() const;
    Rel expand() const;
    bool isPoly() const;
    bool isLinear(const option<std::set<NumVar>> &vars = option<std::set<NumVar>>()) const;
    bool isIneq() const;
    bool isEq() const;
    bool isNeq() const;
    bool isGZeroConstraint() const;
    bool isStrict() const;
    bool isOctagon() const;
    bool isWellformed() const;
    void getBounds(const NumVar &n, Bounds &res) const;

    unsigned hash() const;

    /**
     * @return Moves all addends containing variables to the lhs and all other addends to the rhs, where the given parameters are consiedered to be constants.
     */
    Rel splitVariableAndConstantAddends(const std::set<NumVar> &params = {}) const;
    bool isTriviallyTrue() const;
    bool isTriviallyFalse() const;
    void collectVars(std::set<NumVar> &res) const;
    bool has(const Expr &pattern) const;
    Rel subs(const ExprSubs &map) const;
    void applySubs(const ExprSubs &subs);
    std::string toString() const;
    std::string toRedlog() const;
    RelOp relOp() const;
    std::set<NumVar> vars() const;
    int compare(const Rel& that) const;

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

    static Rel buildEq(const Expr &x, const Expr &y);
    static Rel buildNeq(const Expr &x, const Expr &y);
    static Rel buildGeq(const Expr &x, const Expr &y);
    static Rel buildLeq(const Expr &x, const Expr &y);
    static Rel buildGt(const Expr &x, const Expr &y);
    static Rel buildLt(const Expr &x, const Expr &y);

    friend Rel operator!(const Rel &x);
    friend bool operator==(const Rel &x, const Rel &y);
    friend bool operator!=(const Rel &x, const Rel &y);
    friend bool operator<(const Rel &x, const Rel &y);
    friend std::ostream& operator<<(std::ostream &s, const Rel &e);

    option<std::string> toQepcad() const;

    std::pair<option<Expr>, option<Expr>> getBoundFromIneq(const NumVar &N) const;

private:

    /**
     * Given any relation, checks if the relation is trivially true or false,
     * by checking if rhs-lhs is a numeric value. If unsure, returns none.
     * @return true/false if the relation is trivially valid/invalid
     */
    option<bool> checkTrivial() const;
    Rel toIntPoly() const;

    Expr l;
    Expr r;
    RelOp op;

};

template<class T>
std::ostream& operator<<(std::ostream &s, const RelMap<T> &map) {
    s << "{";
    for (auto it = map.begin(); it != map.end(); ++it) {
        if (it != map.begin()) {
            s << ", ";
        }
        s << it->first << " -> " << it->second;
    }
    s << "}";
    return s;
}
