#pragma once

#include <optional>

#include "theory.hpp"
#include "subs.hpp"

class Recurrence {
private:

public:

    struct Result {
        Subs closed_form {};
        unsigned int prefix {0};
    };

    static std::optional<Result> solve(const Subs &equations, const Arith::Var n);

    static void solve(const std::string &eq);

private:

    Recurrence(const Subs &subs, const Arith::Var n);

    std::optional<std::tuple<Int, Int, Arith::Expr>> handle_exp(const ArithExpPtr &pow);

    Arith::Expr compute_r(const Arith::Expr cs, const Rational &c);

    bool solve();

    bool solve(const Arith::Var lhs, const Arith::Expr rhs);

    bool solve(const Bools::Var &lhs, const Bools::Expr rhs);

    Subs equations;

    const Arith::Var n;

    /**
     * Substitution map, mapping variables to their recurrence equations
     * @note the recurrence equations are valid *before* the transition is taken,
     * i.e. these are the terms for r(n-1) and _not_ for r(n) where r is the recurrence equation.
     */
    Subs closed_form_n_minus_one {};

    Result result {};

    std::unordered_map<Var, unsigned> prefixes {};

};
