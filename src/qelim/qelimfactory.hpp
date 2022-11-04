#pragma once

#include "variablemanager.hpp"
#include "qecalculus.hpp"
#include "itheory.hpp"

namespace qelimfactory {

template <ITheory... Th>
static std::unique_ptr<Qelim<Th...>> solver(VarMan& varMan) {
    return std::unique_ptr<Qelim<Th...>>(new QeProblem<Th...>(varMan));
}

}
