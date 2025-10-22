#include "loopcomplexity.hpp"
#include "theory.hpp"

LoopComplexity LoopComplexity::compute(const RulePtr& rule) {
    LoopComplexity res;
    for (const auto &p : rule->getUpdate()) {
        theory::apply(
            p,
            [&](const auto& p) {
                const auto& [x, v]{p};
                const auto vars{v->vars()};
                ++res.non_recursive;
                for (const auto& y : vars) {
                    if (Var(x) == Var(y)) {
                        --res.non_recursive;
                    } else if (theory::isTempVar(y)) {
                        ++res.tmp_vars;
                    } else {
                        ++res.foreign_vars;
                    }
                }
            });
    }
    for (const auto &[x_arr, v_arr] : rule->getUpdate<Arrays<Arith>>()) {
        assert(x_arr->dim() == 0);
        assert(v_arr->isArrayWrite());
        const ArithVarPtr x {arrays::readConst(x_arr)};
        if (const Arith::Expr v {(*v_arr->isArrayWrite())->val()}; v->has(x) && v->isPoly(x) == 1) {
            if (const auto coeff{v->coeff(x)}) {
                if (const auto c{(*coeff)->isRational()}; c && ***c < 0) {
                    ++res.negated_int;
                }
            }
        }
    }
    for (const auto &[x, v] : rule->getUpdate().get<Bools>()) {
        const auto lits{v->lits()};
        if (const auto lit{bools::mk(x)}; lits.contains(!lit) && !lits.contains(lit)) {
            ++res.negated_bool;
        }
    }
    return res;
}

std::strong_ordering operator<=>(const LoopComplexity &c1, const LoopComplexity &c2) {
    auto cmp{c1.negated_int <=> c2.negated_int};
    if (cmp != std::strong_ordering::equal) {
        return cmp;
    }
    cmp = c1.non_recursive <=> c2.non_recursive;
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
    return c1.negated_bool <=> c2.negated_bool;
}

std::strong_ordering LoopComplexity::compare(const RulePtr& r1, const RulePtr& r2) {
    return compute(r1) <=> compute(r2);
}

std::ostream &operator<<(std::ostream &s, const LoopComplexity &c) {
    return s
           << "{"
           << "negated int: " << c.negated_int
           << ", negated bool: " << c.negated_bool
           << ", non-recursive: " << c.non_recursive
           << ", foreign vars: " << c.foreign_vars
           << ", tmp vars: " << c.tmp_vars
           << "}";
}
