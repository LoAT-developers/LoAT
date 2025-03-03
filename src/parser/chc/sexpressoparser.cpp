#include "sexpressoparser.hpp"

#include <fstream>

CHCPtr SexpressoParser::loadFromFile(const std::string &filename) {
    SexpressoParser parser;
    parser.run(filename);
    return parser.chcs;
}

bool isInt(const std::string &s) {
    return !s.empty() && (s[0] == '-' || std::isdigit(s[0])) && std::all_of(std::next(s.begin()), s.end(), ::isdigit);
}

Bools::Expr parseBoolExpr(sexpresso::Sexp &exp, const std::unordered_map<std::string, Var> &vars, std::vector<Bools::Expr> &refinement, std::vector<std::unordered_map<std::string, Expr>> &bindings);

Arith::Expr parseArithExpr(sexpresso::Sexp &exp, const std::unordered_map<std::string, Var> &vars, std::vector<Bools::Expr> &refinement, std::vector<std::unordered_map<std::string, Expr>> &bindings) {
    if (exp.isString()) {
        const auto name {exp.str()};
        if (isInt(name)) {
            return arith::mkConst(Int(name));
        } else {
            for (int i = bindings.size() - 1; i >= 0; i--) {
                const auto it {bindings[i].find(name)};
                if (it != bindings[i].end()) {
                    return std::get<Arith::Expr>(it->second);
                }
            }
            return std::get<Arith::Var>(vars.at(name));
        }
    } else {
        const auto name {exp[0].str()};
        if (name == "ite") {
            const auto r{parseBoolExpr(exp[1], vars, refinement, bindings)};
            const auto then_case{parseArithExpr(exp[2], vars, refinement, bindings)};
            const auto else_case{parseArithExpr(exp[3], vars, refinement, bindings)};
            const auto var {ArithVar::next(0)};
            refinement.emplace_back((r && bools::mkLit(arith::mkEq(var, then_case))) || ((!r) && bools::mkLit(arith::mkEq(var, else_case))));
            return var;
        } else if (name == "let") {
            auto declarations{exp[1]};
            std::unordered_map<std::string, Expr> newBindings;
            for (unsigned i = 0; i < declarations.childCount(); ++i) {
                auto decl{declarations[i]};
                const auto declName{decl[0].str()};
                newBindings.emplace(declName, parseArithExpr(decl[1], vars, refinement, bindings));
            }
            bindings.push_back(newBindings);
            auto res{parseArithExpr(exp[2], vars, refinement, bindings)};
            bindings.pop_back();
            return res;
        } else if (name == "+") {
            std::vector<Arith::Expr> args;
            for (unsigned i = 1; i < exp.childCount(); ++i) {
                args.push_back(parseArithExpr(exp[i], vars, refinement, bindings));
            }
            return arith::mkPlus(std::move(args));
        } else if (name == "*") {
            std::vector<Arith::Expr> args;
            for (unsigned i = 1; i < exp.childCount(); ++i) {
                args.push_back(parseArithExpr(exp[i], vars, refinement, bindings));
            }
            return arith::mkTimes(std::move(args));
        } else if (name == "-") {
            if (exp.childCount() == 2) {
                // unary minus
                return -parseArithExpr(exp[1], vars, refinement, bindings);
            } else {
                std::vector<Arith::Expr> args;
                args.push_back(parseArithExpr(exp[1], vars, refinement, bindings));
                for (unsigned i = 2; i < exp.childCount(); ++i) {
                    args.push_back(-parseArithExpr(exp[i], vars, refinement, bindings));
                }
                return arith::mkPlus(std::move(args));
            }
        } else if (name == "mod" || name == "div") {
            const auto fst {parseArithExpr(exp[1], vars, refinement, bindings)};
            const auto snd {parseArithExpr(exp[2], vars, refinement, bindings)};
            const auto div {ArithVar::next(0)};
            const auto mod {ArithVar::next(0)};
            std::vector<Bools::Expr> constr;
            constr.push_back(theory::mkEq(fst, snd * div + mod));
            constr.push_back(theory::mkNeq(snd, arith::mkConst(0)));
            bool explicit_encoding = false;
            const auto y {snd->isInt()};
            if (y) {
                if (*y > 0 && *y <= 10) {
                    explicit_encoding = true;
                    std::vector<Bools::Expr> refinement;
                    for (int i = 0; i < *y; i++) {
                        refinement.push_back(theory::mkEq(mod, arith::mkConst(i)));
                    }
                    constr.push_back(bools::mkOr(refinement));
                }
            }
            if (!explicit_encoding) {
                constr.push_back(bools::mkLit(arith::mkGeq(mod, arith::mkConst(0)))); // x mod y is non-negative
                constr.push_back( // |y| > x mod y
                    bools::mkAndFromLits({arith::mkGt(snd, arith::mkConst(0)), arith::mkGt(snd, mod)})
                    || bools::mkAndFromLits({arith::mkLt(snd, arith::mkConst(0)), arith::mkGt(-snd, mod)}));
            }
            refinement.emplace_back(bools::mkAnd(constr));
            if (name == "div") {
                return Arith::varToExpr(div);
            } else {
                return Arith::varToExpr(mod);
            }
        } else {
            throw std::invalid_argument("unknown operator " + name);
        }
    }
}

