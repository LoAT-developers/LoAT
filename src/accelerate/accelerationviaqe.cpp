#include "accelerationviaqe.hpp"
#include "recurrence.hpp"
#include "smtfactory.hpp"
#include "relevantvariables.hpp"
#include "accelerationproblem.hpp"
#include "redlog.hpp"
#include "export.hpp"

AccelerationViaQE::AccelerationViaQE(
        const LinearRule &rule,
        const Recurrence::Result closed,
        ITSProblem &its): AccelerationTechnique(rule, closed, its) {}

std::vector<AccelerationViaQE::Accelerator> AccelerationViaQE::computeRes() {
    const bool tryNonterm = Config::Analysis::nonTermination() || Config::Analysis::complexity();
    Var m = its.getFreshUntrackedSymbol("m", Expr::Int);
    auto qelim = Qelim::solver(its);
    option<Qelim::Result> res;
    std::vector<AccelerationViaQE::Accelerator> ret;
    if (tryNonterm) {
        BoolExpr matrix = rule.getGuard()->subs(closed->update);
        QuantifiedFormula q = matrix->quantify({Quantifier(Quantifier::Type::Forall, {closed->n}, {{closed->n, 0}}, {})});
        res = qelim->qe(q);
        if (res && res->qf != False) {
            Proof proof;
            std::stringstream headline;
            headline << "Proved ";
            if (res->exact) {
                headline << "Universal ";
            }
            headline << "Non-Termination via Quantifier Elimination";
            proof.headline(headline);
            std::stringstream loop;
            loop << "Loop: ";
            ITSExport::printRule(rule, its, loop);
            proof.append(loop);
            proof.append(std::stringstream() << "Certificate of Non-Termination: " << res->qf);
            proof.storeSubProof(res->proof);
            ret.push_back(Accelerator(res->qf, proof, res->exact, true));
            if (res->exact) {
                return ret;
            }
        }
    }
    BoolExpr matrix = rule.getGuard()->subs(closed->update)->subs({closed->n, m});
    QuantifiedFormula q = matrix->quantify({Quantifier(Quantifier::Type::Forall, {m}, {{m, closed->validityBound}}, {{m, closed->n-1}})});
    res = qelim->qe(q);
    if (res && res->qf != False) {
        const BoolExpr accelerator = res->qf & (closed->n >= closed->validityBound);
        Proof proof;
        std::stringstream headline;
        if (res->exact) {
            headline << "Exactly ";
        }
        headline << "Accelerated Loop via Quantifier Elimination";
        proof.headline(headline);
        std::stringstream loop;
        loop << "Loop: ";
        ITSExport::printRule(rule, its, loop);
        proof.append(loop);
        proof.append(std::stringstream() << "Accelerator: " << accelerator);
        proof.storeSubProof(res->proof);
        ret.push_back(Accelerator(accelerator, proof, res->exact, false));
    }
    return ret;
}
