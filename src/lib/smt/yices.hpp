#pragma once

#include <poly/algebraic_number.h>
#include <yices.h>
#include <future>
#include <stdexcept>

#include "smt.hpp"
#include "yicescontext.hpp"
#include "exprtosmt.hpp"

namespace yices {

extern void init();

extern void exit();

}

template<ITheory... Th>
class Yices : public Smt<Th...> {

    using TheTheory = Theory<Th...>;
    using BoolExpr = BExpr<Th...>;
    using BoolExprSet = BoolExpressionSet<Th...>;
    using Lit = typename TheTheory::Lit;

public:

    Yices(const Yices &that) = delete;
    Yices(Yices &&that) = delete;
    Yices& operator=(const Yices &that) = delete;
    Yices& operator=(Yices &&that) = delete;

    Yices(Logic logic): ctx(YicesContext()), config(yices_new_config()) {
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

    void add(const BoolExpr e) override {
        if (yices_assert_formula(solver, ExprToSmt<term_t, Th...>::convert(e, ctx)) < 0) {
            throw YicesError();
        }
    }

    void push() override {
        yices_push(solver);
    }

    void pop() override {
        yices_pop(solver);
    }

    SmtResult processResult(smt_status status) {
        switch (status) {
        case STATUS_SAT:
            return Sat;
        case STATUS_UNSAT:
            return Unsat;
        case STATUS_ERROR: {
            std::cerr << yices_error_string() << std::endl;
            throw std::logic_error("error from yices");
        }
        default:
            return Unknown;
        }
    }

    SmtResult check() override {
        return processResult(yices_check_context(solver, nullptr));
    }

    Model<Th...> model(const std::optional<const VarSet> &vars = {}) override {
        if (ctx.getSymbolMap().empty()) {
            return Model<Th...>();
        }
        model_t *m = yices_get_model(solver, true);
        Model<Th...> res;
        const auto add = [&res, this, m](const auto &x, const auto &y) {
            if constexpr ((std::same_as<Arith, Th> || ...)) {
                if (std::holds_alternative<Arith::Var>(x)) {
                    const auto val {getRealFromModel(m, y)};
                    assert(mp::denominator(val) == 1);
                    res.template put<Arith>(std::get<Arith::Var>(x), mp::numerator(val));
                }
            } else if constexpr ((std::same_as<Bools, Th> || ...)) {
                if (std::holds_alternative<BoolVar>(x)) {
                    int32_t val;
                    if (yices_get_bool_value(m, y, &val) != 0) {
                        throw YicesError();
                    }
                    res.template put<Bools>(std::get<BoolVar>(x), val);
                }
            } else {
                throw std::logic_error("unknown variable type");
            }
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
            for (const auto &[x,y]: map) {
                add(x, y);
            }
        }
        yices_free_model(m);
        return res;
    }

    void randomize(unsigned seed) override {
        // TODO
    }

    void enableModels() override {}

    void resetSolver() override {
        yices_reset_context(solver);
    }

    ~Yices() override {
        yices_free_config(config);
        yices_free_context(solver);
    }

    std::ostream& print(std::ostream& os) const override {
        throw std::invalid_argument("print not supported by yices");
    }

private:
    YicesContext ctx;
    ctx_config_t *config;
    context_t *solver{};


    Rational getRealFromModel(model_t *model, type_t symbol) {
        int64_t num;
        uint64_t denom;
        if (yices_get_rational64_value(model, symbol, &num, &denom) == EVAL_OVERFLOW) {
            throw std::overflow_error("overflow during conversion of model");
        }
        assert(denom != 0);
        Rational res {num};
        res = res / denom;
        return res;
    }

};
