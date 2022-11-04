#include "literal.hpp"
#include "literaltemplates.hpp"

namespace literal {

void collectVariables(VarSet &res, const Lit &e) {
    literal_t::collectVars<IntTheory, BoolTheory>(e, res);
}

VarSet variables(const Lit &e) {
    return literal_t::vars<IntTheory, BoolTheory>(e);
}

bool isTriviallyTrue(const Lit &lit) {
    return literal_t::isTriviallyTrue<IntTheory, BoolTheory>(lit);
}

Lit negate(const Lit &lit) {
    return literal_t::negate<IntTheory, BoolTheory>(lit);
}

}

std::ostream& operator<<(std::ostream &s, const Lit &e) {
    std::visit([&s](const auto &e){s << e;}, e);
    return s;
}
