#ifndef RANKING_FUNCTION_PROBLEM
#define RANKING_FUNCTION_PROBLEM

#include "types.hpp"
#include "rule.hpp"
#include "option.hpp"
#include "variablemanager.hpp"
#include "proof.hpp"
#include "smt.hpp"

class RankingFunctionProblem {

private:

    std::vector<Expr> solution;
    RelSet todo;
    RelSet done;
    Subs up;
    RelSet guard;
    Proof proof;
    std::unique_ptr<Smt> solver;
    VariableManager &varMan;

    RankingFunctionProblem(
            const RelSet guard,
            const Subs &up,
            VariableManager &varMan);

    bool decrease();
    bool eventualDecrease();

public:

    static RankingFunctionProblem init(const LinearRule &r, VariableManager &varMan);
    std::vector<Expr> computeRes();
    Proof getProof() const;

};

#endif
