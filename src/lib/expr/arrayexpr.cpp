#include "arrayexpr.hpp"

#include <utility>
#include "sexpresso.hpp"
#include "renaming.hpp"
#include "subs.hpp"

template <class T>
VarSet Array<T>::vars() const {
    VarSet res;
    collectVars(res);
    return res;
}

template <class T>
CellSet Array<T>::cells() const {
    CellSet res;
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
ArrayPtr<T> ArrayVar<T>::renameVars(const Renaming& map) const {
    return map.get(var());
}

template <class T>
void ArrayVar<T>::collectVars(VarSet& xs) const {
    xs.insert(var());
}

template <class T>
sexpresso::Sexp ArrayVar<T>::to_smtlib() const {
    return sexpresso::Sexp(getName());
}

template <class T>
ArrayPtr<T> ArrayVar<T>::subs(const Subs& subs) const {
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
bool ArrayVar<T>::isPoly() const {
    return true;
}

template <class T>
unsigned ArrayVar<T>::dim() const {
    return m_dim;
}

template <class T>
void ArrayVar<T>::collectCells(CellSet&) const {}

template <class T>
ArrayVarPtr<T> ArrayVar<T>::dummyConst() {
    return cache.from_cache(0, 0);
}

template <class T>
bool ArrayWrite<T>::CacheEqual::operator()(
    const std::tuple<ArrayPtr<T>, Bools::Expr, typename T::Expr>& args1,
    const std::tuple<ArrayPtr<T>, Bools::Expr, typename T::Expr>& args2) const noexcept {
    return args1 == args2;
}

template <class T>
size_t ArrayWrite<T>::CacheHash::operator()(
    const std::tuple<ArrayPtr<T>, Bools::Expr, typename T::Expr>& args) const noexcept {
    auto seed{hash_value(std::get<0>(args))};
    boost::hash_combine(seed, std::get<1>(args));
    boost::hash_combine(seed, std::get<2>(args));
    return seed;
}

template <class T>
ArrayWrite<T>::ArrayWrite(const ArrayPtr<T>& p_arr, Bools::Expr p_cond,
                          const typename T::Expr& p_val) : m_arr(p_arr), m_cond(std::move(p_cond)), m_val(p_val) {}

template <class T>
ArrayWrite<T>::~ArrayWrite() {
    cache.erase(m_arr, m_cond, m_val);
}

template <class T>
ArrayPtr<T> ArrayWrite<T>::arr() const {
    return m_arr;
}

template <class T>
Bools::Expr ArrayWrite<T>::cond() const {
    return m_cond;
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
ArrayPtr<T> ArrayWrite<T>::renameVars(const Renaming& map) const {
    return arrays::mkArrayWrite(m_arr->renameVars(map), m_cond->renameVars(map), m_val->renameVars(map));
}

template <class T>
void ArrayWrite<T>::collectVars(VarSet& xs) const {
    m_arr->collectVars(xs);
    m_cond->collectVars(xs);
    m_val->collectVars(xs);
    // remove bound variables
    for (size_t i = 0; i < dim(); ++i) {
        xs.erase(arrays::array_idx(i)->var());
    }
}

template <class T>
sexpresso::Sexp ArrayWrite<T>::to_smtlib() const {
    sexpresso::Sexp res;
    if (const auto idx{indices()}) {
        res.addChild("store");
        auto outer_arr{m_arr->var()->to_smtlib()};
        res.addChild(outer_arr);
        res.addChild(idx->front()->to_smtlib());
        sexpresso::Sexp val{m_val->to_smtlib()};
        for (unsigned long i = 1; i < idx->size(); ++i) {
            sexpresso::Sexp inner_arr;
            inner_arr.addChild("select");
            inner_arr.addChild(outer_arr);
            inner_arr.addChild(idx->at(i - 1)->to_smtlib());
            sexpresso::Sexp new_val;
            new_val.addChild("store");
            new_val.addChild(inner_arr);
            new_val.addChild(idx->at(i)->to_smtlib());
            res.addChild(val);
            outer_arr = inner_arr;
            val = new_val;
        }
        res.addChild(val);
    } else {
        res.addChild("lambda");
        std::vector<Arith::Expr> indices;
        sexpresso::Sexp decls;
        for (size_t i = 0; i < dim(); ++i) {
            sexpresso::Sexp decl;
            const auto idx = arrays::array_idx(i);
            indices.emplace_back(idx);
            decl.addChild(idx->var()->getName());
            decl.addChild("Int");
            decls.addChild(decl);
        }
        res.addChild(decls);
        sexpresso::Sexp body;
        body.addChild("ite");
        body.addChild(m_cond->to_smtlib());
        body.addChild(m_val->to_smtlib());
        body.addChild(arrays::mkArrayRead(m_arr, indices)->to_smtlib());
        res.addChild(body);
    }
    return res;
}

template <class T>
ArrayPtr<T> ArrayWrite<T>::subs(const Subs& subs) const {
    auto restricted = subs;
    // remove bound variables
    for (size_t i = 0; i < dim(); ++i) {
        restricted.erase(arrays::array_idx(i)->var());
    }
    return arrays::mkArrayWrite(m_arr->subs(restricted), m_cond->subs(restricted), m_val->subs(restricted));
}

template <class T>
ArrayPtr<T> ArrayWrite<T>::withVar(const ArrayVarPtr<T>& var) const {
    return arrays::mkArrayWrite(m_arr->withVar(var), m_cond, m_val);
}

template <class T>
bool ArrayWrite<T>::isLinear() const {
    return m_arr->isLinear() && m_cond->isLinear() && m_val->isLinear();
}

template <class T>
bool ArrayWrite<T>::isPoly() const {
    return m_arr->isPoly() && m_cond->isPoly() && m_val->isPoly();
}

template <class T>
unsigned ArrayWrite<T>::dim() const {
    return arr()->dim();
}

template <class T>
void ArrayWrite<T>::collectCells(CellSet& res) const {
    m_arr->collectCells(res);
    m_cond->collectCells(res);
    m_val->collectCells(res);
    // remove bound variables
    for (size_t i = 0; i < dim(); ++i) {
        res.erase(arrays::array_idx(i));
    }
}

std::optional<std::vector<Arith::Expr>> arrays::indices(const size_t dim, const Bools::Expr& cond) {
    if (!cond->isConjunction()) {
        return std::nullopt;
    }
    const auto lits = cond->lits();
    if (lits.size() != dim) {
        return std::nullopt;
    }
    const auto& arith_lits = lits.get<Arith::Lit>();
    if (arith_lits.size() != dim) {
        return std::nullopt;
    }
    linked_hash_set<ArithVarPtr> indices;
    for (size_t i = 0; i < dim; ++i) {
        indices.insert(array_idx(i));
    }
    std::vector<Arith::Expr> res;
    for (const auto& idx: indices) {
        auto success = false;
        for (const auto& lit : arith_lits) {
            if (const auto eq = lit->getEquality(idx)) {
                if ((*eq)->hasCellWith([&](const auto& x) {
                    return indices.contains(x);
                })) {
                    return std::nullopt;
                }
                res.emplace_back(*eq);
                success = true;
                break;
            }
        }
        if (!success) {
            return std::nullopt;
        }
    }
    return res;
}

template <class T>
std::optional<std::vector<Arith::Expr>> ArrayWrite<T>::indices() const {
    return arrays::indices(dim(), m_cond);
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
    return renameVars(Renaming::build<Arrays<Arith>>(map));
}

template <class T>
ArrayReadPtr<T> ArrayRead<T>::renameVars(const Renaming& map) const {
    const auto arr = m_arr->renameVars(map);
    std::vector<Arith::Expr> indices;
    for (const auto& i : m_indices) {
        indices.emplace_back(i->renameVars(map));
    }
    return cache.from_cache(arr, indices);
}

template <class T>
ArrayReadPtr<T> ArrayRead<T>::withVar(const ArrayVarPtr<T>& var) const {
    return cache.from_cache(m_arr->withVar(var), m_indices);
}

template <class T>
void ArrayRead<T>::collectVars(VarSet& vars) const {
    m_arr->collectVars(vars);
    for (const auto& i: m_indices) {
        i->collectVars(vars);
    }
}

template <class T>
VarSet ArrayRead<T>::vars() const {
    VarSet res;
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
bool ArrayRead<T>::isPoly() const {
    return m_arr->isPoly() && std::ranges::all_of(m_indices, [](const auto& i) {return i->isPoly().has_value();});
}

template <class T>
bool ArrayRead<T>::isPostCell() const {
    return std::ranges::all_of(vars(), theory::isPostVar);
}

template <class T>
bool ArrayRead<T>::isProgCell() const {
    return std::ranges::all_of(vars(), theory::isProgVar);}

ArrayReadPtr<Arith> arrays::mkArrayRead(const ArrayVarPtr<Arith>& arr, const std::vector<Arith::Expr>& indices) {
    assert(arr->dim() == indices.size());
    return ArrayRead<Arith>::cache.from_cache(arr, indices);
}

Arith::Expr arrays::mkArrayRead(const ArrayPtr<Arith>& arr, const std::vector<Arith::Expr>& indices) {
    assert(arr->dim() == indices.size());
    if (const auto write {arr->isArrayWrite()}; write) {
        Subs subs;
        for (size_t i = 0; i < indices.size(); ++i) {
            subs.put(array_idx(i)->var(), writeConst(indices.at(i)));
        }
        const auto cond = (*write)->cond()->subs(subs);
        if (cond == top()) {
            return (*write)->val();
        }
        if (cond == bot()) {
            return mkArrayRead((*write)->arr(), indices);
        }
    }
    return ArrayRead<Arith>::cache.from_cache(arr, indices);
}

ArrayPtr<Arith> arrays::mkArrayWrite(const ArrayPtr<Arith>& arr, const Bools::Expr& cond, const Arith::Expr& val) {
    if (const auto write {arr->isArrayWrite()}) {
        if (cond == (*write)->cond()) {
            return mkArrayWrite((*write)->arr(), cond, val);
        }
    }
    if (const auto read = val->isVar()) {
        // a[...] := b[j]
        if ((*read)->var() == arr) {
            // a[...] := a[j]
            if (const auto w_indices = indices(arr->dim(), cond)) {
                // a[i] := a[j]
                if (w_indices == (*read)->indices()) {
                    // a[i] := a[i]
                    return arr;
                }
            }
        }
    }
    if (arr->dim() == 0) {
        if (cond != top()) {
            throw std::invalid_argument("conditional array write to scalar");
        }
        return ArrayWrite<Arith>::cache.from_cache(ArrayVar<Arith>::dummyConst(), top(), val);
    }
    return ArrayWrite<Arith>::cache.from_cache(arr, cond, val);
}

ArrayPtr<Arith> arrays::mkArrayWrite(const ArrayPtr<Arith>& arr, const std::vector<Arith::Expr>& indices, const Arith::Expr& val) {
    assert(arr->dim() == indices.size());
    std::vector<Arith::Lit> lits;
    for (size_t i = 0; i < indices.size(); ++i) {
        lits.emplace_back(arith::mkEq(array_idx(i), indices.at(i)));
    }
    return ArrayWrite<Arith>::cache.from_cache(arr, bools::mkAnd(lits), val);
}

ArrayPtr<Arith> arrays::update(const ArrayReadPtr<Arith>& read, const Arith::Expr& val) {
    return mkArrayWrite(read->arr(), read->indices(), val);
}

ArrayPtr<Arith> arrays::writeConst(const Arith::Expr& val) {
    return mkArrayWrite(ArrayVar<Arith>::dummyConst(), top(), val);
}

Arith::Expr arrays::readConst(const ArrayPtr<Arith>& arr) {
    return mkArrayRead(arr, {});
}

ArrayReadPtr<Arith> arrays::readConst(const ArrayVarPtr<Arith>& arr) {
    return mkArrayRead(arr, {});
}

template <class T>
std::ostream& operator<<(std::ostream& s, const ArrayReadPtr<T>& read) {
    if (read->dim() == 0) {
        return s << read->arr();
    }
    s << "(select " << read->arr() << " ";
    for (const auto &i: read->indices()) {
        s << "[" << i << "]";
    }
    return s << ")";
}

template <class T>
std::ostream& operator<<(std::ostream& s, const ArrayPtr<T>& a) {
    if (const auto var {a->isVar()}) {
        return s << (*var)->getName();
    }
    const auto write{*a->isArrayWrite()};
    if (const auto idx = write->indices()) {
        if (a->dim() == 0) {
            s << write->val();
        } else {
            s << "(store ";
            s << write->arr() << " ";
            for (const auto& i : *idx) {
                s << "[" << i << "]";
            }
            s << " " << write->val() << ")";
        }
    } else {
        s << "(lambda ";
        std::vector<Arith::Expr> indices;
        for (size_t i = 0; i < a->dim(); ++i) {
            const auto idx = arrays::array_idx(i);
            indices.emplace_back(idx);
            s << "[" << idx->var()->getName() << "]";
        }
        s << " (ite (" << write->cond() << ") (" << write->val() << ") " << arrays::mkArrayRead(write->arr(), indices) << "))";
    }
    return s;
}

template class Array<Arith>;
template class ArrayVar<Arith>;
template class ArrayWrite<Arith>;
template class ArrayRead<Arith>;
template std::ostream& operator<<(std::ostream&, const ArrayPtr<Arith>&);
template std::ostream& operator<<(std::ostream& s, const ArrayReadPtr<Arith>&);
