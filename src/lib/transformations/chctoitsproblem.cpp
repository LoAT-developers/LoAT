#include "chctoitsproblem.hpp"
#include "linearize.hpp"
#include "config.hpp"

CHCToITS::CHCToITS(CHCPtr chcs): chcs(chcs) {}

CHCModel CHCToITS::transform_model(const ITSModel& its_m) const {
    CHCModel chc_m;
    const auto signature {chcs->get_signature()};
    for (const auto loc : its->getLocations()) {
        if (its->getInitialLocation() == loc || its->getSink() == loc) {
            continue;
        }
        const auto inv{its_m.get_invariant(loc)};
        const auto pred{its->getPrintableLocationName(loc)};
        const auto sig{signature.at(pred)};
        unsigned next_int_var{0};
        unsigned next_bool_var{0};
        std::vector<Var> args;
        for (const auto &x : sig) {
            switch (x) {
                case theory::Types::Int:
                    args.emplace_back(vars.at(next_int_var));
                    ++next_int_var;
                    break;
                case theory::Types::Bool:
                    args.emplace_back(bvars.at(next_bool_var));
                    ++next_bool_var;
                    break;
            }
        }
        chc_m.set_interpretation(Lhs::mk(pred, args), inv);
    }
    return chc_m;
}

ClausePtr CHCToITS::rule_to_clause(const RulePtr rule, const ClausePtr prototype) const {
    std::optional<LhsPtr> premise;
    std::optional<FunAppPtr> conclusion;
    Renaming renaming;
    if (const auto prem {prototype->get_premise()}) {
        std::vector<Var> args;
        size_t next_int_var {0};
        size_t next_bool_var {0};
        for (const auto &x: (*prem)->get_args()) {
            std::visit(
                Overload{
                    [&](const Arith::Var&) {
                        const auto y {vars.at(next_int_var)};
                        args.emplace_back(y);
                        renaming.insert(y, x);
                        ++next_int_var;
                    },
                    [&](const Bools::Var&) {
                        const auto y {bvars.at(next_bool_var)};
                        args.emplace_back(y);
                        renaming.insert(y, x);
                        ++next_bool_var;
                    }
                }, x
            );
        }
        premise = Lhs::mk((*prem)->get_pred(), args);
    }
    if (const auto conc {prototype->get_conclusion()}) {
        std::vector<Expr> args;
        size_t next_int_var {0};
        size_t next_bool_var {0};
        const auto &up {rule->getUpdate()};
        for (const auto &x: (*conc)->get_args()) {
            std::visit(
                Overload{
                    [&](const Arith::Expr&) {
                        args.emplace_back(up(vars.at(next_int_var)));
                        ++next_int_var;
                    },
                    [&](const Bools::Expr&) {
                        args.emplace_back(up(vars.at(next_bool_var)));
                        ++next_bool_var;
                    }
                }, x
            );
        }
        conclusion = FunApp::mk((*conc)->get_pred(), args);
    }
    const auto res {Clause::mk(premise, rule->getGuard(), conclusion)};
    return renaming.empty() ? res : res->rename_vars(renaming);
}

