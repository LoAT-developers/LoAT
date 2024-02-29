#include "subs.hpp"

namespace theory {

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
    while (ptr.index() + 1 < variant_size && ptr == end(ptr.index())) {
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
    return Subs::Iterator(*this, std::get<variant_size - 1>(t).end());
}

Subs::Iterator Subs::begin() const {
    return beginImpl();
}

Subs Subs::project(const VS &vars) const {
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

Subs::VS Subs::domain() const {
    VS res;
    domainImpl(res);
    return res;
}

Subs::Expr Subs::get(const Var &var) const {
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

void Subs::erase(const VS &xs) {
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

BExpr Subs::operator()(const Lit &lit) const {
    return subsImpl<0>(lit);
}

BExpr Subs::operator()(const BExpr e) const {
    return e->map([&](const auto &lit) {
        return (*this)(lit);
    });
}

Subs::TheTheory::Expr Subs::operator()(const TheTheory::Expr &expr) const {
    return std::visit(
        Overload{
            [&](const Arith::Expr expr) {
                return TheTheory::Expr{get<Arith>()(expr)};
            },
            [&](const Bools::Expr expr) {
                return TheTheory::Expr{(*this)(expr)};
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

Subs Subs::Empty {};

typename Theory<Arith, Bools>::Var first(const typename Subs::Pair &p) {
    return std::visit(
        [](const auto &p){
            return typename Theory<Arith, Bools>::Var(p.first);
        }, p);
}

typename Theory<Arith, Bools>::Expr second(const typename Subs::Pair &p) {
    return std::visit(
        [](const auto &p) {
            return typename Theory<Arith, Bools>::Expr(p.second);
        }, p);
}

std::ostream& operator<<(std::ostream &s, const Subs &subs) {
    subs.print(s);
    return s;
}

}
