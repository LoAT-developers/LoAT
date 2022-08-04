#include "z3.hpp"
#include "../exprtosmt.hpp"
#include "../smttoexpr.hpp"

std::ostream& Z3::print(std::ostream& os) const {
    return os << solver;
}

Z3::~Z3() {}

Z3::Z3(const VariableManager &varMan): varMan(varMan), ctx(z3Ctx), solver(z3Ctx) {
    updateParams();
}

void Z3::add(const BoolExpr e) {
    solver.add(ExprToSmt<z3::expr>::convert(e, ctx, varMan));
}

void Z3::push() {
    Smt::push();
    solver.push();
}

void Z3::pop() {
    Smt::pop();
    solver.pop();
}

Smt::Result Z3::check() {
    switch (solver.check()) {
    case z3::sat: return Sat;
    case z3::unsat: return Unsat;
    case z3::unknown: return Unknown;
    }
    throw std::logic_error("unknown result");
}

Model Z3::model() {
    assert(models);
    const z3::model &m = solver.get_model();
    VarMap<GiNaC::numeric> vars;
    for (const auto &p: ctx.getSymbolMap()) {
        vars[p.first] = getRealFromModel(m, p.second);
    }
    std::map<unsigned int, bool> constants;
    for (const auto &p: ctx.getConstMap()) {
        constants[p.first] = m.eval(p.second).bool_value();
    }
    return Model(vars, constants);
}

void Z3::setTimeout(unsigned int timeout) {
    this->timeout = timeout;
    updateParams();
}

void Z3::enableModels() {
    this->models = true;
    updateParams();
}

void Z3::updateParams() {
    z3::params params(z3Ctx);
    params.set(":model", models);
    params.set(":timeout", timeout);
    solver.set(params);
}

GiNaC::numeric Z3::getRealFromModel(const z3::model &model, const z3::expr &symbol) {
    int num,denom;
    Z3_get_numeral_int(model.ctx(),Z3_get_numerator(model.ctx(),model.eval(symbol,true)),&num);
    Z3_get_numeral_int(model.ctx(),Z3_get_denominator(model.ctx(),model.eval(symbol,true)),&denom);
    assert(denom != 0);

    GiNaC::numeric res = num;
    res = res / denom;
    return res;
}

std::pair<Smt::Result, BoolExprSet> Z3::_unsatCore(const BoolExprSet &assumptions) {
    std::vector<z3::expr> as;
    std::map<std::pair<unsigned int, std::string>, BoolExpr> map;
    for (const BoolExpr &a: assumptions) {
        z3::expr t = ExprToSmt<z3::expr>::convert(a, ctx, varMan);
        as.push_back(t);
        std::pair<unsigned int, std::string> key = {t.hash(), t.to_string()};
        assert(map.count(key) == 0);
        map.emplace(key, a);
    }
    auto z3res = solver.check(as.size(), &as[0]);
    if (z3res == z3::unsat) {
        z3::expr_vector core = solver.unsat_core();
        BoolExprSet res;
        for (const z3::expr &e: core) {
            std::pair<unsigned int, std::string> key = {e.hash(), e.to_string()};
            assert(map.count(key) > 0);
            res.insert(map[key]);
        }
        return {Unsat, res};
    } else if (z3res == z3::sat) {
        return {Sat, {}};
    } else {
        return {Unknown, {}};
    }
}

void Z3::resetSolver() {
    solver.reset();
    updateParams();
}

