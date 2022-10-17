#include "numvar.hpp"

NumVar::NumVar(const GiNaC::symbol &symbol): symbol(symbol) {}

NumVar::NumVar(const std::string &name): symbol(name) {}

std::string NumVar::getName() const {
    return symbol.get_name();
}

unsigned NumVar::hash() const {
    return symbol.gethash();
}

signed NumVar::compare(const NumVar &that) const {
    return symbol.compare(*that);
}

const GiNaC::symbol& NumVar::operator*() const {
    return symbol;
}

bool operator==(const NumVar &x, const NumVar &y) {
    return GiNaC::ex_is_equal()(*x, *y);
}

bool operator<(const NumVar &x, const NumVar &y) {
    return GiNaC::ex_is_less()(*x, *y);
}

std::ostream& operator<<(std::ostream &s, const NumVar &x) {
    return s << GiNaC::ex(*x);
}
