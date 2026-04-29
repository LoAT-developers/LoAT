#include "sexpressoparser.hpp"
#include "smtlibutil.hpp"

#include <fstream>
#include <boost/algorithm/string/split.hpp>

CHCPtr SexpressoParser::loadFromFile(const std::string &filename) {
    SexpressoParser parser;
    parser.run(filename);
    return parser.chcs;
}

FunAppPtr parsePred(const sexpresso::Sexp &exp, SMTLibParsingState &state) {
    std::vector<Expr> args;
    if (exp.isString()) {
        return FunApp::mk(exp.str(), args);
    }
    for (unsigned i = 1; i < exp.childCount(); ++i) {
        args.push_back(parseExpr(exp[i], state));
    }
    return FunApp::mk(exp[0].str(), args);
}

std::vector<FunAppPtr> parseTopLevelBoolExpr(const sexpresso::Sexp &exp, SMTLibParsingState &state) {
    if (exp.isString()) {
        // get_type returns a value iff the given name has been declared as a variable, or if there is a binding for it
        if (const auto name {exp.str()}; name == "true" || name == "false" || state.get_type(name)) {
            state.add_refinement(parseBoolExpr(exp, state));
            return {};
        }
        return std::vector{parsePred(exp, state)};
    }
    if (const auto f {exp[0].str()}; f == "and") {
        std::vector<FunAppPtr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            const auto l {parseTopLevelBoolExpr(exp[i], state)};
            args.insert(args.end(), l.begin(), l.end());
            if (args.size() > 1) {
                std::cerr << exp.toString() << std::endl;
                throw std::invalid_argument("LoAT cannot handle non-linear clauses");
            }
        }
        return args;
    } else {
        if (f == "let" || f == "ite" || f == "or" || f == "not" || f == "=>" || f == "<" || f == "<=" || f == ">" || f == ">=" || f == "=" || f == "distinct") {
            state.add_refinement(parseBoolExpr(exp, state));
            return {};
        }
        return std::vector{parsePred(exp, state)};
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
        && type[1].isString("Int")) {
        switch (const auto& [base, dim] = parse_type(type[2]); base) {
        case theory::BaseType::Int: {
            return theory::Type(base, dim + 1);
        }
        case theory::BaseType::Bool: ; // do nothing
        }
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
            sexpresso::Sexp clause = ex[1];
            while (clause[0].isString("forall")) {
                auto vars = clause[1];
                for (unsigned i = 0; i < vars.childCount(); ++i) {
                    const auto t = parse_type(vars[i][1]);
                    state.create_var(vars[i][0].str(), t, true);
                }
                clause = clause[2];
            }
            std::vector<FunAppPtr> premise;
            std::optional<FunAppPtr> conclusion;
            sexpresso::Sexp conc;
            if (clause[0].isString("=>")) {
                premise = parseTopLevelBoolExpr(clause[1], state);
                conc = clause[2];
            } else if (clause[0].isString("not")) {
                premise = parseTopLevelBoolExpr(clause[1], state);
                conc = sexpresso::Sexp("false");
            } else {
                conc = clause;
            }
            if (!conc.isString("false")) {
                conclusion = parsePred(conc, state);
            }
            const auto res = Clause::mk(premise, state.refinement(), conclusion);
            chcs->add_clause(res);
            state.pop();
        }
    }
}
