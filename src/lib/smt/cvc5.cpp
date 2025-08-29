#include "cvc5.hpp"
#include "exprconverter.hpp"
#include "config.hpp"

CVC5::CVC5(): solver(), ctx(solver) {
    solver.setOption("seed", std::to_string(seed));
    solver.setLogic("QF_NIRA");
    solver.setOption("produce-interpolants", "true");
}

void CVC5::add(const Bools::Expr e) {
    solver.assertFormula(ExprConverter<cvc5::Term, cvc5::Term, std::vector<cvc5::Term>, std::vector<cvc5::Term>>::convert(e, ctx));
    solver.assertFormula(ctx.clearRefinement());
}

void CVC5::push() {
    solver.push();
}

void CVC5::pop() {
    solver.pop();
}

SmtResult CVC5::check() {
    const auto res {solver.checkSat()};
    if (res.isSat()) {
        return SmtResult::Sat;
    } else if (res.isUnsat()) {
        return SmtResult::Unsat;
    } else {
        return SmtResult::Unknown;
    }
}

Model CVC5::model(const std::optional<const VarSet> &vars) {
    Model res;
    const auto add = [&](const Var &x) {
        std::visit(
            Overload{
                [&](const Arith::Var var) {
                    const auto y{ctx.getArithSymbolMap().get(var)};
                    if (y) {
                        const auto val{getRealFromModel(*y)};
                        assert(mp::denominator(val) == 1);
                        res.template put<Arith>(var, mp::numerator(val));
                    }
                },
                [&](const Bools::Var var) {
                    const auto y{ctx.getBoolSymbolMap().get(var)};
                    if (y) {
                        res.template put<Bools>(var, this->solver.getValue(*y).getBooleanValue());
                    }
                }},
            x);
    };
    if (vars) {
        for (const auto &x : *vars) {
            add(x);
        }
    } else {
        for (const auto &[x, _] : ctx.getArithSymbolMap()) {
            add(x);
        }
        for (const auto &[x, _] : ctx.getBoolSymbolMap()) {
            add(x);
        }
    }
    return res;
}

Arith::Expr convertArith(const cvc5::Term &t, const CVC5Context &ctx);

const std::vector<Arith::Expr> arith_args(const cvc5::Term &t, const CVC5Context &ctx) {
    std::vector<Arith::Expr> args;
    for (size_t i = 0; i < t.getNumChildren(); ++i) {
        args.push_back(convertArith(t[i], ctx));
    }
    return args;
};

Bools::Expr convertFormula(const cvc5::Term &t, const CVC5Context &ctx) {
    if (t.isBooleanValue()) {
        if (t.getBooleanValue()) {
            return top();
        } else {
            return bot();
        }
    }
    const auto bool_args = [&]() {
        std::vector<Bools::Expr> args;
        for (size_t i = 0; i < t.getNumChildren(); ++i) {
            args.push_back(convertFormula(t[i], ctx));
        }
        return args;
    };
    const auto chain_arith = [&](const std::function<Arith::Lit(const Arith::Expr &, const Arith::Expr &)> &f) {
        const auto aa{arith_args(t, ctx)};
        std::vector<Arith::Lit> lits;
        for (size_t i = 0; i < aa.size() - 1; ++i) {
            lits.push_back(f(aa[i], aa[i + 1]));
        }
        return bools::mkAndFromLits(lits);
    };
    switch (t.getKind()) {
        case cvc5::Kind::CONSTANT: {
            return bools::mkLit(bools::mk(ctx.getBoolVar(t)));
        }
        case cvc5::Kind::NOT: {
            const auto ba {bool_args()};
            assert(ba.size() == 1);
            return !ba[0];
        }
        case cvc5::Kind::AND: return bools::mkAnd(bool_args());
        case cvc5::Kind::OR: return bools::mkOr(bool_args());
        case cvc5::Kind::IMPLIES: {
            auto ba {bool_args()};
            for (size_t i = 0; i < ba.size() - 1; ++i) {
                ba[i] = !ba[i];
            }
            return bools::mkOr(ba);
        }
        case cvc5::Kind::EQUAL: {
            const auto sort {t[0].getSort()};
            if (sort.isBoolean()) {
                auto ba {bool_args()};
                std::vector<Bools::Expr> eqs;
                for (size_t i = 0; i < ba.size() - 1; ++i) {
                    eqs.push_back(theory::mkEq(ba[i], ba[i+1]));
                }
                return bools::mkAnd(eqs);
            } else if (sort.isInteger()) {
                return chain_arith(arith::mkEq);
            } else {
                throw std::invalid_argument("unsupported sort " + toString(sort));
            }
        }
        case cvc5::Kind::DISTINCT: {
            const auto sort {t[0].getSort()};
            std::vector<Bools::Expr> neqs;
            if (sort.isBoolean()) {
                const auto ba {bool_args()};
                for (size_t i = 0; i < ba.size(); ++i) {
                    for (size_t j = i + 1; j < ba.size(); ++j) {
                        neqs.push_back(theory::mkNeq(ba[i], ba[j]));
                    }
                }
                return bools::mkAnd(neqs);
            } else if (sort.isInteger()) {
                const auto aa {arith_args(t, ctx)};
                for (size_t i = 0; i < aa.size(); ++i) {
                    for (size_t j = i + 1; j < aa.size(); ++j) {
                        neqs.push_back(theory::mkNeq(aa[i], aa[j]));
                    }
                }
            } else {
                throw std::invalid_argument("unsupported sort " + toString(sort));
            }
            return bools::mkAnd(neqs);
        }
        case cvc5::Kind::LT: return chain_arith(arith::mkLt);
        case cvc5::Kind::LEQ: return chain_arith(arith::mkLeq);
        case cvc5::Kind::GT: return chain_arith(arith::mkGt);
        case cvc5::Kind::GEQ: return chain_arith(arith::mkGeq);
        case cvc5::Kind::DIVISIBLE: {
            const auto aa {arith_args(t, ctx)};
            assert(aa.size() == 1);
            const auto idx {convertArith(t.getOp()[0], ctx)};
            return bools::mkLit(arith::mkEq(arith::mkMod(aa[0], idx), arith::mkConst(0)));
        }
        default: throw std::invalid_argument("unsupported operator " + toString(t.getOp()));
    }
}

