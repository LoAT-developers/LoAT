#include "subs.hpp"

Subs::It Subs::Iterator::begin(size_t i) const {
    return beginImpl(i);
}

Subs::It Subs::Iterator::end(size_t i) const {
    return endImpl(i);
}

Subs::Pair Subs::Iterator::getCurrent() const {
    return getCurrentImpl<0>();
}

Subs::Iterator::Iterator(const Subs &subs, const It &ptr) : subs(subs), ptr(ptr) {}

Subs::Iterator::reference Subs::Iterator::operator*() {
    current = getCurrent();
    return *current;
}

Subs::Iterator::pointer Subs::Iterator::operator->() {
    current = getCurrent();
    return &(*current);
}

void Subs::Iterator::increment() {
    incrementImpl<0>();
}

// Prefix increment
Subs::Iterator& Subs::Iterator::operator++() {
    increment();
    while (ptr.index() + 1 < num_theories && ptr == end(ptr.index())) {
        ptr = begin(ptr.index() + 1);
    }
    return *this;
}

// Postfix increment
Subs::Iterator Subs::Iterator::operator++(int) {
    Iterator tmp = *this;
    ++(*this);
    return tmp;
}

bool operator==(const Subs::Iterator& a, const Subs::Iterator& b) {
    return a.ptr == b.ptr;
};

Subs::Iterator Subs::end() const {
    return Subs::Iterator(*this, std::get<num_theories - 1>(t).end());
}

template <size_t I = 0>
inline Subs::Iterator beginImpl(const Subs &s) {
    if constexpr (I < num_theories) {
        const auto& x = s.get<I>();
        if (x.empty()) {
            return beginImpl<I+1>(s);
        } else {
            return Subs::Iterator(s, x.begin());
        }
    } else {
        return s.end();
    }
}

Subs::Iterator Subs::begin() const {
    return beginImpl(*this);
}

template<std::size_t I = 0>
inline void projectImpl(const Subs &s, Subs& res, const VarSet &vars) {
    if constexpr (I < num_theories) {
        res.get<I>() = s.get<I>().project(vars.template get<I>());
        projectImpl<I+1>(s, res, vars);
    }
}

Subs Subs::project(const VarSet &vars) const {
    Subs res;
    projectImpl(*this, res, vars);
    return Subs(res);
}

template<std::size_t I = 0>
inline void projectImpl(const Subs &s, Subs& res, const std::function<bool(Var)> &keep) {
    if constexpr (I < num_theories) {
        res.get<I>() = s.get<I>().project([&](const auto &x) {
            return keep(x);
        });
        projectImpl<I+1>(s, res, keep);
    }
}

Subs Subs::project(const std::function<bool(Var)> &keep) const {
    Subs res;
    projectImpl(*this, res, keep);
    return Subs(res);
}

template<std::size_t I = 0>
inline void putImpl(Subs &s, const Subs::Pair &p) {
    if constexpr (I < num_theories) {
        if (p.index() == I) {
            s.get<I>().put(std::get<I>(Subs::first(p)), std::get<I>(Subs::second(p)));
        } else {
            putImpl<I+1>(s, p);
        }
    }
}

void Subs::put(const Pair &p) {
    putImpl(*this, p);
}

template<std::size_t I = 0>
inline void putImpl(Subs &s, const Var &x, const Expr &y) {
    if constexpr (I < num_theories) {
        if (x.index() == I) {
            s.get<I>().put(std::get<I>(x), std::get<I>(y));
        } else {
            putImpl<I+1>(s, x, y);
        }
    }
}

void Subs::put(const Var &x, const Expr &y) {
    putImpl(*this, x, y);
}

Subs::Subs(){}

Subs::Subs(Pair &p) {
    put(p);
}

template<std::size_t I = 0>
inline void domainImpl(const Subs &s, VarSet &res) {
    if constexpr (I < num_theories) {
        res.template get<I>() = s.get<I>().domain();
        domainImpl<I+1>(s, res);
    }
}

VarSet Subs::domain() const {
    VarSet res;
    domainImpl(*this, res);
    return res;
}

