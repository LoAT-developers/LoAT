#include "arithlit.hpp"
#include "arithsubs.hpp"

#include <sstream>
#include <assert.h>
#include <boost/functional/hash.hpp>
#include <algorithm>
#include <unordered_set>

std::size_t hash_value(const Bound &bound) {
    std::size_t hash {42};
    boost::hash_combine(hash, bound.bound);
    boost::hash_combine(hash, bound.kind);
    return hash;
}

std::size_t hash_value(const Divisibility &d) {
    std::size_t hash {42};
    boost::hash_combine(hash, d.factor);
    boost::hash_combine(hash, d.modulo);
    boost::hash_combine(hash, d.res);
    return hash;
}

std::ostream& operator<<(std::ostream &s, const ArithLitSet &set) {
    s << "{";
    for (auto it = set.begin(); it != set.end(); ++it) {
        if (it != set.begin()) {
            s << ", ";
        }
        s << *it;
    }
    s << "}";
    return s;
}

ConsHash<ArithLit, ArithLit, ArithLit::CacheHash, ArithLit::CacheEqual, ArithExprPtr, ArithLit::Kind> ArithLit::cache {};

bool ArithLit::CacheEqual::operator()(const std::tuple<ArithExprPtr, ArithLit::Kind> &args1, const std::tuple<ArithExprPtr, ArithLit::Kind> &args2) const noexcept {
    return args1 == args2;
}

size_t ArithLit::CacheHash::operator()(const std::tuple<ArithExprPtr, ArithLit::Kind> &args) const noexcept {
    size_t seed {42};
    boost::hash_combine(seed, std::get<0>(args));
    boost::hash_combine(seed, std::get<1>(args));
    return seed;
}

ArithLit::ArithLit(const ArithExprPtr l, const Kind kind): l(l), kind(kind) { }

ArithLitPtr ArithLit::mk(const ArithExprPtr lhs, const ArithLit::Kind kind) {
    const auto lcm {lhs->denomLcm()};
    auto lhs_integral = lcm == 1 ? lhs : lhs * arith::mkConst(lcm);
    const auto factor {lhs_integral->getConstantFactor()};
    if (factor > 1) {
        lhs_integral = lhs_integral->divide(factor);
    }
    if ((kind == Kind::Eq || kind == Kind::Neq)) {
        if (cache.contains(lhs_integral, kind)) {
            return cache.from_cache(lhs_integral, kind);
        } else if (const auto neg{-lhs_integral}; cache.contains(neg, kind)) {
            return cache.from_cache(neg, kind);
        }
    }
    return cache.from_cache(lhs_integral, kind);
}

ArithExprPtr ArithLit::lhs() const {
    return l;
}

bool ArithLit::isPoly() const {
    return l->isPoly().has_value();
}

bool ArithLit::isLinear(const std::optional<linked_hash_set<ArithVarPtr>> &vars) const {
    return l->isLinear(vars);
}

void ArithLit::getBounds(const ArithVarPtr n, linked_hash_set<Bound> &res) const {
    if (l->isPoly(n) == 1 && kind != Kind::Neq) {
        const auto t = kind == Kind::Eq ? l : l - arith::mkConst(1);
        const auto coeff{*t->coeff(n)};
        const auto optSolved{t->solve(n)};
        if (optSolved) {
            switch (kind) {
            case Kind::Eq:
                res.emplace(*optSolved, BoundKind::Equality);
                break;
            case Kind::Gt: {
                const auto r{***coeff->isRational()};
                if (r > 0) {
                    res.emplace(*optSolved, BoundKind::Lower);
                } else {
                    res.emplace(*optSolved, BoundKind::Upper);
                }
                break;
            }
            default:
                throw std::invalid_argument("unexpected relation");
            }
        }
    }
}

std::optional<std::pair<ArithExprPtr, Int>> ArithLit::isDivisibility() const {
    if (kind == Kind::Eq) {
        if (const auto mod{l->isMod()}) {
            if (const auto modulo{(*mod)->getRhs()->isInt()}) {
                const auto lhs {(*mod)->getLhs()};
                if (lhs->isLinear() && !lhs->isRational()) {
                    return {{lhs, *modulo}};
                }
            }
        }
    }
    return {};
}

std::optional<Divisibility> ArithLit::isDivisibility(const ArithVarPtr n) const {
    linked_hash_set<Divisibility> res;
    getDivisibility(n, res);
    using opt = std::optional<Divisibility>;
    return res.empty() ? opt{} : opt{*res.begin()};
}

