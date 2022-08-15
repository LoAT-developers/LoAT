#include "smt2export.hpp"
#include "sexpresso.hpp"

using namespace sexpresso;

Sexp exprToSexp(const Expr &e) {
    assert(e.isPoly());
    if (e.isAdd()) {
        Sexp res("+");
        for (unsigned int i = 0; i < e.arity(); ++i) {
            if (res.childCount() < 3) {
                res.addChild(exprToSexp(e.op(i)));
            } else {
                res = Sexp({Sexp("+"), res, exprToSexp(e.op(i))});
            }
        }
        return res;
    } else if (e.isMul()) {
        Sexp res("*");
        for (unsigned int i = 0; i < e.arity(); ++i) {
            if (res.childCount() < 3) {
                res.addChild(exprToSexp(e.op(i)));
            } else {
                res = Sexp({Sexp("*"), res, exprToSexp(e.op(i))});
            }
        }
        return res;
    } else if (e.isInt()) {
        return Sexp(e.toString());
    } else if (e.isVar()) {
        return Sexp(e.toString() + "^0");
    } else if (e.isNaturalPow()) {
        int degree = e.op(1).toNum().to_int();
        Sexp res("*");
        for (int i = 0; i < degree; ++i) {
            if (res.childCount() < 3) {
                res.addChild(exprToSexp(e.op(0)));
            } else {
                res = Sexp({Sexp("*"), res, exprToSexp(e.op(0))});
            }
        }
        return res;
    } else {
        throw std::invalid_argument("");
    }
}

option<Sexp> boolExprToSexp(BoolExpr e) {
    assert(e->isConjunction());
    if (e->isAnd()) {
        option<Sexp> res;
        for (BoolExpr c: e->getChildren()) {
            auto lit = boolExprToSexp(c);
            if (res && lit) {
                res = Sexp({Sexp("and"), *res, *lit});
            } else if (!res) {
                res = lit;
            }
        }
        return res;
    } else {
        auto lit = e->getLit();
        if (lit) {
            if (lit->isEq()) {
                return Sexp({Sexp("="), exprToSexp(lit->lhs()), exprToSexp(lit->rhs())});
            } else if (lit->isNeq()) {
                return Sexp({Sexp("!="), exprToSexp(lit->lhs()), exprToSexp(lit->rhs())});
            } else {
                lit = lit->toGt();
                auto exp = lit->lhs() - lit->rhs();
                return Sexp({Sexp(">"), exprToSexp(exp), Sexp("0")});
            }
        } else {
            throw std::invalid_argument("");
        }
    }
}

