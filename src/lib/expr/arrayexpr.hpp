#pragma once

#include "exprfwd.hpp"
#include "arith.hpp"
#include "itheory.hpp"

template <ITheory T>
class Array;

template <ITheory T>
class ArrayWrite;

template <ITheory T>
class ArrayRead;

template <ITheory T>
using ArrayPtr = ptr<Array<T>>;

template <ITheory T>
using ArrayVarPtr = ptr<Array<T>>;

template <ITheory T>
class Array {};

template <ITheory T>
class ArrayVar: public Array<T> {

    int idx;
    unsigned dim;

};

template <ITheory T>
class ArrayWrite: public Array<T> {

    ArrayPtr<T> arr;
    std::vector<Arith::Expr> indices;
    ArrayPtr<T> value;

};

template <ITheory T>
class ArrayRead {

    ArrayPtr<T> arr;
    std::vector<Arith::Expr> indices;

};
