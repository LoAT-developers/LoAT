#include "reverse.hpp"

CHCPtr reverse(const CHCPtr chcs) {
    auto res {std::make_shared<CHCProblem>()};
    for (const auto &c: chcs->get_clauses()) {
        std::vector<Bools::Expr> constr {c->get_constraint()};
        std::optional<LhsPtr> premise;
        if (const auto conc {c->get_conclusion()}) {
            std::vector<Var> lhs_args;
            for (const auto &arg: (*conc)->get_args()) {
                if (const auto &x {theory::is_var(arg)}) {
                    lhs_args.emplace_back(*x);
                } else {
                    const auto y {theory::next(arg)};
                    lhs_args.emplace_back(y);
                    constr.push_back(theory::mkEq(theory::toExpr(y), arg));
                }
            }
            premise = Lhs::mk((*conc)->get_pred(), lhs_args);
        }
        std::optional<FunAppPtr> conclusion;
        if (const auto prem {c->get_premise()}) {
            std::vector<Expr> rhs_args;
            for (const auto &x: (*prem)->get_args()) {
                rhs_args.emplace_back(theory::toExpr(x));
            }
            conclusion = FunApp::mk((*prem)->get_pred(), rhs_args);
        }
        res->add_clause(Clause::mk(premise, bools::mkAnd(constr), conclusion));
    }
    return res;
}
