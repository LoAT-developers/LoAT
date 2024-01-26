#include "loopcomplexity.hpp"
#include "expr.hpp"

LoopComplexity LoopComplexity::compute(const Rule &rule) {
    LoopComplexity res;
    for (const auto &p: rule.getUpdate()) {
        const auto x {expr::first(p)};
        const auto v {expr::second(p)};
        const auto vars {expr::vars(v)};
        ++res.non_recursive;
        for (const auto &y: vars) {
            if (x == y) {
                --res.non_recursive;
            } else if (expr::isTempVar(y)) {
                ++res.tmp_vars;
            } else {
                ++res.foreign_vars;
            }
        }
    }
    for (const auto &[x,v]: rule.getUpdate<IntTheory>()) {
        const auto vars {v.vars()};
        if (vars.contains(x) && v.isPoly() && v.degree(x) == 1) {
            const Expr coeff {v.coeff(x)};
            if (coeff.isRationalConstant() && coeff.toNum().is_negative()) {
                ++res.negated;
            }
        }
    }
    for (const auto &[x,v]: rule.getUpdate().get<BoolTheory>()) {
        const auto lits {v->lits()};
        const auto lit {BoolLit(x)};
        if (lits.find(!lit) != lits.end() && lits.find(lit) == lits.end()) {
            ++res.negated;
        }
    }
    return res;
}

std::strong_ordering operator <=>(const LoopComplexity &c1, const LoopComplexity &c2) {
    auto cmp {c1.non_recursive <=> c2.non_recursive};
    if (cmp != std::strong_ordering::equal) {
        return cmp;
    }
    cmp = c1.foreign_vars <=> c2.foreign_vars;
    if (cmp != std::strong_ordering::equal) {
        return cmp;
    }
    cmp = c1.tmp_vars <=> c2.tmp_vars;
    if (cmp != std::strong_ordering::equal) {
        return cmp;
    }
    return c1.negated <=> c2.negated;
}

std::strong_ordering LoopComplexity::compare(const Rule &r1, const Rule &r2) {
    return compute(r1) <=> compute(r2);
}
