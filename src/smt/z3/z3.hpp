#pragma once

#include "smt.hpp"
#include "z3context.hpp"
#include "config.hpp"
#include "exprtosmt.hpp"

template <ITheory... Th>
class Z3 : public Smt<Th...> {

    using TheTheory = Theory<Th...>;
    using BoolExpr = BExpr<Th...>;
    using BoolExprSet = BoolExpressionSet<Th...>;
    using Lit = typename TheTheory::Lit;

public:
    Z3(const VariableManager &varMan): varMan(varMan), ctx(z3Ctx), solver(z3Ctx) {
        updateParams();
    }

    void add(const BExpr<Th...> e) override {
        solver.add(ExprToSmt<z3::expr, Th...>::convert(e, ctx, varMan));
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

    Model<Th...> model() override {
        assert(models);
        const z3::model &m = solver.get_model();
        Model<Th...> res;
        for (const auto &p: ctx.getSymbolMap()) {
            if constexpr ((std::is_same_v<IntTheory, Th> || ...)) {
                if (std::holds_alternative<NumVar>(p.first)) {
                    NumVar var = std::get<NumVar>(p.first);
                    Num val = getRealFromModel(m, p.second);
                    res.template put<IntTheory>(var, val);
                    continue;
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
                    continue;
                }
            }
            throw std::logic_error("unknown variable type");
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
        solver.reset();
        updateParams();
    }

    ~Z3() override {}

    std::ostream& print(std::ostream& os) const {
        return os << solver;
    }

    std::pair<SmtResult, BoolExpressionSet<Th...>> _unsatCore(const BoolExpressionSet<Th...> &assumptions) override {
        std::vector<z3::expr> as;
        std::map<std::pair<unsigned int, std::string>, BExpr<Th...>> map;
        for (const auto &a: assumptions) {
            z3::expr t = ExprToSmt<z3::expr, Th...>::convert(a, ctx, varMan);
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
                assert(map.contains(key));
                res.insert(map[key]);
            }
            return {Unsat, res};
        } else if (z3res == z3::sat) {
            return {Sat, {}};
        } else {
            return {Unknown, {}};
        }
    }

private:
    bool models = false;
    unsigned int timeout = Config::Smt::DefaultTimeout;
    const VariableManager &varMan;
    z3::context z3Ctx;
    Z3Context ctx;
    z3::solver solver;

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
        params.set(":model", models);
        params.set(":timeout", timeout);
        solver.set(params);
    }

};
