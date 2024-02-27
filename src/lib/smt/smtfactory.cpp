#include "smtfactory.hpp"

namespace SmtFactory {

SmtPtr solver(Logic logic) {
    return _solver<Arith, Bools>(logic);
}

SmtPtr solver() {
    return _solver<Arith, Bools>();
}

SmtPtr modelBuildingSolver(Logic logic) {
    return _modelBuildingSolver<Arith, Bools>(logic);
}

SmtResult check(const BoolExpr e) {
    return _check<Arith, Bools>(e);
}

}
