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

std::ostream& operator<<(std::ostream &s, const BoolVarPtr e) {
    return s << e->getName();
}

BoolVarPtr BoolVar::next() {
    --last_tmp_idx;
    return cpp::assume_not_null(std::make_shared<BoolVar>(last_tmp_idx));
}

BoolVarPtr BoolVar::nextProgVar() {
    last_prog_idx += 2;
    return cpp::assume_not_null(std::make_shared<BoolVar>(last_prog_idx));
}

BoolVarPtr BoolVar::postVar(const BoolVarPtr &var) {
    return cpp::assume_not_null(std::make_shared<BoolVar>(var->getIdx() + 1));
}

BoolVarPtr BoolVar::progVar(const BoolVarPtr &var) {
    return cpp::assume_not_null(std::make_shared<BoolVar>(var->getIdx() - 1));
}

bool BoolVar::isTempVar() const {
    return idx < 0;
}

bool BoolVar::isProgVar() const {
    return idx > 0 && idx % 2 == 1;
}

bool BoolVar::isPostVar() const {
    return idx > 0 && idx % 2 == 0;
}

std::size_t BoolVar::hash() const {
    return std::hash<int>{}(idx);
}

size_t hash_value(const BoolVar &x) {
    return x.hash();
}
