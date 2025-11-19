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
    return eval(lit, subs);
}

bool Model::eval(const Lit& lit, const Subs& subs) {
    return theory::apply(
        lit,
        [&](const Bools::Lit& lit) {
            const auto var {lit->getBoolVar()};
            const auto substituted {subs.get(var)};
            const auto res = substituted->isTheoryLit() ? evalImpl(substituted) : eval(substituted, Subs());
            return lit->isNegated() ? !res : res;
        },
        [&](const Arith::Lit& lit) {
            const auto lhs {eval(lit->lhs(), subs)};
            if (lit->isGt()) {
                return lhs > 0;
            }
            if (lit->isEq()) {
                return lhs == 0;
            }
            assert(lit->isNeq());
            return lhs != 0;
        },
        [&](const Arrays<Arith>::Lit& lit) {
            // TODO fix
            return evalImpl(lit->subs(subs));
        });
}

Bools::Const Model::eval(const Bools::Expr& e) {
    return eval(e, subs);
}

Bools::Const Model::eval(const Bools::Expr& e, const Subs& subs) {
    return e->apply<Bools::Const>(
        [&] {
            return std::ranges::all_of(e->getChildren(), [&](const auto& c) {
                return eval(c, subs);
            });
        }, [&] {
            return std::ranges::any_of(e->getChildren(), [&](const auto& c) {
                return eval(c, subs);
            });
        }, [&](const Lit& lit) {
            return eval(lit, subs);
        }
    );
}

Arith::Const Model::eval(const Arith::Expr& e, const Subs& subs) {
    const auto res {evalToRational(e, subs)};
    assert(mp::denominator(res) == 1);
    return mp::numerator(res);
}

Arith::Const Model::eval(const Arith::Expr& e) {
    return eval(e, subs);
}

Rational Model::evalToRational(const Arith::Expr& e, const Subs& subs) {
    return e->apply<Rational>(
        [&](const ArithConstPtr& c) -> Rational {
            return c->getValue();
        }, [&](const ArithVarPtr& x) -> Rational {
            const auto substituted{x->subs(subs)};
            return substituted->isVar() ? evalToRationalImpl(substituted) : evalToRational(substituted, Subs());
        }, [&](const ArithAddPtr& add) -> Rational {
            Rational res{0};
            for (const auto& arg : add->getArgs()) {
                res += evalToRational(arg, subs);
            }
            return res;
        }, [&](const ArithMultPtr& mul) -> Rational {
            Rational res{1};
            for (const auto& arg : mul->getArgs()) {
                res *= evalToRational(arg, subs);
            }
            return res;
        }, [&](const ArithModPtr& mod) -> Rational {
            const auto lhs {evalToRational(mod->getLhs(), subs)};
            const auto rhs {evalToRational(mod->getRhs(), subs)};
            assert(mp::denominator(lhs) == 1);
            assert(mp::denominator(rhs) == 1);
            const Int x {mp::numerator(lhs)};
            const Int y {mp::numerator(rhs)};
            const Int x_abs {mp::abs(x)};
            const Int y_abs {mp::abs(y)};
            Rational mod_res {x_abs % y_abs};
            if (mod_res == 0 || x >= 0) {
                return mod_res;
            }
            return Rational(y_abs) - mod_res;
        }, [&](const ArithExpPtr& exp) -> Rational {
            const auto base {evalToRational(exp->getBase(), subs)};
            const auto e {evalToRational(exp->getExponent(), subs)};
            assert(mp::denominator(base) == 1);
            assert(mp::denominator(e) == 1);
            return mp::pow(mp::numerator(base), mp::numerator(e).convert_to<long long>());
        });
}

Arith::Const Model::eval(const ArrayReadPtr<Arith>& e) {
    return eval(e, subs);
}

Arith::Const Model::eval(const ArrayReadPtr<Arith>& e, const Subs& subs) {
    return evalImpl(e->subs(subs));
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
    if (!eval(e)) {
        std::cerr << "syntactic implicant failed; model:" << std::endl;
        std::cerr << this->toString(e->vars()) << std::endl;
        std::cerr << "formula: " << e << std::endl;
        std::cerr << "violated literals:" << std::endl;
        for (const auto& l: e->lits()) {
            if (!eval(l)) {
                std::cerr << l << std::endl;
            }
        }
        throw std::invalid_argument("syntacitc implicant failed");
    }
    BoolExprSet res;
    ::syntacticImplicant(e, this, res);
    return bools::mkAnd(res);
}

Rational Model::evalToRational(const Arith::Expr& e) {
    return evalToRational(e, subs);
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
