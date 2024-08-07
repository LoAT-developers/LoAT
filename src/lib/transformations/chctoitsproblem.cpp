#include "chctoitsproblem.hpp"
#include "linearize.hpp"

ITSPtr chcs_to_its(CHCProblem chcs) {
    if (!chcs.is_left_and_right_linear()) {
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
                for (const auto &x: c.get_premise()->args) {
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
            VarSet cVars;
            if (c.get_conclusion()) {
                for (const auto &var: c.get_conclusion()->args) {
                    cVars.insert(var);
                }
            }
            g->collectVars(cVars);
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
                for (const auto &arg: c.get_conclusion()->args) {
                    std::visit(
                        Overload{
                            [&](const Arith::Var var) {
                                up.put<Arith>(vars[int_arg], ren.get<Arith>(var));
                                ++int_arg;
                            },
                            [&](const Bools::Var var) {
                                up.put<Bools>(bvars[bool_arg], ren.get<Bools>(var));
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
            const auto lhs_loc = c.get_premise() ? its->getOrAddLocation(c.get_premise()->pred) : its->getInitialLocation();
            const auto rhs_loc = c.get_conclusion() ? its->getOrAddLocation(c.get_conclusion()->pred) : its->getSink();
            up.put<Arith>(its->getLocVar(), arith::mkConst(rhs_loc));
            const auto guard {ren(g) && theory::mkEq(its->getLocVar(), arith::mkConst(lhs_loc))};
            its->addRule(Rule(guard, up), lhs_loc);
        }
    }
    return its;
}
