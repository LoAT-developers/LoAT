#include "arraylit.hpp"
#include "sexpresso.hpp"

template <class T>
bool ArrayLit<T>::isPoly() {
    return false;
}

template <class T>
bool ArrayLit<T>::isLinear() {
    return false;
}

template <class T>
bool ArrayLit<T>::simplifyAnd(linked_hash_set<ArrayLitPtr<T>>&) {
    // TODO
    return false;
}

template <class T>
bool ArrayEq<T>::CacheEqual::operator()(
    const std::tuple<ArrayPtr<T>, ArrayPtr<T>>& args1,
    const std::tuple<ArrayPtr<T>, ArrayPtr<T>>& args2) const noexcept {
    return args1 == args2;
}

template <class T>
size_t ArrayEq<T>::CacheHash::operator()(const std::tuple<ArrayPtr<T>, ArrayPtr<T>>& args) const noexcept {
    auto seed{hash_value(std::get<0>(args))};
    boost::hash_combine(seed, std::get<1>(args));
    return seed;
}

template <class T>
ArrayEq<T>::~ArrayEq() {
    cache.erase(m_lhs, m_rhs);
}

template <class T>
ArrayEq<T>::ArrayEq(const ArrayPtr<T>& p_lhs, const ArrayPtr<T>& p_rhs) : m_lhs(p_lhs), m_rhs(p_rhs) {}

template <class T>
ArrayPtr<T> ArrayEq<T>::lhs() const {
    return m_lhs;
}

template <class T>
ArrayPtr<T> ArrayEq<T>::rhs() const {
    return m_rhs;
}

template <class T>
bool ArrayEq<T>::isTriviallyTrue() const {
    return m_lhs == m_rhs;
}

template <class T>
sexpresso::Sexp ArrayEq<T>::to_smtlib() const {
    sexpresso::Sexp res;
    res.addChild("=");
    res.addChild(m_lhs->to_smtlib());
    res.addChild(m_rhs->to_smtlib());
    return res;
}

template <class T>
std::size_t ArrayEq<T>::hash() const {
    std::size_t seed{42};
    boost::hash_combine(seed, m_lhs);
    boost::hash_combine(seed, m_rhs);
    return seed;
}

template <class T>
ArrayLitPtr<T> ArrayEq<T>::subs(const ArraySubs<T>& subs) const {
    return cache.from_cache(m_lhs->subs(subs), m_rhs->subs(subs));
}

template <class T>
ArrayLitPtr<T> ArrayEq<T>::renameVars(const array_var_map<T>& map) const {
    return cache.from_cache(m_lhs->renameVars(map), m_rhs->renameVars(map));
}

template <class T>
ArrayLitPtr<T> ArrayEq<T>::renameVars(const Renaming& map) const {
    return cache.from_cache(m_lhs->renameVars(map), m_rhs->renameVars(map));
}

template <class T>
void ArrayEq<T>::collectVars(VarSet& arr) const {
    m_lhs->collectVars(arr);
    m_rhs->collectVars(arr);
}

template <class T>
bool ArrayEq<T>::isTriviallyFalse() const {
    return false;
}

template <class T>
std::optional<ArrayEqPtr<T>> ArrayEq<T>::isArrayEq() const {
    return cpp::assume_not_null(std::static_pointer_cast<const ArrayEq>(static_cast<const ArrayLit<T>*>(this)->shared_from_this()));
}

template <class T>
std::optional<ArrayNeqPtr<T>> ArrayEq<T>::isArrayNeq() const {
    return {};
}

template <class T>
void ArrayEq<T>::collectCells(CellSet& cells) const {
    m_lhs->collectCells(cells);
    m_rhs->collectCells(cells);
}

template <class T>
bool ArrayNeq<T>::CacheEqual::operator()(
    const std::tuple<ArrayPtr<T>, ArrayPtr<T>>& args1,
    const std::tuple<ArrayPtr<T>, ArrayPtr<T>>& args2) const noexcept {
    return args1 == args2;
}

template <class T>
size_t ArrayNeq<T>::CacheHash::operator()(const std::tuple<ArrayPtr<T>, ArrayPtr<T>>& args) const noexcept {
    auto seed{hash_value(std::get<0>(args))};
    boost::hash_combine(seed, std::get<1>(args));
    return seed;
}

