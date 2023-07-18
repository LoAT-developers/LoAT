#include "types.hpp"

std::ostream& operator<<(std::ostream &s, const TransIdx &idx) {
    return s << idx->getId();
}
