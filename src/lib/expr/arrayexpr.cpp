#include "arrayexpr.hpp"
#include "sexpresso.hpp"
#include "arraysubs.hpp"
#include "renaming.hpp"

template <class T>
bool ArrayVar<T>::CacheEqual::operator()(const std::tuple<int, unsigned>& args1,
                                         const std::tuple<int, unsigned>& args2) const noexcept {
    return args1 == args2;
}

template <class T>
size_t ArrayVar<T>::CacheHash::operator()(const std::tuple<int, unsigned>& args) const noexcept {
    auto seed{std::hash<int>()(std::get<int>(args))};
    boost::hash_combine(seed, std::get<unsigned>(args));
    return seed;
}

template <class T>
ArrayVar<T>::ArrayVar(const int p_idx, const unsigned p_dim) : m_idx(p_idx), m_dim(p_dim) {}

template <class T>
ArrayVar<T>::Self ArrayVar<T>::next(const unsigned p_dim) {
    --last_tmp_idx;
    return arrays::mkVar<T>(last_tmp_idx, p_dim)->var();
}

template <class T>
ArrayVar<T>::Self ArrayVar<T>::nextProgVar(const unsigned p_dim) {
    ++last_prog_idx;
    return arrays::mkVar<T>(last_prog_idx, p_dim)->var();
}

template <class T>
ArrayVar<T>::Self ArrayVar<T>::postVar(const Self& arr) {
    return arrays::mkVar<T>(arr->m_idx + 1, arr->m_dim)->var();
}

template <class T>
std::string ArrayVar<T>::getName() const {
    if (m_idx > 0) {
        return "a" + std::to_string(m_idx);
    }
    return "at" + std::to_string(-m_idx);
}

template <class T>
unsigned ArrayVar<T>::idx() const {
    return m_idx;
}

template <class T>
bool ArrayVar<T>::isTempVar() const {
    return m_idx < 0;
}

template <class T>
bool ArrayVar<T>::isProgVar() const {
    return m_idx > 0 && m_idx % 2 == 1;
}

template <class T>
bool ArrayVar<T>::isPostVar() const {
    return m_idx > 0 && m_idx % 2 == 0;
}

template <class T>
ArrayVar<T>::Self ArrayVar<T>::progVar(const Self& arr) {
    return arrays::mkVar<T>(arr->m_idx - 1, arr->m_dim)->var();
}

template <class T>
ArrayPtr<T> ArrayVar<T>::subs(const ArithSubs&) const {
    return cpp::assume_not_null(this->shared_from_this());
}

template <class T>
unsigned ArrayVar<T>::dim() const {
    return m_dim;
}

template <class T>
std::optional<typename ArrayVar<T>::Self> ArrayVar<T>::isVar() const {
    return cpp::assume_not_null(this->shared_from_this());
}

template <class T>
ArrayVar<T>::Self ArrayVar<T>::var() const {
    return cpp::assume_not_null(this->shared_from_this());
}

template <class T>
std::optional<ArrayWritePtr<T>> ArrayVar<T>::isArrayWrite() const {
    return {};
}

template <class T>
ArrayPtr<T> ArrayVar<T>::renameVars(const arith_var_map&) const {
    return var();
}

template <class T>
ArrayPtr<T> ArrayVar<T>::renameVars(const array_var_map<T>& map) const {
    const auto x{var()};
    const auto it{map.left.find(x)};
    return it == map.left.end() ? x : it->second;
}

template <class T>
ArrayPtr<T> ArrayVar<T>::renameVars(const Renaming& map) const {
    return map.get<Arrays<T>>(var());
}

template <class T>
void ArrayVar<T>::collectVars(linked_hash_set<Self>& xs, linked_hash_set<Arith::Var>&,
                              linked_hash_set<typename T::Var>&) const {
    xs.insert(var());
}

template <class T>
std::vector<Arith::Expr> ArrayVar<T>::indices() const {
    return {};
}

template <class T>
sexpresso::Sexp ArrayVar<T>::to_smtlib() const {
    return sexpresso::Sexp(getName());
}

template <class T>
ArrayPtr<T> ArrayVar<T>::subs(const ArraySubs<T>& subs) const {
    return subs.get(var());
}

template <class T>
bool ArrayWrite<T>::CacheEqual::operator()(
    const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>, typename T::Expr>& args1,
    const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>, typename T::Expr>& args2) const noexcept {
    return args1 == args2;
}

template <class T>
size_t ArrayWrite<T>::CacheHash::operator()(
    const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>, typename T::Expr>& args) const noexcept {
    auto seed{hash_value(std::get<0>(args))};
    boost::hash_combine(seed, std::get<1>(args));
    boost::hash_combine(seed, std::get<2>(args));
    return seed;
}

template <class T>
ArrayWrite<T>::ArrayWrite(const ArrayPtr<T>& p_arr, const std::vector<Arith::Expr>& p_indices,
                          const typename T::Expr& p_val) : m_arr(p_arr), m_indices(p_indices), m_val(p_val) {}

template <class T>
ArrayPtr<T> ArrayWrite<T>::arr() const {
    return m_arr;
}

template <class T>
std::vector<Arith::Expr> ArrayWrite<T>::indices() const {
    return m_indices;
}

template <class T>
T::Expr ArrayWrite<T>::val() const {
    return m_val;
}

