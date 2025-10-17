#include "arithlit.hpp"
#include "arithsubs.hpp"
#include "sexpresso.hpp"

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

bool ArithLit::CacheEqual::operator()(const std::tuple<ArithExprPtr, Kind> &args1, const std::tuple<ArithExprPtr, Kind> &args2) const noexcept {
    return args1 == args2;
}

size_t ArithLit::CacheHash::operator()(const std::tuple<ArithExprPtr, Kind> &args) const noexcept {
    size_t seed {42};
    boost::hash_combine(seed, std::get<0>(args));
    boost::hash_combine(seed, std::get<1>(args));
    return seed;
}

ArithLit::ArithLit(const ArithExprPtr& lhs, const Kind kind): l(lhs), kind(kind) { }

ArithLit::~ArithLit() {
    cache.erase(l, kind);
}

ArithLitPtr ArithLit::mk(const ArithExprPtr& lhs, const Kind kind) {
    const auto lcm {lhs->denomLcm()};
    auto lhs_integral = lcm == 1 ? lhs : lhs * arith::mkConst(lcm);
    if (const auto factor {lhs_integral->getConstantFactor()}; factor > 1) {
        lhs_integral = lhs_integral->divide(factor);
    }
    if (kind == Kind::Eq || kind == Kind::Neq) {
        if (lhs_integral->isNegated()) {
            return cache.from_cache(-lhs_integral, kind);
        }
        if (const auto add {lhs_integral->isAdd()}) {
            if ((*(*add)->getArgs().begin())->isNegated()) {
                return cache.from_cache(-lhs_integral, kind);
            }
        }
        return cache.from_cache(lhs_integral, kind);
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

void ArithLit::getBounds(const ArithVarPtr& n, linked_hash_set<Bound> &res) const {
    if (l->isPoly(n) == 1 && kind != Kind::Neq) {
        const auto t = kind == Kind::Eq ? l : l - arith::mkConst(1);
        const auto coeff{*t->coeff(n)};
        if (const auto optSolved{t->solve(n)}) {
            switch (kind) {
            case Kind::Eq:
                res.emplace(*optSolved, BoundKind::Equality);
                break;
            case Kind::Gt: {
                if (const auto r{***coeff->isRational()}; r > 0) {
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
                if (const auto lhs {(*mod)->getLhs()}; lhs->isLinear() && !lhs->isRational()) {
                    return {{lhs, *modulo}};
                }
            }
        }
    }
    return {};
}

std::optional<Divisibility> ArithLit::isDivisibility(const ArithVarPtr& n) const {
    linked_hash_set<Divisibility> res;
    getDivisibility(n, res);
    using opt = std::optional<Divisibility>;
    return res.empty() ? opt{} : opt{*res.begin()};
}

void ArithLit::getDivisibility(const ArithVarPtr& n, linked_hash_set<Divisibility> &res) const {
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
                                    if (auto mul_args{(*mul)->getArgs()}; mul_args.size() == 2 && mul_args.contains(n)) {
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
                    const auto mres{arith::mkPlus(std::vector(args.begin(), args.end()))};
                    if (mres->has(n)) {
                        return;
                    }
                    // (factor * n + mres) % modulo = 0
                    // ==> modulo | factor * n + mres
                    res.emplace(*factor, *modulo, mres);
                } else if (const auto mul{(*mod)->getLhs()->isMult()}) {
                    if (auto mul_args{(*mul)->getArgs()}; mul_args.contains(n)) {
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

std::optional<ArithExprPtr> ArithLit::getEquality(const ArithVarPtr& n) const {
    if (isEq()) {
        return l->solve(n);
    }
    return {};
}

void ArithLit::propagateEquality(ArithSubs &subs, const std::function<bool(const ArithVarPtr &)> &allow, std::unordered_set<ArithVarPtr> &blocked) const {
    if (isEq()) {
        for (const auto vs {vars()}; const auto &x: vs) {
            if (!blocked.contains(x) && allow(x) && l->isLinear({{x}})) {
                if (const auto coeff {l->coeff(x)}; (*coeff)->is(1) || (*coeff)->is(-1)) {
                    const auto t {*l->solve(x)};
                    subs.put(x, t);
                    blocked.insert(vs.begin(), vs.end());
                    return;
                }
            }
        }
    }
}

ArithLitPtr ArithLit::eval(const ModelPtr& model, const ArithVarPtr& keep) const {
    return mk(l->eval(model, keep), kind);
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

bool ArithLit::has(const ArithVarPtr& x) const {
    return l->has(x);
}

ArithLitPtr ArithLit::subs(const ArithSubs &map) const {
    return mk(l->subs(map), kind);
}

ArithLitPtr ArithLit::renameVars(const arith_var_map &map) const {
    return mk(l->renameVars(map), kind);
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

ArithLitPtr arith::mkGeq(const ArithExprPtr& x, const ArithExprPtr& y) {
    const auto lhs {x - y};
    auto lhs_integral {lhs * mkConst(lhs->denomLcm())};
    if (const auto factor {lhs_integral->getConstantFactor()}; factor > 1) {
        lhs_integral = lhs_integral->divide(factor);
    }
    return ArithLit::cache.from_cache(lhs_integral + mkConst(1), ArithLit::Kind::Gt);
}

ArithLitPtr arith::mkLeq(const ArithExprPtr& x, const ArithExprPtr& y) {
    return mkGeq(y, x);
}

ArithLitPtr arith::mkGt(const ArithExprPtr& x, const ArithExprPtr& y) {
    return ArithLit::mk(x - y, ArithLit::Kind::Gt);
}

ArithLitPtr arith::mkEq(const ArithExprPtr& x, const ArithExprPtr& y) {
    return ArithLit::mk(x - y, ArithLit::Kind::Eq);
}

ArithLitPtr arith::mkNeq(const ArithExprPtr& x, const ArithExprPtr& y) {
    return ArithLit::mk(x - y, ArithLit::Kind::Neq);
}

ArithLitPtr arith::mkLt(const ArithExprPtr& x, const ArithExprPtr& y) {
    return ArithLit::mk(y - x, ArithLit::Kind::Gt);
}

ArithLitPtr operator!(const ArithLitPtr& x) {
    switch (x->kind) {
        case ArithLit::Kind::Gt: return ArithLit::mk(arith::mkConst(1) - x->lhs(), ArithLit::Kind::Gt);
        case ArithLit::Kind::Eq: return ArithLit::mk(x->lhs(), ArithLit::Kind::Neq);
        case ArithLit::Kind::Neq: return ArithLit::mk(x->lhs(), ArithLit::Kind::Eq);
        default: throw std::invalid_argument("unexpected relation");
    }
}

std::ostream& operator<<(std::ostream &s, const ArithLitPtr& rel) {
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

sexpresso::Sexp ArithLit::to_smtlib() const {
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
    res.addChild(l->to_smtlib());
    res.addChild("0");
    return res;
}

bool ArithLit::simplifyAnd(linked_hash_set<ArithLitPtr> &lits) {
    std::unordered_set<ArithLitPtr> remove;
    linked_hash_set<ArithLitPtr> add;
    for (const auto &rel: lits) {
        if (rel->isGt() && !remove.contains(rel)) {
            if (const auto converse {arith::mkLeq(rel->lhs(), arith::mkConst(1))}; lits.contains(converse)) {
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
    return !add.empty();
}

bool ArithLit::simplifyOr(linked_hash_set<ArithLitPtr> &lits) {
    std::unordered_set<ArithLitPtr> remove;
    std::unordered_set<ArithLitPtr> add;
    for (const auto &rel: lits) {
        if (rel->isGt() && !remove.contains(rel)) {
            if (const auto converse {arith::mkLt(rel->lhs(), arith::mkConst(0))}; lits.contains(converse)) {
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
    return !add.empty();
}
