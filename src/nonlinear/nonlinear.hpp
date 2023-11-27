#pragma once
#include "linearsolver.hpp"

class NonLinearSolver {

private:

    // NonLinearSolver();  
    
public:

    static void analyze(ILinearSolver &linear_solver);

};

const std::vector<Clause> all_resolvents(const Clause& chc, const std::set<Clause>& facts);

void all_resolvents_aux(const Clause& chc, const std::set<FunApp>::iterator preds, const std::set<Clause>& facts, std::vector<Clause>& resolvents);
