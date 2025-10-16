#pragma once

#include "exprfwd.hpp"
#include "arith.hpp"
#include "itheory.hpp"
#include "conshash.hpp"

#include <ranges>

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

namespace arrays {

    template <ITheory T>
    ArrayPtr<T> mkVar(int p_idx, unsigned p_dim);
    template <ITheory T>
    ArrayReadPtr<T> mkArrayRead(const ArrayPtr<T>&, const std::vector<Arith::Expr>&);
    template <ITheory T>
    ArrayPtr<T> mkArrayWrite(const ArrayPtr<T>&, const std::vector<Arith::Expr>&, const typename T::Expr&);

}

template <ITheory T>
class Array {

    public:

    virtual ~Array() = default;

    virtual ArrayVarPtr<T> var() const = 0;
    virtual std::vector<Arith::Expr> indices() const = 0;
    virtual std::optional<ArrayVarPtr<T>> isVar() const = 0;
    virtual std::optional<ArrayWritePtr<T>> isArrayWrite() const = 0;
    virtual ArrayPtr<T> subs(const ArithSubs&) const = 0;
    virtual ArrayPtr<T> renameVars(const array_var_map<T>&) const = 0;
    virtual ArrayPtr<T> renameVars(const arith_var_map&) const = 0;
    virtual ArrayPtr<T> renameVars(const Renaming&) const = 0;
    virtual ArrayPtr<T> subs(const ArraySubs<T>&) const = 0;

    virtual sexpresso::Sexp to_smtlib() const = 0;

    virtual void collectVars(linked_hash_set<ArrayVarPtr<T>>&, linked_hash_set<Arith::Var>&, linked_hash_set<typename T::Var>&) const = 0;

};

template <ITheory T>
class ArrayVar final: public Array<T>, std::enable_shared_from_this<ArrayVar<T>> {

    friend ArrayPtr<T> arrays::mkVar(int p_idx, unsigned p_dim);

    struct CacheEqual {
        bool operator()(const std::tuple<int, unsigned> &args1, const std::tuple<int, unsigned> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<int, unsigned> &args) const noexcept;
    };

    static ConsHash<Array<T>, ArrayVar, CacheHash, CacheEqual, int, unsigned> cache;

    using Self = ArrayVarPtr<T>;

    static int last_tmp_idx;
    static int last_prog_idx;
    int idx;
    unsigned m_dim;

public:

    explicit ArrayVar(int p_idx, unsigned p_dim);

    static Self next(unsigned p_dim);

    static Self nextProgVar(unsigned p_dim);

    static Self postVar(const Self& arr);

    std::string getName() const;

    bool isTempVar() const;

    bool isProgVar() const;

    bool isPostVar() const;

    static Self progVar(const Self& arr);

    ArrayPtr<T> subs(const ArithSubs&) const override;

    unsigned dim() const;

    std::optional<Self> isVar() const override;

    Self var() const override;

    std::optional<ArrayWritePtr<T>> isArrayWrite() const override;

    ArrayPtr<T> renameVars(const arith_var_map&) const override;
    ArrayPtr<T> renameVars(const array_var_map<T>& map) const override;
    ArrayPtr<T> renameVars(const Renaming&) const override;

    void collectVars(linked_hash_set<Self>& xs, linked_hash_set<Arith::Var>&, linked_hash_set<typename T::Var>&) const override;

    std::vector<Arith::Expr> indices() const override;

    sexpresso::Sexp to_smtlib() const override;
    ArrayPtr<T> subs(const ArraySubs<T>&) const override;
};

template<ITheory T>
ConsHash<Array<T>, ArrayVar<T>, typename ArrayVar<T>::CacheHash, typename ArrayVar<T>::CacheEqual, int, unsigned> ArrayVar<T>::cache{};

template<ITheory T>
int ArrayVar<T>::last_tmp_idx;

template<ITheory T>
int ArrayVar<T>::last_prog_idx;

template <ITheory T>
std::ostream& operator<<(std::ostream &s, const ArrayVarPtr<T> a) {
    return s << a->getName();
}

template <ITheory T>
class ArrayWrite final: public Array<T>, std::enable_shared_from_this<ArrayWrite<T>> {

    friend ArrayPtr<T> arrays::mkArrayWrite(const ArrayPtr<T>& arr, const std::vector<Arith::Expr>& indices, const T::Expr& val);

    ArrayPtr<T> m_arr;
    std::vector<Arith::Expr> m_indices;
    T::Expr m_val;

    struct CacheEqual {
        bool operator()(const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>, typename T::Expr> &args1, const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>, typename T::Expr> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>, typename T::Expr> &args) const noexcept;
    };

    static ConsHash<Array<T>, ArrayWrite, CacheHash, CacheEqual, ArrayPtr<T>, std::vector<Arith::Expr>, typename T::Expr> cache;

public:

