#pragma once

#include "arrayexpr.hpp"
#include "arraysubs.hpp"
#include "arrayconst.hpp"

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
using ArrayEqPtr = ptr<ArrayEq<T>>;

template <ITheory T>
using ArrayNeqPtr = ptr<ArrayNeq<T>>;

template <ITheory T>
using ArrayElemEqPtr = ptr<ArrayElemEq<T>>;

template <ITheory T>
using ArrayElemNeqPtr = ptr<ArrayElemNeq<T>>;

template <ITheory T>
class ArrayLit {

public:
    virtual ~ArrayLit() = default;

    virtual bool isTriviallyTrue() const = 0;
    virtual bool isPoly() const = 0;
    virtual bool isLinear() const = 0;
    virtual sexpresso::Sexp to_smtlib() const = 0;
    virtual std::size_t hash() const = 0;
    virtual ArrayLitPtr<T> subs(const typename T::Subs&) const = 0;
    virtual ArrayLitPtr<T> subs(const ArraySubs<T>&) const = 0;
    virtual ArrayLitPtr<T> renameVars(const array_var_map<T> &map) const = 0;
    virtual ArrayLitPtr<T> renameVars(const typename T::Renaming &map) const = 0;
    virtual bool eval(const linked_hash_map<ArrayVarPtr<T>, ArrayConst<T>>&, const T::Model&) const = 0;
    virtual void collectVars(const linked_hash_set<ArrayVarPtr<T>>&, const linked_hash_set<typename T::Var>&) const = 0;
    virtual bool isTriviallyFalse() const = 0;
    virtual std::optional<ArrayEqPtr<T>> isArrayEq() const = 0;
    virtual std::optional<ArrayNeqPtr<T>> isArrayNeq() const = 0;
    virtual std::optional<ArrayElemEqPtr<T>> isArrayElemEq() const = 0;
    virtual std::optional<ArrayElemNeqPtr<T>> isArrayElemNeq() const = 0;

    static bool simplifyAnd(linked_hash_set<ArrayLitPtr<T>> &lits);

};

template <ITheory T>
class ArrayEq: public ArrayLit<T> {

    ArrayPtr<T> m_lhs;
    ArrayPtr<T> m_rhs;

public:

    ArrayPtr<T> lhs() const {
        return m_lhs;
    }

    ArrayPtr<T> rhs() const {
        return m_rhs;
    }

};

template <ITheory T>
class ArrayNeq: public ArrayLit<T> {

    ArrayPtr<T> m_lhs;
    ArrayPtr<T> m_rhs;

public:

    ArrayPtr<T> lhs() const {
        return m_lhs;
    }

    ArrayPtr<T> rhs() const {
        return m_rhs;
    }

};

template <ITheory T>
class ArrayElemEq: public ArrayLit<T> {

    ArrayReadPtr<T> m_lhs;
    T::Expr m_rhs;

public:

    ArrayReadPtr<T> lhs() const {
        return m_lhs;
    }

    T::Expr rhs() const {
        return m_rhs;
    }

};

template <ITheory T>
class ArrayElemNeq: public ArrayLit<T> {

    ArrayReadPtr<T> m_lhs;
    T::Expr m_rhs;

public:

    ArrayReadPtr<T> lhs() const {
        return m_lhs;
    }

    T::Expr rhs() const {
        return m_rhs;
    }

};

namespace arrays {

    template <ITheory T>
    ArrayLitPtr<T> mkElemEq(ArrayReadPtr<T>, typename T::Expr);
    template <ITheory T>
    ArrayLitPtr<T> mkEq(ArrayPtr<T>, ArrayPtr<T>);
    template <ITheory T>
    ArrayLitPtr<T> mkNeq(ArrayPtr<T>, ArrayPtr<T>);
}

template<ITheory T>
ArrayLitPtr<T> operator!(ArrayLitPtr<T>);