void ArithLit::getDivisibility(const ArithVarPtr n, linked_hash_set<Divisibility> &res) const {
    if (kind == Kind::Eq) {
        if (const auto mod{l->isMod()}) {
            if (const auto modulo{(*mod)->getRhs()->isInt()}) {
                if ((*mod)->getLhs() == n) {
                    // modulo | n
                    res.emplace(1, *modulo, arith::mkConst(0));
                } else if (const auto sum{(*mod)->getLhs()->isAdd()}) {
                    auto args{(*sum)->getArgs()};
                    std::optional<Int> factor;
                    if (args.contains(n)) {
                        factor = 1;
                    } else {
                        for (const auto &arg : args) {
                            if (arg->has(n)) {
                                if (const auto mul{arg->isMult()}) {
                                    auto mul_args{(*mul)->getArgs()};
                                    if (mul_args.size() == 2 && mul_args.contains(n)) {
                                        mul_args.erase(n);
                                        factor = (*mul_args.begin())->isInt();
                                    }
                                }
                                break;
                            }
                        }
                    }
                    if (!factor) {
                        return;
                    }
                    args.erase(arith::mkConst(*factor) * n);
                    const auto mres{arith::mkPlus(std::vector<ArithExprPtr>(args.begin(), args.end()))};
                    if (mres->has(n)) {
                        return;
                    }
                    // (factor * n + mres) % modulo = 0
                    // ==> modulo | factor * n + mres
                    res.emplace(*factor, *modulo, mres);
                    return;
                } else if (const auto mul{(*mod)->getLhs()->isMult()}) {
                    auto mul_args{(*mul)->getArgs()};
                    if (mul_args.contains(n) && mul_args.contains(n)) {
                        mul_args.erase(n);
                        if (const auto factor{(*mul_args.begin())->isInt()}) {
                            // modulo | factor * n
                            res.emplace(*factor, *modulo, arith::mkConst(0));
                        }
                    }
                }
            }
        }
    }
}

std::optional<ArithExprPtr> ArithLit::getEquality(const ArithVarPtr n) const {
    if (isEq()) {
        return l->solve(n);
    }
    return {};
}

void ArithLit::propagateEquality(ArithSubs &subs, const std::function<bool(const ArithVarPtr &)> &allow) const {
    if (isEq()) {
        for (const auto &x: vars()) {
            if (allow(x) && !subs.contains(x) && l->isLinear({{x}})) {
                const auto coeff {l->coeff(x)};
                if ((*coeff)->is(1) || (*coeff)->is(-1)) {
                    const auto t {*l->solve(x)};
                    subs = subs.compose(ArithSubs{{x, t}});
                    return;
                }
            }
        }
    }
}

bool ArithLit::isTriviallyTrue() const {
    const auto optTrivial {checkTrivial()};
    return optTrivial && *optTrivial;
}

bool ArithLit::isTriviallyFalse() const {
    const auto optTrivial {checkTrivial()};
    return optTrivial && !*optTrivial;
}

bool ArithLit::isGt() const {
    return kind == Kind::Gt;
}

bool ArithLit::isEq() const {
    return kind == Kind::Eq;
}

bool ArithLit::isNeq() const {
    return kind == Kind::Neq;
}

std::optional<bool> ArithLit::checkTrivial() const {
    if (const auto r {l->isRational()}) {
        switch (kind) {
            case Kind::Eq: return ***r == 0;
            case Kind::Gt: return ***r > 0;
            case Kind::Neq: return ***r != 0;
        }
    }
    return {};
}

void ArithLit::collectVars(linked_hash_set<ArithVarPtr> &res) const {
    l->collectVars(res);
}

bool ArithLit::has(const ArithVarPtr x) const {
    return l->has(x);
}

ArithLitPtr ArithLit::subs(const ArithSubs &map) const {
    return mk(map(l), kind);
}

linked_hash_set<ArithVarPtr> ArithLit::vars() const {
    return l->vars();
}

std::size_t ArithLit::hash() const {
    size_t seed{0};
    boost::hash_combine(seed, l);
    boost::hash_combine(seed, kind);
    return seed;
}

size_t hash_value(const ArithLit &rel) {
    return rel.hash();
}

ArithLitPtr arith::mkGeq(const ArithExprPtr x, const ArithExprPtr y) {
    const auto lhs {x - y};
    auto lhs_integral {lhs * arith::mkConst(lhs->denomLcm())};
    const auto factor {lhs_integral->getConstantFactor()};
    if (factor > 1) {
        lhs_integral = lhs_integral->divide(factor);
    }
    return ArithLit::cache.from_cache(lhs_integral + arith::mkConst(1), ArithLit::Kind::Gt);
}

ArithLitPtr arith::mkLeq(const ArithExprPtr x, const ArithExprPtr y) {
    return mkGeq(y, x);
}

