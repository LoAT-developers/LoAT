#include "realqe.hpp"
#include "eliminate.h"
#include "mbputil.hpp"

Bools::Expr qe::real_qe(const Bools::Expr &trans, const ModelPtr &model, const std::function<bool(const Cell &)> &eliminate) {
    Bools::Expr res{trans};
    linked_hash_set<ArithVarPtr> arith_vars;
    for (const auto& x : trans->cells()) {
        if (eliminate(x)) {
            theory::apply(
                x,
                [&](const Bools::Var& x) {
                    res = mbp::bool_mbp(res, model, x);
                },
                [&](const ArithVarPtr& x) {
                    arith_vars.emplace(x);
                });
        }
    }
    if (!arith_vars.empty()) {
        res = fmplex::eliminate_variables(res, arith_vars);
#if DEBUG
        const auto vars {res->cells()};
        for (const auto &x: arith_vars) {
            assert(!vars.contains(x));
        }
#endif
    }
    return res;
}
