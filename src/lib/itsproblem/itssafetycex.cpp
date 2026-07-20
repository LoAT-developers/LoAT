#include "itssafetycex.hpp"
#include "formulapreprocessing.hpp"
#include "vector.hpp"
#include "smtfactory.hpp"

#include <cassert>

void ITSSafetyCex::do_step(const RulePtr& trans, const ModelPtr &next) {
    if (!is_known(trans)) {
        throw std::logic_error("adding unknown rule " + toString(trans->getId()) + " to cex");
    }
    m_states.push_back(next);
    m_transitions.push_back(trans);
}

void ITSSafetyCex::set_initial_state(const ModelPtr &m) {
    assert(m_transitions.empty());
    m_states.clear();
    m_states.push_back(m);
}

void ITSSafetyCex::add_final_transition(const RulePtr& trans) {
    m_transitions.push_back(trans);
}

std::ostream& operator<<(std::ostream &s, const ITSSafetyCex &cex) {
    const auto derived {cex.get_used_rules()};
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
                    s << "\t\t-" << t << "-> is subset of -" << cex.implicants.at(t).in() << "->\n";
                    break;
                }
                case ProofStepKind::ACCEL: {
                    s << "\t\t-" << t << "-> is subset of -" << cex.accel.at(t) << "->^+" << std::endl;
                    break;
                }
                case ProofStepKind::RESOLVENT: {
                    s << "\t\t" << "chain(";
                    auto first{true};
                    for (const auto &r : cex.resolvents.at(t).in()) {
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
        for (size_t i = 0; i < cex.m_transitions.size(); ++i) {
            const auto &trans{cex.m_transitions.at(i)};
            auto vars{trans->vars()};
            s << "\t" << cex.m_states.at(i)->toString(prog_vars) << "\n\t-" << trans->getId() << "->\n";
        }
        s << "\terr";
    }
    return s;
}

size_t ITSSafetyCex::num_states() const {
    return m_states.size();
}

ModelPtr ITSSafetyCex::get_state(const size_t i) const {
    return m_states.at(i);
}

ITSSafetyCex::ITSSafetyCex(const linked_hash_set<RulePtr> &p_orig): ITSCex(p_orig) {}

size_t ITSSafetyCex::num_transitions() const {
    return m_transitions.size();
}

RulePtr ITSSafetyCex::get_transition(const size_t i) const {
    return m_transitions.at(i);
}

std::vector<std::pair<RulePtr, ProofStepKind>> ITSSafetyCex::get_used_rules() const {
    return ITSCex::get_used_rules(m_transitions);
}
