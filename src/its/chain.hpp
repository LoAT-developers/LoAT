#pragma once

#include "variablemanager.hpp"
#include "rule.hpp"

namespace Chaining {

    Rule chain(const Rule &fst, const Rule &snd, VariableManager &its);

}
