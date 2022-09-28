#include "rankingfunctionproblem.hpp"
#include "smtfactory.hpp"

RankingFunctionProblem::RankingFunctionProblem(
        const RelSet guard,
        const Subs &up,
        VariableManager &varMan): todo(guard), up(up), guard(guard), varMan(varMan) {
    Smt::Logic logic = Smt::chooseLogic<RelSet, ExprSubs>({todo}, {up.getExprSubs()});
    this->solver = SmtFactory::modelBuildingSolver(logic, varMan);
    this->proof.append(std::stringstream() << "searching recurrent set for " << buildAnd(guard) << " wrt. " << up);
}

RankingFunctionProblem RankingFunctionProblem::init(const LinearRule &r, VariableManager &varMan) {
    assert(r.getGuard()->isConjunction());
    return RankingFunctionProblem(
                r.getGuard()->toG()->lits(),
                r.getUpdate(),
                varMan);
}

bool RankingFunctionProblem::decrease() {
    for (auto it = todo.begin(); it != todo.end();) {
        const Rel rel = *it;
        const Rel dec = rel.lhs() > rel.lhs().subs(up.getExprSubs());
        BoolExprSet assumptions;
        BoolExprSet deps;
        solver->resetSolver();
        for (const auto& g: guard) {
            solver->add(g);
        }
        solver->add(!dec);
        if (solver->check() == Smt::Unsat) {
            solution.push_back(rel.lhs());
            std::stringstream ss;
            ss << rel << " is decreasing and bounded";
            proof.newline();
            proof.append(ss);
            todo.clear();
            return true;
        } else {
            ++it;
        }
    }
    return false;
}


bool RankingFunctionProblem::eventualDecrease() {
    for (auto it = todo.begin(); it != todo.end();) {
        const Rel rel = *it;
        const Expr updated = rel.lhs().subs(up.getExprSubs());
        const Rel dec = rel.lhs() > updated;
        BoolExprSet assumptions;
        BoolExprSet deps;
        solver->resetSolver();
        for (const auto& g: guard) {
            solver->add(g);
        }
        solver->add(dec);
        solver->add(!(updated > updated.subs(up.getExprSubs())));
        if (solver->check() == Smt::Unsat) {
            const Rel inc = updated - rel.lhs() >= 0;
            if (done.find(inc) != done.end()) {
                solution.push_back(updated);
                std::stringstream ss;
                ss << rel << " is eventually decreasing and bounded";
                proof.newline();
                proof.append(ss);
                guard.insert(inc);
                todo.insert(inc);
                done.insert(*it);
                todo.erase(it);
                return true;
            } else {
                ++it;
            }
        } else {
            ++it;
        }
    }
    return false;
}

std::vector<Expr> RankingFunctionProblem::computeRes() {
    do {
        if (decrease()) {
            return solution;
        }
    } while (eventualDecrease() && !todo.empty());
    return {};
}

Proof RankingFunctionProblem::getProof() const {
    return proof;
}
