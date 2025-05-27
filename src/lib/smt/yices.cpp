#include "yices.hpp"
#include "exprconverter.hpp"

namespace yices {

void init() {
    yices_init();
}

void exit() {
    yices_exit();
}

}

Yices::Yices(Logic logic) : ctx(YicesContext()), config(yices_new_config()) {
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

SmtResult Yices::processResult(smt_status status) {
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

Model Yices::model(const std::optional<const VarSet> &vars) {
    if (ctx.getArithSymbolMap().empty() && ctx.getBoolSymbolMap().empty()) {
        return Model();
    }
    model_t *m = yices_get_model(solver, true);
    Model res;
    const auto add = [&](const Var &x) {
        std::visit(Overload{
            [&](const Arith::Var x) {
                const auto y{ctx.getArithSymbolMap().get(x)};
                if (y) {
                    const auto val{getRealFromModel(m, *y)};
                    assert(mp::denominator(val) == 1);
                    res.template put<Arith>(x, mp::numerator(val));
                }
            },
            [&](const Bools::Var x) {
                const auto y{ctx.getBoolSymbolMap().get(x)};
                if (y) {
                    int32_t val;
                    if (yices_get_bool_value(m, *y, &val) != 0) {
                        throw YicesError();
                    }
                    res.template put<Bools>(x, val);
                }
            }}, x);
    };
    if (vars) {
        for (const auto &x: *vars) {
            add(x);
        }
    } else {
        for (const auto &[x,_]: ctx.getArithSymbolMap()) {
            add(x);
        }
        for (const auto &[x,_]: ctx.getBoolSymbolMap()) {
            add(x);
        }
    }
    yices_free_model(m);
    return res;
}

void Yices::randomize(unsigned seed) {
    // TODO
}

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

Rational Yices::getRealFromModel(model_t *model, type_t symbol) {
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

Arith::Expr convertArith(const term_t t, const YicesContext &ctx);

Bools::Expr convertFormula(const term_t t, const YicesContext &ctx) {
    assert(yices_term_is_bool(t));
    const auto num_children {yices_term_num_children(t)};
    switch (yices_term_constructor(t)) {
        case YICES_BOOL_CONSTANT: {
            assert(num_children == 0);
            int32_t val;
            if (yices_bool_const_value(t, &val) != 0) {
                std::cout << yices_error_string() << std::endl;
                ctx.printStderr(t);
                throw std::logic_error("error from yices");
            }
            return val ? top() : bot();
        }
        case YICES_UNINTERPRETED_TERM: {
            if (num_children == 0) {
                return bools::mkLit(bools::mk(ctx.getBoolVar(t)));
            } else {
                throw std::logic_error("not yet implemented");
            }
        }
        case YICES_OR_TERM: {
            std::vector<Bools::Expr> children;
            for (auto i = 0; i < num_children; ++i) {
                children.emplace_back(convertFormula(yices_term_child(t, i), ctx));
            }
            return bools::mkOr(children);
        }
        case YICES_NOT_TERM: {
            assert(num_children == 1);
            return !convertFormula(yices_term_child(t, 0), ctx);
        }
        case YICES_ARITH_GE_ATOM: {
            assert(num_children == 2);
            return bools::mkLit(arith::mkLeq(convertArith(yices_term_child(t, 0), ctx), convertArith(yices_term_child(t, 1), ctx)));
        }
        case YICES_DISTINCT_TERM: {
            assert(num_children == 2);
            const auto fst {yices_term_child(t, 0)};
            const auto snd {yices_term_child(t, 1)};
            if (yices_term_is_int(fst)) {
                return bools::mkLit(arith::mkNeq(convertArith(fst, ctx), convertArith(snd, ctx)));
            } else {
                return theory::mkNeq(convertFormula(fst, ctx), convertFormula(snd, ctx));
            }
        }
        case YICES_EQ_TERM: {
            assert(num_children == 2);
            const auto fst {yices_term_child(t, 0)};
            const auto snd {yices_term_child(t, 1)};
            if (yices_term_is_int(fst)) {
                return bools::mkLit(arith::mkEq(convertArith(fst, ctx), convertArith(snd, ctx)));
            } else {
                return theory::mkEq(convertFormula(fst, ctx), convertFormula(snd, ctx));
            }
        }
        default: {
            throw std::logic_error("not yet implemented");
        }
    }
}

Arith::Expr convertArith(const term_t t, const YicesContext &ctx) {
    std::cout << "converting ";
    yices_pp_term(stdout, t, 80, 20, 0);
    std::cout << std::endl;
    assert(yices_term_is_int(t));
    const auto num_children{yices_term_num_children(t)};
    switch (yices_term_constructor(t)) {
        case YICES_ARITH_CONSTANT: {
            assert(num_children == 0);
            mpq_t val;
            mpq_init(val);
            if (yices_rational_const_value(t, val) != 0) {
                std::cout << yices_error_string() << std::endl;
                throw std::logic_error("error from yices");
            }
            const auto res {arith::mkConst(ctx.getRational(val))};
            mpq_clear(val);
            return res;
        }
        case YICES_UNINTERPRETED_TERM: {
            if (num_children == 0) {
                return ctx.getArithVar(t);
            } else {
                throw std::logic_error("not yet implemented");
            }
        }
        case YICES_ARITH_SUM: {
            const auto num_children{yices_term_num_children(t)};
            std::vector<Arith::Expr> addends;
            for (auto i = 0; i < num_children; ++i) {
                term_t term;
                mpq_t coeff;
                mpq_init(coeff);
                yices_sum_component(t, i, coeff, &term);
                const auto converted_coeff{arith::mkConst(ctx.getRational(coeff))};
                mpq_clear(coeff);
                if (term == NULL_TERM) {
                    addends.emplace_back(converted_coeff);
                } else {
                    const auto converted{convertArith(term, ctx)};
                    addends.emplace_back(converted_coeff * converted);
                }
            }
            return arith::mkPlus(std::move(addends));
        }
        default: {
            throw std::logic_error("not yet implemented");
        }
    }
}

std::optional<Bools::Expr> Yices::interpolate(const Bools::Expr e) {
    Yices other {QF_LA};
    other.ctx = ctx;
    other.add(e);
    interpolation_context_t ictx;
    ictx.ctx_A = solver;
    ictx.ctx_B = other.solver;
    const auto status {yices_check_context_with_interpolation(&ictx, NULL, 1)};
    std::optional<Bools::Expr> res;
    switch (status) {
        case STATUS_SAT:
            return std::nullopt;
        case STATUS_UNSAT:
            std::cout << "interpolant: " << std::endl;
            yices_pp_term(stderr, ictx.interpolant, 80, 20, 0);
            res = convertFormula(ictx.interpolant, ctx);
            std::cout << "converted: " << std::endl << *res << std::endl;
            break;
        case STATUS_ERROR:
            std::cerr << yices_error_string() << std::endl;
            throw std::logic_error("error from yices");
        default: break;
    }
    return res;
}
