#pragma once

#include "smt.hpp"

namespace SmtFactory {

    SmtPtr solver(Logic logic, const bool model = false);

    SmtPtr solver(const bool model = false);

    SmtPtr modelBuildingSolver(Logic logic);

    SmtPtr modelBuildingSolver();

    SmtResult check(const Bools::Expr e);

}
