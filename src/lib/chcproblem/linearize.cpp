#include "linearize.hpp"

FunApp linearize(const FunApp &f, Clause &c, std::vector<Bools::Expr> &constr) {
    std::vector<Var> args;
    VarSet arg_set;
    for (const auto &x: f.args) {
        if (!arg_set.insert(x)) {
            const auto next {theory::next(x)};
            args.push_back(next);
            c.vars.emplace(theory::getName(next), next);
            constr.push_back(theory::mkEq(theory::toExpr(x), theory::toExpr(next)));
        }
    }
    return FunApp(f.pred, args);
}

Clause linearize(const Clause &c) {
    Clause res;
    std::vector<Bools::Expr> constraints {c.constraint};
    if (c.premise) {
        res.premise = linearize(*c.premise, res, constraints);
    }
    if (c.conclusion) {
        res.conclusion = linearize(*c.conclusion, res, constraints);
    }
    res.constraint = bools::mkAnd(constraints);
    return res;
}

CHCProblem linearize(const CHCProblem &chcs) {
    CHCProblem res;
    for (const auto &c: chcs.get_clauses()) {
        res.add_clause(linearize(c));
    }
    return res;
}