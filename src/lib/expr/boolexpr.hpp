#pragma once

#include "itheory.hpp"
#include "variantset.hpp"
#include "arithlit.hpp"
#include "conshash.hpp"
#include "linkedhashset.hpp"
#include "bools.hpp"
#include "arith.hpp"

#include <type_traits>
#include <memory>
#include <boost/functional/hash.hpp>


class BoolTheoryLit;
class BoolJunction;
class BoolExpression;
using BoolExpr = std::shared_ptr<const BoolExpression>;

using BoolExpressionSet = linked_hash_set<BoolExpr>;

enum ConcatOperator { ConcatAnd, ConcatOr };

class BoolExpression: public std::enable_shared_from_this<BoolExpression> {

    friend class BoolTheoryLit;
    friend class BoolJunction;

protected:

    using TheTheory = BaseTheory<Arith, Bools>;
    using Var = typename TheTheory::Var;
    using Lit = typename TheTheory::Lit;
    using Model = typename TheTheory::Model;
    using VarSet = VariantSet<Arith::Var, Bools::Var>;
    using LitSet = VariantSet<Arith::Lit, Bools::Lit>;

private:

    static const BoolExpr from_cache(const BoolExpressionSet &children, ConcatOperator op);

    template <class Lits>
    static const BoolExpr buildFromLits(const Lits &lits, ConcatOperator op) {
        BoolExpressionSet children;
        for (const auto &lit: lits) {
            children.insert(mkLit(lit));
        }
        return from_cache(children, op);
    }

    template <class Children>
    static const BoolExpr build(const Children &lits, ConcatOperator op) {
        std::stack<BoolExpr> todo;
        for (const auto &lit: lits) {
            todo.push(lit);
        }
        BoolExpressionSet children;
        while (!todo.empty()) {
            BoolExpr current = todo.top();
            if ((op == ConcatAnd && current->isAnd()) || (op == ConcatOr && current->isOr())) {
                const BoolExpressionSet &currentChildren = current->getChildren();
                todo.pop();
                for (const BoolExpr &c: currentChildren) {
                    todo.push(c);
                }
            } else {
                children.insert(current);
                todo.pop();
            }
        }
        if (children.size() == 1) {
            return *children.begin();
        }
        return from_cache(children, op);
    }

public:

    static const BoolExpr top();
    static const BoolExpr bot();

    template <class Lits>
    static const BoolExpr mkAndFromLits(const Lits &lits) {
        return buildFromLits(lits, ConcatAnd);
    }

    template <class Children>
    static const BoolExpr mkAnd(const Children &lits) {
        return build(lits, ConcatAnd);
    }

    template <class Lits>
    static const BoolExpr mkOrFromLits(const Lits &lits) {
        return buildFromLits(lits, ConcatOr);
    }

    template <class Children>
    static const BoolExpr mkOr(const Children &lits) {
        return build(lits, ConcatOr);
    }

    static const BoolExpr mkLit(const Lit &lit);

    virtual bool isTheoryLit() const = 0;
    virtual const Lit* getTheoryLit() const = 0;
    virtual bool isAnd() const = 0;
    virtual bool isOr() const = 0;
    virtual BoolExpressionSet getChildren() const = 0;
    virtual const BoolExpr negation() const = 0;
    virtual bool forall(const std::function<bool(const Lit&)> &pred) const = 0;
    virtual LitSet universallyValidLits() const = 0;
    virtual bool isConjunction() const = 0;
    virtual void collectLits(LitSet &res) const = 0;
    virtual size_t size() const = 0;
    virtual void getBounds(const ArithVarPtr n, Bounds &res) const = 0;

    bool isTriviallyTrue() const;
    bool isTriviallyFalse() const;
    Bounds getBounds(const ArithVarPtr n) const;
    BoolExpr linearize(const ArithVarPtr n) const;
    BoolExpr toInfinity(const ArithVarPtr n) const;
    BoolExpr toMinusInfinity(const ArithVarPtr n) const;
    void iter(const std::function<void(const Lit&)> &f) const;
    BoolExpr map(const std::function<BoolExpr(const Lit&)> &f, std::unordered_map<BoolExpr, BoolExpr> &cache) const;
    BoolExpr map(const std::function<BoolExpr(const Lit&)> &f) const;

    void collectVars(VarSet &vars) const;

    template <ITheory T>
    void collectVars(linked_hash_set<typename T::Var> &vars) const {
        VarSet res;
        res.template get<typename T::Var>() = vars;
        collectVars(res);
    }

    VarSet vars() const;
    BoolExpr simplify() const;
    virtual ~BoolExpression();
    LitSet lits() const;
    bool isLinear() const;
    bool isPoly() const;

};


class BoolTheoryLit: public BoolExpression {

    const Lit lit;

    struct CacheEqual {
        bool operator()(const std::tuple<Lit> &args1, const std::tuple<Lit> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<Lit> &args) const noexcept;
    };

    static ConsHash<BoolExpression, BoolTheoryLit, CacheHash, CacheEqual, Lit> cache;

public:

    BoolTheoryLit(const Lit &lit);
    static BoolExpr from_cache(const Lit &lit);
    bool isAnd() const override;
    bool isOr() const override;
    bool isTheoryLit() const override;
    const Lit* getTheoryLit() const override;
    BoolExpressionSet getChildren() const override;
    const BoolExpr negation() const override;
    bool forall(const std::function<bool(const Lit&)> &pred) const override;
    ~BoolTheoryLit() override;
    bool isConjunction() const override;
    LitSet universallyValidLits() const override;
    void collectLits(LitSet &res) const override;
    size_t size() const override;
    void getBounds(const ArithVarPtr var, Bounds &res) const override;

};

class BoolJunction: public BoolExpression {

    const BoolExpressionSet children;
    const ConcatOperator op;

    struct CacheEqual {
        bool operator()(const std::tuple<BoolExpressionSet, ConcatOperator> &args1, const std::tuple<BoolExpressionSet, ConcatOperator> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<BoolExpressionSet, ConcatOperator> &args) const noexcept;
    };

    static ConsHash<BoolExpression, BoolJunction, CacheHash, CacheEqual, BoolExpressionSet, ConcatOperator> cache;

public:

    static BoolExpr from_cache(const BoolExpressionSet &children, ConcatOperator op);
    BoolJunction(const BoolExpressionSet &children, ConcatOperator op);
    bool isAnd() const override;
    bool isOr() const override;
    bool isTheoryLit() const override;
    const Lit* getTheoryLit() const override;
    BoolExpressionSet getChildren() const override;
    const BoolExpr negation() const override;
    bool forall(const std::function<bool(const Lit&)> &pred) const override;
    ~BoolJunction() override;
    bool isConjunction() const override;
    LitSet universallyValidLits() const override;
    void collectLits(LitSet &res) const override;
    size_t size() const override;
    void getBounds(const ArithVarPtr n, Bounds &res) const override;

};

const BoolExpr operator&&(const BoolExpr a, const BoolExpr b);

const BoolExpr operator||(const BoolExpr a, const BoolExpr b);

const BoolExpr operator!(const BoolExpr a);

std::ostream& operator<<(std::ostream &s, const BoolExpr e);

template<>
struct std::hash<BoolExpr> {
    std::size_t operator()(const BoolExpr x) const noexcept {
        return boost::hash_value(x);
    }
};
