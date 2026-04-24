#include "arrays.hpp"
#include "theory.hpp"
#include "arraylit.hpp"

ArithVarPtr arrays::array_idx(size_t i) {
    static std::vector<ArithVarPtr> indices;
    if (indices.size() <= i) {
        indices.emplace_back(arrays::nextConst<Arith>());
    }
    return indices.at(i);
}

template <ITheory T>
Bools::Expr Arrays<T>::mkEq(const Expr& lhs, const Expr& rhs) {
    return bools::mkLit(arrays::mkEq(lhs, rhs));
}

template Bools::Expr Arrays<Arith>::mkEq(const Expr& lhs, const Expr& rhs);
