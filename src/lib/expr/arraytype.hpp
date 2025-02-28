#pragma once

#include "type.hpp"

#include <cstddef>
#include <functional>
#include <ostream>

class ArrayType {

    theory::Type t;
    unsigned dimension;

public:
    ArrayType(const theory::Type t, const unsigned dimension);
    theory::Type get_type() const;
    unsigned get_dimension() const;
};

template <>
struct std::hash<ArrayType> {
    std::size_t operator()(const ArrayType &x) const noexcept;
};

std::ostream& operator<<(std::ostream&, const ArrayType&);
