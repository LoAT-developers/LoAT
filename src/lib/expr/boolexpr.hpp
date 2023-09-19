#pragma once

#include "itheory.hpp"
#include "thset.hpp"
#include "conjunction.hpp"
#include "rel.hpp"
#include "boollit.hpp"
#include "literal.hpp"

#include <type_traits>
#include <memory>
#include <set>
#include <unordered_set>
#include <boost/functional/hash.hpp>

template <ITheory... Th>
class BoolTheoryLit;
template <ITheory... Th>
class BoolJunction;
template <IBaseTheory... Th>
class BoolExpression;
template <ITheory... Th>
using BExpr = std::shared_ptr<const BoolExpression<Th...>>;
template<ITheory... Th>
struct BExprHash;
template<ITheory... Th>
struct BExprEqual;

template<ITheory... Th>
struct CacheEntry {
    std::weak_ptr<const BoolExpression<Th...>> ptr;
    size_t hash;

    CacheEntry(const BExpr<Th...> ptr): ptr(ptr), hash(ptr->hash()) {}

};

namespace literal {

template<std::size_t I = 0, ITheory... Th>
inline BExpr<Th...> subsImpl(const typename Theory<Th...>::Lit &lit, const theory::Subs<Th...> &s) {
    if constexpr (I < sizeof...(Th)) {
        if (lit.index() == I) {
            using T = typename std::tuple_element_t<I, std::tuple<Th...>>;
            if constexpr (std::same_as<typename T::Var, BoolVar>) {
                return s.template get<T>().subs(std::get<I>(lit));
            } else {
                return BoolExpression<Th...>::buildTheoryLit(std::get<I>(lit).subs(s.template get<T>()));
            }
        } else {
            return subsImpl<I+1, Th...>(lit, s);
        }
    } else {
        throw std::logic_error("unknown theory");
    }
}

template<ITheory... Th>
BExpr<Th...> subs(const typename Theory<Th...>::Lit &lit, const theory::Subs<Th...> &s) {
    return subsImpl<0, Th...>(lit, s);
}

}

template <ITheory... Th>
struct BExprCompare {
    bool operator() (const BExpr<Th...> a, const BExpr<Th...> b) const {
        return a < b;
    }
};

template<ITheory... Th>
struct CacheHash {
    std::size_t operator()(const CacheEntry<Th...> &e) const noexcept {
        return e.hash;
    }
};

template<ITheory... Th>
struct CacheEqual {
    std::size_t operator()(const CacheEntry<Th...> e1, const CacheEntry<Th...> e2) const noexcept {
        if (e1.hash != e2.hash || e1.ptr.expired() || e2.ptr.expired()) {
            return false;
        }
        const auto s1 {e1.ptr.lock()};
        const auto s2 {e2.ptr.lock()};
        if (s1 == s2) {
            return true;
        }
        const auto l1 {s1->getTheoryLit()};
        const auto l2 {s2->getTheoryLit()};
        if (l1 && l2) {
            return *l1 == *l2;
        } else if (l1 || l2) {
            return false;
        }
        if (s1->isAnd() != s2->isAnd()) {
            return false;
        } else {
            return s1->getChildren() == s2->getChildren();
        }
    }
};

template <ITheory... Th>
using BoolExpressionSet = std::set<BExpr<Th...>, BExprCompare<Th...>> ;

enum ConcatOperator { ConcatAnd, ConcatOr };

template <IBaseTheory... Th>
class BoolExpression: public std::enable_shared_from_this<BoolExpression<Th...>> {

    static_assert(sizeof...(Th) > 0);

    friend class BoolTheoryLit<Th...>;
    friend class BoolJunction<Th...>;

    using T = Theory<Th...>;
    using Var = typename T::Var;
    using Lit = typename T::Lit;
    using VS = theory::VarSet<Th...>;
    using LS = theory::LitSet<Th...>;
    using G = Conjunction<Th...>;
    using BE = BExpr<Th...>;
    using BES = BoolExpressionSet<Th...>;
    using Subs = theory::Subs<Th...>;

