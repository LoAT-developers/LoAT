#pragma once

#include "theory.hpp"
#include "subs.hpp"

class Model {

    friend std::ostream& operator<<(std::ostream &s, const Model &e);

private:

    void print(std::ostream &s) const;

    template <std::size_t I = 0>
    static inline void uniteImpl(Model &res, const Model &that);

    template <size_t I = 0>
    inline void composeBackwardsImpl(const Subs &subs, Model &res) const;

    template <size_t I = 0>
    inline void composeBackwardsImpl(const Renaming &subs, Model &res) const;

    template <size_t I = 0>
    inline bool evalImpl(const Lit &lit) const;

    template <size_t I = 0>
    void projectImpl(Model &model, const VarSet &vars) const;

    template <size_t I = 0>
    void projectImpl(Model &model, const std::function<bool(const Var)> &p) const;

    template <std::size_t I = 0>
    inline void printImpl(const Model &subs, std::ostream &s, bool first = true) const;

public:

    Model();
    Model(const typename TheTheory::Model &m);
    Model unite(const Model &m) const;

    template <ITheory T>
    typename T::Const get(const typename T::Var &var) const {
        const auto map {std::get<linked_hash_map<typename T::Var, typename T::Const>>(m)};
        assert(map.contains(var));
        return map[var];
    }

    Const get(const Var &var) const;

    template <ITheory T>
    void put(const typename T::Var &var, const typename T::Const &val) {
        std::get<linked_hash_map<typename T::Var, typename T::Const>>(m).put(var, val);
    }

    template <ITheory T>
    bool contains(const typename T::Var &var) const {
        return std::get<linked_hash_map<typename T::Var, typename T::Const>>(m).contains(var);
    }

    bool contains(const Var &var) const;

    template <ITheory T>
    typename T::Model& get() {
        return std::get<typename T::Model>(m);
    }

    template <ITheory T>
    const typename T::Model& get() const {
        return std::get<typename T::Model>(m);
    }

    bool eval(const Lit &lit) const;

    template <ITheory T>
    typename T::Const eval(const typename T::Expr &e) const {
        if constexpr (std::is_same_v<T, Bools>) {
            if (e->isAnd()) {
                const auto children {e->getChildren()};
                return std::all_of(children.begin(), children.end(), [&](const auto &c) {
                    return eval<Bools>(c);
                });
            } else if (e->isOr()) {
                const auto children {e->getChildren()};
                return std::any_of(children.begin(), children.end(), [&](const auto &c) {
                    return eval<Bools>(c);
                });
            } else {
                return eval(*e->getTheoryLit());
            }
        } else {
            return e->eval(std::get<typename T::Model>(m));
        }
    }

    Const eval(const Expr &e) const;

    Model composeBackwards(const Subs &subs) const;
    Model composeBackwards(const Renaming &subs) const;
    Bools::Expr syntacticImplicant(const Bools::Expr e) const;
    Model project(const VarSet &vars) const;
    Model project(const std::function<bool(const Var)> &p) const;

private:

    typename TheTheory::Model m{};

};

std::ostream& operator<<(std::ostream &s, const Model &e);
