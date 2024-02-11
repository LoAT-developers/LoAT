#include "numvar.hpp"

#include <assert.h>

int NumVar::last_tmp_idx {0};
int NumVar::last_prog_idx {1};

std::unordered_map<int, GiNaC::symbol> NumVar::symbols;
const NumVar NumVar::loc_var {1};

NumVar::NumVar(const int idx): idx(idx) {
    const auto it {symbols.find(idx)};
    if (it == symbols.end()) {
        if (idx > 0) {
            last_prog_idx = std::max(last_prog_idx, idx);
        } else {
            last_tmp_idx = std::min(last_tmp_idx, idx);
        }
        symbols.emplace(idx, getName());
    }
}

int NumVar::getIdx() const {
    return idx;
}

std::string NumVar::getName() const {
    if (idx > 0) {
        return "i" + std::to_string(idx);
    } else {
        return "it" + std::to_string(-idx);
    }
}

const GiNaC::symbol& NumVar::operator*() const {
    return symbols[idx];
}

std::ostream& operator<<(std::ostream &s, const NumVar &x) {
    return s << x.getName();
}

NumVar NumVar::next() {
    --last_tmp_idx;
    return NumVar(last_tmp_idx);
}

NumVar NumVar::nextProgVar() {
    ++last_prog_idx;
    return NumVar(last_prog_idx);
}

bool NumVar::isTempVar() const {
    return idx < 0;
}

size_t NumVar::hash() const {
    return std::hash<int>{}(idx);
}

std::size_t hash_value(const NumVar &x) {
    return x.hash();
}
