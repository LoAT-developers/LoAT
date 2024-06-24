#pragma once
#include "clause.hpp"

namespace LinearSolver {
    enum Result { Unsat, Sat, Unknown, Pending };
    enum ConstraintTier { Linear, Polynomial, Exponential };

	/**
	 * Fixed list of all constraint tiers in order of solving difficulty. 
	 */
    const std::vector<LinearSolver::ConstraintTier> constraint_tiers = {
        LinearSolver::ConstraintTier::Linear,
        LinearSolver::ConstraintTier::Polynomial,
        LinearSolver::ConstraintTier::Exponential
    };
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
	 *
	 * The argument `max_constr_tier` can be set to `Linear`, `Polynomial` or `Exponential`.
	 * Here "linear" does NOT refer the the plurality of left-hand-side predicates but the
	 * clause constraint. For example:
	 *
	 *  - linear constraint      : F(x) /\ 2*x=4 ==> F(x)
	 *  - polynomial constraint  : F(x) /\ x^2=4 ==> F(x)
	 *  - exponential constraint : F(x) /\ 2^x=4 ==> F(x)
     *
	 * If the argument is set to `Linear` the solver should only derive facts with linear 
	 * constraint. If the argument is set to `Polynomial`, only polynomial facts should be
	 * derived. This includes linear facts, since linear constraints are also polynomial.
	 * Polynomial constraints are also exponential, so the argument `Exponential` instructs
	 * the solver to derive arbitrary constraints.
	 *
	 * The distinction is for optimization. Because the constraint tiers are successively
	 * harder to deal with for SMT solvers, we can first try to solve a CHC instance by only
	 * considering "easy" linear constraints and only consider harder polynomial and exponential
	 * constraints if necessary.
	 */
	virtual const std::set<Clause> derive_new_facts(
		LinearSolver::ConstraintTier max_constr_tier
	) = 0;

	/**
	 * Return current status of the solver. Status Unknown or Sat should be reset to 
	 * Pending, when new clauses are added via `add_clauses`. The status Unsat should
	 * be considered final.
	 */
	virtual LinearSolver::Result get_analysis_result() const = 0;

	/**
	 * Adds new clauses to the solver in batch. The added clauses must be linear. 
	 */
    virtual void add_clauses(const std::set<Clause> &clauses) = 0;

};