    static const BE from_cache(const BE e) {
        static std::unordered_set<
            CacheEntry<Th...>,
            CacheHash<Th...>,
            CacheEqual<Th...>> cache {};
        const CacheEntry ce {e};
        auto it {cache.find(ce)};
        if (it == cache.end()) {
            cache.insert(ce);
            return e;
        } else {
            return it->ptr.lock();
        }
    }

    static const BE build_cached(const BES &children, ConcatOperator op) {
        return from_cache(BE(new BoolJunction(children, op)));
    }

public:

    static const BE True;
    static const BE False;

    template <class LitPtrs>
    static const BE buildFromLitPtrs(const LitPtrs &lits, ConcatOperator op) {
        BES children;
        for (const Lit *lit: lits) {
            children.insert(buildTheoryLit(*lit));
        }
        return build_cached(children, op);
    }

    template <class Lits>
    static const BE buildFromLits(const Lits &lits, ConcatOperator op) {
        BES children;
        for (const Lit &lit: lits) {
            children.insert(buildTheoryLit(lit));
        }
        return build_cached(children, op);
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
        return build_cached(children, op);
    }

    template <class Lits>
    static const BE buildAndFromLits(const Lits &lits) {
        return buildFromLits(lits, ConcatAnd);
    }

    template <class LitPtrs>
    static const BE buildAndFromLitPtrs(const LitPtrs &lits) {
        return buildFromLitPtrs(lits, ConcatAnd);
    }

    template <class Children>
    static const BE buildAnd(const Children &lits) {
        return build(lits, ConcatAnd);
    }

    template <class Lits>
    static const BE buildOrFromLits(const Lits &lits) {
        return buildFromLits(lits, ConcatOr);
    }

    template <class Children>
    static const BE buildOr(const Children &lits) {
        return build(lits, ConcatOr);
    }

    static const BE buildTheoryLit(const Lit &lit) {
        return from_cache(BE(new BoolTheoryLit<Th...>(lit)));
    }

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
    virtual void getBounds(const Var &n, Bounds &res) const = 0;
    virtual std::size_t hash() const = 0;

    bool isTriviallyTrue() const {
        if (isTheoryLit()) {
            return literal::isTriviallyTrue<Th...>(*getTheoryLit());
        } else {
            const auto children = getChildren();
            if (isAnd()) {
                return std::all_of(children.begin(), children.end(), [](const auto &c){return c->isTriviallyTrue();});
            } else if (isOr()) {
                return std::any_of(children.begin(), children.end(), [](const auto &c){return c->isTriviallyTrue();});
            } else {
                throw std::logic_error("unknown junctor");
            }
        }
    }

private:

    bool implicant(Subs &subs, std::set<const Lit*> &res) const {
        if (isOr()) {
            std::optional<std::set<const Lit*>> best_res;
            for (const auto &c: getChildren()) {
                std::set<const Lit*> current_res;
                if (c->implicant(subs, current_res)) {
                    if (!best_res) {
                        best_res = current_res;
                    } else if (current_res.size() < best_res->size()) {
                        best_res = current_res;
                    }
                }
            }
            if (best_res) {
                res.insert(best_res->begin(), best_res->end());
            }
            return best_res.has_value();
        } else if (isAnd()) {
            for (const auto &c: getChildren()) {
                if (!c->implicant(subs, res)) {
                    res.clear();
                    return false;
                }
            }
            return true;
        } else {
            const auto lit = getTheoryLit();
            if (lit) {
                auto l = literal::subs(*lit, subs);
                const auto vars = l->vars();
                if (!vars.empty()) {
                    // Since this->subs(subs) is a tautology, we may set variables in non-ground
                    // literals to arbitrary values.
                    for (const auto &x: vars) {
                        subs.put(x, T::anyValue(x.index()));
                    }
                    l = l->subs(subs);
                }
                if (l->isTriviallyTrue()) {
                    res.insert(lit);
                    return true;
                } else {
                    return false;
                }
            } else {
                throw std::invalid_argument("unknown kind of BoolExpr");
            }
        }
    }

public:

    /**
     * Assumes that this->subs(subs) is a tautology.
     */
    std::optional<std::set<const Lit*>> implicant(Subs subs) const {
        std::set<const Lit*> res;
        if (implicant(subs, res)) {
            return res;
        } else {
            return {};
        }
    }

