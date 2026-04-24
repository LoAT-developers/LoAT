#include "ariparser.hpp"
#include "smtlibutil.hpp"
#include "config.hpp"

#include <fstream>

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
            state.push();
            auto lhs {ex[1]};
            auto rhs {ex[2]};
            const auto lhs_loc = lhs.isString() ? lhs.str() : lhs[0].str();
            const auto rhs_loc = rhs.isString() ? rhs.str() : rhs[0].str();
            const auto type {types.at(lhs_loc)};
            const auto child_count {lhs.childCount()};
            Subs update;
            for (unsigned i = 1; i < child_count; ++i) {
                const auto [base,dim] = type.at(i-1);
                assert(dim == 0);
                switch (base) {
                    case theory::BaseType::Int: {
                        const auto var = state.get_or_create_arith_var(lhs[i].str(), false);
                        update.writeConst(var, parseArithExpr(rhs[i], state));
                        break;
                    }
                    case theory::BaseType::Bool: {
                        const auto var = state.get_or_create_bool_var(lhs[i].str(), false);
                        update.put(var, parseBoolExpr(rhs[i], state));
                        break;
                    }
                }
            }
            std::vector<Bools::Expr> guard;
            Arith::Expr cost {arith::one()};
            for (unsigned idx = 3; idx + 1 < ex.childCount(); idx += 2) {
                const auto key {ex[idx].str()};
                auto val {ex[idx + 1]};
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
            const auto cost_var {its->getCostVar()};
            if (Config::Analysis::complexity()) {
                update.update(cost_var, cost_var + cost);
            } else if (Config::Analysis::relative_termination()) {
                assert(cost->isInt());
                assert(*cost->isInt() >= 0);
                update.update(cost_var, cost_var + cost);
            }
            const auto lhs_idx {its->getOrAddLocation(lhs_loc)};
            const auto rhs_idx {its->getOrAddLocation(rhs_loc)};
            guard.emplace_back(bools::mkLit(arith::mkEq(its->getLocVar(), arith::mkConst(lhs_idx))));
            const auto loc_var {its->getLocVar()};
            update.update(loc_var, arith::mkConst(rhs_idx));
            its->addRule(Rule::mk(bools::mkAnd(guard), update), lhs_idx);
            state.pop();
        }
    }
}

ITSPtr ARIParser::loadFromFile(const std::string &filename) {
    ARIParser parser;
    parser.run(filename);
    return parser.its;
}