CHCCex CHCToITS::transform_cex(const ITSCex &cex) {
    CHCCex res {chcs};
    for (const auto &[rule, kind]: cex.get_used_rules()) {
        switch (kind) {
            case ProofStepKind::IMPLICANT: {
                const auto orig {cex.get_implicants().at(rule)};
                const auto it{clause_map.find(orig)};
                assert(it != clause_map.end());
                const auto orig_clause{it->second};
                const auto imp_clause{rule_to_clause(rule, orig_clause)};
                clause_map.emplace(rule, imp_clause);
                res.add_implicant(orig_clause, imp_clause);
                break;
            }
            case ProofStepKind::ACCEL: {
                const auto orig {cex.get_accel().at(rule)};
                const auto it{clause_map.find(orig)};
                assert(it != clause_map.end());
                const auto orig_clause{it->second};
                const auto accel_clause{rule_to_clause(rule, orig_clause)};
                clause_map.emplace(rule, accel_clause);
                res.add_accel(orig_clause, accel_clause);
                break;
            }
            case ProofStepKind::RESOLVENT: {
                const auto origs {cex.get_resolvents().at(rule)};
                std::vector<ClausePtr> orig_clauses;
                for (const auto &o: origs) {
                    orig_clauses.emplace_back(clause_map.at(o));
                }
                const auto prototype {Clause::mk(orig_clauses.front()->get_premise(), top(), orig_clauses.back()->get_conclusion())};
                const auto resolvent{rule_to_clause(rule, prototype)};
                clause_map.emplace(rule, resolvent);
                res.add_resolvent(orig_clauses, resolvent);
                break;
            }
            case ProofStepKind::ORIG: {
                break;
            }
        }
    }
    for (size_t i = 0; i < cex.num_transitions(); ++i) {
        Renaming ren;
        const auto trans {cex.get_transition(i)};
        const auto state {cex.get_state(i)};
        const auto clause {clause_map.at(trans)};
        if (const auto prem {clause->get_premise()}) {
            unsigned int_arg {0};
            unsigned bool_arg {0};
            for (const auto &x: (*prem)->get_args()) {
                std::visit(
                    Overload{
                        [&](const Arith::Var x) {
                            ren.insert<Arith>(x, vars[int_arg]);
                            ++int_arg;
                        },
                        [&](const Bools::Var x) {
                            ren.insert<Bools>(x, bvars[bool_arg]);
                            ++bool_arg;
                        }},
                    x);
            }
        }
        if (!res.try_step(state.composeBackwards(ren), clause)) {
            throw std::logic_error("transform_cex failed");
        }
    }
    return res;
}

ITSPtr CHCToITS::transform() {
    if (!chcs->is_left_linear()) {
        chcs = linearize(chcs);
    }
    unsigned max_int_arity {chcs->max_arity<Arith>()};
    unsigned max_bool_arity {chcs->max_arity<Bools>()};
    for (unsigned i = 0; i < max_int_arity; ++i) {
        vars.emplace_back(ArithVar::nextProgVar());
    }
    for (unsigned i = 0; i < max_bool_arity; ++i) {
        bvars.emplace_back(BoolVar::nextProgVar());
    }
    for (const auto &c: chcs->get_clauses()) {
        Renaming ren;
        // replace the arguments of the body predicate with the corresponding program variables
        unsigned bool_arg{0};
        unsigned int_arg{0};
        if (const auto prem {c->get_premise()}) {
            for (const auto &x : (*prem)->get_args()) {
                std::visit(
                    Overload{
                        [&](const Arith::Var x) {
                            ren.insert<Arith>(x, vars[int_arg]);
                            ++int_arg;
                        },
                        [&](const Bools::Var x) {
                            ren.insert<Bools>(x, bvars[bool_arg]);
                            ++bool_arg;
                        }},
                    x);
            }
        }
        bool_arg = 0;
        int_arg = 0;
        Subs up;
        if (const auto conc {c->get_conclusion()}) {
            for (const auto &arg : (*conc)->get_args()) {
                std::visit(
                    Overload{
                        [&](const Arith::Expr var) {
                            up.put<Arith>(vars[int_arg], var->renameVars(ren.get<Arith>()));
                            ++int_arg;
                        },
                        [&](const Bools::Expr var) {
                            up.put<Bools>(bvars[bool_arg], ren(var));
                            ++bool_arg;
                        }},
                    arg);
            }
            for (unsigned i = int_arg; i < max_int_arity; ++i) {
                up.put<Arith>(vars[i], ArithVar::next()->toExpr());
            }
            for (unsigned i = bool_arg; i < max_bool_arity; ++i) {
                up.put<Bools>(bvars[i], bools::mkLit(bools::mk(BoolVar::next())));
            }
        }
        const auto lhs_loc = c->get_premise() ? its->getOrAddLocation((*c->get_premise())->get_pred()) : its->getInitialLocation();
        const auto rhs_loc = c->get_conclusion() ? its->getOrAddLocation((*c->get_conclusion())->get_pred()) : its->getSink();
        up.put<Arith>(its->getLocVar(), arith::mkConst(rhs_loc));
        const auto guard{ren(c->get_constraint()) && theory::mkEq(its->getLocVar(), arith::mkConst(lhs_loc))};
        const auto rule {Rule::mk(guard, up)};
        if (Config::Analysis::model) {
            clause_map.emplace(rule, c);
        }
        its->addRule(rule, lhs_loc);
    }
    return its;
}
