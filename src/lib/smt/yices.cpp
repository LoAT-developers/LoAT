#include "yices.hpp"
#include "exprconverter.hpp"
#include "yicesmodel.hpp"

namespace yices {

void init() {
    yices_init();
}

void exit() {
    yices_exit();
}

}

Yices::Yices(const Logic logic): ctx(YicesContext()), config(yices_new_config()) {
    std::string l;
    switch (logic) {
    case QF_LA:
        l = "QF_LIA";
        break;
    case QF_NA:
        if (!yices_has_mcsat()) {
            throw std::runtime_error("mcsat missing");
        }
        l = "QF_NIA";
        break;
    default:
        throw std::invalid_argument("unsupported logic");
    }
    if (yices_default_config_for_logic(config, l.c_str()) == -1) {
        std::cout << yices_error_string() << std::endl;
        throw std::logic_error("error from yices");
    }
    solver = yices_new_context(config);
}

void Yices::add(const Bools::Expr e) {
    if (yices_assert_formula(solver, ExprConverter<term_t, term_t, std::vector<term_t>, std::vector<term_t>>::convert(e, ctx)) < 0) {
        throw YicesError();
    }
}

void Yices::push() {
    yices_push(solver);
}

void Yices::pop() {
    yices_pop(solver);
}

SmtResult Yices::processResult(const smt_status status) {
    switch (status) {
    case STATUS_SAT:
        return SmtResult::Sat;
    case STATUS_UNSAT:
        return SmtResult::Unsat;
    case STATUS_ERROR: {
        std::cerr << yices_error_string() << std::endl;
        throw std::logic_error("error from yices");
    }
    default:
        return SmtResult::Unknown;
    }
}

SmtResult Yices::check() {
    return processResult(yices_check_context(solver, nullptr));
}

ModelPtr Yices::model() {
    auto m {std::shared_ptr<model_t>(yices_get_model(solver, true), &yices_free_model)};
    return cpp::assume_not_null(std::make_shared<YicesModel>(ctx, m, Subs()));
}

void Yices::randomize(unsigned seed) {
    // TODO
}

void Yices::enableModels() {}

void Yices::resetSolver() {
    yices_reset_context(solver);
}

Yices::~Yices() {
    yices_free_config(config);
    yices_free_context(solver);
}

std::ostream& Yices::print(std::ostream& os) const {
    throw std::invalid_argument("print not supported by yices");
}

Rational Yices::getRealFromModel(model_t *model, const type_t symbol) {
    int64_t num;
    uint64_t denom;
    if (yices_get_rational64_value(model, symbol, &num, &denom) != NO_ERROR) {
        std::cerr << yices_error_string() << std::endl;
        throw std::logic_error("error during conversion of model");
    }
    assert(denom != 0);
    Rational res {num};
    res = res / denom;
    return res;
}
