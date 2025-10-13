#include "itscpxcex.hpp"
#include "formulapreprocessing.hpp"
#include "vector.hpp"
#include "smtfactory.hpp"

#include <boost/algorithm/string.hpp>
#include <cassert>

ITSCpxCex::ITSCpxCex(const ITSPtr& its): ITSCex(its) {}

std::ostream& operator<<(std::ostream &s, const ITSCpxCex &cex) {
    if (cex.witness) {
        const auto derived {cex.get_used_rules({*cex.witness})};
        s << "init: " << cex.its->getLocVar() << " = " << cex.its->getInitialLocation();
        s << "\n\nerr: " << cex.its->getLocVar() << " = " << cex.its->getSink();
        if (!derived.empty()) {
            s << "\n\nrules:" << std::endl;
            for (const auto &[t,kind]: derived) {
                s << "\t" << *t << std::endl;
                s << "\t\tcost: " << cex.its->getCost(t) << std::endl;
                s << "\t\torigin: ";
                switch (kind) {
                    case ProofStepKind::ORIG: {
                        s << "original rule" << std::endl;
                        break;
                    }
                    case ProofStepKind::IMPLICANT: {
                        s << "-" << t << "-> is subset of -" << cex.implicants.at(t) << "->\n";
                        break;
                    }
                    case ProofStepKind::ACCEL: {
                        s << "-" << t << "-> is subset of -" << cex.accel.at(t) << "->^+" << std::endl;
                        break;
                    }
                    case ProofStepKind::RESOLVENT: {
                        s << "chain(";
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
                        s << "guard(" << t << ") is a recurrent set of " << cex.recurrent_set.at(t) << std::endl;
                        break;
                    }
                }
            }
        }
        auto valuation_str {(*cex.valuation)->toString(cex.vars())};
        boost::replace_all(valuation_str, (*cex.param)->getName(), "n");
        s << "\nwitness: " << *cex.witness << std::endl;
        s << "\nvaluation: " << valuation_str << std::endl;
    }
    return s;
}

ITSCpxCex ITSCpxCex::replace_rules(const linked_hash_map<RulePtr, RulePtr> &map) const {
    ITSCpxCex res{its};
    if (witness) {
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
        assert(!map.contains(*witness));
        res.witness = witness;
        res.valuation = valuation;
        res.param = param;
    }
    return res;
}

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
        res.insert(*param);
    }
    return res;
}
