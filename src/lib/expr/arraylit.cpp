#include "arraylit.hpp"
#include "sexpresso.hpp"

template <ITheory T>
bool ArrayLit<T>::isPoly() {
    return false;
}

template <ITheory T>
bool ArrayLit<T>::isLinear() {
    return false;
}

template <ITheory T>
bool ArrayLit<T>::simplifyAnd(linked_hash_set<ArrayLitPtr<T>>&) {
    // TODO
    return false;
}

template <ITheory T>
bool ArrayEq<T>::CacheEqual::operator()(const std::tuple<ArrayPtr<T>, ArrayPtr<T>>& args1,
                                        const std::tuple<ArrayPtr<T>, ArrayPtr<T>>& args2) const noexcept {
    return args1 == args2;
}

template <ITheory T>
size_t ArrayEq<T>::CacheHash::operator()(const std::tuple<ArrayPtr<T>, ArrayPtr<T>>& args) const noexcept {
    auto seed{hash_value(std::get<0>(args))};
    boost::hash_combine(seed, std::get<1>(args));
    return seed;
}

template <ITheory T>
ArrayEq<T>::ArrayEq(const ArrayPtr<T>& p_lhs, const ArrayPtr<T>& p_rhs) : m_lhs(p_lhs), m_rhs(p_rhs) {}

template <ITheory T>
ArrayPtr<T> ArrayEq<T>::lhs() const {
    return m_lhs;
}

template <ITheory T>
ArrayPtr<T> ArrayEq<T>::rhs() const {
    return m_rhs;
}

template <ITheory T>
bool ArrayEq<T>::isTriviallyTrue() const {
    return m_lhs == m_rhs;
}

template <ITheory T>
sexpresso::Sexp ArrayEq<T>::to_smtlib() const {
    sexpresso::Sexp res;
    res.addChild("=");
    res.addChild(m_lhs->to_smtlib());
    res.addChild(m_rhs->to_smtlib());
    return res;
}

template <ITheory T>
std::size_t ArrayEq<T>::hash() const {
    std::size_t seed{42};
    boost::hash_combine(seed, m_lhs);
    boost::hash_combine(seed, m_rhs);
    return seed;
}

template <ITheory T>
ArrayLitPtr<T> ArrayEq<T>::subs(const typename T::Subs& subs) const {
    return arrays::mkEq(m_lhs->subs(subs), m_rhs->subs(subs));
}

template <ITheory T>
ArrayLitPtr<T> ArrayEq<T>::subs(const ArraySubs<T>& subs) const {
    return arrays::mkEq(m_lhs->subs(subs), m_rhs->subs(subs));
}

template <ITheory T>
ArrayLitPtr<T> ArrayEq<T>::renameVars(const array_var_map<T>& map) const {
    return arrays::mkEq(m_lhs->renameVars(map), m_rhs->renameVars(map));
}

template <ITheory T>
ArrayLitPtr<T> ArrayEq<T>::renameVars(const typename T::Renaming& map) const {
    return arrays::mkEq(m_lhs->renameVars(map), m_rhs->renameVars(map));
}

template <ITheory T>
void ArrayEq<T>::collectVars(linked_hash_set<ArrayVarPtr<T>>& arr, linked_hash_set<Arith::Var>& arith,
                             linked_hash_set<typename T::Var>& t) const {
    m_lhs->collectVars(arr, arith, t);
    m_rhs->collectVars(arr, arith, t);
}

template <ITheory T>
bool ArrayEq<T>::isTriviallyFalse() const {
    return false;
}

template <ITheory T>
std::optional<ArrayEqPtr<T>> ArrayEq<T>::isArrayEq() const {
    return cpp::assume_not_null(this->shared_from_this());
}

template <ITheory T>
std::optional<ArrayNeqPtr<T>> ArrayEq<T>::isArrayNeq() const {
    return {};
}

