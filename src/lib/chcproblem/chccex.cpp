#include "chccex.hpp"

#include <ranges>
#include <stack>
#include <utility>

#include "formulapreprocessing.hpp"

CHCCex::CHCCex(CHCPtr chcs): chcs(std::move(chcs)) {}

void CHCCex::do_step(const ModelPtr &m, const ClausePtr &c) {
    states.emplace_back(m);
    transitions.emplace_back(c);
}

void CHCCex::add_accel(const ClausePtr &loop, const ClausePtr &res) {
    accel.emplace(res, loop);
}

void CHCCex::add_recurrent_set(const ClausePtr &loop, const ClausePtr &res) {
    recurrent_set.emplace(res, loop);
}

void CHCCex::add_resolvent(const std::vector<ClausePtr> &rules, const ClausePtr &res) {
    resolvents.emplace(res, rules);

}

void CHCCex::add_implicant(const ClausePtr &rule, const ClausePtr &imp) {
    implicants.emplace(imp, rule);
}

std::vector<std::pair<ClausePtr, ProofStepKind>> CHCCex::get_used_clauses() const {
    linked_hash_set<ClausePtr> done;
    std::stack<ClausePtr> todo;
    std::vector<std::pair<ClausePtr, ProofStepKind>> derived;
    for (const auto & transition : std::ranges::reverse_view(transitions)) {
        todo.push(transition);
    }
    while (!todo.empty()) {
        const auto t{todo.top()};
        auto ready {true};
        if (!done.contains(t)) {
            if (const auto loop{accel.get(t)}) {
                if ((ready = done.contains(*loop))) {
                    derived.emplace_back(t, ProofStepKind::ACCEL);
                } else {
                    todo.push(*loop);
                }
            } else if (const auto orig{recurrent_set.get(t)}) {
                if ((ready = done.contains(*orig))) {
                    derived.emplace_back(t, ProofStepKind::RECURRENT_SET);
                } else {
                    todo.push(*orig);
                }
            } else if (const auto orig{implicants.get(t)}) {
                if ((ready = done.contains(*orig))) {
                    derived.emplace_back(t, ProofStepKind::IMPLICANT);
                } else {
                    todo.push(*orig);
                }
            } else if (const auto rules{resolvents.get(t)}) {
                for (const auto &r : *rules) {
                    if (!done.contains(r)) {
                        todo.push(r);
                        ready = false;
                    }
                }
                if (ready) {
                    derived.emplace_back(t, ProofStepKind::RESOLVENT);
                }
            } else {
                derived.emplace_back(t, ProofStepKind::ORIG);
            }
        }
        if (ready) {
            done.insert(t);
            todo.pop();
        }
    }
    return derived;
}

Bools::Expr unify(const FunAppPtr &f1, const FunAppPtr &f2) {
    BoolExprSet conjuncts;
    for (unsigned j = 0; j < f1->get_args().size(); ++j) {
        const auto last_arg = f1->get_args()[j];
        const auto current_arg = f2->get_args()[j];
        theory::apply(
            last_arg,
            [&](const Arith::Expr &last_arg) {
                conjuncts.insert(bools::mkLit(arith::mkEq(
                    last_arg, std::get<Arith::Expr>(current_arg))));
            },
            [&](const Bools::Expr &last_arg) {
                conjuncts.insert(Bools::mkEq(
                    last_arg, std::get<Bools::Expr>(current_arg)));
            },
            [&](const Arrays<Arith>::Expr &last_arg) {
                conjuncts.insert(bools::mkLit(arrays::mkEq(
                    last_arg,
                    std::get<Arrays<Arith>::Expr>(current_arg))));
            });
    }
    return bools::mkAnd(conjuncts);
}

