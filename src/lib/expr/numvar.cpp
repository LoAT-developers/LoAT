#include "numvar.hpp"
#include "purrs.hh"

#include <assert.h>

namespace Purrs = Parma_Recurrence_Relation_Solver;

std::map<std::string, GiNaC::symbol> NumVar::symbols;

NumVar NumVar::ginacN() {
    static const NumVar res {GiNaC::ex_to<GiNaC::symbol>(Purrs::Expr(Purrs::Recurrence::n).toGiNaC())};
    return res;
}

NumVar::NumVar(const std::string &name): name(name) {}

NumVar::NumVar(const GiNaC::symbol &sym): name(sym.get_name()) {
    assert(symbols.find(name) == symbols.end());
    symbols.emplace(name, sym);
}

std::string NumVar::getName() const {
    return name;
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

std::ostream& operator<<(std::ostream &s, const NumVar &x) {
    return s << x.getName();
}
