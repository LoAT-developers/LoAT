#include "chctoitsproblem.hpp"

#include <utility>
#include "config.hpp"

CHCToITS::CHCToITS(CHCPtr  chcs): chcs(std::move(chcs)) {}

CHCModel CHCToITS::transform_model(const ITSModel& its_m) const {
    CHCModel chc_m;
    const auto signature {chcs->get_signature()};
    for (const auto loc : its->getLocations()) {
        if (its->getInitialLocation() == loc || its->getSink() == loc) {
            continue;
        }
        const auto inv{its_m.get_invariant(loc)};
        const auto pred{its->getPrintableLocationName(loc)};
        const auto& sig{signature.at(pred)};
        unsigned next_int_var{0};
        unsigned next_arr_var{0};
        unsigned next_bool_var{0};
        std::vector<Var> args;
        for (const auto& x : sig) {
            switch (x) {
            case theory::Type::Int:
                args.emplace_back(vars.at(next_int_var)->var());
                ++next_int_var;
                break;
            case theory::Type::Bool:
                args.emplace_back(bvars.at(next_bool_var));
                ++next_bool_var;
                break;
            case theory::Type::IntArray:
                args.emplace_back(avars.at(next_arr_var)->var());
                ++next_arr_var;
                break;
            }
        }
        chc_m.set_interpretation(pred, args, inv);
    }
    return chc_m;
}

ClausePtr CHCToITS::rule_to_clause(const RulePtr& rule, const ClausePtr& prototype) const {
    std::optional<FunAppPtr> premise;
    std::optional<FunAppPtr> conclusion;
    if (const auto prem {prototype->get_premise()}) {
        std::vector<Expr> args;
        size_t next_int_var {0};
        size_t next_arr_var {0};
        size_t next_bool_var {0};
        for (const auto& x : (*prem)->get_args()) {
            theory::apply(
                x,
                [&](const Arith::Expr&) {
                    const auto y{vars.at(next_int_var)};
                    args.emplace_back(y);
                    ++next_int_var;
                },
                [&](const Arrays<Arith>::Expr&) {
                    const auto y{avars.at(next_arr_var)};
                    args.emplace_back(theory::toExpr(y));
                    ++next_arr_var;
                },
                [&](const Bools::Expr&) {
                    const auto y{bvars.at(next_bool_var)};
                    args.emplace_back(theory::toExpr(y));
                    ++next_bool_var;
                }
            );
        }
        premise = FunApp::mk((*prem)->get_pred(), args);
    }
    if (const auto conc {prototype->get_conclusion()}) {
        std::vector<Expr> args;
        size_t next_int_var {0};
        size_t next_arr_var {0};
        size_t next_bool_var {0};
        const auto& up {rule->getUpdate()};
        for (const auto& x : (*conc)->get_args()) {
            theory::apply(
                x,
                [&](const Arith::Expr&) {
                    args.emplace_back(up(vars.at(next_int_var)));
                    ++next_int_var;
                },
                [&](const Arrays<Arith>::Expr&) {
                    args.emplace_back(up.get(avars.at(next_arr_var)));
                    ++next_arr_var;
                },
                [&](const Bools::Expr&) {
                    args.emplace_back(up(vars.at(next_bool_var)));
                    ++next_bool_var;
                }
            );
        }
        conclusion = FunApp::mk((*conc)->get_pred(), args);
    }
    return Clause::mk(premise, rule->getGuard(), conclusion);
}

CHCCex CHCToITS::transform_cex(const ITSSafetyCex &cex) {
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
            case ProofStepKind::RECURRENT_SET: {
                throw std::logic_error("recurrent sets are not supported for CHCs");
            }
        }
    }
    for (size_t i = 0; i < cex.num_transitions(); ++i) {
        const auto trans {cex.get_transition(i)};
        auto state {cex.get_state(i)};
        if (const auto it {renamings.find(trans)}; it != renamings.end()) {
            state = state->composeBackwards(it->second);
        }
        const auto clause {clause_map.at(trans)};
        res.do_step(state, clause);
    }
    return res;
}