    void iter(const std::function<void(const Lit&)> &f) const {
        if (isTheoryLit()) {
            f(*getTheoryLit());
        } else {
            for (const auto &c: getChildren()) {
                c->iter(f);
            }
        }
    }

    template <ITheory... Th_>
    BExpr<Th_...> map(const std::function<BExpr<Th_...>(const Lit&)> &f) const {
        if (isAnd()) {
            BoolExpressionSet<Th_...> newChildren;
            for (const auto &c: getChildren()) {
                const auto simp = c->template map<Th_...>(f);
                if (simp == BoolExpression<Th_...>::False) {
                    return BoolExpression<Th_...>::False;
                } else {
                    if (simp != BoolExpression<Th_...>::True) {
                        if (simp->isAnd()) {
                            const auto children = simp->getChildren();
                            newChildren.insert(children.begin(), children.end());
                        } else {
                            newChildren.insert(simp);
                        }
                    }
                }
            }
            if (newChildren.empty()) {
                return BoolExpression<Th_...>::True;
            } else {
                for (const auto &c: newChildren) {
                    if (c->isTheoryLit()) {
                        if (newChildren.find(!c) != newChildren.end()) {
                            return BoolExpression<Th_...>::False;
                        }
                    }
                }
                return BoolExpression<Th_...>::buildAnd(newChildren);
            }
        } else if (isOr()) {
            BoolExpressionSet<Th_...> newChildren;
            for (const auto &c: getChildren()) {
                const auto simp = c->template map<Th_...>(f);
                if (simp == BoolExpression<Th_...>::True) {
                    return BoolExpression<Th_...>::True;
                } else {
                    if (simp != BoolExpression<Th_...>::False) {
                        if (simp->isOr()) {
                            const auto children = simp->getChildren();
                            newChildren.insert(children.begin(), children.end());
                        } else {
                            newChildren.insert(simp);
                        }
                    }
                }
            }
            if (newChildren.empty()) {
              return BoolExpression<Th_...>::False;
            } else {
                for (const auto &c: newChildren) {
                    if (c->isTheoryLit()) {
                        if (newChildren.find(!c) != newChildren.end()) {
                            return BoolExpression<Th_...>::True;
                        }
                    }
                }
                return BoolExpression<Th_...>::buildOr(newChildren);
            }
        } else if (isTheoryLit()) {
            return f(*getTheoryLit());
        }
        throw std::logic_error("unknown boolean expression");
    }

    BE map(const std::function<BE(const Lit&)> &f, std::unordered_map<BE, BE> &cache) const {
        const auto it {cache.find(this->shared_from_this())};
        if (it != cache.end()) {
            return it->second;
        }
        BE res;
        if (isAnd()) {
            bool changed = false;
            BoolExpressionSet<Th...> newChildren;
            for (const auto &c: getChildren()) {
                const auto simp = c->map(f, cache);
                changed |= simp.get() != c.get();
                if (simp == False) {
                    cache.emplace(this->shared_from_this(), False);
                    return False;
                } else {
                    if (simp != True) {
                        if (simp->isAnd()) {
                            const auto children = simp->getChildren();
                            newChildren.insert(children.begin(), children.end());
                        } else {
                            newChildren.insert(simp);
                        }
                    }
                }
            }
            if (!changed) {
                res = this->shared_from_this();
            } else if (newChildren.empty()) {
                res = True;
            } else {
                for (const auto &c: newChildren) {
                    if (c->isTheoryLit()) {
                        if (newChildren.find(!c) != newChildren.end()) {
                            cache.emplace(this->shared_from_this(), False);
                            return False;
                        }
                    }
                }
                res = buildAnd(newChildren);
            }
        } else if (isOr()) {
            BoolExpressionSet<Th...> newChildren;
            bool changed = false;
            for (const auto &c: getChildren()) {
                const auto simp = c->map(f, cache);
                changed |= simp.get() != c.get();
                if (simp == True) {
                    cache.emplace(this->shared_from_this(), True);
                    return True;
                } else {
                    if (simp != False) {
                        if (simp->isOr()) {
                            const auto children = simp->getChildren();
                            newChildren.insert(children.begin(), children.end());
                        } else {
                            newChildren.insert(simp);
                        }
                    }
                }
            }
            if (!changed) {
                res = this->shared_from_this();
            } else if (newChildren.empty()) {
                res = False;
            } else {
                for (const auto &c: newChildren) {
                    if (c->isTheoryLit()) {
                        if (newChildren.find(!c) != newChildren.end()) {
                            cache.emplace(this->shared_from_this(), True);
                            return True;
                        }
                    }
                }
                res = buildOr(newChildren);
            }
        } else if (isTheoryLit()) {
            const auto lit = *getTheoryLit();
            const auto mapped = f(lit);
            const auto mappedLit = mapped->getTheoryLit();
            if (mappedLit && *mappedLit == lit) {
                res = this->shared_from_this();
            } else {
                res = mapped;
            }
        }
        cache.emplace(this->shared_from_this(), res);
        return res;
    }

