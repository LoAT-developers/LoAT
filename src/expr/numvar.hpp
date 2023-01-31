#pragma once

#include <ginac/ginac.h>

class NumVar {

    std::string name;

    static std::map<std::string, GiNaC::symbol> symbols;

public:

    explicit NumVar(const std::string &name);

    std::string getName() const;

    unsigned hash() const;

    signed compare(const NumVar &that) const;

    const GiNaC::symbol& operator*() const;

};

bool operator==(const NumVar &x, const NumVar &y);

bool operator<(const NumVar &x, const NumVar &y);

std::ostream& operator<<(std::ostream &s, const NumVar &x);
