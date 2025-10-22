#pragma once

#include "exprfwd.hpp"
#include "arith.hpp"
#include "conshash.hpp"

#include <ranges>

template <class T>
class Array;

template <class T>
class ArrayWrite;

template <class T>
class ArrayRead;

template <class T>
using ArrayReadPtr = ptr<ArrayRead<T>>;

template <class T>
using ArrayWritePtr = ptr<ArrayWrite<T>>;

template <class T>
using ArrayPtr = ptr<Array<T>>;

namespace arrays {

    template <class T>
    ArrayPtr<T> mkVar(int p_idx, unsigned p_dim);

    Arith::Expr mkArrayRead(const ArrayPtr<Arith>&, const std::vector<Arith::Expr>&);
    ArrayPtr<Arith> mkArrayWrite(const ArrayPtr<Arith>&, const std::vector<Arith::Expr>&, const Arith::Expr&);
    ArrayReadPtr<Arith> readConst(const ArrayPtr<Arith>& arr);
    ArrayPtr<Arith> update(const ArrayReadPtr<Arith>& read, const Arith::Expr& val);
    ArrayPtr<Arith> writeConst(const ArrayPtr<Arith>& arr, const Arith::Expr& val);

    template <class T>
    ArrayReadPtr<T> nextProgConst();

    template <class T>
    ArrayReadPtr<T> nextConst();

}

template <class T>
class Array {

    public:

    virtual ~Array() = default;

    virtual ArrayVarPtr<T> var() const = 0;
    virtual unsigned dim() const = 0;
    virtual std::vector<Arith::Expr> indices() const = 0;
    virtual std::optional<ArrayVarPtr<T>> isVar() const = 0;
    virtual std::optional<ArrayWritePtr<T>> isArrayWrite() const = 0;
    virtual ArrayPtr<T> renameVars(const array_var_map<T>&) const = 0;
    virtual ArrayPtr<T> renameVars(const Renaming&) const = 0;
    virtual ArrayPtr<T> subs(const ArraySubs<T>&) const = 0;
    virtual ArrayPtr<T> withVar(const ArrayVarPtr<T>&) const = 0;
    virtual bool isLinear() const = 0;
    virtual std::optional<Int> isPoly() const = 0;

    virtual sexpresso::Sexp to_smtlib() const = 0;

    virtual void collectVars(linked_hash_set<ArrayVarPtr<T>>&) const = 0;
    void collectVars(VarSet&) const;
    linked_hash_set<ArrayVarPtr<T>> vars() const;
    virtual void collectCells(linked_hash_set<ArrayReadPtr<T>>&) const = 0;

};

template <class T>
class ArrayVar final: public Array<T>, std::enable_shared_from_this<ArrayVar<T>> {

    friend ArrayPtr<T> arrays::mkVar(int p_idx, unsigned p_dim);
    friend class ConsHash<ArrayVar, int, unsigned>;

    struct CacheEqual {
        bool operator()(const std::tuple<int, unsigned> &args1, const std::tuple<int, unsigned> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<int, unsigned> &args) const noexcept;
    };

    static ConsHash<ArrayVar, int, unsigned> cache;

    using Self = ArrayVarPtr<T>;

    static int last_tmp_idx;
    static int last_prog_idx;
    int m_idx;
    unsigned m_dim;

public:

    explicit ArrayVar(int p_idx, unsigned p_dim);
    ~ArrayVar() override;

    static Self next(unsigned p_dim);

    static Self nextProgVar(unsigned p_dim);

    Self postVar() const;

    std::string getName() const;

    unsigned idx() const;

    bool isTempVar() const;

    bool isProgVar() const;

    bool isPostVar() const;

    Self progVar() const;

    std::optional<Self> isVar() const override;

    Self var() const override;

    std::optional<ArrayWritePtr<T>> isArrayWrite() const override;

    ArrayPtr<T> renameVars(const array_var_map<T>& map) const override;
    ArrayPtr<T> renameVars(const Renaming&) const override;

    void collectVars(linked_hash_set<Self>& xs) const override;

    std::vector<Arith::Expr> indices() const override;

    sexpresso::Sexp to_smtlib() const override;
    ArrayPtr<T> subs(const ArraySubs<T>&) const override;
    ArrayPtr<T> withVar(const ArrayVarPtr<T>&) const override;
    bool isLinear() const override;
    std::optional<Int> isPoly() const override;
    unsigned dim() const override;
    void collectCells(linked_hash_set<cpp::not_null<std::shared_ptr<const ArrayRead<T>>>>&) const override;
};

template<class T>
ConsHash<ArrayVar<T>, int, unsigned> ArrayVar<T>::cache{};

template<class T>
int ArrayVar<T>::last_tmp_idx;

template<class T>
int ArrayVar<T>::last_prog_idx;

template <class T>
std::ostream& operator<<(std::ostream &s, const ArrayVarPtr<T> a) {
    return s << a->getName();
}

template <class T>
class ArrayWrite final: public Array<T>, std::enable_shared_from_this<ArrayWrite<T>> {

