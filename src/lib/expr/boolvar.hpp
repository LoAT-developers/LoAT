#pragma once

#include <memory>
#include <string>

#include "notnull.hpp"

class BoolVar;

using BoolVarPtr = cpp::not_null<std::shared_ptr<BoolVar>>;

class BoolVar {

private:

    static int last_prog_idx;
    static int last_tmp_idx;

    int idx;

public:

    friend auto operator<=>(const BoolVar &x, const BoolVar &y) = default;
    friend bool operator==(const BoolVar &x, const BoolVar &y) = default;

    BoolVar(const int idx);

    std::string getName() const;

    int getIdx() const;

    static BoolVarPtr next();

    static BoolVarPtr nextProgVar();

    static BoolVarPtr postVar(const BoolVarPtr&);

    static BoolVarPtr progVar(const BoolVarPtr&);

    bool isTempVar() const;

    bool isProgVar() const;

    bool isPostVar() const;

    std::size_t hash() const;

};

std::ostream& operator<<(std::ostream &s, const BoolVarPtr e);

template<>
struct std::hash<BoolVar> {
    std::size_t operator()(const BoolVar& x) const noexcept {
        return x.hash();
    }
};

size_t hash_value(const BoolVar &x);