template <ITheory T>
std::optional<ArrayElemEqPtr<T>> ArrayEq<T>::isArrayElemEq() const {
    return {};
}

template <ITheory T>
std::optional<ArrayElemNeqPtr<T>> ArrayEq<T>::isArrayElemNeq() const {
    return {};
}

template <ITheory T>
bool ArrayNeq<T>::CacheEqual::operator()(const std::tuple<ArrayPtr<T>, ArrayPtr<T>>& args1,
                                         const std::tuple<ArrayPtr<T>, ArrayPtr<T>>& args2) const noexcept {
    return args1 == args2;
}

template <ITheory T>
size_t ArrayNeq<T>::CacheHash::operator()(const std::tuple<ArrayPtr<T>, ArrayPtr<T>>& args) const noexcept {
    auto seed{hash_value(std::get<0>(args))};
    boost::hash_combine(seed, std::get<1>(args));
    return seed;
}

template <ITheory T>
ArrayNeq<T>::ArrayNeq(const ArrayPtr<T>& p_lhs, const ArrayPtr<T>& p_rhs) : m_lhs(p_lhs), m_rhs(p_rhs) {}

template <ITheory T>
ArrayPtr<T> ArrayNeq<T>::lhs() const {
    return m_lhs;
}

template <ITheory T>
ArrayPtr<T> ArrayNeq<T>::rhs() const {
    return m_rhs;
}

template <ITheory T>
bool ArrayNeq<T>::isTriviallyTrue() const {
    return false;
}

template <ITheory T>
sexpresso::Sexp ArrayNeq<T>::to_smtlib() const {
    sexpresso::Sexp res;
    res.addChild("distinct");
    res.addChild(m_lhs->to_smtlib());
    res.addChild(m_rhs->to_smtlib());
    return res;
}

template <ITheory T>
std::size_t ArrayNeq<T>::hash() const {
    std::size_t seed{23};
    boost::hash_combine(seed, m_lhs);
    boost::hash_combine(seed, m_rhs);
    return seed;
}

template <ITheory T>
ArrayLitPtr<T> ArrayNeq<T>::subs(const typename T::Subs& subs) const {
    return arrays::mkNeq(m_lhs->subs(subs), m_rhs->subs(subs));
}

template <ITheory T>
ArrayLitPtr<T> ArrayNeq<T>::subs(const ArraySubs<T>& subs) const {
    return arrays::mkNeq(m_lhs->subs(subs), m_rhs->subs(subs));
}

template <ITheory T>
ArrayLitPtr<T> ArrayNeq<T>::renameVars(const array_var_map<T>& map) const {
    return arrays::mkNeq(m_lhs->renameVars(map), m_rhs->renameVars(map));
}

template <ITheory T>
ArrayLitPtr<T> ArrayNeq<T>::renameVars(const typename T::Renaming& map) const {
    return arrays::mkNeq(m_lhs->renameVars(map), m_rhs->renameVars(map));
}

template <ITheory T>
void ArrayNeq<T>::collectVars(linked_hash_set<ArrayVarPtr<T>>& arr, linked_hash_set<Arith::Var>& arith,
                              linked_hash_set<typename T::Var>& t) const {
    m_lhs->collectVars(arr, arith, t);
    m_rhs->collectVars(arr, arith, t);
}

template <ITheory T>
bool ArrayNeq<T>::isTriviallyFalse() const {
    return m_lhs == m_rhs;
}

template <ITheory T>
std::optional<ArrayEqPtr<T>> ArrayNeq<T>::isArrayEq() const {
    return {};
}

template <ITheory T>
std::optional<ArrayNeqPtr<T>> ArrayNeq<T>::isArrayNeq() const {
    return cpp::assume_not_null(this->shared_from_this());
}

template <ITheory T>
std::optional<ArrayElemEqPtr<T>> ArrayNeq<T>::isArrayElemEq() const {
    return {};
}

