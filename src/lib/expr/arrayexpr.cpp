#include "arrayexpr.hpp"
#include "sexpresso.hpp"
#include "arraysubs.hpp"

template <ITheory T>
bool ArrayVar<T>::CacheEqual::operator()(const std::tuple<int, unsigned>& args1,
                                         const std::tuple<int, unsigned>& args2) const noexcept {
    return args1 == args2;
}

template <ITheory T>
size_t ArrayVar<T>::CacheHash::operator()(const std::tuple<int, unsigned>& args) const noexcept {
    auto seed{std::hash<int>()(std::get<int>(args))};
    boost::hash_combine(seed, std::get<unsigned>(args));
    return seed;
}

template <ITheory T>
ArrayVar<T>::ArrayVar(const int p_idx, const unsigned p_dim) : idx(p_idx), m_dim(p_dim) {}

template <ITheory T>
ArrayVar<T>::Self ArrayVar<T>::next(const unsigned p_dim) {
    --last_tmp_idx;
    return arrays::mkVar<T>(last_tmp_idx, p_dim)->var();
}

template <ITheory T>
ArrayVar<T>::Self ArrayVar<T>::nextProgVar(const unsigned p_dim) {
    ++last_prog_idx;
    return arrays::mkVar<T>(last_prog_idx, p_dim)->var();
}

template <ITheory T>
ArrayVar<T>::Self ArrayVar<T>::postVar(const Self& arr) {
    return arrays::mkVar<T>(arr->idx + 1, arr->m_dim)->var();
}

template <ITheory T>
std::string ArrayVar<T>::getName() const {
    if (idx > 0) {
        return "a" + std::to_string(idx);
    }
    return "at" + std::to_string(-idx);
}

template <ITheory T>
bool ArrayVar<T>::isTempVar() const {
    return idx < 0;
}

template <ITheory T>
bool ArrayVar<T>::isProgVar() const {
    return idx > 0 && idx % 2 == 1;
}

template <ITheory T>
bool ArrayVar<T>::isPostVar() const {
    return idx > 0 && idx % 2 == 0;
}

template <ITheory T>
ArrayVar<T>::Self ArrayVar<T>::progVar(const Self& arr) {
    return arrays::mkVar<T>(arr->idx - 1, arr->m_dim)->var();
}

template <ITheory T>
ArrayPtr<T> ArrayVar<T>::subs(const ArithSubs&) const {
    return cpp::assume_not_null(this->shared_from_this());
}

template <ITheory T>
unsigned ArrayVar<T>::dim() const {
    return m_dim;
}

template <ITheory T>
std::optional<typename ArrayVar<T>::Self> ArrayVar<T>::isVar() const {
    return cpp::assume_not_null(this->shared_from_this());
}

template <ITheory T>
ArrayVar<T>::Self ArrayVar<T>::var() const {
    return cpp::assume_not_null(this->shared_from_this());
}

template <ITheory T>
std::optional<ArrayWritePtr<T>> ArrayVar<T>::isArrayWrite() const {
    return {};
}

template <ITheory T>
ArrayPtr<T> ArrayVar<T>::renameVars(const arith_var_map&) const {
    return var();
}

template <ITheory T>
ArrayPtr<T> ArrayVar<T>::renameVars(const array_var_map<T>& map) const {
    const auto x{var()};
    const auto it{map.left.find(x)};
    return it == map.left.end() ? x : it->second;
}

template <ITheory T>
void ArrayVar<T>::collectVars(linked_hash_set<Self>& xs, linked_hash_set<Arith::Var>&,
                              linked_hash_set<typename T::Var>&) const {
    xs.insert(var());
}

template <ITheory T>
std::vector<Arith::Expr> ArrayVar<T>::indices() const {
    return {};
}

template <ITheory T>
sexpresso::Sexp ArrayVar<T>::to_smtlib() const {
    return sexpresso::Sexp(getName());
}

template <ITheory T>
ArrayPtr<T> ArrayVar<T>::subs(const ArraySubs<T>& subs) const {
    return subs.get(var());
}

template <ITheory T>
bool ArrayWrite<T>::CacheEqual::operator()(
    const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>, typename T::Expr>& args1,
    const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>, typename T::Expr>& args2) const noexcept {
    return args1 == args2;
}

template <ITheory T>
size_t ArrayWrite<T>::CacheHash::operator()(
    const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>, typename T::Expr>& args) const noexcept {
    auto seed{hash_value(std::get<0>(args))};
    boost::hash_combine(seed, std::get<1>(args));
    boost::hash_combine(seed, std::get<2>(args));
    return seed;
}

template <ITheory T>
ArrayWrite<T>::ArrayWrite(const ArrayPtr<T>& p_arr, const std::vector<Arith::Expr>& p_indices,
                          const typename T::Expr& p_val) : m_arr(p_arr), m_indices(p_indices), m_val(p_val) {}

template <ITheory T>
ArrayPtr<T> ArrayWrite<T>::arr() const {
    return m_arr;
}

template <ITheory T>
std::vector<Arith::Expr> ArrayWrite<T>::indices() const {
    return m_indices;
}

template <ITheory T>
T::Expr ArrayWrite<T>::val() const {
    return m_val;
}

template <ITheory T>
ArrayPtr<T> ArrayWrite<T>::subs(const ArithSubs& that) const {
    std::vector<Arith::Expr> indices;
    for (const auto& i : m_indices) {
        indices.emplace_back(i->subs(that));
    }
    return arrays::mkArrayWrite(m_arr, indices, m_val->subs(that));
}

template <ITheory T>
ArrayVarPtr<T> ArrayWrite<T>::var() const {
    return m_arr->var();
}

