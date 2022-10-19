#include "literal.hpp"
#include "literaltemplates.hpp"

namespace literal {

void collectVariables(VarSet &res, const Lit &e) {
    literal::collectVars<IntTheory, BoolTheory>(e, res);
}

VarSet variables(const Lit &e) {
    return literal::vars<IntTheory, BoolTheory>(e);
}

}

std::ostream& operator<<(std::ostream &s, const Lit &e) {
    std::visit([&s](const auto &e){s << e;}, e);
    return s;
}