template <class T>
ArrayPtr<T> ArrayWrite<T>::subs(const ArithSubs& that) const {
    std::vector<Arith::Expr> indices;
    for (const auto& i : m_indices) {
        indices.emplace_back(i->subs(that));
    }
    return arrays::mkArrayWrite(m_arr, indices, m_val->subs(that));
}

template <class T>
ArrayVarPtr<T> ArrayWrite<T>::var() const {
    return m_arr->var();
}

template <class T>
std::optional<ArrayVarPtr<T>> ArrayWrite<T>::isVar() const {
    return {};
}

template <class T>
std::optional<ArrayWritePtr<T>> ArrayWrite<T>::isArrayWrite() const {
    return cpp::assume_not_null(this->shared_from_this());
}

template <class T>
ArrayPtr<T> ArrayWrite<T>::renameVars(const array_var_map<T>& map) const {
    return arrays::mkArrayWrite(m_arr->renameVars(map), m_indices, m_val);
}

template <class T>
ArrayPtr<T> ArrayWrite<T>::renameVars(const arith_var_map& map) const {
    const auto indices{
        m_indices | std::views::transform([&](const auto& i) {
            return i->renameVars(map);
        })
    };
    return arrays::mkArrayWrite(m_arr->renameVars(map), {indices.begin(), indices.end()}, m_val->renameVars(map));
}

template <class T>
ArrayPtr<T> ArrayWrite<T>::renameVars(const Renaming& map) const {
    const auto indices{
        m_indices | std::views::transform([&](const auto& i) {
            return i->renameVars(map);
        })
    };
    return arrays::mkArrayWrite(m_arr, {indices.begin(), indices.end()}, m_val->renameVars(map));
}

template <class T>
void ArrayWrite<T>::collectVars(linked_hash_set<ArrayVarPtr<T>>& arr, linked_hash_set<Arith::Var>& arith,
                                linked_hash_set<typename T::Var>& t) const {
    m_arr->collectVars(arr, arith, t);
    for (const auto& i : m_indices) {
        i->collectVars(arith);
    }
    m_val->collectVars(t);
}

template <class T>
sexpresso::Sexp ArrayWrite<T>::to_smtlib() const {
    sexpresso::Sexp res;
    res.addChild("store");
    auto outer_arr{m_arr->var()->to_smtlib()};
    res.addChild(outer_arr);
    res.addChild(m_indices.front()->to_smtlib());
    sexpresso::Sexp val{m_val->to_smtlib()};
    for (unsigned long i = 1; i < m_indices.size(); ++i) {
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

template <class T>
ArrayPtr<T> ArrayWrite<T>::subs(const ArraySubs<T>& subs) const {
    return arrays::mkArrayWrite(arr()->subs(subs), m_indices, m_val);
}

template <class T>
bool ArrayRead<T>::CacheEqual::operator()(const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>>& args1,
                                          const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>>& args2) const
    noexcept {
    return args1 == args2;
}

template <class T>
size_t ArrayRead<T>::CacheHash::operator(
)(const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>>& args) const noexcept {
    auto seed{hash_value(std::get<0>(args))};
    boost::hash_combine(seed, std::get<1>(args));
    return seed;
}

template <class T>
ArrayRead<T>::ArrayRead(const ArrayPtr<T>& p_arr, const std::vector<Arith::Expr>& p_indices): m_arr(p_arr), m_indices(p_indices) {}

template <class T>
ArrayPtr<T> ArrayRead<T>::arr() const {
    return m_arr;
}

template <class T>
std::vector<Arith::Expr> ArrayRead<T>::indices() const {
    return m_indices;
}

template <class T>
bool ArrayRead<T>::isTempVar() const {
    return m_arr->var()->isTempVar();
}

template <class T>
bool ArrayRead<T>::isProgVar() const {
    return m_arr->var()->isProgVar();
}

template <class T>
bool ArrayRead<T>::isPostVar() const {
    return m_arr->var()->isPostVar();
}

template <class T>
sexpresso::Sexp ArrayRead<T>::to_smtlib() const {
    sexpresso::Sexp res {m_arr->to_smtlib()};
    for (const auto & i : m_indices) {
        sexpresso::Sexp outer;
        outer.addChild("select");
        outer.addChild(res);
        outer.addChild(i->to_smtlib());
        res = outer;
    }
    return res;
}

template <class T>
ArrayReadPtr<T> ArrayRead<T>::subs(const ArithSubs& subs) const {
    std::vector<Arith::Expr> indices;
    for (const auto &i: m_indices) {
        indices.emplace_back(i->subs(subs));
    }
    return arrays::mkArrayRead(m_arr->subs(subs), indices);
}

template <class T>
ArrayReadPtr<T> ArrayRead<T>::subs(const ArraySubs<T>& subs) const {
    return arrays::mkArrayRead(m_arr->subs(subs), m_indices);
}

template <class T>
ArrayReadPtr<T> ArrayRead<T>::renameVars(const array_var_map<T>& map) const {
    return arrays::mkArrayRead(m_arr->renameVars(map), m_indices);
}

template <class T>
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

template <class T>
ArrayReadPtr<T> ArrayRead<T>::renameVars(const Renaming& map) const {
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

template <class T>
void ArrayRead<T>::collectVars(linked_hash_set<ArrayVarPtr<T>>& arr, linked_hash_set<Arith::Var>& arith, linked_hash_set<typename T::Var>& ts) const {
    m_arr->collectVars(arr, arith, ts);
}

template class ArrayVar<Arith>;
template class ArrayWrite<Arith>;
template class ArrayRead<Arith>;
