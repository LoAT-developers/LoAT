#pragma once

#include "numexpression.hpp"
#include "theory.hpp"
#include "variable.hpp"

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
        typename Th::Var res {getFreshName(basename)};
        untrackedVariables[res] = type;
        return res;
    }

    Var getFreshUntrackedSymbol(const Var &x) {
        std::lock_guard guard(mutex);
        const std::string name = getFreshName(variable::getName(x));
        option<Var> res;
        Expr::Type type;
        if (std::holds_alternative<NumVar>(x)) {
            type = Expr::Int;
            res = NumVar(name);
        } else if (std::holds_alternative<BoolVar>(x)) {
            type = Expr::Int;
            res = BoolVar(name);
        } else {
            throw std::invalid_argument("unsupported variable type");
        }
        untrackedVariables[*res] = type;
        return *res;
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
        typename Th::Var sym {name};
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
        temporaryVariables.insert(x.getName());
        return x;
    }

    Var addFreshTemporaryVariable(const Var &var) {
        std::lock_guard guard(mutex);
        const auto name = getFreshName(variable::getName(var));
        Var x = std::visit(
                    Overload{
                        [this, &name](const NumVar &var) {
                            return Var(addVariable<IntTheory>(name));
                        },
                        [this, &name](const BoolVar &var) {
                            return Var(addVariable<BoolTheory>(name));
                        }
                    }, var);
        temporaryVariables.insert(name);
        return x;
    }

    std::pair<QuantifiedFormula<IntTheory>, theory::Subs<IntTheory>> normalizeVariables(const QuantifiedFormula<IntTheory> &f) {
        {
            const auto matrix = f.getMatrix();
            std::set<NumVar> vars = matrix->vars().get<NumVar>();
            ExprSubs normalization, inverse;
            unsigned count = 0;
            for (const NumVar &x: vars) {
                ++count;
                std::string varName = "x" + std::to_string(count);
                const NumVar replacement = NumVar(varName);
                normalization.put(x, replacement);
                inverse.put(replacement, x);
            }
            const auto newMatrix = matrix->subs(normalization);
            std::vector<Quantifier> newPrefix;
            for (const auto& q: f.getPrefix()) {
                std::set<NumVar> newVars;
                std::map<NumVar, Expr> newLowerBounds;
                std::map<NumVar, Expr> newUpperBounds;
                for (const auto& x: q.getVars()) {
                    if (vars.find(x) != vars.end()) {
                        newVars.insert(normalization.get(x).toVar());
                        auto lb = q.lowerBound(x);
                        auto ub = q.upperBound(x);
                        if (lb) {
                            newLowerBounds[x] = lb.get();
                        }
                        if (ub) {
                            newUpperBounds[x] = ub.get();
                        }
                    }
                }
                if (!newVars.empty()) {
                    newPrefix.push_back(Quantifier(q.getType(), newVars, newLowerBounds, newUpperBounds));
                }
            }
            return {QuantifiedFormula(newPrefix, newMatrix), inverse};
        }

    }

private:
    std::map<Var, Expr::Type> untrackedVariables;

    // The set of variables (identified by their index) that are used as temporary variables (not bound by lhs)
    std::set<std::string> temporaryVariables;

    std::map<std::string, unsigned int> basenameCount;
    std::set<std::string> used;
};

using VarMan = VariableManager;
