#pragma once

#include "smt.hpp"
#include "config.hpp"

namespace SmtFactory {

    std::unique_ptr<Smt> solver(Smt::Logic logic, const VariableManager &varMan, unsigned int timeout = Config::Smt::DefaultTimeout);
    std::unique_ptr<Smt> modelBuildingSolver(Smt::Logic logic, const VariableManager &varMan, unsigned int timeout = Config::Smt::DefaultTimeout);

}