template<std::size_t I = 0>
inline Expr getImpl(const Subs &s, const Var &var) {
    if constexpr (I >= num_theories) {
        throw std::invalid_argument("variable not found");
    } else if (var.index() == I) {
        return s.get<I>().get(std::get<I>(var));
    } else {
        return getImpl<I+1>(s, var);
    }
}

Expr Subs::get(const Var &var) const {
    return getImpl(*this, var);
}

template<std::size_t I = 0>
inline void uniteImpl(const Subs &fst, const Subs &snd, Subs &res) {
    if constexpr (I < num_theories) {
        res.get<I>() = fst.get<I>().unite(snd.get<I>());
        uniteImpl<I+1>(fst, snd, res);
    }
}

Subs Subs::unite(const Subs &that) const {
    Subs res;
    uniteImpl(*this, that, res);
    return res;
}

template<std::size_t I = 0>
inline bool changesImpl(const Subs &s, const Var &x) {
    if constexpr (I < num_theories) {
        if (x.index() == I) {
            return s.get<I>().changes(std::get<I>(x));
        } else {
            return changesImpl<I+1>(s, x);
        }
    } else {
        return false;
    }
}

bool Subs::changes(const Var &x) const {
    return changesImpl(*this, x);
}

template<std::size_t I = 0>
inline void eraseImpl(Subs &subs, const Var &x) {
    if constexpr (I < num_theories) {
        if (x.index() == I) {
            subs.get<I>().erase(std::get<I>(x));
        } else {
            eraseImpl<I+1>(subs, x);
        }
    }
}

void Subs::erase(const Var &x) {
    eraseImpl(*this, x);
}

template<std::size_t I = 0>
inline void eraseImpl(Subs &subs, const VarSet &xs) {
    if constexpr (I < num_theories) {
        auto &s = subs.get<I>();
        for (const auto &x: xs.template get<I>()) {
            s.erase(x);
        }
        eraseImpl<I+1>(subs, xs);
    }
}

void Subs::erase(const VarSet &xs) {
    eraseImpl(*this, xs);
}

template<std::size_t I = 0>
inline void printImpl(const Subs &subs, std::ostream &s, bool first = true) {
    if constexpr (I < num_theories) {
        const auto &m {subs.get<I>()};
        if (!m.empty()) {
            if (first) {
                first = false;
            } else {
                s << " u ";
            }
            s << m;
        }
        if constexpr (I + 1 < num_theories) {
            printImpl<I+1>(subs, s, first);
        }
    }
}

void Subs::print(std::ostream &s) const {
    printImpl(*this, s);
}

size_t Subs::hash() const {
    return boost::hash_value(t);
}

template<std::size_t I = 0>
inline bool containsImpl(const Subs &s, const Var &var) {
    if constexpr (I < num_theories) {
        if (var.index() == I) {
            const auto &subs = s.get<I>();
            return subs.contains(std::get<I>(var));
        } else {
            return containsImpl<I+1>(s, var);
        }
    } else {
        return false;
    }
}

bool Subs::contains(const Var &var) const {
    return containsImpl(*this, var);
}

size_t Subs::size() const {
    return std::apply([](const auto&... x){return (0 + ... + x.size());}, t);
}

bool Subs::empty() const {
    return std::apply([](const auto&... x){return (true && ... && x.empty());}, t);
}

bool Subs::isLinear() const {
    return std::apply([](const auto&... x){return (true && ... && x.isLinear());}, t);
}

bool Subs::isPoly() const {
    return std::apply([](const auto&... x){return (true && ... && x.isPoly());}, t);
}

template<std::size_t I = 0>
inline Bools::Expr subsImpl(const Subs &s, const Lit &lit) {
    if constexpr (I < num_theories) {
        if (lit.index() == I) {
            using T = typename std::tuple_element_t<I, Theories>;
            if constexpr (std::same_as<T, Bools>) {
                return s.template get<T>().subs(std::get<I>(lit));
            } else {
                return bools::mkLit(std::get<I>(lit)->subs(s.template get<T>()));
            }
        } else {
            return subsImpl<I+1>(s, lit);
        }
    } else {
        throw std::logic_error("unknown theory");
    }
}

