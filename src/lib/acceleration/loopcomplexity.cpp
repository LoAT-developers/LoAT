#include "loopcomplexity.hpp"
#include "theory.hpp"

LoopComplexity LoopComplexity::compute(const RulePtr rule) {
    LoopComplexity res;
    for (const auto &[x, v] : rule->getUpdate()) {
        const auto vars{theory::vars(v)};
        ++res.non_recursive;
        for (const auto &y : vars) {
            if (x == y) {
                --res.non_recursive;
            } else if (theory::isTempVar(y)) {
                ++res.tmp_vars;
            } else {
                ++res.foreign_vars;
            }
        }
    }
    // for (const auto &[x, v] : rule->getUpdate<Arith>()) {
    //     const auto vars{v->vars()};
    //     if (vars.contains(x) && v->isPoly(x) == 1) {
    //         const auto coeff{v->coeff(x)};
    //         if (coeff) {
    //             const auto c{(*coeff)->isRational()};
    //             if (c && ***c < 0) {
    //                 ++res.negated;
    //             }
    //         }
    //     }
    // }
    for (const auto &[x, v] : rule->getUpdate().get<Bools>()) {
        const auto lits{v->lits()};
        const auto lit{bools::mk(x)};
        if (lits.contains(!lit) && !lits.contains(lit)) {
            ++res.negated;
        }
    }
    return res;
}

std::strong_ordering operator<=>(const LoopComplexity &c1, const LoopComplexity &c2) {
    auto cmp{c1.non_recursive <=> c2.non_recursive};
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

std::strong_ordering LoopComplexity::compare(const RulePtr r1, const RulePtr r2) {
    return compute(r1) <=> compute(r2);
}

std::ostream &operator<<(std::ostream &s, const LoopComplexity &c) {
    return std::cout
           << "{"
           << "negated: " << c.negated
           << ", non-recursive: " << c.non_recursive
           << ", foreign vars: " << c.foreign_vars
           << ", tmp vars: " << c.tmp_vars
           << "}";
}