linked_hash_map<ClausePtr, std::vector<std::pair<ClausePtr, Bools::Expr>>> CHCCex::get_reachability_sets() const {
    const auto get_renaming = [&](const ClausePtr &c, const ClausePtr &d, const Bools::Expr &e) {
        Renaming ren;
        VarSet vars;
        c->collect_vars(vars);
        d->collect_vars(vars);
        e->collectVars(vars);
        for (const auto &x: vars) {
            theory::apply(x, [&](const auto &x) {
                Renaming::renameVar(x, ren);
            });
        }
        return ren;
    };
    const auto rename = [&](const ClausePtr &c) {
        Renaming ren;
        VarSet vars;
        c->collect_vars(vars);
        for (const auto &x: vars) {
            theory::apply(x, [&](const auto &x) {
                Renaming::renameVar(x, ren);
            });
        }
        return c->rename_vars(ren);
    };
    const auto simplify = [&](const ClausePtr& derived_clause, const ClausePtr& d, const BoolExprSet& conjuncts) {
        VarSet keep;
        derived_clause->collect_vars(keep);
        d->collect_vars(keep);
        return Preprocess::preprocessFormula(bools::mkAnd(conjuncts), [&](const auto& x) {
            return !keep.contains(x);
        });
    };
    // if res[c]=[c',d,b], then c' is a variant of c, and if sigma(c') is used and in the proof and (the existential
    // closure of) sigma(b) holds, then we consider sigma(d) to be reachable
    linked_hash_map<ClausePtr, std::vector<std::pair<ClausePtr, Bools::Expr> > > res;
    const auto used = get_used_clauses();
    for (const auto &[derived_clause,k]: used) {
        switch (k) {
            case ProofStepKind::ORIG:
            case ProofStepKind::IMPLICANT: {
                res.put(derived_clause, std::vector({std::pair(derived_clause, derived_clause->get_constraint())}));
                break;
            }
            case ProofStepKind::RESOLVENT: {
                const auto cs = resolvents.at(derived_clause);
                // compute fresh variants of all clauses that were used for resolution
                std::vector<ClausePtr> variants;
                for (const auto &c: cs) {
                    assert(c->is_linear());
                    variants.push_back(rename(c));
                }
                // enforce that these variants unify
                BoolExprSet unification_conditions;
                for (unsigned i = 0; i < variants.size() - 1; ++i) {
                    unification_conditions.insert(unify(variants.at(i)->get_conclusion().value(),
                                                         variants.at(i + 1)->get_premise().front()));
                }
                if (!derived_clause->is_fact()) {
                    unification_conditions.insert(unify(derived_clause->get_premise().front(),
                                                         variants.front()->get_premise().front()));
                }
                if (!derived_clause->is_query()) {
                    unification_conditions.insert(unify(derived_clause->get_conclusion().value(),
                                                         variants.back()->get_conclusion().value()));
                }
                // take clauses that get reachable by using elements of cs into account
                std::vector<std::pair<ClausePtr, Bools::Expr> > vec;
                for (unsigned i = 0; i < cs.size(); ++i) {
                    const auto& v = variants.at(i);
                    for (auto [d, b]: res.at(cs.at(i))) {
                        // if c is used in the proof, then d is reachable, provided that b holds
                        // compute fresh variants to avoid name clashes
                        const auto ren = get_renaming(cs.at(i), d, b);
                        const auto c = cs.at(i)->rename_vars(ren);
                        d = d->rename_vars(ren);
                        b = b->renameVars(ren);
                        // collect the conditions that imply reachability of d
                        // (A) the clauses used for resolution must unify
                        BoolExprSet conjuncts = unification_conditions;
                        // (B) the condition for reachability of d must hold
                        conjuncts.insert(b);
                        // (C) the left-hand sides of c and its variant must unify
                        if (!c->is_fact()) {
                            conjuncts.insert(unify(c->get_premise().front(), v->get_premise().front()));
                        }
                        // (D) the right-hand sides of c and its variant must unify
                        if (!c->is_query()) {
                            conjuncts.insert(unify(c->get_conclusion().value(), v->get_conclusion().value()));
                        }
                        vec.emplace_back(d, simplify(derived_clause, d, conjuncts));
                    }
                }
                res.put(derived_clause, vec);
                break;
            }
            case ProofStepKind::ACCEL: {
                const auto loop = accel.at(derived_clause);
                const auto cond = derived_clause->get_constraint();
                std::vector<std::pair<ClausePtr, Bools::Expr> > vec;
                for (auto [d, b]: res.at(loop)) {
                    const auto ren = get_renaming(loop, d, b);
                    const auto c = loop->rename_vars(ren);
                    d = d->rename_vars(ren);
                    b = b->renameVars(ren);
                    BoolExprSet conjuncts;
                    conjuncts.insert(b);
                    conjuncts.insert(cond);
                    conjuncts.insert(unify(c->get_premise().front(), loop->get_premise().front()));
                    conjuncts.insert(unify(c->get_conclusion().value(), loop->get_conclusion().value()));
                    vec.emplace_back(d, simplify(derived_clause, d, conjuncts));
                }
                res.put(derived_clause, vec);
                break;
            }
            case ProofStepKind::RECURRENT_SET: {
                const auto loop = recurrent_set.at(derived_clause);
                const auto unif = unify(loop->get_premise().front(), derived_clause->get_premise().front());
                const auto cond = derived_clause->get_constraint() && unif;
                std::vector<std::pair<ClausePtr, Bools::Expr> > vec;
                for (auto [d, b]: res.at(loop)) {
                    const auto ren = get_renaming(loop, d, b);
                    const auto c = loop->rename_vars(ren);
                    d = d->rename_vars(ren);
                    b = b->renameVars(ren);
                    BoolExprSet conjuncts;
                    conjuncts.insert(b);
                    conjuncts.insert(cond);
                    conjuncts.insert(unify(c->get_premise().front(), loop->get_premise().front()));
                    conjuncts.insert(unify(c->get_conclusion().value(), loop->get_conclusion().value()));
                    vec.emplace_back(d, simplify(derived_clause, d, conjuncts));
                }
                res.put(derived_clause, vec);
                break;
            }
            default: throw std::logic_error("unknown proof step");
        }
    }
    for (const auto& [f,vec]: res) {
        std::cout << "reachability sets for " << f << std::endl;
        for (const auto& [k,v]: vec) {
            std::cout << k << ": " << v << std::endl;
        }
    }
    return res;
}

