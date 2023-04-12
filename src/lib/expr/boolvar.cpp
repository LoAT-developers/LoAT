#include "boolvar.hpp"

#include <string>

BoolVar::BoolVar(const std::string &name): name(name) {}

std::string BoolVar::getName() const {
    return name;
}

std::ostream& operator<<(std::ostream &s, const BoolVar &e) {
    return s << e.getName();
}
