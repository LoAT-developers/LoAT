#pragma once

#include "smt.hpp"
#include "cvc5context.hpp"
#include "exprtosmt.hpp"

#include <cvc5/cvc5.h>

template <ITheory... Th>
class CVC5 : public Smt<Th...> {

    using TheTheory = Theory<Th...>;
    using BoolExpr = BExpr<Th...>;
    using BoolExprSet = BoolExpressionSet<Th...>;
    using Lit = typename TheTheory::Lit;

public:
    CVC5(unsigned timeout): timeout(timeout), ctx(solver) {
        updateParams();
    }

    void add(const BExpr<Th...> e) override {
        solver.assertFormula(ExprToSmt<cvc5::Term, Th...>::convert(e, ctx));
        solver.assertFormula(ctx.clearRefinement());
    }

    void push() override {
        solver.push();
    }

    void pop() override {
        solver.pop();
    }

    SmtResult check() override {
        const auto res {solver.checkSat()};
        if (res.isSat()) {
            return Sat;
        } else if (res.isUnsat()) {
            return Unsat;
        } else {
            return Unknown;
        }
    }

    Model<Th...> model(const std::optional<const VarSet> &vars = {}) override {
        assert(models);
        Model<Th...> res;
        const auto add = [&res, this](const auto &p) {
            if constexpr ((std::is_same_v<IntTheory, Th> || ...)) {
                if (std::holds_alternative<NumVar>(p.first)) {
                    NumVar var = std::get<NumVar>(p.first);
                    Num val = getRealFromModel(p.second);
                    res.template put<IntTheory>(var, val);
                    return;
                }
            }
            if constexpr ((std::is_same_v<BoolTheory, Th> || ...)) {
                if (std::holds_alternative<BoolVar>(p.first)) {
                    BoolVar var = std::get<BoolVar>(p.first);
                    res.template put<BoolTheory>(var, this->solver.getValue(p.second).getBooleanValue());
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

    void enableModels() override {
        this->models = true;
        updateParams();
    }

    void resetSolver() override {
        solver.resetAssertions();
        updateParams();
    }

    ~CVC5() override {}

    std::ostream& print(std::ostream& os) const override {
        for (const auto &t: solver.getAssertions()) {
            os << t << std::endl;
        }
        return os;
    }

    void setSeed(unsigned seed) {
        this->seed = seed;
        updateParams();
    }

private:
    bool models = false;
    unsigned int timeout;
    CVC5Context ctx;
    cvc5::Solver solver;
    unsigned seed = 42u;

    Num getRealFromModel(const cvc5::Term &symbol) {
        const auto val {solver.getValue(symbol)};
        if (val.isReal64Value()) {
            throw std::overflow_error("overflow in CVC5::getRealFromModel");
        }
        const auto [num, denom] {val.getReal64Value()};
        return Num(num) / Num(denom);
    }

    void updateParams() {
        if (models) {
            solver.setOption("produce-models", "true");
        }
        if (timeout > 0) {
            solver.setOption("timeout", std::to_string(timeout));
        }
        solver.setOption("seed", std::to_string(seed));
        solver.setLogic("QF_NIAT");
    }

};
