#pragma once

#include "itheory.hpp"
#include "thset.hpp"
#include "conjunction.hpp"
#include "arithlit.hpp"
#include "conshash.hpp"
#include "set.hpp"
#include "bools.hpp"
#include "arith.hpp"

#include <type_traits>
#include <memory>
#include <boost/functional/hash.hpp>


class BoolTheoryLit;
class BoolJunction;
class BoolExpression;
using BExpr = std::shared_ptr<const BoolExpression>;

using BoolExpressionSet = linked_hash_set<BExpr>;

enum ConcatOperator { ConcatAnd, ConcatOr };

class BoolExpression: public std::enable_shared_from_this<BoolExpression> {

    friend class BoolTheoryLit;
    friend class BoolJunction;

    using T = BaseTheory<Arith, Bools>;
    using Var = typename T::Var;
    using Lit = typename T::Lit;
    using Model = typename T::Model;
    using VS = theories::ThSet<Arith::Var, Bools::Var>;
    using LS = theories::ThSet<Arith::Lit, Bools::Lit>;
    using G = Conjunction;
    using BE = BExpr;
    using BES = BoolExpressionSet;

private:

    static const BE from_cache(const BES &children, ConcatOperator op);

    template <class Lits>
    static const BE buildFromLits(const Lits &lits, ConcatOperator op) {
        BES children;
        for (const auto &lit: lits) {
            children.insert(mkLit(lit));
        }
        return from_cache(children, op);
    }

    template <class Children>
    static const BE build(const Children &lits, ConcatOperator op) {
        std::stack<BE> todo;
        for (const auto &lit: lits) {
            todo.push(lit);
        }
        BES children;
        while (!todo.empty()) {
            BE current = todo.top();
            if ((op == ConcatAnd && current->isAnd()) || (op == ConcatOr && current->isOr())) {
                const BES &currentChildren = current->getChildren();
                todo.pop();
                for (const BE &c: currentChildren) {
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

    static const BE top();
    static const BE bot();

    template <class Lits>
    static const BE mkAndFromLits(const Lits &lits) {
        return buildFromLits(lits, ConcatAnd);
    }

    template <class Children>
    static const BE mkAnd(const Children &lits) {
        return build(lits, ConcatAnd);
    }

    template <class Lits>
    static const BE mkOrFromLits(const Lits &lits) {
        return buildFromLits(lits, ConcatOr);
    }

    template <class Children>
    static const BE mkOr(const Children &lits) {
        return build(lits, ConcatOr);
    }

    static const BE mkLit(const Lit &lit);

    virtual bool isTheoryLit() const = 0;
    virtual const Lit* getTheoryLit() const = 0;
    virtual bool isAnd() const = 0;
    virtual bool isOr() const = 0;
    virtual BES getChildren() const = 0;
    virtual const BE negation() const = 0;
    virtual bool forall(const std::function<bool(const Lit&)> &pred) const = 0;
    virtual LS universallyValidLits() const = 0;
    virtual bool isConjunction() const = 0;
    virtual void collectLits(LS &res) const = 0;
    virtual size_t size() const = 0;
    virtual void getBounds(const ArithVarPtr n, Bounds &res) const = 0;

    bool isTriviallyTrue() const;
    bool isTriviallyFalse() const;
    Bounds getBounds(const ArithVarPtr n) const;
    BE linearize(const ArithVarPtr n) const;
    BE toInfinity(const ArithVarPtr n) const;
    BE toMinusInfinity(const ArithVarPtr n) const;
    void iter(const std::function<void(const Lit&)> &f) const;
    BE map(const std::function<BE(const Lit&)> &f, std::unordered_map<BE, BE> &cache) const;
    BE map(const std::function<BE(const Lit&)> &f) const;

    void collectVars(VS &vars) const;

    template <ITheory T>
    void collectVars(linked_hash_set<typename T::Var> &vars) const {
        VS res;
        res.template get<typename T::Var>() = vars;
        collectVars(res);
    }

    VS vars() const;
    BE simplify() const;
    virtual ~BoolExpression();
    LS lits() const;
    bool isLinear() const;
    bool isPoly() const;
    G conjunctionToGuard() const;

};


class BoolTheoryLit: public BoolExpression {

    using T = BaseTheory<Arith, Bools>;
    using Var = typename T::Var;
    using Lit = typename T::Lit;
    using VS = theories::ThSet<Arith::Var, Bools::Var>;
    using LS = theories::ThSet<Arith::Lit, Bools::Lit>;
    using G = Conjunction;
    using BE = BExpr;
    using BES = BoolExpressionSet;

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
    static BE from_cache(const Lit &lit);
    bool isAnd() const override;
    bool isOr() const override;
    bool isTheoryLit() const override;
    const Lit* getTheoryLit() const override;
    BES getChildren() const override;
    const BE negation() const override;
    bool forall(const std::function<bool(const Lit&)> &pred) const override;
    ~BoolTheoryLit() override;
    bool isConjunction() const override;
    LS universallyValidLits() const override;
    void collectLits(LS &res) const override;
    size_t size() const override;
    void getBounds(const ArithVarPtr var, Bounds &res) const override;

};

class BoolJunction: public BoolExpression {

    using T = BaseTheory<Arith, Bools>;
    using Var = typename T::Var;
    using Lit = typename T::Lit;
    using VS = theories::ThSet<Arith::Var, Bools::Var>;
    using LS = theories::ThSet<Arith::Lit, Bools::Lit>;
    using G = Conjunction;
    using BE = BExpr;
    using BES = BoolExpressionSet;

    const BES children;
    const ConcatOperator op;

    struct CacheEqual {
        bool operator()(const std::tuple<BES, ConcatOperator> &args1, const std::tuple<BES, ConcatOperator> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<BES, ConcatOperator> &args) const noexcept;
    };

    static ConsHash<BoolExpression, BoolJunction, CacheHash, CacheEqual, BES, ConcatOperator> cache;

public:

    static BE from_cache(const BES &children, ConcatOperator op);
    BoolJunction(const BES &children, ConcatOperator op);
    bool isAnd() const override;
    bool isOr() const override;
    bool isTheoryLit() const override;
    const Lit* getTheoryLit() const override;
    BES getChildren() const override;
    const BE negation() const override;
    bool forall(const std::function<bool(const Lit&)> &pred) const override;
    ~BoolJunction() override;
    bool isConjunction() const override;
    LS universallyValidLits() const override;
    void collectLits(LS &res) const override;
    size_t size() const override;
    void getBounds(const ArithVarPtr n, Bounds &res) const override;

};

const BExpr operator&&(const BExpr a, const BExpr b);

const BExpr operator||(const BExpr a, const BExpr b);

const BExpr operator!(const BExpr a);

std::ostream& operator<<(std::ostream &s, const BExpr e);
