#pragma once

#include "expression.hpp"
#include "boundedness.hpp"

using RelSet = std::set<Rel>;
template <class T> using RelMap = std::map<Rel, T>;

class Rel {
public:

    class InvalidRelationalExpression: std::exception { };

    enum RelOp {lt, leq, gt, geq, eq, neq};

    Rel(const Expr &lhs, RelOp op, const Expr &rhs);

    Expr lhs() const;
    Expr rhs() const;
    Rel expand() const;
    bool isPoly() const;
    bool isLinear(const option<VarSet> &vars = option<VarSet>()) const;
    bool isIneq() const;
    bool isEq() const;
    bool isNeq() const;
    bool isGZeroConstraint() const;
    bool isStrict() const;
    bool isOctagon() const;
    Boundedness::Kind getBoundedness(const Var &x) const;

    unsigned hash() const;

    /**
     * @return Moves all addends containing variables to the lhs and all other addends to the rhs, where the given parameters are consiedered to be constants.
     */
    Rel splitVariableAndConstantAddends(const VarSet &params = VarSet()) const;
    bool isTriviallyTrue() const;
    bool isTriviallyFalse() const;
    void collectVariables(VarSet &res) const;
    bool has(const Expr &pattern) const;
    Rel subs(const Subs &map) const;
    void applySubs(const Subs &subs);
    std::string toString() const;
    RelOp relOp() const;
    VarSet vars() const;

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

    static Rel buildEq(const Expr &x, const Expr &y);
    static Rel buildNeq(const Expr &x, const Expr &y);

    friend Rel operator!(const Rel &x);
    friend bool operator==(const Rel &x, const Rel &y);
    friend bool operator!=(const Rel &x, const Rel &y);
    friend bool operator<(const Rel &x, const Rel &y);
    friend std::ostream& operator<<(std::ostream &s, const Rel &e);

    option<std::string> toQepcad() const;

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

Rel operator<(const Var &x, const Expr &y);
Rel operator<(const Expr &x, const Var &y);
Rel operator<(const Var &x, const Var &y);
Rel operator>(const Var &x, const Expr &y);
Rel operator>(const Expr &x, const Var &y);
Rel operator>(const Var &x, const Var &y);
Rel operator<=(const Var &x, const Expr &y);
Rel operator<=(const Expr &x, const Var &y);
Rel operator<=(const Var &x, const Var &y);
Rel operator>=(const Var &x, const Expr &y);
Rel operator>=(const Expr &x, const Var &y);
Rel operator>=(const Var &x, const Var &y);

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
