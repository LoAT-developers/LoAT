#include "renaming.hpp"

Renaming::It Renaming::Iterator::begin(size_t i) const {
    return beginImpl(i);
}

Renaming::It Renaming::Iterator::end(size_t i) const {
    return endImpl(i);
}

Renaming::Pair Renaming::Iterator::getCurrent() const {
    return getCurrentImpl<0>();
}

Renaming::Iterator::Iterator(const Renaming &subs, const It &ptr) : subs(subs), ptr(ptr) {}

Renaming::Iterator::reference Renaming::Iterator::operator*() {
    current = getCurrent();
    return *current;
}

Renaming::Iterator::pointer Renaming::Iterator::operator->() {
    current = getCurrent();
    return &(*current);
}

void Renaming::Iterator::increment() {
    incrementImpl<0>();
}

// Prefix increment
Renaming::Iterator& Renaming::Iterator::operator++() {
    increment();
    while (ptr.index() + 1 < num_theories && ptr == end(ptr.index())) {
        ptr = begin(ptr.index() + 1);
    }
    return *this;
}

// Postfix increment
Renaming::Iterator Renaming::Iterator::operator++(int) {
    Iterator tmp = *this;
    ++(*this);
    return tmp;
}

bool operator==(const Renaming::Iterator& a, const Renaming::Iterator& b) {
    return a.ptr == b.ptr;
};

Renaming::Iterator Renaming::end() const {
    return Renaming::Iterator(*this, std::get<num_theories - 1>(t).left.end());
}

template <size_t I = 0>
inline Renaming::Iterator beginImpl(const Renaming &s) {
    if constexpr (I < num_theories) {
        const auto& x = s.get<I>();
        if (x.empty()) {
            return beginImpl<I+1>(s);
        } else {
            return Renaming::Iterator(s, x.left.begin());
        }
    } else {
        return s.end();
    }
}

Renaming::Iterator Renaming::begin() const {
    return beginImpl(*this);
}

template<std::size_t I = 0>
inline void insertImpl(Renaming &s, const Renaming::Pair &p) {
    if constexpr (I < num_theories) {
        if (p.index() == I) {
            using value_t = typename std::tuple_element_t<I, Theories>::Renaming::left_value_type;
            s.get<I>().left.insert(value_t(std::get<I>(Renaming::first(p)), std::get<I>(Renaming::second(p))));
        } else {
            insertImpl<I+1>(s, p);
        }
    }
}

void Renaming::insert(const Pair &p) {
    insertImpl(*this, p);
}

template<std::size_t I = 0>
inline void insertImpl(Renaming &s, const Var &x, const Var &y) {
    if constexpr (I < num_theories) {
        if (x.index() == I) {
            using value_t = typename std::tuple_element_t<I, Theories>::Renaming::left_value_type;
            s.get<I>().left.insert(value_t(std::get<I>(x), std::get<I>(y)));
        } else {
            insertImpl<I+1>(s, x, y);
        }
    }
}

void Renaming::insert(const Var &x, const Var &y) {
    insertImpl(*this, x, y);
}

Renaming::Renaming(){}

Renaming::Renaming(Pair &p) {
    insert(p);
}

template<std::size_t I = 0>
inline Var getImpl(const Renaming &s, const Var &var) {
    if constexpr (I >= num_theories) {
        throw std::invalid_argument("variable not found");
    } else if (var.index() == I) {
        const auto &map {s.get<I>().left};
        const auto it {map.find(std::get<I>(var))};
        return it == map.end() ? var : it->second;
    } else {
        return getImpl<I+1>(s, var);
    }
}

Var Renaming::get(const Var &var) const {
    return getImpl(*this, var);
}

template<std::size_t I = 0>
inline void uniteImpl(const Renaming &fst, const Renaming &snd, Renaming &res) {
    if constexpr (I < num_theories) {
        auto &r {res.get<I>()};
        r = fst.get<I>();
        const auto &s {snd.get<I>()};
        r.insert(s.begin(), s.end());
        uniteImpl<I+1>(fst, snd, res);
    }
}

