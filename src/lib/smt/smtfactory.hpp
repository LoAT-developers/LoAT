#pragma once

#include "smt.hpp"

namespace SmtFactory {

    SmtPtr solver(Logic logic);

    SmtPtr solver();

    SmtPtr modelBuildingSolver(Logic logic);

    SmtPtr interpolatingSolver();

    SmtResult check(const Bools::Expr e);

}
