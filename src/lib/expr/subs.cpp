#include "subs.hpp"

Subs::It Subs::Iterator::begin(const size_t i) const {
    return beginImpl(i);
}

Subs::It Subs::Iterator::end(const size_t i) const {
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
    return &*current;
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
    ++*this;
    return tmp;
}

bool operator==(const Subs::Iterator& a, const Subs::Iterator& b) {
    return a.ptr == b.ptr;
}

Subs::Iterator Subs::end() const {
    return {*this, std::get<num_theories - 1>(t).end()};
}

template <size_t I = 0>
Subs::Iterator beginImpl(const Subs &s) {
    if constexpr (I < num_theories) {
        const auto& x = s.get<I>();
        if (x.empty()) {
            return beginImpl<I+1>(s);
        }
        return Subs::Iterator(s, x.begin());
    } else {
        return s.end();
    }
}

Subs::Iterator Subs::begin() const {
    return beginImpl(*this);
}

template<std::size_t I = 0>
void projectImpl(const Subs &s, Subs& res, const VarSet &vars) {
    if constexpr (I < num_theories) {
        res.get<I>() = s.get<I>().project(vars.get<I>());
        projectImpl<I+1>(s, res, vars);
    }
}

Subs Subs::project(const VarSet &vars) const {
    Subs res;
    projectImpl(*this, res, vars);
    return res;
}

template<std::size_t I = 0>
void projectImpl(const Subs &s, Subs& res, const std::function<bool(Var)> &keep) {
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
    return {res};
}

