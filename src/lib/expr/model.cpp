#include "model.hpp"

Model::Model() {}
Model::Model(const typename TheTheory::Model &m) : m(m) {}

template <std::size_t I>
inline void Model::uniteImpl(Model &res, const Model &that) {
    if constexpr (I < num_theories) {
        auto &r{std::get<I>(res.m)};
        for (const auto &[x, c] : std::get<I>(that.m)) {
            r.put(x, c);
        }
        uniteImpl<I + 1>(res, that);
    }
}

Model Model::unite(const Model &m) const {
    auto res{*this};
    uniteImpl(res, m);
    return res;
}

template <size_t I>
inline void Model::composeBackwardsImpl(const Subs &subs, Model &res) const {
    if constexpr (I < num_theories) {
        using Th = std::tuple_element_t<I, Theories>;
        const auto &substitution{subs.get<Th>()};
        const auto &model{std::get<I>(m)};
        auto &result{res.get<Th>()};
        for (const auto &[key, v] : substitution) {
            result.put(key, eval(v));
        }
        for (const auto &[key, value] : model) {
            if (!result.contains(key)) {
                result.put(key, value);
            }
        }
        composeBackwardsImpl<I + 1>(subs, res);
    }
}

Model Model::composeBackwards(const Renaming &subs) const {
    Model res;
    composeBackwardsImpl(subs, res);
    return res;
}

template <size_t I>
inline void Model::composeBackwardsImpl(const Renaming &subs, Model &res) const {
    if constexpr (I < num_theories) {
        using Th = std::tuple_element_t<I, Theories>;
        const auto &substitution{subs.get<Th>()};
        const auto &model{std::get<I>(m)};
        auto &result{res.get<Th>()};
        for (const auto &[key, v] : substitution) {
            result.put(key, eval(Th::varToExpr(v)));
        }
        for (const auto &[key, value] : model) {
            if (!result.contains(key)) {
                result.put(key, value);
            }
        }
        composeBackwardsImpl<I + 1>(subs, res);
    }
}

Model Model::composeBackwards(const Subs &subs) const {
    Model res;
    composeBackwardsImpl(subs, res);
    return res;
}

template <size_t I>
inline bool Model::evalImpl(const Lit &lit) const {
    return std::visit(Overload{
        [&](const Bools::Lit &lit) {
            return lit->eval(std::get<Bools::Model>(m));
        },
        [&](const Arith::Lit &lit) {
            return lit->eval(std::get<Arith::Model>(m));
        },
        [&](const Arrays<Arith>::Lit &lit) {
            return lit->eval(std::get<Arrays<Arith>::Model>(m), std::get<Arith::Model>(m));
        }
    }, lit);
}

bool Model::eval(const Lit &lit) const {
    return evalImpl<0>(lit);
}

Bools::Const Model::eval(const Bools::Expr &e) const {
    if (e->isAnd()) {
        const auto children{e->getChildren()};
        return std::all_of(children.begin(), children.end(), [&](const auto &c) {
            return eval(c);
        });
    } else if (e->isOr()) {
        const auto children{e->getChildren()};
        return std::any_of(children.begin(), children.end(), [&](const auto &c) {
            return eval(c);
        });
    } else {
        return eval(*e->getTheoryLit());
    }
}

Arith::Const Model::eval(const Arith::Expr &e) const {
    return e->eval(get<Arith>());
}

Arrays<Arith>::Const Model::eval(const Arrays<Arith>::Expr &e) const {
    return e->eval(get<Arrays<Arith>>(), get<Arith>());
}

Const Model::eval(const Expr &e) const {
    return std::visit(
        Overload{
            [&](const auto &e) {
                return Const{eval(e)};
            }},
        e);
}

template <size_t I>
void Model::projectImpl(Model &model, const VarSet &vars) const {
    if constexpr (I < num_theories) {
        using Th = std::tuple_element_t<I, Theories>;
        model.get<Th>().project(vars.get<I>());
        projectImpl<I + 1>(model, vars);
    }
}

Model Model::project(const VarSet &vars) const {
    Model res{*this};
    projectImpl(res, vars);
    return res;
}

template <size_t I>
void Model::projectImpl(Model &model, const std::function<bool(const Var)> &p) const {
    if constexpr (I < num_theories) {
        using Th = std::tuple_element_t<I, Theories>;
        model.get<Th>().project(p);
        projectImpl<I + 1>(model, p);
    }
}

Model Model::project(const std::function<bool(const Var)> &p) const {
    Model res{*this};
    projectImpl(res, p);
    return res;
}

Model Model::erase(const Var &x) const {
    Model res {*this};
    theory::apply(
        x,
        [&](const auto &x) {
            using T = decltype(theory::theory(x));
            std::get<typename T::Model>(res.m).erase(x);
        }
    );
    return res;
}

Const Model::get(const Var &var) const {
    return theory::apply(
        var,
        [&](const auto &x) {
            using T = decltype(theory::theory(x));
            return Const{std::get<typename T::Model>(m).at(x)};
        });
}
bool Model::contains(const Var &var) const {
    return theory::apply(
        var,
        [&](const auto &x) {
            using T = decltype(theory::theory(x));
            return contains<T>(std::get<typename T::Var>(var));
        });
}

bool syntacticImplicant(const Bools::Expr e, const Model &m, BoolExprSet &res) {
    if (e->isAnd()) {
        BoolExprSet sub;
        for (const auto &c : e->getChildren()) {
            if (!syntacticImplicant(c, m, sub)) {
                return false;
            }
        }
        res.insert(sub.begin(), sub.end());
        return true;
    } else if (e->isOr()) {
        for (const auto &c : e->getChildren()) {
            if (syntacticImplicant(c, m, res)) {
                return true;
            }
        }
        return false;
    } else {
        if (const auto lit = e->getTheoryLit()) {
            return std::visit(
                Overload{
                    [&](const Arith::Lit &l) {
                        if (l->isNeq()) {
                            const auto lt{arith::mkLt(l->lhs(), arith::mkConst(0))};
                            if (m.eval(lt)) {
                                res.insert(bools::mkLit(lt));
                                return true;
                            } else {
                                const auto gt{arith::mkGt(l->lhs(), arith::mkConst(0))};
                                if (m.eval(gt)) {
                                    res.insert(bools::mkLit(gt));
                                    return true;
                                }
                            }
                        } else if (m.eval(l)) {
                            res.insert(e);
                            return true;
                        }
                        return false;
                    },
                    [&](const auto &l) {
                        if (m.eval(l)) {
                            res.insert(e);
                            return true;
                        }
                        return false;
                    }},
                *lit);
        } else {
            throw std::invalid_argument("unknown kind of BoolExpr");
        }
    }
}

Bools::Expr Model::syntacticImplicant(const Bools::Expr e) const {
    assert(eval(e));
    BoolExprSet res;
    ::syntacticImplicant(e, *this, res);
    return bools::mkAnd(res);
}

template <std::size_t I>
inline void Model::printImpl(const Model &subs, std::ostream &s, bool first) const {
    if constexpr (I < num_theories) {
        const auto &m{std::get<I>(subs.m)};
        if (!m.empty()) {
            if (first) {
                first = false;
            } else {
                s << " u ";
            }
            s << m;
        }
        if constexpr (I + 1 < num_theories) {
            printImpl<I + 1>(subs, s, first);
        }
    }
}

void Model::print(std::ostream &s) const {
    printImpl(*this, s);
}

std::ostream &operator<<(std::ostream &s, const Model &e) {
    e.print(s);
    return s;
}
