#pragma once

#include "itheory.hpp"
#include "boolexpr.hpp"
#include "variablemanager.hpp"
#include "model.hpp"

enum SmtResult {Sat, Unknown, Unsat};
enum Logic {
    /**
     * linear arithmetic
     */
    QF_LA,
    /**
     * polynomial arithmetic
     */
    QF_NA,
    /**
     * polynomial arithmetic + transcendentals (currently just exponentiation)
     */
    QF_NAT};

namespace SmtFactory {
template<ITheory... Th>
BoolExpressionSet<Th...> unsatCore(const BoolExpressionSet<Th...> &assumptions, VariableManager &varMan);
}

template <ITheory... Th>
class Smt
{
    template<ITheory... Th_>
    friend BoolExpressionSet<Th_...> SmtFactory::unsatCore(const BoolExpressionSet<Th_...> &assumptions, VariableManager &varMan);

public:

    using TheTheory = Theory<Th...>;
    using BoolExpr = BExpr<Th...>;
    using BoolExprSet = BoolExpressionSet<Th...>;
    using Lit = typename TheTheory::Lit;

    virtual void add(const BoolExpr e) = 0;

    void add(const Lit &e) {
        return this->add(BoolExpression<Th...>::buildTheoryLit(e));
    }

    virtual void push() {
        pushCount++;
    }

    virtual void pop() {
        pushCount--;
    };

    virtual SmtResult check() = 0;
    virtual Model<Th...> model() = 0;
    virtual void setTimeout(unsigned int timeout) = 0;
    virtual void enableModels() = 0;
    virtual void resetSolver() = 0;

    virtual ~Smt() {}

    static BoolExprSet unsatCore(const BoolExpressionSet<Th...> &assumptions, VariableManager &varMan);

    void popAll() {
        while (pushCount > 0) {
            pop();
        }
    }

    static Logic chooseLogic(const std::vector<BExpr<Th...>> &xs, const std::vector<Subs> &up = {}) {
        Logic res = QF_LA;
        for (const auto &x: xs) {
            if (!(x->isLinear())) {
                if (!(x->isPoly())) {
                    return QF_NAT;
                }
                res = QF_NA;
            }
        }
        for (const Subs &u: up) {
            if (!u.isLinear()) {
                if (!u.isPoly()) {
                    return QF_NAT;
                }
                res = QF_NA;
            }
        }
        return res;
    }

    static Logic chooseLogic(const BoolExpressionSet<Th...> &xs) {
        Logic res = QF_LA;
        for (const auto &x: xs) {
            if (!(x->isLinear())) {
                if (!(x->isPoly())) {
                    return QF_NAT;
                }
                res = QF_NA;
            }
        }
        return res;
    }

    template<class RELS, class UP>
    static Logic chooseLogic(const std::vector<RELS> &g, const std::vector<UP> &up) {
        Logic res = QF_LA;
        for (const RELS &rels: g) {
            for (const auto &lit: rels) {
                if (!literal_t::isLinear<Th...>(lit)) {
                    if (!literal_t::isPoly<Th...>(lit)) {
                        return QF_NAT;
                    }
                    res = QF_NA;
                }
            }
        }
        for (const UP &t: up) {
            if (!t.isLinear()) {
                if (!t.isPoly()) {
                    return QF_NAT;
                }
                res = QF_NA;
            }
        }
        return res;
    }

protected:

    virtual std::pair<SmtResult, BoolExpressionSet<Th...>> _unsatCore(const BoolExpressionSet<Th...> &assumptions) = 0;


private:

    int pushCount = 0;
};
