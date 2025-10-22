#include "renaming.hpp"

Renaming::It Renaming::Iterator::begin(const size_t i) const {
    return beginImpl(i);
}

Renaming::It Renaming::Iterator::end(const size_t i) const {
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
    return &*current;
}

void Renaming::Iterator::increment() {
    incrementImpl<0>();
}

// Prefix increment
Renaming::Iterator& Renaming::Iterator::operator++() {
    increment();
    while (ptr.index() + 1 < variants && ptr == end(ptr.index())) {
        ptr = begin(ptr.index() + 1);
    }
    return *this;
}

// Postfix increment
Renaming::Iterator Renaming::Iterator::operator++(int) {
    Iterator tmp = *this;
    ++*this;
    return tmp;
}

bool operator==(const Renaming::Iterator& a, const Renaming::Iterator& b) {
    return a.ptr == b.ptr;
}

Renaming::Iterator Renaming::end() const {
    return {*this, std::get<variants - 1>(t).left.end()};
}

template <size_t I = 0>
Renaming::Iterator beginImpl(const Renaming &s) {
    if constexpr (I < Renaming::variants) {
        const auto& x = s.get<I>();
        if (x.empty()) {
            return beginImpl<I+1>(s);
        }
        return Renaming::Iterator(s, x.left.begin());
    } else {
        return s.end();
    }
}

Renaming::Iterator Renaming::begin() const {
    return beginImpl(*this);
}

void Renaming::insert(const Pair &p) {
    theory::apply(
        p,
        [&](const auto& p) {
            using T = decltype(theory::theory(p.first));
            using value_t = T::Renaming::left_value_type;
            std::get<typename T::Renaming>(t).left.insert(value_t(p.first, p.second));
        });
}

void Renaming::insert(const Bools::Var& x, const Bools::Var& y) {
    std::get<Bools::Renaming>(t).insert(Bools::Renaming::value_type(x, y));
}

void Renaming::insert(const Arrays<Arith>::Var& x, const Arrays<Arith>::Var& y) {
    std::get<Arrays<Arith>::Renaming>(t).insert(Arrays<Arith>::Renaming::value_type(x, y));
}

Renaming::Renaming(const Pair &p) {
    insert(p);
}

template<std::size_t I = 0>
void uniteImpl(const Renaming &fst, const Renaming &snd, Renaming &res) {
    if constexpr (I < Renaming::variants) {
        auto &r {res.get<I>()};
        r = fst.get<I>();
        const auto &s {snd.get<I>()};
        r.insert(s.begin(), s.end());
        uniteImpl<I+1>(fst, snd, res);
    }
}

Bools::Var Renaming::get(const Bools::Var& x) const {
    const auto& map {get<Bools>()};
    const auto it {map.left.find(x)};
    return it == map.left.end() ? x : it->second;
}

Arrays<Arith>::Var Renaming::get(const Arrays<Arith>::Var& x) const {
    const auto& map {get<Arrays<Arith>>()};
    const auto it {map.left.find(x)};
    return it == map.left.end() ? x : it->second;
}

Renaming Renaming::unite(const Renaming &that) const {
    Renaming res;
    uniteImpl(*this, that, res);
    return res;
}

template<std::size_t I = 0>
bool changesImpl(const Renaming &s, const Var &x) {
    if constexpr (I < Renaming::variants) {
        if (x.index() == I) {
            const auto &map {s.get<I>().left};
            const auto it {map.find(std::get<I>(x))};
            return it != map.end() && it->first != it->second;
        }
        return changesImpl<I+1>(s, x);
    } else {
        return false;
    }
}

bool Renaming::changes(const Var &x) const {
    return changesImpl(*this, x);
}

template<std::size_t I = 0>
void eraseImpl(Renaming &subs, const Var &x) {
    if constexpr (I < Renaming::variants) {
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
void eraseImpl(Renaming &subs, const VarSet &xs) {
    if constexpr (I < Renaming::variants) {
        auto &s = subs.get<I>();
        for (const auto &x: xs.get<I>()) {
            s.left.erase(x);
        }
        eraseImpl<I+1>(subs, xs);
    }
}

void Renaming::erase(const VarSet &xs) {
    eraseImpl(*this, xs);
}

template<std::size_t I = 0>
void printImpl(const Renaming &subs, std::ostream &s, bool first = true) {
    if constexpr (I < Renaming::variants) {
        if (const auto &m {subs.get<I>()}; !m.empty()) {
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
        if constexpr (I + 1 < Renaming::variants) {
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
bool containsImpl(const Renaming &s, const Var &var) {
    if constexpr (I < Renaming::variants) {
        if (var.index() == I) {
            const auto &subs = s.get<I>();
            return subs.left.find(std::get<I>(var)) != subs.left.end();
        }
        return containsImpl<I+1>(s, var);
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

Lit Renaming::operator()(const Lit& lit) const {
    return theory::apply(
        lit,
        [&](const Bools::Lit& lit) -> Lit {
            return lit->renameVars(get<Bools>());
        },
        [&](const auto& lit) -> Lit {
            return lit->renameVars(get<Arrays<Arith>>());
        });
}

Expr Renaming::operator()(const Expr& expr) const {
    return theory::apply(
        expr,
        [&](const Bools::Expr& expr) -> Expr {
            return expr->renameVars(*this);
        },
        [&](const auto& expr) -> Expr {
            return expr->renameVars(get<Arrays<Arith>>());
        });
}

template<std::size_t I = 0>
void collectCoDomainVarsImpl(const Renaming &subs, VarSet &res) {
    if constexpr (I < Renaming::variants) {
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


Renaming Renaming::compose(const Renaming& that) const {
    Renaming res;
    theory::iter(
        t,
        [&]<typename T>(const T& f) {
            using value_t = T::value_type;
            auto& r{std::get<T>(res.t)};
            const auto& s{std::get<T>(that.t)};
            for (const auto& [k,v] : f) {
                const auto it{s.left.find(v)};
                if (it == s.left.end()) {
                    r.insert(value_t(k, v));
                }
                else {
                    r.insert(value_t(k, it->second));
                }
            }
            for (const auto& [k,v] : s) {
                if (r.left.find(k) == r.left.end()) {
                    r.insert(value_t(k, v));
                }
            }
        });
    return res;
}

Renaming Renaming::project(const VarSet& vars) const {
    Renaming res;
    theory::iter(
        t,
        [&]<class T>(const T& s) {
            using value_t = T::value_type;
            auto& map{std::get<T>(res.t)};
            for (const auto& [k,v] : s) {
                if (vars.contains(k)) {
                    map.insert(value_t(k, v));
                }
            }
        });
    return res;
}

Renaming Renaming::invert() const {
    Renaming res;
    theory::iter(
        t,
        [&]<class T>(const T& s) {
            using value_t = T::value_type;
            auto& map{std::get<T>(res.t)};
            for (const auto& [x,y] : s) {
                map.insert(value_t(y, x));
            }
        });
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

Bools::Var Renaming::renameVar(const Bools::Var& x, Renaming& sigma) {
    const auto next{BoolVar::next()};
    sigma.insert(x, next);
    return next;
}

Arrays<Arith>::Var Renaming::renameVar(const Arrays<Arith>::Var& x, Renaming& sigma) {
    const auto next{ArrayVar<Arith>::next(x->dim())};
    sigma.insert(x, next);
    return next;
}
