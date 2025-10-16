#pragma once

#include "arrayexpr.hpp"
#include "exprfwd.hpp"

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

namespace arrays {

    template <ITheory T>
    ArrayLitPtr<T> mkEq(const ArrayPtr<T>& lhs, const ArrayPtr<T>& rhs);

    template <ITheory T>
    ArrayLitPtr<T> mkNeq(const ArrayPtr<T>& lhs, const ArrayPtr<T>& rhs);

    template <ITheory T>
    ArrayLitPtr<T> mkElemEq(const ArrayReadPtr<T>&, const typename T::Expr&);

    template <ITheory T>
    ArrayLitPtr<T> mkElemNeq(const ArrayReadPtr<T>&, const typename T::Expr&);

}

template <ITheory T>
class ArrayLit {

public:

    virtual ~ArrayLit() = default;

    virtual bool isTriviallyTrue() const = 0;

    static bool isPoly();

    static bool isLinear();

    virtual sexpresso::Sexp to_smtlib() const = 0;
    virtual std::size_t hash() const = 0;
    virtual ArrayLitPtr<T> subs(const T::Subs&) const = 0;
    virtual ArrayLitPtr<T> subs(const ArraySubs<T>&) const = 0;
    virtual ArrayLitPtr<T> renameVars(const array_var_map<T>&) const = 0;
    virtual ArrayLitPtr<T> renameVars(const T::Renaming&) const = 0;
    virtual ArrayLitPtr<T> renameVars(const Renaming&) const = 0;
    virtual void collectVars(linked_hash_set<ArrayVarPtr<T>>& arr, linked_hash_set<Arith::Var>& arith, linked_hash_set<typename T::Var>& t) const = 0;
    virtual bool isTriviallyFalse() const = 0;
    virtual std::optional<ArrayEqPtr<T>> isArrayEq() const = 0;
    virtual std::optional<ArrayNeqPtr<T>> isArrayNeq() const = 0;
    virtual std::optional<ArrayElemEqPtr<T>> isArrayElemEq() const = 0;
    virtual std::optional<ArrayElemNeqPtr<T>> isArrayElemNeq() const = 0;

    static bool simplifyAnd(linked_hash_set<ArrayLitPtr<T>>&);

};

template <ITheory T>
class ArrayEq final: public ArrayLit<T>, std::enable_shared_from_this<ArrayEq<T>> {

    friend ArrayLitPtr<T> arrays::mkEq(const ArrayPtr<T>& lhs, const ArrayPtr<T>& rhs);

    ArrayPtr<T> m_lhs;
    ArrayPtr<T> m_rhs;

    struct CacheEqual {
        bool operator()(const std::tuple<ArrayPtr<T>, ArrayPtr<T>> &args1, const std::tuple<ArrayPtr<T>, ArrayPtr<T>> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<ArrayPtr<T>, ArrayPtr<T>> &args) const noexcept;
    };

    static ConsHash<ArrayLit<T>, ArrayEq, CacheHash, CacheEqual, ArrayPtr<T>, ArrayPtr<T>> cache;

public:

    ArrayEq(const ArrayPtr<T>& p_lhs, const ArrayPtr<T>& p_rhs);

    ArrayPtr<T> lhs() const;

    ArrayPtr<T> rhs() const;

    bool isTriviallyTrue() const override;

    sexpresso::Sexp to_smtlib() const override;

    std::size_t hash() const override;

    ArrayLitPtr<T> subs(const T::Subs& subs) const override;

    ArrayLitPtr<T> subs(const ArraySubs<T>& subs) const override;

    ArrayLitPtr<T> renameVars(const array_var_map<T>&) const override;
    ArrayLitPtr<T> renameVars(const T::Renaming&) const override;
    ArrayLitPtr<T> renameVars(const Renaming&) const override;

    void collectVars(linked_hash_set<ArrayVarPtr<T>>& arr, linked_hash_set<Arith::Var>& arith, linked_hash_set<typename T::Var>& t) const override;

    bool isTriviallyFalse() const override;

    std::optional<ArrayEqPtr<T>> isArrayEq() const override;

    std::optional<ArrayNeqPtr<T>> isArrayNeq() const override;

    std::optional<ArrayElemEqPtr<T>> isArrayElemEq() const override;

    std::optional<ArrayElemNeqPtr<T>> isArrayElemNeq() const override;
};

template <ITheory T>
ConsHash<ArrayLit<T>, ArrayEq<T>, typename ArrayEq<T>::CacheHash, typename ArrayEq<T>::CacheEqual, ArrayPtr<T>, ArrayPtr<T>> ArrayEq<T>::cache {};

