#include "bmc.hpp"
#include "expr.hpp"
#include "preprocessing.hpp"
#include "smtfactory.hpp"
#include "config.hpp"
#include "export.hpp"

BMC::BMC(ITSProblem &its): its(its) {}

void BMC::unsat(const unsigned depth) {
    std::cout << "unsat" << std::endl;
    proof.append("reached error location at depth " + std::to_string(depth));
    proof.result("unsat");
    proof.print();
}

void BMC::sat(const unsigned depth) {
    std::cout << "sat" << std::endl;
    proof.append(std::to_string(depth) + "-fold unrolling of the transition relation is unsatisfiable");
    proof.result("sat");
    proof.print();
}

void BMC::analyze() {
    if (Config::Analysis::log) {
        std::cout << "initial ITS" << std::endl;
        its.print(std::cout);
    }
    proof.majorProofStep("Initial ITS", ITSProof(), its);
    const auto res {Preprocess::preprocess(its)};
    if (res) {
        proof.concat(res.getProof());
        if (Config::Analysis::log) {
            std::cout << "Simplified ITS" << std::endl;
            ITSExport::printForProof(its, std::cout);
        }
    }
    std::map<Var, Var> post_vars;
    const auto vars {its.getVars()};
    for (const auto &var: vars) {
        post_vars.emplace(var, expr::next(var));
    }
    std::vector<BoolExpr> inits;
    for (const auto &idx: its.getInitialTransitions()) {
        if (its.isSinkTransition(idx)) {
            switch (SmtFactory::check(idx->getGuard())) {
            case SmtResult::Sat:
                unsat(1);
                return;
            case SmtResult::Unknown:
                approx = true;
                break;
            case SmtResult::Unsat: {}
            }
        } else {
            const auto up {idx->getUpdate()};
            std::vector<BoolExpr> i {idx->getGuard()};
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
    for (const auto &r: its.getAllTransitions()) {
        if (its.isInitialTransition(&r) || its.isSinkTransition(&r)) {
            continue;
        }
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
            queries.push_back(idx->getGuard());
        }
    }
    const auto query {BExpression::buildOr(queries)};

    unsigned depth {0};
    while (true) {
        Subs subs;
        if (Config::Analysis::log) {
            std::cout << "depth: " << depth << std::endl;
        }
        ++depth;
        for (const auto &var: vars) {
            const auto &post_var {post_vars.at(var)};
            subs.put(var, subs.get(post_var));
            subs.put(post_var, expr::toExpr(expr::next(post_var)));
        }
        z3.push();
        z3.add(query->subs(subs));
        if (z3.check() == SmtResult::Sat) {
            unsat(depth);
            return;
        }
        z3.pop();
        z3.add(step->subs(subs));
        if (z3.check() == SmtResult::Unsat) {
            if (!approx) {
                sat(depth);
            }
            return;
        }
    }

}

void BMC::analyze(ITSProblem &its) {
    BMC(its).analyze();
}
