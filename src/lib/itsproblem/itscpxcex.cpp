#include "itscpxcex.hpp"
#include "formulapreprocessing.hpp"
#include "vector.hpp"
#include "smtfactory.hpp"
#include "theory.hpp"

#include <boost/algorithm/string.hpp>
#include <cassert>

std::ostream& operator<<(std::ostream &s, const ITSCpxCex &cex) {
    if (cex.witness) {
        const auto derived {cex.get_used_rules({*cex.witness})};
        if (!derived.empty()) {
            s << "\n\nrules:" << std::endl;
            for (const auto &[t,kind]: derived) {
                s << "\t" << *t << std::endl;
                s << "\t\tcost: " << ITSProblem::getCost(t) << std::endl;
                s << "\t\torigin: ";
                switch (kind) {
                    case ProofStepKind::ORIG: {
                        s << "original rule" << std::endl;
                        break;
                    }
                    case ProofStepKind::IMPLICANT: {
                        s << "-" << t << "-> is subset of -" << cex.implicants.at(t).in() << "->\n";
                        break;
                    }
                    case ProofStepKind::ACCEL: {
                        s << "-" << t << "-> is subset of -" << cex.accel.at(t) << "->^+" << std::endl;
                        break;
                    }
                    case ProofStepKind::RESOLVENT: {
                        s << "chain(";
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
                        s << "guard(" << t << ") is a recurrent set of " << cex.recurrent_set.at(t) << std::endl;
                        break;
                    }
                }
            }
        }
        auto valuation_str {(*cex.valuation)->toString(cex.vars())};
        boost::replace_all(valuation_str, (*cex.param)->var()->getName(), "n");
        s << "\nwitness: " << *cex.witness << std::endl;
        s << "\nvaluation: " << valuation_str << std::endl;
    }
    return s;
}

ITSCpxCex::ITSCpxCex(const linked_hash_set<RulePtr> &orig): ITSCex(orig) {}

void ITSCpxCex::set_witness(const RulePtr& witness, const ModelPtr &valuation, const ArithVarPtr &param) {
    this->witness = witness;
    this->valuation = valuation;
    this->param = param;
}

VarSet ITSCpxCex::vars() const {
    VarSet res;
    if (witness) {
        (*witness)->collectVars(res);
    }
    if (param) {
        (*param)->collectVars(res);
    }
    return res;
}
