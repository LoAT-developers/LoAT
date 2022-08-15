#include "yices.hpp"
#include "exprtosmt.hpp"
#include "exceptions.hpp"
#include "smttoexpr.hpp"

#include <future>
#include <chrono>

Yices::~Yices() {
    mutex.lock();
    --running;
    mutex.unlock();
    yices_free_config(config);
    yices_free_context(solver);
}

Yices::Yices(const VariableManager &varMan, Logic logic): ctx(YicesContext()), varMan(varMan), config(yices_new_config()) {
    if (logic == Smt::QF_NA) {
        yices_set_config(config, "solver-type", "mcsat");
    }
    solver = yices_new_context(config);
    mutex.lock();
    ++running;
    mutex.unlock();
}

void Yices::add(const BoolExpr e) {
    if (yices_assert_formula(solver, ExprToSmt<term_t>::convert(e, ctx, varMan)) < 0) {
        throw YicesError();
    }
}

void Yices::push() {
    Smt::push();
    yices_push(solver);
}

void Yices::pop() {
    Smt::pop();
    yices_pop(solver);
}

Smt::Result Yices::check() {
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

Model Yices::model() {
    if (ctx.getSymbolMap().empty() && ctx.getConstMap().empty()) {
        return Model({}, {});
    }
    model_t *m = yices_get_model(solver, true);
    VarMap<GiNaC::numeric> vars;
    for (const auto &p: ctx.getSymbolMap()) {
        vars[p.first] = getRealFromModel(m, p.second);
    }
    std::map<unsigned int, bool> constants;
    for (const auto &p: ctx.getConstMap()) {
        int32_t val;
        if (yices_get_bool_value(m, p.second, &val) != 0) {
            throw YicesError();
        }
        constants[p.first] = val;
    }
    yices_free_model(m);
    return Model(vars, constants);
}

void Yices::setTimeout(unsigned int timeout) {
    this->timeout = timeout;
}

void Yices::enableModels() { }

GiNaC::numeric Yices::getRealFromModel(model_t *model, type_t symbol) {
    int64_t num;
    uint64_t denom;
    yices_get_rational64_value(model, symbol, &num, &denom);
    assert(denom != 0);
    GiNaC::numeric res = num;
    res = res / denom;
    return res;
}

void Yices::resetSolver() {
    yices_reset_context(solver);
}

std::pair<Smt::Result, BoolExprSet> Yices::_unsatCore(const BoolExprSet &assumptions) {
    std::vector<term_t> as;
    std::map<term_t, BoolExpr> map;
    for (const BoolExpr &a: assumptions) {
        term_t t = ExprToSmt<term_t>::convert(a, ctx, varMan);
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

unsigned int Yices::running;
std::mutex Yices::mutex;

void Yices::init() {
    yices_init();
}

void Yices::exit() {
    mutex.lock();
    if (running == 0) {
        yices_exit();
    }
    mutex.unlock();
}