ArithLitPtr arith::mkGt(const ArithExprPtr x, const ArithExprPtr y) {
    return ArithLit::mk(x - y, ArithLit::Kind::Gt);
}

ArithLitPtr arith::mkEq(const ArithExprPtr x, const ArithExprPtr y) {
    return ArithLit::mk(x - y, ArithLit::Kind::Eq);
}

ArithLitPtr arith::mkNeq(const ArithExprPtr x, const ArithExprPtr y) {
    return ArithLit::mk(x - y, ArithLit::Kind::Neq);
}

ArithLitPtr arith::mkLt(const ArithExprPtr x, const ArithExprPtr y) {
    return ArithLit::mk(y - x, ArithLit::Kind::Gt);
}

ArithLitPtr operator!(const ArithLitPtr x) {
    switch (x->kind) {
        case ArithLit::Kind::Gt: return ArithLit::mk(arith::mkConst(1) - x->lhs(), ArithLit::Kind::Gt);
        case ArithLit::Kind::Eq: return ArithLit::mk(x->lhs(), ArithLit::Kind::Neq);
        case ArithLit::Kind::Neq: return ArithLit::mk(x->lhs(), ArithLit::Kind::Eq);
        default: throw std::invalid_argument("unexpected relation");
    }
}

std::ostream& operator<<(std::ostream &s, const ArithLitPtr rel) {
    std::string lhs;
    std::string rhs;
    if (const auto add {rel->lhs()->isAdd()}) {
        std::vector<ArithExprPtr> lhs_args;
        std::vector<ArithExprPtr> rhs_args;
        for (const auto &arg: (*add)->getArgs()) {
            if (arg->isNegated()) {
                rhs_args.emplace_back(-arg);
            } else {
                lhs_args.emplace_back(arg);
            }
        }
        lhs = toString(arith::mkPlus(std::move(lhs_args)));
        rhs = toString(arith::mkPlus(std::move(rhs_args)));
    } else {
        lhs = toString(rel->lhs());
        rhs = "0";
    }
    switch (rel->kind) {
        case ArithLit::Kind::Gt: return s << lhs << " > " << rhs;
        case ArithLit::Kind::Eq: return s << lhs << " = " << rhs;
        case ArithLit::Kind::Neq: return s << lhs << " != " << rhs;
        default: throw std::invalid_argument("unexpected relation");
    }
}

bool ArithLit::eval(const linked_hash_map<ArithVarPtr, Int> &m) const {
    switch (kind) {
        case Kind::Gt: return l->eval(m) > 0;
        case Kind::Eq: return l->eval(m) == 0;
        case Kind::Neq: return l->eval(m) != 0;
        default: throw std::invalid_argument("unexpected relation");
    }
}

sexpresso::Sexp ArithLit::to_smtlib(const std::function<std::string(const ArithVarPtr)> &var_map) const {
    std::string op;
    switch (kind) {
    case Kind::Gt:
        op = ">";
        break;
    case Kind::Eq:
        op = "=";
        break;
    case Kind::Neq:
        op = "distinct";
        break;
    }
    sexpresso::Sexp res {op};
    res.addChild(l->to_smtlib(var_map));
    res.addChild("0");
    return res;
}

void ArithLit::simplifyAnd(linked_hash_set<ArithLitPtr> &lits) {
    std::unordered_set<ArithLitPtr> remove;
    linked_hash_set<ArithLitPtr> add;
    for (const auto &rel: lits) {
        if (rel->isGt() && !remove.contains(rel)) {
            const auto converse {arith::mkLeq(rel->lhs(), arith::mkConst(1))};
            if (lits.contains(converse)) {
                remove.insert(rel);
                remove.insert(converse);
                add.insert(arith::mkEq(rel->lhs(), arith::mkConst(1)));
            }
        }
    }
    for (const auto &r: remove) {
        lits.erase(r);
    }
    for (const auto &a: add) {
        lits.insert(a);
    }
}

void ArithLit::simplifyOr(linked_hash_set<ArithLitPtr> &lits) {
    std::unordered_set<ArithLitPtr> remove;
    std::unordered_set<ArithLitPtr> add;
    for (const auto &rel: lits) {
        if (rel->isGt() && !remove.contains(rel)) {
            const auto converse {arith::mkLt(rel->lhs(), arith::mkConst(0))};
            if (lits.contains(converse)) {
                remove.insert(rel);
                remove.insert(converse);
                add.insert(arith::mkNeq(rel->lhs(), arith::mkConst(0)));
            }
        }
    }
    for (const auto &r: remove) {
        lits.erase(r);
    }
    for (const auto &a: add) {
        lits.insert(a);
    }
}
