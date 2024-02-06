#pragma once

#include <ginac/ginac.h>
#include <functional>

class NumVar {

private:

    static int last_tmp_idx;
    static int last_prog_idx;

    int idx;

    static std::map<int, GiNaC::symbol> symbols;

public:

    friend auto operator<=>(const NumVar&, const NumVar&) = default;
    friend bool operator==(const NumVar&, const NumVar&) = default;

    static const NumVar loc_var;

    explicit NumVar(const int idx);

    int getIdx() const;

    std::string getName() const;

    const GiNaC::symbol& operator*() const;

    static NumVar next();

    static NumVar nextProgVar();

    bool isTempVar() const;

    size_t hash() const;

};

std::ostream& operator<<(std::ostream &s, const NumVar &x);

template<>
struct std::hash<NumVar> {
    std::size_t operator()(const NumVar& x) const noexcept {
        return x.hash();
    }
};

std::size_t hash_value(const NumVar &x);
