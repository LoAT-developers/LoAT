#pragma once

#include <ginac/ginac.h>

class NumVar {

    std::string name;

    static std::map<std::string, GiNaC::symbol> symbols;

    explicit NumVar(const GiNaC::symbol &sym);

    friend std::strong_ordering operator<=>(const NumVar&, const NumVar&) = default;

public:

    static NumVar ginacN();

    explicit NumVar(const std::string &name);

    std::string getName() const;

    const GiNaC::symbol& operator*() const;

};

std::ostream& operator<<(std::ostream &s, const NumVar &x);
