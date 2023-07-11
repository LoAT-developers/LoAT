#include "bmc.hpp"
#include "expr.hpp"
#include "preprocessing.hpp"
#include "smtfactory.hpp"

const bool BMC::log {true};

BMC::BMC(const ITSProblem &its): its(its) {}

void BMC::analyze() {
    if (log) {
        its.print(std::cout);
    }
    const auto res {Preprocess::preprocess(its)};
    if (log && res) {
        res.print();
    }
    std::map<Var, Var> post_vars;
    const auto vars {its.getVars()};
    for (const auto &var: vars) {
        post_vars.emplace(var, expr::next(var));
    }
    std::vector<BoolExpr> inits;
    for (const auto &idx: its.getInitialTransitions()) {
        const auto r {its.getRule(idx)};
        if (its.isSinkTransition(idx)) {
            switch (SmtFactory::check(r.getGuard())) {
            case SmtResult::Sat:
                std::cout << "unsat" << std::endl;
                return;
            case SmtResult::Unknown:
                approx = true;
                break;
            case SmtResult::Unsat: {}
            }
        } else {
            const auto up {r.getUpdate()};
            std::vector<BoolExpr> i {r.getGuard()};
            for (const auto &x: vars) {
                if (expr::isProgVar(x)) {
                    i.push_back(expr::mkEq(expr::toExpr(post_vars.at(x)), up.get(x)));
                }
            }
            inits.push_back(BExpression::buildAnd(i));
        }
    }
    z3.add(BExpression::buildOr(inits));

    std::vector<BoolExpr> steps;
    for (const auto &idx: its.getAllTransitions()) {
        if (its.isInitialTransition(idx) || its.isSinkTransition(idx)) {
            continue;
        }
        const auto r {its.getRule(idx)};
        const auto up {r.getUpdate()};
        std::vector<BoolExpr> s {r.getGuard()};
        for (const auto &x: vars) {
            if (expr::isProgVar(x)) {
                s.push_back(expr::mkEq(expr::toExpr(post_vars.at(x)), up.get(x)));
            }
        }
        steps.push_back(BExpression::buildAnd(s));
    }
    const auto step {BExpression::buildOr(steps)};

    std::vector<BoolExpr> queries;
    for (const auto &idx: its.getSinkTransitions()) {
        if (!its.isInitialTransition(idx)) {
            const auto r {its.getRule(idx)};
            queries.push_back(r.getGuard());
        }
    }
    const auto query {BExpression::buildOr(queries)};

    Subs subs;
    unsigned depth {1};
    while (true) {
        if (log) {
            std::cout << "depth: " << depth << std::endl;
            ++depth;
        }
        for (const auto &var: vars) {
            const auto &post_var {post_vars.at(var)};
            subs.put(var, subs.get(post_var));
            subs.put(post_var, expr::toExpr(expr::next(post_var)));
        }
        z3.push();
        z3.add(query->subs(subs));
        if (z3.check() == SmtResult::Sat) {
            std::cout << "unsat" << std::endl;
            return;
        }
        z3.pop();
        z3.add(step->subs(subs));
        if (z3.check() == SmtResult::Unsat) {
            if (!approx) {
                std::cout << "sat" << std::endl;
            }
            return;
        }
    }

}

void BMC::analyze(const ITSProblem &its) {
    BMC(its).analyze();
}
