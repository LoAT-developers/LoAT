#ifndef SMT_H
#define SMT_H

#include "expression.hpp"
#include "boolexpr.hpp"
#include "variablemanager.hpp"
#include "model.hpp"

class Smt
{
public:

    enum Result {Sat, Unknown, Unsat};
    enum Logic {QF_LA, QF_NA, QF_ENA};

    virtual void add(const BoolExpr e) = 0;
    void add(const Rel &e);
    virtual void push() = 0;
    virtual void pop() = 0;
    virtual Result check() = 0;
    virtual Model model() = 0;
    virtual void setTimeout(unsigned int timeout) = 0;
    virtual void enableModels() = 0;
    virtual void resetSolver() = 0;
    virtual ~Smt();

    static Smt::Result check(const BoolExpr e, const VariableManager &varMan);
    static bool isImplication(const BoolExpr lhs, const BoolExpr rhs, const VariableManager &varMan);
    static BoolExprSet unsatCore(const BoolExprSet &assumptions, VariableManager &varMan);
    static Logic chooseLogic(const std::vector<BoolExpr> &xs, const std::vector<Subs> &up = {});
    static Logic chooseLogic(const BoolExprSet &xs);

    template<class RELS, class UP> static Logic chooseLogic(const std::vector<RELS> &g, const std::vector<UP> &up) {
        Logic res = QF_LA;
        for (const RELS &rels: g) {
            for (const Rel &rel: rels) {
                if (!rel.isLinear()) {
                    if (!rel.isPoly()) {
                        return QF_ENA;
                    }
                    res = QF_NA;
                }
            }
        }
        for (const UP &t: up) {
            if (!t.isLinear()) {
                if (!t.isPoly()) {
                    return QF_ENA;
                }
                res = QF_NA;
            }
        }
        return res;
    }

    void popAll();

protected:

    virtual std::pair<Result, BoolExprSet> _unsatCore(const BoolExprSet &assumptions) = 0;


private:

    int pushCount = 0;
};

#endif // SMT_H