template<std::size_t I = 0>
void putImpl(Subs &s, const Subs::Pair &p) {
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
void putImpl(Subs &s, const Var &x, const Expr &y) {
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

Subs::Subs(const Pair &p) {
    put(p);
}

Subs::Subs(const Renaming& r) {
    for (const auto &p: r) {
        theory::apply(p, [&](const auto &p) {
            using Th = decltype(theory::theory(p.first));
            put(p.first, Th::varToExpr(p.second));
        });
    }
}

template<std::size_t I = 0>
void domainImpl(const Subs &s, VarSet &res) {
    if constexpr (I < num_theories) {
        res.get<I>() = s.get<I>().domain();
        domainImpl<I+1>(s, res);
    }
}

VarSet Subs::domain() const {
    VarSet res;
    domainImpl(*this, res);
    return res;
}

template<std::size_t I = 0>
Expr getImpl(const Subs &s, const Var &var) {
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
bool changesImpl(const Subs &s, const Var &x) {
    if constexpr (I < num_theories) {
        if (x.index() == I) {
            return s.get<I>().changes(std::get<I>(x));
        }
        return changesImpl<I+1>(s, x);
    } else {
        return false;
    }
}

bool Subs::changes(const Var &x) const {
    return changesImpl(*this, x);
}

template<std::size_t I = 0>
void eraseImpl(Subs &subs, const Var &x) {
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
void eraseImpl(Subs &subs, const VarSet &xs) {
    if constexpr (I < num_theories) {
        auto &s = subs.get<I>();
        for (const auto &x: xs.get<I>()) {
            s.erase(x);
        }
        eraseImpl<I+1>(subs, xs);
    }
}

void Subs::erase(const VarSet &xs) {
    eraseImpl(*this, xs);
}

template<std::size_t I = 0>
void printImpl(const Subs &subs, std::ostream &s, bool first = true) {
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
bool containsImpl(const Subs &s, const Var &var) {
    if constexpr (I < num_theories) {
        if (var.index() == I) {
            const auto &subs = s.get<I>();
            return subs.contains(std::get<I>(var));
        }
        return containsImpl<I+1>(s, var);
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

bool Subs::isIdempotent() const {
    return theory::all_of(t, [&](const auto& subs) {
        return std::ranges::all_of(subs, [&](const auto& p) {
            return Expr(p.second) == Expr((*this)(p.second));
        });
    });
}

template<std::size_t I = 0, std::size_t J = 0>
Lit subsImpl(const Subs &s, const Lit &lit) {
    if constexpr (I < num_theories - 1) {
        if (lit.index() == I) {
            if constexpr (J <= I) {
                // theory of the literal
                using T1 = std::tuple_element_t<I, Theories>;
                // some other theory
                using T2 = std::tuple_element_t<J, Theories>;
                if constexpr (depends_on<T1, T2>::value) {
                    return subsImpl<I, J + 1>(s, Lit(std::get<I>(lit)->subs(s.get<T2>())));
                } else {
                    return subsImpl<I, J + 1>(s, lit);
                }
            } else {
                return lit;
            }
        }
        return subsImpl<I + 1, J>(s, lit);
    } else {
        throw std::logic_error("unknown theory");
    }
}

Bools::Expr Subs::operator()(const Lit &lit) const {
    if (std::holds_alternative<Bools::Lit>(lit)) {
        return this->get<Bools>().subs(std::get<Bools::Lit>(lit));
    }
    return bools::mkLit(subsImpl<0, 0>(*this, lit));
}

Bools::Expr Subs::operator()(const Bools::Expr& e) const {
    return e->map([&](const auto &lit) {
        return (*this)(lit);
    });
}

Expr Subs::operator()(const Expr &expr) const {
    return std::visit(
        Overload{
            [&](const Arith::Expr& expr) {
                return Expr{expr->subs(get<Arith>())};
            },
            [&](const auto& expr) {
                return Expr{(*this)(expr)};
            }
        }, expr);
}

Subs Subs::concat(const ArithSubs &that) const {
    Subs res;
    theory::iter(t, [&]<typename T>(const T& t) {
        std::get<T>(res.t) = t.concat(that);
    });
    return res;
}

Subs Subs::concat(const BoolSubs &that) const {
    Subs res {*this};
    auto& b {std::get<Bools::Subs>(res.t)};
    b = b.concat(that);
    return res;
}

BoolSubs concat(const BoolSubs &fst, const Renaming &snd) {
    BoolSubs res;
    for (const auto &[k,v]: fst) {
        res.put(k, snd(v));
    }
    return res;
}

Subs Subs::concat(const Renaming &that) const {
    Subs res;
    theory::iter(
        t,
        [&](const ArithSubs& t) {
            std::get<ArithSubs>(res.t) = t.concat(that.get<Arith>());
        },
        [&](const ArraySubs<Arith>& t) {
            std::get<ArraySubs<Arith>>(res.t) = t.concat(that.get<Arrays<Arith>>()).concat(that.get<Arith>());
        },
        [&](const BoolSubs& t) {
            std::get<BoolSubs>(res.t) = ::concat(t, that);
        });
    return res;
}

Subs Subs::compose(const Subs &that) const {
    Subs res;
    theory::iter(
        t,
        [&](const ArithSubs& t) {
            std::get<ArithSubs>(res.t) = t.compose(that.get<Arith>());
        },
        [&](const ArraySubs<Arith>& t) {
            std::get<ArraySubs<Arith>>(res.t) = t.concat(that.get<Arith>()).compose(that.get<Arrays<Arith>>());
        },
        [&](const BoolSubs& t) {
            std::get<BoolSubs>(res.t) = t.concat(that).unite(that.get<Bools>());
        });
    return res;
}

void Subs::collectCoDomainVars(VarSet& res) const {
    theory::iter(
        t,
        [&](const ArithSubs& t) {
            t.collectCoDomainVars(res.get<Arith::Var>());
        },
        [&](const Arrays<Arith>::Subs& t) {
            auto& arith{res.get<Arith::Var>()};
            t.collectCoDomainVars(res.get<Arrays<Arith>::Var>(), arith, arith);
        },
        [&](const BoolSubs& t) {
            t.collectCoDomainVars(res);
        }
    );
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
    return theory::apply(p, [](const auto &p) {
        return Var(p.first);
    });
}

Expr Subs::second(const Pair &p) {
    return theory::apply(p, [](const auto &p) {
        return Expr(p.second);
    });
}

std::ostream& operator<<(std::ostream &s, const Subs &subs) {
    subs.print(s);
    return s;
}
