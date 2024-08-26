#pragma once

#include "theory.hpp"

Bools::Expr integerFourierMotzkin(Bools::Expr e, const std::function<bool(const Var &)> &allow);