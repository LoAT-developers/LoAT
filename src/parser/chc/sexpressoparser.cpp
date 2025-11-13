#include "sexpressoparser.hpp"
#include "smtlibutil.hpp"

#include <fstream>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/trim.hpp>

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
        if (const auto name {exp.str()}; name == "true" || name == "false" || state.vars.contains(name) || std::any_of(state.bindings.rbegin(), state.bindings.rend(), [&](const auto &b) {
            return b.contains(name);
        })) {
            state.refinement.emplace_back(parseBoolExpr(exp, state));
            return {};
        }
        return parsePred(exp, state);
    }
    if (const auto f {exp[0].str()}; f == "and") {
        std::optional<FunAppPtr> lhs;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            if (const auto l {parseTopLevelBoolExpr(exp[i], state)}) {
                assert(!lhs);
                lhs = l;
            }
        }
        return lhs;
    } else {
        if (f == "ite" || f == "let" || f == "or" || f == "not" || f == "<" || f == "<=" || f == ">" || f == ">=" || f == "=" || f == "distinct") {
            state.refinement.emplace_back(parseBoolExpr(exp, state));
            return {};
        }
        return parsePred(exp, state);
    }
}

void SexpressoParser::run(const std::string &filename) const {
    std::ifstream ifs(filename);
    std::string content(
        (std::istreambuf_iterator(ifs)),
        (std::istreambuf_iterator<char>()));
    sexpresso::Sexp sexp = sexpresso::parse(content);
    SMTLibParsingState state;
    for (auto &ex: sexp.arguments()) {
        if (ex[0].isString("assert")) {
            sexpresso::Sexp imp;
            if (ex[1].childCount() > 0 && ex[1][0].isString("forall")) {
                auto vars {ex[1][1]};
                for (unsigned i = 0; i < vars.childCount(); ++i) {
                    const auto name = vars[i][0].str();
                    auto type = vars[i][1];
                    if (type.isString()) {
                        if (type.str() == "Int") {
                            state.vars.emplace(name, ArrayVar<Arith>::next(0));
                            continue;
                        }
                        if (type.str() == "Bool") {
                            state.vars.emplace(name, BoolVar::next());
                            continue;
                        }
                    } else if (type[0].isString()
                        && type[0].str() == "Array"
                        && type[1].isString()
                        && type[1].str() == "Int"
                        && type[2].isString()
                        && type[2].str() == "Int") {
                        state.vars.emplace(name, ArrayVar<Arith>::next(1));
                        continue;
                    }
                    throw std::invalid_argument("unknown type " + type.toString());
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
            state.clear();
        }
    }
}