    friend ArrayPtr<Arith> arrays::mkArrayWrite(const ArrayPtr<Arith>& arr, const std::vector<Arith::Expr>& indices, const Arith::Expr& val);
    friend class ConsHash<ArrayWrite, ArrayPtr<T>, std::vector<Arith::Expr>, typename T::Expr>;

    ArrayPtr<T> m_arr;
    std::vector<Arith::Expr> m_indices;
    T::Expr m_val;

    struct CacheEqual {
        bool operator()(const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>, typename T::Expr> &args1, const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>, typename T::Expr> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>, typename T::Expr> &args) const noexcept;
    };

    static ConsHash<ArrayWrite, ArrayPtr<T>, std::vector<Arith::Expr>, typename T::Expr> cache;

public:

    ArrayWrite(const ArrayPtr<T>& p_arr, const std::vector<Arith::Expr>& p_indices, const T::Expr &p_val);
    ~ArrayWrite() override;

    ArrayPtr<T> arr() const;

    std::vector<Arith::Expr> indices() const override;

    T::Expr val() const;

    ArrayVarPtr<T> var() const override;

    std::optional<ArrayVarPtr<T>> isVar() const override;

    std::optional<ArrayWritePtr<T>> isArrayWrite() const override;

    ArrayPtr<T> renameVars(const array_var_map<T>& map) const override;
    ArrayPtr<T> renameVars(const Renaming&) const override;

    void collectVars(linked_hash_set<ArrayVarPtr<T>>& arr) const override;

    sexpresso::Sexp to_smtlib() const override;
    ArrayPtr<T> subs(const ArraySubs<T>&) const override;
    ArrayPtr<T> withVar(const ArrayVarPtr<T>&) const override;
    bool isLinear() const override;
    std::optional<Int> isPoly() const override;
    unsigned dim() const override;
    void collectCells(linked_hash_set<cpp::not_null<std::shared_ptr<const ArrayRead<T>>>>&) const override;
};

template <class T>
ConsHash<ArrayWrite<T>, ArrayPtr<T>, std::vector<Arith::Expr>, typename T::Expr> ArrayWrite<T>::cache{};

template <class T>
class ArrayRead final: public T::Expr::element_type {

    friend Arith::Expr arrays::mkArrayRead(const ArrayPtr<Arith>& arr, const std::vector<Arith::Expr>& indices);
    friend ArrayReadPtr<T> arrays::nextConst();
    friend ArrayReadPtr<Arith> arrays::readConst(const ArrayPtr<Arith>& arr);
    friend ArrayReadPtr<T> arrays::nextProgConst();
    friend class ConsHash<ArrayRead, ArrayPtr<T>, std::vector<Arith::Expr>>;

    ArrayPtr<T> m_arr;
    std::vector<Arith::Expr> m_indices;

    struct CacheEqual {
        bool operator()(const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>> &args1, const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>> &args) const noexcept;
    };

    static ConsHash<ArrayRead, ArrayPtr<T>, std::vector<Arith::Expr>> cache;

public:

    ArrayRead(const ArrayPtr<T>& p_arr, const std::vector<Arith::Expr>& p_indices);
    ~ArrayRead();

    // getter
    ArrayPtr<T> arr() const;
    ArrayVarPtr<T> var() const;
    unsigned dim() const;
    std::vector<Arith::Expr> indices() const;

    // properties
    bool isTempVar() const;
    bool isProgVar() const;
    bool isPostVar() const;
    bool isLinear() const;
    std::optional<Int> isPoly() const;
    bool isPostCell() const;
    bool isProgCell() const;

    // mutators
    ArrayReadPtr<T> renameVars(const array_var_map<T>& map) const;
    ArrayReadPtr<T> renameVars(const Renaming&) const;
    ArrayReadPtr<T> withVar(const ArrayVarPtr<T>&) const;

    // utility
    T::Expr toExpr() const;
    sexpresso::Sexp to_smtlib() const;

    // retrieval
    void collectVars(linked_hash_set<ArrayVarPtr<T>>&) const;
    void collectVars(VarSet&) const;
    linked_hash_set<ArrayVarPtr<T>> vars() const;

};

template <class T>
ConsHash<ArrayRead<T>, ArrayPtr<T>, std::vector<Arith::Expr>> ArrayRead<T>::cache;

template <class T>
std::ostream& operator<<(std::ostream& s, const ArrayReadPtr<T>& read) {
    s << read->arr();
    for (const auto &i: read->indices()) {
        s << "[" << i << "]";
    }
    return s;
}

template <class T>
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

    template <class T>
    ArrayPtr<T> mkVar(int p_idx, unsigned p_dim) {
        return ArrayVar<T>::cache.from_cache(p_idx, p_dim);
    }

    template <class T>
    ArrayReadPtr<T> nextConst() {
        return ArrayRead<T>::cache.from_cache(ArrayVar<T>::next(0), {});
    }

    template <class T>
    ArrayReadPtr<T> nextProgConst() {
        return ArrayRead<T>::cache.from_cache(ArrayVar<T>::nextProgVar(0), {});
    }

}
