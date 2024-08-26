#include "linearize.hpp"

Lhs linearize(const Lhs &f, Clause &c, std::vector<Bools::Expr> &constr) {
    std::vector<Var> args;
    VarSet arg_set;
    for (const auto &x: f.get_args()) {
        if (!arg_set.insert(x)) {
            const auto next {theory::next(x)};
            args.push_back(next);
            c.add_var(theory::getName(next), next);
            constr.push_back(theory::mkEq(theory::toExpr(x), theory::toExpr(next)));
        }
    }
    return Lhs(f.get_pred(), args);
}

FunApp linearize(const FunApp &f, Clause &c, std::vector<Bools::Expr> &constr) {
    std::vector<Expr> args;
    VarSet arg_set;
    for (const auto &x: f.get_args()) {
        const auto var {theory::is_var(x)};
        if (!var || !arg_set.insert(*var)) {
            const auto next {theory::next(x)};
            const auto next_arg {theory::toExpr(next)};
            args.push_back(next_arg);
            c.add_var(theory::getName(next), next);
            constr.push_back(theory::mkEq(next_arg, x));
        }
    }
    return FunApp(f.get_pred(), args);
}

Clause linearize(const Clause &c) {
    Clause res;
    std::vector<Bools::Expr> constraints {c.get_constraint()};
    if (c.get_premise()) {
        res.set_premise(linearize(*c.get_premise(), res, constraints));
    }
    if (c.get_conclusion()) {
        res.set_conclusion(linearize(*c.get_conclusion(), res, constraints));
    }
    res.set_constraint(bools::mkAnd(constraints));
    return res;
}

CHCProblem linearize(const CHCProblem &chcs) {
    CHCProblem res;
    for (const auto &c: chcs.get_clauses()) {
        res.add_clause(linearize(c));
    }
    return res;
}