#pragma once

#include "option.hpp"
#include "theory.hpp"
#include "guard.hpp"

#include <memory>
#include <set>

class BoolTheoryLit;
class BoolJunction;
class BoolExpression;
class Quantifier;
class QuantifiedFormula;
typedef std::shared_ptr<const BoolExpression> BoolExpr;

struct boolexpr_compare {
    bool operator() (const BoolExpr a, const BoolExpr b) const;
};

typedef std::set<BoolExpr, boolexpr_compare> BoolExprSet;

class BoolExpression: public std::enable_shared_from_this<BoolExpression> {

    friend class BoolTheoryLit;
    friend class BoolJunction;
    friend class BoolConst;

public:

    virtual option<Lit> getTheoryLit() const = 0;
    virtual bool isAnd() const = 0;
    virtual bool isOr() const = 0;
    virtual BoolExprSet getChildren() const = 0;
    virtual const BoolExpr negation() const = 0;
    virtual bool forall(const std::function<bool(const Lit&)> &pred) const = 0;
    virtual BoolExpr map(const std::function<option<BoolExpr>(const Lit&)> &f) const = 0;
    BoolExpr simplify() const;
    virtual ~BoolExpression();
    std::set<Lit> lits() const;
    bool isLinear() const;
    bool isPoly() const;
    virtual std::set<Lit> universallyValidLits() const = 0;
    void findConsequences(const BoolVar &var, BoolExprSet &res) const;
    VarSet vars() const;
    std::vector<Guard> dnf() const;
    virtual bool isConjunction() const = 0;
    Guard conjunctionToGuard() const;
    virtual BoolExpr toG() const = 0;
    virtual void collectLits(std::set<Lit> &res) const = 0;
    virtual void collectVars(VarSet &res) const = 0;
    virtual void collectVars(std::set<BoolVar> &res) const = 0;
    virtual BoolExpr subs(const ThSubs &subs) const = 0;
    virtual std::string toRedlog() const = 0;
    virtual size_t size() const = 0;
    virtual BoolExpr replaceLits(const std::map<Lit, BoolExpr> map) const = 0;
    virtual unsigned hash() const = 0;
    QuantifiedFormula quantify(const std::vector<Quantifier> &prefix) const;
    virtual void getBounds(const Var &n, Bounds &res) const = 0;
    virtual int compare(const BoolExpr that) const = 0;

protected:
    virtual void dnf(std::vector<Guard> &res) const = 0;
};

class BoolTheoryLit: public BoolExpression {

private:

    Lit lit;

public:

    BoolTheoryLit(const Lit &lit);
    bool isAnd() const override;
    bool isOr() const override;
    option<Lit> getTheoryLit() const override;
    BoolExprSet getChildren() const override;
    const BoolExpr negation() const override;
    bool forall(const std::function<bool(const Lit&)> &pred) const override;
    BoolExpr map(const std::function<option<BoolExpr>(const Lit&)> &f) const override;
    ~BoolTheoryLit() override;
    bool isConjunction() const override;
    BoolExpr toG() const override;
    std::set<Lit> universallyValidLits() const override;
    void collectLits(std::set<Lit> &res) const override;
    void collectVars(VarSet &res) const override;
    void collectVars(std::set<BoolVar> &res) const override;
    BoolExpr subs(const ThSubs &subs) const override;
    size_t size() const override;
    std::string toRedlog() const override;
    BoolExpr replaceLits(const std::map<Lit, BoolExpr> map) const override;
    unsigned hash() const override;
    void getBounds(const Var &n, Bounds &res) const override;
    int compare(const BoolExpr that) const override;

protected:
    void dnf(std::vector<Guard> &res) const override;

};

enum ConcatOperator { ConcatAnd, ConcatOr };

class BoolJunction: public BoolExpression {

private:

    BoolExprSet children;
    ConcatOperator op;

public:

