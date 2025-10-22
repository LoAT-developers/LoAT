#include "accelerationproblem.hpp"
#include "recurrence.hpp"
#include "smtfactory.hpp"
#include "theory.hpp"
#include "boolexpr.hpp"
#include "relevantvariables.hpp"
#include "config.hpp"

AccelerationProblem::PolyAccelMode AccelerationProblem::polyaccel {PolyAccelMode::LowDegree};

AccelerationProblem::AccelerationProblem(
        const RulePtr& rule,
        const std::optional<Recurrence::Result> &closed,
        const std::optional<Subs> &samplePoint,
        const AccelConfig &config):
    closed(closed),
    update(rule->getUpdate()),
    guard(rule->getGuard()),
    config(config),
    samplePoint(samplePoint) {
    for (const auto &l: guard->lits()) {
        std::visit(Overload {
            // TODO think about a better handling of equalities
            [&](const Arith::Lit &l) {
                if (l->isNeq()) {
                    throw std::invalid_argument("neq in acceleration problem");
                } else if (l->isEq()) {
                    todo.insert(arith::mkGeq(l->lhs(), arith::zero));
                    todo.insert(arith::mkLeq(l->lhs(), arith::zero));
                } else {
                    todo.insert(l);
                }
            },
            [&](const auto &l) {
                todo.insert(l);
            }
        }, l);
    }
    const auto subs {closed ? std::vector{update, closed->closed_form} : std::vector{update}};
    const auto logic {Smt::chooseLogic<LitSet, Subs>({todo}, subs)};
    this->solver = SmtFactory::modelBuildingSolver(logic);
    if (closed) {
        const auto bound {bools::mkLit(arith::mkGt(config.n, arith::zero))};
        this->solver->add(bound);
        this->res.formula.push_back(bound);
    }
}

bool AccelerationProblem::trivial(const Lit &lit) {
    if (update(lit) == top()) {
        res.formula.push_back(bools::mkLit(lit));
        if (Config::Analysis::doLogAccel()) {
            std::cout << lit << ": trivial" << std::endl;
        }
        solver->add(bools::mkLit(lit));
        return true;
    }
    return false;
}

bool AccelerationProblem::unchanged(const Lit &lit) {
    if (bools::mkLit(lit) == update(lit)) {
        res.formula.push_back(bools::mkLit(lit));
        if (Config::Analysis::doLogAccel()) {
            std::cout << lit << ": unchanged" << std::endl;
        }
        return true;
    }
    return false;
}

bool AccelerationProblem::polynomial(const Lit &lit) {
    if (polyaccel == PolyAccelMode::None || !closed || closed->prefix > 0 || !config.tryAccel || !std::holds_alternative<Arith::Lit>(lit)) {
        return false;
    }
    const auto &rel {std::get<Arith::Lit>(lit)};
    const auto nfold {rel->lhs()->subs(closed->closed_form)};
    const auto d {nfold->isPoly(config.n)};
    if (!d || d == 0) {
        return false;
    }
    const auto but_last {closed->closed_form.compose(Subs::build(config.n, config.n - arith::one))};
    bool low_degree {false};
    ArithLitSet guard;
    ArithLitSet covered;
    if (d == 0) {
        return false;
    } else if (d == 1) {
        const auto coeff {*nfold->coeff(config.n, 1)};
        if (const auto c {coeff->isRational()}) {
            if (***c > 0) {
                guard.insert(rel);
            } else {
                guard.insert(rel->subs(but_last));
                res.nonterm = false;
            }
        } else {
            guard.insert(rel);
            guard.insert(rel->subs(but_last));
            res.nonterm = false;
        }
        low_degree = true;
    } else if (d == 2) {
        const auto coeff {*nfold->coeff(config.n, 2)};
        if (const auto c {coeff->isRational()}) {
            if (***c < 0) {
                guard.insert(rel);
                guard.insert(rel->subs(but_last));
                res.nonterm = false;
                low_degree = true;
            }
        }
    }
    if (!low_degree) {
        if (!samplePoint || polyaccel != PolyAccelMode::Full) {
            return false;
        }
        std::vector derivatives {rel->lhs()};
        std::vector signs {(*rel->lhs()->subs(*samplePoint)->isRational())->getValue()};
        Arith::Expr diff {arith::zero};
        do {
            const auto &last {derivatives.back()};
            diff = last->subs(update) - last;
            derivatives.push_back(diff);
            signs.push_back((*diff->subs(*samplePoint)->isRational())->getValue());
        } while (!diff->isRational());
        for (unsigned i = 1; i < signs.size() - 1; ++i) {
            if (signs.at(i).is_zero()) {
                for (unsigned j = i + 1; j < signs.size(); ++j) {
                    if (!signs.at(j).is_zero()) {
                        signs[i] = signs[j];
                        break;
                    }
                }
            }
        }
        if (signs.at(1) > 0) {
            guard.insert(rel);
        } else {
            guard.insert(rel->subs(but_last));
            res.nonterm = false;
        }
        for (unsigned i = 1; i < derivatives.size() - 1; ++i) {
            if (signs.at(i) > 0) {
                covered.insert(arith::mkGeq(derivatives.at(i), arith::zero));
            } else {
                covered.insert(arith::mkLeq(derivatives.at(i), arith::zero));
            }
            if (signs.at(i+1) > 0) {
                // the i-th derivative is monotonically increasing at the sampling point
                if (signs.at(i) > 0) {
                    guard.insert(arith::mkGeq(derivatives.at(i), arith::zero));
                } else {
                    guard.insert(arith::mkLeq(derivatives.at(i)->subs(but_last), arith::zero));
                }
            } else {
                res.nonterm = false;
                if (signs.at(i) > 0) {
                    guard.insert(arith::mkGeq(derivatives.at(i)->subs(but_last), arith::zero));
                } else {
                    guard.insert(arith::mkLeq(derivatives.at(i), arith::zero));
                }
            }
        }
    }
    const auto g {bools::mkAnd(guard)};
    const auto c {bools::mkAnd(covered)};
    res.formula.push_back(g);
    res.covered.push_back(c);
    if (Config::Analysis::doLogAccel()) {
        std::cout << lit << ": polynomial acceleration yields " << g << std::endl;
        std::cout << "covered: " << c << std::endl;
    }
    solver->add(bools::mkLit(lit));
    return true;
}

