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
    CVC5(): solver(), ctx(solver) {
        solver.setOption("seed", std::to_string(seed));
        solver.setLogic("QF_NIRAT");
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
        Model<Th...> res;
        const auto add = [&res, this](const auto &x, const auto &y) {
            if constexpr ((std::is_same_v<IntTheory, Th> || ...)) {
                if (std::holds_alternative<NumVar>(x)) {
                    NumVar var = std::get<NumVar>(x);
                    Num val = getRealFromModel(y);
                    res.template put<IntTheory>(var, val);
                    return;
                }
            }
            if constexpr ((std::is_same_v<BoolTheory, Th> || ...)) {
                if (std::holds_alternative<BoolVar>(x)) {
                    BoolVar var = std::get<BoolVar>(x);
                    res.template put<BoolTheory>(var, this->solver.getValue(y).getBooleanValue());
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
        solver.setOption("produce-models", "true");
    }

    void resetSolver() override {
        solver.resetAssertions();
    }

    ~CVC5() override {}

    std::ostream& print(std::ostream& os) const override {
        for (const auto &t: solver.getAssertions()) {
            os << t << std::endl;
        }
        return os;
    }

    void randomize(unsigned seed) override {
        // TODO
    }

private:
    cvc5::Solver solver;
    CVC5Context ctx;
    unsigned seed = 42u;

    Num getRealFromModel(const cvc5::Term &symbol) {
        const auto val {solver.getValue(symbol)};
        if (val.isIntegerValue()) {
            return Num(val.getIntegerValue().c_str());
        } else if (val.isRealValue()) {
            if (val.isReal64Value()) {
                const auto [num, denom] {val.getReal64Value()};
                return Num(num) / Num(denom);
            } else {
                throw std::overflow_error((std::stringstream() << "overflow in CVC5::getRealFromModel: " << val).str());
            }
        } else {
            throw std::logic_error((std::stringstream() << "CVC5::getRealFromModel: tried to convert " << val << " to real").str());
        }
    }

};
