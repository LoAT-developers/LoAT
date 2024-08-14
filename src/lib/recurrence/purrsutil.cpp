#include "purrsutil.hpp"
#include "string.hpp"

#include <numeric>

namespace arith {

std::pair<Purrs::Expr, purrs_var_map> toPurrs(const ArithExprPtr e, const ArithVarPtr n) {
    purrs_var_map m;
    m.left.insert(purrs_var_map::left_value_type(n, Purrs::Recurrence::n));
    const auto res {toPurrs(e, m)};
    return {res, m};
}

Purrs::Expr toPurrs(const ArithExprPtr e, purrs_var_map &m) {
    return e->apply<Purrs::Expr>(
        [](const ArithConstPtr t) {
            return Purrs::Number(t->numerator()->getValue().str().c_str()) / Purrs::Number(t->denominator()->getValue().str().c_str());
        },
        [&](const ArithVarPtr x) {
            const auto res {m.left.find(x)};
            if (res == m.left.end()) {
                Purrs::Symbol s {x->getName()};
                m.left.insert(purrs_var_map::left_value_type(x, s));
                return s;
            }
            return res->second;
        },
        [&](const ArithAddPtr a) {
            const auto &args {a->getArgs()};
            return std::accumulate(args.begin(), args.end(), Purrs::Expr(0), [&m](const auto &x, const auto &y){
                return x + toPurrs(y, m);
            });
        },
        [&](const ArithMultPtr mult) {
            const auto &args {mult->getArgs()};
            return std::accumulate(args.begin(), args.end(), Purrs::Expr(1), [&m](const auto &x, const auto &y){
                return x * toPurrs(y, m);
            });
        },
        [&](const ArithModPtr mod) {
            return Purrs::mod(toPurrs(mod->getLhs(), m), toPurrs(mod->getRhs(), m));
        },
        [&](const ArithExpPtr e) {
            return Purrs::pwr(toPurrs(e->getBase(), m), toPurrs(e->getExponent(), m));
        });
}

std::optional<ArithExprPtr> solveTermFor(const ArithExprPtr e, const ArithVarPtr var) {
    // we can only solve linear expressions with rational coefficients
    if (!e->isLinear({{var}})) {
        return {};
    }
    const auto c {e->coeff(var)};
    if (!c || (*c)->is(0)) {
        return {};
    }
    const auto r {(*c)->isRational()};
    if (!r) {
        return {};
    }
    const auto monomial {(*c) * var->toExpr()};
    const auto not_normalized {e - monomial};
    const auto normalized {not_normalized->divide(-(***r))};
    return normalized;
}

ArithExprPtr fromPurrs(const Purrs::Expr &e, const purrs_var_map &map) {
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
        std::vector<ArithExprPtr> args;
        for (unsigned i = 0; i < e.nops(); ++i) {
            args.push_back(fromPurrs(e.op(i), map));
        }
        return mkPlus(std::move(args));
    }
    if (e.is_a_mul()) {
        std::vector<ArithExprPtr> args;
        for (unsigned i = 0; i < e.nops(); ++i) {
            args.push_back(fromPurrs(e.op(i), map));
        }
        return mkTimes(std::move(args));
    }
    if (e.is_a_power()) {
        return mkExp(fromPurrs(e.arg(0), map), fromPurrs(e.arg(1), map));
    }
    throw std::invalid_argument("unknown purrs expression " + toString(e));
}

}