template <ITheory T>
class ArrayNeq final: public ArrayLit<T>, std::enable_shared_from_this<ArrayNeq<T>> {

    friend ArrayLitPtr<T> arrays::mkNeq(const ArrayPtr<T>& lhs, const ArrayPtr<T>& rhs);

    ArrayPtr<T> m_lhs;
    ArrayPtr<T> m_rhs;

    struct CacheEqual {
        bool operator()(const std::tuple<ArrayPtr<T>, ArrayPtr<T>> &args1, const std::tuple<ArrayPtr<T>, ArrayPtr<T>> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<ArrayPtr<T>, ArrayPtr<T>> &args) const noexcept;
    };

    static ConsHash<ArrayLit<T>, ArrayNeq, CacheHash, CacheEqual, ArrayPtr<T>, ArrayPtr<T>> cache;

public:

    ArrayNeq(const ArrayPtr<T>& p_lhs, const ArrayPtr<T>& p_rhs);

    ArrayPtr<T> lhs() const;

    ArrayPtr<T> rhs() const;

    bool isTriviallyTrue() const override;

    sexpresso::Sexp to_smtlib() const override;

    std::size_t hash() const override;

    ArrayLitPtr<T> subs(const T::Subs& subs) const override;

    ArrayLitPtr<T> subs(const ArraySubs<T>& subs) const override;

    ArrayLitPtr<T> renameVars(const array_var_map<T>&) const override;
    ArrayLitPtr<T> renameVars(const T::Renaming&) const override;
    ArrayLitPtr<T> renameVars(const Renaming&) const override;

    void collectVars(linked_hash_set<ArrayVarPtr<T>>& arr, linked_hash_set<Arith::Var>& arith, linked_hash_set<typename T::Var>& t) const override;

    bool isTriviallyFalse() const override;

    std::optional<ArrayEqPtr<T>> isArrayEq() const override;

    std::optional<ArrayNeqPtr<T>> isArrayNeq() const override;

    std::optional<ArrayElemEqPtr<T>> isArrayElemEq() const override;

    std::optional<ArrayElemNeqPtr<T>> isArrayElemNeq() const override;
};

template <ITheory T>
ConsHash<ArrayLit<T>, ArrayNeq<T>, typename ArrayNeq<T>::CacheHash, typename ArrayNeq<T>::CacheEqual, ArrayPtr<T>, ArrayPtr<T>> ArrayNeq<T>::cache {};

template <ITheory T>
class ArrayElemEq final: public ArrayLit<T>, std::enable_shared_from_this<ArrayElemEq<T>> {

    friend ArrayLitPtr<T> arrays::mkElemEq(const ArrayReadPtr<T>&, const T::Expr&);

    ArrayReadPtr<T> m_lhs;
    T::Expr m_rhs;

    struct CacheEqual {
        bool operator()(const std::tuple<ArrayReadPtr<T>, typename T::Expr> &args1, const std::tuple<ArrayReadPtr<T>, typename T::Expr> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<ArrayReadPtr<T>, typename T::Expr> &args) const noexcept;
    };

    static ConsHash<ArrayLit<T>, ArrayElemEq, CacheHash, CacheEqual, ArrayReadPtr<T>, typename T::Expr> cache;

public:

    ArrayElemEq(const ArrayReadPtr<T>& p_lhs, const T::Expr& p_rhs);

    ArrayReadPtr<T> lhs() const;

    T::Expr rhs() const;

    bool isTriviallyTrue() const override;

    sexpresso::Sexp to_smtlib() const override;

    std::size_t hash() const override;

    ArrayLitPtr<T> subs(const T::Subs& subs) const override;

    ArrayLitPtr<T> subs(const ArraySubs<T>& subs) const override;

    ArrayLitPtr<T> renameVars(const array_var_map<T>&) const override;
    ArrayLitPtr<T> renameVars(const T::Renaming&) const override;
    ArrayLitPtr<T> renameVars(const Renaming&) const override;

    void collectVars(linked_hash_set<ArrayVarPtr<T>>& arr, linked_hash_set<Arith::Var>& arith, linked_hash_set<typename T::Var>& t) const override;

    bool isTriviallyFalse() const override;

    std::optional<ArrayEqPtr<T>> isArrayEq() const override;

    std::optional<ArrayNeqPtr<T>> isArrayNeq() const override;

    std::optional<ArrayElemEqPtr<T>> isArrayElemEq() const override;

