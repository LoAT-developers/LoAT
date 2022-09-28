#pragma once

#include "option.hpp"
#include "rel.hpp"
#include "guard.hpp"
#include "boolvar.hpp"
#include "variablemanager.hpp"

#include <memory>
#include <set>

class BoolLit;
class BoolTheoryLit;
class BoolJunction;
class BoolExpression;
class Quantifier;
class QuantifiedFormula;
typedef std::shared_ptr<const BoolExpression> BoolExpr;

struct Bounds {
    ExprSet upperBounds;
    ExprSet lowerBounds;
    option<Expr> equality;
};

struct boolexpr_compare {
    bool operator() (const BoolExpr a, const BoolExpr b) const;
};

typedef std::set<BoolExpr, boolexpr_compare> BoolExprSet;

class BoolExpression: public std::enable_shared_from_this<BoolExpression> {

    friend class BoolLit;
    friend class BoolTheoryLit;
    friend class BoolJunction;
    friend class BoolConst;

public:

    virtual option<Rel> getTheoryLit() const = 0;
    virtual option<BoolLit> getLit() const = 0;
    virtual bool isAnd() const = 0;
    virtual bool isOr() const = 0;
    virtual BoolExprSet getChildren() const = 0;
    virtual const BoolExpr negation() const = 0;
    virtual bool isLinear() const = 0;
    virtual bool isPolynomial() const = 0;
    virtual ~BoolExpression();
    RelSet lits() const;
    virtual RelSet universallyValidLits() const = 0;
    void findConsequences(const BoolVar &var, BoolExprSet &res) const;
    VarSet vars() const;
    BoolVarSet boolVars() const;
    std::vector<Guard> dnf() const;
    virtual bool isConjunction() const = 0;
    Guard conjunctionToGuard() const;
    virtual BoolExpr toG() const = 0;
    virtual void collectLits(RelSet &res) const = 0;
    virtual void collectVars(VarSet &res) const = 0;
    virtual void collectBoolVars(BoolVarSet &res) const = 0;
    virtual BoolExpr subs(const ExprSubs &subs) const = 0;
    virtual std::string toRedlog() const = 0;
    virtual size_t size() const = 0;
    virtual BoolExpr replaceRels(const RelMap<BoolExpr> map) const = 0;
    virtual unsigned hash() const = 0;
    QuantifiedFormula quantify(const std::vector<Quantifier> &prefix) const;
    virtual void getBounds(const Var &n, Bounds &res) const = 0;
    virtual option<BoolExpr> simplify() const = 0;
    virtual bool isOctagon() const = 0;
    virtual int compare(const BoolExpr that) const = 0;

protected:
    virtual void dnf(std::vector<Guard> &res) const = 0;
};

class BoolTheoryLit: public BoolExpression {

private:

    Rel lit;

public:

    BoolTheoryLit(const Rel &lit);
    bool isAnd() const override;
    bool isOr() const override;
    option<Rel> getTheoryLit() const override;
    option<BoolLit> getLit() const override;
    BoolExprSet getChildren() const override;
    const BoolExpr negation() const override;
    bool isLinear() const override;
    bool isPolynomial() const override;
    ~BoolTheoryLit() override;
    bool isConjunction() const override;
    BoolExpr toG() const override;
    RelSet universallyValidLits() const override;
    void collectLits(RelSet &res) const override;
    void collectVars(VarSet &res) const override;
    void collectBoolVars(BoolVarSet &res) const override;
    BoolExpr subs(const ExprSubs &subs) const override;
    size_t size() const override;
    std::string toRedlog() const override;
    BoolExpr replaceRels(const RelMap<BoolExpr> map) const override;
    unsigned hash() const override;
    void getBounds(const Var &n, Bounds &res) const override;
    option<BoolExpr> simplify() const override;
    bool isOctagon() const override;
    int compare(const BoolExpr that) const override;

protected:
    void dnf(std::vector<Guard> &res) const override;

};

class BoolLit: public BoolExpression {

private:

    const BoolVar var;
    bool negated;

public:

    BoolLit(const BoolVar &var, bool negated = false);
    bool isAnd() const override;
    bool isOr() const override;
    option<Rel> getTheoryLit() const override;
    option<BoolLit> getLit() const override;
    BoolExprSet getChildren() const override;
    const BoolExpr negation() const override;
    bool isLinear() const override;
    bool isPolynomial() const override;
    ~BoolLit() override;
    bool isConjunction() const override;
    BoolExpr toG() const override;
    RelSet universallyValidLits() const override;
    void collectLits(RelSet &res) const override;
    void collectVars(VarSet &res) const override;
    void collectBoolVars(BoolVarSet &res) const override;
    BoolExpr subs(const ExprSubs &subs) const override;
    size_t size() const override;
    std::string toRedlog() const override;
    BoolExpr replaceRels(const RelMap<BoolExpr> map) const override;
    unsigned hash() const override;
    void getBounds(const Var &n, Bounds &res) const override;
    option<BoolExpr> simplify() const override;
    bool isOctagon() const override;
    bool isNegated() const;
    BoolVar getBoolVar() const;
    int compare(const BoolExpr that) const override;

protected:
    void dnf(std::vector<Guard> &res) const override;

};

