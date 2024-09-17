#include "bmc.hpp"
#include "theory.hpp"
#include "smtfactory.hpp"
#include "config.hpp"
#include "renaming.hpp"

BMC::BMC(ITSProblem &its): its(its), vars(its.getVars()) {
    for (const auto &var: vars) {
        post_vars.emplace(var, theory::next(var));
    }
}

void BMC::unsat() {
    std::cout << "unsat" << std::endl;
    if (Config::Analysis::log) {
        std::cout << "reached error location at depth " << depth << std::endl;
    }
}

void BMC::sat() {
    std::cout << "sat" << std::endl;
    if (Config::Analysis::log) {
        std::cout << depth << "-fold unrolling of the transition relation is unsatisfiable" << std::endl;
    }
}

Bools::Expr BMC::encode_transition(const TransIdx idx) {
    const auto up {idx->getUpdate()};
    std::vector<Bools::Expr> res {idx->getGuard()};
    for (const auto &x: vars) {
        if (theory::isProgVar(x)) {
            res.push_back(theory::mkEq(theory::toExpr(post_vars.at(x)), up.get(x)));
        }
    }
    return bools::mkAnd(res);
}

SmtResult BMC::analyze() {
    std::vector<Bools::Expr> inits;
    for (const auto &idx: its.getInitialTransitions()) {
        if (its.isSinkTransition(idx)) {
            switch (SmtFactory::check(idx->getGuard())) {
            case SmtResult::Sat:
                unsat();
                return SmtResult::Unsat;
            case SmtResult::Unknown:
                if (Config::Analysis::log) {
                    std::cout << "got unknown from SMT solver -- approximating" << std::endl;
                }
                approx = true;
                break;
            case SmtResult::Unsat: {}
            }
        } else {
            inits.push_back(encode_transition(idx));
        }
    }
    solver->add(bools::mkOr(inits));

    std::vector<Bools::Expr> steps;
    for (const auto &r: its.getAllTransitions()) {
        if (its.isInitialTransition(&r) || its.isSinkTransition(&r)) {
            continue;
        }
        steps.push_back(encode_transition(&r));
    }
    const auto step {bools::mkOr(steps)};

    std::vector<Bools::Expr> queries;
    for (const auto &idx: its.getSinkTransitions()) {
        if (!its.isInitialTransition(idx)) {
            queries.push_back(idx->getGuard());
        }
    }
    const auto query {bools::mkOr(queries)};

    Renaming last_s;
    while (true) {
        Renaming s;
        for (const auto &var: vars) {
            const auto &post_var {post_vars.at(var)};
            s.insert(var, last_s.get(post_var));
            s.insert(post_var, theory::next(post_var));
        }
        if (Config::Analysis::model) {
            renamings.emplace_back(last_s);
        }
        last_s = s;
        solver->push();
        solver->add(s(query));
        switch (solver->check()) {
        case SmtResult::Sat:
            unsat();
            return SmtResult::Unsat;
        case SmtResult::Unknown:
            if (Config::Analysis::log && !approx) {
                std::cout << "got unknown from SMT solver -- approximating" << std::endl;
            }
            approx = true;
            break;
        case SmtResult::Unsat: {}
        }
        solver->pop();
        solver->add(s(step));
        ++depth;
        if (solver->check() == SmtResult::Unsat) {
            if (approx) {
                return SmtResult::Unknown;
            } else {
                sat();
                return SmtResult::Sat;
            }
        }
        if (Config::Analysis::log) {
            std::cout << "depth: " << depth << std::endl;
        }
    }

}

ITSModel BMC::get_model() const {
    std::vector<Bools::Expr> steps;
    std::vector<Bools::Expr> inits;
    for (const auto &t: its.getAllTransitions()) {
        if (its.isInitialTransition(&t)) {
            inits.push_back(t.getGuard());
            continue;
        }
        if (its.isSinkTransition(&t)) {
            continue;
        }
        std::vector<Bools::Expr> conjuncts;
        conjuncts.emplace_back(t.getGuard());
        const auto &up {t.getUpdate()};
        for (const auto &[pre,post]: post_vars) {
            if (theory::isProgVar(pre)) {
                conjuncts.push_back(theory::mkEq(theory::toExpr(post), up.get(pre)));
            }
        }
        steps.push_back(bools::mkAnd(std::move(conjuncts)));
    }
    const auto step {bools::mkOr(steps)};
    const auto init {bools::mkOr(inits)};
    std::vector<Bools::Expr> res{init};
    Bools::Expr last{init};
    for (unsigned i = 0; i + 1 < depth; ++i) {
        const auto s1{renamings.at(i)};
        last = last && s1(step);
        Renaming s2;
        for (const auto &[pre,post]: post_vars) {
            if (theory::isProgVar(pre)) {
                s2.insert(s1.get(post), pre);
                s2.insert(pre, theory::next(pre));
            }
        }
        res.push_back(s2(last));
    }
    ITSModel model;
    const auto m {bools::mkOr(res)};
    for (const auto &l: its.getLocations()) {
        model.set_invariant(l, Subs::build<Arith>(its.getLocVar(), arith::mkConst(l))(m));
    }
    model.set_invariant(its.getInitialLocation(), top());
    return model;
}
