#pragma once

#include "arrayexpr.hpp"

template <ITheory T>
class ArrayLit;

template <ITheory T>
class ArrayEq;

template <ITheory T>
class ArrayNeq;

template <ITheory T>
class ArrayElemEq;

template <ITheory T>
class ArrayElemNeq;

template <ITheory T>
using ArrayLitPtr = ptr<ArrayLit<T>>;

template <ITheory T>
class ArrayLit {};

template <ITheory T>
class ArrayEq: public ArrayLit<T> {

    ArrayPtr<T> lhs;
    ArrayPtr<T> rhs;

};

template <ITheory T>
class ArrayNeq: public ArrayLit<T> {};

template <ITheory T>
class ArrayElemEq: public ArrayLit<T> {

    ArrayPtr<T> lhs;
    T::Expr rhs;

};

template <ITheory T>
class ArrayNeq: public ArrayLit<T> {

    ArrayPtr<T> lhs;
    T::Expr rhs;

};
