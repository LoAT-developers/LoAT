#include "boolvar.hpp"

#include <string>
#include <functional>

int BoolVar::last_tmp_idx {0};
int BoolVar::last_prog_idx {1};

ConsHash<BoolVar, BoolVar, BoolVar::CacheHash, BoolVar::CacheEqual, int> BoolVar::cache {};

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
    return bools::mkVar(last_tmp_idx);
}

BoolVarPtr BoolVar::nextProgVar() {
    last_prog_idx += 2;
    return bools::mkVar(last_prog_idx);
}

BoolVarPtr BoolVar::postVar(const BoolVarPtr &var) {
    return bools::mkVar(var->getIdx() + 1);
}

BoolVarPtr BoolVar::progVar(const BoolVarPtr &var) {
    return bools::mkVar(var->getIdx() - 1);
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

BoolVarPtr bools::mkVar(const int idx) {
    return BoolVar::cache.from_cache(idx);
}

bool BoolVar::CacheEqual::operator()(const std::tuple<int> &args1, const std::tuple<int> &args2) const noexcept {
    return args1 == args2;
}

size_t BoolVar::CacheHash::operator()(const std::tuple<int> &args) const noexcept {
    return std::hash<int>{}(std::get<0>(args));
}
