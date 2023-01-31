#include "accelerationviaqe.hpp"
#include "recurrence.hpp"
#include "qelimfactory.hpp"
#include "qelim.hpp"
#include "export.hpp"

AccelerationViaQE::AccelerationViaQE(
        const LinearRule &rule,
        const Recurrence::Result closed,
        ITSProblem &its,
        const AccelConfig &config): AccelerationTechnique(rule, closed, its, config) {}

AccelerationViaQE::AcceleratorPair AccelerationViaQE::computeRes() {
    NumVar m = its.getFreshUntrackedSymbol<IntTheory>("m", Expr::Int);
    auto qelim = qelimfactory::solver<IntTheory, BoolTheory>(its);
    option<Qelim<IntTheory,BoolTheory>::Result> res;
    AcceleratorPair ret;
    BoolExpr matrix = rule.getGuard()->toG()->subs(closed->update);
    if (Config::Analysis::tryNonterm()) {
        const QFormula q = matrix->quantify({Quantifier(Quantifier::Type::Forall, {closed->n}, {{closed->n, 0}}, {})});
        res = qelim->qe(q);
        if (res && res->qf != BExpression::False) {
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
            ret.nonterm.emplace(res->qf, proof, res->exact);
            if (res->exact) {
                return ret;
            }
        }
    }
    matrix = matrix->subs(Subs::build<IntTheory>(closed->n, m));
    const QFormula q = matrix->quantify({Quantifier(Quantifier::Type::Forall, {m}, {{m, 0}}, {{m, (*closed->n) - 1}})});
    res = qelim->qe(q);
    if (res && res->qf != BExpression::False) {
        const auto accelerator = res->qf & Rel(closed->n, Rel::geq, 1);
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
        ret.term.emplace(accelerator, proof, res->exact);
    }
    return ret;
}
