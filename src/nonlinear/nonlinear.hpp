#pragma once
#include "linearsolver.hpp"

class NonLinearSolver {

private:

    // NonLinearSolver();  
    
public:

    static void analyze(const std::vector<Clause>& chcs);

};

const std::vector<Clause> all_resolvents(const Clause& chc, const std::set<Clause>& facts);

void all_resolvents_aux(const Clause& chc, const std::set<FunApp>::iterator preds, const std::set<Clause>& facts, std::vector<Clause>& resolvents);

const std::vector<Clause> normalize_all_preds(const std::vector<Clause>& chc_problem);

const std::optional<Clause> unilaterally_resolvable_with(const FunApp& pred, const std::set<Clause>& chcs);

const std::set<Clause> presolve(const std::vector<Clause>& chc_problem);
