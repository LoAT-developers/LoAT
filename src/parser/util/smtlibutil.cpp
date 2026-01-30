#include "smtlibutil.hpp"

#include <utility>

template <class Var, class Expr>
std::optional<ptr<Var>> SMTLibParsingState::Decls<Var, Expr>::get_var(const std::string& name) const {
    if (const auto it = decls.find(name); it != decls.end()) {
        return it->second;
    }
    return std::nullopt;
}

template <class Var, class Expr>
bool SMTLibParsingState::Decls<Var, Expr>::declares(const std::string& name) const {
    return decls.contains(name) || bindings.contains(name);
}

template <class Var, class Expr>
SMTLibParsingState::Decls<Var, Expr>::Decls(const size_t next): next(next) {}

size_t SMTLibParsingState::next_array_var_id(const size_t dim) const {
    for (const auto& f: frames | std::views::reverse) {
        if (const auto it = f.array_vars.find(dim); it != f.array_vars.end()) {
            return it->second.next;
        }
    }
    return 0;
}

std::optional<Arrays<Arith>::Var> SMTLibParsingState::get_array_var(const std::string& name) {
    for (const auto& f: frames | std::views::reverse) {
        for (const auto& a: f.array_vars | std::views::values) {
            if (const auto res = a.get_var(name)) {
                return *res;
            }
        }
    }
    return std::nullopt;
}

Arrays<Arith>::Var SMTLibParsingState::get_or_create_array_var(const std::string& name, const size_t dim, const bool tmp) {
    if (const auto opt = get_array_var(name)) {
        return *opt;
    }
    return create_array_var(name, dim, tmp);
}

Arrays<Arith>::Var SMTLibParsingState::get_or_create_arith_var(const std::string& name, const bool tmp) {
    for (const auto& f: frames | std::views::reverse) {
        if (const auto res = f.arith_vars.get_var(name)) {
            return *res;
        }
    }
    return create_arith_var(name, tmp);
}

Bools::Var SMTLibParsingState::get_or_create_bool_var(const std::string& name, const bool tmp) {
    for (const auto& f: frames | std::views::reverse) {
        if (const auto res = f.bool_vars.get_var(name)) {
            return *res;
        }
    }
    return create_bool_var(name, tmp);
}

Arrays<Arith>::Var SMTLibParsingState::create_arith_var(const std::string& name, const bool tmp) {
    auto& arith = frames.back().arith_vars;
    if (arith.next == arith_vars.size()) {
        const auto var = tmp ? ArrayVar<Arith>::next(0) : ArrayVar<Arith>::nextProgVar(0);
        arith_vars.emplace_back(var);
    }
    const auto res = arith_vars.at(arith.next);
    ++arith.next;
    arith.decls.emplace(name, res);
    return res;
}

Arrays<Arith>::Var SMTLibParsingState::create_array_var(const std::string& name, const size_t dim, const bool tmp) {
    auto& arr = frames.back().array_vars.emplace(dim, Decls<ArrayVar<Arith>, Arrays<Arith>::Expr>(next_array_var_id(dim))).first->second;
    auto& vec = array_vars.emplace(dim, std::vector<Arrays<Arith>::Var>()).first->second;
    if (arr.next == vec.size()) {
        const auto var = tmp ? ArrayVar<Arith>::next(dim) : ArrayVar<Arith>::nextProgVar(dim);
        vec.emplace_back(var);
    }
    const auto res = vec.at(arr.next);
    ++arr.next;
    arr.decls.emplace(name, res);
    return res;
}

Bools::Var SMTLibParsingState::create_bool_var(const std::string& name, const bool tmp) {
    auto& bools = frames.back().bool_vars;
    if (bools.next == bool_vars.size()) {
        const auto var = tmp ? BoolVar::next() : BoolVar::nextProgVar();
        bool_vars.emplace_back(var);
    }
    const auto res = bool_vars.at(bools.next);
    ++bools.next;
    bools.decls.emplace(name, res);
    return res;
}

