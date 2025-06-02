#pragma once

#include "theory.hpp"
#include "subs.hpp"

class Model {

public:

    Model();
    Model(const typename TheTheory::Model &m);

private:

    template<std::size_t I = 0>
    static inline void uniteImpl(Model &res, const Model &that) {
        if constexpr (I < num_theories) {
            auto &r {std::get<I>(res.m)};
            for (const auto &[x,c]: std::get<I>(that.m)) {
                r.put(x,c);
            }
            uniteImpl<I+1>(res, that);
        }
    }

public:

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

private:

    template<std::size_t I = 0>
    inline void toSubsImpl(Subs &subs) const {
        if constexpr (I < num_theories) {
            using T = std::tuple_element_t<I, Theories>;
            auto &substitution {subs.get<T>()};
            const auto &model {std::get<I>(m)};
            for (const auto &[x,_]: model) {
                substitution.put(x, T::constToExpr(model[x]));
            }
            toSubsImpl<I+1>(subs);
        }
    }

public:

    Subs toSubs() const;

private:

    template <size_t I = 0>
    inline bool evalImpl(const Lit &lit) const {
        if constexpr (I < num_theories) {
            if (lit.index() == I) {
                const auto &literal {std::get<I>(lit)};
                const auto &model {std::get<I>(m)};
                return literal->eval(model);
            }
            return evalImpl<I+1>(lit);
        } else {
            throw std::logic_error("unknown theory");
        }
    }

    template <size_t I = 0>
    inline TVL partialEvalImpl(const Lit &lit) const {
        if constexpr (I < num_theories) {
            if (lit.index() == I) {
                const auto &literal {std::get<I>(lit)};
                const auto &model {std::get<I>(m)};
                return literal->partial_eval(model);
            }
            return partialEvalImpl<I+1>(lit);
        } else {
            throw std::logic_error("unknown theory");
        }
    }

public:

    bool eval(const Lit &lit) const;
    TVL partialEval(const Lit &lit) const;

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

private:

    template <size_t I = 0>
    inline void composeBackwardsImpl(const Subs &subs, Model &res) const {
        if constexpr (I < num_theories) {
            using Th = std::tuple_element_t<I, Theories>;
            const auto &substitution {subs.get<Th>()};
            const auto &model {std::get<I>(m)};
            auto &result {res.get<Th>()};
            for (const auto &[key, v]: substitution) {
                result.put(key, eval<Th>(v));
            }
            for (const auto &[key, value]: model) {
                if (!result.contains(key)) {
                    result.put(key, value);
                }
            }
            composeBackwardsImpl<I+1>(subs, res);
        }
    }

    template <size_t I = 0>
    inline void composeBackwardsImpl(const Renaming &subs, Model &res) const {
        if constexpr (I < num_theories) {
            using Th = std::tuple_element_t<I, Theories>;
            const auto &substitution {subs.get<Th>()};
            const auto &model {std::get<I>(m)};
            auto &result {res.get<Th>()};
            for (const auto &[key, v]: substitution) {
                if (contains(v)) {
                    result.put(key, get<Th>(v));
                }
            }
            for (const auto &[key, value]: model) {
                if (!result.contains(key)) {
                    result.put(key, value);
                }
            }
            composeBackwardsImpl<I+1>(subs, res);
        }
    }

public:

    Model composeBackwards(const Subs &subs) const;
    Model composeBackwards(const Renaming &subs) const;
    Bools::Expr syntacticImplicant(const Bools::Expr e) const;
    Bools::Expr specialize(const Bools::Expr e) const;

private:

    template <size_t I = 0>
    void projectImpl(Model &model, const VarSet &vars) const {
        if constexpr (I < num_theories) {
            using Th = std::tuple_element_t<I, Theories>;
            model.get<Th>().project(vars.get<I>());
            projectImpl<I+1>(model, vars);
        }
    }

public:

    Model project(const VarSet &vars) const {
        Model res {*this};
        projectImpl(res, vars);
        return res;
    }

private:

    template <size_t I = 0>
    void projectImpl(Model &model, const std::function<bool(const Var)> &p) const {
        if constexpr (I < num_theories) {
            using Th = std::tuple_element_t<I, Theories>;
            model.get<Th>().project(p);
            projectImpl<I+1>(model, p);
        }
    }

public:

    Model project(const std::function<bool(const Var)> &p) const {
        Model res {*this};
        projectImpl(res, p);
        return res;
    }

private:

    typename TheTheory::Model m{};

};

std::ostream& operator<<(std::ostream &s, const Model &e);
