#include "sexpressoparser.hpp"

#include <fstream>

CHCProblem SexpressoParser::loadFromFile(const std::string &filename) {
    SexpressoParser parser;
    parser.run(filename);
    return parser.chcs;
}

FunApp parsePred(sexpresso::Sexp &exp, Clause &c) {
    const auto &vars {c.get_vars()};
    std::vector<Var> args;
    if (exp.isString()) {
        return FunApp(exp.str(), args);
    }
    for (unsigned i = 1; i < exp.childCount(); ++i) {
        args.push_back(vars.left.at(exp[i].str()));
    }
    return FunApp(exp[0].str(), args);
}

bool isInt(const std::string &s) {
    return !s.empty() && (s[0] == '-' || std::isdigit(s[0])) && std::all_of(std::next(s.begin()), s.end(), ::isdigit);
}

Bools::Expr parseBoolExpr(sexpresso::Sexp &exp, Clause &c, std::vector<std::unordered_map<std::string, Expr>> &bindings);

Arith::Expr parseArithExpr(sexpresso::Sexp &exp, Clause &c, std::vector<std::unordered_map<std::string, Expr>> &bindings) {
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
            return std::get<Arith::Var>(c.get_vars().left.at(name));
        }
    } else {
        const auto name {exp[0].str()};
        if (name == "ite") {
            const auto r{parseBoolExpr(exp[1], c, bindings)};
            const auto then_case{parseArithExpr(exp[2], c, bindings)};
            const auto else_case{parseArithExpr(exp[3], c, bindings)};
            const auto var {ArithVar::next()};
            c.add_constraint((r && bools::mkLit(arith::mkEq(var, then_case))) || ((!r) && bools::mkLit(arith::mkEq(var, else_case))));
            return var;
        } else if (name == "let") {
            auto declarations{exp[1]};
            std::unordered_map<std::string, Expr> newBindings;
            for (unsigned i = 0; i < declarations.childCount(); ++i) {
                auto decl{declarations[i]};
                const auto declName{decl[0].str()};
                newBindings.emplace(declName, parseArithExpr(decl[1], c, bindings));
            }
            bindings.push_back(newBindings);
            auto res{parseArithExpr(exp[2], c, bindings)};
            bindings.pop_back();
            return res;
        } else if (name == "+") {
            std::vector<Arith::Expr> args;
            for (unsigned i = 1; i < exp.childCount(); ++i) {
                args.push_back(parseArithExpr(exp[i], c, bindings));
            }
            return arith::mkPlus(std::move(args));
        } else if (name == "*") {
            std::vector<Arith::Expr> args;
            for (unsigned i = 1; i < exp.childCount(); ++i) {
                args.push_back(parseArithExpr(exp[i], c, bindings));
            }
            return arith::mkTimes(std::move(args));
        } else if (name == "-") {
            if (exp.childCount() == 2) {
                // unary minus
                return -parseArithExpr(exp[1], c, bindings);
            } else {
                std::vector<Arith::Expr> args;
                args.push_back(parseArithExpr(exp[1], c, bindings));
                for (unsigned i = 2; i < exp.childCount(); ++i) {
                    args.push_back(-parseArithExpr(exp[i], c, bindings));
                }
                return arith::mkPlus(std::move(args));
            }
        } else if (name == "mod" || name == "div") {
            const auto fst {parseArithExpr(exp[1], c, bindings)};
            const auto snd {parseArithExpr(exp[2], c, bindings)};
            const auto div {ArithVar::next()};
            const auto mod {ArithVar::next()};
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
            c.add_constraint(bools::mkAnd(constr));
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

std::string getType(sexpresso::Sexp &exp, Clause &c, std::vector<std::unordered_map<std::string, Expr>> &bindings) {
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
            const auto &vars{c.get_vars().left};
            if (vars.find(name) != vars.end()) {
                const Var var{vars.at(name)};
                return std::visit(
                    Overload{
                        [](const Arith::Var &) {
                            return "Int";
                        },
                        [&](const Bools::Var &) {
                            return "Bool";
                        }},
                    var);
            }
            for (int i = bindings.size() - 1; i >= 0; i--) {
                const auto it {bindings[i].find(name)};
                if (it != bindings[i].end()) {
                    return std::visit(
                        Overload{
                            [](const Arith::Expr&) {
                                return "Int";
                            },
                            [](const Bools::Expr&) {
                                return "Bool";
                            }
                        }, it->second
                    );
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

Bools::Expr parseBoolExpr(sexpresso::Sexp &exp, Clause &c, std::vector<std::unordered_map<std::string, Expr>> &bindings) {
    const auto &vars{c.get_vars().left};
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
            c.set_premise(parsePred(exp, c));
            return top();
        }
    }
    const auto f {exp[0].str()};
    if (f == "ite") {
        const auto r{parseBoolExpr(exp[1], c, bindings)};
        const auto then_case{parseBoolExpr(exp[2], c, bindings)};
        const auto else_case{parseBoolExpr(exp[3], c, bindings)};
        return (r && then_case) || ((!r) && else_case);
    } else if (f == "let") {
        auto declarations {exp[1]};
        std::unordered_map<std::string, Expr> newBindings;
        for (unsigned i = 0; i < declarations.childCount(); ++i) {
            auto decl {declarations[i]};
            const auto declName {decl[0].str()};
            const auto type {getType(decl[1], c, bindings)};
            if (type == "Int") {
                newBindings.emplace(declName, parseArithExpr(decl[1], c, bindings));
            } else {
                newBindings.emplace(declName, parseBoolExpr(decl[1], c, bindings));
            }
        }
        bindings.push_back(newBindings);
        auto res {parseBoolExpr(exp[2], c, bindings)};
        bindings.pop_back();
        return res;
    } else if (f == "and") {
        std::vector<Bools::Expr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            args.push_back(parseBoolExpr(exp[i], c, bindings));
        }
        return bools::mkAnd(args);
    } else if (f == "or") {
        std::vector<Bools::Expr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            args.push_back(parseBoolExpr(exp[i], c, bindings));
        }
        return bools::mkOr(args);
    } else if (f == "not") {
        return !parseBoolExpr(exp[1], c, bindings);
    } else if (f == "<" || f == "<=" || f == ">" || f == ">=") {
        std::vector<Arith::Expr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            args.push_back(parseArithExpr(exp[i], c, bindings));
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
        std::string type {getType(exp[1], c, bindings)};
        std::vector<Expr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            if (type == "Int") {
                args.push_back(parseArithExpr(exp[i], c, bindings));
            } else {
                args.push_back(parseBoolExpr(exp[i], c, bindings));
            }
        }
        std::vector<Bools::Expr> lits;
        if (f == "=") {
            for (unsigned i = 1; i < args.size(); ++i) {
                lits.push_back(theory::mkEq(args[i - 1], args[i]));
            }
        } else {
            for (unsigned i = 0; i < args.size() - 1; ++i) {
                for (unsigned j = i + 1; i < args.size(); ++i) {
                    lits.push_back(theory::mkNeq(args[i], args[j]));
                }
            }
        }
        return bools::mkAnd(lits);
    } else {
        c.set_premise(parsePred(exp, c));
        return top();
    }
}