Var SMTLibParsingState::create_var(const std::string& name, const theory::Type type, const bool tmp) {
    switch (type.base) {
        case theory::BaseType::Bool: return create_bool_var(name, tmp);
        case theory::BaseType::Int: {
            if (type.dim == 0) {
                return create_arith_var(name, tmp);
            }
            return create_array_var(name, type.dim, tmp);
        }
    }
    throw std::invalid_argument("unknown type");
}

SMTLibParsingState::Frame::Frame(
    std::vector<Bools::Expr> refinement,
    const size_t next_arith,
    const size_t next_bool) :
    arith_vars(next_arith),
    bool_vars(next_bool),
    m_refinement(std::move(refinement)) {}

void SMTLibParsingState::push() {
    const auto& f = frames.back();
    frames.emplace_back(f.m_refinement, f.arith_vars.next, f.bool_vars.next);
}

void SMTLibParsingState::pop() {
    frames.pop_back();
}

std::optional<Arith::Expr> SMTLibParsingState::get_arith_binding(const std::string& name) {
    for (const auto& f: frames | std::views::reverse) {
        if (const auto it = f.arith_vars.bindings.find(name); it != f.arith_vars.bindings.end()) {
            return it->second;
        }
    }
    return std::nullopt;
}

std::optional<Bools::Expr> SMTLibParsingState::get_bool_binding(const std::string& name) {
    for (const auto& f: frames | std::views::reverse) {
        if (const auto it = f.bool_vars.bindings.find(name); it != f.bool_vars.bindings.end()) {
            return it->second;
        }
    }
    return std::nullopt;
}

std::optional<Arrays<Arith>::Expr> SMTLibParsingState::get_array_binding(const std::string& name) {
    for (const auto& f: frames | std::views::reverse) {
        for (const auto& d: f.array_vars | std::views::values) {
            if (const auto it = d.bindings.find(name); it != d.bindings.end()) {
                return it->second;
            }
        }
    }
    return std::nullopt;
}

void SMTLibParsingState::add_refinement(const Bools::Expr& e) {
    frames.back().m_refinement.emplace_back(e);
}

Bools::Expr SMTLibParsingState::refinement() const {
    return bools::mkAnd(frames.back().m_refinement);
}

std::optional<theory::Type> SMTLibParsingState::get_type(const std::string& name) const {
    for (const auto& [arith_vars, bool_vars, array_vars, refinement]: frames | std::views::reverse) {
        if (arith_vars.declares(name)) {
            return theory::Type::Int;
        }
        if (bool_vars.declares(name)) {
            return theory::Type::Bool;
        }
        for (const auto& [dim,decl]: array_vars) {
            if (decl.declares(name)) {
                return theory::Type(theory::BaseType::Int, dim);
            }
        }
    }
    return std::nullopt;
}

void SMTLibParsingState::add_binding(const std::string& s, const Expr& e) {
    auto& [arith_vars, bool_vars, array_vars, refinement] = frames.back();
    theory::apply(
        e,
        [&](const Arith::Expr& e) {
            arith_vars.bindings.emplace(s, e);
        },
        [&](const Bools::Expr& e) {
            bool_vars.bindings.emplace(s, e);
        },
        [&](const Arrays<Arith>::Expr& e) {
            // no need to distinguish bindings by arity, so we always use arity 1 here
            array_vars.emplace(1, Decls<ArrayVar<Arith>, Arrays<Arith>::Expr>(next_array_var_id(1))).first->second.bindings.emplace(s, e);
        });
}

bool isInt(const std::string &s) {
    return !s.empty() && (s[0] == '-' || std::isdigit(s[0])) && std::all_of(std::next(s.begin()), s.end(), isdigit);
}

