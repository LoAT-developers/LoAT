#include "numexpressionutils.hpp"
#include "string.hpp"

#include <purrs.hh>

std::optional<ExprPtr> arith::solveTermFor(const ExprPtr e, const NumVarPtr var) {
    // we can only solve linear expressions with rational coefficients
    const auto c {e->coeff(var)};
    if (!c) {
        return {};
    }
    const auto r {(*c)->isRational()};
    if (!r) {
        return {};
    }
    return (e - (*c) * var->toExpr())->divide(-(***r));
}

ExprPtr arith::fromPurrs(const Purrs::Expr &e, const purrs_var_map &map) {
    Purrs::Number n;
    if (e.is_a_number(n)) {
        const Rational num {toString(n.numerator())};
        const Rational denom {toString(n.denominator())};
        return mkConst(num / denom);
    }
    Purrs::Symbol s;
    if (e.is_a_symbol(s)) {
        return map.right.at(s)->toExpr();
    }
    if (e.is_a_add()) {
        std::vector<ExprPtr> args;
        for (unsigned i = 0; i < e.nops(); ++i) {
            args.push_back(fromPurrs(e.arg(i), map));
        }
        return mkPlus(args);
    }
    if (e.is_a_mul()) {
        std::vector<ExprPtr> args;
        for (unsigned i = 0; i < e.nops(); ++i) {
            args.push_back(fromPurrs(e.arg(i), map));
        }
        return mkTimes(args);
    }
    if (e.is_a_power()) {
        return mkExp(fromPurrs(e.arg(0), map), fromPurrs(e.arg(1), map));
    }
    throw std::invalid_argument("unknown purrs expression " + toString(e));
}
