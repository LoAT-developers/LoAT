#pragma once

#include "smt.hpp"
#include "z3context.hpp"
#include "exprtosmt.hpp"
#include "thset.hpp"

template <ITheory... Th>
class Z3Opt : public Smt<Th...> {

    using TheTheory = Theory<Th...>;
    using BoolExpr = BExpr<Th...>;
    using BoolExprSet = BoolExpressionSet<Th...>;
    using Lit = typename TheTheory::Lit;

public:
    Z3Opt(unsigned timeout): timeout(timeout), ctx(z3Ctx), solver(z3Ctx) {
        updateParams();
    }

    void add_soft(const BExpr<Th...> e) override {
        solver.add_soft(ExprToSmt<z3::expr, Th...>::convert(e, ctx), 1);
    }

    void add(const BExpr<Th...> e) override {
        solver.add(ExprToSmt<z3::expr, Th...>::convert(e, ctx));
    }

    void push() override {
        Smt<Th...>::push();
        solver.push();
    }

    void pop() override {
        Smt<Th...>::pop();
        solver.pop();
    }

    SmtResult check() override {
        switch (solver.check()) {
        case z3::sat: return Sat;
        case z3::unsat: return Unsat;
        case z3::unknown: return Unknown;
        }
        throw std::logic_error("unknown result");
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

    void setTimeout(unsigned int timeout) override {
        this->timeout = timeout;
        updateParams();
    }

    void enableModels() override {}

    void resetSolver() override {
        throw std::invalid_argument("resetSolver not supported by z3_opt");
    }

    std::pair<SmtResult, BoolExpressionSet<Th...>> _unsatCore(const BoolExpressionSet<Th...> &assumptions) override {
        throw std::invalid_argument("_unsatCore not supported by z3_opt");
    }

    ~Z3Opt() override {}

    std::ostream& print(std::ostream& os) const {
        return os << solver;
    }

    void setSeed(unsigned seed) {}

private:
    unsigned int timeout;
    z3::context z3Ctx;
    Z3Context ctx;
    z3::optimize solver;

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
        z3::params params(z3Ctx);
        params.set(":timeout", timeout);
        params.set(":incremental", true);
        solver.set(params);
    }

};
