#include "accelerationproblem_naive.hpp"
#include "recurrence.hpp"
#include "smtfactory.hpp"
#include "relevantvariables.hpp"

AccelerationProblem::AccelerationProblem(
        const BoolExpr guard,
        const Subs &up,
        option<const Subs&> closed,
        const Expr &cost,
        const Expr &iteratedCost,
        const Var &n,
        const unsigned int validityBound,
        ITSProblem &its): todo(guard->lits()), up(up), closed(closed), cost(cost), iteratedCost(iteratedCost), n(n), guard(guard), validityBound(validityBound), its(its) {
    res = buildLit(n >= validityBound);
    std::vector<Subs> subs = closed.map([&up](auto const &closed){return std::vector<Subs>{up, closed};}).get_value_or({up});
    Smt::Logic logic = Smt::chooseLogic<RelSet, Subs>({todo}, subs);
    this->solver = SmtFactory::modelBuildingSolver(logic, its);}

option<AccelerationProblem> AccelerationProblem::init(const LinearRule &r, ITSProblem &its) {
    const Var &n = its.addFreshTemporaryVariable("n");
    const option<Recurrence::Result> &res = Recurrence::iterateRule(its, r, n);
    if (res) {
        return {AccelerationProblem(
                        r.getGuard()->toG(),
                        r.getUpdate(),
                        option<const Subs&>(res->update),
                        r.getCost(),
                        res->cost,
                        n,
                        res->validityBound,
                        its)};
    } else {
        return {AccelerationProblem(
                        r.getGuard()->toG(),
                        r.getUpdate(),
                        option<const Subs&>(),
                        r.getCost(),
                        r.getCost(),
                        n,
                        0,
                        its)};
    }
}

AccelerationProblem AccelerationProblem::initForRecurrentSet(const LinearRule &r, ITSProblem &its) {
    return AccelerationProblem(
                r.getGuard()->toG(),
                r.getUpdate(),
                option<const Subs&>(),
                r.getCost(),
                r.getCost(),
                its.addFreshTemporaryVariable("n"),
                0,
                its);
}

bool AccelerationProblem::monotonicity(const Rel &rel) {
    if (closed) {
        solver->resetSolver();
        solver->add(done);
        solver->add(rel.subs(up));
        if (solver->check() == Smt::Sat) {
            solver->add(!buildLit(rel));
            if (solver->check() == Smt::Unsat) {
                Rel newCond = rel.subs(closed.get()).subs(Subs(n, n-1));
                res = res & newCond;
                nonterm = false;
                std::stringstream ss;
                ss << "discharged " << rel << " with monotonic decrease, got " << newCond;
                proof.newline();
                proof.append(ss);
                return true;
            }
        }
    }
    return false;
}

bool AccelerationProblem::recurrence(const Rel &rel) {
    solver->resetSolver();
    solver->add(done);
    solver->add(rel);
    solver->add(!buildLit(rel.subs(up)));
    if (solver->check() == Smt::Unsat) {
        res = res & rel;
        std::stringstream ss;
        ss << "discharged " << rel << " with monotonic increase, got " << rel;
        proof.newline();
        proof.append(ss);
        return true;
    }
    return false;
}

bool AccelerationProblem::eventualWeakDecrease(const Rel &rel) {
    if (closed) {
        const Expr &updated = rel.lhs().subs(up);
        const Rel &dec = rel.lhs() >= updated;
        solver->resetSolver();
        solver->add(done);
        solver->add(dec);
        if (solver->check() == Smt::Sat) {
            const Rel &dec_dec = updated >= updated.subs(up);
            solver->add(!dec_dec);
            if (solver->check() == Smt::Unsat) {
                BoolExpr newCond = buildLit(rel) & rel.subs(closed.get()).subs(Subs(n, n-1));
                res = res & newCond;
                nonterm = false;
                std::stringstream ss;
                ss << "discharged " << rel << " with eventual decrease, got " << newCond;
                proof.newline();
                proof.append(ss);
                return true;
            }
        }
    }
    return false;
}

bool AccelerationProblem::eventualWeakIncrease(const Rel &rel) {
    const Expr &updated = rel.lhs().subs(up);
    const Rel &inc = rel.lhs() <= updated;
    solver->resetSolver();
    solver->add(done);
    solver->add(inc);
    if (solver->check() == Smt::Sat) {
        const Rel &inc_inc = updated <= updated.subs(up);
        solver->add(!inc_inc);
        if (solver->check() == Smt::Unsat) {
            res = res & inc & rel;
            std::stringstream ss;
            ss << "discharged " << rel << " with eventual increase, got " << (buildLit(inc) & rel);
            proof.newline();
            proof.append(ss);
            return true;
        }
    }
    return false;
}

bool AccelerationProblem::fixpoint(const Rel &rel) {
    RelSet eqs;
    VarSet vars = util::RelevantVariables::find(rel.vars(), {up}, True);
    for (const Var& var: vars) {
        eqs.insert(Rel::buildEq(var, Expr(var).subs(up)));
    }
    BoolExpr allEq = buildAnd(eqs);
    if (Smt::check(guard & allEq, its) == Smt::Sat) {
        res = res & allEq & rel;
        std::stringstream ss;
        ss << "discharged " << rel << " with fixpoint, got " << allEq;
        proof.newline();
        proof.append(ss);
        return true;
    }
    return false;
}

std::vector<AccelerationProblem::Result> AccelerationProblem::computeRes() {
    this->proof.append(std::stringstream() << "accelerating " << guard << " wrt. " << up);
    bool changed;
    do {
        changed = false;
        auto it = todo.begin();
        while (it != todo.end()) {
            if (recurrence(*it) || monotonicity(*it) || eventualWeakDecrease(*it) || eventualWeakIncrease(*it) || fixpoint(*it)) {
                done = done & *it;
                it = todo.erase(it);
                changed = true;
            } else {
                it++;
            }
        }
    } while (changed);
    std::vector<Result> result;
    if (todo.empty()) {
        bool positiveCost = Config::Analysis::mode != Config::Analysis::Mode::Complexity || Smt::isImplication(guard, buildLit(cost > 0), its);
        if (Smt::check(res & (n >= validityBound), its) == Smt::Sat) {
            result.push_back({res, nonterm && positiveCost});
        }
        if (!nonterm && closed && positiveCost) {
            proof.newline();
            proof.append("done, trying nonterm");
            todo = guard->lits();
            done = True;
            res = True;
            do {
                changed = false;
                auto it = todo.begin();
                while (it != todo.end()) {
                    if (recurrence(*it) || eventualWeakIncrease(*it) || fixpoint(*it)) {
                        done = done & *it;
                        it = todo.erase(it);
                        changed = true;
                    } else {
                        it++;
                    }
                }
            } while (changed);
            if (todo.empty() && Smt::check(res, its) == Smt::Sat) {
                result.push_back({res, true});
            }
        }
    }
    return result;
}

Proof AccelerationProblem::getProof() const {
    return proof;
}

Expr AccelerationProblem::getAcceleratedCost() const {
    return iteratedCost;
}

option<Subs> AccelerationProblem::getClosedForm() const {
    return closed;
}

Var AccelerationProblem::getIterationCounter() const {
    return n;
}

unsigned int AccelerationProblem::getValidityBound() const {
    return validityBound;
}
