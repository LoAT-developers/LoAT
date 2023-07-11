#include "accelerationresult.hpp"

namespace acceleration {

std::ostream& operator<<(std::ostream &s, const Status x) {
    switch (x) {
    case NotSat: return s << "not sat";
    case Nondet: return s << "nondet";
    case PseudoLoop: return s << "pseudo loop";
    case Disjunctive: return s << "disjunctive";
    case AccelerationFailed: return s << "acceleration failed";
    case ClosedFormFailed: return s << "closed form failed";
    case Success: return s << "success";
    }
    return s;
}

}
