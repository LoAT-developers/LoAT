#pragma once

#include "theory.hpp"

namespace variable {

std::string getName(const Var &var);

bool isTempVar(const Var &var);

bool isProgVar(const Var &var);

Var next(const Var &var);

}

std::ostream& operator<<(std::ostream &s, const Var &e);