void SexpressoParser::run(const std::string &filename) {
    std::ifstream ifs(filename);
    std::string content(
        (std::istreambuf_iterator<char>(ifs)),
        (std::istreambuf_iterator<char>()));
    sexpresso::Sexp sexp = sexpresso::parse(content);
    for (auto &ex: sexp.arguments()) {
        if (ex[0].str() == "assert") {
            Clause c;
            auto forall {ex[1]};
            auto vars {forall[1]};
            for (unsigned i = 0; i < vars.childCount(); ++i) {
                const auto name {vars[i][0].str()};
                const auto type {vars[i][1].str()};
                if (type == "Int") {
                    c.add_var(name, ArithVar::next());
                } else if (type == "Bool") {
                    c.add_var(name, BoolVar::next());
                } else {
                    throw std::invalid_argument("unknown type " + type);
                }
            }
            auto imp {forall[2]};
            auto premise {imp[1]};
            std::vector<std::unordered_map<std::string, Expr>> bindings;
            const auto constraint {parseBoolExpr(premise, c, bindings)};
            c.add_constraint(constraint);
            auto conclusion {imp[2]};
            if (!conclusion.isString() || conclusion.str() != "false") {
                const auto pred {parsePred(conclusion, c)};
                c.set_conclusion(pred);
            }
            chcs.add_clause(c);
        }
    }
}