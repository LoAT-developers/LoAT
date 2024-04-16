#include "cvc5.hpp"
#include "exprtosmt.hpp"

CVC5::CVC5(): solver(), ctx(solver) {
    solver.setOption("seed", std::to_string(seed));
    solver.setLogic("QF_NIRAT");
}

void CVC5::add(const Bools::Expr e) {
    solver.assertFormula(ExprToSmt<cvc5::Term>::convert(e, ctx));
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
        return Sat;
    } else if (res.isUnsat()) {
        return Unsat;
    } else {
        return Unknown;
    }
}

Model CVC5::model(const std::optional<const VarSet> &vars) {
    Model res;
    const auto add = [&](const auto &x, const auto &y) {
        std::visit(
            Overload {
                [&](const Arith::Var var) {
                    const auto val {getRealFromModel(y)};
                    assert(mp::denominator(val) == 1);
                    res.template put<Arith>(var, mp::numerator(val));
                },
                [&](const Bools::Var var) {
                    res.template put<Bools>(var, this->solver.getValue(y).getBooleanValue());
                }
            }, x);
    };
    const auto map = ctx.getSymbolMap();
    if (vars) {
        for (const auto &x: *vars) {
            const auto res {map.get(x)};
            if (res) {
                add(x, *res);
            }
        }
    } else {
        for (const auto &[x, y]: map) {
            add(x, y);
        }
    }
    return res;
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
        const auto val {solver.getValue(symbol)};
        if (val.isIntegerValue()) {
            return Int(val.getIntegerValue());
        } else if (val.isRealValue()) {
            return Rational(val.getRealValue());
        } else {
            throw std::logic_error((std::stringstream() << "CVC5::getRealFromModel: tried to convert " << val << " to real").str());
        }
    }

