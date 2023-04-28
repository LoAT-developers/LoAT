#pragma once

#include "itheory.hpp"
#include "thset.hpp"
#include "conjunction.hpp"
#include "rel.hpp"
#include "boollit.hpp"
#include "literaltemplates.hpp"

#include <type_traits>
#include <memory>
#include <set>

template <ITheory... Th>
class BoolTheoryLit;
template <ITheory... Th>
class BoolJunction;
template <IBaseTheory... Th>
class BoolExpression;
template <ITheory... Th>
using BExpr = std::shared_ptr<const BoolExpression<Th...>>;

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
struct BExpr_compare {
    bool operator() (const BExpr<Th...> a, const BExpr<Th...> b) const {
        return a < b;
    }
};

template <ITheory... Th>
using BoolExpressionSet = std::set<BExpr<Th...>, BExpr_compare<Th...>> ;

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

public:

    static const BE True;
    static const BE False;

    template <class Lits>
    static const BE buildFromLits(const Lits &lits, ConcatOperator op) {
        BES children;
        for (const Lit &lit: lits) {
            children.insert(buildTheoryLit(lit));
        }
        return BE(new BoolJunction(children, op));
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
        return BE(new BoolJunction(children, op));
    }

    template <class Lits>
    static const BE buildAndFromLits(const Lits &lits) {
        return buildFromLits(lits, ConcatAnd);
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
        return BE(new BoolTheoryLit<Th...>(lit));
    }

    virtual bool isTheoryLit() const = 0;
    virtual std::optional<const Lit> getTheoryLit() const = 0;
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

    bool isTriviallyTrue() const {
        if (isTheoryLit()) {
            return literal_t::isTriviallyTrue<Th...>(*getTheoryLit());
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

    bool implicant(Subs &subs, LS &res) const {
        if (isOr()) {
            std::optional<LS> best_res;
            for (const auto &c: getChildren()) {
                LS current_res;
                if (c->implicant(subs, current_res)) {
                    if (!best_res) {
                        best_res = current_res;
                    } else if (current_res.size() < best_res->size()) {
                        best_res = current_res;
                    }
                }
            }
            if (best_res) {
                res.insertAll(*best_res);
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
                    res.insert(*lit);
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
    std::optional<LS> implicant(Subs subs) const {
        LS res;
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

    BE map(const std::function<BE(const Lit&)> &f) const {
        if (isAnd()) {
            bool changed = false;
            BoolExpressionSet<Th...> newChildren;
            for (const auto &c: getChildren()) {
                const auto simp = c->map(f);
                changed |= simp.get() != c.get();
                if (simp == BoolExpression<Th...>::False) {
                    return BoolExpression<Th...>::False;
                } else {
                    if (simp != BoolExpression<Th...>::True) {
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
                return this->shared_from_this();
            } else if (newChildren.empty()) {
                return BoolExpression<Th...>::True;
            } else {
                for (const auto &c: newChildren) {
                    if (c->isTheoryLit()) {
                        if (newChildren.find(!c) != newChildren.end()) {
                            return BoolExpression<Th...>::False;
                        }
                    }
                }
                return BoolExpression<Th...>::buildAnd(newChildren);
            }
        } else if (isOr()) {
            BoolExpressionSet<Th...> newChildren;
            bool changed = false;
            for (const auto &c: getChildren()) {
                const auto simp = c->map(f);
                changed |= simp.get() != c.get();
                if (simp == BoolExpression<Th...>::True) {
                    return BoolExpression<Th...>::True;
                } else {
                    if (simp != BoolExpression<Th...>::False) {
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
                return this->shared_from_this();
            } else if (newChildren.empty()) {
              return BoolExpression<Th...>::False;
            } else {
                for (const auto &c: newChildren) {
                    if (c->isTheoryLit()) {
                        if (newChildren.find(!c) != newChildren.end()) {
                            return BoolExpression<Th...>::True;
                        }
                    }
                }
                return BoolExpression<Th...>::buildOr(newChildren);
            }
        } else if (isTheoryLit()) {
            const auto lit = *getTheoryLit();
            const auto mapped = f(lit);
            const auto mappedLit = mapped->getTheoryLit();
            if (mappedLit && *mappedLit == lit) {
                return this->shared_from_this();
            } else {
                return mapped;
            }
        }
        throw std::logic_error("unknown boolean expression");
    }

    BE subs(const Subs &subs) const {
        return map([&subs](const auto &lit) {
            return literal::subs<Th...>(lit, subs);
        });
    }

    void collectVars(VS &vars) const {
        iter([&vars](const auto &lit) {
            literal_t::collectVars<Th...>(lit, vars);
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

    std::optional<BE> impliedEquality(const Lit &l) const {
        std::vector<BE> todo;
        const BE lit = buildTheoryLit(l);
        if (isAnd()) {
            const auto children = getChildren();
            for (const auto &c: children) {
                if (c->isOr()) {
                    auto grandChildren = c->getChildren();
                    const auto it = grandChildren.find(lit);
                    if (it != grandChildren.end()) {
                        grandChildren.erase(it);
                        const BE cand = buildOr(grandChildren);
                        // we have     lit \/  cand
                        // search for !lit \/ !cand
                        if (children.contains((!lit) | (!cand))) {
                            // we have (lit \/ cand) /\ (!lit \/ !cand), i.e., lit <==> !cand
                            return !cand;
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
                const auto children = current->getChildren();
                if (children.size() == 2) {
                    for (const auto &c: children) {
                        if (c->isAnd()) {
                            auto grandChildren = c->getChildren();
                            const auto it = grandChildren.find(lit);
                            if (it != grandChildren.end()) {
                                grandChildren.erase(it);
                                const BE cand = buildAnd(grandChildren);
                                // we have     lit /\  cand
                                // search for !lit /\ !cand
                                if (children.contains((!lit) & (!cand))) {
                                    // we have (lit /\ cand) \/ (!lit /\ !cand), i.e., lit <==> cand
                                    return cand;
                                }
                            }
                        }
                    }
                }
            } else if (current == lit) {
                return True;
            } else if (current == !lit) {
                return False;
            }
        }
        return {};
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

    template<ITheory T>
    unsigned nextVarIdx() const {
        const auto variables {vars().template get<typename T::Var>()};
        return variables.empty() ? 1 : variables.rbegin()->getIdx() + 1;
    }

protected:
    virtual void dnf(std::vector<G> &res) const = 0;
};

template <IBaseTheory... Th>
const BExpr<Th...> BoolExpression<Th...>::True = BE(new BoolJunction(BoolExpressionSet<Th...>{}, ConcatAnd));

template <IBaseTheory... Th>
const BExpr<Th...> BoolExpression<Th...>::False = BE(new BoolJunction(BoolExpressionSet<Th...>{}, ConcatOr));

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

    BoolTheoryLit(const Lit &lit) : lit(literal_t::normalize<Th...>(lit)) {}

    bool isAnd() const override {
        return false;
    }

    bool isOr() const override {
        return false;
    }

    bool isTheoryLit() const override {
        return true;
    }

    std::optional<const Lit> getTheoryLit() const override {
        return {lit};
    }

    BES getChildren() const override {
        return {};
    }

    const BE negation() const override {
        return BoolExpression<Th...>::buildTheoryLit(literal_t::negate<Th...>(lit));
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

    std::optional<const Lit> getTheoryLit() const override {
        return {};
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
bool operator ==(const BExpr<Th...> a, const BExpr<Th...> b) {
    if (a->getTheoryLit() != b->getTheoryLit()) {
        return false;
    }
    if (a->isTheoryLit()) {
        return true;
    }
    if (a->isAnd() != b->isAnd()) {
        return false;
    }
    return a->getChildren() == b->getChildren();
}

template <ITheory... Th>
std::strong_ordering operator <=>(const BExpr<Th...> a, const BExpr<Th...> b) {
    auto res {a->getTheoryLit() <=> b->getTheoryLit()};
    if (std::is_neq(res)) {
        return res;
    }
    if (a->isAnd() && !b->isAnd()) {
        return std::strong_ordering::greater;
    } else if (!a->isAnd() && b->isAnd()) {
        return std::strong_ordering::less;
    }
    return a->getChildren() <=> b->getChildren();
}

template <ITheory... Th>
bool operator !=(const BExpr<Th...> a, const BExpr<Th...> b) {
    return !(a==b);
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
