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
    static const Bools::Expr buildFromLits(const Lits &lits, ConcatOperator op);

    template <class Children>
    static const Bools::Expr build(const Children &lits, ConcatOperator op);

public:

    static const Bools::Expr top();
    static const Bools::Expr bot();

    template <class Lits>
    static const Bools::Expr mkAndFromLits(const Lits &lits);

    template <class Children>
    static const Bools::Expr mkAnd(const Children &lits);

    template <class Children>
    static const Bools::Expr mkOr(const Children &lits);

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

    void getBounds(const Arith::Var n, linked_hash_set<Bound> &res) const;
    linked_hash_set<Bound> getBounds(const Arith::Var n) const;
    void getDivisibility(const Arith::Var n, linked_hash_set<Divisibility> &res) const;
    linked_hash_set<Divisibility> getDivisibility(const Arith::Var n) const;
    std::optional<Arith::Expr> getEquality(const Arith::Var n) const;
    void propagateEqualities(Arith::Subs &subs, const std::function<bool(const Var &)> &allow) const;
    Arith::Subs propagateEqualities(const std::function<bool(const Var &)> &allow) const;
    Bools::Expr toInfinity(const Arith::Var n) const;
    Bools::Expr toMinusInfinity(const Arith::Var n) const;
    void iter(const std::function<void(const Lit&)> &f) const;
    Bools::Expr map(const std::function<Bools::Expr(const Lit&)> &f, std::unordered_map<Bools::Expr, Bools::Expr> &cache) const;
    Bools::Expr map(const std::function<Bools::Expr(const Lit&)> &f) const;
    sexpresso::Sexp to_smtlib(const std::function<std::string(const Var &)>&) const;
    BoolExprSet get_disjuncts() const;

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

};

const Bools::Expr operator&&(const Bools::Expr a, const Bools::Expr b);

const Bools::Expr operator||(const Bools::Expr a, const Bools::Expr b);

const Bools::Expr operator!(const Bools::Expr a);

std::ostream& operator<<(std::ostream &s, const Bools::Expr e);
