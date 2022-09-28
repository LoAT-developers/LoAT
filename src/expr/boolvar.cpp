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

bool BoolVar::equals(const BoolVar &that) const {
    return this->name == that.name;
}

int BoolVar::compare(const BoolVar &that) const {
    return this->name.compare(that.name);
}

bool BoolVar_is_less::operator()(const BoolVar &lh, const BoolVar &rh) const {
     return lh.getName().compare(rh.getName()) < 0;
}

bool operator==(const BoolVar &v1, const BoolVar &v2) {
    return v1.getName() == v2.getName();
}

bool operator <(const BoolVar &v1, const BoolVar &v2) {
    return v1.getName() < v2.getName();
}

std::ostream& operator<<(std::ostream &s, const BoolVar &e) {
    return s << e.getName();
}
