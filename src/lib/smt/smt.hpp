#pragma once

#include "theory.hpp"
#include "boolexpr.hpp"
#include "model.hpp"
#include "theories.hpp"

namespace smt {

extern const unsigned default_timeout;

}

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

class Smt {

public:

    virtual void add(const BoolExpr e) = 0;

    virtual void add_soft(const BoolExpr e) {
        throw std::invalid_argument("add_soft not supported");
    }

    virtual void add_objective(const ArithExprPtr e) {
        throw std::invalid_argument("add_objective not supported");
    }

    void add(const Lit &e) {
        return this->add(bools::mkLit(e));
    }

    virtual void push() = 0;

    virtual void pop() = 0;

    virtual SmtResult check() = 0;
    virtual Model model(const std::optional<const VarSet> &vars = {}) = 0;
    virtual void enableModels() = 0;
    virtual void resetSolver() = 0;

    virtual void randomize(unsigned seed) = 0;

    virtual ~Smt() {}

    static Logic chooseLogic(const std::vector<BExpr> &xs, const std::vector<Subs> &up = {}) {
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

    static Logic chooseLogic(const BoolExpressionSet &xs) {
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
                if (!theory::isLinear(lit)) {
                    if (!theory::isPoly(lit)) {
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

    virtual std::ostream& print(std::ostream& os) const = 0;

};

using SmtPtr = std::unique_ptr<Smt>;
