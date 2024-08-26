#include "chctoitsproblem.hpp"
#include "linearize.hpp"

ReversibleCHCToITS::ReversibleCHCToITS(
    const ITSPtr its,
    const linked_hash_map<std::string, std::vector<theory::Types>> &signature,
    const std::vector<Arith::Var> &arith_vars,
    const std::vector<Bools::Var> &bool_vars):
    Reversible<ITSPtr, ITSModel, CHCModel>(its),
    signature(signature),
    arith_vars(arith_vars),
    bool_vars(bool_vars) {}

CHCModel ReversibleCHCToITS::revert_model(const ITSModel& its_m) const {
    CHCModel chc_m;
    for (const auto loc : res->getLocations()) {
        if (res->getInitialLocation() == loc || res->getSink() == loc) {
            continue;
        }
        const auto inv{its_m.get_invariant(loc)};
        const auto pred{res->getPrintableLocationName(loc)};
        const auto sig{signature.at(pred)};
        unsigned next_int_var{0};
        unsigned next_bool_var{0};
        std::vector<Var> args;
        for (const auto &x : sig) {
            switch (x) {
                case theory::Types::Int:
                    args.emplace_back(arith_vars.at(next_int_var));
                    ++next_int_var;
                    break;
                case theory::Types::Bool:
                    args.emplace_back(bool_vars.at(next_bool_var));
                    ++next_bool_var;
                    break;
            }
        }
        chc_m.set_interpretation(Lhs(pred, args), inv);
    }
    return chc_m;
}

ReversibleCHCToITS chcs_to_its(CHCProblem chcs) {
    if (!chcs.is_left_linear()) {
        chcs = linearize(chcs);
    }
    ITSPtr its {std::make_shared<ITSProblem>()};
    unsigned max_int_arity {chcs.max_arity<Arith>()};
    unsigned max_bool_arity {chcs.max_arity<Bools>()};
    std::vector<Arith::Var> vars;
    std::vector<Bools::Var> bvars;
    for (unsigned i = 0; i < max_int_arity; ++i) {
        vars.emplace_back(ArithVar::nextProgVar());
    }
    for (unsigned i = 0; i < max_bool_arity; ++i) {
        bvars.emplace_back(BoolVar::nextProgVar());
    }
    for (const Clause &c: chcs.get_clauses()) {
        const auto disjuncts = c.get_constraint()->isOr() ? c.get_constraint()->getChildren() : BoolExprSet{c.get_constraint()};
        for (const auto &g: disjuncts) {
            Subs ren;
            // replace the arguments of the body predicate with the corresponding program variables
            unsigned bool_arg {0};
            unsigned int_arg {0};
            if (c.get_premise()) {
                for (const auto &x: c.get_premise()->get_args()) {
                    std::visit(
                        Overload{
                            [&](const Arith::Var x) {
                                ren.put<Arith>(x, vars[int_arg]);
                                ++int_arg;
                            },
                            [&](const Bools::Var x) {
                                ren.put<Bools>(x, bools::mkLit(bools::mk(bvars[bool_arg])));
                                ++bool_arg;
                            }},
                        x);
                }
            }
            VarSet cVars {g->vars()};
            // replace all other variables from the clause with temporary variables
            for (const auto &x: cVars) {
                if (!ren.contains(x)) {
                    std::visit(
                        Overload{
                            [&](const auto var) {
                                const auto th{theory::theory(var)};
                                ren.put<decltype(th)>(var, th.varToExpr(var->next()));
                            }},
                        x);
                }
            }
            bool_arg = 0;
            int_arg = 0;
            Subs up;
            if (c.get_conclusion()) {
                for (const auto &arg: c.get_conclusion()->get_args()) {
                    std::visit(
                        Overload{
                            [&](const Arith::Expr var) {
                                up.put<Arith>(vars[int_arg], ren.get<Arith>()(var));
                                ++int_arg;
                            },
                            [&](const Bools::Expr var) {
                                up.put<Bools>(bvars[bool_arg], ren(var));
                                ++bool_arg;
                            }},
                        arg);
                }
            }
            for (unsigned i = int_arg; i < max_int_arity; ++i) {
                up.put<Arith>(vars[i], ArithVar::next()->toExpr());
            }
            for (unsigned i = bool_arg; i < max_bool_arity; ++i) {
                up.put<Bools>(bvars[i], bools::mkLit(bools::mk(BoolVar::next())));
            }
            const auto lhs_loc = c.get_premise() ? its->getOrAddLocation(c.get_premise()->get_pred()) : its->getInitialLocation();
            const auto rhs_loc = c.get_conclusion() ? its->getOrAddLocation(c.get_conclusion()->get_pred()) : its->getSink();
            up.put<Arith>(its->getLocVar(), arith::mkConst(rhs_loc));
            const auto guard {ren(g) && theory::mkEq(its->getLocVar(), arith::mkConst(lhs_loc))};
            its->addRule(Rule(guard, up), lhs_loc);
        }
    }
    return ReversibleCHCToITS(its, chcs.get_signature(), vars, bvars);
}