std::unordered_map<std::string, std::pair<FunAppPtr, BoolExprSet>> CHCCex::to_recurrent_set() const {

    const auto instantiate = [](const FunAppPtr& f, const ModelPtr& m) {
        Subs subs;
        for (const auto& x: f->get_args()) {
            theory::apply(x, [&](const Arrays<Arith>::Expr& x) {
                if (x->isVar() && x->dim() == 0) {
                    subs.writeConst(x->var(), arith::mkConst(m->eval(arrays::readConst(x))));
                }
            }, [&](const Bools::Expr& x) {
                if (const auto var = x->isVar()) {
                    subs.put(var.value(), m->eval(x) ? top() : bot());
                }
            }, [&](const Arith::Expr& x) {
                if (const auto var = x->isVar()) {
                    subs.writeConst(var.value()->var(), arith::mkConst(m->eval(x)));
                }
            });
        }
        return f->subs(subs);
    };

    const auto simplify = [&](const FunAppPtr& p, const Bools::Expr& e) {
        const auto keep = p->vars();
        return Preprocess::preprocessFormula(e, [&](const auto& x) {
            return !keep.contains(x);
        });
    };

    const auto mk_template = [&](const FunAppPtr& f) {
        std::vector<Expr> args;
        for (const auto &x: f->get_args()) {
            theory::apply(
                x, [&](const Arrays<Arith>::Expr &x) {
                    args.push_back(Arrays<Arith>::next(x->dim()));
                },
                [&](const Bools::Expr &) {
                    args.push_back(bools::mkLit(bools::mk(Bools::next(0))));
                },
                [&](const Arith::Expr &) {
                    args.push_back(arrays::nextConst<Arith>());
                });
        }
        return FunApp::mk(f->get_pred(), args);
    };

    std::unordered_map<std::string, std::pair<FunAppPtr, BoolExprSet>> res;

    const auto init = [&](const FunAppPtr& f) -> std::pair<FunAppPtr, BoolExprSet>& {
        return res.emplace(f->get_pred(), std::pair{mk_template(f), BoolExprSet()}).first->second;
    };

    const auto reachability_sets = get_reachability_sets();
    for (unsigned i = 0; i < transitions.size(); ++i) {
        const auto t = transitions.at(i);
        std::cout << "processing " << t << std::endl;
        const auto from = states.at(i);
        if (recurrent_set.contains(t)) {
            for (const auto& [d, b]: reachability_sets.at(t)) {
                const auto premise = d->get_premise().front();
                auto &[p, c] = init(premise);
                std::cout << "adding " << p << " -> " << simplify(p, b && unify(p, premise)) << std::endl;
                c.insert(simplify(p, b && unify(p, premise)));
            }
        } else {
            const auto to = states.at(i+1);
            if (accel.contains(t)) {
                const auto spec = instantiate(transitions.at(i+1)->get_premise().front(), to);
                const auto unif = unify(t->get_conclusion().value(), spec);
                for (const auto& [d, b]: reachability_sets.at(t)) {
                    const auto conc = d->get_conclusion().value();
                    auto &[p, c] = init(conc);
                    std::cout << "spec: " << spec << std::endl;
                    std::cout << "adding " << p << " -> " << (b && unify(p, conc) && unif) << std::endl;
                    c.insert(b && unify(p, conc) && unif);
                }
            } else {
                for (const auto& [d, b]: reachability_sets.at(t)) {
                    if (!t->is_fact()) {
                        const auto premise = d->get_premise().front();
                        const auto premise_spec = instantiate(premise, from);
                        auto &[p, c] = init(premise);
                        std::cout << "adding " << p << " -> " << simplify(p, b && unify(p, premise_spec)) << std::endl;
                        c.insert(simplify(p, b && unify(p, premise_spec)));
                    }
                    const auto conc = d->get_conclusion().value();
                    const auto conc_spec = instantiate(conc, to);
                    auto &[p, c] = init(conc);
                    std::cout << "adding " << p << " -> " << simplify(p, b && unify(p, conc_spec)) << std::endl;
                    c.insert(simplify(p, b && unify(p, conc_spec)));
                }
            }
        }
    }
    for (const auto &[f,b]: res | std::views::values) {
        std::cout << f << std::endl;
        std::cout << bools::mkOr(b) << std::endl;
    }
    return res;
}

