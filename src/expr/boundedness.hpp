#pragma once

#include <ostream>

namespace Boundedness {

enum Kind {
    Lower, Upper, Both, None, Unknown
};

Kind unite(Kind x, Kind y);
Kind intersect(Kind x, Kind y);
std::ostream& operator<<(std::ostream &s, const Kind e);

}
