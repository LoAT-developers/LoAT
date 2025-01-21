#include "swine.hpp"
#include "exprconverter.hpp"
#include "config.hpp"

#include <iostream>
#include <fstream>
#include <cstdio>

unsigned Swine::counter {0};

Swine::Swine(swine::Config config): solver(config, z3ctx), printer(config, z3ctx), ctx(solver) {
    auto &s {solver.get_solver()};
    s.set("random_seed", 42u);
    s.set("seed", 42u);
    s.set("sat.random_seed", 42u);
    s.set("nlsat.seed", 42u);
}

void Swine::add(const Bools::Expr e) {
    if (exp < 0 && e->isExponential()) {
        std::cout << e << std::endl;
        exp = level;
    }
    const auto to_add {ExprConverter<z3::expr, z3::expr, z3::expr_vector, z3::expr_vector>::convert(e, ctx)};
    solver.add(to_add);
    printer.add(to_add);
}

void Swine::push() {
    ++level;
    solver.push();
    printer.push();
}

void Swine::pop() {
    --level;
    if (level < exp) {
        exp = -1;
    }
    solver.pop();
    printer.pop();
}

SmtResult Swine::check() {
    std::string name{"./benchmarks/" + Config::Analysis::filename + "_" + std::to_string(counter) + ".smt2"};
    if (exp >= 0) {
        std::ofstream out;
        out.open(name);
        out << printer;
        out.close();
    }
    switch (solver.check()) {
    case z3::unsat:
        if (exp >= 0) {
            if (std::remove(name.c_str())) {
                std::cout << "failed removing " << name << std::endl;
            }
        }
        return SmtResult::Unsat;
    case z3::unknown:
        if (exp >= 0) {
            ++counter;
            std::cout << "wrote " << name << std::endl;
        }
        return SmtResult::Unknown;
    case z3::sat:
    if (exp >= 0) {
            if (std::remove(name.c_str())) {
                std::cout << "failed removing " << name << std::endl;
            }
        }
        return SmtResult::Sat;
    }
    throw std::logic_error("unknown result from SMT solver");
}

Model Swine::model(const std::optional<const VarSet> &vars) {
    const z3::model &m = solver.get_model();
    Model res;
    const auto add = [&](const Var &x) {
        std::visit(
            Overload{
                [&](const Arith::Var var) {
                    const auto y {ctx.getArithSymbolMap().get(var)};
                    if (y) {
                        const auto val{getRealFromModel(m, *y)};
                        assert(mp::denominator(val) == 1);
                        res.template put<Arith>(var, mp::numerator(val));
                    }
                },
                [&](const Bools::Var var) {
                    const auto y{ctx.getBoolSymbolMap().get(var)};
                    if (y) {
                        switch (m.eval(*y).bool_value()) {
                        case Z3_L_FALSE:
                            res.template put<Bools>(var, false);
                            break;
                        default:
                            res.template put<Bools>(var, true);
                            break;
                        }
                    }
                }},
            x);
    };
    if (vars) {
        for (const auto &x: *vars) {
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

void Swine::enableModels() {}

void Swine::resetSolver() {
    level = 0;
    exp = -1;
    solver.reset();
    printer.reset();
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
