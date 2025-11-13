#include "smtlibutil.hpp"

Var SMTLibParsingState::get_var(const std::string &name, const theory::Type type) {
    if (const auto it {vars.find(name)}; it != vars.end()) {
        return it->second;
    }
    std::optional<Var> var;
    switch (type) {
        case theory::Type::Int: {
            if (next_tmp_arith_var == tmp_arith_vars.size()) {
                tmp_arith_vars.emplace_back(ArrayVar<Arith>::next(0));
            }
            var = tmp_arith_vars.at(next_tmp_arith_var);
            ++next_tmp_arith_var;
            break;
        }
        case theory::Type::Bool: {
            if (next_tmp_bool_var == tmp_bool_vars.size()) {
                tmp_bool_vars.emplace_back(BoolVar::next());
            }
            var = tmp_bool_vars.at(next_tmp_bool_var);
            ++next_tmp_bool_var;
            break;
        }
    case theory::Type::IntArray:
        if (next_tmp_arr_var == tmp_arr_vars.size()) {
            tmp_arr_vars.emplace_back(ArrayVar<Arith>::next(1));
        }
        var = tmp_arr_vars.at(next_tmp_arr_var);
        ++next_tmp_arr_var;
        break;
        break;
    }
    vars.emplace(name, *var);
    return *var;
}

void SMTLibParsingState::clear() {
    this->vars.clear();
    this->bindings.clear();
    this->refinement.clear();
    this->next_arith_var = 0;
    this->next_bool_var = 0;
    this->next_tmp_arith_var = 0;
    this->next_tmp_bool_var = 0;
}

bool isInt(const std::string &s) {
    return !s.empty() && (s[0] == '-' || std::isdigit(s[0])) && std::all_of(std::next(s.begin()), s.end(), isdigit);
}

Arrays<Arith>::Var getArrayVar(const std::string &name, SMTLibParsingState &state) {
    return std::get<Arrays<Arith>::Var>(state.get_var(name, theory::Type::Int));
}

Arrays<Arith>::Expr parseArray(sexpresso::Sexp &exp, SMTLibParsingState &state) {
    if (exp.isString()) {
        const auto name{exp.str()};
        for (int i = state.bindings.size() - 1; i >= 0; i--) {
            if (const auto it{state.bindings[i].find(name)}; it != state.bindings[i].end()) {
                return std::get<Arrays<Arith>::Expr>(it->second);
            }
        }
        return getArrayVar(name, state);
    }
    if (exp[0].str() == "store") {
        const auto arr = parseArray(exp[1], state);
        const auto idx = parseArithExpr(exp[2], state);
        const auto val = parseArithExpr(exp[3], state);
        return arrays::mkArrayWrite(arr, std::vector{idx}, val);
    }
    throw std::invalid_argument("unknown array");
}

Arith::Expr parseArithExpr(sexpresso::Sexp &exp, SMTLibParsingState &state) {
    if (exp.isString()) {
        if (const auto name {exp.str()}; isInt(name)) {
            return arith::mkConst(Int(name));
        } else {
            for (int i = state.bindings.size() - 1; i >= 0; i--) {
                if (const auto it{state.bindings[i].find(name)}; it != state.bindings[i].end()) {
                    return std::get<Arith::Expr>(it->second);
                }
            }
            return arrays::readConst(getArrayVar(name, state));
        }
    }
    const auto name {exp[0].str()};
    if (name == "ite") {
        const auto r{parseBoolExpr(exp[1], state)};
        const auto then_case{parseArithExpr(exp[2], state)};
        const auto else_case{parseArithExpr(exp[3], state)};
        const auto var {arrays::nextConst<Arith>()};
        state.refinement.emplace_back((r && bools::mkLit(arith::mkEq(var, then_case))) || (!r && bools::mkLit(arith::mkEq(var, else_case))));
        return var;
    }
    if (name == "let") {
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
    }
    if (name == "+") {
        std::vector<Arith::Expr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            args.push_back(parseArithExpr(exp[i], state));
        }
        return arith::mkPlus(std::move(args));
    }
    if (name == "*") {
        std::vector<Arith::Expr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            args.push_back(parseArithExpr(exp[i], state));
        }
        return arith::mkTimes(std::move(args));
    }
    if (name == "-") {
        if (exp.childCount() == 2) {
            // unary minus
            return -parseArithExpr(exp[1], state);
        }
        std::vector<Arith::Expr> args;
        args.push_back(parseArithExpr(exp[1], state));
        for (unsigned i = 2; i < exp.childCount(); ++i) {
            args.push_back(-parseArithExpr(exp[i], state));
        }
        return arith::mkPlus(std::move(args));
    }
    if (name == "mod" || name == "div") {
        const auto fst {parseArithExpr(exp[1], state)};
        const auto snd {parseArithExpr(exp[2], state)};
        const auto div {arrays::nextConst<Arith>()};
        const auto mod {arrays::nextConst<Arith>()};
        std::vector<Bools::Expr> constr;
        constr.push_back(theory::mkEq(fst, snd * div + mod));
        constr.push_back(theory::mkNeq(snd, arith::zero()));
        bool explicit_encoding = false;
        if (const auto y {snd->isInt()}) {
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
            constr.push_back(bools::mkLit(arith::mkGeq(mod, arith::zero()))); // x mod y is non-negative
            constr.push_back( // |y| > x mod y
                bools::mkAnd(std::vector{arith::mkGt(snd, arith::zero()), arith::mkGt(snd, mod)})
                || bools::mkAnd(std::vector{arith::mkLt(snd, arith::zero()), arith::mkGt(-snd, mod)}));
        }
        state.refinement.emplace_back(bools::mkAnd(constr));
        if (name == "div") {
            return div;
        }
        return mod;
    }
    if (name == "select") {
        const auto arr = parseArray(exp[1], state);
        const auto idx = parseArithExpr(exp[2], state);
        return arrays::mkArrayRead(arr, std::vector{idx});
    }
    throw std::invalid_argument("unknown operator " + name);
}