    std::optional<ArrayElemNeqPtr<T>> isArrayElemNeq() const override;
};

template <ITheory T>
ConsHash<ArrayLit<T>, ArrayElemEq<T>, typename ArrayElemEq<T>::CacheHash, typename ArrayElemEq<T>::CacheEqual, ArrayReadPtr<T>, typename T::Expr> ArrayElemEq<T>::cache {};

template <ITheory T>
class ArrayElemNeq final: public ArrayLit<T>, std::enable_shared_from_this<ArrayElemNeq<T>> {

    friend ArrayLitPtr<T> arrays::mkElemNeq(const ArrayReadPtr<T>& lhs, const T::Expr& rhs);

    ArrayReadPtr<T> m_lhs;
    T::Expr m_rhs;

    struct CacheEqual {
        bool operator()(const std::tuple<ArrayReadPtr<T>, typename T::Expr> &args1, const std::tuple<ArrayReadPtr<T>, typename T::Expr> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<ArrayReadPtr<T>, typename T::Expr> &args) const noexcept;
    };

    static ConsHash<ArrayLit<T>, ArrayElemNeq, CacheHash, CacheEqual, ArrayReadPtr<T>, typename T::Expr> cache;

public:

    ArrayElemNeq(const ArrayReadPtr<T>& p_lhs, const T::Expr& p_rhs);

    ArrayReadPtr<T> lhs() const;

    T::Expr rhs() const;
    bool isTriviallyTrue() const override;
    sexpresso::Sexp to_smtlib() const override;
    std::size_t hash() const override;
    ArrayLitPtr<T> subs(const T::Subs&) const override;
    ArrayLitPtr<T> subs(const ArraySubs<T>&) const override;
    ArrayLitPtr<T> renameVars(const array_var_map<T>& map) const override;
    ArrayLitPtr<T> renameVars(const T::Renaming& map) const override;
    ArrayLitPtr<T> renameVars(const Renaming&) const override;
    void collectVars(linked_hash_set<ArrayVarPtr<T>>& arr, linked_hash_set<Arith::Var>& arith,
        linked_hash_set<typename T::Var>& t) const override;
    bool isTriviallyFalse() const override;
    std::optional<ArrayEqPtr<T>> isArrayEq() const override;
    std::optional<ArrayNeqPtr<T>> isArrayNeq() const override;
    std::optional<ArrayElemEqPtr<T>> isArrayElemEq() const override;
    std::optional<ArrayElemNeqPtr<T>> isArrayElemNeq() const override;
};

template <ITheory T>
ConsHash<ArrayLit<T>, ArrayElemNeq<T>, typename ArrayElemNeq<T>::CacheHash, typename ArrayElemNeq<T>::CacheEqual, ArrayReadPtr<T>, typename T::Expr> ArrayElemNeq<T>::cache {};

namespace arrays {

    template <ITheory T>
    ArrayLitPtr<T> mkElemEq(const ArrayReadPtr<T> &lhs, const typename T::Expr &rhs) {
        return ArrayElemEq<T>::cache.from_cache(lhs, rhs);
    }

    template <ITheory T>
    ArrayLitPtr<T> mkElemNeq(const ArrayReadPtr<T>& lhs, const typename T::Expr& rhs) {
        return ArrayElemNeq<T>::cache.from_cache(lhs, rhs);
    }

    template <ITheory T>
    ArrayLitPtr<T> mkEq(const ArrayPtr<T>& lhs, const ArrayPtr<T>& rhs) {
        return ArrayEq<T>::cache.from_cache(lhs, rhs);
    }

    template <ITheory T>
    ArrayLitPtr<T> mkNeq(const ArrayPtr<T>& lhs, const ArrayPtr<T>& rhs) {
        return ArrayNeq<T>::cache.from_cache(lhs, rhs);
    }
}

template<ITheory T>
ArrayLitPtr<T> operator!(const ArrayLitPtr<T>& lit) {
    if (const auto eq {lit->isArrayEq()}) {
        return arrays::mkNeq((*eq)->lhs(), (*eq)->rhs());
    }
    if (const auto neq {lit->isArrayNeq()}) {
        return arrays::mkEq((*neq)->lhs(), (*neq)->rhs());
    }
    if (const auto eq {lit->isArrayElemEq()}) {
        return arrays::mkElemNeq((*eq)->lhs(), (*eq)->rhs());
    }
    if (const auto neq {lit->isArrayElemNeq()}) {
        return arrays::mkElemEq((*neq)->lhs(), (*neq)->rhs());
    }
    throw std::logic_error("unknown array literal");
}
