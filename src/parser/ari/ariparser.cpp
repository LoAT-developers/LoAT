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
            if (max_int_arity != state.arith_vars.size()) {
                for (unsigned i = 0; i < max_int_arity; ++i) {
                    state.arith_vars.emplace_back(ArithVar::nextProgVar());
                }
            }
            if (max_bool_arity != state.bool_vars.size()) {
                for (unsigned i = 0; i < max_bool_arity; ++i) {
                    state.bool_vars.emplace_back(BoolVar::nextProgVar());
                }
            }

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
                        const auto arg {state.arith_vars[state.next_arith_var]};
                        state.vars.emplace(lhs[i].str(), arg);
                        update.put(arg, parseArithExpr(rhs[i], state));
                        ++state.next_arith_var;
                        break;
                    }
                    case theory::Type::Bool: {
                        const auto arg {state.bool_vars[state.next_bool_var]};
                        state.vars.emplace(lhs[i].str(), arg);
                        update.put(arg, parseBoolExpr(rhs[i], state));
                        ++state.next_bool_var;
                        break;
                    }
                    case theory::Type::IntArray: {
                        throw std::invalid_argument("arrays are not supported in ARI");
                    }
                }
            }
            std::vector<Bools::Expr> guard;
            Arith::Expr cost {arith::mkConst(1)};
            for (unsigned idx = 3; idx + 1 < ex.childCount(); idx += 2) {
                const auto key {ex[idx].str()};
                auto val {ex[idx + 1]};
                if (key == ":var") {
                    continue;
                } else if (key == ":guard") {
                    guard.emplace_back(parseBoolExpr(val, state));
                } else if (key == ":cost") {
                    const auto cost {parseArithExpr(val, state)};
                    if (Config::Analysis::complexity()) {
                        update.put(its->getCostVar(), its->getCostVar() + cost);
                    } else if (Config::Analysis::relative_termination()) {
                        assert(cost->isInt());
                        assert(*cost->isInt() >= 0);
                        update.put(its->getCostVar(), its->getCostVar() + cost);
                    }
                } else {
                    throw std::invalid_argument("failed to parse " + ex.toString());
                }
            }
            if (Config::Analysis::complexity()) {
                update.put<Arith>(its->getCostVar(), its->getCostVar() + cost);
            } else if (Config::Analysis::relative_termination()) {
                assert(cost->isInt());
                assert(*cost->isInt() >= 0);
                update.put<Arith>(its->getCostVar(), its->getCostVar() + cost);
            }
            const auto lhs_idx {its->getOrAddLocation(lhs_loc)};
            const auto rhs_idx {its->getOrAddLocation(rhs_loc)};
            guard.emplace_back(bools::mkLit(arith::mkEq(its->getLocVar(), arith::mkConst(lhs_idx))));
            update.put(its->getLocVar(), arith::mkConst(rhs_idx));
            its->addRule(Rule::mk(bools::mkAnd(guard), update), lhs_idx);
            state.clear();
        }
    }
}

ITSPtr ARIParser::loadFromFile(const std::string &filename) {
    ARIParser parser;
    parser.run(filename);
    return parser.its;
}