theory::Type getType(const sexpresso::Sexp &exp, SMTLibParsingState &state) {
    auto child{exp};
    while (!child.isString() && (child[0].str() == "ite" || child[0].str() == "let")) {
        child = child[2];
    }
    std::vector<Expr> args;
    if (child.isString()) {
        const auto name{child.str()};
        if (name == "true" || name == "false") {
            return theory::Type::Bool;
        }
        if (isInt(name)) {
            return theory::Type::Int;
        }
        if (const auto it {state.vars.find(name)}; it != state.vars.end()) {
            return theory::to_type(it->second);
        }
        for (int i = state.bindings.size() - 1; i >= 0; i--) {
            if (const auto it {state.bindings[i].find(name)}; it != state.bindings[i].end()) {
                return theory::to_type(it->second);
            }
        }
        throw std::invalid_argument("unknown symbol " + name);
    }
    if (const auto name = child[0].str(); name == "and" || name == "or" || name == "not" || name == "<" || name == "<=" || name == ">" || name == ">=" || name == "=" || name == "distinct" || name == "exists") {
        return theory::Type::Bool;
    }
    if (child[0].str() == "store") {
        return theory::Type::IntArray;
    }
    return theory::Type::Int;
}

Expr parseExpr(sexpresso::Sexp &exp, SMTLibParsingState &state) {
    switch (getType(exp, state)) {
    case theory::Type::Bool: return parseBoolExpr(exp, state);
    case theory::Type::Int: return parseArithExpr(exp, state);
    case theory::Type::IntArray: return parseArray(exp, state);
    }
    assert(false);
}

Bools::Expr parseBoolExpr(sexpresso::Sexp &exp, SMTLibParsingState &state) {
    if (exp.isString()) {
        const auto name {exp.str()};
        if (name == "true") {
            return top();
        }
        if (name == "false") {
            return bot();
        }
        for (int i = state.bindings.size() - 1; i >= 0; i--) {
            if (const auto it {state.bindings[i].find(name)}; it != state.bindings[i].end()) {
                return std::get<Bools::Expr>(it->second);
            }
        }
        const auto x {state.get_var(name, theory::Type::Bool)};
        return bools::mkLit(bools::mk(std::get<Bools::Var>(x)));
    }
    const auto f {exp[0].str()};
    if (f == "ite") {
        const auto r{parseBoolExpr(exp[1], state)};
        const auto then_case{parseBoolExpr(exp[2], state)};
        const auto else_case{parseBoolExpr(exp[3], state)};
        return (r && then_case) || (!r && else_case);
    }
    if (f == "let") {
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
    }
    if (f == "exists") {
        const auto num_vars {exp[1].childCount()};
        std::unordered_map<std::string, Var> old_bindings;
        for (unsigned i = 0; i < num_vars; ++i) {
            const auto var_name {exp[1][i][0].str()};
            const auto var_type {exp[1][i][1].str()};
            if (const auto it {state.vars.find(var_name)}; it != state.vars.end()) {
                old_bindings.emplace(*it);
                state.vars.erase(var_name);
            }
            state.get_var(var_name, theory::to_type(var_type));
        }
        const auto res {parseBoolExpr(exp[2], state)};
        for (unsigned i = 0; i < num_vars; ++i) {
            const auto var_name {exp[1][i][0].str()};
            state.vars.erase(var_name);
        }
        for (const auto &p: old_bindings) {
            state.vars.emplace(p);
        }
        return res;
    }
    if (f == "and") {
        std::vector<Bools::Expr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            args.push_back(parseBoolExpr(exp[i], state));
        }
        return bools::mkAnd(args);
    }
    if (f == "or") {
        std::vector<Bools::Expr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            args.push_back(parseBoolExpr(exp[i], state));
        }
        return bools::mkOr(args);
    }
    if (f == "not") {
        return !parseBoolExpr(exp[1], state);
    }
    if (f == "<" || f == "<=" || f == ">" || f == ">=") {
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
        return bools::mkAnd(lits);
    }
    if (f == "=" || f == "distinct") {
        auto type {getType(exp[1], state)};
        std::vector<Expr> args;
        for (unsigned i = 1; i < exp.childCount(); ++i) {
            switch (type) {
            case theory::Type::Int: {
                args.emplace_back(parseArithExpr(exp[i], state));
                break;
            }
            case theory::Type::Bool: {
                args.emplace_back(parseBoolExpr(exp[i], state));
                break;
            }
            case theory::Type::IntArray: {
                args.emplace_back(parseArray(exp[i], state));
                break;
            }
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
    }
    throw std::invalid_argument("unknwon bool expression");
}
