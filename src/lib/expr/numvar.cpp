#include "numvar.hpp"

#include <assert.h>

std::map<std::string, GiNaC::symbol> NumVar::symbols;

NumVar::NumVar(const std::string &name): name(name) {}

NumVar::NumVar(const GiNaC::symbol &sym): name(sym.get_name()) {
    assert(symbols.find(name) == symbols.end());
    symbols.emplace(name, sym);
}

std::string NumVar::getName() const {
    return name;
}

unsigned NumVar::hash() const {
    return std::hash<std::string>()(name);
}

signed NumVar::compare(const NumVar &that) const {
    return name.compare(that.name);
}

const GiNaC::symbol& NumVar::operator*() const {
    const auto it = symbols.find(name);
    if (it == symbols.end()) {
        symbols.emplace(name, GiNaC::symbol(name));
        return symbols.at(name);
    } else {
        return it->second;
    }
}

bool operator==(const NumVar &x, const NumVar &y) {
    return x.getName() == y.getName();
}

bool operator<(const NumVar &x, const NumVar &y) {
    return x.getName() < y.getName();
}

std::ostream& operator<<(std::ostream &s, const NumVar &x) {
    return s << x.getName();
}
