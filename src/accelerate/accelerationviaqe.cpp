#include "accelerationviaqe.hpp"
#include "recurrence.hpp"
#include "qelim.hpp"
#include "export.hpp"

AccelerationViaQE::AccelerationViaQE(
        const LinearRule &rule,
        const Recurrence::Result closed,
        ITSProblem &its): AccelerationTechnique(rule, closed, its) {}

AccelerationViaQE::AcceleratorPair AccelerationViaQE::computeRes() {
    const auto isIntLiteral = [](const Lit &lit){
        return std::holds_alternative<Rel>(lit);
    };
    if (!rule.getGuard()->forall(isIntLiteral)) {
        return {};
    }
    NumVar m = its.getFreshUntrackedSymbol<IntTheory>("m", Expr::Int);
    auto qelim = Qelim::solver(its);
    option<Qelim::Result> res;
    AcceleratorPair ret;
    BExpr<IntTheory> matrix = rule.getGuard()->toG()->transform<IntTheory>()->subs(closed->update);
    if (Config::Analysis::tryNonterm()) {
        QuantifiedFormula<IntTheory> q = matrix->quantify({Quantifier(Quantifier::Type::Forall, {closed->n}, {{closed->n, 1}}, {})});
        res = qelim->qe(q);
        if (res && res->qf != BoolExpression<IntTheory>::False) {
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
    matrix = matrix->subs(theory::Subs<IntTheory>::build<IntTheory>(closed->n, m));
    const QuantifiedFormula<IntTheory> q = matrix->quantify({Quantifier(Quantifier::Type::Forall, {m}, {{m, 1}}, {{m, (*closed->n) - 1}})});
    res = qelim->qe(q);
    if (res && res->qf != BoolExpression<IntTheory>::False) {
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