bool AccelerationProblem::monotonicity(const Lit &lit) {
    if (!closed || !config.tryAccel) {
        return false;
    }
    auto success {false};
    const auto updated {update(lit)};
    solver->push();
    solver->add(updated);
    if (solver->check() == SmtResult::Sat) {
        solver->add(bools::mkLit(theory::negate(lit)));
        if (solver->check() == SmtResult::Unsat) {
            success = true;
            auto g {closed->closed_form(lit)->subs({{config.n->var(), arrays::update(config.n, config.n - arith::one)}})};
            if (closed->prefix > 0) {
                g = g && bools::mkLit(lit);
            }
            res.formula.push_back(g);
            if (Config::Analysis::doLogAccel()) {
                std::cout << lit << ": montonic decrease yields " << g << std::endl;
            }
            res.nonterm = false;
        }
    }
    solver->pop();
    return success;
}

bool AccelerationProblem::recurrence(const Lit &lit) {
    const auto updated {update(lit)};
    solver->push();
    solver->add(bools::mkLit(lit));
    solver->add(!updated);
    const auto success {solver->check() == SmtResult::Unsat};
    if (success) {
        const auto g {bools::mkLit(lit)};
        res.formula.push_back(g);
        if (Config::Analysis::doLogAccel()) {
            std::cout << lit << ": montonic increase yields " << g << std::endl;
        }
    }
    solver->pop();
    return success;
}

bool AccelerationProblem::eventualWeakDecrease(const Lit &lit) {
    if (!closed || !config.tryAccel || !std::holds_alternative<Arith::Lit>(lit)) {
        return false;
    }
    auto success {false};
    const auto &rel {std::get<Arith::Lit>(lit)};
    const auto updated {rel->lhs()->subs(update)};
    const auto dec {arith::mkGeq(rel->lhs(), updated)};
    solver->push();
    solver->add(bools::mkLit(dec));
    if (solver->check() == SmtResult::Sat) {
        const auto inc {arith::mkLt(updated, updated->subs(update))};
        solver->add(bools::mkLit(inc));
        if (solver->check() == SmtResult::Unsat) {
            success = true;
            const auto g {bools::mkAnd(std::vector{rel, rel->subs(closed->closed_form)->subs({{config.n->var(), arrays::update(config.n, config.n - arith::one)}})})};
            res.formula.push_back(g);
            if (Config::Analysis::doLogAccel()) {
                std::cout << rel << ": eventual decrease yields " << g << std::endl;
            }
            res.nonterm = false;
        }
    }
    solver->pop();
    return success;
}