    BE map(const std::function<BE(const Lit&)> &f) const {
        std::unordered_map<BE, BE> cache;
        return map(f, cache);
    }

    BE subs(const Subs &subs) const {
        return map([&subs](const auto &lit) {
            return literal::subs<Th...>(lit, subs);
        });
    }

    void collectVars(VS &vars) const {
        iter([&vars](const auto &lit) {
            literal::collectVars<Th...>(lit, vars);
        });
    }

    template <ITheory T>
    void collectVars(std::set<typename T::Var> &vars) const {
        VS res;
        res.template get<typename T::Var>() = vars;
        collectVars(res);
    }

    VS vars() const {
        VS res;
        collectVars(res);
        return res;
    }

    BE simplify() const {
        return map([](const Lit &lit) -> BE {
            if (std::holds_alternative<Rel>(lit)) {
                const auto &rel = std::get<Rel>(lit);
                if (rel.isTriviallyTrue()) {
                    return True;
                } else if (rel.isTriviallyFalse()) {
                    return False;
                } else if (rel.isNeq()) {
                    return buildTheoryLit(Rel(rel.lhs(), Rel::lt, rel.rhs())) | (Rel(rel.lhs(), Rel::gt, rel.rhs()));
                }
            }
            return buildTheoryLit(lit);
        });
    }

    BE replaceLits(const std::map<Lit, BE> &m) const {
        return map([&m](const Lit &lit) {
            const auto it = m.find(lit);
            if (it != m.end()) {
                return it->second;
            }
            return buildTheoryLit(lit);
        });
    }

    virtual ~BoolExpression() {};

    LS lits() const {
        LS res;
        collectLits(res);
        return res;
    }

    bool isLinear() const {
        return forall([](const auto &lit) {
            if constexpr ((std::same_as<Rel, typename Th::Lit> || ...)) {
                if (std::holds_alternative<Rel>(lit)) {
                    return std::get<Rel>(lit).isLinear();
                }
            }
            if constexpr ((std::same_as<BoolLit, typename Th::Lit> || ...)) {
                if (std::holds_alternative<BoolLit>(lit)) {
                    return true;
                }
            }
            throw std::logic_error("unknown literal");
        });
    }

    bool isPoly() const{
        return forall([](const auto &lit) {
            if constexpr ((std::same_as<Rel, typename Th::Lit> || ...)) {
                if (std::holds_alternative<Rel>(lit)) {
                    return std::get<Rel>(lit).isPoly();
                }
            }
            if constexpr ((std::same_as<BoolLit, typename Th::Lit> || ...)) {
                if (std::holds_alternative<BoolLit>(lit)) {
                    return true;
                }
            }
            throw std::logic_error("unknown literal");
        });
    }

