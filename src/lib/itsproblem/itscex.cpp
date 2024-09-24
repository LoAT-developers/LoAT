#include "itscex.hpp"
#include <assert.h>

ITSCex::ITSCex(ITSPtr its): its(its) {}

bool ITSCex::is_valid_step(const Model &m) const {
    if (states.size() != transitions.size()) {
        return false;
    }
    if (transitions.empty()) {
        const auto &init{its->getInitialTransitions()};
        return std::any_of(init.begin(), init.end(), [&](const auto &i) {
            return m.eval<Bools>(i->getGuard());
        });
    } else {
        const auto &up{transitions.back()->getUpdate()};
        const auto &last{states.back()};
        for (const auto &x : its->getVars()) {
            if (theory::isProgVar(x) && m.get(x) != last.eval(up.get(x))) {
                return false;
            }
        }
        return true;
    }
}

bool ITSCex::try_step(const Model &m, const RulePtr trans) {
    if (!m.eval<Bools>(trans->getGuard()) || !is_valid_step(m)) {
        return false;
    }
    states.push_back(m);
    transitions.push_back(trans);
    return true;
}

std::ostream& operator<<(std::ostream &s, const ITSCex &cex) {
    linked_hash_set<RulePtr> done;
    std::stack<RulePtr> todo;
    linked_hash_set<RulePtr> imp;
    for (const auto &t: cex.transitions) {
        todo.push(t);
    }
    s << "input:" << std::endl;
    s << "\tinit: " << cex.its->getLocVar() << " = " << cex.its->getInitialLocation() << std::endl;
    s << "\terr: " << cex.its->getLocVar() << " = " << cex.its->getSink() << std::endl;
    auto has_learned_transitions {false};
    while (!todo.empty()) {
        const auto t {todo.top()};
        todo.pop();
        if (done.insert(t).second) {
            if (const auto loop {cex.accel.get(t)}) {
                has_learned_transitions = true;
                todo.push(*loop);
            } else if (const auto orig {cex.implicants.get(t)}) {
                imp.insert(t);
                todo.push(*orig);
            } else if (const auto rules {cex.resolvents.get(t)}) {
                for (const auto &r: *rules) {
                    todo.push(r);
                }
            } else {
                s << "\t" << *t << std::endl;
            }
        }
    }
    if (has_learned_transitions) {
        s << "\nderived:" << std::endl;
        for (const auto &t : imp) {
            s << "\t" << cex.implicants.at(t) << " implies " << *t << std::endl;
        }
        for (const auto &t : cex.transitions) {
            if (const auto loop{cex.accel.get(t)}) {
                if (const auto rules{cex.resolvents.get(*loop)}) {
                    s << "\t" << "resolve(";
                    auto first{true};
                    for (const auto &r : *rules) {
                        if (first) {
                            s << r;
                            first = false;
                        } else {
                            s << ", " << r;
                        }
                    }
                    s << ") = " << **loop << std::endl;
                }
                s << "\t" << "accel(" << *loop << ") = " << *t << std::endl;
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

size_t ITSCex::size() const {
    return states.size();
}
