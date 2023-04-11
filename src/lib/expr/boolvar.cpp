#include "boolvar.hpp"

#include <string>
#include <functional>

BoolVar::BoolVar(const std::string &name): name(name) {}

std::string BoolVar::getName() const {
    return name;
}

size_t BoolVar::hash() const {
    return std::hash<std::string>{}(name);
}

std::ostream& operator<<(std::ostream &s, const BoolVar &e) {
    return s << e.getName();
}
