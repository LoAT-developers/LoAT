#include "boolvar.hpp"

#include <functional>

BoolVar::BoolVar(const std::string &name): name(name) {}

std::string BoolVar::toString() const {
    return name;
}

size_t BoolVar::hash() const {
    return std::hash<std::string>{}(name);
}
