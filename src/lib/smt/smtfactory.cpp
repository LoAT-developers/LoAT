#include "smtfactory.hpp"

namespace SmtFactory {

SmtPtr solver(Logic logic) {
    return _solver<Arith, BoolTheory>(logic);
}

SmtPtr solver() {
    return _solver<Arith, BoolTheory>();
}

SmtPtr modelBuildingSolver(Logic logic) {
    return _modelBuildingSolver<Arith, BoolTheory>(logic);
}

SmtResult check(const BoolExpr e) {
    return _check<Arith, BoolTheory>(e);
}

}
