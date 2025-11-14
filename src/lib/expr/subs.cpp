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
    while (ptr.index() + 1 < variants && ptr == end(ptr.index())) {
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
    return {*this, std::get<variants - 1>(t).end()};
}

template <size_t I = 0>
Subs::Iterator beginImpl(const Subs &s) {
    if constexpr (I < Subs::variants) {
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
    if constexpr (I < Subs::variants) {
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
    if constexpr (I < Subs::variants) {
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
    if constexpr (I < Subs::variants) {
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

void Subs::put(const Bools::Var& var, const Bools::Expr& expr) {
    std::get<Bools::Subs>(t).put(var, expr);
}

void Subs::put(const Arrays<Arith>::Var& var, const Arrays<Arith>::Expr& expr) {
    std::get<Arrays<Arith>::Subs>(t).put(var, expr);
}

void Subs::writeConst(const Arrays<Arith>::Var& var, const Arith::Expr& expr) {
    put(var, arrays::writeConst(expr));
}

void Subs::update(const ArrayReadPtr<Arith>& read, const Arith::Expr& expr) {
    put(read->var(), arrays::update(read, expr));
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

Subs Subs::build(const Bools::Var& var, const Bools::Expr& expr) {
    Subs subs;
    subs.put(var, expr);
    return subs;
}

Subs Subs::build(const Arrays<Arith>::Var& var, const Arrays<Arith>::Expr& expr) {
    Subs subs;
    subs.put(var, expr);
    return subs;
}

Subs Subs::build(const ArrayReadPtr<Arith>& read, const Arith::Expr& expr) {
    Subs subs;
    subs.update(read, expr);
    return subs;
}

template<std::size_t I = 0>
void domainImpl(const Subs &s, VarSet &res) {
    if constexpr (I < Subs::variants) {
        res.get<I>() = s.get<I>().domain();
        domainImpl<I+1>(s, res);
    }
}

VarSet Subs::domain() const {
    VarSet res;
    domainImpl(*this, res);
    return res;
}

Bools::Expr Subs::get(const Bools::Var& var) const {
    return std::get<Bools::Subs>(t).get(var);
}

Arrays<Arith>::Expr Subs::get(const Arrays<Arith>::Var& var) const {
    return std::get<Arrays<Arith>::Subs>(t).get(var);
}

Arith::Expr Subs::getConst(const ArithVarPtr& var) const {
    assert(var->dim() == 0);
    return arrays::readConst(std::get<Arrays<Arith>::Subs>(t).get(var->var()));
}

template<std::size_t I = 0>
bool changesImpl(const Subs &s, const Var &x) {
    if constexpr (I < Subs::variants) {
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
    if constexpr (I < Subs::variants) {
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
    if constexpr (I < Subs::variants) {
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
    if constexpr (I < Subs::variants) {
        const auto &m {subs.get<I>()};
        if (!m.empty()) {
            if (first) {
                first = false;
            } else {
                s << " u ";
            }
            s << m;
        }
        if constexpr (I + 1 < Subs::variants) {
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
    if constexpr (I < Subs::variants) {
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

Bools::Expr Subs::operator()(const Lit& lit) const {
    return theory::apply(
        lit,
        [&](const Bools::Lit& lit) {
            return lit->subs(*this);
        },
        [&](const auto& lit) -> Bools::Expr {
            return bools::mkLit(lit->subs(*this));
        });
}

Expr Subs::operator()(const Expr& expr) const {
    return theory::apply(
        expr,
        [&](const Bools::Expr& expr) -> Expr {
            return expr->subs(*this);
        },
        [&](const auto& expr) -> Expr {
            return expr->subs(*this);
        }
    );
}

Subs Subs::concat(const Subs &that) const {
    Subs res;
    theory::iter(t, [&]<typename T>(const T& t) {
        std::get<T>(res.t) = t.concat(that);
    });
    return res;
}

BoolSubs concat(const BoolSubs &fst, const Renaming &snd) {
    BoolSubs res;
    for (const auto &[k,v]: fst) {
        res.put(k, v->renameVars(snd));
    }
    return res;
}

Subs Subs::concat(const Renaming &that) const {
    Subs res;
    theory::iter(
        t,
        [&](const ArraySubs<Arith>& t) {
            std::get<ArraySubs<Arith>>(res.t) = t.concat(that);
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
        [&](const ArraySubs<Arith>& t) {
            std::get<ArraySubs<Arith>>(res.t) = t.compose(that.get<Arrays<Arith>>());
        },
        [&](const BoolSubs& t) {
            std::get<BoolSubs>(res.t) = t.concat(that).unite(that.get<Bools>());
        });
    return res;
}

void Subs::collectCoDomainVars(VarSet& res) const {
    theory::iter(
        t,
        [&](const Arrays<Arith>::Subs& t) {
            t.collectCoDomainVars(res);
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

void Subs::collectCoDomainCells(CellSet& res) const {
    theory::iter(
        t,
        [&](const Arrays<Arith>::Subs& t) {
            t.collectCoDomainCells(res);
        },
        [&](const BoolSubs& t) {
            t.collectCoDomainCells(res);
        }
    );
}

CellSet Subs::coDomainCells() const {
    CellSet res;
    collectCoDomainCells(res);
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
        theory::apply(y, [&](const auto& y) {y->collectVars(vars);});
    }
}

Subs Subs::Empty {};

Var Subs::first(const Pair &p) {
    return theory::apply(p, [](const auto &p) {
        return Var(p.first);
    });
}

std::variant<Arrays<Arith>::Expr, Bools::Expr> Subs::second(const Pair &p) {
    return theory::apply(p, [](const auto &p) {
        return std::variant<Arrays<Arith>::Expr, Bools::Expr>(p.second);
    });
}

std::ostream& operator<<(std::ostream &s, const Subs &subs) {
    subs.print(s);
    return s;
}
