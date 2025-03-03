#include "realqe.hpp"
#include "eliminate.h"
#include "mbputil.hpp"

Bools::Expr qe::real_qe(const Bools::Expr &trans, const Model &model, const std::function<bool(const Var &)> &eliminate) {
    Bools::Expr res{trans};
    linked_hash_set<Arith::Var> arith_vars;
    for (const auto &x : trans->vars()) {
        if (eliminate(x)) {
            theory::apply(
                x,
                [&](const Bools::Var x) {
                    res = mbp::bool_mbp(res, model, x);
                },
                [&](const Arith::Var x) {
                    arith_vars.emplace(x);
                });
        }
    }
    if (!arith_vars.empty()) {
        res = fmplex::eliminate_variables(res, arith_vars);
        const auto vars {res->vars()};
        for (const auto &x: arith_vars) {
            assert(!vars.contains(x));
        }
    }
    return res;
}