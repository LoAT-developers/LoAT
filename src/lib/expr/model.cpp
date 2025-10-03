#include "model.hpp"

#include <utility>

Model::Model(Subs p_subs): subs(std::move(p_subs)) {}

ModelPtr Model::composeBackwards(const Renaming &subs) const {
    return composeBackwards(Subs(subs));
}

ModelPtr Model::composeBackwards(const Subs &subs) const {
    return withSubs(subs.compose(this->subs));
}

Arith::Const Model::get(const Arith::Var &var) {
    return eval(subs.get<Arith>(var));
}

Bools::Const Model::get(const Bools::Var &var) {
    return eval(subs.get<Bools>(var));
}

Arith::Const Model::get(const ArrayReadPtr<Arith> &read) {
    return getImpl(subs.get(read));
}

bool Model::eval(const Lit& lit) {
    return evalImpl(subs(lit));
}

Bools::Const Model::eval(const Bools::Expr& e) {
    return evalImpl(subs(e));
}

Arith::Const Model::eval(const Arith::Expr& e) {
    return evalImpl(subs.get<Arith>()(e));
}

bool syntacticImplicant(const Bools::Expr& e, Model* m, BoolExprSet &res) {
    if (e->isAnd()) {
        BoolExprSet sub;
        for (const auto &c : e->getChildren()) {
            if (!syntacticImplicant(c, m, sub)) {
                return false;
            }
        }
        res.insert(sub.begin(), sub.end());
        return true;
    }
    if (e->isOr()) {
        for (const auto &c : e->getChildren()) {
            if (syntacticImplicant(c, m, res)) {
                return true;
            }
        }
        return false;
    }
    if (const auto lit = e->getTheoryLit()) {
        return std::visit(
            Overload{
                [&](const Arith::Lit &l) {
                    if (l->isNeq()) {
                        if (const auto lt{arith::mkLt(l->lhs(), arith::mkConst(0))}; m->eval(lt)) {
                            res.insert(bools::mkLit(lt));
                            return true;
                        }
                        if (const auto gt{arith::mkGt(l->lhs(), arith::mkConst(0))}; m->eval(gt)) {
                            res.insert(bools::mkLit(gt));
                            return true;
                        }
                    } else if (m->eval(l)) {
                        res.insert(e);
                        return true;
                    }
                    return false;
                },
                [&](const auto &l) {
                    if (m->eval(l)) {
                        res.insert(e);
                        return true;
                    }
                    return false;
                }},
            *lit);
    }
    throw std::invalid_argument("unknown kind of BoolExpr");
}

Bools::Expr Model::syntacticImplicant(const Bools::Expr& e) {
    assert(eval(e));
    BoolExprSet res;
    ::syntacticImplicant(e, this, res);
    return bools::mkAnd(res);
}

Arith::Const Model::evalImpl(const Arith::Expr &e) {
#if DEBUG
    assert(e->isIntegral());
#endif
    const auto res {evalToRational(e)};
    if (mp::denominator(res) != 1) {
        throw std::invalid_argument(toString(e) + " is not integral");
    }
    return mp::numerator(res);
}

bool Model::contains(const Var& var) const {
    return theory::apply(var, [&](const auto& var) {
        return this->contains(var);
    });
}

void Model::print(std::ostream& s, const VarSet& xs) {
    s << "[";
    auto first {true};
    for (const auto &x: xs) {
        if (first) {
            first = false;
        } else {
            s << ", ";
        }
        print(s, subs.get(x));
    }
    s << "]";
}
