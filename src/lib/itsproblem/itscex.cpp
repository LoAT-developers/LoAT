#include "itscex.hpp"
#include "formulapreprocessing.hpp"
#include "vector.hpp"

#include <assert.h>

ITSCex::ITSCex(ITSPtr its): its(its) {}

bool ITSCex::is_valid_step(const RulePtr trans, const Model &next) const {
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
    if (!is_valid_step(trans, m)) {
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
    assert(transitions.empty() || is_valid_step(transitions.back(), m));
    states.push_back(m);
}

std::vector<std::pair<RulePtr, ProofStepKind>> ITSCex::get_used_rules() const {
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

std::ostream& operator<<(std::ostream &s, const ITSCex &cex) {
    const auto derived {cex.get_used_rules()};
    s << "init: " << cex.its->getLocVar() << " = " << cex.its->getInitialLocation();
    s << "\n\nerr: " << cex.its->getLocVar() << " = " << cex.its->getSink();
    if (!derived.empty()) {
        s << "\n\nrules:" << std::endl;
        for (const auto &[t,kind]: derived) {
            s << "\t" << *t << std::endl;
            switch (kind) {
                case ProofStepKind::ORIG:
                    s << "\t\toriginal rule" << std::endl;
                    break;
                case ProofStepKind::IMPLICANT:
                    s << "\t\t-" << t << "-> is subset of -" << cex.implicants.at(t) << "->\n";
                    break;
                case ProofStepKind::ACCEL:
                    s << "\t\t-" << t << "-> is subset of -" << cex.accel.at(t) << "->^+" << std::endl;
                    break;
                case ProofStepKind::RESOLVENT:
                    s << "\t\t" << "chain(";
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
        s << "\ncounterexample:" << std::endl;
        for (size_t i = 0; i < cex.transitions.size(); ++i) {
            const auto &trans{cex.transitions.at(i)};
            const auto vars{trans->vars()};
            const auto projection{cex.states.at(i).project([&](const auto &x) {
                return theory::isProgVar(x) || vars.contains(x);
            })};
            s << "\t" << projection << "\n\t-" << trans->getId() << "->\n";
        }
        s << "\terr";
    }
    return s;
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

RulePtr ITSCex::get_transition(const size_t i) const {
    return transitions.at(i);
}

Model ITSCex::get_state(const size_t i) const {
    return states.at(i);
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

ITSCex ITSCex::replace_rules(const linked_hash_map<RulePtr, std::pair<RulePtr, Subs>> &map) const {
    ITSCex res(its);
    for (const auto &[x,y]: implicants) {
        std::optional<RulePtr> y_opt;
        if (const auto opt {map.get(y)}) {
            y_opt = opt->first;
        }
        std::optional<RulePtr> x_opt;
        if (const auto opt {map.get(x)}) {
            x_opt = opt->first;
        }
        res.add_implicant(y_opt.value_or(y), x_opt.value_or(x));
    }
    for (const auto &[x,y]: accel) {
        std::optional<RulePtr> y_opt;
        if (const auto opt {map.get(y)}) {
            y_opt = opt->first;
        }
        std::optional<RulePtr> x_opt;
        if (const auto opt {map.get(x)}) {
            x_opt = opt->first;
        }
        res.add_accel(y_opt.value_or(y), x_opt.value_or(x));
    }
    for (const auto &[x,ys]: resolvents) {
        std::vector<RulePtr> transformed;
        for (const auto &y: ys) {
            std::optional<RulePtr> y_opt;
            if (const auto opt{map.get(y)}) {
                y_opt = opt->first;
            }
            transformed.emplace_back(y_opt.value_or(y));
        }
        std::optional<RulePtr> x_opt;
        if (const auto opt {map.get(x)}) {
            x_opt = opt->first;
        }
        res.add_resolvent(transformed, x_opt.value_or(x));
    }
    res.set_initial_state(states.front());
    for (size_t i = 1; i < num_states(); ++i) {
        const auto trans {transitions.at(i - 1)};
        auto state {states.at(i)};
        if (const auto opt {map.get(trans)}) {
            auto transformed {FormulaPreprocessor::transform_model(res.states.back(), opt->second)};
            res.replace_state(transformed);
            if (!res.try_step(opt->first, state)) {
                throw std::logic_error("replace_rules failed");
            }
        } else if (!res.try_step(trans, state)) {
            throw std::logic_error("replace_rules failed");
        }
    }
    const auto trans {transitions.back()};
    if (const auto opt {map.get(trans)}) {
        auto transformed {FormulaPreprocessor::transform_model(states.back(), opt->second)};
        res.replace_state(transformed);
        if (!res.try_final_transition(opt->first)) {
            throw std::logic_error("replace_rules failed");
        }
    } else if (!res.try_final_transition(trans)) {
        throw std::logic_error("replace_rules failed");
    }
    return res;
}
