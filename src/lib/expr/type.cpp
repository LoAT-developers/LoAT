#include "type.hpp"

namespace theory {

std::string abbreviate(const Type type) {
    switch (type) {
        case Type::Int:
            return "i";
        case Type::Bool:
            return "b";
    }
}

} // namespace theory
