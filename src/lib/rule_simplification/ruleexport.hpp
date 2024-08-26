#pragma once

#include <ostream>
#include <string>

#include "theory.hpp"
#include "rule.hpp"


namespace RuleExport {

void printRule(const Rule &rule, std::ostream &s);

}
