#include "qelim.hpp"
#include "qecalculus.hpp"

std::unique_ptr<Qelim> Qelim::solver(VarMan& varMan) {
    return std::unique_ptr<Qelim>(new QeProblem(varMan));
}
