#pragma once

#include <ostream>
#include <string>

#include "rule.hpp"


namespace RuleExport {

void printColor(std::ostream &os, const std::string &s);

/**
     * Print the given rule in a readable format.
     * Note that colors are only used if colors is true and Config::Output::ColorInIts is true
     */
void printRule(const Rule &rule, std::ostream &s, bool colors = true);

/**
     * Prints the given guard in a readable format (constraints separated by &&)
     * Note that colors are only used if colors is true and Config::Output::ColorInIts is true
     */
void printGuard(const BoolExpr guard, std::ostream &s, bool colors = true);

}
