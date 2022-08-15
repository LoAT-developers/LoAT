#ifndef VARIABLEMANAGER_H
#define VARIABLEMANAGER_H

#include "types.hpp"
#include "expression.hpp"

#include <mutex>

// Abbreviation since the VariableManager is passed around quite a bit
class VariableManager;
typedef VariableManager VarMan;


/**
 * Manages variables, i.e., can map between variable indices, names and GiNaC symbols.
 * Also manages the set of temporary/free variables.
 *
 * This class is used as a part of an ITSProblem, but is separate since many functions
 * only need variable management, not the full ITSProblem.
 */
class VariableManager {
public:

    // Handling of temporary variables
    const VarSet& getTempVars() const;
    bool isTempVar(const Var &var) const;

    // Useful to iterate over all variables (for printing/debugging)
    VarSet getVars() const;

    option<Var> getVar(std::string name) const;

    /**
     * Adds a new fresh variable based on the given name
     * (the given name is used if it is still available, otherwise it is modified)
     * @return the VariableIdx of the newly added variable
     */
    Var addFreshVariable(std::string basename);
    Var addFreshTemporaryVariable(std::string basename);

    /**
     * Generates a fresh (unused) GiNaC symbol, but does _not_ add it to the list of variables
     *
     * @warning The name of the created symbol is not stored, so it may be re-used by future calls!
     * Note that two generated symbols are always different (to GiNac), even if they use the same name.
     *
     * @return The newly created symbol (_not_ associated with a variable index!)
     */
    Var getFreshUntrackedSymbol(std::string basename, Expr::Type type);

    Expr::Type getType(const Var &x) const;

    static std::recursive_mutex mutex;

private:
    // Adds a variable with the given name to all relevant maps, returns the new index
    Var addVariable(std::string name);

    // Generates a yet unused name starting with the given string
    std::string getFreshName(std::string basename);

private:
    // Data stored for each variable
    struct Variable {
        std::string name;
        Var symbol;
    };

    // List of all variables (VariableIdx is an index in this list; a Variable is a name and a ginac symbol)
    // Note: Variables are never removed, so this list is appended, but otherwise not modified
    VarSet variables;
    VarMap<Expr::Type> untrackedVariables;

    // The set of variables (identified by their index) that are used as temporary variables (not bound by lhs)
    VarSet temporaryVariables;

    std::map<std::string, unsigned int> basenameCount;
    // Reverse mapping for efficiency
    std::map<std::string, Var> variableNameLookup;

    unsigned int boolVarCount = 1;
};





#endif //VARIABLEMANAGER_H
