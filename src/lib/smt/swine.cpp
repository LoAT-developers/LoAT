#include "swine.hpp"
#include "exprconverter.hpp"
#include "swinemodel.hpp"

Swine::Swine(const swine::Config& config): solver(config, z3ctx), ctx(solver) {
    auto &s {solver.get_solver()};
    s.set("random_seed", 42u);
    // s.set("rlimit", 10000000u);
    // config.set_rlimit(1000);
}

void Swine::add(const Bools::Expr e) {
    solver.add(ExprConverter<z3::expr, z3::expr, z3::expr_vector, z3::expr_vector>::convert(e, ctx));
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
        return SmtResult::Unsat;
    case z3::unknown:
        return SmtResult::Unknown;
    case z3::sat:
        return SmtResult::Sat;
    }
    throw std::logic_error("unknown result from SMT solver");
}

ModelPtr Swine::model() {
    return cpp::assume_not_null(std::make_shared<SwineModel>(ctx, solver.get_model(), Subs()));
}

void Swine::enableModels() {}

void Swine::resetSolver() {
    solver.reset();
}

std::ostream& Swine::print(std::ostream& os) const {
    return os << solver;
}

void Swine::randomize(const unsigned seed) {
    auto &s {solver.get_solver()};
    s.set("random_seed", seed);
}

Rational Swine::getRealFromModel(const z3::model &model, const z3::expr &symbol) {
    const Rational numerator {Z3_get_numeral_string(
        model.ctx(),
        Z3_get_numerator(
            model.ctx(),
            model.eval(symbol, true)))};
    const Rational denominator {Z3_get_numeral_string(
        model.ctx(),
        Z3_get_denominator(
            model.ctx(),
            model.eval(symbol, true)))};
    return numerator / denominator;
}
