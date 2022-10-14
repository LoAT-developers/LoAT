#pragma once

#include "expression.hpp"
#include "theory.hpp"

#include <mutex>

/**
 * Manages variables, i.e., can map between variable indices, names and symbols.
 * Also manages the set of temporary/free variables.
 *
 * This class is used as a part of an ITSProblem, but is separate since many functions
 * only need variable management, not the full ITSProblem.
 */
class VariableManager {
public:

    // Handling of temporary variables
    bool isTempVar(const Var &var) const;

    // Useful to iterate over all variables (for printing/debugging)
    VarSet getVars() const;

    option<Var> getVar(std::string name) const;

    /**
     * Generates a fresh (unused) symbol, but does _not_ add it to the list of variables
     *
     * @warning The name of the created symbol is not stored, so it may be re-used by future calls!
     * Note that two generated symbols are always different, even if they use the same name.
     *
     * @return The newly created symbol (_not_ associated with a variable index!)
     */
    template<ITheory Th>
    typename Th::Var getFreshUntrackedSymbol(std::string basename, Expr::Type type) {
        std::lock_guard guard(mutex);
        typename Th::Var res(getFreshName(basename));
        variableNameLookup.emplace(theory::getName(res), res);
        untrackedVariables[res] = type;
        return res;
    }

    Expr::Type getType(const Var &x) const;

    static std::recursive_mutex mutex;

private:

    void toLower(std::string &str) const;

    // Adds a variable with the given name to all relevant maps, returns the new index
    template<ITheory Th>
    typename Th::Var addVariable(std::string name) {
        std::lock_guard guard(mutex);
        toLower(name);
        typename Th::Var sym(name);
        variables.insert(sym);
        variableNameLookup.emplace(name, sym);
        return sym;
    }

    // Generates a yet unused name starting with the given string
    std::string getFreshName(std::string basename);

public:

    /**
     * Adds a new fresh variable based on the given name
     * (the given name is used if it is still available, otherwise it is modified)
     * @return the VariableIdx of the newly added variable
     */
    template<ITheory Th>
    typename Th::Var addFreshVariable(std::string basename) {
        std::lock_guard guard(mutex);
        return addVariable<Th>(getFreshName(basename));
    }

    template<ITheory Th>
    typename Th::Var addFreshTemporaryVariable(std::string basename) {
        std::lock_guard guard(mutex);
        typename Th::Var x = addVariable<Th>(getFreshName(basename));
        temporaryVariables.insert(theory::getName<Th>(x));
        return x;
    }

    template<ITheory... Th>
    std::pair<QuantifiedFormula<Th...>, theory::Subs<Th...>> normalizeVariables(const QuantifiedFormula<Th...> &f);

private:
    // List of all variables (VariableIdx is an index in this list; a Variable is a name and a symbol)
    // Note: Variables are never removed, so this list is appended, but otherwise not modified
    VarSet variables;
    std::map<Var, Expr::Type> untrackedVariables;

    // The set of variables (identified by their index) that are used as temporary variables (not bound by lhs)
    std::set<std::string> temporaryVariables;

    std::map<std::string, unsigned int> basenameCount;
    // Reverse mapping for efficiency
    std::map<std::string, Var> variableNameLookup;
    std::set<std::string> used;
};

using VarMan = VariableManager;
