#include "chccex.hpp"

#include <ranges>
#include <stack>
#include <utility>

#include "formulapreprocessing.hpp"
#include "recurrentset.hpp"

CHCCex::CHCCex(CHCPtr chcs): chcs(std::move(chcs)) {}

void CHCCex::do_step(const ModelPtr &m, const ClausePtr &c) {
    assert(c->get_constraint() != bot());
    states.emplace_back(m);
    transitions.emplace_back(c);
}

void CHCCex::add_accel(const ClausePtr &loop, const ClausePtr &res) {
    assert(res->get_constraint() != bot());
    accel.emplace(res, loop);
}

void CHCCex::add_recurrent_set(const ClausePtr &loop, const ClausePtr &res) {
    assert(res->get_constraint() != bot());
    recurrent_set.emplace(res, loop);
}

void CHCCex::add_resolvent(const std::vector<ClausePtr> &rules, const ClausePtr &res) {
    assert(res->get_constraint() != bot());
    resolvents.emplace(res, rules);
}

void CHCCex::add_implicant(const ClausePtr &rule, const ClausePtr &imp) {
    assert(imp->get_constraint() != bot());
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

ClausePtr rename_clause(const ClausePtr &c) {
    Renaming ren;
    VarSet vars;
    c->collect_vars(vars);
    for (const auto &x: vars) {
        theory::apply(x, [&](const auto &x) {
            Renaming::renameVar(x, ren);
        });
    }
    return c->rename_vars(ren);
}

void CHCCex::complete_recurrent_set(RecurrentSet& rs, const ClausePtr& clause, bool with_start) const{

    const auto rename = [&](const std::pair<FunAppPtr, BoolExprSet> &p) {
        Renaming ren;
        VarSet vars;
        p.first->collect_vars(vars);
        for (const auto& e: p.second) {
            e->collectVars(vars);
        }
        for (const auto &x: vars) {
            theory::apply(x, [&](const auto &x) {
                Renaming::renameVar(x, ren);
            });
        }
        BoolExprSet res;
        for (const auto& e: p.second) {
            res.insert(e->renameVars(ren));
        }
        return std::pair(p.first->rename_vars(ren), res);
    };

    if (resolvents.contains(clause)) {
        const auto cs = resolvents.at(clause);
        for (const auto &c: cs | std::views::reverse) {
            complete_recurrent_set(rs, c, c != cs.front());
        }
    } else if (accel.contains(clause)) {
        complete_recurrent_set(rs, accel.at(clause), false);
    } else if (recurrent_set.contains(clause)) {
        complete_recurrent_set(rs, recurrent_set.at(clause), false);
    } else {
        rs.add(clause);
        if (with_start && !clause->is_fact()) {
            const auto renamed = rename_clause(clause);
            const auto premise = renamed->get_premise().front();
            const auto conclusion = renamed->get_conclusion().value();
            const auto [sig_conclusion, rs_conclusion] = rename(rs.get(conclusion));
            const auto unif = FunApp::unify(conclusion, sig_conclusion);
            for (const auto& b: rs_conclusion) {
                rs.add(premise, BoolExprSet{renamed->get_constraint(), b, unif});
            }
        }
    }
}

RecurrentSet CHCCex::to_recurrent_set() const {

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

    RecurrentSet res;

    for (unsigned i = 0; i < transitions.size(); ++i) {
        const auto t = transitions.at(i);
        const auto from = states.at(i);
        if (recurrent_set.contains(t)) {
            const auto premise = t->get_premise().front();
            res.add(premise, t->get_constraint());
        } else {
            const auto to = states.at(i+1);
            if (accel.contains(t)) {
                const auto renamed = rename_clause(t);
                const auto premise = renamed->get_premise().front();
                const auto conc = renamed->get_conclusion().value();
                const auto spec = instantiate(transitions.at(i+1)->get_premise().front(), to);
                const auto unif = FunApp::unify(conc, spec);
                // the final value is in the recurrent set
                res.add(conc, unif);
                // all values that can reach the final value are in the recurrent set
                res.add(premise, unif && renamed->get_constraint());
            } else {
                if (!t->is_fact()) {
                    const auto premise = t->get_premise().front();
                    const auto premise_spec = instantiate(premise, from);
                    res.add(premise, FunApp::unify(premise, premise_spec));
                }
                const auto conc = t->get_conclusion().value();
                const auto conc_spec = instantiate(transitions.at(i+1)->get_premise().front(), to);
                res.add(conc, FunApp::unify(conc, conc_spec));
            }
        }
        complete_recurrent_set(res, t, false);
    }
    res.simplify();
    std::cout << res << std::endl;
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

