#include "itssafetycex.hpp"
#include "formulapreprocessing.hpp"
#include "vector.hpp"
#include "smtfactory.hpp"

#include <cassert>

void ITSSafetyCex::do_step(const RulePtr& trans, const ModelPtr &next) {
    if (!is_known(trans)) {
        throw std::logic_error("adding unknown rule " + toString(trans->getId()) + " to cex");
    }
    states.push_back(next);
    transitions.push_back(trans);
}

void ITSSafetyCex::set_initial_state(const ModelPtr &m) {
    assert(transitions.empty());
    states.clear();
    states.push_back(m);
}

void ITSSafetyCex::add_final_transition(const RulePtr& trans) {
    assert(trans->getUpdate().getConst(ITSProblem::loc_var()) == arith::mkConst(ITSProblem::getSink()));
    transitions.push_back(trans);
}

std::ostream& operator<<(std::ostream &s, const ITSSafetyCex &cex) {
    const auto derived {cex.get_used_rules()};
    s << "init: " << ITSProblem::loc_var() << " = " << ITSProblem::getInitialLocation();
    s << "\n\nerr: " << ITSProblem::loc_var() << " = " << ITSProblem::getSink();
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

ITSSafetyCex::ITSSafetyCex(const linked_hash_set<RulePtr> &orig): ITSCex(orig) {}

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
    ITSSafetyCex res{{}};
    const auto get = [&](const auto& r) {
        return map.get(r).value_or(r);
    };
    for (const auto &[r,k]: get_used_rules()) {
        switch (k) {
            case ProofStepKind::IMPLICANT: {
                res.add_implicant(get(implicants.at(r)), get(r));
                break;
            }
            case ProofStepKind::RESOLVENT: {
                const auto orig = resolvents.at(r);
                std::vector<RulePtr> transformed;
                for (const auto& r: orig) {
                    transformed.emplace_back(get(r));
                }
                res.add_resolvent(transformed, get(r));
                break;
            }
            case ProofStepKind::RECURRENT_SET: {
                res.add_recurrent_set(get(recurrent_set.at(r)), get(r));
                break;
            }
            case ProofStepKind::ACCEL: {
                res.add_accel(get(accel.at(r)), get(r));
                break;
            }
            case ProofStepKind::ORIG: {
                res.add_orig(get(r));
            }
        }
    }
    res.set_initial_state(states.front());
    for (size_t i = 1; i < num_states(); ++i) {
        auto trans{transitions.at(i - 1)};
        auto state{states.at(i)};
        res.do_step(get(trans), state);
    }
    const auto trans{transitions.back()};
    res.add_final_transition(get(trans));
    return res;
}