template <class T>
ArrayNeq<T>::~ArrayNeq() {
    cache.erase(m_lhs, m_rhs);
}

template <class T>
ArrayNeq<T>::ArrayNeq(const ArrayPtr<T>& p_lhs, const ArrayPtr<T>& p_rhs) : m_lhs(p_lhs), m_rhs(p_rhs) {}

template <class T>
ArrayPtr<T> ArrayNeq<T>::lhs() const {
    return m_lhs;
}

template <class T>
ArrayPtr<T> ArrayNeq<T>::rhs() const {
    return m_rhs;
}

template <class T>
bool ArrayNeq<T>::isTriviallyTrue() const {
    return false;
}

template <class T>
sexpresso::Sexp ArrayNeq<T>::to_smtlib() const {
    sexpresso::Sexp res;
    res.addChild("distinct");
    res.addChild(m_lhs->to_smtlib());
    res.addChild(m_rhs->to_smtlib());
    return res;
}

template <class T>
std::size_t ArrayNeq<T>::hash() const {
    std::size_t seed{23};
    boost::hash_combine(seed, m_lhs);
    boost::hash_combine(seed, m_rhs);
    return seed;
}

template <class T>
ArrayLitPtr<T> ArrayNeq<T>::subs(const ArraySubs<T>& subs) const {
    return cache.from_cache(m_lhs->subs(subs), m_rhs->subs(subs));
}

template <class T>
ArrayLitPtr<T> ArrayNeq<T>::renameVars(const array_var_map<T>& map) const {
    return cache.from_cache(m_lhs->renameVars(map), m_rhs->renameVars(map));
}

template <class T>
ArrayLitPtr<T> ArrayNeq<T>::renameVars(const Renaming& map) const {
    return cache.from_cache(m_lhs->renameVars(map), m_rhs->renameVars(map));
}

template <class T>
void ArrayNeq<T>::collectVars(VarSet& arr) const {
    m_lhs->collectVars(arr);
    m_rhs->collectVars(arr);
}

template <class T>
bool ArrayNeq<T>::isTriviallyFalse() const {
    return m_lhs == m_rhs;
}

template <class T>
std::optional<ArrayEqPtr<T>> ArrayNeq<T>::isArrayEq() const {
    return {};
}

template <class T>
std::optional<ArrayNeqPtr<T>> ArrayNeq<T>::isArrayNeq() const {
    return cpp::assume_not_null(std::static_pointer_cast<const ArrayNeq>(static_cast<const ArrayLit<T>*>(this)->shared_from_this()));
}

template <class T>
void ArrayNeq<T>::collectCells(CellSet& res) const {
    m_lhs->collectCells(res);
    m_rhs->collectCells(res);
}

template <class T>
std::ostream& operator<<(std::ostream& s, const ArrayLitPtr<T>& e) {
    if (const auto eq = e->isArrayEq()) {
        return s << (*eq)->lhs() << " = " << (*eq)->rhs();
    }
    if (const auto neq = e->isArrayNeq()) {
        return s << (*neq)->lhs() << " != " << (*neq)->rhs();
    }
    throw std::invalid_argument("unknown array literal");
}

Lit arrays::mkEq(const ArrayPtr<Arith>& lhs, const ArrayPtr<Arith>& rhs) {
    if (lhs->dim() == 0) {
        return arith::mkEq(readConst(lhs), readConst(rhs));
    }
    return ArrayEq<Arith>::cache.from_cache(lhs, rhs);
}

Lit arrays::mkNeq(const ArrayPtr<Arith>& lhs, const ArrayPtr<Arith>& rhs) {
    if (lhs->dim() == 0) {
        return arith::mkNeq(readConst(lhs), readConst(rhs));
    }
    return ArrayNeq<Arith>::cache.from_cache(lhs, rhs);
}

template class ArrayLit<Arith>;
template class ArrayEq<Arith>;
template class ArrayNeq<Arith>;

template std::ostream& operator<<(std::ostream&, const ArrayLitPtr<Arith>&);