bool operator<(const BoolLit &l1, const BoolLit &l2);

std::ostream& operator<<(std::ostream &s, const BoolLit &e);

enum ConcatOperator { ConcatAnd, ConcatOr };

class BoolJunction: public BoolExpression {

private:

    BoolExprSet children;
    ConcatOperator op;

public:

    BoolJunction(const BoolExprSet &children, ConcatOperator op);
    bool isAnd() const override;
    bool isOr() const override;
    option<Rel> getTheoryLit() const override;
    option<BoolLit> getLit() const override;
    BoolExprSet getChildren() const override;
    const BoolExpr negation() const override;
    bool isLinear() const override;
    bool isPolynomial() const override;
    ~BoolJunction() override;
    bool isConjunction() const override;
    BoolExpr toG() const override;
    RelSet universallyValidLits() const override;
    void collectLits(RelSet &res) const override;
    void collectVars(VarSet &res) const override;
    void collectBoolVars(BoolVarSet &res) const override;
    BoolExpr subs(const ExprSubs &subs) const override;
    size_t size() const override;
    std::string toRedlog() const override;
    BoolExpr replaceRels(const RelMap<BoolExpr> map) const override;
    unsigned hash() const override;
    void getBounds(const Var &n, Bounds &res) const override;
    option<BoolExpr> simplify() const override;
    bool isOctagon() const override;
    int compare(const BoolExpr that) const override;

protected:
    void dnf(std::vector<Guard> &res) const override;

};

class Quantifier {

public:
    enum class Type { Forall, Exists };

private:
    Type qType;
    VarSet vars;
    VarMap<Expr> lowerBounds;
    VarMap<Expr> upperBounds;

public:
    Quantifier(const Type &qType, const VarSet &vars, const VarMap<Expr> &lowerBounds, const VarMap<Expr> &upperBounds);

    Quantifier negation() const;
    const VarSet& getVars() const;
    Type getType() const;
    std::string toRedlog() const;
    option<Expr> lowerBound(const Var &x) const;
    option<Expr> upperBound(const Var &x) const;
    Quantifier remove(const Var &x) const;

};

class QuantifiedFormula {

private:
    std::vector<Quantifier> prefix;
    BoolExpr matrix;

public:

    QuantifiedFormula(std::vector<Quantifier> prefix, const BoolExpr &matrix);
    const QuantifiedFormula negation() const;
    bool isLinear() const;
    bool isPolynomial() const;
    VarSet boundVars() const;
    QuantifiedFormula toG() const;
    void collectLits(RelSet &res) const;
    QuantifiedFormula subs(const ExprSubs &subs) const;
    VarSet freeVars() const;
    std::string toRedlog() const;
    option<QuantifiedFormula> simplify() const;
    bool isTiviallyTrue() const;
    bool isTiviallyFalse() const;
    friend std::ostream& operator<<(std::ostream &s, const QuantifiedFormula &f);
    std::vector<Quantifier> getPrefix() const;
    BoolExpr getMatrix() const;
    bool isConjunction() const;
    std::pair<QuantifiedFormula, ExprSubs> normalizeVariables(VariableManager &varMan) const;

};

const BoolExpr buildAnd(const std::vector<Rel> &xs);
const BoolExpr buildAnd(const std::vector<BoolExpr> &xs);
const BoolExpr buildOr(const std::vector<Rel> &xs);
const BoolExpr buildOr(const std::vector<BoolExpr> &xs);
const BoolExpr buildAnd(const RelSet &xs);
const BoolExpr buildAnd(const BoolExprSet &xs);
const BoolExpr buildOr(const RelSet &xs);
const BoolExpr buildOr(const BoolExprSet &xs);
const BoolExpr buildTheoryLit(const Rel &lit);
const BoolExpr buildLit(const BoolVar &var, bool negated = false);
const BoolExpr buildConjunctiveClause(const BoolExprSet &xs);

extern const BoolExpr True;
extern const BoolExpr False;

const BoolExpr operator &(const BoolExpr a, const BoolExpr b);
const BoolExpr operator &(const BoolExpr a, const Rel &b);
const BoolExpr operator |(const BoolExpr a, const BoolExpr b);
const BoolExpr operator |(const BoolExpr a, const Rel b);
const BoolExpr operator !(const BoolExpr);

bool operator ==(const BoolExpr a, const BoolExpr b);
bool operator !=(const BoolExpr a, const BoolExpr b);
std::ostream& operator<<(std::ostream &s, const BoolExpr e);
