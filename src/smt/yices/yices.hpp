#pragma once

#include "smt.hpp"
#include "yicescontext.hpp"
#include "config.hpp"
#include "exprtosmt.hpp"

#include <mutex>
#include <future>
#include <stdexcept>

namespace yices {

unsigned int running;
std::mutex mutex;

static void init() {
    yices_init();
}

static void exit() {
    mutex.lock();
    if (running == 0) {
        yices_exit();
    }
    mutex.unlock();
}

}

template<ITheory... Th>
class Yices : public Smt<Th...> {

    using TheTheory = Theory<Th...>;
    using BoolExpr = BExpr<Th...>;
    using BoolExprSet = BoolExpressionSet<Th...>;
    using Lit = typename TheTheory::Lit;

public:
    Yices(const VariableManager &varMan, Logic logic): ctx(YicesContext()), varMan(varMan), config(yices_new_config()) {
        if (logic == QF_NA) {
            yices_set_config(config, "solver-type", "mcsat");
        }
        solver = yices_new_context(config);
        yices::mutex.lock();
        ++yices::running;
        yices::mutex.unlock();
    }

    void add(const BoolExpr e) override {
        if (yices_assert_formula(solver, ExprToSmt<term_t, Th...>::convert(e, ctx, varMan)) < 0) {
            throw YicesError();
        }
    }

    void push() override {
        Smt<Th...>::push();
        yices_push(solver);
    }

    void pop() override {
        Smt<Th...>::pop();
        yices_pop(solver);
    }

    SmtResult check() override {
        auto future = std::async(yices_check_context, solver, nullptr);
        if (future.wait_for(std::chrono::milliseconds(timeout)) != std::future_status::timeout) {
            switch (future.get()) {
            case STATUS_SAT:
                return Sat;
            case STATUS_UNSAT:
                return Unsat;
            default:
                return Unknown;
            }
        } else {
           yices_stop_search(solver);
           return Unknown;
        }
    }

    Model<Th...> model() override {
        if (ctx.getSymbolMap().empty()) {
            return Model<Th...>();
        }
        model_t *m = yices_get_model(solver, true);
        Model<Th...> res;
        for (const auto &p: ctx.getSymbolMap()) {
            if constexpr ((std::same_as<IntTheory, Th> || ...)) {
                if (std::holds_alternative<NumVar>(p.first)) {
                    res.template put<IntTheory>(std::get<NumVar>(p.first), getRealFromModel(m, p.second));
                }
            }
            if constexpr ((std::same_as<BoolTheory, Th> || ...)) {
                if (std::holds_alternative<BoolVar>(p.first)) {
                    int32_t val;
                    if (yices_get_bool_value(m, p.second, &val) != 0) {
                        throw YicesError();
                    }
                    res.template put<BoolTheory>(std::get<BoolVar>(p.first), val);
                }
            }
            throw std::logic_error("unknown variable type");
        }
        yices_free_model(m);
        return res;
    }

    void setTimeout(unsigned int timeout) override {
        this->timeout = timeout;
    }

    void enableModels() override {}

    void resetSolver() override {
        yices_reset_context(solver);
    }

    ~Yices() override {
        yices::mutex.lock();
        --yices::running;
        yices::mutex.unlock();
        yices_free_config(config);
        yices_free_context(solver);
    }

    std::ostream& print(std::ostream& os) const;

    std::pair<SmtResult, BoolExpressionSet<Th...>> _unsatCore(const BoolExpressionSet<Th...> &assumptions) override {
        std::vector<term_t> as;
        std::map<term_t, BExpr<Th...>> map;
        for (const BoolExpr &a: assumptions) {
            term_t t = ExprToSmt<term_t, Th...>::convert(a, ctx, varMan);
            as.push_back(t);
            map.emplace(t, a);
        }
        auto future = std::async(yices_check_context_with_assumptions, solver, nullptr, as.size(), &as[0]);
        if (future.wait_for(std::chrono::milliseconds(timeout)) != std::future_status::timeout) {
            switch (future.get()) {
            case STATUS_SAT:
                return {Sat, {}};
            case STATUS_UNSAT: {
                term_vector_t core;
                yices_init_term_vector(&core);
                yices_get_unsat_core(solver, &core);
                BoolExprSet res;
                for (unsigned int i = 0; i < core.size; ++i) {
                    res.insert(map[core.data[i]]);
                }
                return {Unsat, res};
            }
            default:
                return {Unknown, {}};
            }
        } else {
            yices_stop_search(solver);
            return {Unknown, {}};
        }
    }

private:
    unsigned int timeout = Config::Smt::DefaultTimeout;
    YicesContext ctx;
    const VariableManager &varMan;
    ctx_config_t *config;
    context_t *solver;


    Num getRealFromModel(model_t *model, type_t symbol) {
        int64_t num;
        uint64_t denom;
        yices_get_rational64_value(model, symbol, &num, &denom);
        assert(denom != 0);
        Num res = num;
        res = res / denom;
        return res;
    }

};
