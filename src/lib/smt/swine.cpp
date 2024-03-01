#include "swine.hpp"
#include "exprtosmt.hpp"

Swine::Swine(swine::Config config): solver(config, z3ctx), ctx(solver) {
    auto &s {solver.get_solver()};
    s.set("random_seed", 42u);
    s.set("seed", 42u);
    s.set("sat.random_seed", 42u);
    s.set("nlsat.seed", 42u);
    // s.set("rlimit", 10000000u);
    // config.set_rlimit(1000);
}

void Swine::add(const Bools::Expr e) {
    solver.add(ExprToSmt<z3::expr>::convert(e, ctx));
}

void Swine::push() {
    solver.push();
}

void Swine::pop() {
    solver.pop();
}

SmtResult Swine::check() {
    switch (solver.check()) {
    case z3::unsat:
        return Unsat;
    case z3::unknown:
        return Unknown;
    case z3::sat:
        return Sat;
    }
    throw std::logic_error("unknown result from SMT solver");
}

Model Swine::model(const std::optional<const VarSet> &vars) {
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

void Swine::enableModels() {}

void Swine::resetSolver() {
    solver.reset();
}

Swine::~Swine() {}

std::ostream& Swine::print(std::ostream& os) const {
    return os << solver;
}

void Swine::randomize(unsigned seed) {
    auto &s {solver.get_solver()};
    s.set("random_seed", seed);
    s.set("seed", seed);
    s.set("sat.random_seed", seed);
    s.set("nlsat.seed", seed);
}

Rational Swine::getRealFromModel(const z3::model &model, const z3::expr &symbol) {
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