    ArrayWrite(const ArrayPtr<T>& p_arr, const std::vector<Arith::Expr>& p_indices, const T::Expr &p_val);

    ArrayPtr<T> arr() const;

    std::vector<Arith::Expr> indices() const override;

    T::Expr val() const;

    ArrayPtr<T> subs(const ArithSubs& that) const override;

    ArrayVarPtr<T> var() const override;

    std::optional<ArrayVarPtr<T>> isVar() const override;

    std::optional<ArrayWritePtr<T>> isArrayWrite() const override;

    ArrayPtr<T> renameVars(const array_var_map<T>& map) const override;
    ArrayPtr<T> renameVars(const arith_var_map& map) const override;
    ArrayPtr<T> renameVars(const Renaming&) const override;

    void collectVars(linked_hash_set<ArrayVarPtr<T>>& arr, linked_hash_set<Arith::Var>& arith, linked_hash_set<typename T::Var>& t) const override;

    sexpresso::Sexp to_smtlib() const override;
    ArrayPtr<T> subs(const ArraySubs<T>&) const override;
};

template <ITheory T>
ConsHash<Array<T>, ArrayWrite<T>, typename ArrayWrite<T>::CacheHash, typename ArrayWrite<T>::CacheEqual, ArrayPtr<T>, std::vector<Arith::Expr>, typename T::Expr> ArrayWrite<T>::cache{};

template <ITheory T>
class ArrayRead final {

    friend ArrayReadPtr<T> arrays::mkArrayRead(const ArrayPtr<T>& arr, const std::vector<Arith::Expr>& indices);

    ArrayPtr<T> m_arr;
    std::vector<Arith::Expr> m_indices;

    struct CacheEqual {
        bool operator()(const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>> &args1, const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>> &args) const noexcept;
    };

    static ConsHash<ArrayRead, ArrayRead, CacheHash, CacheEqual, ArrayPtr<T>, std::vector<Arith::Expr>> cache;

public:

    ArrayRead(const ArrayPtr<T>& p_arr, const std::vector<Arith::Expr>& p_indices);

    ArrayPtr<T> arr() const;

    std::vector<Arith::Expr> indices() const;

    bool isTempVar() const;

    bool isProgVar() const;

    bool isPostVar() const;

    sexpresso::Sexp to_smtlib() const;

    ArrayReadPtr<T> subs(const ArithSubs& subs) const;
    ArrayReadPtr<T> subs(const ArraySubs<T>& subs) const;

    ArrayReadPtr<T> renameVars(const array_var_map<T>& map) const;
    ArrayReadPtr<T> renameVars(const T::Renaming& map) const;
    ArrayReadPtr<T> renameVars(const Renaming&) const;

    void collectVars(linked_hash_set<ArrayVarPtr<T>>&, linked_hash_set<Arith::Var>&, linked_hash_set<typename T::Var>&) const;

    static ArrayReadPtr<T> postVar(const ArrayReadPtr<T>&);
    static ArrayReadPtr<T> progVar(const ArrayReadPtr<T>&);

};

template <ITheory T>
ConsHash<ArrayRead<T>, ArrayRead<T>, typename ArrayRead<T>::CacheHash, typename ArrayRead<T>::CacheEqual, ArrayPtr<T>, std::vector<Arith::Expr>> ArrayRead<T>::cache;

template <ITheory T>
std::ostream& operator<<(std::ostream& s, const ArrayReadPtr<T>& read) {
    s << read->arr();
    for (const auto &i: read->indices()) {
        s << "[" << i << "]";
    }
    return s;
}

template <ITheory T>
std::ostream& operator<<(std::ostream& s, const ArrayPtr<T>& a) {
    if (const auto var {a->isVar()}) {
        return s << (*var)->getName();
    }
    const auto write{a->isArrayWrite()};
    s << (*write)->arr();
    for (const auto& i : (*write)->indices()) {
        s << "[" << i << "]";
    }
    s << ":=" << (*write)->val();
    return s;
}

namespace arrays {

    template <ITheory T>
    ArrayPtr<T> mkVar(int p_idx, unsigned p_dim) {
        return ArrayVar<T>::cache.from_cache(p_idx, p_dim);
    }

    template <ITheory T>
    ArrayReadPtr<T> mkArrayRead(const ArrayPtr<T>& arr, const std::vector<Arith::Expr>& indices) {
        return ArrayRead<T>::cache.from_cache(arr, indices);
    }

    template <ITheory T>
    ArrayPtr<T> mkArrayWrite(const ArrayPtr<T>& arr, const std::vector<Arith::Expr>& indices, const typename T::Expr& val) {
        return ArrayWrite<T>::cache.from_cache(arr, indices, val);
    }

}
