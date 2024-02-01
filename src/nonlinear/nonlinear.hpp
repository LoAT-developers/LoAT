#pragma once
#include "linearsolver.hpp"

class NonLinearSolver {

private:

    // NonLinearSolver();  
    
public:

    static void analyze(const std::vector<Clause>& chcs);

};

const std::set<Clause> all_resolvents(const std::set<Clause>& non_linear_chcs, const std::set<Clause>& facts);

void all_resolvents_aux(
    const Clause& chc, 
    unsigned pred_index, 
    const std::set<Clause>& facts, 
    std::set<Clause>& resolvents, 
    unsigned& redundant_resolvent_count
);

const Clause merge_facts(const std::vector<Clause> facts);

const std::vector<Clause> normalize_all_preds(const std::vector<Clause>& chc_problem);

const std::optional<Clause> unilaterally_resolvable_with(const FunApp& pred, const std::set<Clause>& chcs);

const std::set<Clause> presolve(const std::vector<Clause>& chc_problem);