std::ostream& operator<<(std::ostream &s, const CHCCex &cex) {
    const auto derived{cex.get_used_clauses()};
    std::unordered_map<ClausePtr, unsigned> indices;
    unsigned next {0};
    s << "clauses:" << std::endl;
    for (const auto &[t, kind]: derived) {
        indices.emplace(t, next);
        s << "\t" << next << ": " << t << std::endl;
        switch (kind) {
            case ProofStepKind::ORIG: {
                s << "\t\toriginal clause (modulo variable renaming)" << std::endl;
                break;
            }
            case ProofStepKind::IMPLICANT: {
                s << "\t\tderived from " << indices.at(cex.implicants.at(t)) << " (implicant)\n";
                break;
            }
            case ProofStepKind::ACCEL: {
                s << "\t\tderived from " << indices.at(cex.accel.at(t)) << " (acceleration)" << std::endl;
                break;
            }
            case ProofStepKind::RESOLVENT: {
                s << "\t\t" << "resolve(";
                auto first{true};
                for (const auto &r : cex.resolvents.at(t)) {
                    if (first) {
                        s << indices.at(r);
                        first = false;
                    } else {
                        s << ", " << indices.at(r);
                    }
                }
                s << ") = " << next << std::endl;
                break;
            }
            case ProofStepKind::RECURRENT_SET: {
                s << "\t\tderived from " << indices.at(cex.recurrent_set.at(t)) << " (recurrent set)" << std::endl;
                break;
            }
        }
        ++next;
    }
    s << "\nproof:" << std::endl;
    VarSet prog_vars;
    for (size_t i = 0; i < cex.transitions.size(); ++i) {
        const auto &clause{cex.transitions.at(i)};
        s << "\t" << clause << cex.states.at(i)->toString(clause->vars()) << " by " << indices.at(clause) << "\n";
    }
    return s;
}

const linked_hash_map<ClausePtr, ClausePtr>& CHCCex::get_accel() const {
    return accel;
}

const linked_hash_map<ClausePtr, ClausePtr>& CHCCex::get_implicants() const {
    return implicants;
}

const linked_hash_map<ClausePtr, std::vector<ClausePtr>>& CHCCex::get_resolvents() const {
    return resolvents;
}

const std::vector<ClausePtr>& CHCCex::get_transitions() const {
    return transitions;
}

const std::vector<ModelPtr>& CHCCex::get_states() const {
    return states;
}

