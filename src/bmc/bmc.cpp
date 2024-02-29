#include "bmc.hpp"
#include "theory.hpp"
#include "preprocessing.hpp"
#include "smtfactory.hpp"
#include "config.hpp"
#include "export.hpp"

BMC::BMC(ITSProblem &its): its(its) {}

void BMC::unsat() {
    std::cout << "unsat" << std::endl;
    proof.append("reached error location at depth " + std::to_string(depth));
    proof.result("unsat");
    proof.print();
}

void BMC::sat() {
    std::cout << "sat" << std::endl;
    proof.append(std::to_string(depth) + "-fold unrolling of the transition relation is unsatisfiable");
    proof.result("sat");
    proof.print();
}

BoolExprPtr BMC::encode_transition(const TransIdx idx) {
    const auto up {idx->getUpdate()};
    std::vector<BoolExprPtr> res {idx->getGuard()};
    for (const auto &x: vars) {
        if (theory::isProgVar(x)) {
            res.push_back(theory::mkEq(theory::toExpr(post_vars.at(x)), up.get(x)));
        }
    }
    return bools::mkAnd(res);
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
    vars.insertAll(its.getVars());
    for (const auto &var: vars) {
        post_vars.emplace(var, theory::next(var));
    }
    std::vector<BoolExprPtr> inits;
    for (const auto &idx: its.getInitialTransitions()) {
        if (its.isSinkTransition(idx)) {
            switch (SmtFactory::check(idx->getGuard())) {
            case SmtResult::Sat:
                unsat();
                return;
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
    solver.add(bools::mkOr(inits));

    std::vector<BoolExprPtr> steps;
    for (const auto &r: its.getAllTransitions()) {
        if (its.isInitialTransition(&r) || its.isSinkTransition(&r)) {
            continue;
        }
        steps.push_back(encode_transition(&r));
    }
    const auto step {bools::mkOr(steps)};

    std::vector<BoolExprPtr> queries;
    for (const auto &idx: its.getSinkTransitions()) {
        if (!its.isInitialTransition(idx)) {
            queries.push_back(idx->getGuard());
        }
    }
    const auto query {bools::mkOr(queries)};

    Subs last_s;
    while (true) {
        Subs s;
        for (const auto &var: vars) {
            const auto &post_var {post_vars.at(var)};
            s.put(var, last_s.get(post_var));
            s.put(post_var, theory::toExpr(theory::next(post_var)));
        }
        last_s = s;
        solver.push();
        solver.add(s(query));
        switch (solver.check()) {
        case SmtResult::Sat:
            unsat();
            return;
        case SmtResult::Unknown:
            if (Config::Analysis::log && !approx) {
                std::cout << "got unknown from SMT solver -- approximating" << std::endl;
            }
            approx = true;
            break;
        case SmtResult::Unsat: {}
        }
        solver.pop();
        solver.add(s(step));
        ++depth;
        if (solver.check() == SmtResult::Unsat) {
            if (!approx) {
                sat();
            }
            return;
        }
        if (Config::Analysis::log) {
            std::cout << "depth: " << depth << std::endl;
        }
    }

}

void BMC::analyze(ITSProblem &its) {
    BMC(its).analyze();
}