    Subs impliedEqualities() const {
        Subs res;
        std::vector<BE> todo;
        const auto find_elim = [](const BE &c) {
            std::optional<BoolVar> elim;
            const auto vars {c->vars().template get<BoolVar>()};
            for (const auto &x: vars) {
                if (x.isTempVar()) {
                    if (elim) {
                        return std::optional<BoolVar>{};
                    } else {
                        elim = x;
                    }
                }
            }
            return elim;
        };
        if (isAnd()) {
            const auto children {getChildren()};
            for (const auto &c: children) {
                if (c->isOr()) {
                    const auto elim {find_elim(c)};
                    if (elim) {
                        auto grandChildren {c->getChildren()};
                        auto lit {buildTheoryLit(BoolLit(*elim))};
                        bool positive {grandChildren.contains(lit)};
                        if (!positive) {
                            lit = !lit;
                            if (!grandChildren.contains(lit)) {
                                continue;
                            }
                        }
                        grandChildren.erase(lit);
                        const BE cand {buildOr(grandChildren)};
                        // we have     lit \/  cand
                        // search for !lit \/ !cand
                        if (children.contains((!lit) | (!cand))) {
                            // we have (lit \/ cand) /\ (!lit \/ !cand), i.e., lit <==> !cand
                            res.put(*elim, positive ? !cand : cand);
                        }
                    }
                }
            }
            todo.insert(todo.end(), children.begin(), children.end());
        } else {
            todo.push_back(this->shared_from_this());
        }
        for (const auto &current: todo) {
            if (current->isOr()) {
                const auto children {current->getChildren()};
                if (children.size() == 2) {
                    for (const auto &c: children) {
                        if (c->isAnd()) {
                            const auto elim {find_elim(c)};
                            if (elim) {
                                auto grandChildren {c->getChildren()};
                                auto lit {buildTheoryLit(BoolLit(*elim))};
                                bool positive {grandChildren.contains(lit)};
                                if (!positive) {
                                    lit = !lit;
                                    if (!grandChildren.contains(lit)) {
                                        continue;
                                    }
                                }
                                grandChildren.erase(lit);
                                const BE cand {buildAnd(grandChildren)};
                                if (children.contains((!lit) & (!cand))) {
                                    // we have (lit /\ cand) \/ (!lit /\ !cand), i.e., lit <==> cand
                                    res.put(*elim, positive ? cand : !cand);
                                }
                            }
                        }
                    }
                }
            } else if (current->isTheoryLit()) {
                const auto lit {*current->getTheoryLit()};
                if (std::holds_alternative<BoolLit>(lit)) {
                    const auto &bool_lit {std::get<BoolLit>(lit)};
                    const auto var {bool_lit.getBoolVar()};
                    if (var.isTempVar()) {
                        res.put(var, bool_lit.isNegated() ? False : True);
                    }
                }
            }
        }
        return res;
    }

    std::vector<G> dnf() const {
        std::vector<G> res;
        dnf(res);
        return res;
    }

    G conjunctionToGuard() const{
        const LS &lits = this->lits();
        return G(lits.begin(), lits.end());
    }

    BE toG() const {
        return map([](const Lit &lit) {
            if (std::holds_alternative<Rel>(lit)) {
                const Rel &rel = std::get<Rel>(lit);
                if (rel.isEq()) {
                    return buildAnd(std::initializer_list<BE>{
                                        buildTheoryLit(Rel::buildGeq(rel.lhs(), rel.rhs())),
                                        buildTheoryLit(Rel::buildGeq(rel.rhs(), rel.lhs()))
                                    });
                } else if (rel.isNeq()) {
                    return buildOr(std::initializer_list<BE>{
                                       buildTheoryLit(Rel::buildGt(rel.lhs(), rel.rhs())),
                                       buildTheoryLit(Rel::buildGt(rel.rhs(), rel.lhs()))
                                   });
                }
                return buildTheoryLit(rel.toG());
            }
            return buildTheoryLit(lit);
        });
    }

    template <ITheory T>
    BExpr<T> transform() const {
        const std::function<BExpr<T>(const Lit&)> mapper = [](const Lit &lit) {
            if (std::holds_alternative<typename T::Lit>(lit)) {
                return BoolExpression<T>::buildTheoryLit(typename Theory<T>::Lit(std::get<typename T::Lit>(lit)));
            }
            throw std::logic_error("transform failed");
        };
        return map<T>(mapper);
    }

protected:
    virtual void dnf(std::vector<G> &res) const = 0;
};

template <IBaseTheory... Th>
const BExpr<Th...> BoolExpression<Th...>::True = build_cached(BoolExpressionSet<Th...>{}, ConcatAnd);