Bools::Expr Subs::operator()(const Lit &lit) const {
    return subsImpl<0>(*this, lit);
}

Bools::Expr Subs::operator()(const Bools::Expr e) const {
    return e->map([&](const auto &lit) {
        return (*this)(lit);
    });
}

Expr Subs::operator()(const Expr &expr) const {
    return std::visit(
        Overload{
            [&](const Arith::Expr expr) {
                return Expr{get<Arith>()(expr)};
            },
            [&](const Bools::Expr expr) {
                return Expr{(*this)(expr)};
            }
        }, expr);
}

/**
 * that.concat(this)
 */
BoolSubs Subs::tac(const BoolSubs &that) const {
    BoolSubs res;
    for (const auto &p: that) {
        res.put(p.first, (*this)(p.second));
    }
    return res;
}

template<std::size_t I = 0>
inline void concatImpl(const Subs &fst, const Subs &snd, Subs &res) {
    if constexpr (I < num_theories) {
        if constexpr (std::same_as<std::tuple_element_t<I, Theories>, Bools>) {
            res.get<I>() = snd.tac(fst.get<I>());
        } else {
            res.get<I>() = fst.get<I>().concat(snd.get<I>());
        }
        concatImpl<I+1>(fst, snd, res);
    }
}

Subs Subs::concat(const Subs &that) const {
    Subs res;
    concatImpl(*this, that, res);
    return res;
}

template<std::size_t I = 0>
inline void composeImpl(const Subs &fst, const Subs &snd, Subs &res) {
    if constexpr (I < num_theories) {
        if constexpr (std::same_as<std::tuple_element_t<I, Theories>, Bools>) {
            res.get<I>() = snd.tac(fst.get<I>()).unite(snd.get<I>());
        } else {
            res.get<I>() = fst.get<I>().compose(snd.get<I>());
        }
        composeImpl<I+1>(fst, snd, res);
    }
}

Subs Subs::compose(const Subs &that) const {
    Subs res;
    composeImpl(*this, that, res);
    return res;
}

template<std::size_t I = 0>
inline void collectDomainImpl(const Subs &subs, VarSet &res) {
    if constexpr (I < num_theories) {
        subs.get<I>().collectDomain(res.get<I>());
        collectDomainImpl<I+1>(subs, res);
    }
}

void Subs::collectDomain(VarSet &res) const {
    collectDomainImpl<0>(*this, res);
}

template<std::size_t I = 0>
inline void collectCoDomainVarsImpl(const Subs &subs, VarSet &res) {
    if constexpr (I < num_theories) {
        if constexpr (theory::is<I, Bools>()) {
            subs.get<I>().collectCoDomainVars(res);
        } else {
            subs.get<I>().collectCoDomainVars(res.get<I>());
        }
        collectCoDomainVarsImpl<I+1>(subs, res);
    }
}

void Subs::collectCoDomainVars(VarSet &res) const {
    collectCoDomainVarsImpl<0>(*this, res);
}

VarSet Subs::coDomainVars() const {
    VarSet res;
    collectCoDomainVars(res);
    return res;
}

VarSet Subs::vars() const {
    VarSet res;
    collectVars(res);
    return res;
}

void Subs::collectVars(VarSet &vars) const {
    for (const auto &[x,y]: *this) {
        vars.insert(x);
        theory::collectVars(y, vars);
    }
}

Subs Subs::Empty {};

Var Subs::first(const Pair &p) {
    return std::visit(
        [](const auto &p){
            return Var(p.first);
        }, p);
}

Expr Subs::second(const Pair &p) {
    return std::visit(
        [](const auto &p) {
            return Expr(p.second);
        }, p);
}

std::ostream& operator<<(std::ostream &s, const Subs &subs) {
    subs.print(s);
    return s;
}

Var Subs::renameVar(const Var &x, Subs &sigma, Subs &inverted) {
    return theory::apply(x, [&sigma, &inverted](const auto &x) {
        const auto th {theory::theory(x)};
        const auto next {th.next()};
        sigma.put<decltype(th)>(x, th.varToExpr(next));
        inverted.put<decltype(th)>(next, th.varToExpr(x));
        return Var(next);
    });
}
