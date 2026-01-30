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
        std::unordered_map<size_t, unsigned> next_arr_var;
        unsigned next_bool_var{0};
        std::vector<Var> args;
        for (const auto& [base, dim] : sig) {
            switch (base) {
            case theory::BaseType::Int:
                if (dim == 0) {
                    args.emplace_back(vars.at(next_int_var)->var());
                    ++next_int_var;
                } else {
                    args.emplace_back(avars.at(dim).at(next_int_var));
                    ++next_arr_var.emplace(dim, 0).first->second;
                }
                break;
            case theory::BaseType::Bool:
                args.emplace_back(bvars.at(next_bool_var));
                ++next_bool_var;
                break;
            }
        }
        chc_m.set_interpretation(pred, args, inv);
    }
    return chc_m;
}

ClausePtr CHCToITS::rule_to_clause(const RulePtr& rule, const ClausePtr& prototype) const {
    std::vector<FunAppPtr> premise;
    std::optional<FunAppPtr> conclusion;
    for (const auto& prem: prototype->get_premise()) {
        std::vector<Expr> args;
        size_t next_int_var {0};
        std::unordered_map<size_t, unsigned> next_arr_var;
        size_t next_bool_var {0};
        for (const auto& x : prem->get_args()) {
            theory::apply(
                x,
                [&](const Arith::Expr&) {
                    const auto y{vars.at(next_int_var)};
                    args.emplace_back(y);
                    ++next_int_var;
                },
                [&](const Arrays<Arith>::Expr& e) {
                    const auto& vec{avars.at(e->dim())};
                    auto& next = next_arr_var.emplace(e->dim(), 0).first->second;
                    args.emplace_back(vec.at(next));
                    ++next;
                },
                [&](const Bools::Expr&) {
                    const auto y{bvars.at(next_bool_var)};
                    args.emplace_back(bools::mkLit(bools::mk(y)));
                    ++next_bool_var;
                }
            );
        }
        premise.emplace_back(FunApp::mk(prem->get_pred(), args));
    }
    if (const auto conc {prototype->get_conclusion()}) {
        std::vector<Expr> args;
        size_t next_int_var {0};
        std::unordered_map<size_t, unsigned> next_arr_var;
        size_t next_bool_var {0};
        const auto& up {rule->getUpdate()};
        for (const auto& x : (*conc)->get_args()) {
            theory::apply(
                x,
                [&](const Arith::Expr&) {
                    args.emplace_back(up(vars.at(next_int_var)));
                    ++next_int_var;
                },
                [&](const Arrays<Arith>::Expr& e) {
                    const auto& vec = avars.at(e->dim());
                    auto& next = next_arr_var.emplace(e->dim(), 0).first->second;
                    args.emplace_back(up.get(vec.at(next)));
                    ++next;
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
    const auto max_int_arity = chcs->max_arity(theory::Type::Int);
    const auto max_dim = chcs->max_dim(theory::BaseType::Int);
    const auto max_bool_arity = chcs->max_arity(theory::Type::Bool);
    for (unsigned i = 0; i < max_int_arity; ++i) {
        vars.emplace_back(arrays::nextProgConst<Arith>());
    }
    for (unsigned i = 0; i < max_bool_arity; ++i) {
        bvars.emplace_back(BoolVar::nextProgVar());
    }
    for (size_t i = 1; i <= max_dim; ++i) {
        if (const auto max_arity = chcs->max_arity(theory::Type(theory::BaseType::Int, i)); max_arity > 0) {
            auto& vec = avars.emplace(i, std::vector<Arrays<Arith>::Var>()).first->second;
            for (size_t j = 0; j < max_arity; ++j) {
                vec.emplace_back(ArrayVar<Arith>::nextProgVar(i));
            }
        }
    }
    for (const auto &c: chcs->get_clauses()) {
        if (!c->is_linear()) {
            throw std::invalid_argument("non-linear clauses cannot be transformed to transition systems");
        }
        Renaming renaming;
        const auto premise = c->get_premise();
        std::vector constraints{c->get_constraint()};
        const auto lhs_loc = premise.empty() ? its->getInitialLocation() : its->getOrAddLocation(premise.front()->get_pred());
        constraints.emplace_back(Arith::mkEq(its->getLocVar(), arith::mkConst(lhs_loc)));
        // replace the arguments of the body predicate with the corresponding program variables
        unsigned bool_premise_arity{0};
        std::unordered_map<size_t, size_t> arr_premise_arity;
        unsigned int_premise_arity{0};
        for (const auto& prem: premise) {
            for (const auto& ex : prem->get_args()) {
                theory::apply(
                    ex,
                    [&](const Arith::Expr& x) {
                        if (const auto var{x->isVar()}; var && !renaming.contains((*var)->var())) {
                            renaming.insert((*var)->var(), vars[int_premise_arity]->var());
                        } else {
                            constraints.emplace_back(Arith::mkEq(x, vars[int_premise_arity]));
                        }
                        ++int_premise_arity;
                    },
                    [&](const Arrays<Arith>::Expr& x) {
                        const auto dim = x->dim();
                        auto& arity = arr_premise_arity.emplace(dim, 0).first->second;
                        const auto& vec = avars.at(dim);
                        if (const auto var{x->isVar()}; var && !renaming.contains(*var)) {
                            renaming.insert(*var, vec[arity]);
                        } else {
                            constraints.emplace_back(Arrays<Arith>::mkEq(x, vec[arity]));
                        }
                        ++arity;
                    },
                    [&](const Bools::Expr& x) {
                        if (const auto var{x->isVar()}; var && !renaming.contains(*var)) {
                            renaming.insert(*var, bvars[bool_premise_arity]);
                        } else {
                            constraints.emplace_back(Bools::mkEq(x, bools::mkLit(bools::mk(bvars[bool_premise_arity]))));
                        }
                        ++bool_premise_arity;
                    });
            }
        }
        Subs up;
        if (const auto conc{c->get_conclusion()}) {
            unsigned int_arg = 0;
            std::unordered_map<size_t, size_t> arr_arg;
            unsigned bool_arg = 0;
            for (const auto &arg : (*conc)->get_args()) {
                theory::apply(
                    arg,
                    [&](const Arith::Expr& arg) {
                        const auto var {vars[int_arg]};
                        up.update(var, arg);
                        ++int_arg;
                    },
                    [&](const Arrays<Arith>::Expr& var) {
                        const auto dim = var->dim();
                        const auto& vec = avars.at(dim);
                        auto& arg = arr_arg.emplace(dim, 0).first->second;
                        up.put(vec[arg], var);
                        ++arg;
                    },
                    [&](const Bools::Expr& var) {
                        up.put(bvars[bool_arg], var);
                        ++bool_arg;
                    });
            }
            for (unsigned i = int_arg; i < int_premise_arity; ++i) {
                up.update(vars[i], arrays::nextConst<Arith>());
            }
            for (size_t i = 1; i <= max_dim; ++i) {
                if (const auto max = arr_premise_arity.emplace(i, 0).first->second; max > 0) {
                    const auto& vec = avars.at(i);
                    for (unsigned j = arr_arg.emplace(i, 0).first->second; j < max; ++j) {
                        up.put(vec[j], ArrayVar<Arith>::next(i));
                    }
                }
            }
            for (unsigned i = bool_arg; i < bool_premise_arity; ++i) {
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
