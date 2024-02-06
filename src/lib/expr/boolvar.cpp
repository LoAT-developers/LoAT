#include "boolvar.hpp"

#include <string>
#include <functional>

int BoolVar::last_tmp_idx {0};
int BoolVar::last_prog_idx {0};


BoolVar::BoolVar(const int idx): idx(idx) {
    if (idx > 0) {
        last_prog_idx = std::max(last_prog_idx, idx);
    } else {
        last_tmp_idx = std::min(last_tmp_idx, idx);
    }
}

std::string BoolVar::getName() const {
    if (idx > 0) {
        return "b" + std::to_string(idx);
    } else {
        return "bt" + std::to_string(-idx);
    }
}

int BoolVar::getIdx() const {
    return idx;
}

std::ostream& operator<<(std::ostream &s, const BoolVar &e) {
    return s << e.getName();
}

BoolVar BoolVar::next() {
    --last_tmp_idx;
    return BoolVar(last_tmp_idx);
}

BoolVar BoolVar::nextProgVar() {
    ++last_prog_idx;
    return BoolVar(last_prog_idx);
}

bool BoolVar::isTempVar() const {
    return idx < 0;
}

std::size_t BoolVar::hash() const {
    return std::hash<int>{}(idx);
}

size_t hash_value(const BoolVar &x) {
    return x.hash();
}
