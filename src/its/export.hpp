#pragma once

#include <ostream>
#include <string>

#include "itsproblem.hpp"


namespace ITSExport {
    /**
     * Print the given rule in a readable format, prefixed with its index (used for proof output)
     */
    void printLabeledRule(TransIdx rule, const ITSProblem &its, std::ostream &s);

    /**
     * Print the given rule in a readable format (used by printLabeledRule).
     * Note that colors are only used if colors is true and Config::Output::ColorInIts is true
     */
    void printRule(const Rule &rule, std::ostream &s, bool colors = true);

    /**
     * Prints the given guard in a readable format (constraints separated by &&)
     * Note that colors are only used if colors is true and Config::Output::ColorInIts is true
     */
    void printGuard(const BoolExpr guard, std::ostream &s, bool colors = true);

    /**
     * Prints the given cost expression (does not do much except for colors)
     * Note that colors are only used if colors is true and Config::Output::ColorInIts is true
     */
    void printCost(const Expr &cost, std::ostream &s, bool colors = true);

    /**
     * Prints the ITS problem in a readable but ugly format for debugging
     */
    void printDebug(const ITSProblem &its, std::ostream &s);

    /**
     * Print the ITS problem in a more readable format suitable for the proof output
     */
    void printForProof(const ITSProblem &its, std::ostream &s);

    void printKoAT(const ITSProblem &its, std::ostream &s);

}

std::ostream& operator<<(std::ostream &s, const ITSProblem &its);
