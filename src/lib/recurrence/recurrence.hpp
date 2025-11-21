#pragma once

#include <optional>

#include "theory.hpp"
#include "subs.hpp"
#include "variantmap.hpp"

class Recurrence {

public:

    using Idx = std::vector<Arith::Expr>;

    struct Result {
        Subs closed_form;
        Bools::Expr refinement {top()};
        unsigned int prefix {0};
    };

    static std::optional<Result> solve(const Subs &equations, const ArithVarPtr& n);

private:

    Recurrence(Subs equations, ArithVarPtr  n);

    std::optional<std::tuple<Int, Int, Arith::Expr>> handle_exp(const ArithExpPtr &pow) const;

    Arith::Expr compute_r(const Arith::Expr& q, const Rational &c);

    bool solve();

    bool solve(const ArithVarPtr& x, const Arith::Expr& rhs);

    bool solve(const Bools::Var &lhs, const Bools::Expr& rhs);

    std::optional<std::vector<ArithConstPtr>> compute_shift(const Idx& idx) const;

    Subs equations;

    const ArithVarPtr n;

    const Subs n_to_n_minus_one;

    linked_hash_map<ArithVarPtr, Arith::Expr> closed_form {};
    /**
     * Substitution map, mapping variables to their recurrence equations
     * @note the recurrence equations are valid *before* the transition is taken,
     * i.e. these are the terms for r(n-1) and _not_ for r(n) where r is the recurrence equation.
     */
    Variant<ArithVarPtr, Bools::Var>::Map<Arith::Expr, Bools::Expr> closed_form_n_minus_one {};

    Result result {};

    std::unordered_map<Cell, unsigned> prefixes {};

};
