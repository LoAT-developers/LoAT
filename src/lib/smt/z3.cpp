#include "z3.hpp"
#include "exprtosmt.hpp"
#include "variantset.hpp"

void Z3::add(const BExpr e) {
    solver.add(ExprToSmt<z3::expr>::convert(e, ctx));
}

void Z3::push() {
    solver.push();
}

void Z3::pop() {
    solver.pop();
}

SmtResult Z3::check() {
    switch (solver.check()) {
    case z3::unsat: return Unsat;
    case z3::unknown: return Unknown;
    case z3::sat: return Sat;
    }
    throw std::logic_error("unknown result from SMT solver");
}

Model Z3::model(const std::optional<const VarSet> &vars) {
    const z3::model &m = solver.get_model();
    Model res;
    const auto add = [&](const auto &x, const auto &y) {
        std::visit(
            Overload {
                [&](const Arith::Var var) {
                    const auto val {getRealFromModel(m, y)};
                    assert(mp::denominator(val) == 1);
                    res.template put<Arith>(var, mp::numerator(val));
                },
                [&](const Bools::Var var) {
                    switch (m.eval(y).bool_value()) {
                    case Z3_L_FALSE:
                        res.template put<Bools>(var, false);
                        break;
                    case Z3_L_TRUE:
                        res.template put<Bools>(var, true);
                        break;
                    default: break;
                    }
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

void Z3::enableModels() {
    solver.set("model", true);
}

void Z3::resetSolver() {
    solver.reset();
}

Z3::~Z3() {}

std::ostream& Z3::print(std::ostream& os) const {
    return os << solver;
}

void Z3::randomize(unsigned seed) {
    solver.set("random_seed", seed);
    solver.set("sat.random_seed", seed);
    solver.set("seed", seed);
    solver.set("nlsat.seed", seed);
}

Z3::Z3(): ctx(z3Ctx), solver(z3Ctx) {
    solver.set("random_seed", 42u);
    solver.set("sat.random_seed", 42u);
    solver.set("seed", 42u);
    solver.set("nlsat.seed", 42u);
    solver.set("rlimit", 10000000u);
}

Rational Z3::getRealFromModel(const z3::model &model, const z3::expr &symbol) {
    Rational numerator {Z3_get_numeral_string(
        model.ctx(),
        Z3_get_numerator(
            model.ctx(),
            model.eval(symbol, true)))};
    Rational denominator {Z3_get_numeral_string(
        model.ctx(),
        Z3_get_denominator(
            model.ctx(),
            model.eval(symbol, true)))};
    return numerator / denominator;
}