template <ITheory T>
std::optional<ArrayVarPtr<T>> ArrayWrite<T>::isVar() const {
    return {};
}

template <ITheory T>
std::optional<ArrayWritePtr<T>> ArrayWrite<T>::isArrayWrite() const {
    return cpp::assume_not_null(this->shared_from_this());
}

template <ITheory T>
ArrayPtr<T> ArrayWrite<T>::renameVars(const array_var_map<T>& map) const {
    return arrays::mkArrayWrite(m_arr->renameVars(map), m_indices, m_val);
}

template <ITheory T>
ArrayPtr<T> ArrayWrite<T>::renameVars(const arith_var_map& map) const {
    const auto indices{
        m_indices | std::views::transform([&](const auto& i) {
            return i->renameVars(map);
        })
    };
    return arrays::mkArrayWrite(m_arr, {indices.begin(), indices.end()}, m_val->renameVars(map));
}

template <ITheory T>
void ArrayWrite<T>::collectVars(linked_hash_set<ArrayVarPtr<T>>& arr, linked_hash_set<Arith::Var>& arith,
                                linked_hash_set<typename T::Var>& t) const {
    m_arr->collectVars(arr, arith, t);
    for (const auto& i : m_indices) {
        i->collectVars(arith);
    }
    m_val->collectVars(t);
}

template <ITheory T>
sexpresso::Sexp ArrayWrite<T>::to_smtlib() const {
    sexpresso::Sexp res;
    res.addChild("store");
    auto outer_arr{m_arr->var()->to_smtlib()};
    res.addChild(outer_arr);
    res.addChild(m_indices.front()->to_smtlib());
    sexpresso::Sexp val{m_val->to_smtlib()};
    for (ulong i = 1; i < m_indices.size(); ++i) {
        sexpresso::Sexp inner_arr;
        inner_arr.addChild("select");
        inner_arr.addChild(outer_arr);
        inner_arr.addChild(m_indices.at(i - 1)->to_smtlib());
        sexpresso::Sexp new_val;
        new_val.addChild("store");
        new_val.addChild(inner_arr);
        new_val.addChild(m_indices.at(i)->to_smtlib());
        res.addChild(val);
        outer_arr = inner_arr;
        val = new_val;
    }
    res.addChild(val);
    return res;
}

template <ITheory T>
ArrayPtr<T> ArrayWrite<T>::subs(const ArraySubs<T>& subs) const {
    return arrays::mkArrayWrite(arr()->subs(subs), m_indices, m_val);
}

template <ITheory T>
bool ArrayRead<T>::CacheEqual::operator()(const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>>& args1,
                                          const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>>& args2) const
    noexcept {
    return args1 == args2;
}

template <ITheory T>
size_t ArrayRead<T>::CacheHash::operator(
)(const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>>& args) const noexcept {
    auto seed{hash_value(std::get<0>(args))};
    boost::hash_combine(seed, std::get<1>(args));
    return seed;
}

template <ITheory T>
ArrayRead<T>::ArrayRead(const ArrayPtr<T>& p_arr, const std::vector<Arith::Expr>& p_indices): m_arr(p_arr), m_indices(p_indices) {}

template <ITheory T>
ArrayPtr<T> ArrayRead<T>::arr() const {
    return m_arr;
}

template <ITheory T>
std::vector<Arith::Expr> ArrayRead<T>::indices() const {
    return m_indices;
}

template <ITheory T>
bool ArrayRead<T>::isTempVar() const {
    return m_arr->var()->isTempVar();
}

template <ITheory T>
bool ArrayRead<T>::isProgVar() const {
    return m_arr->var()->isProgVar();
}

template <ITheory T>
bool ArrayRead<T>::isPostVar() const {
    return m_arr->var()->isPostVar();
}

template <ITheory T>
sexpresso::Sexp ArrayRead<T>::to_smtlib() const {
    sexpresso::Sexp res {m_arr->to_smtlib()};
    for (ulong i = 0; i < m_indices.size(); ++i) {
        sexpresso::Sexp outer;
        outer.addChild("select");
        outer.addChild(res);
        outer.addChild(m_indices.at(i)->to_smtlib());
        res = outer;
    }
    return res;
}

template <ITheory T>
ArrayReadPtr<T> ArrayRead<T>::subs(const ArithSubs& subs) const {
    std::vector<Arith::Expr> indices;
    for (const auto &i: m_indices) {
        indices.emplace_back(i->subs(subs));
    }
    return arrays::mkArrayRead(m_arr->subs(subs), indices);
}

template <ITheory T>
ArrayReadPtr<T> ArrayRead<T>::subs(const ArraySubs<T>& subs) const {
    return arrays::mkArrayRead(m_arr->subs(subs), m_indices);
}

template <ITheory T>
ArrayReadPtr<T> ArrayRead<T>::renameVars(const array_var_map<T>& map) const {
    return arrays::mkArrayRead(m_arr->renameVars(map), m_indices);
}

template <ITheory T>
ArrayReadPtr<T> ArrayRead<T>::renameVars(const typename T::Renaming& map) const {
    std::vector<Arith::Expr> indices;
    if constexpr (std::is_same_v<T, Arith>) {
        for (const auto &i: m_indices) {
            indices.emplace_back(i->renameVars(map));
        }
    } else {
        indices = m_indices;
    }
    return arrays::mkArrayRead(m_arr->renameVars(map), indices);
}

template <ITheory T>
void ArrayRead<T>::collectVars(linked_hash_set<ArrayVarPtr<T>>& arr, linked_hash_set<Arith::Var>& arith, linked_hash_set<typename T::Var>& ts) const {
    m_arr->collectVars(arr, arith, ts);
}

template class ArrayVar<Arith>;
template class ArrayWrite<Arith>;
template class ArrayRead<Arith>;
