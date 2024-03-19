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
class BoolExpr;

using BoolExprSet = linked_hash_set<Bools::Expr>;

enum ConcatOperator { ConcatAnd, ConcatOr };

class BoolExpr: public std::enable_shared_from_this<BoolExpr> {

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

    static const Bools::Expr from_cache(const BoolExprSet &children, ConcatOperator op);

    template <class Lits>
    static const Bools::Expr buildFromLits(const Lits &lits, ConcatOperator op) {
        BoolExprSet children;
        for (const auto &lit: lits) {
            const auto l {mkLit(lit)};
            if (l == top()) {
                if (op == ConcatOr) {
                    return top();
                }
            } else if (l == bot()) {
                if (op == ConcatAnd) {
                    return bot();
                }
            } else {
                children.insert(l);
            }
        }
        return from_cache(children, op);
    }

    template <class Children>
    static const Bools::Expr build(const Children &lits, ConcatOperator op) {
        std::stack<Bools::Expr> todo;
        for (const auto &lit: lits) {
            if (lit == top()) {
                if (op == ConcatOr) {
                    return top();
                }
            } else if (lit == bot()) {
                if (op == ConcatAnd) {
                    return bot();
                }
            } else {
                todo.push(lit);
            }
        }
        BoolExprSet children;
        while (!todo.empty()) {
            Bools::Expr current = todo.top();
            if ((op == ConcatAnd && current->isAnd()) || (op == ConcatOr && current->isOr())) {
                const BoolExprSet &currentChildren = current->getChildren();
                todo.pop();
                for (const Bools::Expr &c: currentChildren) {
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

    static const Bools::Expr top();
    static const Bools::Expr bot();

    template <class Lits>
    static const Bools::Expr mkAndFromLits(const Lits &lits) {
        return buildFromLits(lits, ConcatAnd);
    }

    template <class Children>
    static const Bools::Expr mkAnd(const Children &lits) {
        return build(lits, ConcatAnd);
    }

    template <class Lits>
    static const Bools::Expr mkOrFromLits(const Lits &lits) {
        return buildFromLits(lits, ConcatOr);
    }

    template <class Children>
    static const Bools::Expr mkOr(const Children &lits) {
        return build(lits, ConcatOr);
    }

    static const Bools::Expr mkLit(const Lit &lit);

    virtual bool isTheoryLit() const = 0;
    virtual const Lit* getTheoryLit() const = 0;
    virtual bool isAnd() const = 0;
    virtual bool isOr() const = 0;
    virtual BoolExprSet getChildren() const = 0;
    virtual const Bools::Expr negation() const = 0;
    virtual bool forall(const std::function<bool(const Lit&)> &pred) const = 0;
    virtual LitSet universallyValidLits() const = 0;
    virtual bool isConjunction() const = 0;
    virtual void collectLits(LitSet &res) const = 0;
    virtual size_t size() const = 0;
    virtual void getBounds(const Arith::Var n, Bounds &res) const = 0;

    Bounds getBounds(const Arith::Var n) const;
    Bools::Expr linearize(const Arith::Var n) const;
    Bools::Expr toInfinity(const Arith::Var n) const;
    Bools::Expr toMinusInfinity(const Arith::Var n) const;
    void iter(const std::function<void(const Lit&)> &f) const;
    Bools::Expr map(const std::function<Bools::Expr(const Lit&)> &f, std::unordered_map<Bools::Expr, Bools::Expr> &cache) const;
    Bools::Expr map(const std::function<Bools::Expr(const Lit&)> &f) const;

    void collectVars(VarSet &vars) const;

    template <ITheory T>
    void collectVars(linked_hash_set<typename T::Var> &vars) const {
        VarSet res;
        res.template get<typename T::Var>() = vars;
        collectVars(res);
    }

    VarSet vars() const;
    virtual ~BoolExpr();
    LitSet lits() const;
    bool isLinear() const;
    bool isPoly() const;

};


class BoolTheoryLit: public BoolExpr {

    const Lit lit;

    struct CacheEqual {
        bool operator()(const std::tuple<Lit> &args1, const std::tuple<Lit> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<Lit> &args) const noexcept;
    };

    static ConsHash<BoolExpr, BoolTheoryLit, CacheHash, CacheEqual, Lit> cache;

public:

    BoolTheoryLit(const Lit &lit);
    static Bools::Expr from_cache(const Lit &lit);
    bool isAnd() const override;
    bool isOr() const override;
    bool isTheoryLit() const override;
    const Lit* getTheoryLit() const override;
    BoolExprSet getChildren() const override;
    const Bools::Expr negation() const override;
    bool forall(const std::function<bool(const Lit&)> &pred) const override;
    ~BoolTheoryLit() override;
    bool isConjunction() const override;
    LitSet universallyValidLits() const override;
    void collectLits(LitSet &res) const override;
    size_t size() const override;
    void getBounds(const Arith::Var var, Bounds &res) const override;

};

class BoolJunction: public BoolExpr {

    const BoolExprSet children;
    const ConcatOperator op;

    struct CacheEqual {
        bool operator()(const std::tuple<BoolExprSet, ConcatOperator> &args1, const std::tuple<BoolExprSet, ConcatOperator> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<BoolExprSet, ConcatOperator> &args) const noexcept;
    };

    static ConsHash<BoolExpr, BoolJunction, CacheHash, CacheEqual, BoolExprSet, ConcatOperator> cache;

public:

    static Bools::Expr from_cache(const BoolExprSet &children, ConcatOperator op);
    BoolJunction(const BoolExprSet &children, ConcatOperator op);
    bool isAnd() const override;
    bool isOr() const override;
    bool isTheoryLit() const override;
    const Lit* getTheoryLit() const override;
    BoolExprSet getChildren() const override;
    const Bools::Expr negation() const override;
    bool forall(const std::function<bool(const Lit&)> &pred) const override;
    ~BoolJunction() override;
    bool isConjunction() const override;
    LitSet universallyValidLits() const override;
    void collectLits(LitSet &res) const override;
    size_t size() const override;
    void getBounds(const Arith::Var n, Bounds &res) const override;

};

const Bools::Expr operator&&(const Bools::Expr a, const Bools::Expr b);

const Bools::Expr operator||(const Bools::Expr a, const Bools::Expr b);

const Bools::Expr operator!(const Bools::Expr a);

std::ostream& operator<<(std::ostream &s, const Bools::Expr e);