void smt2Export::doExport(const ITSProblem& its) {
    Sexp res;
    res.addChild(Sexp({Sexp("declare-sort"), Sexp("Loc"), Sexp("0")}));
    Sexp distinct("distinct");
    for (auto loc: its.getLocations()) {
        std::string loc_str = "l" + std::to_string(loc);
        res.addChild(Sexp({Sexp("declare-const"), Sexp(loc_str), Sexp("Loc")}));
        distinct.addChild(loc_str);
    }
    res.addChild(Sexp({Sexp("assert"), distinct}));
    res.addChild(Sexp({
                          Sexp("define-fun"),
                          Sexp("cfg_init"),
                          Sexp({
                              Sexp({Sexp("pc"), Sexp("Loc")}),
                              Sexp({Sexp("src"), Sexp("Loc")}),
                              Sexp({Sexp("rel"), Sexp("Bool")})
                          }),
                          Sexp("Bool"),
                          Sexp({
                              Sexp("and"),
                              Sexp({Sexp("="),
                                    Sexp("pc"),
                                    Sexp("src")
                              }), Sexp("rel")
                          })
                      }));
    res.addChild(Sexp({
                          Sexp("define-fun"),
                          Sexp("cfg_trans2"),
                          Sexp({
                              Sexp({Sexp("pc"), Sexp("Loc")}),
                              Sexp({Sexp("src"), Sexp("Loc")}),
                              Sexp({Sexp("pc1"), Sexp("Loc")}),
                              Sexp({Sexp("dst"), Sexp("Loc")}),
                              Sexp({Sexp("rel"), Sexp("Bool")})
                          }),
                          Sexp("Bool"),
                          Sexp({
                              Sexp("and"),
                              Sexp({Sexp("="),
                                    Sexp("pc"),
                                    Sexp("src")
                              }),
                              Sexp({Sexp("="),
                                    Sexp("pc1"),
                                    Sexp("dst")
                              }), Sexp("rel")
                          })
                      }));
    res.addChild(Sexp({
                          Sexp("define-fun"),
                          Sexp("cfg_trans3"),
                          Sexp({
                              Sexp({Sexp("pc"), Sexp("Loc")}),
                              Sexp({Sexp("exit"), Sexp("Loc")}),
                              Sexp({Sexp("pc1"), Sexp("Loc")}),
                              Sexp({Sexp("pc2"), Sexp("Loc")}),
                              Sexp({Sexp("return"), Sexp("Loc")}),
                              Sexp({Sexp("rel"), Sexp("Bool")})
                          }),
                          Sexp("Bool"),
                          Sexp({
                              Sexp("and"),
                              Sexp({Sexp("="),
                                    Sexp("pc"),
                                    Sexp("exit")
                              }),
                              Sexp({Sexp("="),
                                    Sexp("pc1"),
                                    Sexp("call")
                              }),
                              Sexp({Sexp("="),
                                    Sexp("pc2"),
                                    Sexp("return")
                              }), Sexp("rel")
                          })
                      }));
    Sexp var_list;
    var_list.addChild(Sexp({Sexp("pc^0"), Sexp("Loc")}));
    for (auto x: its.getVars()) {
        assert(!its.isTempVar(x));
        var_list.addChild(Sexp({Sexp(x.get_name() + "^0"), Sexp("Int")}));
    }
    std::string init_loc = "l" + std::to_string(its.getInitialLocation());
    res.addChild(Sexp({
                          Sexp("define-fun"),
                          Sexp("init_main"),
                          var_list,
                          Sexp("Bool"),
                          Sexp({Sexp("cfg_init"), Sexp("pc^0"), Sexp(init_loc), Sexp("true")})
                      }));
    var_list.addChild(Sexp({Sexp("pc^post"), Sexp("Loc")}));
    for (auto x: its.getVars()) {
        if (!its.isTempVar(x)) {
            var_list.addChild(Sexp({Sexp(x.get_name() + "^post"), Sexp("Int")}));
        }
    }
    Sexp transitions("or");
    for (auto idx: its.getAllTransitions()) {
        LinearRule rule = its.getRule(idx).toLinear();
        Sexp src = Sexp("l" + std::to_string(rule.getLhs().getLoc()));
        Sexp dst = Sexp("l" + std::to_string(rule.getRhsLoc()));
        Sexp trans({Sexp("cfg_trans2"), Sexp("pc^0"), src, Sexp("pc^post"), dst});
        option<Sexp> cond;
        const auto &up = rule.getUpdate();
        for (auto var: its.getVars()) {
            auto it = up.find(var);
            if (it != up.end()) {
                if (cond) {
                    cond = Sexp({Sexp("and"), *cond, Sexp({Sexp("="), Sexp(var.get_name() + "^post"), exprToSexp(it->second)})});
                } else {
                    cond = Sexp({Sexp("="), Sexp(var.get_name() + "^post"), exprToSexp(it->second)});
                }
            } else if (cond) {
                cond = Sexp({Sexp("and"), *cond, Sexp({Sexp("="), Sexp(var.get_name() + "^post"), Sexp(var.get_name() + "^0")})});
            } else {
                cond = Sexp({Sexp("="), Sexp(var.get_name() + "^post"), Sexp(var.get_name() + "^0")});
            }
        }
        if (cond) {
            auto guard = boolExprToSexp(rule.getGuard());
            if (guard) {
                cond = Sexp({Sexp("and"), *guard, *cond});
            }
        } else {
            cond = boolExprToSexp(rule.getGuard());
        }
        trans.addChild(*cond);
        transitions.addChild(trans);
    }
    res.addChild(Sexp({
                          Sexp("define-fun"),
                          Sexp("next_main"),
                          var_list,
                          Sexp("Bool"),
                          transitions
                      }));
    std::cout << res.toString() << std::endl;
}
