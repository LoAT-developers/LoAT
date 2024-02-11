#include "theory.hpp"
#include "types.hpp"
#include <vector>

class FunApp {

public:
    const std::basic_string<char> name;
    const std::vector<Var> args;

    FunApp(
        const std::basic_string<char> name,
        const std::vector<Var> args
    ): name(name), args(args) {}

    const FunApp renameWith(const Subs &renaming) const;

    const VarSet vars() const;

    unsigned long intArity() const;

    unsigned long boolArity() const;
};

class Clause {

public:
    const std::vector<FunApp> lhs;
    const std::optional<FunApp> rhs;
    const BoolExpr guard;

    /**
     * Constructor for a Constrained Horn Clause (CHC). For example:
     * 
     *    F(x1) /\ G(x2,x3) /\ (x1 < x2 /\ x2 < x3)   ==>   H(x1,x2,x3)
     *    
     *    ^^^^^^^^^^^^^^^^^    ^^^^^^^^^^^^^^^^^^^^         ^^^^^^^^^^^
     *           lhs                  guard                     rhs
     *
     * @param lhs - a set of predicates on the left-hand-side (LHS) of the implication.
     * @param rhs - an optional predicate on the right-hand-side (RHS) of the implication.
     * @param guard - a boolean expression describing the clause constraint.
     */
    Clause(
        const std::vector<FunApp> lhs, 
        const std::optional<FunApp> rhs, 
        const BoolExpr guard
    ) : lhs(lhs), rhs(rhs), guard(guard) {}

    const Clause renameWith(const Subs &renaming) const;

    const std::optional<Clause> resolutionWith(const Clause &chc, unsigned pred_index) const;

    const Clause normalize() const;

    bool isLinear() const;

    bool isFact() const;

    bool isQuery() const;
    
    const VarSet vars() const;

    std::optional<unsigned> indexOfLHSPred(const std::basic_string<char> name) const;
};

const std::tuple<std::set<Clause>, std::set<Clause>> partitionByDegree(const std::set<Clause>& chcs);

const std::map<std::basic_string<char>, std::set<Clause>> partitionFactsByRHS(const std::set<Clause>& facts);

const std::tuple<std::set<Clause>, std::set<Clause>> partitionFacts(const std::set<Clause>& chcs);

const std::map<std::optional<std::basic_string<char>>, std::vector<Clause>> partitionByRHS(const std::set<Clause>& chcs);

const std::optional<Subs> computeUnifier(const FunApp &pred1, const FunApp &pred2);
const std::optional<Subs> computeUnifier(const std::vector<Var> &args1, const std::vector<Var> &args2);

const std::pair<unsigned long, unsigned long> maxArity(const std::vector<Clause>& chc_problem);

bool allLinear(const std::vector<Clause>& chcs);

// implement comparison operators so they can be stored in std::set
bool operator<(const Clause &c1, const Clause &c2);
bool operator<(const FunApp &fun1, const FunApp &fun2);

std::ostream& operator<<(std::ostream &s, const FunApp &fun_app);

std::ostream& operator<<(std::ostream &s, const Clause &chc);

std::ostream& printSimple(std::ostream &s, const Clause &chc);
