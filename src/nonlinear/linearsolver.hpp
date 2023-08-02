#pragma once
#include "clause.hpp"

namespace LinearSolver {
    enum Result { Unsat, Sat, Unknown, Pending };
}

/**
 * Any linear CHC solver that implements this interface (e.g. ADCL) is compatible with the 
 * non-linear CHC solver. The linear solver must also act as a data structure 
 * for the CHC problem. That is, it must store all available linear and non-linear
 * clauses. That way the non-linear solver is not only independent of the linear solver
 * but also the problem representation (e.g. ITS).
 */
class ILinearSolver {
    
public:

	// virtual destructor 
	virtual ~ILinearSolver() {}; 

	/**
	 * Let linear solver derive all (ideally non-redundant) facts it can derive with 
	 * the current linear clause set.
 	 */
	virtual const std::list<Clause> derive_new_facts() = 0;

	virtual LinearSolver::Result get_analysis_result() const = 0;

	/**
	 * Adds a new clauses to the linear solver in batch. The added clauses can be 
	 * linear or non-linear. 
	 */
    virtual void add_clauses(const std::list<Clause> &clauses) = 0;

	virtual const std::list<Clause> get_initial_facts() const = 0;

	virtual const std::list<Clause> get_non_linear_chcs() const = 0;

};
