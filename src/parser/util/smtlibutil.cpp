#include "smtlibutil.hpp"

bool isInt(const std::string &s) {
    return !s.empty() && (s[0] == '-' || std::isdigit(s[0])) && std::all_of(std::next(s.begin()), s.end(), ::isdigit);
}

Arith::Expr parseArithExpr(sexpresso::Sexp &exp, SMTLibParsingState &state) {
    if (exp.isString()) {
        const auto name {exp.str()};
        if (isInt(name)) {
            return arith::mkConst(Int(name));
        } else {
            for (int i = state.bindings.size() - 1; i >= 0; i--) {
                const auto it {state.bindings[i].find(name)};
                if (it != state.bindings[i].end()) {
                    return std::get<Arith::Expr>(it->second);
                }
            }
            auto it {state.vars.find(name)};
            if (it == state.vars.end()) {
                it = state.vars.emplace(name, ArithVar::next()).first;
            }
            return std::get<Arith::Var>(it->second);
        }
    } else {
        const auto name {exp[0].str()};
        if (name == "ite") {
            const auto r{parseBoolExpr(exp[1], state)};
            const auto then_case{parseArithExpr(exp[2], state)};
            const auto else_case{parseArithExpr(exp[3], state)};
            const auto var {ArithVar::next()};
            state.refinement.emplace_back((r && bools::mkLit(arith::mkEq(var, then_case))) || ((!r) && bools::mkLit(arith::mkEq(var, else_case))));
            return var;
        } else if (name == "let") {
            auto declarations{exp[1]};
            std::unordered_map<std::string, Expr> newBindings;
            for (unsigned i = 0; i < declarations.childCount(); ++i) {
                auto decl{declarations[i]};
                const auto declName{decl[0].str()};
                newBindings.emplace(declName, parseArithExpr(decl[1], state));
            }
            state.bindings.push_back(newBindings);
            auto res{parseArithExpr(exp[2], state)};
            state.bindings.pop_back();
            return res;
        } else if (name == "+") {
            std::vector<Arith::Expr> args;
            for (unsigned i = 1; i < exp.childCount(); ++i) {
                args.push_back(parseArithExpr(exp[i], state));
            }
            return arith::mkPlus(std::move(args));
        } else if (name == "*") {
            std::vector<Arith::Expr> args;
            for (unsigned i = 1; i < exp.childCount(); ++i) {
                args.push_back(parseArithExpr(exp[i], state));
            }
            return arith::mkTimes(std::move(args));
        } else if (name == "-") {
            if (exp.childCount() == 2) {
                // unary minus
                return -parseArithExpr(exp[1], state);
            } else {
                std::vector<Arith::Expr> args;
                args.push_back(parseArithExpr(exp[1], state));
                for (unsigned i = 2; i < exp.childCount(); ++i) {
                    args.push_back(-parseArithExpr(exp[i], state));
                }
                return arith::mkPlus(std::move(args));
            }
        } else if (name == "mod" || name == "div") {
            const auto fst {parseArithExpr(exp[1], state)};
            const auto snd {parseArithExpr(exp[2], state)};
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
            state.refinement.emplace_back(bools::mkAnd(constr));
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

std::string getType(sexpresso::Sexp &exp, SMTLibParsingState &state) {
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
            if (state.vars.find(name) != state.vars.end()) {
                const Var var{state.vars.at(name)};
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
            for (int i = state.bindings.size() - 1; i >= 0; i--) {
                const auto it {state.bindings[i].find(name)};
                if (it != state.bindings[i].end()) {
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

Expr parseExpr(sexpresso::Sexp &exp, SMTLibParsingState &state) {
    const auto type{getType(exp, state)};
    if (type == "Int") {
        return parseArithExpr(exp, state);
    } else {
        return parseBoolExpr(exp, state);
    }
}

Bools::Expr parseBoolExpr(sexpresso::Sexp &exp, SMTLibParsingState &state) {
    if (exp.isString()) {
        const auto name {exp.str()};
        if (name == "true") {
            return top();
        } else if (name == "false") {
            return bot();
        } else {
            for (int i = state.bindings.size() - 1; i >= 0; i--) {
                const auto it {state.bindings[i].find(name)};
                if (it != state.bindings[i].end()) {
                    return std::get<Bools::Expr>(it->second);
                }
            }
        }
        auto it{state.vars.find(name)};
        if (it == state.vars.end()) {
            it = state.vars.emplace(name, BoolVar::next()).first;
        }
        return bools::mkLit(bools::mk(std::get<Bools::Var>(it->second)));
    }
    const auto f {exp[0].str()};
    if (f == "ite") {
        const auto r{parseBoolExpr(exp[1], state)};
        const auto then_case{parseBoolExpr(exp[2], state)};
        const auto else_case{parseBoolExpr(exp[3], state)};
        return (r && then_case) || ((!r) && else_case);
    } else if (f == "let") {
        auto declarations {exp[1]};
        std::unordered_map<std::string, Expr> newBindings;
        for (unsigned i = 0; i < declarations.childCount(); ++i) {
            auto decl {declarations[i]};
            const auto declName {decl[0].str()};
            newBindings.emplace(declName, parseExpr(decl[1], state));
        }
        state.bindings.push_back(newBindings);
        auto res {parseBoolExpr(exp[2], state)};
        state.bindings.pop_back();
        return res;
    } else if (f == "exists") {
        const auto res {parseBoolExpr(exp[2], state)};
        const auto num_vars {exp[1].childCount()};
        for (unsigned i = 0; i < num_vars; ++i) {
            const auto var_name {exp[1][i][0].str()};
            assert(state.vars.find(var_name) != state.vars.end());
            state.vars.erase(var_name);
        }
        return res;
    } else if (f == "and") {
        std::vector<Bools::Expr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            args.push_back(parseBoolExpr(exp[i], state));
        }
        return bools::mkAnd(args);
    } else if (f == "or") {
        std::vector<Bools::Expr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            args.push_back(parseBoolExpr(exp[i], state));
        }
        return bools::mkOr(args);
    } else if (f == "not") {
        return !parseBoolExpr(exp[1], state);
    } else if (f == "<" || f == "<=" || f == ">" || f == ">=") {
        std::vector<Arith::Expr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            args.push_back(parseArithExpr(exp[i], state));
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
        std::string type {getType(exp[1], state)};
        std::vector<Expr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            if (type == "Int") {
                args.push_back(parseArithExpr(exp[i], state));
            } else {
                args.push_back(parseBoolExpr(exp[i], state));
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
