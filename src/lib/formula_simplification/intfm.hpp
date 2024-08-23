#pragma once

#include "theory.hpp"
#include "proof.hpp"
#include "result.hpp"

Result<Bools::Expr, Proof> integerFourierMotzkin(const Bools::Expr e, const std::function<bool(const Var &)> &allow);