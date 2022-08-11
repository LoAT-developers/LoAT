#include "accelerationviaqe.hpp"
#include "../accelerate/recurrence/recurrence.hpp"
#include "../smt/smtfactory.hpp"
#include "../util/relevantvariables.hpp"
#include "../qelim/redlog.hpp"
#include "../nonterm/nontermproblem.hpp"
#include "../its/export.hpp"

AccelerationViaQE::AccelerationViaQE(
        const LinearRule &rule,
        option<const Subs&> closed,
        const Expr &iteratedCost,
        const Var &n,
        const unsigned int validityBound,
        ITSProblem &its): closed(closed), iteratedCost(iteratedCost), n(n), rule(rule), validityBound(validityBound), its(its) {}

option<AccelerationViaQE> AccelerationViaQE::init(const LinearRule &r, ITSProblem &its) {
    const Var &n = its.addFreshTemporaryVariable("n");
    const option<Recurrence::Result> &res = Recurrence::iterateRule(its, r, n);
    if (res) {
        return {AccelerationViaQE(
                        r,
                        option<const Subs&>(res->update),
                        res->cost,
                        n,
                        res->validityBound,
                        its)};
    } else {
        return {AccelerationViaQE(
                        r,
                        option<const Subs&>(),
                        r.getCost(),
                        n,
                        0,
                        its)};
    }
}

AccelerationViaQE AccelerationViaQE::initForRecurrentSet(const LinearRule &r, ITSProblem &its) {
    return AccelerationViaQE(
                r,
                option<const Subs&>(),
                r.getCost(),
                its.addFreshTemporaryVariable("n"),
                0,
                its);
}

std::vector<AccelerationViaQE::Result> AccelerationViaQE::computeRes() {
    if (!closed || !closed->isPoly() || !rule.getGuard()->isPolynomial()) {
        auto nt = NontermProblem::init(rule.getGuard(), rule.getUpdate(), rule.getCost(), its);
        const auto res = nt.computeRes();
        if (res) {
            return {Result(res->newGuard, nt.getProof(), res->exact, true)};
        }
        if (!closed) {
            return {};
        }
    }
    Var m = its.getFreshUntrackedSymbol("m", Expr::Int);
    BoolExpr matrix = rule.getGuard()->subs(closed.get());
    auto qelim = Qelim::solver(its);
    QuantifiedFormula q = matrix->quantify({Quantifier(Quantifier::Type::Forall, {n}, {{n, 0}}, {})});
    option<Qelim::Result> res = qelim->qe(q);
    std::vector<AccelerationViaQE::Result> ret;
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
        ret.push_back(Result(res->qf, proof, res->exact, true));
        if (res->exact) {
            return ret;
        }
    }
    matrix = rule.getGuard()->subs(closed.get())->subs({n, m});
    q = matrix->quantify({Quantifier(Quantifier::Type::Forall, {m}, {{m, validityBound}}, {{m, n-1}})});
    res = qelim->qe(q);
    if (res && res->qf != False) {
        const BoolExpr accelerator = res->qf & (n >= validityBound);
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
        ret.push_back(Result(accelerator, proof, res->exact, false));
    }
    return ret;
}

Expr AccelerationViaQE::getAcceleratedCost() const {
    return iteratedCost;
}

option<Subs> AccelerationViaQE::getClosedForm() const {
    return closed;
}

Var AccelerationViaQE::getIterationCounter() const {
    return n;
}

unsigned int AccelerationViaQE::getValidityBound() const {
    return validityBound;
}
