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
using ArrayReadPtr = ptr<ArrayRead<T>>;

template <ITheory T>
using ArrayWritePtr = ptr<ArrayWrite<T>>;

template <ITheory T>
using ArrayPtr = ptr<Array<T>>;

template <ITheory T>
class Array {

    public:

    virtual ~Array() = default;

    virtual ArrayVarPtr<T> var() const = 0;
    virtual std::optional<ArrayVarPtr<T>> isVar() const = 0;
    virtual std::optional<ArrayWritePtr<T>> isArrayWrite() const = 0;

    sexpresso::Sexp to_smtlib() const;

    virtual ArrayPtr<T> renameVars(const array_var_map<T>&, const T::Renaming&) const = 0;
    virtual void collectVars(const linked_hash_set<ArrayVarPtr<T>>&, const linked_hash_set<typename T::Var>&) const = 0;

};

template <ITheory T>
class ArrayVar: public Array<T>, std::enable_shared_from_this<ArrayVar<T>> {

    using Self = ArrayVarPtr<T>;

    int idx;
    unsigned m_dim;

public:

    static Self next();
    static Self nextProgVar();
    static ArrayVarPtr<T> postVar(const ArrayVarPtr<T>&);
    std::string getName() const;
    bool isTempVar() const;
    bool isProgVar() const;
    bool isPostVar() const;
    static ArrayVarPtr<T> progVar(const ArrayVarPtr<T>&);

    unsigned dim() const {
        return m_dim;
    }

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

    ArrayVarPtr<T> m_arr;
    std::vector<Arith::Expr> m_indices;
    T::Expr m_val;

public:

    ArrayVarPtr<T> arr() const {
        return m_arr;
    }

    std::vector<Arith::Expr> indices() const {
        return m_indices;
    }

    T::Expr val() const {
        return m_val;
    }

};

template <ITheory T>
class ArrayRead {

    ArrayPtr<T> m_arr;
    std::vector<Arith::Expr> m_indices;

public:

    ArrayPtr<T> arr() const {
        return m_arr;
    }

    std::vector<Arith::Expr> indices() const {
        return m_indices;
    }

    bool isTempVar() const {
        return m_arr->var()->isTempVar();
    }

    bool isProgVar() const {
        return m_arr->var()->isProgVar();
    }

    bool isPostVar() const {
        return m_arr->var()->isPostVar();
    }

    static ArrayReadPtr<T> postVar(const ArrayReadPtr<T>&);
    static ArrayReadPtr<T> progVar(const ArrayReadPtr<T>&);

};

template <ITheory T>
std::ostream& operator<<(std::ostream& s, const ArrayReadPtr<T>& read) {
    s << read->arr();
    for (const auto &i: read->indices()) {
        s << "[" << i << "]";
    }
    return s;
}

namespace arrays {

    template <ITheory T>
    ArrayReadPtr<T> mkArrayRead(const ArrayPtr<T>&, const std::vector<Arith::Expr>&);
    template <ITheory T>
    ArrayPtr<T> mkArrayWrite(const ArrayPtr<T>&, const std::vector<Arith::Expr>&, const typename T::Expr&);

}
