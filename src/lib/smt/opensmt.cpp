#include "opensmt.hpp"
#include "exprconverter.hpp"

OpenSmt::OpenSmt(const bool model) {
    ctx = std::make_unique<OpenSmtContext>(logic);
    if (model) {
        conf.setProduceModels();
    }
    auto str {"ok"};
    conf.setOption(opensmt::SMTConfig::o_produce_inter, opensmt::SMTOption(true), str);
    conf.setSimplifyInterpolant(4);
    solver = std::make_unique<opensmt::MainSolver>(logic, conf, "opensmt");
}

void OpenSmt::add(const Bools::Expr e) {
    solver->addAssertion(ExprConverter<opensmt::PTRef, opensmt::PTRef, std::vector<opensmt::PTRef>, std::vector<opensmt::PTRef>>::convert(e, *ctx));
}

void OpenSmt::push() {
    solver->push();
}

void OpenSmt::pop() {
    solver->pop();
}

SmtResult OpenSmt::check() {
    const auto res {solver->check()};
    if (res == opensmt::s_True) {
        return SmtResult::Sat;
    } else if (res == opensmt::s_False) {
        return SmtResult::Unsat;
    } else if (res == opensmt::s_Error) {
        throw std::logic_error("error from opensmt");
    } else {
        return SmtResult::Unknown;
    }
}

Model OpenSmt::model(const std::optional<const VarSet> &vars) {
    const std::unique_ptr<opensmt::Model> m {solver->getModel()};
    Model res;
    const auto add = [&](const Var &x) {
        std::visit(
            Overload{
                [&](const Arith::Var var) {
                    const auto y {ctx->getArithSymbolMap().get(var)};
                    if (y) {
                        const auto val{getRealFromModel(*m, *y)};
                        assert(mp::denominator(val) == 1);
                        res.template put<Arith>(var, mp::numerator(val));
                    }
                },
                [&](const Bools::Var var) {
                    const auto y{ctx->getBoolSymbolMap().get(var)};
                    if (y) {
                        res.template put<Bools>(var, m->evaluate(*y) == logic.getTerm_true());
                    }
                }},
            x);
    };
    if (vars) {
        for (const auto &x: *vars) {
            add(x);
        }
    } else {
        for (const auto &[x, _] : ctx->getArithSymbolMap()) {
            add(x);
        }
        for (const auto &[x, _] : ctx->getBoolSymbolMap()) {
            add(x);
        }
    }
    return res;
}

void OpenSmt::randomize(unsigned seed) {
    // TODO
}

void OpenSmt::resetSolver() {
    solver = std::make_unique<opensmt::MainSolver>(solver->getLogic(), solver->getConfig(), "opensmt");
}

OpenSmt::~OpenSmt() {}

std::ostream &OpenSmt::print(std::ostream &os) const {
    for (const auto &e: solver->getCurrentAssertions()) {
        os << logic.printTerm(e) << std::endl;
    }
    return os;
}

Arith::Expr OpenSmt::convertArith(const opensmt::PTRef &t) {
    const auto &term {logic.getPterm(t)};
    const auto nargs {term.nargs()};
    if (logic.isConstant(t)) {
        const auto val {logic.getNumConst(t)};
        const auto num {val.get_num()};
        const auto den {val.get_den()};
        assert(num.isInteger());
        assert(den.isInteger());
        return arith::mkConst(Rational(num.get_str(), den.get_str()));
    }
    if (logic.isNumVar(t)) {
        return ctx->getArithVar(t);
    }
    if (logic.isIntMinus(t)) {
        assert(nargs == 2);
        return convertArith(term[0]) - convertArith(term[1]);
    }
    if (logic.isMinusOne(t)) {
        return convertArith(term[0]) - arith::mkConst(1);
    }
    if (logic.isNeg(t)) {
        return -convertArith(term[0]);
    }
    if (logic.isPlus(t)) {
        std::vector<Arith::Expr> args;
        for (unsigned i = 0; i < nargs; ++i) {
            args.emplace_back(convertArith(term[i]));
        }
        return arith::mkPlus(std::move(args));
    }
    if (logic.isTimes(t)) {
        std::vector<Arith::Expr> args;
        for (unsigned i = 0; i < nargs; ++i) {
            args.emplace_back(convertArith(term[i]));
        }
        return arith::mkTimes(std::move(args));
    }
    if (logic.isMod(term.symb())) {
        assert(nargs == 2);
        return arith::mkMod(convertArith(term[0]), convertArith(term[1]));
    }
    throw std::invalid_argument("unknown operator: " + logic.printTerm(t));
};

Bools::Expr OpenSmt::convertFormula(const opensmt::PTRef &t) {
    const auto &term {logic.getPterm(t)};
    const auto nargs {term.nargs()};
    if (t == logic.getTerm_true()) {
        return top();
    }
    if (t == logic.getTerm_false()) {
        return bot();
    }
    if (logic.isBoolAtom(t)) {
        return bools::mkLit(bools::mk(ctx->getBoolVar(t)));
    }
    if (logic.isAnd(t)) {
        std::vector<Bools::Expr> args;
        for (unsigned i = 0; i < nargs; ++i) {
            args.emplace_back(convertFormula(term[i]));
        }
        return bools::mkAnd(std::move(args));
    }
    if (logic.isOr(t)) {
        std::vector<Bools::Expr> args;
        for (unsigned i = 0; i < nargs; ++i) {
            args.emplace_back(convertFormula(term[i]));
        }
        return bools::mkOr(std::move(args));
    }
    if (logic.isNot(t)) {
        return !convertFormula(term[0]);
    }
    if (logic.isIntGeq(t) || logic.isIntGt(t) || logic.isIntLeq(t) || logic.isIntLt(t) || logic.isIntEq(t)) {
        std::vector<Arith::Expr> args;
        for (unsigned i = 0; i < nargs; ++i) {
            args.emplace_back(convertArith(term[i]));
        }
        std::vector<Arith::Lit> lits;
        const auto mk = [&](const auto &x, const auto &y) {
            if (logic.isIntGeq(t)) {
                return arith::mkGeq(x, y);
            }
            if (logic.isIntGt(t)) {
                return arith::mkGt(x, y);
            }
            if (logic.isIntLeq(t)) {
                return arith::mkLeq(x, y);
            }
            if (logic.isIntLt(t)) {
                return arith::mkLeq(x, y);
            }
            if (logic.isIntEq(t)) {
                return arith::mkEq(x, y);
            }
            throw std::invalid_argument("unknown comparator: " + logic.printTerm(t));
        };
        for (size_t i = 0; i < args.size() - 1; ++i) {
            lits.emplace_back(mk(convertArith(term[i]), convertArith(term[i + 1])));
        }
        return bools::mkAndFromLits(lits);
    }
    throw std::invalid_argument("unknown operator: " + logic.printTerm(t));
}

Bools::Expr OpenSmt::interpolate(opensmt::ipartitions_t mask) {
    auto itpContext {solver->getInterpolationContext()};
    std::vector<opensmt::PTRef> itps;
    itpContext->getSingleInterpolant(itps, mask);
    assert(itps.size() == 1);
    return convertFormula(itps[0]);
}

Rational OpenSmt::getRealFromModel(opensmt::Model &model, opensmt::PTRef x) {
    auto val {logic.getNumConst(model.evaluate(x))};
    const auto den {val.get_den()};
    const auto num {val.get_num()};
    assert(den.isInteger());
    assert(num.isInteger());
    return Rational(num.get_str(), den.get_str());
}