template <ITheory T>
std::optional<ArrayElemNeqPtr<T>> ArrayNeq<T>::isArrayElemNeq() const {
    return {};
}

template <ITheory T>
bool ArrayElemEq<T>::CacheEqual::operator()(const std::tuple<ArrayReadPtr<T>, typename T::Expr>& args1,
                                            const std::tuple<ArrayReadPtr<T>, typename T::Expr>& args2) const noexcept {
    return args1 == args2;
}

template <ITheory T>
size_t ArrayElemEq<T>::CacheHash::operator()(const std::tuple<ArrayReadPtr<T>, typename T::Expr>& args) const noexcept {
    auto seed{hash_value(std::get<0>(args))};
    boost::hash_combine(seed, std::get<1>(args));
    return seed;
}

template <ITheory T>
ArrayElemEq<T>::ArrayElemEq(const ArrayReadPtr<T>& p_lhs, const typename T::Expr& p_rhs) : m_lhs(p_lhs), m_rhs(p_rhs) {}

template <ITheory T>
ArrayReadPtr<T> ArrayElemEq<T>::lhs() const {
    return m_lhs;
}

template <ITheory T>
T::Expr ArrayElemEq<T>::rhs() const {
    return m_rhs;
}

template <ITheory T>
bool ArrayElemEq<T>::isTriviallyTrue() const {
    return false;
}

template <ITheory T>
sexpresso::Sexp ArrayElemEq<T>::to_smtlib() const {
    sexpresso::Sexp res;
    res.addChild("=");
    res.addChild(m_lhs->to_smtlib());
    res.addChild(m_rhs->to_smtlib());
    return res;
}

template <ITheory T>
std::size_t ArrayElemEq<T>::hash() const {
    std::size_t seed{42};
    boost::hash_combine(seed, m_lhs);
    boost::hash_combine(seed, m_rhs);
    return seed;
}

template <ITheory T>
ArrayLitPtr<T> ArrayElemEq<T>::subs(const typename T::Subs& subs) const {
    return arrays::mkElemEq<T>(m_lhs->subs(subs), m_rhs->subs(subs));
}

template <ITheory T>
ArrayLitPtr<T> ArrayElemEq<T>::subs(const ArraySubs<T>& subs) const {
    return arrays::mkElemEq<T>(m_lhs->subs(subs), m_rhs);
}

template <ITheory T>
ArrayLitPtr<T> ArrayElemEq<T>::renameVars(const array_var_map<T>& map) const {
    return arrays::mkElemEq<T>(m_lhs->renameVars(map), m_rhs);
}

template <ITheory T>
ArrayLitPtr<T> ArrayElemEq<T>::renameVars(const typename T::Renaming& map) const {
    return arrays::mkElemEq<T>(m_lhs->renameVars(map), m_rhs->renameVars(map));
}

template <ITheory T>
void ArrayElemEq<T>::collectVars(linked_hash_set<ArrayVarPtr<T>>& arr, linked_hash_set<Arith::Var>& arith,
                                 linked_hash_set<typename T::Var>& t) const {
    m_lhs->collectVars(arr, arith, t);
    m_rhs->collectVars(t);
}

template <ITheory T>
bool ArrayElemEq<T>::isTriviallyFalse() const {
    return false;
}

template <ITheory T>
std::optional<ArrayEqPtr<T>> ArrayElemEq<T>::isArrayEq() const {
    return {};
}

template <ITheory T>
std::optional<ArrayNeqPtr<T>> ArrayElemEq<T>::isArrayNeq() const {
    return {};
}

template <ITheory T>
std::optional<ArrayElemEqPtr<T>> ArrayElemEq<T>::isArrayElemEq() const {
    return cpp::assume_not_null(this->shared_from_this());
}

template <ITheory T>
std::optional<ArrayElemNeqPtr<T>> ArrayElemEq<T>::isArrayElemNeq() const {
    return {};
}

