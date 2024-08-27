#include "reverse.hpp"

CHCProblem reverse(const CHCProblem &chcs) {
    CHCProblem res;
    for (const auto &c: chcs.get_clauses()) {
        std::vector<Bools::Expr> constr {c.get_constraint()};
        Clause reversed;
        if (const auto conc {c.get_conclusion()}) {
            std::vector<Var> lhs_args;
            for (const auto &arg: conc->get_args()) {
                if (const auto &x {theory::is_var(arg)}) {
                    lhs_args.emplace_back(*x);
                } else {
                    const auto y {theory::next(arg)};
                    lhs_args.emplace_back(y);
                    constr.push_back(theory::mkEq(theory::toExpr(y), arg));
                }
            }
            reversed.set_premise(Lhs(conc->get_pred(), lhs_args));
        }
        if (const auto prem {c.get_premise()}) {
            std::vector<Expr> rhs_args;
            for (const auto &x: prem->get_args()) {
                rhs_args.emplace_back(theory::toExpr(x));
            }
            reversed.set_conclusion(FunApp(prem->get_pred(), rhs_args));
        }
        reversed.set_constraint(bools::mkAnd(constr));
        res.add_clause(reversed);
    }
    return res;
}