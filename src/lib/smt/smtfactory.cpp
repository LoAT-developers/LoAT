#include "smtfactory.hpp"

namespace SmtFactory {

SmtPtr solver(Logic logic) {
    return _solver<IntTheory, BoolTheory>(logic);
}

SmtPtr solver() {
    return _solver<IntTheory, BoolTheory>();
}

SmtPtr modelBuildingSolver(Logic logic) {
    return _modelBuildingSolver<IntTheory, BoolTheory>(logic);
}

SmtResult check(const BoolExpr e) {
    return _check<IntTheory, BoolTheory>(e);
}

}
