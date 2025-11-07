#pragma once

#include "arrayexpr.hpp"
#include "exprfwd.hpp"

template <class T>
class ArrayEq;

template <class T>
class ArrayNeq;

template <class T>
using ArrayEqPtr = ptr<ArrayEq<T>>;

template <class T>
using ArrayNeqPtr = ptr<ArrayNeq<T>>;

namespace arrays {

    Lit mkEq(const ArrayPtr<Arith>& lhs, const ArrayPtr<Arith>& rhs);
    Lit mkNeq(const ArrayPtr<Arith>& lhs, const ArrayPtr<Arith>& rhs);

}

template <class T>
class ArrayLit {

public:

    virtual ~ArrayLit() = default;

    virtual bool isTriviallyTrue() const = 0;

    static bool isPoly();

    static bool isLinear();

    virtual sexpresso::Sexp to_smtlib() const = 0;
    virtual std::size_t hash() const = 0;
    virtual ArrayLitPtr<T> subs(const ArraySubs<T>&) const = 0;
    virtual ArrayLitPtr<T> subs(const linked_hash_map<ArithVarPtr, ArithExprPtr>&) const;
    virtual ArrayLitPtr<T> renameVars(const array_var_map<T>&) const = 0;
    virtual ArrayLitPtr<T> renameVars(const Renaming&) const = 0;
    virtual void collectVars(linked_hash_set<ArrayVarPtr<T>>& arr) const = 0;
    virtual void collectCells(linked_hash_set<ArrayReadPtr<T>>&) const = 0;
    virtual bool isTriviallyFalse() const = 0;
    virtual std::optional<ArrayEqPtr<T>> isArrayEq() const = 0;
    virtual std::optional<ArrayNeqPtr<T>> isArrayNeq() const = 0;

    static bool simplifyAnd(linked_hash_set<ArrayLitPtr<T>>&);

};

template <class T>
class ArrayEq final: public ArrayLit<T>, std::enable_shared_from_this<ArrayEq<T>> {

    friend Lit arrays::mkEq(const ArrayPtr<Arith>& lhs, const ArrayPtr<Arith>& rhs);
    friend class ConsHash<ArrayEq, ArrayPtr<T>, ArrayPtr<T>>;
    template <class S> friend ArrayLitPtr<S> operator!(const ArrayLitPtr<S>& lit);

    ArrayPtr<T> m_lhs;
    ArrayPtr<T> m_rhs;

    struct CacheEqual {
        bool operator()(const std::tuple<ArrayPtr<T>, ArrayPtr<T>> &args1, const std::tuple<ArrayPtr<T>, ArrayPtr<T>> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<ArrayPtr<T>, ArrayPtr<T>> &args) const noexcept;
    };

    static ConsHash<ArrayEq, ArrayPtr<T>, ArrayPtr<T>> cache;

public:

    ArrayEq(const ArrayPtr<T>& p_lhs, const ArrayPtr<T>& p_rhs);

    ArrayPtr<T> lhs() const;

    ArrayPtr<T> rhs() const;

    bool isTriviallyTrue() const override;

    sexpresso::Sexp to_smtlib() const override;

    std::size_t hash() const override;

    ArrayLitPtr<T> subs(const ArraySubs<T>& subs) const override;

    ArrayLitPtr<T> renameVars(const array_var_map<T>&) const override;
    ArrayLitPtr<T> renameVars(const Renaming&) const override;

    void collectVars(linked_hash_set<ArrayVarPtr<T>>& arr) const override;

    bool isTriviallyFalse() const override;

    std::optional<ArrayEqPtr<T>> isArrayEq() const override;

    std::optional<ArrayNeqPtr<T>> isArrayNeq() const override;
    void collectCells(linked_hash_set<cpp::not_null<std::shared_ptr<const ArrayRead<T>>>>&) const override;
};

template <class T>
ConsHash<ArrayEq<T>, ArrayPtr<T>, ArrayPtr<T>> ArrayEq<T>::cache {};

template <class T>
class ArrayNeq final: public ArrayLit<T>, std::enable_shared_from_this<ArrayNeq<T>> {

    friend Lit arrays::mkNeq(const ArrayPtr<Arith>& lhs, const ArrayPtr<Arith>& rhs);
    friend class ConsHash<ArrayNeq, ArrayPtr<T>, ArrayPtr<T>>;
    template <class S> friend ArrayLitPtr<S> operator!(const ArrayLitPtr<S>& lit);

    ArrayPtr<T> m_lhs;
    ArrayPtr<T> m_rhs;

    struct CacheEqual {
        bool operator()(const std::tuple<ArrayPtr<T>, ArrayPtr<T>> &args1, const std::tuple<ArrayPtr<T>, ArrayPtr<T>> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<ArrayPtr<T>, ArrayPtr<T>> &args) const noexcept;
    };

    static ConsHash<ArrayNeq, ArrayPtr<T>, ArrayPtr<T>> cache;

public:

    ArrayNeq(const ArrayPtr<T>& p_lhs, const ArrayPtr<T>& p_rhs);

    ArrayPtr<T> lhs() const;

    ArrayPtr<T> rhs() const;

    bool isTriviallyTrue() const override;

    sexpresso::Sexp to_smtlib() const override;

    std::size_t hash() const override;

    ArrayLitPtr<T> subs(const ArraySubs<T>& subs) const override;

    ArrayLitPtr<T> renameVars(const array_var_map<T>&) const override;
    ArrayLitPtr<T> renameVars(const Renaming&) const override;

    void collectVars(linked_hash_set<ArrayVarPtr<T>>& arr) const override;

    bool isTriviallyFalse() const override;

    std::optional<ArrayEqPtr<T>> isArrayEq() const override;

    std::optional<ArrayNeqPtr<T>> isArrayNeq() const override;
    void collectCells(linked_hash_set<cpp::not_null<std::shared_ptr<const ArrayRead<T>>>>&) const override;
};

template <class T>
ConsHash<ArrayNeq<T>, ArrayPtr<T>, ArrayPtr<T>> ArrayNeq<T>::cache {};

template<class T>
ArrayLitPtr<T> operator!(const ArrayLitPtr<T>& lit) {
    if (const auto eq {lit->isArrayEq()}) {
        return ArrayNeq<T>::cache.from_cache((*eq)->lhs(), (*eq)->rhs());
    }
    if (const auto neq {lit->isArrayNeq()}) {
        return ArrayEq<T>::cache.from_cache((*neq)->lhs(), (*neq)->rhs());
    }
    throw std::logic_error("unknown array literal");
}