std::string getType(sexpresso::Sexp &exp, const std::unordered_map<std::string, Var> &vars, std::vector<std::unordered_map<std::string, Expr>> &bindings) {
    auto child{exp};
    while (!child.isString() && (child[0].str() == "ite" || child[0].str() == "let")) {
        child = child[2];
    }
    std::vector<Expr> args;
    if (child.isString()) {
        const auto name{child.str()};
        if (name == "true" || name == "false") {
            return "Bool";
        } else if (isInt(name)) {
            return "Int";
        } else {
            if (vars.find(name) != vars.end()) {
                const Var var{vars.at(name)};
                return theory::apply(
                    var,
                    [](const Arith::Var &) {
                        return "Int";
                    },
                    [&](const Bools::Var &) {
                        return "Bool";
                    });
            }
            for (int i = bindings.size() - 1; i >= 0; i--) {
                const auto it {bindings[i].find(name)};
                if (it != bindings[i].end()) {
                    return theory::apply(
                        it->second,
                        [](const Arith::Expr &) {
                            return "Int";
                        },
                        [](const Bools::Expr &) {
                            return "Bool";
                        });
                }
            }
            throw std::invalid_argument("unknown symbol " + name);
        }
    } else if (const auto name = child[0].str(); name == "and" || name == "or" || name == "not" || name == "<" || name == "<=" || name == ">" || name == ">=" || name == "=" || name == "distinct") {
        return "Bool";
    } else {
        return "Int";
    }
}

Expr parseExpr(sexpresso::Sexp &exp, const std::unordered_map<std::string, Var> &vars, std::vector<Bools::Expr> &refinement, std::vector<std::unordered_map<std::string, Expr>> &bindings) {
    const auto type{getType(exp, vars, bindings)};
    if (type == "Int") {
        return parseArithExpr(exp, vars, refinement, bindings);
    } else {
        return parseBoolExpr(exp, vars, refinement, bindings);
    }
}

Bools::Expr parseBoolExpr(sexpresso::Sexp &exp, const std::unordered_map<std::string, Var> &vars, std::vector<Bools::Expr> &refinement, std::vector<std::unordered_map<std::string, Expr>> &bindings) {
    if (exp.isString()) {
        const auto name {exp.str()};
        if (name == "true") {
            return top();
        } else if (name == "false") {
            return bot();
        } else if (vars.find(name) != vars.end()) {
            const Var var {vars.at(name)};
            return bools::mkLit(bools::mk(std::get<Bools::Var>(var)));
        } else {
            for (int i = bindings.size() - 1; i >= 0; i--) {
                const auto it {bindings[i].find(name)};
                if (it != bindings[i].end()) {
                    return std::get<Bools::Expr>(it->second);
                }
            }
            throw std::invalid_argument("unknwon bool expression");
        }
    }
    const auto f {exp[0].str()};
    if (f == "ite") {
        const auto r{parseBoolExpr(exp[1], vars, refinement, bindings)};
        const auto then_case{parseBoolExpr(exp[2], vars, refinement, bindings)};
        const auto else_case{parseBoolExpr(exp[3], vars, refinement, bindings)};
        return (r && then_case) || ((!r) && else_case);
    } else if (f == "let") {
        auto declarations {exp[1]};
        std::unordered_map<std::string, Expr> newBindings;
        for (unsigned i = 0; i < declarations.childCount(); ++i) {
            auto decl {declarations[i]};
            const auto declName {decl[0].str()};
            newBindings.emplace(declName, parseExpr(decl[1], vars, refinement, bindings));
        }
        bindings.push_back(newBindings);
        auto res {parseBoolExpr(exp[2], vars, refinement, bindings)};
        bindings.pop_back();
        return res;
    } else if (f == "and") {
        std::vector<Bools::Expr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            args.push_back(parseBoolExpr(exp[i], vars, refinement, bindings));
        }
        return bools::mkAnd(args);
    } else if (f == "or") {
        std::vector<Bools::Expr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            args.push_back(parseBoolExpr(exp[i], vars, refinement, bindings));
        }
        return bools::mkOr(args);
    } else if (f == "not") {
        return !parseBoolExpr(exp[1], vars, refinement, bindings);
    } else if (f == "<" || f == "<=" || f == ">" || f == ">=") {
        std::vector<Arith::Expr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            args.push_back(parseArithExpr(exp[i], vars, refinement, bindings));
        }
        LitSet lits;
        for (unsigned i = 1; i < args.size(); ++i) {
            if (f == "<") {
                lits.insert(arith::mkLt(args[i-1], args[i]));
            } else if (f == "<=") {
                lits.insert(arith::mkLeq(args[i-1], args[i]));
            } else if (f == ">") {
                lits.insert(arith::mkGt(args[i-1], args[i]));
            } else if (f == ">=") {
                lits.insert(arith::mkGeq(args[i-1], args[i]));
            }
        }
        return bools::mkAndFromLits(lits);
    } else if (f == "=" || f == "distinct") {
        std::string type {getType(exp[1], vars, bindings)};
        std::vector<Expr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            if (type == "Int") {
                args.push_back(parseArithExpr(exp[i], vars, refinement, bindings));
            } else {
                args.push_back(parseBoolExpr(exp[i], vars, refinement, bindings));
            }
        }
        std::vector<Bools::Expr> lits;
        if (f == "=") {
            for (unsigned i = 1; i < args.size(); ++i) {
                lits.push_back(theory::mkEq(args[i - 1], args[i]));
            }
        } else {
            for (unsigned i = 0; i < args.size() - 1; ++i) {
                for (unsigned j = i + 1; j < args.size(); ++j) {
                    lits.push_back(theory::mkNeq(args[i], args[j]));
                }
            }
        }
        return bools::mkAnd(lits);
    } else {
        throw std::invalid_argument("unknwon bool expression");
    }
}

