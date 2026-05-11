#include "ariparser.hpp"
#include "smtlibutil.hpp"
#include "config.hpp"

#include <fstream>

FunAppPtr ARIParser::parseFunApp(const sexpresso::Sexp& sexp, SMTLibParsingState& state) const {
    const auto loc = sexp.isString() ? sexp.str() : sexp[0].str();
    const auto type {types.at(loc)};
    const auto child_count = sexp.childCount();
    std::vector<Expr> args;
    for (unsigned i = 1; i < child_count; ++i) {
        args.emplace_back(parseExpr(sexp[i], state, type.at(i - 1)));
    }
    return FunApp::mk(loc, args);
}

void ARIParser::run(const std::string &filename) {
    std::ifstream ifs(filename);
    std::string content(
        (std::istreambuf_iterator(ifs)),
        (std::istreambuf_iterator<char>()));
    sexpresso::Sexp sexp = sexpresso::parse(content);
    unsigned max_int_arity {0};
    unsigned max_bool_arity {0};
    SMTLibParsingState state;
    for (auto &ex: sexp.arguments()) {
        if (ex[0].isString("entrypoint")) {
            const auto pred = ex[1].str();
            const auto type {types.at(pred)};
            const auto child_count = type.size();
            std::vector<Expr> args;
            for (unsigned i = 0; i < child_count; ++i) {
                const auto [base,dim] = type.at(i);
                assert(dim == 0);
                const auto name = "x_" + std::to_string(i);
                switch (base) {
                    case theory::BaseType::Int: {
                        args.emplace_back(arrays::readConst(state.get_or_create_arith_var(name, false)));
                        break;
                    }
                    case theory::BaseType::Bool: {
                        args.emplace_back(Bools::varToExpr(state.get_or_create_bool_var(name, false)));
                        break;
                    }
                }
            }
            const auto rhs = FunApp::mk(pred, args);
            const auto c = Clause::mk({}, top(), arith::zero(), rhs);
            its->add_clause(c);
        } else if (ex[0].isString("fun")) {
            const auto fun {ex[1].str()};
            const auto& type {ex[2]};
            const auto child_count {type.childCount()};
            unsigned int_arity {0};
            unsigned bool_arity {0};
            std::vector<theory::Type> t;
            for (unsigned i = 1; i < child_count - 1; ++i) {
                if (type[i].isString("Int")) {
                    ++int_arity;
                    t.emplace_back(theory::Type::Int);
                } else {
                    assert(type[i].isString("Bool"));
                    ++bool_arity;
                    t.emplace_back(theory::Type::Bool);
                }
            }
            types.emplace(fun, t);
            max_int_arity = std::max(max_int_arity, int_arity);
            max_bool_arity = std::max(max_bool_arity, bool_arity);
        } else if (ex[0].isString("rule")) {
            state.push();
            auto lhs = parseFunApp(ex[1], state);
            auto rhs = parseFunApp(ex[2], state);
            std::vector<Bools::Expr> guard;
            Arith::Expr cost {arith::one()};
            for (unsigned idx = 3; idx + 1 < ex.childCount(); idx += 2) {
                const auto key {ex[idx].str()};
                const auto& val {ex[idx + 1]};
                if (key == ":var") {
                    continue;
                } else if (key == ":guard") {
                    guard.emplace_back(parseBoolExpr(val, state));
                } else if (key == ":cost") {
                    cost = parseArithExpr(val, state);
                } else {
                    throw std::invalid_argument("failed to parse " + ex.toString());
                }
            }
            const auto c = Clause::mk({lhs}, bools::mkAnd(guard), cost, rhs);
            its->add_clause(c);
            state.pop();
        }
    }
}

CHCPtr ARIParser::loadFromFile(const std::string &filename) {
    ARIParser parser;
    parser.run(filename);
    return parser.its;
}
