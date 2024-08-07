#include "chctosafetyproblem.hpp"
#include "chctoitsproblem.hpp"
#include "itstosafetyproblem.hpp"

SafetyProblem chc_to_safetyproblem(const CHCProblem &chcs) {
    const auto its {chcs_to_its(chcs)};
    return its_to_safetyproblem(its);
}