    BoolJunction(const BoolExprSet &children, ConcatOperator op);
    bool isAnd() const override;
    bool isOr() const override;
    option<Lit> getTheoryLit() const override;
    BoolExprSet getChildren() const override;
    const BoolExpr negation() const override;
    bool forall(const std::function<bool(const Lit&)> &pred) const override;
    BoolExpr map(const std::function<option<BoolExpr>(const Lit&)> &f) const override;
    ~BoolJunction() override;
    bool isConjunction() const override;
    BoolExpr toG() const override;
    std::set<Lit> universallyValidLits() const override;
    void collectLits(std::set<Lit> &res) const override;
    void collectVars(VarSet &res) const override;
    void collectVars(std::set<BoolVar> &res) const override;
    BoolExpr subs(const ThSubs &subs) const override;
    size_t size() const override;
    std::string toRedlog() const override;
    BoolExpr replaceLits(const std::map<Lit, BoolExpr> map) const override;
    unsigned hash() const override;
    void getBounds(const Var &n, Bounds &res) const override;
    int compare(const BoolExpr that) const override;

protected:
    void dnf(std::vector<Guard> &res) const override;

};

class Quantifier {

public:
    enum class Type { Forall, Exists };

private:
    Type qType;
    std::set<NumVar> vars;
    std::map<NumVar, Expr> lowerBounds;
    std::map<NumVar, Expr> upperBounds;

public:
    Quantifier(const Type &qType, const std::set<NumVar> &vars, const std::map<NumVar, Expr> &lowerBounds, const std::map<NumVar, Expr> &upperBounds);

    Quantifier negation() const;
    const std::set<NumVar>& getVars() const;
    Type getType() const;
    std::string toRedlog() const;
    option<Expr> lowerBound(const NumVar &x) const;
    option<Expr> upperBound(const NumVar &x) const;
    Quantifier remove(const NumVar &x) const;

};

class QuantifiedFormula {

private:
    std::vector<Quantifier> prefix;
    BoolExpr matrix;

public:

    QuantifiedFormula(std::vector<Quantifier> prefix, const BoolExpr &matrix);
    const QuantifiedFormula negation() const;
    bool forall(const std::function<bool(const Lit&)> &pred) const;
    QuantifiedFormula map(const std::function<BoolExpr(const Lit&)> &f) const;
    std::set<NumVar> boundVars() const;
    QuantifiedFormula toG() const;
    void collectLits(std::set<Lit> &res) const;
    QuantifiedFormula subs(const ThSubs &subs) const;
    VarSet freeVars() const;
    std::string toRedlog() const;
    bool isTiviallyTrue() const;
    bool isTiviallyFalse() const;
    friend std::ostream& operator<<(std::ostream &s, const QuantifiedFormula &f);
    std::vector<Quantifier> getPrefix() const;
    BoolExpr getMatrix() const;
    bool isConjunction() const;
//    std::pair<QuantifiedFormula, ExprSubs> normalizeVariables(VariableManager &varMan) const;

};

const BoolExpr buildAnd(const std::vector<Lit> &xs);
const BoolExpr buildAnd(const std::vector<BoolExpr> &xs);
const BoolExpr buildOr(const std::vector<Lit> &xs);
const BoolExpr buildOr(const std::vector<BoolExpr> &xs);
const BoolExpr buildAnd(const std::set<Lit> &xs);
const BoolExpr buildAnd(const BoolExprSet &xs);
const BoolExpr buildOr(const std::set<Lit> &xs);
const BoolExpr buildOr(const BoolExprSet &xs);
const BoolExpr buildTheoryLit(const Lit &lit);
const BoolExpr buildLit(const BoolVar &var, bool negated = false);
const BoolExpr buildConjunctiveClause(const BoolExprSet &xs);

extern const BoolExpr True;
extern const BoolExpr False;

const BoolExpr operator &(const BoolExpr a, const BoolExpr b);
const BoolExpr operator &(const BoolExpr a, const Lit &b);
const BoolExpr operator |(const BoolExpr a, const BoolExpr b);
const BoolExpr operator |(const BoolExpr a, const Lit b);
const BoolExpr operator !(const BoolExpr);

bool operator ==(const BoolExpr a, const BoolExpr b);
bool operator !=(const BoolExpr a, const BoolExpr b);
std::ostream& operator<<(std::ostream &s, const BoolExpr e);
