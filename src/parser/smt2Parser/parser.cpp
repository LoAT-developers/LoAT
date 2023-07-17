/*  This file is part of LoAT.
 *  Copyright (c) 2019 Florian Frohn
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses>.
 */

#include "parser.hpp"
#include "boolexpression.hpp"
#include "config.hpp"

#include <fstream>
#include <boost/algorithm/string.hpp>
#include <ginac/ginac.h>

namespace sexpressionparser {

    typedef Parser Self;

    ITSProblem Self::loadFromFile(const std::string &filename) {
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
                LocationIdx locIdx = res.addNamedLocation(ex[1].str());
                locations[ex[1].str()] = locIdx;
            } else if (ex[0].str() == "define-fun") {
                if (ex[1].str() == "init_main") {
                    // the initial state
                    sexpresso::Sexp &scope = ex[2];
                    for (sexpresso::Sexp &e: scope.arguments()) {
                        if (e[1].str() == "Int") {
                            vars.emplace(e[0].str(), NumVar::nextProgVar());
                            preVars.push_back(e[0].str());
                        }
                    }
                    sexpresso::Sexp &init = ex[4];
                    // we do not support conditions regarding the initial state
                    assert(init[3].str() == "true");
                    res.setInitialLocation(locations[init[2].str()]);
                } else if (ex[1].value.str == "next_main") {
                    sexpresso::Sexp &scope = ex[2];
                    for (sexpresso::Sexp &e: scope.arguments()) {
                        if (e[1].str() == "Int") {
                            if (std::find(preVars.begin(), preVars.end(), e[0].str()) == preVars.end()) {
                                vars.emplace(e[0].str(), NumVar::next());
                                postVars.push_back(e[0].str());
                            }
                        }
                    }
                    assert(preVars.size() == postVars.size());
                    sexpresso::Sexp ruleExps = ex[4];
                    std::set<NumVar> tmpVars;
                    for (const std::string &str: postVars) {
                        tmpVars.insert(vars.at(str));
                    }
                    const auto cost_var = res.getCostVar();
                    for (auto &ruleExp: ruleExps.arguments()) {
                        if (ruleExp[0].str() == "cfg_trans2") {
                            LocationIdx from = locations[ruleExp[2].str()];
                            LocationIdx to = locations[ruleExp[4].str()];
                            Subs update;
                            Conjunction<IntTheory> guard;
                            parseCond(ruleExp[5], guard);
                            guard.push_back(Rel::buildEq(NumVar::loc_var, from));
                            BoolExpr cond = boolExpression::transform(BoolExpression<IntTheory>::buildAndFromLits(guard));
                            for (unsigned int i = 0; i < preVars.size(); i++) {
                                update.put<IntTheory>(vars.at(preVars[i]), vars.at(postVars[i]));
                            }
                            update.put<IntTheory>(NumVar::loc_var, to);
                            if (Config::Analysis::complexity()) {
                                update.put(cost_var, Expr(cost_var) + 1);
                            }
                            Rule rule(cond, update);
                            // make sure that the temporary variables are unique
                            std::set<NumVar> currTmpVars(tmpVars);
                            cond->collectVars<IntTheory>(currTmpVars);
                            Subs subs;
                            for (const NumVar &var: currTmpVars) {
                                if (var.isTempVar()) {
                                    subs.get<IntTheory>().put(var, NumVar::next());
                                }
                            }
                            res.addRule(rule.subs(subs), from);
                        }
                    }
                }
            }
        }
    }

    void Self::parseCond(sexpresso::Sexp &sexp, Conjunction<IntTheory> &guard) {
        if (sexp.isString()) {
            if (sexp.str() == "false") {
                guard.push_back(Rel(0, Rel::lt, 0));
            } else {
                assert(sexp.str() == "true");
                return;
            }
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
                vars.emplace(varName, NumVar::next());
            }
            parseCond(sexp[2], guard);
        } else {
            guard.push_back(parseConstraint(sexp, false));
        }

    }

    Rel Self::parseConstraint(sexpresso::Sexp &sexp, bool negate) {
        if (sexp.childCount() == 2) {
            assert(sexp[0].str() == "not");
            return parseConstraint(sexp[1], !negate);
        }
        assert(sexp.childCount() == 3);
        const std::string &op = sexp[0].str();
        const Expr &fst = parseExpression(sexp[1]);
        const Expr &snd = parseExpression(sexp[2]);
        if (op == "<=") {
            return negate ? Rel::buildGt(fst, snd) : Rel::buildLeq(fst, snd);
        } else if (sexp[0].str() == "<") {
            return negate ? Rel::buildGeq(fst, snd) : Rel::buildLt(fst, snd);
        } else if (sexp[0].str() == ">=") {
            return negate ? Rel::buildLt(fst, snd) : Rel::buildGeq(fst, snd);
        } else if (sexp[0].str() == ">") {
            return negate ? Rel::buildLeq(fst, snd) : Rel::buildGt(fst, snd);
        } else if (sexp[0].str() == "=") {
            assert(!negate);
            return Rel::buildEq(fst, snd);
        }
        throw std::invalid_argument("");
    }

    Expr Self::parseExpression(sexpresso::Sexp &sexp) {
        if (sexp.childCount() == 1) {
            const std::string &str = sexp.str();
            if (std::isdigit(str[0]) || str[0] == '-') {
                GiNaC::parser parser;
                return Expr(parser(str));
            } else {
                if (vars.find(str) == vars.end()) {
                    vars.emplace(str, NumVar::next());
                }
                return vars.at(str);
            }
        }
        const std::string &op = sexp[0].str();
        const Expr &fst = parseExpression(sexp[1]);
        if (sexp.childCount() == 3) {
            const Expr &snd = parseExpression(sexp[2]);
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
