#pragma once

#include <string>
#include <set>
#include <map>

class BoolVar {

    static int last_prog_idx;
    static int last_tmp_idx;

    int idx;

    friend auto operator<=>(const BoolVar &x, const BoolVar &y) = default;
    friend bool operator==(const BoolVar &x, const BoolVar &y) = default;

public:

    BoolVar(const int idx);

    std::string getName() const;

    int getIdx() const;

    static BoolVar next();

    static BoolVar nextProgVar();

    bool isTempVar() const;

    std::size_t hash() const;

};

std::ostream& operator<<(std::ostream &s, const BoolVar &e);
