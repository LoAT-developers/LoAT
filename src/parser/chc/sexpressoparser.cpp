#include "sexpressoparser.hpp"
#include "smtlibutil.hpp"

#include <fstream>

CHCPtr SexpressoParser::loadFromFile(const std::string &filename) {
    SexpressoParser parser;
    parser.run(filename);
    return parser.chcs;
}

FunAppPtr parsePred(sexpresso::Sexp &exp, SMTLibParsingState &state) {
    std::vector<Expr> args;
    if (exp.isString()) {
        return FunApp::mk(exp.str(), args);
    }
    for (unsigned i = 1; i < exp.childCount(); ++i) {
        args.push_back(parseExpr(exp[i], state));
    }
    return FunApp::mk(exp[0].str(), args);
}

std::optional<FunAppPtr> parseTopLevelBoolExpr(sexpresso::Sexp &exp, SMTLibParsingState &state) {
    if (exp.isString()) {
        const auto name {exp.str()};
        if (name == "true" || name == "false" || state.vars.find(name) != state.vars.end() || std::any_of(state.bindings.rbegin(), state.bindings.rend(), [&](const auto &b) {
            return b.contains(name);
        })) {
            state.refinement.emplace_back(parseBoolExpr(exp, state));
            return {};
        } else {
            return parsePred(exp, state);
        }
    }
    const auto f {exp[0].str()};
    if (f == "and") {
        std::optional<FunAppPtr> lhs;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            const auto l {parseTopLevelBoolExpr(exp[i], state)};
            if (l) {
                assert(!lhs);
                lhs = l;
            }
        }
        return lhs;
    } else if (f == "ite" || f == "let" || f == "or" || f == "not" || f == "<" || f == "<=" || f == ">" || f == ">=" || f == "=" || f == "distinct") {
        state.refinement.emplace_back(parseBoolExpr(exp, state));
        return {};
    } else {
        return parsePred(exp, state);
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
            SMTLibParsingState state;
            sexpresso::Sexp imp;
            if (ex[1].childCount() > 0 && ex[1][0].isString("forall")) {
                auto vars {ex[1][1]};
                for (unsigned i = 0; i < vars.childCount(); ++i) {
                    const auto name {vars[i][0].str()};
                    const auto type {vars[i][1].str()};
                    if (type == "Int") {
                        state.vars.emplace(name, ArithVar::next());
                    } else if (type == "Bool") {
                        state.vars.emplace(name, Bools::next());
                    } else {
                        throw std::invalid_argument("unknown type " + type);
                    }
                }
                imp = ex[1][2];
            } else {
                imp = ex[1];
            }
            std::optional<FunAppPtr> premise, conclusion;
            sexpresso::Sexp conc;
            if (imp[0].isString("=>")) {
                premise = parseTopLevelBoolExpr(imp[1], state);
                conc = imp[2];
            } else {
                conc = imp[0];
            }
            if (!conc.isString("false")) {
                conclusion = parsePred(conc, state);
            }
            chcs->add_clause(Clause::mk(premise, bools::mkAnd(state.refinement), conclusion));
        }
    }
}
