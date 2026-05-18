#include "chccex.hpp"

#include <ranges>
#include <stack>
#include <utility>

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

linked_hash_map<ClausePtr, linked_hash_map<FunAppPtr, Bools::Expr>> CHCCex::get_reachability_sets() const {
    const auto unify = [](const FunAppPtr& f1, const FunAppPtr& f2) {
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
    };
    const auto get_renaming = [&](const FunAppPtr& f, const Bools::Expr& e) {
        Renaming ren;
        VarSet vars;
        f->collect_vars(vars);
        e->collectVars(vars);
        for (const auto &x: vars) {
            theory::apply(x, [&](const auto &x) {
                Renaming::renameVar(x, ren);
            });
        }
        return ren;
    };
    linked_hash_map<ClausePtr, linked_hash_map<FunAppPtr, Bools::Expr>> res;
    const auto used = get_used_clauses();
    for (const auto& [c,k]: used) {
        switch (k) {
            case ProofStepKind::ORIG:
            case ProofStepKind::IMPLICANT: {
                res.emplace(c, linked_hash_map<FunAppPtr, Bools::Expr>({std::pair(c->get_conclusion().value(), c->get_constraint())}));
                break;
            }
            case ProofStepKind::RESOLVENT: {
                const auto cs = resolvents.at(c);
                linked_hash_map<FunAppPtr, Bools::Expr> map = res.at(cs.back());
                assert(cs.back()->is_linear());
                auto last_pred = cs.back()->get_premise().front();
                const auto unif = unify(c->get_conclusion().value(), cs.back()->get_conclusion().value());
                const auto cond = c->get_constraint() && unif;
                for (unsigned i = cs.size() - 2; i > 0; --i) {
                    const auto clause = cs.at(i);
                    assert(clause->is_linear());
                    for (auto [p,c]: res.at(clause)) {
                        const auto ren = get_renaming(p,c);
                        const auto unif = unify(last_pred, clause->get_conclusion().value()->rename_vars(ren));
                        // avoid accidental overwrites
                        const auto old_cond = map.get(p).value_or(bot());
                        BoolExprSet conjuncts;
                        conjuncts.emplace(unif);
                        conjuncts.emplace(cond);
                        conjuncts.emplace(c->renameVars(ren));
                        map.put(p->rename_vars(ren), old_cond || bools::mkAnd(conjuncts));
                    }
                    last_pred = cs.at(i)->get_premise().front();
                }
                res.emplace(c, map);
                break;
            }
            case ProofStepKind::ACCEL: {
                const auto loop = accel.at(c);
                const auto cond = c->get_constraint();
                linked_hash_map<FunAppPtr, Bools::Expr> map;
                for (const auto &[k, v]: res.at(loop)) {
                    const auto ren = get_renaming(k, v);
                    const auto unif = unify(c->get_conclusion().value(), loop->get_conclusion().value()->rename_vars(ren));
                    map.emplace(k->rename_vars(ren), bools::mkAnd(std::vector({v->renameVars(ren), cond, unif})));
                }
                res.emplace(c, map);
                break;
            }
            }
        }
    }
}

linked_hash_map<std::string, std::pair<FunApp, Bools::Expr>> CHCCex::to_recurrent_set() const {
    linked_hash_map<std::string, std::pair<FunApp, Bools::Expr>> res;
    for (const auto& t: transitions) {
        const auto prem = t->get_premise();
        assert(prem.size() <= 1);
        if (prem.size() == 0) {
            assert(t->get_conclusion());
            const auto conc = *t->get_conclusion();
            if (!res.contains(conc->get_pred())) {
                res.emplace(conc->get_pred(), std::pair(conc, t->get_constraint())).first->second;
                continue;
            }
            const auto &[f, b] = res.at(conc->get_pred());
            const auto subs = f.unify(conc);
            res.put(conc->get_pred(), std::pair(f, b || t->get_constraint()->renameVars(*subs)));
        }
    }
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