ITSPtr CHCToITS::transform() {
    unsigned max_int_arity {chcs->max_arity<Arith>()};
    unsigned max_arr_arity {chcs->max_arity<Arrays<Arith>>()};
    unsigned max_bool_arity {chcs->max_arity<Bools>()};
    for (unsigned i = 0; i < max_int_arity; ++i) {
        vars.emplace_back(arrays::nextProgConst<Arith>());
    }
    for (unsigned i = 0; i < max_bool_arity; ++i) {
        bvars.emplace_back(BoolVar::nextProgVar());
    }
    for (unsigned i = 0; i < max_arr_arity; ++i) {
        avars.emplace_back(ArrayVar<Arith>::next(1));
    }
    for (const auto &c: chcs->get_clauses()) {
        Renaming renaming;
        std::vector constraints{c->get_constraint()};
        const auto lhs_loc = c->get_premise() ? its->getOrAddLocation((*c->get_premise())->get_pred()) : its->getInitialLocation();
        constraints.emplace_back(theory::mkEq(its->getLocVar(), arith::mkConst(lhs_loc)));
        // replace the arguments of the body predicate with the corresponding program variables
        unsigned bool_arg{0};
        unsigned arr_arg{0};
        unsigned int_arg{0};
        if (const auto prem{c->get_premise()}) {
            for (const auto& ex : (*prem)->get_args()) {
                theory::apply(
                    ex,
                    [&](const Arith::Expr& x) {
                        if (const auto var{x->isVar()}; var && !renaming.contains((*var)->var())) {
                            renaming.insert((*var)->var(), vars[int_arg]->var());
                        } else {
                            constraints.emplace_back(theory::mkEq(x, vars[int_arg]));
                        }
                        ++int_arg;
                    },
                    [&](const Arrays<Arith>::Expr& x) {
                        if (const auto var{x->isVar()}; var && !renaming.contains(*var)) {
                            renaming.insert(*var, avars[arr_arg]);
                        } else {
                            constraints.emplace_back(theory::mkEq(x, avars[arr_arg]));
                        }
                        ++arr_arg;
                    },
                    [&](const Bools::Expr& x) {
                        if (const auto var{x->isVar()}; var && !renaming.contains(*var)) {
                            renaming.insert(*var, bvars[bool_arg]);
                        } else {
                            constraints.emplace_back(theory::mkEq(x, theory::toExpr(bvars[bool_arg])));
                        }
                        ++bool_arg;
                    });
            }
        }
        bool_arg = 0;
        arr_arg = 0;
        int_arg = 0;
        Subs up;
        if (const auto conc{c->get_conclusion()}) {
            for (const auto &arg : (*conc)->get_args()) {
                theory::apply(
                    arg,
                    [&](const Arith::Expr& arg) {
                        const auto var {vars[int_arg]};
                        up.update(var, arg);
                        ++int_arg;
                    },
                    [&](const Arrays<Arith>::Expr& var) {
                        up.put(avars[arr_arg], var);
                        ++arr_arg;
                    },
                    [&](const Bools::Expr& var) {
                        up.put(bvars[bool_arg], var);
                        ++bool_arg;
                    });
            }
            for (unsigned i = int_arg; i < max_int_arity; ++i) {
                up.update(vars[i], arrays::nextConst<Arith>());
            }
            for (unsigned i = arr_arg; i < max_arr_arity; ++i) {
                up.update(vars[i], arrays::nextConst<Arith>());
            }
            for (unsigned i = bool_arg; i < max_bool_arity; ++i) {
                up.put(bvars[i], bools::mkLit(bools::mk(BoolVar::next())));
            }
        }
        const auto rhs_loc = c->get_conclusion() ? its->getOrAddLocation((*c->get_conclusion())->get_pred()) : its->getSink();
        const auto loc_var {its->getLocVar()->var()};
        up.writeConst(loc_var, arith::mkConst(rhs_loc));
        const auto rule{Rule::mk(bools::mkAnd(constraints), up)->renameVars(renaming)};
        if (Config::Analysis::model) {
            clause_map.emplace(rule, c);
            renamings.emplace(rule, renaming);
        }
        its->addRule(rule, lhs_loc);
    }
    return its;
}
