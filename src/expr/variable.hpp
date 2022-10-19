#pragma once

#include "theory.hpp"

namespace variable {

std::string getName(const Var &var);

}

std::ostream& operator<<(std::ostream &s, const Var &e);