Arith::Expr convertArith(const cvc5::Term &t, const CVC5Context &ctx) {
    if (t.isIntegerValue()) {
        return arith::mkConst(Int(t.getIntegerValue()));
    } else if (t.getKind() == cvc5::Kind::CONSTANT) {
        return ctx.getArithVar(t);
    }
    auto args {arith_args(t, ctx)};
    switch (t.getKind()) {
        case cvc5::Kind::ADD: return arith::mkPlus(std::move(args));
        case cvc5::Kind::SUB: {
            assert(args.size() == 2);
            return args[0] - args[1];
        }
        case cvc5::Kind::MULT: return arith::mkTimes(std::move(args));
        case cvc5::Kind::NEG: {
            assert(args.size() == 1);
            return -args[0];
        }
        case cvc5::Kind::POW2: {
            assert(args.size() == 1);
            return arith::mkConst(2) ^ args[0];
        }
        case cvc5::Kind::POW: {
            assert(args.size() == 2);
            return args[0] ^ args[1];
        }
        default: throw std::invalid_argument("unsupported operator " + toString(t.getOp()));
    }
}

void CVC5::enableModels() {
    solver.setOption("produce-models", "true");
}

void CVC5::resetSolver() {
    solver.resetAssertions();
}

CVC5::~CVC5() {}

std::ostream& CVC5::print(std::ostream& os) const {
    for (const auto &t: solver.getAssertions()) {
        os << t << std::endl;
    }
    return os;
}

void CVC5::randomize(unsigned seed) {
    // TODO
}

Rational CVC5::getRealFromModel(const cvc5::Term &symbol) {
    const auto val{solver.getValue(symbol)};
    if (val.isIntegerValue()) {
        return Int(val.getIntegerValue());
    } else if (val.isRealValue()) {
        return Rational(val.getRealValue());
    } else {
        throw std::logic_error((std::stringstream() << "CVC5::getRealFromModel: tried to convert " << val << " to real").str());
    }
}

std::optional<Bools::Expr> CVC5::interpolate(const BoolExprSet& conclusion) {
    std::cout << "conclusion: " << bools::mkAnd(conclusion) << std::endl;
    const auto res {solver.getInterpolant(ExprConverter<cvc5::Term, cvc5::Term, std::vector<cvc5::Term>,
    std::vector<cvc5::Term>>::convert(!bools::mkAnd(conclusion), ctx))};
    if (res.isNull()) {
        return std::nullopt;
    } else {
        std::cout << "raw interpolant: " << res << std::endl;
        return !convertFormula(res, ctx);
    }
}
