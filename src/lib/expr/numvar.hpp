#pragma once

#include <ginac/ginac.h>

class NumVar {

    static int last_tmp_idx;
    static int last_prog_idx;

    int idx;

    static std::map<int, GiNaC::symbol> symbols;

    friend auto operator<=>(const NumVar&, const NumVar&) = default;
    friend bool operator==(const NumVar&, const NumVar&) = default;

public:

    explicit NumVar(const int idx);

    int getIdx() const;

    std::string getName() const;

    const GiNaC::symbol& operator*() const;

    static NumVar next();

    static NumVar nextProgVar();

    bool isTempVar() const;

};

std::ostream& operator<<(std::ostream &s, const NumVar &x);
