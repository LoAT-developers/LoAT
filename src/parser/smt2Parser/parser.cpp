#include "parser.hpp"
#include "config.hpp"

#include <fstream>
#include <boost/algorithm/string.hpp>
#include <ginac/ginac.h>

namespace sexpressionparser {

    typedef Parser Self;

    ITSPtr Self::loadFromFile(const std::string &filename) {
        Parser parser;
        parser.run(filename);
        return parser.res;
    }

    void Self::run(const std::string &filename) {
        std::ifstream ifs(filename);
        std::string content(
                (std::istreambuf_iterator<char>(ifs)),
                (std::istreambuf_iterator<char>()));
        sexpresso::Sexp sexp = sexpresso::parse(content);
        for (auto &ex: sexp.arguments()) {
            if (ex[0].str() == "declare-const" && ex[2].str() == "Loc") {
                LocationIdx locIdx = res->addNamedLocation(ex[1].str());
                locations[ex[1].str()] = locIdx;
            } else if (ex[0].str() == "define-fun") {
                if (ex[1].str() == "init_main") {
                    // the initial state
                    sexpresso::Sexp &scope = ex[2];
                    for (sexpresso::Sexp &e: scope.arguments()) {
                        if (e[1].str() == "Int") {
                            vars.emplace(e[0].str(), ArithVar::nextProgVar());
                            preVars.push_back(e[0].str());
                        }
                    }
                    sexpresso::Sexp &init = ex[4];
                    // we do not support conditions regarding the initial state
                    assert(init[3].str() == "true");
                    res->setInitialLocation(locations[init[2].str()]);
                } else if (ex[1].value.str == "next_main") {
                    sexpresso::Sexp &scope = ex[2];
                    for (sexpresso::Sexp &e: scope.arguments()) {
                        if (e[1].str() == "Int") {
                            if (std::find(preVars.begin(), preVars.end(), e[0].str()) == preVars.end()) {
                                vars.emplace(e[0].str(), ArithVar::next());
                                postVars.push_back(e[0].str());
                            }
                        }
                    }
                    assert(preVars.size() == postVars.size());
                    sexpresso::Sexp ruleExps = ex[4];
                    linked_hash_set<Arith::Var> tmpVars;
                    for (const std::string &str: postVars) {
                        tmpVars.insert(vars.at(str));
                    }
                    const auto cost_var = res->getCostVar();
                    for (auto &ruleExp: ruleExps.arguments()) {
                        if (ruleExp[0].str() == "cfg_trans2") {
                            LocationIdx from = locations[ruleExp[2].str()];
                            LocationIdx to = locations[ruleExp[4].str()];
                            Subs update;
                            std::vector<Bools::Expr> guard;
                            parseCond(ruleExp[5], guard);
                            guard.push_back(theory::mkEq(res->getLocVar(), arith::mkConst(from)));
                            const auto cond {bools::mkAnd(guard)};
                            for (unsigned int i = 0; i < preVars.size(); i++) {
                                update.put<Arith>(vars.at(preVars[i]), vars.at(postVars[i]));
                            }
                            update.put<Arith>(res->getLocVar(), arith::mkConst(to));
                            if (Config::Analysis::complexity()) {
                                update.put<Arith>(cost_var, cost_var + arith::mkConst(1));
                            }
                            Rule rule(cond, update);
                            res->addRule(rule, from);
                        }
                    }
                }
            }
        }
    }

    void Self::parseCond(sexpresso::Sexp &sexp, std::vector<Bools::Expr> &guard) {
        if (sexp.isString()) {
            if (sexp.str() == "false") {
                guard.push_back(bot());
            } else {
                assert(sexp.str() == "true");
            }
            return;
        }
        const std::string op = sexp[0].str();
        if (op == "and") {
            for (unsigned int i = 1; i < sexp.childCount(); i++) {
                parseCond(sexp[i], guard);
                }
        } else if (op == "exists") {
            sexpresso::Sexp scope = sexp[1];
            for (sexpresso::Sexp &var: scope.arguments()) {
                const std::string &varName = var[0].str();
                vars.emplace(varName, ArithVar::next());
            }
            parseCond(sexp[2], guard);
        } else {
            guard.push_back(parseConstraint(sexp, false));
        }

    }

    Bools::Expr Self::parseConstraint(sexpresso::Sexp &sexp, bool negate) {
        if (sexp.childCount() == 2) {
            assert(sexp[0].str() == "not");
            return parseConstraint(sexp[1], !negate);
        }
        assert(sexp.childCount() == 3);
        const std::string &op {sexp[0].str()};
        const auto fst {parseExpression(sexp[1])};
        const auto snd {parseExpression(sexp[2])};
        if (op == "<=") {
            return bools::mkLit(negate ? arith::mkGt(fst, snd) : arith::mkLeq(fst, snd));
        } else if (sexp[0].str() == "<") {
            return bools::mkLit(negate ? arith::mkGeq(fst, snd) : arith::mkLt(fst, snd));
        } else if (sexp[0].str() == ">=") {
            return bools::mkLit(negate ? arith::mkLt(fst, snd) : arith::mkGeq(fst, snd));
        } else if (sexp[0].str() == ">") {
            return bools::mkLit(negate ? arith::mkLeq(fst, snd) : arith::mkGt(fst, snd));
        } else if (sexp[0].str() == "=") {
            if (negate) {
                return theory::mkNeq(fst, snd);
            } else {
                return theory::mkEq(fst, snd);
            }
        }
        throw std::invalid_argument("");
    }

    Arith::Expr Self::parseExpression(sexpresso::Sexp &sexp) {
        if (sexp.childCount() == 1) {
            const auto &str {sexp.str()};
            if (std::isdigit(str[0]) || str[0] == '-') {
                return arith::mkConst(Rational(str));
            } else {
                if (vars.find(str) == vars.end()) {
                    vars.emplace(str, ArithVar::next());
                }
                return vars.at(str);
            }
        }
        const auto &op {sexp[0].str()};
        const auto fst {parseExpression(sexp[1])};
        if (sexp.childCount() == 3) {
            const auto snd {parseExpression(sexp[2])};
            if (op == "+") {
                return fst + snd;
            } else if (op == "-") {
                return fst - snd;
            } else if (op == "*") {
                return fst * snd;
            }
        } else if (sexp.childCount() == 2) {
            assert(op == "-");
            return -fst;
        }
        throw std::invalid_argument("unknown operator");
    }

}
