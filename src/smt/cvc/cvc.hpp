#pragma once

#include "smt.hpp"
#include "cvccontext.hpp"
#include "config.hpp"
#include "exprtosmt.hpp"

template <ITheory... Th>
class CVC : public Smt<Th...> {

    using TheTheory = Theory<Th...>;
    using BoolExpr = BExpr<Th...>;
    using BoolExprSet = BoolExpressionSet<Th...>;
    using Lit = typename TheTheory::Lit;

public:
    CVC(const VariableManager &varMan): varMan(varMan), ctx(solver) {
        updateParams();
    }

    void add(const BExpr<Th...> e) override {
        solver.assertFormula(ExprToSmt<cvc5::Term, Th...>::convert(e, ctx, varMan));
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
        const auto res = solver.checkSat();
        if (res.isSat()) {
            return Sat;
        } else if (res.isUnsat()) {
            return Unsat;
        } else {
            return Unknown;
        }
    }

    Model<Th...> model() override {
        assert(models);
        Model<Th...> res;
        for (const auto &p: ctx.getSymbolMap()) {
            if constexpr ((std::is_same_v<IntTheory, Th> || ...)) {
                if (std::holds_alternative<NumVar>(p.first)) {
                    NumVar var = std::get<NumVar>(p.first);
                    Num val(solver.getValue(p.second).getIntegerValue().c_str());
                    res.template put<IntTheory>(var, val);
                    continue;
                }
            }
            if constexpr ((std::is_same_v<BoolTheory, Th> || ...)) {
                if (std::holds_alternative<BoolVar>(p.first)) {
                    BoolVar var = std::get<BoolVar>(p.first);
                    bool val = solver.getValue(p.second).getBooleanValue();
                    res.template put<BoolTheory>(var, val);
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
        solver.resetAssertions();
        updateParams();
    }

    ~CVC() override {}

    std::ostream& print(std::ostream& os) const {
        for (const auto &a: solver.getAssertions()) {
            os << a << std::endl;
        }
        return os;
    }

    std::pair<SmtResult, BoolExpressionSet<Th...>> _unsatCore(const BoolExpressionSet<Th...> &assumptions) override {
        std::vector<cvc5::Term> as;
        std::map<std::pair<unsigned int, std::string>, BExpr<Th...>> map;
        for (const auto &a: assumptions) {
            const cvc5::Term t = ExprToSmt<cvc5::Term, Th...>::convert(a, ctx, varMan);
            as.push_back(t);
            std::pair<unsigned int, std::string> key = {t.getId(), t.toString()};
            assert(map.count(key) == 0);
            map.emplace(key, a);
        }
        auto cvcRes = solver.checkSatAssuming(as);
        if (cvcRes.isUnsat()) {
            const auto core = solver.getUnsatAssumptions();
            BoolExprSet res;
            for (const auto &e: core) {
                std::pair<unsigned int, std::string> key = {e.getId(), e.toString()};
                assert(map.contains(key));
                res.insert(map[key]);
            }
            return {Unsat, res};
        } else if (cvcRes.isSat()) {
            return {Sat, {}};
        } else {
            return {Unknown, {}};
        }
    }

private:
    bool models = false;
    unsigned int timeout = Config::Smt::DefaultTimeout;
    const VariableManager &varMan;
    cvc5::Solver solver;
    CVCContext ctx;

    void updateParams() {
        solver.setOption("produce-models", models ? "true" : "false");
        solver.setOption("tlimit", std::to_string(timeout));
        // TODO make this configurable
        solver.setOption("produce-unsat-assumptions", "true");
    }

};
