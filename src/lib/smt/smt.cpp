#include "smt.hpp"

std::ostream& operator<<(std::ostream &s, const SmtResult &res) {
    switch (res) {
        case SmtResult::Sat: s << "sat";
        break;
        case SmtResult::Unsat: s << "unsat";
        break;
        case SmtResult::Unknown: s << "unknown";
        break;
    }
    return s;
}

std::optional<Bools::Expr> Smt::interpolate(const BoolExprSet&) {
    throw std::invalid_argument("interpolation is not supported by this solver");
}
