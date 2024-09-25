#include "linearize.hpp"

LhsPtr linearize(const LhsPtr f, std::vector<Bools::Expr> &constr) {
    std::vector<Var> args;
    VarSet arg_set;
    for (const auto &x: f->get_args()) {
        if (!arg_set.insert(x)) {
            const auto next {theory::next(x)};
            args.push_back(next);
            constr.push_back(theory::mkEq(theory::toExpr(x), theory::toExpr(next)));
        }
    }
    return Lhs::mk(f->get_pred(), args);
}

FunAppPtr linearize(const FunAppPtr f, std::vector<Bools::Expr> &constr) {
    std::vector<Expr> args;
    VarSet arg_set;
    for (const auto &x: f->get_args()) {
        const auto var {theory::is_var(x)};
        if (!var || !arg_set.insert(*var)) {
            const auto next {theory::next(x)};
            const auto next_arg {theory::toExpr(next)};
            args.push_back(next_arg);
            constr.push_back(theory::mkEq(next_arg, x));
        }
    }
    return FunApp::mk(f->get_pred(), args);
}

ClausePtr linearize(const ClausePtr c) {
    std::optional<LhsPtr> premise;
    std::optional<FunAppPtr> conclusion;
    std::vector<Bools::Expr> constraints {c->get_constraint()};
    if (const auto prem {c->get_premise()}) {
        premise = linearize(*prem, constraints);
    }
    if (const auto conc {c->get_conclusion()}) {
        conclusion = linearize(*conc, constraints);
    }
    return Clause::mk(premise, bools::mkAnd(constraints), conclusion);
}

CHCPtr linearize(const CHCPtr chcs) {
    auto res {std::make_shared<CHCProblem>()};
    for (const auto &c: chcs->get_clauses()) {
        res->add_clause(linearize(c));
    }
    return res;
}
