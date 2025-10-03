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
                throw std::logic_error("recurrent sets are not supported for CHCs");
            }
        }
        ++next;
    }
    s << "\nproof:" << std::endl;
    VarSet prog_vars;
    for (size_t i = 0; i < cex.transitions.size(); ++i) {
        const auto &clause{cex.transitions.at(i)};
        auto vars{clause->vars()};
        for (const auto& x: vars) {
            if (theory::isProgVar(x)) {
                prog_vars.insert(x);
            }
        }
        vars.insertAll(prog_vars);
        s << "\t" << clause;
        cex.states.at(i)->print(s, vars);
        s << " by " << indices.at(clause) << "\n";
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