template <IBaseTheory... Th>
const BExpr<Th...> BoolExpression<Th...>::False = build_cached(BoolExpressionSet<Th...>{}, ConcatOr);

template <ITheory... Th>
class BoolTheoryLit: public BoolExpression<Th...> {

    static_assert(sizeof...(Th) > 0);

    using T = Theory<Th...>;
    using Var = typename T::Var;
    using Lit = typename T::Lit;
    using VS = theory::VarSet<Th...>;
    using LS = theory::LitSet<Th...>;
    using C = Conjunction<Th...>;
    using BE = BExpr<Th...>;
    using BES = BoolExpressionSet<Th...>;
    using Subs = theory::Subs<Th...>;

    Lit lit;

public:

    BoolTheoryLit(const Lit &lit) : lit(literal::normalize<Th...>(lit)) {}

    bool isAnd() const override {
        return false;
    }

    bool isOr() const override {
        return false;
    }

    bool isTheoryLit() const override {
        return true;
    }

    const Lit* getTheoryLit() const override {
        return &lit;
    }

    BES getChildren() const override {
        return {};
    }

    const BE negation() const override {
        return BoolExpression<Th...>::buildTheoryLit(literal::negate<Th...>(lit));
    }

    bool forall(const std::function<bool(const Lit&)> &pred) const override {
        return pred(lit);
    }

    ~BoolTheoryLit() override {}

    bool isConjunction() const override {
        return true;
    }

    LS universallyValidLits() const override {
        LS res;
        res.insert(lit);
        return res;
    }

    void collectLits(LS &res) const override {
        res.insert(lit);
    }

    size_t size() const override {
        return 1;
    }

    void getBounds(const Var &var, Bounds &res) const override {
        if (std::holds_alternative<Rel>(lit)) {
            std::get<Rel>(lit).getBounds(std::get<NumVar>(var), res);
        }
    }

    std::size_t hash() const {
        return std::visit(Overload {
            [](const auto &lit) {
                return lit.hash();
            }
        }, lit);
    }

protected:

    void dnf(std::vector<C> &res) const override {
        if (res.empty()) {
            res.push_back({lit});
        } else {
            for (auto &g: res) {
                g.push_back(lit);
            }
        }
    }

};

template <ITheory... Th>
class BoolJunction: public BoolExpression<Th...> {

    static_assert(sizeof...(Th) > 0);

    using T = Theory<Th...>;
    using Var = typename T::Var;
    using Lit = typename T::Lit;
    using VS = theory::VarSet<Th...>;
    using LS = theory::LitSet<Th...>;
    using C = Conjunction<Th...>;
    using BE = BExpr<Th...>;
    using BES = BoolExpressionSet<Th...>;
    using Subs = theory::Subs<Th...>;

    BE True = BoolExpression<Th...>::True;
    BE False = BoolExpression<Th...>::False;

    BES children;
    ConcatOperator op;

public:

    BoolJunction(const BES &children, ConcatOperator op): children(children), op(op) { }

    bool isAnd() const override {
        return op == ConcatAnd;
    }

    bool isOr() const override {
        return op == ConcatOr;
    }

    bool isTheoryLit() const override {
        return false;
    }

    const Lit* getTheoryLit() const override {
        return nullptr;
    }

    BES getChildren() const override {
        return children;
    }

    const BE negation() const override {
        BES newChildren;
        for (const BE &c: children) {
            newChildren.insert(c->negation());
        }
        switch (op) {
        case ConcatOr: return BoolExpression<Th...>::buildAnd(newChildren);
        case ConcatAnd: return BoolExpression<Th...>::buildOr(newChildren);
        }
        throw std::invalid_argument("unknown junction");
    }

    bool forall(const std::function<bool(const Lit&)> &pred) const override {
        for (const BE &e: children) {
            if (!e->forall(pred)) {
                return false;
            }
        }
        return true;
    }

    ~BoolJunction() override {}

    bool isConjunction() const override {
        return isAnd() && std::all_of(children.begin(), children.end(), [](const BE c){
            return c->isConjunction();
        });
    }

    LS universallyValidLits() const override {
        LS res;
        if (isAnd()) {
            for (const BE &c: children) {
                if (c->isTheoryLit()) {
                    res.insert(*c->getTheoryLit());
                }
            }
        }
        return res;
    }

