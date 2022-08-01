#ifndef BOOLEXPR_HPP
#define BOOLEXPR_HPP

#include "../its/types.hpp"
#include "../util/option.hpp"
#include "../expr/rel.hpp"
#include "../its/guard.hpp"
#include "../its/variablemanager.hpp"

#include <memory>
#include <set>

class BoolLit;
class BoolJunction;
class BoolExpression;
class Quantifier;
class QuantifiedFormula;
typedef std::shared_ptr<const BoolExpression> BoolExpr;

struct boolexpr_compare {
    bool operator() (BoolExpr a, BoolExpr b) const;
};

typedef std::set<BoolExpr, boolexpr_compare> BoolExprSet;

class BoolExpression: public std::enable_shared_from_this<BoolExpression> {

    friend class BoolLit;
    friend class BoolJunction;
    friend class BoolConst;

public:
    virtual option<Rel> getLit() const = 0;
    virtual bool isAnd() const = 0;
    virtual bool isOr() const = 0;
    virtual BoolExprSet getChildren() const = 0;
    virtual const BoolExpr negation() const = 0;
    virtual bool isLinear() const = 0;
    virtual bool isPolynomial() const = 0;
    virtual ~BoolExpression();
    virtual BoolExpr subs(const Subs &subs) const = 0;
    RelSet lits() const;
    virtual RelSet universallyValidLits() const = 0;
    VarSet vars() const;
    std::vector<Guard> dnf() const;
    virtual bool isConjunction() const = 0;
    Guard conjunctionToGuard() const;
    virtual BoolExpr toG() const = 0;
    virtual void collectLits(RelSet &res) const = 0;
    virtual void collectVars(VarSet &res) const = 0;
    virtual std::string toRedlog() const = 0;
    virtual size_t size() const = 0;
    virtual BoolExpr replaceRels(const RelMap<BoolExpr> map) const = 0;
    virtual unsigned hash() const = 0;
    QuantifiedFormula quantify(const std::vector<Quantifier> &prefix) const;
    virtual option<BoolExpr> simplify() const = 0;

protected:
    virtual void dnf(std::vector<Guard> &res) const = 0;
};

class BoolLit: public BoolExpression {

private:

    Rel lit;

public:

    BoolLit(const Rel &lit);
    bool isAnd() const override;
    bool isOr() const override;
    option<Rel> getLit() const override;
    BoolExprSet getChildren() const override;
    const BoolExpr negation() const override;
    bool isLinear() const override;
    bool isPolynomial() const override;
    ~BoolLit() override;
    BoolExpr subs(const Subs &subs) const override;
    bool isConjunction() const override;
    BoolExpr toG() const override;
    RelSet universallyValidLits() const override;
    void collectLits(RelSet &res) const override;
    void collectVars(VarSet &res) const override;
    size_t size() const override;
    std::string toRedlog() const override;
    BoolExpr replaceRels(const RelMap<BoolExpr> map) const override;
    unsigned hash() const override;
    option<BoolExpr> simplify() const override;

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
    option<Rel> getLit() const override;
    BoolExprSet getChildren() const override;
    const BoolExpr negation() const override;
    bool isLinear() const override;
    bool isPolynomial() const override;
    ~BoolJunction() override;
    BoolExpr subs(const Subs &subs) const override;
    bool isConjunction() const override;
    BoolExpr toG() const override;
    RelSet universallyValidLits() const override;
    void collectLits(RelSet &res) const override;
    void collectVars(VarSet &res) const override;
    size_t size() const override;
    std::string toRedlog() const override;
    BoolExpr replaceRels(const RelMap<BoolExpr> map) const override;
    unsigned hash() const override;
    option<BoolExpr> simplify() const override;

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
    QuantifiedFormula subs(const Subs &subs) const;
    QuantifiedFormula toG() const;
    void collectLits(RelSet &res) const;
    VarSet freeVars() const;
    std::string toRedlog() const;
    std::pair<QuantifiedFormula, Subs> normalizeVariables(VariableManager &varMan) const;
    option<QuantifiedFormula> simplify() const;
    bool isTiviallyTrue() const;
    bool isTiviallyFalse() const;
    friend std::ostream& operator<<(std::ostream &s, const QuantifiedFormula f);
    std::vector<Quantifier> getPrefix() const;
    BoolExpr getMatrix() const;
    bool isConjunction() const;

};

const BoolExpr buildAnd(const std::vector<Rel> &xs);
const BoolExpr buildAnd(const std::vector<BoolExpr> &xs);
const BoolExpr buildOr(const std::vector<Rel> &xs);
const BoolExpr buildOr(const std::vector<BoolExpr> &xs);
const BoolExpr buildAnd(const RelSet &xs);
const BoolExpr buildAnd(const BoolExprSet &xs);
const BoolExpr buildOr(const RelSet &xs);
const BoolExpr buildOr(const BoolExprSet &xs);
const BoolExpr buildLit(const Rel &lit);
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

#endif // BOOLEXPR_HPP