template <ITheory T>
bool ArrayElemNeq<T>::CacheEqual::operator()(const std::tuple<ArrayReadPtr<T>, typename T::Expr>& args1,
                                             const std::tuple<ArrayReadPtr<T>, typename T::Expr>& args2) const
    noexcept {
    return args1 == args2;
}

template <ITheory T>
size_t ArrayElemNeq<T>::CacheHash::operator(
)(const std::tuple<ArrayReadPtr<T>, typename T::Expr>& args) const noexcept {
    auto seed{hash_value(std::get<0>(args))};
    boost::hash_combine(seed, std::get<1>(args));
    return seed;
}

template <ITheory T>
ArrayElemNeq<
    T>::ArrayElemNeq(const ArrayReadPtr<T>& p_lhs, const typename T::Expr& p_rhs) : m_lhs(p_lhs), m_rhs(p_rhs) {}

template <ITheory T>
ArrayReadPtr<T> ArrayElemNeq<T>::lhs() const {
    return m_lhs;
}

template <ITheory T>
typename T::Expr ArrayElemNeq<T>::rhs() const {
    return m_rhs;
}

template <ITheory T>
bool ArrayElemNeq<T>::isTriviallyTrue() const {
    return false;
}

template <ITheory T>
sexpresso::Sexp ArrayElemNeq<T>::to_smtlib() const {
    sexpresso::Sexp res;
    res.addChild("distinct");
    res.addChild(m_lhs->to_smtlib());
    res.addChild(m_rhs->to_smtlib());
    return res;
}

template <ITheory T>
std::size_t ArrayElemNeq<T>::hash() const {
    auto seed{hash_value(m_lhs)};
    boost::hash_combine(seed, m_rhs);
    return seed;
}

template <ITheory T>
ArrayLitPtr<T> ArrayElemNeq<T>::subs(const typename T::Subs& subs) const {
    return arrays::mkElemNeq(m_lhs->subs(subs), m_rhs->subs(subs));
}

template <ITheory T>
ArrayLitPtr<T> ArrayElemNeq<T>::subs(const ArraySubs<T>& subs) const {
    return arrays::mkElemNeq(m_lhs->subs(subs), m_rhs);
}

template <ITheory T>
ArrayLitPtr<T> ArrayElemNeq<T>::renameVars(const array_var_map<T>& map) const {
    return arrays::mkElemNeq(m_lhs->renameVars(map), m_rhs);
}

template <ITheory T>
ArrayLitPtr<T> ArrayElemNeq<T>::renameVars(const typename T::Renaming& map) const {
    return arrays::mkElemNeq(m_lhs->renameVars(map), m_rhs->renameVars(map));
}

template <ITheory T>
void ArrayElemNeq<T>::collectVars(linked_hash_set<ArrayVarPtr<T>>& arr, linked_hash_set<Arith::Var>& arith,
    linked_hash_set<typename T::Var>& t) const {
    m_lhs->collectVars(arr, arith, t);
    m_rhs->collectVars(t);
}

template <ITheory T>
bool ArrayElemNeq<T>::isTriviallyFalse() const {
    return false;
}

template <ITheory T>
std::optional<ArrayEqPtr<T>> ArrayElemNeq<T>::isArrayEq() const {
    return {};
}

template <ITheory T>
std::optional<ArrayNeqPtr<T>> ArrayElemNeq<T>::isArrayNeq() const {
    return {};
}

template <ITheory T>
std::optional<ArrayElemEqPtr<T>> ArrayElemNeq<T>::isArrayElemEq() const {
    return {};
}

template <ITheory T>
std::optional<ArrayElemNeqPtr<T>> ArrayElemNeq<T>::isArrayElemNeq() const {
    return cpp::assume_not_null(this->shared_from_this());
}

template class ArrayLit<Arith>;
template class ArrayEq<Arith>;
template class ArrayNeq<Arith>;
template class ArrayElemEq<Arith>;
template class ArrayElemNeq<Arith>;
