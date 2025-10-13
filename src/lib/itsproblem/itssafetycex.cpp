#include "itssafetycex.hpp"
#include "formulapreprocessing.hpp"
#include "vector.hpp"
#include "smtfactory.hpp"

#include <cassert>

ITSSafetyCex::ITSSafetyCex(const ITSPtr& its): ITSCex(its) {}

void ITSSafetyCex::do_step(const RulePtr& trans, const ModelPtr &next) {
    states.push_back(next);
    transitions.push_back(trans);
}

void ITSSafetyCex::set_initial_state(const ModelPtr &m) {
    assert(transitions.empty());
    states.clear();
    states.push_back(m);
}

void ITSSafetyCex::add_final_transition(const RulePtr& trans) {
    assert(trans->getUpdate().get<Arith>(its->getLocVar()) == arith::mkConst(its->getSink()));
    transitions.push_back(trans);
}

std::ostream& operator<<(std::ostream &s, const ITSSafetyCex &cex) {
    const auto derived {cex.get_used_rules()};
    s << "init: " << cex.its->getLocVar() << " = " << cex.its->getInitialLocation();
    s << "\n\nerr: " << cex.its->getLocVar() << " = " << cex.its->getSink();
    if (!derived.empty()) {
        s << "\n\nrules:" << std::endl;
        for (const auto &[t,kind]: derived) {
            s << "\t" << *t << std::endl;
            switch (kind) {
                case ProofStepKind::ORIG: {
                    s << "\t\toriginal rule" << std::endl;
                    break;
                }
                case ProofStepKind::IMPLICANT: {
                    s << "\t\t-" << t << "-> is subset of -" << cex.implicants.at(t) << "->\n";
                    break;
                }
                case ProofStepKind::ACCEL: {
                    s << "\t\t-" << t << "-> is subset of -" << cex.accel.at(t) << "->^+" << std::endl;
                    break;
                }
                case ProofStepKind::RESOLVENT: {
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
                case ProofStepKind::RECURRENT_SET: {
                    s << "\t\tguard(" << t << ") is a recurrent set of " << cex.recurrent_set.at(t) << std::endl;
                    break;
                }
            }
        }
        s << "\ncounterexample:" << std::endl;
        VarSet prog_vars;
        for (size_t i = 0; i < cex.transitions.size(); ++i) {
            const auto &trans{cex.transitions.at(i)};
            auto vars{trans->vars()};
            for (const auto& x: vars) {
                if (theory::isProgVar(x)) {
                    prog_vars.insert(x);
                }
            }
            vars.insertAll(prog_vars);
            s << "\t" << cex.states.at(i)->toString(vars) << "\n\t-" << trans->getId() << "->\n";
        }
        s << "\terr";
    }
    return s;
}

size_t ITSSafetyCex::num_states() const {
    return states.size();
}

ModelPtr ITSSafetyCex::get_state(const size_t i) const {
    return states.at(i);
}

size_t ITSSafetyCex::num_transitions() const {
    return transitions.size();
}

RulePtr ITSSafetyCex::get_transition(const size_t i) const {
    return transitions.at(i);
}

std::vector<std::pair<RulePtr, ProofStepKind>> ITSSafetyCex::get_used_rules() const {
    return ITSCex::get_used_rules(transitions);
}

ITSSafetyCex ITSSafetyCex::replace_rules(const linked_hash_map<RulePtr, RulePtr> &map) const {
    ITSSafetyCex res{its};
    for (const auto &[x, y] : implicants) {
        res.add_implicant(map.get(y).value_or(y), map.get(x).value_or(x));
    }
    for (const auto &[x, y] : accel) {
        res.add_accel(map.get(y).value_or(y), map.get(x).value_or(x));
    }
    for (const auto &[x, ys] : resolvents) {
        std::vector<RulePtr> transformed;
        for (const auto &y : ys) {
            transformed.emplace_back(map.get(y).value_or(y));
        }
        res.add_resolvent(transformed, map.get(x).value_or(x));
    }
    for (const auto &[x, y] : recurrent_set) {
        res.add_recurrent_set(map.get(y).value_or(y), map.get(x).value_or(x));
    }
    res.set_initial_state(states.front());
    for (size_t i = 1; i < num_states(); ++i) {
        auto trans{transitions.at(i - 1)};
        auto state{states.at(i)};
        res.do_step(map.get(trans).value_or(trans), state);
    }
    const auto trans{transitions.back()};
    res.add_final_transition(map.get(trans).value_or(trans));
    return res;
}
