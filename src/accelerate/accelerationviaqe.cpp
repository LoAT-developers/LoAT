#include "accelerationviaqe.hpp"
#include "recurrence.hpp"
#include "qelim.hpp"
#include "export.hpp"

AccelerationViaQE::AccelerationViaQE(
        const LinearRule &rule,
        const Recurrence::Result closed,
        ITSProblem &its): AccelerationTechnique(rule, closed, its) {}

std::vector<AccelerationTechnique<IntTheory>::Accelerator> AccelerationViaQE::computeRes() {
    const auto isIntLiteral = [](const Lit &lit){
        return std::visit(Overload{
                              [](const Rel &rel){return true;},
                              [](const auto &lit){return false;}
                          }, lit);
    };
    if (!rule.getGuard()->forall(isIntLiteral)) {
        return {};
    }
    NumVar m = its.getFreshUntrackedSymbol<IntTheory>("m", Expr::Int);
    auto qelim = Qelim::solver(its);
    option<Qelim::Result> res;
    std::vector<Accelerator> ret;
    BExpr<IntTheory> matrix = rule.getGuard()->toG()->transform<IntTheory>()->subs(closed->update);
    if (Config::Analysis::tryNonterm()) {
        QuantifiedFormula<IntTheory> q = matrix->quantify({Quantifier(Quantifier::Type::Forall, {closed->n}, {{closed->n, closed->validityBound}}, {})});
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
            ret.push_back(Accelerator(res->qf, proof, res->exact, true));
            if (res->exact) {
                return ret;
            }
        }
    }
    matrix = matrix->subs(theory::Subs<IntTheory>::build<IntTheory>(closed->n, m));
    const QuantifiedFormula<IntTheory> q = matrix->quantify({Quantifier(Quantifier::Type::Forall, {m}, {{m, closed->validityBound}}, {{m, (*closed->n) - 1}})});
    res = qelim->qe(q);
    if (res && res->qf != BoolExpression<IntTheory>::False) {
        const Rel bound = Config::Analysis::reachability() && closed->validityBound == 0 ? Rel(closed->n, Rel::gt, 0) : Rel(closed->n, Rel::geq, closed->validityBound);
        const auto accelerator = res->qf & bound;
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
