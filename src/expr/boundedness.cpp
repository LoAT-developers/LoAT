#include "boundedness.hpp"

namespace Boundedness {

Kind unite(Kind x, Kind y) {
    if (x == y) return x;
    if (x == Unknown || y == Unknown) return Unknown;
    if (x == None) return y;
    if (y == None) return x;
    return Both;
}

Kind intersect(Kind x, Kind y) {
    if (x == y) return x;
    if (x == Unknown || y == Unknown) return Unknown;
    if (x == None || y == None) return None;
    if (x == Both) return y;
    return x;
}

std::ostream& operator<<(std::ostream &s, const Kind e) {
    switch (e) {
    case Lower: s << "lower";
        break;
    case Upper: s << "upper";
        break;
    case Unknown: s << "unknown";
        break;
    case Both: s << "both";
        break;
    case None: s << "none";
        break;
    }
    return s;
}

}
