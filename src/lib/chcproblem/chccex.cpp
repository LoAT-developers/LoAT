#include "chccex.hpp"

#include <ranges>
#include <stack>
#include <utility>

#include "formulapreprocessing.hpp"
#include "chcrecurrentset.hpp"

CHCCex::CHCCex(CHCPtr chcs): chcs(std::move(chcs)) {}

void CHCCex::do_step(const ModelPtr &m, const ClausePtr &c) {
    assert(c->get_constraint() != bot());
    if (!m->eval(c->get_constraint())) {
        std::cerr << "not a model" << std::endl;
        std::cerr << c->get_constraint() << std::endl;
        std::cerr << m->toString(c->vars()) << std::endl;
        throw std::logic_error("failed to transform cex");
    }
    states.emplace_back(m);
    transitions.emplace_back(c);
}

void CHCCex::add_accel(const ClausePtr &loop, const ClausePtr &res) {
    assert(res->get_constraint() != bot());
    if (res != loop) {
        accel.emplace(res, loop);
    }
}

void CHCCex::add_recurrent_set(const ClausePtr &loop, const ClausePtr &res) {
    assert(res->get_constraint() != bot());
    recurrent_set.emplace(res, loop);
}

void CHCCex::add_resolvent(const std::vector<ClausePtr> &rules, const ClausePtr &res) {
    assert(res->get_constraint() != bot());
    resolvents.emplace(res, rules);
}

void CHCCex::add_implicant(const ClausePtr &rule, const ClausePtr &imp) {
    assert(imp->get_constraint() != bot());
    if (rule != imp) {
        implicants.emplace(imp, rule);
    }
}

void CHCCex::add_used_clause(const ClausePtr c, const ProofStepKind kind) {
    used_clauses.emplace_back(c, kind);
}

std::ostream& operator<<(std::ostream &s, const CHCCex &cex) {
    std::unordered_map<ClausePtr, unsigned> indices;
    unsigned next {0};
    s << "clauses:" << std::endl;
    for (const auto &[t, kind]: cex.used_clauses) {
        indices.emplace(t, next);
        s << "\t" << next << ": " << t << std::endl;
        switch (kind) {
            case ProofStepKind::ORIG: {
                s << "\t\toriginal clause (modulo variable renaming)" << std::endl;
                break;
            }
            case ProofStepKind::IMPLICANT: {
                s << "\t\tderived from " << indices.at(cex.implicants.at(t)) << " (implicant)\n";
                break;
            }
            case ProofStepKind::ACCEL: {
                s << "\t\tderived from " << indices.at(cex.accel.at(t)) << " (acceleration)" << std::endl;
                break;
            }
            case ProofStepKind::RESOLVENT: {
                s << "\t\t" << "resolve(";
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
            case ProofStepKind::RECURRENT_SET: {
                s << "\t\tderived from " << indices.at(cex.recurrent_set.at(t)) << " (recurrent set)" << std::endl;
                break;
            }
        }
        ++next;
    }
    s << "\nproof:" << std::endl;
    VarSet prog_vars;
    for (size_t i = 0; i < cex.transitions.size(); ++i) {
        const auto &clause{cex.transitions.at(i)};
        s << "\t" << clause << cex.states.at(i)->toString(clause->vars()) << " by " << indices.at(clause) << "\n";
    }
    return s;
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

const std::vector<ModelPtr>& CHCCex::get_states() const {
    return states;
}

