#include "realqe.hpp"
#include "eliminate.h"
#include "mbputil.hpp"
#include "smtfactory.hpp"

Conjunction qe::real_qe(const Conjunction &trans, const Model &model, const std::function<bool(const Var &)> &eliminate) {
    auto res {trans};
    const auto bool_vars {res.vars().get<Bools::Var>()};
    for (const auto &x : bool_vars) {
        if (eliminate(x)) {
            mbp::bool_mbp(res, model, x);
        }
    }
    const auto arith_vars {res.vars().get<Arith::Var>()};
    if (!arith_vars.empty()) {
        fmplex::eliminate_variables(res.get<Arith::Lit>(), arith_vars);
        assert(res.vars().get<Arith::Var>().empty());
    }
}
