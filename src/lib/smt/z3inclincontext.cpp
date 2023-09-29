#include "z3inclincontext.hpp"

Z3IncLinContext::Z3IncLinContext(z3::context& ctx): Z3Context(ctx), exp(mkExp(ctx)) {}

z3::func_decl Z3IncLinContext::mkExp(z3::context& ctx) {
    z3::sort_vector sorts{ctx};
    sorts.push_back(ctx.int_sort());
    sorts.push_back(ctx.int_sort());
    return ctx.function("exp", sorts, ctx.int_sort());
}

z3::expr Z3IncLinContext::pow(const z3::expr &base, const z3::expr &exp) {
    long int_base;
    if (isRationalConstant(exp) || !isRationalConstant(base) || !base.is_numeral_i64(int_base) || int_base < 2) {
        return Z3Context::pow(base, exp);
    } else {
        const auto res {this->exp(base, exp)};
        exps.push_back(res);
        return res;
    }
}

z3::func_decl Z3IncLinContext::getExp() const {
    return exp;
}

std::vector<z3::expr> Z3IncLinContext::clearExps() {
    std::vector<z3::expr> res {exps};
    exps.clear();
    return res;
}
