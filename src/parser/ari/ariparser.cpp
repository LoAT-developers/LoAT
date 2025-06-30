#include "ariparser.hpp"
#include "smtlibutil.hpp"

#include <fstream>

void ARIParser::run(const std::string &filename) {
    std::ifstream ifs(filename);
    std::string content(
        (std::istreambuf_iterator<char>(ifs)),
        (std::istreambuf_iterator<char>()));
    sexpresso::Sexp sexp = sexpresso::parse(content);
    unsigned max_int_arity {0};
    unsigned max_bool_arity {0};
    for (auto &ex: sexp.arguments()) {
        if (ex[0].isString("entrypoint")) {
            const auto entry {its->getOrAddLocation(ex[1].str())};
            its->setInitialLocation(entry);
        } else if (ex[0].isString("fun")) {
            const auto fun {ex[1].str()};
            auto type {ex[2]};
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
            if (max_int_arity != arith_vars.size()) {
                for (unsigned i = 0; i < max_int_arity; ++i) {
                    arith_vars.emplace_back(ArithVar::nextProgVar());
                }
            }
            if (max_bool_arity != bool_vars.size()) {
                for (unsigned i = 0; i < max_bool_arity; ++i) {
                    bool_vars.emplace_back(BoolVar::nextProgVar());
                }
            }
            unsigned next_int_arg {0};
            unsigned next_bool_arg {0};
            SMTLibParsingState state;
            auto lhs {ex[1]};
            auto rhs {ex[2]};
            const auto lhs_loc {lhs[0].str()};
            const auto rhs_loc {rhs[0].str()};
            const auto type {types.at(lhs_loc)};
            const auto child_count {lhs.childCount()};
            Subs update;
            for (unsigned i = 1; i < child_count; ++i) {
                switch (type.at(i-1)) {
                    case theory::Type::Int: {
                        const auto arg {arith_vars[next_int_arg]};
                        state.vars.emplace(lhs[i].str(), arg);
                        update.put<Arith>(arg, parseArithExpr(rhs[i], state));
                        ++next_int_arg;
                        break;
                    }
                    case theory::Type::Bool: {
                        const auto arg {bool_vars[next_bool_arg]};
                        state.vars.emplace(lhs[i].str(), arg);
                        update.put<Bools>(arg, parseBoolExpr(rhs[i], state));
                        ++next_bool_arg;
                        break;
                    }
                }
            }
            std::vector<Bools::Expr> guard;
            if (ex.childCount() > 3) {
                guard.emplace_back(parseBoolExpr(ex[4], state));
            }
            const auto lhs_idx {its->getOrAddLocation(lhs_loc)};
            const auto rhs_idx {its->getOrAddLocation(rhs_loc)};
            guard.emplace_back(bools::mkLit(arith::mkEq(its->getLocVar(), arith::mkConst(lhs_idx))));
            update.put<Arith>(its->getLocVar(), arith::mkConst(rhs_idx));
            its->addRule(Rule::mk(bools::mkAnd(guard), update), lhs_idx);
        }
    }
}

ITSPtr ARIParser::loadFromFile(const std::string &filename) {
    ARIParser parser;
    parser.run(filename);
    return parser.its;
}