#include "arrayexpr.hpp"
#include "sexpresso.hpp"
#include "renaming.hpp"

template <class T>
void Array<T>::collectVars(VarSet& res) const {
    collectVars(res.get<ArrayVarPtr<T>>());
}

template <class T>
linked_hash_set<ArrayVarPtr<T>> Array<T>::vars() const {
    linked_hash_set<ArrayVarPtr<T>> res;
    collectVars(res);
    return res;
}

template <class T>
linked_hash_set<ArrayReadPtr<T>> Array<T>::cells() const {
    linked_hash_set<ArrayReadPtr<T>> res;
    collectCells(res);
    return res;
}

template <class T>
bool ArrayVar<T>::CacheEqual::operator()(
    const std::tuple<int, unsigned>& args1,
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
ArrayVar<T>::~ArrayVar() {
    cache.erase(m_idx, m_dim);
}

template <class T>
ArrayVar<T>::Self ArrayVar<T>::next(const unsigned p_dim) {
    --last_tmp_idx;
    return arrays::mkVar<T>(last_tmp_idx, p_dim);
}

template <class T>
ArrayVar<T>::Self ArrayVar<T>::nextProgVar(const unsigned p_dim) {
    last_prog_idx += 2;
    return arrays::mkVar<T>(last_prog_idx, p_dim);
}

template <class T>
ArrayVar<T>::Self ArrayVar<T>::postVar() const {
    return arrays::mkVar<T>(m_idx + 1, m_dim);
}

template <class T>
std::string ArrayVar<T>::getName() const {
    auto prefix {theory::abbrev(theory::type<T>())};
    if (m_dim > 0) {
        prefix += "a";
    }
    if (m_idx > 0) {
        return prefix + std::to_string(m_idx);
    }
    return prefix + "t" + std::to_string(-m_idx);
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
ArrayVar<T>::Self ArrayVar<T>::progVar() const {
    return arrays::mkVar<T>(m_idx - 1, m_dim);
}

template <class T>
std::optional<typename ArrayVar<T>::Self> ArrayVar<T>::isVar() const {
    return var();
}

template <class T>
ArrayVar<T>::Self ArrayVar<T>::var() const {
    return cpp::assume_not_null(std::static_pointer_cast<const ArrayVar>(static_cast<const Array<T>*>(this)->shared_from_this()));
}

template <class T>
std::optional<ArrayWritePtr<T>> ArrayVar<T>::isArrayWrite() const {
    return {};
}

template <class T>
ArrayPtr<T> ArrayVar<T>::renameVars(const array_var_map<T>& map) const {
    const auto x{var()};
    const auto it{map.left.find(x)};
    return it == map.left.end() ? x : it->second;
}

template <class T>
ArrayPtr<T> ArrayVar<T>::renameVars(const Renaming& map) const {
    return map.get(var());
}

template <class T>
void ArrayVar<T>::collectVars(linked_hash_set<Self>& xs) const {
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
ArrayPtr<T> ArrayVar<T>::withVar(const ArrayVarPtr<T>& var) const {
    return var;
}

template <class T>
bool ArrayVar<T>::isLinear() const {
    return true;
}

template <class T>
std::optional<Int> ArrayVar<T>::isPoly() const {
    return 1;
}

template <class T>
unsigned ArrayVar<T>::dim() const {
    return m_dim;
}

template <class T>
void ArrayVar<T>::collectCells(linked_hash_set<cpp::not_null<std::shared_ptr<const ArrayRead<T>>>>& res) const {}

template <class T>
ArrayVarPtr<T> ArrayVar<T>::dummyConst() {
    return cache.from_cache(0, 0);
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
ArrayWrite<T>::~ArrayWrite() {
    cache.erase(m_arr, m_indices, m_val);
}

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
ArrayVarPtr<T> ArrayWrite<T>::var() const {
    return m_arr->var();
}

template <class T>
std::optional<ArrayVarPtr<T>> ArrayWrite<T>::isVar() const {
    return {};
}

template <class T>
std::optional<ArrayWritePtr<T>> ArrayWrite<T>::isArrayWrite() const {
    return cpp::assume_not_null(std::static_pointer_cast<const ArrayWrite>(static_cast<const Array<T>*>(this)->shared_from_this()));
}

template <class T>
ArrayPtr<T> ArrayWrite<T>::renameVars(const array_var_map<T>& map) const {
    return renameVars(Renaming::build<Arrays<T>>(map));
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
void ArrayWrite<T>::collectVars(linked_hash_set<ArrayVarPtr<T>>& arr) const {
    if (dim() > 0) {
        m_arr->collectVars(arr);
        for (const auto& i : m_indices) {
            i->collectVars(arr);
        }
    }
    m_val->collectVars(arr);
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
    std::vector<Arith::Expr> indices;
    for (const auto& i : m_indices) {
        indices.emplace_back(i->subs(subs));
    }
    return arrays::mkArrayWrite(m_arr->subs(subs), indices, m_val->subs(subs));
}

template <class T>
ArrayPtr<T> ArrayWrite<T>::withVar(const ArrayVarPtr<T>& var) const {
    return arrays::mkArrayWrite(m_arr->withVar(var), m_indices, m_val);
}

template <class T>
bool ArrayWrite<T>::isLinear() const {
    return m_arr->isLinear() &&
        std::ranges::all_of(m_indices, [&](const auto& i) {
            return i->isLinear();
        }) &&
        m_val->isLinear();
}

template <class T>
std::optional<Int> ArrayWrite<T>::isPoly() const {
    Int d {0};
    if (const auto da {m_arr->isPoly()}; !da) {
        return {};
    } else {
        d = std::max(d, *da);
    }
    for (const auto &i: m_indices) {
        if (const auto di {i->isPoly()}; !di) {
            return {};
        } else {
            d = std::max(d, *di);
        }
    }
    if (const auto dv {m_val->isPoly()}; !dv) {
        return {};
    } else {
        d = std::max(d, *dv);
    }
    return d;
}

template <class T>
unsigned ArrayWrite<T>::dim() const {
    return arr()->dim();
}

template <class T>
void ArrayWrite<T>::collectCells(linked_hash_set<cpp::not_null<std::shared_ptr<const ArrayRead<T>>>>& res) const {
    m_arr->collectCells(res);
    for (const auto& i : m_indices) {
        i->collectCells(res);
    }
    m_val->collectCells(res);
}

template <class T>
bool ArrayRead<T>::CacheEqual::operator()(
    const std::tuple<ArrayPtr<T>, std::vector<Arith::Expr>>& args1,
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
ArrayRead<T>::~ArrayRead() {
    cache.erase(m_arr, m_indices);
}

template <class T>
ArrayPtr<T> ArrayRead<T>::arr() const {
    return m_arr;
}

template <class T>
ArrayVarPtr<T> ArrayRead<T>::var() const {
    return m_arr->var();
}

template <class T>
unsigned ArrayRead<T>::dim() const {
    return var()->dim();
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
ArrayReadPtr<T> ArrayRead<T>::renameVars(const array_var_map<T>& map) const {
    return cache.from_cache(m_arr->renameVars(map), m_indices);
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
    return cache.from_cache(m_arr->renameVars(map), indices);
}

template <class T>
ArrayReadPtr<T> ArrayRead<T>::withVar(const ArrayVarPtr<T>& var) const {
    return cache.from_cache(m_arr->withVar(var), m_indices);
}

template <class T>
void ArrayRead<T>::collectVars(linked_hash_set<ArrayVarPtr<T>>& arr) const {
    m_arr->collectVars(arr);
    for (const auto& i: m_indices) {
        i->collectVars(arr);
    }
}

template <class T>
void ArrayRead<T>::collectVars(VarSet& vars) const {
    return collectVars(vars.get<Arrays<Arith>::Var>());
}

template <class T>
linked_hash_set<ArrayVarPtr<T>> ArrayRead<T>::vars() const {
    linked_hash_set<ArrayVarPtr<T>> res;
    collectVars(res);
    return res;
}

template <class T>
bool ArrayRead<T>::isLinear() const {
    return m_arr->isLinear() && std::ranges::all_of(m_indices, [&](const Arith::Expr& i) {
        return i->isLinear();
    });
}

template <class T>
std::optional<Int> ArrayRead<T>::isPoly() const {
    Int d {0};
    if (const auto da {m_arr->isPoly()}; !da) {
        return {};
    } else {
        d = std::max(d, *da);
    }
    for (const auto &i: m_indices) {
        if (const auto di {i->isPoly()}; !di) {
            return {};
        } else {
            d = std::max(d, *di);
        }
    }
    return d;
}

template <class T>
bool ArrayRead<T>::isPostCell() const {
    return std::ranges::all_of(vars(), [](const auto& x) {
        return x->isPostVar();
    });
}

template <class T>
bool ArrayRead<T>::isProgCell() const {
    const auto xs {vars()};
    return std::ranges::all_of(xs, [](const auto& x) {
        return x->isProgVar();
    });}

Arith::Expr arrays::mkArrayRead(const ArrayPtr<Arith>& arr, const std::vector<Arith::Expr>& indices) {
    if (const auto write {arr->isArrayWrite()}; write && indices == (*write)->indices()) {
        return (*write)->val();
    }
    return ArrayRead<Arith>::cache.from_cache(arr, indices);
}

ArrayPtr<Arith> arrays::mkArrayWrite(const ArrayPtr<Arith>& arr, const std::vector<Arith::Expr>& indices, const Arith::Expr& val) {
    if (arr->dim() == 0) {
        return ArrayWrite<Arith>::cache.from_cache(ArrayVar<Arith>::dummyConst(), indices, val);
    }
    if (const auto write {arr->isArrayWrite()}; write && indices == (*write)->indices()) {
        return mkArrayWrite((*write)->arr(), indices, val);
    }
    return ArrayWrite<Arith>::cache.from_cache(arr, indices, val);
}

ArrayPtr<Arith> arrays::update(const ArrayReadPtr<Arith>& read, const Arith::Expr& val) {
    return mkArrayWrite(read->arr(), read->indices(), val);
}

ArrayPtr<Arith> arrays::writeConst(const ArrayPtr<Arith>& arr, const Arith::Expr& val) {
    assert(arr->dim() == 0);
    return mkArrayWrite(arr, {}, val);
}

Arith::Expr arrays::readConst(const ArrayPtr<Arith>& arr) {
    assert(arr->dim() == 0);
    return mkArrayRead(arr, {});
}

ArrayReadPtr<Arith> arrays::readConst(const ArrayVarPtr<Arith>& arr) {
    return ArrayRead<Arith>::cache.from_cache(arr, {});
}

template class Array<Arith>;
template class ArrayVar<Arith>;
template class ArrayWrite<Arith>;
template class ArrayRead<Arith>;
