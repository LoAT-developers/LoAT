#pragma once

#include "smt.hpp"
#include "swinecontext.hpp"
#include "exprtosmt.hpp"


template <ITheory... Th>
class Swine: public Smt<Th...> {

    using TheTheory = Theory<Th...>;
    using BoolExpr = BExpr<Th...>;
    using BoolExprSet = BoolExpressionSet<Th...>;
    using Lit = typename TheTheory::Lit;

public:

    Swine(const swine::Config config = swine::Config()): solver(config, z3ctx), ctx(solver) {
        updateParams();
    }

    void add(const BExpr<Th...> e) override {
        solver.add(ExprToSmt<z3::expr, Th...>::convert(e, ctx));
    }

    void push() override {
        solver.push();
    }

    void pop() override {
        solver.pop();
    }

    SmtResult check() override {
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

    Model<Th...> model(const std::optional<const VarSet> &vars = {}) override {
        const z3::model &m = solver.get_model();
        Model<Th...> res;
        const auto add = [&res, this, &m](const auto &p) {
            if constexpr ((std::is_same_v<IntTheory, Th> || ...)) {
                if (std::holds_alternative<NumVar>(p.first)) {
                    NumVar var = std::get<NumVar>(p.first);
                    Num val = getRealFromModel(m, p.second);
                    res.template put<IntTheory>(var, val);
                    return;
                }
            }
            if constexpr ((std::is_same_v<BoolTheory, Th> || ...)) {
                if (std::holds_alternative<BoolVar>(p.first)) {
                    BoolVar var = std::get<BoolVar>(p.first);
                    switch (m.eval(p.second).bool_value()) {
                    case Z3_L_FALSE:
                        res.template put<BoolTheory>(var, false);
                        break;
                    case Z3_L_TRUE:
                        res.template put<BoolTheory>(var, true);
                        break;
                    default: break;
                    }
                    return;
                }
            }
            throw std::logic_error("unknown variable type");
        };
        const auto map = ctx.getSymbolMap();
        if (vars) {
            for (const auto &x: *vars) {
                const auto it = map.find(x);
                if (it != map.end()) {
                    add(*it);
                }
            }
        } else {
            for (const auto &p: map) {
                add(p);
            }
        }
        return res;
    }

    void enableModels() override {}

    void resetSolver() override {
        solver.reset();
        updateParams();
    }

    ~Swine() override {}

    std::ostream& print(std::ostream& os) const override {
        return os << solver;
    }

    void setSeed(unsigned seed) override {
        this->seed = seed;
        updateParams();
    }

private:

    z3::context z3ctx;
    swine::Swine solver;
    SwineContext ctx;
    unsigned seed = 42u;

    Num getRealFromModel(const z3::model &model, const z3::expr &symbol) {
        return Num(Z3_get_numeral_string(
                   model.ctx(),
                   Z3_get_numerator(
                       model.ctx(),
                       model.eval(symbol, true)))) /
               Num(Z3_get_numeral_string(
                   model.ctx(),
                   Z3_get_denominator(
                       model.ctx(),
                       model.eval(symbol, true))));
    }

    void updateParams() {
        z3::params params(z3ctx);
        params.set(":seed", seed);
        params.set(":random_seed", seed);
        solver.get_solver().set(params);
    }

};
