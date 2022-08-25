#include "nondetupdate.hpp"

NondetUpdate::LowerUpper::LowerUpper(const option<Expr> &lower, const option<Expr> upper): lower(lower), upper(upper) {}

VarSet NondetUpdate::LowerUpper::vars() const {
    VarSet res;
    if (lower) lower->collectVars(res);
    if (upper) upper->collectVars(res);
    return res;
}

void NondetUpdate::LowerUpper::subs(const Subs &subs) {
    if (lower) lower = lower->subs(subs);
    if (upper) upper = upper->subs(subs);
}

NondetUpdate::Entry::Entry(const Expr &e): e(e){}

NondetUpdate::Entry::Entry(const option<Expr> &lower, const option<Expr> &upper): e(LowerUpper(lower, upper)){}

VarSet NondetUpdate::Entry::vars() const {
    if (std::holds_alternative<Expr>(e)) {
        return std::get<Expr>(e).vars();
    } else {
        return std::get<LowerUpper>(e).vars();
    }
}

option<Expr> NondetUpdate::Entry::getLower() const {
    if (std::holds_alternative<Expr>(e)) {
        return std::get<Expr>(e);
    } else {
        return std::get<LowerUpper>(e).lower;
    }
}

option<Expr> NondetUpdate::Entry::getUpper() const {
    if (std::holds_alternative<Expr>(e)) {
        return std::get<Expr>(e);
    } else {
        return std::get<LowerUpper>(e).upper;
    }
}

void NondetUpdate::Entry::subs(const Subs &subs) {
    if (std::holds_alternative<Expr>(e)) {
        e = std::get<Expr>(e).subs(subs);
    } else {
        std::get<LowerUpper>(e).subs(subs);
    }
}

bool NondetUpdate::Entry::isDeterministic() const {
    return std::holds_alternative<Expr>(e);
}

bool NondetUpdate::Entry::isLinear() const {
    if (std::holds_alternative<Expr>(e)) {
        return std::get<Expr>(e).isLinear();
    } else {
        const LowerUpper lu = std::get<LowerUpper>(e);
        return (!lu.lower || lu.lower->isLinear()) && (!lu.upper || lu.upper->isLinear());
    }
}

bool NondetUpdate::Entry::isPoly() const {
    if (std::holds_alternative<Expr>(e)) {
        return std::get<Expr>(e).isPoly();
    } else {
        const LowerUpper lu = std::get<LowerUpper>(e);
        return (!lu.lower || lu.lower->isPoly()) && (!lu.upper || lu.upper->isPoly());
    }
}

NondetUpdate::NondetUpdate() = default;

NondetUpdate::NondetUpdate(const Subs &subs) {
    for (const auto &e: subs) {
        map.emplace(e.first, e.second);
    }
}

void NondetUpdate::put(const Var &x, const option<Expr> &l, const option<Expr> &u) {
    map.emplace(x, Entry(l, u));
}

void NondetUpdate::put(const Var &x, const Expr &e) {
    map.emplace(x, e);
}

option<Expr> NondetUpdate::getLower(const Var &x) const {
    const auto it = map.find(x);
    if (it == map.end()) return Expr(x);
    else return it->second.getLower();
}

option<Expr> NondetUpdate::getUpper(const Var &x) const {
    const auto it = map.find(x);
    if (it == map.end()) return Expr(x);
    else return it->second.getUpper();
}

bool NondetUpdate::isDeterministic(const Var &x) const {
    const auto it = map.find(x);
    return it == map.end() || it->second.isDeterministic();
}

bool NondetUpdate::isDeterministic() const {
    return std::all_of(map.begin(), map.end(), [](const auto &e){return e.second.isDeterministic();});
}

bool NondetUpdate::isLinear() const {
    return std::all_of(map.begin(), map.end(), [](const auto &e){return e.second.isLinear();});
}

bool NondetUpdate::isPoly() const {
    return std::all_of(map.begin(), map.end(), [](const auto &e){return e.second.isPoly();});
}

size_t NondetUpdate::size() const {
    return map.size();
}

bool NondetUpdate::contains(const Var &x) const {
    return map.find(x) != map.end();
}

void NondetUpdate::compose(const Subs &subs) {
    for (auto &e: map) {
        e.second.subs(subs);
    }
}

option<Subs> NondetUpdate::toSubs() const {
    Subs subs;
    for (const auto &e: map) {
        if (e.second.isDeterministic()) {
            subs.put(e.first, *e.second.getLower());
        } else {
            return {};
        }
    }
    return subs;
}

VarMap<NondetUpdate::Entry>::iterator NondetUpdate::begin() {
    return map.begin();
}

VarMap<NondetUpdate::Entry>::iterator NondetUpdate::end() {
    return map.end();
}

VarMap<NondetUpdate::Entry>::const_iterator NondetUpdate::begin() const {
    return map.begin();
}

VarMap<NondetUpdate::Entry>::const_iterator NondetUpdate::end() const {
    return map.end();
}
