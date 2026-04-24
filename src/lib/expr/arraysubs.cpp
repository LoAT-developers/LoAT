#include "arraysubs.hpp"

#include "subs.hpp"
#include "variantset.hpp"

template <class T>
ArraySubs<T>::ArraySubs(const linked_hash_map<Var, Expr>& map) : map(map) {}

template <class T>
ArraySubs<T>::ArraySubs(std::initializer_list<std::pair<const Var, Expr>> init) : map(init) {}

template <class T>
ArraySubs<T>::Expr ArraySubs<T>::get(const Var& x) const {
    return map.get(x).value_or(x);
}

template <class T>
void ArraySubs<T>::put(const Var& x, const Expr& e) {
    map.put(x, e);
}

template <class T>
ArraySubs<T>::const_iterator ArraySubs<T>::begin() const {
    return map.begin();
}

template <class T>
ArraySubs<T>::const_iterator ArraySubs<T>::end() const {
    return map.end();
}

template <class T>
bool ArraySubs<T>::contains(const Var& x) const {
    return map.contains(x);
}

template <class T>
bool ArraySubs<T>::empty() const {
    return map.empty();
}

template <class T>
unsigned int ArraySubs<T>::size() const {
    return map.size();
}

template <class T>
size_t ArraySubs<T>::erase(const Var& x) {
    return map.erase(x);
}

template <class T>
ArraySubs<T> ArraySubs<T>::compose(const Self& that) const {
    Self res;
    for (const auto& [key,val] : map) {
        res.put(key, val->subs(Subs::build<Arrays<T>>(that)));
    }
    for (const auto& [key,val] : that) {
        if (!contains(key)) {
            res.put(key, val);
        }
    }
    return res;
}

template <class T>
ArraySubs<T> ArraySubs<T>::concat(const Subs& that) const {
    Self res;
    for (const auto& [key,val] : map) {
        res.put(key, val->subs(that));
    }
    return res;
}

template <class T>
ArraySubs<T> ArraySubs<T>::concat(const Renaming& that) const {
    Self res;
    for (const auto& [key,val] : map) {
        res.put(key, val->renameVars(that));
    }
    return res;
}

template <class T>
ArraySubs<T> ArraySubs<T>::project(const linked_hash_set<Var>& vars) const {
    auto m{map};
    m.project(vars);
    return ArraySubs(m);
}

template <class T>
ArraySubs<T> ArraySubs<T>::project(const std::function<bool(Var)>& keep) const {
    auto m{map};
    m.project(keep);
    return ArraySubs(m);
}

template <class T>
bool ArraySubs<T>::changes(const Var& x) const {
    const auto opt{map.get(x)};
    return opt && x != *opt;
}

template <class T>
void ArraySubs<T>::collectCoDomainCells(CellSet& res) const {
    for (const auto& [_,v] : map) {
        v->collectCells(res);
    }
}

template <class T>
bool ArraySubs<T>::isLinear() {
    return false;
}

template <class T>
bool ArraySubs<T>::isPoly() {
    return false;
}

template <class T>
void ArraySubs<T>::collectCoDomainVars(VarSet& vars) const {
    for (const auto& [_,v] : map) {
        v->collectVars(vars);
    }
}

template <class T>
void ArraySubs<T>::collectVars(VarSet& vars) const {
    for (const auto& [k,v] : map) {
        vars.insert(k);
        v->collectVars(vars);
    }
}

template <class T>
linked_hash_set<typename ArraySubs<T>::Var> ArraySubs<T>::domain() const {
    linked_hash_set<Var> res;
    for (const auto& [k,v] : map) {
        res.insert(k);
    }
    return res;
}

template <class T>
VarSet ArraySubs<T>::coDomainVars() const {
    VarSet vars;
    collectCoDomainVars(vars);
    return vars;
}

template <class T>
size_t ArraySubs<T>::hash() const {
    return boost::hash_unordered_range(map.begin(), map.end());
}

template <class T>
bool operator==(const ArraySubs<T>& m1, const ArraySubs<T>& m2) {
    return m1.map == m2.map;
}

template class ArraySubs<Arith>;
template bool operator==(const ArraySubs<Arith>&, const ArraySubs<Arith>&);
