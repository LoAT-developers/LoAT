#pragma once

#include "smt.hpp"

namespace SmtFactory {

    SmtPtr solver(Logic logic);

    SmtPtr solver();

    SmtPtr modelBuildingSolver(Logic logic);

    SmtResult check(const Bools::Expr& e);

}
