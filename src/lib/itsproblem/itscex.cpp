#include "itscex.hpp"
#include "formulapreprocessing.hpp"
#include "vector.hpp"
#include "smtfactory.hpp"

#include <assert.h>
#include <stack>

ITSCex::ITSCex(ITSPtr its): its(its) {}

std::vector<std::pair<RulePtr, ProofStepKind>> ITSCex::get_used_rules(const std::vector<RulePtr> &transitions) const {
    linked_hash_set<RulePtr> done;
    std::stack<RulePtr> todo;
    std::vector<std::pair<RulePtr, ProofStepKind>> derived;
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
            } else if (const auto loop{recurrent_set.get(t)}) {
                if ((ready = done.contains(*loop))) {
                    derived.emplace_back(t, ProofStepKind::RECURRENT_SET);
                } else {
                    todo.push(*loop);
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

void ITSCex::add_recurrent_set(const RulePtr loop, const RulePtr res) {
    recurrent_set.emplace(res, loop);
}

void ITSCex::add_accel(const RulePtr loop, const RulePtr res) {
    accel.emplace(res, loop);
}

void ITSCex::add_resolvent(const std::vector<RulePtr> &rules, const RulePtr res) {
    resolvents.emplace(res, rules);
}

void ITSCex::add_implicant(const RulePtr rule, const RulePtr imp) {
    implicants.emplace(imp, rule);
}

const linked_hash_map<RulePtr, RulePtr> &ITSCex::get_accel() const {
    return accel;
}

const linked_hash_map<RulePtr, RulePtr> &ITSCex::get_implicants() const {
    return implicants;
}

const linked_hash_map<RulePtr, std::vector<RulePtr>> &ITSCex::get_resolvents() const {
    return resolvents;
}