Renaming Renaming::unite(const Renaming &that) const {
    Renaming res;
    uniteImpl(*this, that, res);
    return res;
}

template<std::size_t I = 0>
inline bool changesImpl(const Renaming &s, const Var &x) {
    if constexpr (I < num_theories) {
        if (x.index() == I) {
            const auto &map {s.get<I>().left};
            const auto it {map.find(std::get<I>(x))};
            return it != map.end() && it->first != it->second;
        } else {
            return changesImpl<I+1>(s, x);
        }
    } else {
        return false;
    }
}

bool Renaming::changes(const Var &x) const {
    return changesImpl(*this, x);
}

template<std::size_t I = 0>
inline void eraseImpl(Renaming &subs, const Var &x) {
    if constexpr (I < num_theories) {
        if (x.index() == I) {
            subs.get<I>().left.erase(std::get<I>(x));
        } else {
            eraseImpl<I+1>(subs, x);
        }
    }
}

void Renaming::erase(const Var &x) {
    eraseImpl(*this, x);
}

template<std::size_t I = 0>
inline void eraseImpl(Renaming &subs, const VarSet &xs) {
    if constexpr (I < num_theories) {
        auto &s = subs.get<I>();
        for (const auto &x: xs.template get<I>()) {
            s.left.erase(x);
        }
        eraseImpl<I+1>(subs, xs);
    }
}

void Renaming::erase(const VarSet &xs) {
    eraseImpl(*this, xs);
}

template<std::size_t I = 0>
inline void printImpl(const Renaming &subs, std::ostream &s, bool first = true) {
    if constexpr (I < num_theories) {
        const auto &m {subs.get<I>()};
        if (!m.empty()) {
            if (first) {
                first = false;
            } else {
                s << " u ";
            }
            auto inner_first {true};
            for (const auto &[l,r]: m.left) {
                if (!inner_first) {
                    s << ", ";
                }
                inner_first = false;
                s << l << "=" << r;
            }
        }
        if constexpr (I + 1 < num_theories) {
            printImpl<I+1>(subs, s, first);
        }
    }
}

void Renaming::print(std::ostream &s) const {
    printImpl(*this, s);
}

size_t Renaming::hash() const {
    return boost::hash_value(t);
}

template<std::size_t I = 0>
inline bool containsImpl(const Renaming &s, const Var &var) {
    if constexpr (I < num_theories) {
        if (var.index() == I) {
            const auto &subs = s.get<I>();
            return subs.left.find(std::get<I>(var)) != subs.left.end();
        } else {
            return containsImpl<I+1>(s, var);
        }
    } else {
        return false;
    }
}

bool Renaming::contains(const Var &var) const {
    return containsImpl(*this, var);
}

size_t Renaming::size() const {
    return std::apply([](const auto&... x){return (0 + ... + x.size());}, t);
}

bool Renaming::empty() const {
    return std::apply([](const auto&... x){return (true && ... && x.empty());}, t);
}

template<std::size_t I = 0>
inline Lit renameVarsImpl(const Renaming &s, const Lit &lit) {
    if constexpr (I < num_theories) {
        if (lit.index() == I) {
            return Lit(std::get<I>(lit)->renameVars(s.template get<I>()));
        } else {
            return renameVarsImpl<I+1>(s, lit);
        }
    } else {
        throw std::logic_error("unknown theory");
    }
}

Lit Renaming::operator()(const Lit &lit) const {
    return renameVarsImpl<0>(*this, lit);
}

Expr Renaming::operator()(const Expr &expr) const {
    return std::visit(
        Overload{
            [&](const Arith::Expr expr) {
                return Expr(expr->renameVars(get<Arith>()));
            },
            [&](const Bools::Expr expr) {
                return Expr{(*this)(expr)};
            }
        }, expr);
}

