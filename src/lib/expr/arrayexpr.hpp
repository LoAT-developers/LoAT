#pragma once

#include "exprfwd.hpp"
#include "arith.hpp"
#include "itheory.hpp"

template <ITheory T>
class Array;

template <ITheory T>
class ArrayVar;

template <ITheory T>
class ArrayWrite;

template <ITheory T>
class ArrayRead;

template <ITheory T>
using ArrayReadPtr = ptr<ArrayRead<T>>;

template <ITheory T>
using ArrayPtr = ptr<Array<T>>;

template <ITheory T>
using ArrayVarPtr = ptr<ArrayVar<T>>;

template <ITheory T>
class Array {};

template <ITheory T>
class ArrayVar: public Array<T> {

    using Self = ArrayVarPtr<T>;

    int idx;
    unsigned dim;

public:

    static Self next();
    static Self nextProgVar();
    static Self postVar(const Self);
    std::string get_name() const;

};

template <ITheory T>
std::ostream& operator<<(std::ostream &s, const ArrayVarPtr<T> a) {
    return s << a->get_name();
}

template <ITheory T>
class ArrayWrite: public Array<T> {

    ArrayPtr<T> arr;
    std::vector<Arith::Expr> indices;
    ArrayPtr<T> value;

};

template <ITheory T>
class ArrayRead: public Array<T> {

    ArrayPtr<T> arr;
    std::vector<Arith::Expr> indices;

};

namespace arrays {

    template <ITheory T>
    ArrayReadPtr<T> mkArrayRead(const ArrayPtr<T>, const std::vector<Arith::Expr> &indices);

}