    void collectLits(LS &res) const override {
        for (const BE &c: children) {
            c->collectLits(res);
        }
    }

    size_t size() const override {
        size_t res = 1;
        for (const BE &c: children) {
            res += c->size();
        }
        return res;
    }

    void getBounds(const Var &n, Bounds &res) const override {
        if (isAnd()) {
            for (const auto &c: children) {
                c->getBounds(n, res);
            }
        } else if (isOr()) {
            bool first = true;
            for (const auto &c: children) {
                if (first) {
                    c->getBounds(n, res);
                    first = false;
                } else {
                    Bounds cres = res;
                    c->getBounds(n, cres);
                    if (res.equality && (!cres.equality || !(*res.equality - *cres.equality).isZero())) {
                        res.equality = {};
                    }
                    if (!res.equality && res.lowerBounds.empty() && res.upperBounds.empty()) {
                        return;
                    }
                }
            }
        }
    }

    std::size_t hash() const {
        std::size_t seed = 0;
        boost::hash_combine(seed, op);
        boost::hash_combine(seed, boost::hash_range(children.begin(), children.end()));
        return seed;
    }

protected:

    void dnf(std::vector<C> &res) const override {
        if (isAnd()) {
            for (const BE &e: children) {
                e->dnf(res);
            }
        } else {
            std::vector<C> oldRes(res);
            res.clear();
            for (const BE &e: children) {
                std::vector<C> newRes(oldRes);
                e->dnf(newRes);
                res.insert(res.end(), newRes.begin(), newRes.end());
            }
        }
    }

};

template <ITheory... Th>
const BExpr<Th...> operator &(const BExpr<Th...> a, const BExpr<Th...> b) {
    const BoolExpressionSet<Th...> children{a, b};
    return BoolExpression<Th...>::buildAnd(children);
}

template <ITheory... Th>
const BExpr<Th...> operator &(const BExpr<Th...> a, const typename Theory<Th...>::Lit &b) {
    return a & BoolExpression<Th...>::buildTheoryLit(b);
}

template <ITheory... Th>
const BExpr<Th...> operator |(const BExpr<Th...> a, const BExpr<Th...> b) {
    const BoolExpressionSet<Th...> children{a, b};
    return BoolExpression<Th...>::buildOr(children);
}

template <ITheory... Th>
const BExpr<Th...> operator |(const BExpr<Th...> a, const typename Theory<Th...>::Lit b) {
    return a | BoolExpression<Th...>::buildTheoryLit(b);
}

template <ITheory... Th>
const BExpr<Th...> operator !(const BExpr<Th...> a) {
    return a->negation();
}

template <ITheory... Th>
std::strong_ordering operator <=>(const BExpr<Th...> a, const BExpr<Th...> b) {
    if (a == b) {
        return std::strong_ordering::equal;
    }
    if (a->isTheoryLit()) {
        if (b->isTheoryLit()) {
            return *a->getTheoryLit() <=> *b->getTheoryLit();
        } else {
            return std::strong_ordering::less;
        }
    }
    if (b->isTheoryLit()) {
        return std::strong_ordering::greater;
    }
    if (a->isAnd() && !b->isAnd()) {
        return std::strong_ordering::greater;
    } else if (!a->isAnd() && b->isAnd()) {
        return std::strong_ordering::less;
    }
    return a->getChildren() <=> b->getChildren();
}

template <ITheory T, ITheory... Th>
std::ostream& operator<<(std::ostream &s, const BExpr<T, Th...> e) {
    if (e->isTheoryLit()) {
        std::visit([&s](const auto lit){s << lit;}, *e->getTheoryLit());
    } else if (e->getChildren().empty()) {
        if (e->isAnd()) {
            s << "T";
        } else {
            s << "_|_";
        }
    } else {
        bool first = true;
        s << "(";
        for (const auto &c: e->getChildren()) {
            if (first) {
                s << c;
                first = false;
            } else {
                if (e->isAnd()) {
                    s << " /\\ ";
                } else {
                    s << " \\/ ";
                }
                s << c;
            }
        }
        s << ")";
    }
    return s;
}
