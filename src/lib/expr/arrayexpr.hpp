#pragma once

#include "exprfwd.hpp"
#include "arith.hpp"
#include "itheory.hpp"
#include "arrayconst.hpp"

template <ITheory T>
class Array;

template <ITheory T>
class ArrayWrite;

template <ITheory T>
class ArrayRead;

template <ITheory T>
using ArrayReadPtr = ptr<ArrayRead<T>>;

template <ITheory T>
using ArrayPtr = ptr<Array<T>>;

template <ITheory T>
class Array {

    public:

    virtual std::optional<ArrayVarPtr<T>> isVar() const {
        return std::nullopt;
    }

    sexpresso::Sexp to_smtlib() const;

    virtual ArrayPtr<T> renameVars(const array_var_map<T>&, const typename T::Renaming&) const = 0;
    virtual void collectVars(const linked_hash_set<ArrayVarPtr<T>>&, const linked_hash_set<typename T::Var>&) const = 0;
    virtual ArrayConst<T> eval(const linked_hash_map<ArrayVarPtr<T>, ArrayConst<T>>&, const T::Model&) const = 0;

};

template <ITheory T>
class ArrayVar: public Array<T>, std::enable_shared_from_this<ArrayVar<T>> {

    using Self = ArrayVarPtr<T>;

    int idx;
    unsigned dim;

public:

    static Self next();
    static Self nextProgVar();
    static Self postVar(const Self);
    std::string getName() const;
    bool isTempVar() const;
    bool isProgVar() const;
    bool isPostVar() const;
    static ArrayVarPtr<T> progVar(const ArrayVarPtr<T>);

    std::optional<ArrayVarPtr<T>> isVar() const override {
        return cpp::assume_not_null(this->shared_from_this());
    }

};

template <ITheory T>
std::ostream& operator<<(std::ostream &s, const ArrayVarPtr<T> a) {
    return s << a->getName();
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