#include "accelerationviaqe.hpp"
#include "recurrence.hpp"
#include "smtfactory.hpp"
#include "relevantvariables.hpp"
#include "accelerationproblem.hpp"
#include "redlog.hpp"
#include "export.hpp"

AccelerationViaQE::AccelerationViaQE(
        const LinearRule &rule,
        const Recurrence::Result<NondetUpdate> closed,
        ITSProblem &its): AccelerationTechnique(rule, closed, its) {}

std::vector<AccelerationTechnique::Accelerator> AccelerationViaQE::computeRes() {
    const bool tryNonterm = Config::Analysis::nonTermination() || Config::Analysis::complexity();
    Var m = its.getFreshUntrackedSymbol("m", Expr::Int);
    auto qelim = Qelim::solver(its);
    option<Qelim::Result> res;
    std::vector<Accelerator> ret;
    BoolExpr matrix = rule.getGuard()->toG();
    VarSet vars;
    VarMap<Expr> lb, ub;
    for (const auto &e: closed->update) {
        if (e.second.isDeterministic()) {
            matrix = matrix->subs({e.first, *e.second.getLower()});
        } else if (e.second.getLower() && !e.second.getUpper()) {
            matrix = matrix->subs({e.first, *e.second.getLower()});
        } else if (!e.second.getLower() && e.second.getUpper()) {
            matrix = matrix->subs({e.first, *e.second.getUpper()});
        } else {
            const Var var = its.getFreshUntrackedSymbol(e.first.get_name(), Expr::Int);
            vars.insert(var);
            if (e.second.getLower()) lb[var] = *e.second.getLower();
            if (e.second.getUpper()) ub[var] = *e.second.getUpper();
            matrix = matrix->subs({e.first, var});
        }
    }
    if (tryNonterm) {
        VarSet nontermVars(vars);
        VarMap<Expr> nontermLb(lb);
        nontermVars.insert(closed->n);
        nontermLb[closed->n] = closed->validityBound;
        QuantifiedFormula q = matrix->quantify({Quantifier(Quantifier::Type::Forall, nontermVars, nontermLb, ub)});
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
    matrix = matrix->subs({closed->n, m});
    vars.insert(m);
    lb[m] = closed->validityBound;
    ub[m] = closed->n - 1;
    const QuantifiedFormula q = matrix->quantify({Quantifier(Quantifier::Type::Forall, vars, lb, ub)});
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
