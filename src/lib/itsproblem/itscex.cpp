#include "itscex.hpp"
#include <assert.h>

ITSCex::ITSCex(ITSPtr its): its(its) {}

bool ITSCex::is_valid_step(const Model &next, const RulePtr trans) const {
    if (states.size() != transitions.size() + 1) {
        return false;
    }
    const auto m {states.back()};
    if (!m.eval<Bools>(trans->getGuard())) {
        return false;
    }
    const auto &up{trans->getUpdate()};
    for (const auto &x : its->getVars()) {
        if (theory::isProgVar(x) && m.eval(up.get(x)) != next.get(x)) {
            return false;
        }
    }
    return true;
}

bool ITSCex::try_step(const RulePtr trans, const Model &m) {
    if (!is_valid_step(m, trans)) {
        return false;
    }
    states.push_back(m);
    transitions.push_back(trans);
    return true;
}

void ITSCex::set_initial_state(const Model &m) {
    assert(transitions.empty());
    states.clear();
    states.push_back(m);
}

bool ITSCex::try_final_transition(const RulePtr trans) {
    assert(its->isSinkTransition(trans));
    if (states.back().eval<Bools>(trans->getGuard())) {
        transitions.push_back(trans);
        return true;
    } else {
        return false;
    }
}

void ITSCex::replace_state(const Model &m) {
    assert(!states.empty());
    states.pop_back();
    assert(transitions.empty() || is_valid_step(m, transitions.back()));
    states.push_back(m);
}

enum DerivedRuleKind {
    RESOLVENT, ACCEL, IMPLICANT
};

std::ostream& operator<<(std::ostream &s, const ITSCex &cex) {
    linked_hash_set<RulePtr> done;
    std::stack<RulePtr> todo;
    std::vector<std::pair<RulePtr, DerivedRuleKind>> derived;
    for (auto it = cex.transitions.rbegin(); it != cex.transitions.rend(); ++it) {
        todo.push(*it);
    }
    s << "init: " << cex.its->getLocVar() << " = " << cex.its->getInitialLocation();
    s << "\n\nerr: " << cex.its->getLocVar() << " = " << cex.its->getSink();
    s << "\n\nunsat core:" << std::endl;
    while (!todo.empty()) {
        const auto t {todo.top()};
        todo.pop();
        if (done.insert(t).second) {
            if (const auto loop {cex.accel.get(t)}) {
                derived.emplace_back(t, ACCEL);
                todo.push(*loop);
            } else if (const auto orig {cex.implicants.get(t)}) {
                derived.emplace_back(t, IMPLICANT);
                todo.push(*orig);
            } else if (const auto rules {cex.resolvents.get(t)}) {
                derived.emplace_back(t, RESOLVENT);
                for (const auto &r: *rules) {
                    todo.push(r);
                }
            } else {
                s << "\t" << *t << std::endl;
            }
        }
    }
    if (!derived.empty()) {
        s << "\nderived:" << std::endl;
        for (auto it = derived.rbegin(); it != derived.rend(); ++it) {
            const auto &[t,kind] {*it};
            s << "\t" << *t << std::endl;
            switch (kind) {
                case IMPLICANT:
                    s << "\t\t-" << t << "-> is subset of -" << cex.implicants.at(t) << "->\n";
                    break;
                case ACCEL:
                    s << "\t\t-" << t << "-> is subset of -" << cex.accel.at(t) << "->^+" << std::endl;
                    break;
                case RESOLVENT:
                    s << "\t\t" << "resolve(";
                    auto first{true};
                    for (const auto &r : cex.resolvents.at(t)) {
                        if (first) {
                            s << r;
                            first = false;
                        } else {
                            s << ", " << r;
                        }
                    }
                    s << ") = " << t << std::endl;
                    break;
            }
        }
    }
    s << "\ncounterexample:" << std::endl;
    for (size_t i = 0; i < cex.transitions.size(); ++i) {
        const auto &trans {cex.transitions.at(i)};
        const auto vars {trans->vars()};
        const auto projection {cex.states.at(i).project([&](const auto &x) {
                return theory::isProgVar(x) || vars.contains(x);
            })
        };
        s << "\t" << projection << "\n\t-" << trans->getId() << "->\n";
    }
    return s << "\terr";
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

size_t ITSCex::num_states() const {
    return states.size();
}

size_t ITSCex::num_transitions() const {
    return transitions.size();
}
