#pragma once

#include "smt.hpp"
#include "config.hpp"

namespace SmtFactory {

    SmtPtr solver(Logic logic);

    SmtPtr solver();

    SmtPtr solver(const Logic logic, const Config::Analysis::SmtSolver which);

    SmtPtr modelBuildingSolver(Logic logic);

    SmtResult check(const Bools::Expr e);

}
