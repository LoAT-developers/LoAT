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

Subs::Iterator Subs::begin() const {
    return beginImpl();
}

Subs Subs::project(const VarSet &vars) const {
    Subs res;
    projectImpl(res, vars);
    return Subs(res);
}

void Subs::put(const Pair &p) {
    putImpl(p);
}

void Subs::put(const Var &x, const Expr &y) {
    putImpl(x, y);
}

Subs::Subs(){}

Subs::Subs(Pair &p) {
    put(p);
}

VarSet Subs::domain() const {
    VarSet res;
    domainImpl(res);
    return res;
}

Expr Subs::get(const Var &var) const {
    return getImpl(var);
}

Subs Subs::unite(const Subs &that) const {
    Subs res;
    uniteImpl(that, res);
    return res;
}

bool Subs::changes(const Var &x) const {
    return changesImpl(x);
}

void Subs::erase(const Var &x) {
    eraseImpl(x);
}

void Subs::erase(const VarSet &xs) {
    eraseImpl(xs);
}

void Subs::print(std::ostream &s) const {
    printImpl(s);
}

size_t Subs::hash() const {
    size_t res {0};
    hashImpl(res);
    return res;
}

bool Subs::contains(const Var &var) const {
    return containsImpl(var);
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

BoolExprPtr Subs::operator()(const Lit &lit) const {
    return subsImpl<0>(lit);
}

BoolExprPtr Subs::operator()(const BoolExprPtr e) const {
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

Subs Subs::concat(const Subs &that) const {
    Subs res;
    concatImpl(that, res);
    return res;
}

Subs Subs::compose(const Subs &that) const {
    Subs res;
    composeImpl(that, res);
    return res;
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