Bools::Expr Renaming::operator()(const Bools::Expr e) const {
    if (const auto lit {e->getTheoryLit()}) {
        return bools::mkLit((*this)(*lit));
    }
    BoolExprSet children;
    for (const auto &c: e->getChildren()) {
        children.insert((*this)(c));
    }
    const auto op = e->isAnd() ? ConcatAnd : ConcatOr;
    return BoolExpr::from_cache(children, op);
}

template<std::size_t I = 0>
inline void collectCoDomainVarsImpl(const Renaming &subs, VarSet &res) {
    if constexpr (I < num_theories) {
        for (const auto &[_,v]: subs.get<I>()) {
            res.insert(v);
        }
        collectCoDomainVarsImpl<I+1>(subs, res);
    }
}

VarSet Renaming::coDomainVars() const {
    VarSet res;
    collectCoDomainVars(res);
    return res;
}

void Renaming::collectCoDomainVars(VarSet &res) const {
    collectCoDomainVarsImpl<0>(*this, res);
}

template<std::size_t I = 0>
inline void composeImpl(const Renaming &fst, const Renaming &snd, Renaming &res) {
    if constexpr (I < num_theories) {
        using value_t = typename std::tuple_element_t<I, Theories>::Renaming::value_type;
        auto &r {res.get<I>()};
        const auto &f {fst.get<I>()};
        const auto &s {snd.get<I>()};
        for (const auto &[k,v]: f) {
            const auto it {s.left.find(v)};
            if (it == s.left.end()) {
                r.insert(value_t(k, v));
            } else {
                r.insert(value_t(k, it->second));
            }
        }
        for (const auto &[k,v]: s) {
            if (r.left.find(k) == r.left.end()) {
                r.insert(value_t(k, v));
            }
        }
        composeImpl<I+1>(fst, snd, res);
    }
}

Renaming Renaming::compose(const Renaming &that) const {
    Renaming res;
    composeImpl(*this, that, res);
    return res;
}

template<std::size_t I = 0>
inline void projectImpl(const Renaming &s, Renaming& res, const VarSet &vars) {
    if constexpr (I < num_theories) {
        using value_t = typename std::tuple_element_t<I, Theories>::Renaming::value_type;
        auto &map {res.get<I>()};
        for (const auto &[k,v]: s.get<I>()) {
            if (vars.contains(k)) {
                map.insert(value_t(k, v));
            }
        }
        projectImpl<I+1>(s, res, vars);
    }
}

Renaming Renaming::project(const VarSet &vars) const {
    Renaming res;
    projectImpl(*this, res, vars);
    return res;
}

template<std::size_t I = 0>
inline void invertImpl(const Renaming &s, Renaming& res) {
    if constexpr (I < num_theories) {
        using Th = std::tuple_element_t<I, Theories>;
        auto &map {res.get<I>()};
        for (const auto &[x,y]: s.get<I>()) {
            map.insert(typename Th::Renaming::value_type(y, x));
        }
        invertImpl<I+1>(s, res);
    }
}

Renaming Renaming::invert() const {
    Renaming res;
    invertImpl(*this, res);
    return res;
}

Renaming Renaming::Empty {};

Var Renaming::first(const Pair &p) {
    return theory::apply(p, [](const auto &p) {
        return Var(p.first);
    });
}

Var Renaming::second(const Pair &p) {
    return theory::apply(p, [](const auto &p) {
        return Var(p.second);
    });
}

std::ostream& operator<<(std::ostream &s, const Renaming &subs) {
    subs.print(s);
    return s;
}

Var Renaming::renameVar(const Var &x, Renaming &sigma) {
    return theory::apply(x, [&](const auto &x) {
        const auto th {theory::theory(x)};
        const auto next {th.next()};
        sigma.insert<decltype(th)>(x, next);
        return Var(next);
    });
}