Arrays<Arith>::Expr parseArray(sexpresso::Sexp &exp, SMTLibParsingState &state) {
    if (exp.isString()) {
        const auto name{exp.str()};
        if (const auto binding = state.get_array_binding(name)) {
            return *binding;
        }
        return *state.get_array_var(name);
    }
    if (exp[0].str() == "store") {
        const auto arr = parseArray(exp[1], state);
        std::vector<Arith::Expr> idx;
        idx.push_back(parseArithExpr(exp[2], state));
        auto last_idx = exp[2];
        auto inner_exp = exp[3];
        for (size_t i = 1; i < arr->dim(); ++i) {
            assert(inner_exp[0].isString("store"));
            assert(inner_exp[1][0].isString("select"));
            assert(inner_exp[1][1].isString(exp[1].str()));
            assert(inner_exp[1][2].isString(last_idx.str()));
            idx.push_back(parseArithExpr(inner_exp[2], state));
            last_idx = inner_exp[2];
            inner_exp = inner_exp[3];
        }
        return arrays::mkArrayWrite(arr, idx, parseArithExpr(inner_exp, state));
    }
    throw std::invalid_argument("unknown array: " + exp.toString());
}

Arith::Expr parseArithExpr(sexpresso::Sexp &exp, SMTLibParsingState &state) {
    if (exp.isString()) {
        if (const auto name {exp.str()}; isInt(name)) {
            return arith::mkConst(Int(name));
        } else {
            if (const auto binding = state.get_arith_binding(name)) {
                return *binding;
            }
            return arrays::readConst(state.get_or_create_arith_var(name, true));
        }
    }
    const auto name {exp[0].str()};
    if (name == "ite") {
        const auto r{parseBoolExpr(exp[1], state)};
        const auto then_case{parseArithExpr(exp[2], state)};
        const auto else_case{parseArithExpr(exp[3], state)};
        const auto var {arrays::nextConst<Arith>()};
        state.add_refinement((r && bools::mkLit(arith::mkEq(var, then_case))) || (!r && bools::mkLit(arith::mkEq(var, else_case))));
        return var;
    }
    if (name == "let") {
        state.push();
        auto declarations{exp[1]};
        std::unordered_map<std::string, Expr> newBindings;
        for (unsigned i = 0; i < declarations.childCount(); ++i) {
            auto decl{declarations[i]};
            const auto declName{decl[0].str()};
            state.add_binding(declName, parseArithExpr(decl[1], state));
        }
        auto res{parseArithExpr(exp[2], state)};
        state.pop();
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
        constr.push_back(bools::mkLit(arith::mkEq(fst, snd * div + mod)));
        constr.push_back(bools::mkLit(arith::mkNeq(snd, arith::zero())));
        bool explicit_encoding = false;
        if (const auto y {snd->isInt()}) {
            if (*y > 0 && *y <= 10) {
                explicit_encoding = true;
                std::vector<Bools::Expr> refinement;
                for (int i = 0; i < *y; i++) {
                    refinement.push_back(Arith::mkEq(mod, arith::mkConst(i)));
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
        state.add_refinement(bools::mkAnd(constr));
        if (name == "div") {
            return div;
        }
        return mod;
    }
    if (name == "select") {
        std::vector<Arith::Expr> idx;
        auto select = exp;
        while (!select.isString() && select[0].isString("select")) {
            idx.emplace_back(parseArithExpr(select[2], state));
            select = select[1];
        }
        std::ranges::reverse(idx);
        const auto arr = parseArray(select, state);
        return arrays::mkArrayRead(arr, idx);
    }
    throw std::invalid_argument("unknown operator " + name);
}

theory::Type getType(const sexpresso::Sexp &exp, const SMTLibParsingState &state) {
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
        if (const auto type = state.get_type(name)) {
            return *type;
        }
        throw std::invalid_argument("unknown symbol " + name);
    }
    if (const auto name = child[0].str(); name == "and" || name == "or" || name == "not" || name == "<" || name == "<=" || name == ">" || name == ">=" || name == "=" || name == "distinct" || name == "exists") {
        return theory::Type::Bool;
    }
    if (child[0].str() == "store") {
        // we don't know the precise dimension here, and we just use 1 to signal that it's an array
        return theory::Type(theory::BaseType::Int, 1);
    }
    return theory::Type::Int;
}

Expr parseExpr(sexpresso::Sexp& exp, SMTLibParsingState& state) {
    switch (const auto [base, dim]{getType(exp, state)}; base) {
    case theory::BaseType::Bool: return parseBoolExpr(exp, state);
    case theory::BaseType::Int: {
        if (dim == 0) {
            return parseArithExpr(exp, state);
        }
        return parseArray(exp, state);
    }
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
        if (const auto& binding = state.get_bool_binding(name)) {
            return *binding;
        }
        const auto x {state.get_or_create_bool_var(name, true)};
        return bools::mkLit(bools::mk(x));
    }
    const auto f {exp[0].str()};
    if (f == "ite") {
        const auto r{parseBoolExpr(exp[1], state)};
        const auto then_case{parseBoolExpr(exp[2], state)};
        const auto else_case{parseBoolExpr(exp[3], state)};
        return (r && then_case) || (!r && else_case);
    }
    if (f == "let") {
        state.push();
        auto declarations {exp[1]};
        std::unordered_map<std::string, Expr> newBindings;
        for (unsigned i = 0; i < declarations.childCount(); ++i) {
            auto decl {declarations[i]};
            const auto declName {decl[0].str()};
            state.add_binding(declName, parseExpr(decl[1], state));
        }
        auto res {parseBoolExpr(exp[2], state)};
        state.pop();
        return res;
    }
    if (f == "exists") {
            state.push();
            const auto num_vars{exp[1].childCount()};
            for (unsigned i = 0; i < num_vars; ++i) {
                const auto var_name{exp[1][i][0].str()};
                const auto var_type{exp[1][i][1].str()};
                state.create_var(var_name, theory::to_type(var_type), true);
            }
            const auto res{parseBoolExpr(exp[2], state)};
            state.pop();
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
        if (f == "=>") {
            Bools::Expr res = parseBoolExpr(exp[exp.childCount() - 1], state);
            for (unsigned i = exp.childCount() - 2; i > 0; --i) {
                res = !parseBoolExpr(exp[i], state) || res;
            }
            return res;
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
                    lits.insert(arith::mkLt(args[i - 1], args[i]));
                } else if (f == "<=") {
                    lits.insert(arith::mkLeq(args[i - 1], args[i]));
                } else if (f == ">") {
                    lits.insert(arith::mkGt(args[i - 1], args[i]));
                } else if (f == ">=") {
                    lits.insert(arith::mkGeq(args[i - 1], args[i]));
                }
            }
            return bools::mkAnd(lits);
        }
        if (f == "=" || f == "distinct") {
            auto [base, dim] = getType(exp[1], state);
            std::vector<Bools::Expr> lits;
            const auto build_lits = [&]<class T>(const auto& parse) {
                std::vector<typename T::Expr> args;
                for (unsigned i = 1; i < exp.childCount(); ++i) {
                    args.emplace_back(parse(exp[i], state));
                }
                if (f == "=") {
                    for (unsigned i = 1; i < args.size(); ++i) {
                        lits.push_back(T::mkEq(args[i - 1], args[i]));
                    }
                } else {
                    for (unsigned i = 0; i < args.size() - 1; ++i) {
                        for (unsigned j = i + 1; j < args.size(); ++j) {
                            lits.push_back(!T::mkEq(args[i], args[j]));
                        }
                    }
                }
            };
            switch (base) {
            case theory::BaseType::Int: {
                if (dim == 0) {
                    build_lits.operator()<Arith>(parseArithExpr);
                } else {
                    build_lits.operator()<Arrays<Arith>>(parseArray);
                }
                break;
            }
            case theory::BaseType::Bool: {
                build_lits.operator()<Bools>(parseBoolExpr);
                break;
            }
            }
            return bools::mkAnd(lits);
        }
        throw std::invalid_argument("unknwon bool expression");
    }