bool AccelerationProblem::eventualIncrease(const Lit &lit, const bool strict) {
    if (!std::holds_alternative<Arith::Lit>(lit)) {
        return false;
    }
    // t > 0
    const auto &rel {std::get<Arith::Lit>(lit)};
    // up(t)
    const auto updated {rel->lhs()->subs(update)};
    // t <(=) up(t)
    const auto i = strict ? arith::mkLt(rel->lhs(), updated) : arith::mkLeq(rel->lhs(), updated);
    const auto inc {bools::mkLit(i)};
    solver->push();
    solver->add(inc);
    if (solver->check() == SmtResult::Sat) {
        // up(t) >(=) up^2(t)
        const auto d {strict ? arith::mkGeq(updated, updated->subs(update)) : arith::mkGt(updated, updated->subs(update))};
        const auto dec {bools::mkLit(d)};
        solver->push();
        solver->add(dec);
        const auto success {solver->check() == SmtResult::Unsat};
        solver->pop();
        if (success) {
            Bools::Expr g {bot()};
            Bools::Expr c {bot()};
            if (samplePoint && i->subs(*samplePoint)->isTriviallyFalse()) {
                if (!closed) {
                    solver->pop();
                    return false;
                }
                const auto s {closed->closed_form.compose(Subs::build(config.n, config.n->toExpr() - arith::one))};
                g = bools::mkAnd(std::vector{(!i)->subs(s), rel->subs(s)});
                c = bools::mkLit(!i);
                res.nonterm = false;
            } else {
                g = inc && bools::mkLit(rel);
                c = inc;
            }
            res.formula.push_back(g);
            res.covered.push_back(c);
            if (Config::Analysis::doLogAccel()) {
                std::cout << rel << ": eventual increase yields " << g << std::endl;
                std::cout << "covered: " << c << std::endl;
            }
            return true;
        }
    }
    solver->pop();
    return false;
}

bool AccelerationProblem::fixpoint(const Lit &lit) {
    if (config.tryAccel) {
        return false;
    }
    std::vector<Bools::Expr> eqs;
    for (const auto vars{util::RelevantVariables::find(theory::cells(lit), update)};
         const auto& v : vars) {
        if (!theory::apply(
            v,
            [&](const Bools::Var&) {
                // encoding equality for booleans introduces a disjunction
                return false;
            },
            [&](const ArithVarPtr& v) {
                eqs.push_back(bools::mkLit(arith::mkEq(v, v->subs(update))));
                return true;
            })) {
            return false;
        }
    }
    const auto c {bools::mkAnd(eqs)};
    if (c == bot() || (samplePoint && !c->subs(*samplePoint) == top())) {
        return false;
    }
    const auto g {c && bools::mkLit(lit)};
    solver->push();
    solver->add(g);
    if (solver->check() == SmtResult::Sat) {
        res.formula.push_back(g);
        res.covered.push_back(c);
        if (Config::Analysis::doLogAccel()) {
            std::cout << lit << ": fixpoint yields " << g << std::endl;
            std::cout << "covered: " << c << std::endl;
        }
        return true;
    }
    solver->pop();
    return false;
}

std::optional<AccelerationProblem::Accelerator> AccelerationProblem::computeRes() {
    auto progress {true};
    while (!todo.empty() && progress) {
        // try complete techniques exhaustively
        while (!todo.empty() && progress) {
            progress = false;
            for (auto it = todo.begin(); it != todo.end();) {
                solver->push();
                solver->add(bools::mkLit(*it));
                if (solver->check() != SmtResult::Sat) {
                    return {};
                }
                solver->pop();
                if (trivial(*it)
                    || unchanged(*it)
                    || polynomial(*it)
                    || recurrence(*it)
                    || monotonicity(*it)
                    || eventualWeakDecrease(*it)) {
                    solver->add(bools::mkLit(*it));
                    progress = true;
                    it = todo.erase(it);
                } else {
                    ++it;
                }
            }
        }
        // try incomplete techniques next
        for (auto it = todo.begin(); !progress && it != todo.end();) {
            solver->push();
            solver->add(bools::mkLit(*it));
            if (solver->check() != SmtResult::Sat) {
                return {};
            }
            solver->pop();
            if (eventualIncrease(*it, false) || eventualIncrease(*it, true)) {
                solver->add(bools::mkLit(*it));
                progress = true;
                it = todo.erase(it);
            } else {
                ++it;
            }
        }
        // only look for fixpoints if nothing else works
        for (auto it = todo.begin(); !progress && it != todo.end();) {
            solver->push();
            solver->add(bools::mkLit(*it));
            if (solver->check() != SmtResult::Sat) {
                return {};
            }
            solver->pop();
            if (fixpoint(*it)) {
                solver->add(bools::mkLit(*it));
                progress = true;
                it = todo.erase(it);
            } else {
                ++it;
            }
        }
    }
    if (progress) {
        if (res.nonterm && Config::Analysis::relative_termination()) {
            // if we analyze relative termination, ensure that the costs diverge
            const Lit lit{arith::mkGt(config.cost, arith::zero)};
            solver->add(bools::mkLit(lit));
            if (solver->check() != SmtResult::Sat) {
                res.nonterm = false;
            } else {
                // guard /\ cost > 0 is satisfiable, accelerate cost > 0
                // try complete techniques in any case
                if (!trivial(lit) && !unchanged(lit) && !polynomial(lit) && !recurrence(lit)) {
                    // complete techniques failed
                    if (config.tryAccel) {
                        // if we want to accelerate (and not just prove nonterm), give up...
                        res.nonterm = false;
                    } else if (!eventualIncrease(lit, false) && !eventualIncrease(lit, true) && !fixpoint(lit)) {
                        // ...otherwise, also try incomplete techniques
                        res.nonterm = false;
                    }
                }
            }
        }
        return res;
    }
    return {};
}
