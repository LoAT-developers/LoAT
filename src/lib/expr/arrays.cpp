#include "arrays.hpp"

ArithVarPtr arrays::array_idx(size_t i) {
    static std::vector<ArithVarPtr> indices;
    if (indices.size() <= i) {
        indices.emplace_back(arrays::nextConst<Arith>());
    }
    return indices.at(i);
}