FunAppPtr parsePred(sexpresso::Sexp &exp, const std::unordered_map<std::string, Var> &vars, std::vector<Bools::Expr> &refinement, std::vector<std::unordered_map<std::string, Expr>> &bindings) {
    std::vector<Expr> args;
    if (exp.isString()) {
        return FunApp::mk(exp.str(), args);
    }
    for (unsigned i = 1; i < exp.childCount(); ++i) {
        args.push_back(parseExpr(exp[i], vars, refinement, bindings));
    }
    return FunApp::mk(exp[0].str(), args);
}

std::optional<FunAppPtr> parseTopLevelBoolExpr(sexpresso::Sexp &exp, const std::unordered_map<std::string, Var> &vars, std::vector<Bools::Expr> &result, std::vector<std::unordered_map<std::string, Expr>> &bindings) {
    if (exp.isString()) {
        const auto name {exp.str()};
        if (name == "true" || name == "false" || vars.find(name) != vars.end() || std::any_of(bindings.rbegin(), bindings.rend(), [&](const auto &b) {
            return b.contains(name);
        })) {
            result.emplace_back(parseBoolExpr(exp, vars, result, bindings));
            return {};
        } else {
            return parsePred(exp, vars, result, bindings);
        }
    }
    const auto f {exp[0].str()};
    if (f == "and") {
        std::optional<FunAppPtr> lhs;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            const auto l {parseTopLevelBoolExpr(exp[i], vars, result, bindings)};
            if (l) {
                assert(!lhs);
                lhs = l;
            }
        }
        return lhs;
    } else if (f == "ite" || f == "let" || f == "or" || f == "not" || f == "<" || f == "<=" || f == ">" || f == ">=" || f == "=" || f == "distinct") {
        result.emplace_back(parseBoolExpr(exp, vars, result, bindings));
        return {};
    } else {
        return parsePred(exp, vars, result, bindings);
    }
}

void SexpressoParser::run(const std::string &filename) {
    std::ifstream ifs(filename);
    std::string content(
        (std::istreambuf_iterator<char>(ifs)),
        (std::istreambuf_iterator<char>()));
    sexpresso::Sexp sexp = sexpresso::parse(content);
    for (auto &ex: sexp.arguments()) {
        if (ex[0].isString("assert")) {
            std::unordered_map<std::string, Var> var_map;
            sexpresso::Sexp imp;
            if (ex[1].childCount() > 0 && ex[1][0].isString("forall")) {
                auto vars {ex[1][1]};
                for (unsigned i = 0; i < vars.childCount(); ++i) {
                    const auto name {vars[i][0].str()};
                    const auto type {vars[i][1].str()};
                    if (type == "Int") {
                        var_map.emplace(name, ArithVar::next(0));
                    } else if (type == "Bool") {
                        var_map.emplace(name, Bools::next(0));
                    } else {
                        throw std::invalid_argument("unknown type " + type);
                    }
                }
                imp = ex[1][2];
            } else {
                imp = ex[1];
            }
            std::vector<std::unordered_map<std::string, Expr>> bindings;
            std::vector<Bools::Expr> constraints;
            std::optional<FunAppPtr> premise, conclusion;
            sexpresso::Sexp conc;
            if (imp[0].isString("=>")) {
                premise = parseTopLevelBoolExpr(imp[1], var_map, constraints, bindings);
                conc = imp[2];
            } else {
                conc = imp[0];
            }
            if (!conc.isString("false")) {
                conclusion = parsePred(conc, var_map, constraints, bindings);
            }
            chcs->add_clause(Clause::mk(premise, bools::mkAnd(constraints), conclusion));
        }
    }
}
