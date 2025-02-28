#pragma once

#include <string>

namespace theory {

enum class Type {
    Int,
    Bool
};

std::string abbreviate(const Type type);

} // namespace theory
