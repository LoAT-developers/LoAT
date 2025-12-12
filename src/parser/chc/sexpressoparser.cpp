#include "sexpressoparser.hpp"
#include "smtlibutil.hpp"

#include <fstream>
#include <boost/algorithm/string/split.hpp>

CHCPtr SexpressoParser::loadFromFile(const std::string &filename) {
    SexpressoParser parser;
    parser.run(filename);
    return parser.chcs;
}

std::pair<std::vector<FunAppPtr>, Bools::Expr> parsePred(sexpresso::Sexp &exp, SMTLibParsingState &state, const std::unordered_map<std::string, std::pair<std::vector<FunAppPtr>, Bools::Expr>>& predicate_bindings) {
    std::vector<Expr> args;
    if (exp.isString()) {
        const auto it = predicate_bindings.find(exp.str());
        if (it == predicate_bindings.end()) {
            return {std::vector{FunApp::mk(exp.str(), args)}, top()};
        }
        return it->second;
    }
    for (unsigned i = 1; i < exp.childCount(); ++i) {
        args.push_back(parseExpr(exp[i], state));
    }
    const auto res = FunApp::mk(exp[0].str(), args);
    return {std::vector{res}, top()};
}

std::pair<std::vector<FunAppPtr>, Bools::Expr> parseTopLevelBoolExpr(sexpresso::Sexp &exp, SMTLibParsingState &state, std::unordered_map<std::string, std::pair<std::vector<FunAppPtr>, Bools::Expr>>& predicate_bindings) {
    std::vector<FunAppPtr> args;
    if (exp.isString()) {
        // get_type returns a value iff the given name has been declared as a variable, or if there is a binding for it
        if (const auto name {exp.str()}; name == "true" || name == "false" || state.get_type(name)) {
            return {args, parseBoolExpr(exp, state)};
        }
        return parsePred(exp, state, predicate_bindings);
    }
    if (const auto f {exp[0].str()}; f == "and") {
        std::vector<Bools::Expr> conds;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            const auto [l,cond] {parseTopLevelBoolExpr(exp[i], state, predicate_bindings)};
            args.insert(args.end(), l.begin(), l.end());
            conds.emplace_back(cond);
        }
        return {args, bools::mkAnd(conds)};
    } else {
        if (f == "let") {
            auto decls = exp[1];
            for (unsigned i = 0; i < decls.childCount(); ++i) {
                const auto name = decls[i][0].str();
                auto def = decls[i][1];
                if (const auto [p, cond] = parseTopLevelBoolExpr(def, state, predicate_bindings); !p.empty()) {
                    predicate_bindings.emplace(name, std::pair(p, cond));
                } else {
                    state.add_binding(name, cond);
                }
            }
            return parseTopLevelBoolExpr(exp[2], state, predicate_bindings);
        }
        if (f == "ite" || f == "or" || f == "not" || f == "=>" || f == "<" || f == "<=" || f == ">" || f == ">=" || f == "=" || f == "distinct") {
            return {args, parseBoolExpr(exp, state)};
        }
        return parsePred(exp, state, predicate_bindings);
    }
}

theory::Type parse_type(sexpresso::Sexp& type) {
    if (type.isString()) {
        if (type.str() == "Int") {
            return theory::Type::Int;
        }
        if (type.str() == "Bool") {
            return theory::Type::Bool;
        }
        throw std::invalid_argument("unknown type");
    }
    if (type[0].isString("Array")
        && type[1].isString("Int")
        && type[2].isString("Int")) {
        return theory::Type::IntArray;
    }
    throw std::invalid_argument("unknown type " + type.toString());
}

void SexpressoParser::run(const std::string &filename) {
    std::ifstream ifs(filename);
    std::string content(
        (std::istreambuf_iterator(ifs)),
        (std::istreambuf_iterator<char>()));
    for (sexpresso::Sexp sexp = sexpresso::parse(content); auto &ex: sexp.arguments()) {
        if (ex[0].isString("assert")) {
            state.push();
            std::unordered_map<std::string, std::pair<std::vector<FunAppPtr>, Bools::Expr>> predicate_bindings;
            sexpresso::Sexp clause = ex[1];
            while (clause[0].isString("forall") || clause[0].isString("let") || clause[0].isString("!")) {
                if (clause[0].isString("forall")) {
                    auto vars = clause[1];
                    for (unsigned i = 0; i < vars.childCount(); ++i) {
                        state.create_var(vars[i][0].str(), parse_type(vars[i][1]), true);
                    }
                    clause = clause[2];
                } else if (clause[0].isString("let")) {
                    auto decls = clause[1];
                    for (unsigned i = 0; i < decls.childCount(); ++i) {
                        const auto name = decls[i][0].str();
                        auto def = decls[i][1];
                        if (const auto [p, cond] = parseTopLevelBoolExpr(def, state, predicate_bindings); !p.empty()) {
                            predicate_bindings.emplace(name, std::pair(p, cond));
                        } else {
                            state.add_binding(name, cond);
                        }
                    }
                    clause = clause[2];
                } else {
                    assert(clause[0].isString("!"));
                    const auto child = clause[1];
                    clause = child;
                }
            }
            std::vector<FunAppPtr> premise;
            std::optional<FunAppPtr> conclusion;
            sexpresso::Sexp conc;
            if (clause[0].isString("=>")) {
                const auto [pred, cond] = parseTopLevelBoolExpr(clause[1], state, predicate_bindings);
                premise = pred;
                state.add_refinement(cond);
                conc = clause[2];
            } else if (clause[0].isString("not")) {
                const auto [pred, cond] = parseTopLevelBoolExpr(clause[1], state, predicate_bindings);
                premise = pred;
                state.add_refinement(cond);
                conc = sexpresso::Sexp("false");
            } else {
                conc = clause;
            }
            if (!conc.isString("false")) {
                const auto [p, cond] = parsePred(conc, state, predicate_bindings);
                assert(cond == top());
                assert(p.size() == 1);
                conclusion = p.front();
            }
            const auto res = Clause::mk(premise, state.refinement(), conclusion);
            chcs->add_clause(res);
            state.pop();
        }
    }
}
