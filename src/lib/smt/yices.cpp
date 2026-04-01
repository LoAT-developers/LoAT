#include "yices.hpp"
#include "exprconverter.hpp"
#include "yicesmodel.hpp"

using Converter = ExprConverter<term_t, term_t, std::vector<term_t>, std::vector<term_t>>;

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
    const auto check_mcsat = []() {
        if (!yices_has_mcsat()) {
            throw std::runtime_error("mcsat missing");
        }
    };
    switch (logic) {
    case Logic::QF_LA:
        l = "QF_LIA";
        break;
    case Logic::QF_ALA:
        l = "QF_ALIA";
        break;
    case Logic::QF_NA:
        check_mcsat();
        l = "QF_NIA";
        break;
    case Logic::QF_ANA:
        check_mcsat();
        l = "QF_ANIA";
        break;
    default:
        throw std::invalid_argument("unsupported logic");
    }
    if (yices_default_config_for_logic(config, l.c_str()) == -1) {
        std::cout << yices_error_string() << std::endl;
        throw std::logic_error("error from yices");
    }
    solver = yices_new_context(config);
    yices::check_err();
}

std::pair<SmtResult, BoolExprSet> Yices::check_with_assumptions(const BoolExprSet& set) {
    std::unordered_map<term_t, Bools::Expr> map;
    std::vector<term_t> converted;
    for (const auto& a: set) {
        const auto c = Converter::convert(a, ctx);
        map.emplace(c, a);
        converted.emplace_back(c);
    }
    const auto res = processResult(yices_check_context_with_assumptions(solver, nullptr, converted.size(), converted.data()));
    BoolExprSet core;
    if (res == SmtResult::Unsat) {
        term_vector_t vec;
        yices_init_term_vector(&vec);
        yices_get_unsat_core(solver, &vec);
        yices::check_err();
        for (unsigned i = 0; i < vec.size; i++) {
            core.emplace(map.at(vec.data[i]));
        }
        yices_delete_term_vector(&vec);
    }
    return {res, core};
}

void Yices::add(const Bools::Expr e) {
    if (yices_assert_formula(solver, Converter::convert(e, ctx)) < 0) {
        throw YicesError();
    }
    yices::check_err();
}

void Yices::push() {
    if (yices_context_status(solver) == STATUS_UNSAT) {
        ++pushes_since_unsat;
    } else {
        yices_push(solver);
        yices::check_err();
    }
}

void Yices::pop() {
    if (pushes_since_unsat > 0) {
        --pushes_since_unsat;
    } else {
        yices_pop(solver);
        yices::check_err();
    }
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
    const auto res = processResult(yices_check_context(solver, nullptr));
    yices::check_err();
    return res;
}

ModelPtr Yices::model() {
    auto m {std::shared_ptr<model_t>(yices_get_model(solver, true), &yices_free_model)};
    yices::check_err();
    return cpp::assume_not_null(std::make_shared<YicesModel>(ctx, m, Subs()));
}

void Yices::randomize(unsigned seed) {
    // TODO
}

void Yices::enableModels() {}

void Yices::resetSolver() {
    yices_reset_context(solver);
    pushes_since_unsat = 0;
    yices::check_err();
}

Yices::~Yices() {
    yices_free_config(config);
    yices_free_context(solver);
    yices::check_err();
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
    yices::check_err();
    assert(denom != 0);
    Rational res {num};
    res = res / denom;
    return res;
}
