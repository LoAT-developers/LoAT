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
class ArrayLit {

public:

    virtual bool isTriviallyTrue() const = 0;
    virtual bool isPoly() const = 0;
    virtual bool isLinear() const = 0;
    virtual sexpresso::Sexp to_smtlib() const = 0;
    virtual std::size_t hash() const = 0;

};

template <ITheory T>
class ArrayEq: public ArrayLit<T> {

    ArrayPtr<T> lhs;
    ArrayPtr<T> rhs;

};

template <ITheory T>
class ArrayNeq: public ArrayLit<T> {

    ArrayPtr<T> lhs;
    ArrayPtr<T> rhs;

};

template <ITheory T>
class ArrayElemEq: public ArrayLit<T> {

    ArrayReadPtr<T> lhs;
    T::Expr rhs;

};

template <ITheory T>
class ArrayElemNeq: public ArrayLit<T> {

    ArrayReadPtr<T> lhs;
    T::Expr rhs;

};

namespace arrays {

    template <ITheory T>
    ArrayLitPtr<T> mkElemEq(const ArrayReadPtr<T>, const typename T::Expr);

}
