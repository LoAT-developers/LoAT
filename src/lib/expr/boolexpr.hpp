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

using BoolExprPtr = std::shared_ptr<const BoolExpr>;
using BoolExprSet = linked_hash_set<BoolExprPtr>;

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

    static const BoolExprPtr from_cache(const BoolExprSet &children, ConcatOperator op);

    template <class Lits>
    static const BoolExprPtr buildFromLits(const Lits &lits, ConcatOperator op) {
        BoolExprSet children;
        for (const auto &lit: lits) {
            children.insert(mkLit(lit));
        }
        return from_cache(children, op);
    }

    template <class Children>
    static const BoolExprPtr build(const Children &lits, ConcatOperator op) {
        std::stack<BoolExprPtr> todo;
        for (const auto &lit: lits) {
            todo.push(lit);
        }
        BoolExprSet children;
        while (!todo.empty()) {
            BoolExprPtr current = todo.top();
            if ((op == ConcatAnd && current->isAnd()) || (op == ConcatOr && current->isOr())) {
                const BoolExprSet &currentChildren = current->getChildren();
                todo.pop();
                for (const BoolExprPtr &c: currentChildren) {
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

    static const BoolExprPtr top();
    static const BoolExprPtr bot();

    template <class Lits>
    static const BoolExprPtr mkAndFromLits(const Lits &lits) {
        return buildFromLits(lits, ConcatAnd);
    }

    template <class Children>
    static const BoolExprPtr mkAnd(const Children &lits) {
        return build(lits, ConcatAnd);
    }

    template <class Lits>
    static const BoolExprPtr mkOrFromLits(const Lits &lits) {
        return buildFromLits(lits, ConcatOr);
    }

    template <class Children>
    static const BoolExprPtr mkOr(const Children &lits) {
        return build(lits, ConcatOr);
    }

    static const BoolExprPtr mkLit(const Lit &lit);

    virtual bool isTheoryLit() const = 0;
    virtual const Lit* getTheoryLit() const = 0;
    virtual bool isAnd() const = 0;
    virtual bool isOr() const = 0;
    virtual BoolExprSet getChildren() const = 0;
    virtual const BoolExprPtr negation() const = 0;
    virtual bool forall(const std::function<bool(const Lit&)> &pred) const = 0;
    virtual LitSet universallyValidLits() const = 0;
    virtual bool isConjunction() const = 0;
    virtual void collectLits(LitSet &res) const = 0;
    virtual size_t size() const = 0;
    virtual void getBounds(const Arith::Var n, Bounds &res) const = 0;

    bool isTriviallyTrue() const;
    bool isTriviallyFalse() const;
    Bounds getBounds(const Arith::Var n) const;
    BoolExprPtr linearize(const Arith::Var n) const;
    BoolExprPtr toInfinity(const Arith::Var n) const;
    BoolExprPtr toMinusInfinity(const Arith::Var n) const;
    void iter(const std::function<void(const Lit&)> &f) const;
    BoolExprPtr map(const std::function<BoolExprPtr(const Lit&)> &f, std::unordered_map<BoolExprPtr, BoolExprPtr> &cache) const;
    BoolExprPtr map(const std::function<BoolExprPtr(const Lit&)> &f) const;

    void collectVars(VarSet &vars) const;

    template <ITheory T>
    void collectVars(linked_hash_set<typename T::Var> &vars) const {
        VarSet res;
        res.template get<typename T::Var>() = vars;
        collectVars(res);
    }

    VarSet vars() const;
    BoolExprPtr simplify() const;
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
    static BoolExprPtr from_cache(const Lit &lit);
    bool isAnd() const override;
    bool isOr() const override;
    bool isTheoryLit() const override;
    const Lit* getTheoryLit() const override;
    BoolExprSet getChildren() const override;
    const BoolExprPtr negation() const override;
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

    static BoolExprPtr from_cache(const BoolExprSet &children, ConcatOperator op);
    BoolJunction(const BoolExprSet &children, ConcatOperator op);
    bool isAnd() const override;
    bool isOr() const override;
    bool isTheoryLit() const override;
    const Lit* getTheoryLit() const override;
    BoolExprSet getChildren() const override;
    const BoolExprPtr negation() const override;
    bool forall(const std::function<bool(const Lit&)> &pred) const override;
    ~BoolJunction() override;
    bool isConjunction() const override;
    LitSet universallyValidLits() const override;
    void collectLits(LitSet &res) const override;
    size_t size() const override;
    void getBounds(const Arith::Var n, Bounds &res) const override;

};

const BoolExprPtr operator&&(const BoolExprPtr a, const BoolExprPtr b);

const BoolExprPtr operator||(const BoolExprPtr a, const BoolExprPtr b);

const BoolExprPtr operator!(const BoolExprPtr a);

std::ostream& operator<<(std::ostream &s, const BoolExprPtr e);

template<>
struct std::hash<BoolExprPtr> {
    std::size_t operator()(const BoolExprPtr x) const noexcept {
        return boost::hash_value(x);
    }
};
