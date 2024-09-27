#include "chccex.hpp"

CHCCex::CHCCex(CHCPtr chcs): chcs(chcs) {}

bool CHCCex::is_valid_step(const Model &m, const ClausePtr &c) const {
    if (!m.eval<Bools>(c->get_constraint())) {
        return false;
    }
    if (states.empty()) {
        return true;
    }
    const auto last_c {transitions.back()};
    assert(last_c->get_conclusion());
    assert(c->get_premise());
    const auto new_pred {*c->get_premise()};
    const auto last_pred {*last_c->get_conclusion()};
    if (new_pred->get_pred() != last_pred->get_pred()) {
        return false;
    }
    const auto &new_args {new_pred->get_args()};
    const auto &last_args {last_pred->get_args()};
    const auto &last_state {states.back()};
    for (size_t i = 0; i < last_args.size(); ++i) {
        if (last_state.eval(last_args.at(i)) != m.eval(new_args.at(i))) {
            return false;
        }
    }
    return true;
}

bool CHCCex::try_step(const Model &m, const ClausePtr &c) {
    if (!is_valid_step(m, c)) {
        return false;
    }
    states.emplace_back(m);
    transitions.emplace_back(c);
    return true;
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
    for (auto it = transitions.rbegin(); it != transitions.rend(); ++it) {
        todo.push(*it);
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
    s << "rules:" << std::endl;
    for (const auto &[t, kind]: derived) {
        indices.emplace(t, next);
        s << "\t" << next << ": " << t << std::endl;
        switch (kind) {
            case ProofStepKind::ORIG:
                s << "\t\toriginal rule (modulo variable renaming)" << std::endl;
                break;
            case ProofStepKind::IMPLICANT:
                s << "\t\t-" << next << "-> is subset of -" << indices.at(cex.implicants.at(t)) << "->\n";
                break;
            case ProofStepKind::ACCEL:
                s << "\t\t-" << next << "-> is subset of -" << indices.at(cex.accel.at(t)) << "->^+" << std::endl;
                break;
            case ProofStepKind::RESOLVENT:
                s << "\t\t" << "chain(";
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
        ++next;
    }
    s << "\ncounterexample:" << std::endl;
    for (size_t i = 0; i < cex.transitions.size(); ++i) {
        const auto &trans{cex.transitions.at(i)};
        const auto vars{trans->vars()};
        const auto projection{cex.states.at(i).project([&](const auto &x) {
            return theory::isProgVar(x) || vars.contains(x);
        })};
        s << "\t" << projection << "\n\t-" << indices.at(trans) << "->\n";
    }
    return s << "\terr";
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

const std::vector<Model>& CHCCex::get_states() const {
    return states;
}
