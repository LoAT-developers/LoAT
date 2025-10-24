#include "model.hpp"

#include <utility>

Model::Model(Subs p_subs): subs(std::move(p_subs)) {}

ModelPtr Model::composeBackwards(const Renaming &subs) const {
    return composeBackwards(Subs(subs));
}

ModelPtr Model::composeBackwards(const Subs &subs) const {
    return withSubs(subs.compose(this->subs));
}

Arith::Const Model::get(const ArithVarPtr &var) {
    return eval(var);
}

Bools::Const Model::get(const Bools::Var &var) {
    return eval(bools::mk(var));
}

void Model::put(const ArithVarPtr& x, const Arith::Const& c) {
    const auto var {x->var()};
    const auto old {subs.get(var)};
    subs.put(var, arrays::mkArrayWrite(old, x->indices(), arith::mkConst(c)));
}

bool Model::eval(const Lit& lit) {
    return eval(bools::mkLit(lit));
}

Bools::Const Model::eval(const Bools::Expr& e) {
    return evalImpl(e->subs(subs));
}

Arith::Const Model::eval(const Arith::Expr& e) {
    return evalImpl(e->subs(subs.get<Arrays<Arith>>()));
}

Arith::Const Model::eval(const ArrayReadPtr<Arith>& e) {
    return evalImpl(e->subs(subs.get<Arrays<Arith>>()));
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
                        if (const auto lt{arith::mkLt(l->lhs(), arith::zero())}; m->eval(lt)) {
                            res.insert(bools::mkLit(lt));
                            return true;
                        }
                        if (const auto gt{arith::mkGt(l->lhs(), arith::zero())}; m->eval(gt)) {
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

Rational Model::evalToRational(const Arith::Expr& e) {
    return evalToRationalImpl(e->subs(subs.get<Arrays<Arith>>()));
}

Arith::Const Model::evalImpl(const Arith::Expr &e) {
    assert(e->isIntegral());
    const auto res {evalToRationalImpl(e)};
    if (mp::denominator(res) != 1) {
        throw std::invalid_argument(toString(e) + " is not integral");
    }
    return mp::numerator(res);
}

std::string Model::toString(const VarSet& xs) {
    std::stringstream s;
    s << "[";
    auto first {true};
    for (const auto& x : xs) {
        theory::apply(
            x,
            [&](const auto& x) {
                if (first) {
                    first = false;
                } else {
                    s << ", ";
                }
                s << x << "=" << toString(subs.get(x));
            });
    }
    s << "]";
    return s.str();
}
