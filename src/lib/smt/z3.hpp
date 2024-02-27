#pragma once

#include "smt.hpp"
#include "z3context.hpp"
#include "exprtosmt.hpp"
#include "thset.hpp"

template <class Ctx, ITheory... Th>
class Z3Base : public Smt<Th...> {

    using TheTheory = Theory<Th...>;
    using BoolExpr = BExpr<Th...>;
    using BoolExprSet = BoolExpressionSet<Th...>;
    using Lit = typename TheTheory::Lit;

public:

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
        case z3::unsat: return Unsat;
        case z3::unknown: return Unknown;
        case z3::sat: return Sat;
        }
        throw std::logic_error("unknown result from SMT solver");
    }

    Model<Th...> model(const std::optional<const VarSet> &vars = {}) override {
        const z3::model &m = solver.get_model();
        Model<Th...> res;
        const auto add = [&res, this, &m](const auto &x, const auto &y) {
            if constexpr ((std::is_same_v<Arith, Th> || ...)) {
                if (std::holds_alternative<Arith::Var>(x)) {
                    const auto var {std::get<Arith::Var>(x)};
                    const auto val {getRealFromModel(m, y)};
                    assert(mp::denominator(val) == 1);
                    res.template put<Arith>(var, mp::numerator(val));
                    return;
                }
            }
            if constexpr ((std::is_same_v<Bools, Th> || ...)) {
                if (std::holds_alternative<Bools::Var>(x)) {
                    const auto var {std::get<Bools::Var>(x)};
                    switch (m.eval(y).bool_value()) {
                    case Z3_L_FALSE:
                        res.template put<Bools>(var, false);
                        break;
                    case Z3_L_TRUE:
                        res.template put<Bools>(var, true);
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
                const auto res {map.get(x)};
                if (res) {
                    add(x, *res);
                }
            }
        } else {
            for (const auto &[x, y]: map) {
                add(x, y);
            }
        }
        return res;
    }

    void enableModels() override {
        solver.set("model", true);
    }

    void resetSolver() override {
        solver.reset();
    }

    ~Z3Base() override {}

    std::ostream& print(std::ostream& os) const override {
        return os << solver;
    }

    void randomize(unsigned seed) override {
        solver.set("random_seed", seed);
        solver.set("sat.random_seed", seed);
        solver.set("seed", seed);
        solver.set("nlsat.seed", seed);
    }

protected:
    z3::context z3Ctx{};
    Ctx ctx;
    z3::solver solver;

    Z3Base(): ctx(z3Ctx), solver(z3Ctx) {
        solver.set("random_seed", 42u);
        solver.set("sat.random_seed", 42u);
        solver.set("seed", 42u);
        solver.set("nlsat.seed", 42u);
        solver.set("rlimit", 10000000u);
    }

    Rational getRealFromModel(const z3::model &model, const z3::expr &symbol) {
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

};

template <ITheory... Th>
class Z3: public Z3Base<Z3Context, Th...> {

public:

    Z3(): Z3Base<Z3Context, Th...>() {}

};
