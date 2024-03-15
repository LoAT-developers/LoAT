#pragma once

#include <memory>
#include <string>

class BoolVar;

using BoolVarPtr = std::shared_ptr<BoolVar>;

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

    bool isTempVar() const;

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
