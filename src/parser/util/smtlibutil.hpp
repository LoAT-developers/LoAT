#pragma once

#include "theory.hpp"

class SMTLibParsingState {

    std::vector<Arrays<Arith>::Var> arith_vars;
    std::unordered_map<size_t, std::vector<Arrays<Arith>::Var>> array_vars;
    std::vector<Bools::Var> bool_vars;

    template <class Var, class Expr>
    struct Decls {
        size_t next = 0;
        std::unordered_map<std::string, Expr> bindings;
        std::unordered_map<std::string, ptr<Var>> decls;

        std::optional<ptr<Var>> get_var(const std::string&) const;
        bool declares(const std::string&) const;

        explicit Decls(size_t next);

    };

    struct Frame {
        Decls<ArrayVar<Arith>, Arith::Expr> arith_vars;
        Decls<BoolVar, Bools::Expr> bool_vars;
        std::unordered_map<size_t, Decls<ArrayVar<Arith>, Arrays<Arith>::Expr>> array_vars;
        std::vector<Bools::Expr> m_refinement;

        explicit Frame(std::vector<Bools::Expr> refinement, size_t next_arith, size_t next_bool);

    };

    std::vector<Frame> frames {Frame({}, 0, 0)};

    size_t next_array_var_id(size_t dim) const;

public:

    std::optional<Arrays<Arith>::Var> get_array_var(const std::string&);
    Arrays<Arith>::Var get_or_create_array_var(const std::string&, size_t dim, bool tmp);
    Arrays<Arith>::Var get_or_create_arith_var(const std::string&, bool tmp);
    Bools::Var get_or_create_bool_var(const std::string&, bool tmp);
    Arrays<Arith>::Var create_arith_var(const std::string&, bool tmp);
    Arrays<Arith>::Var create_array_var(const std::string&, size_t dim, bool tmp);
    Bools::Var create_bool_var(const std::string&, bool tmp);
    Var create_var(const std::string&, theory::Type, bool tmp);
    void push();
    void pop();

    std::optional<Arith::Expr> get_arith_binding(const std::string&);
    std::optional<Bools::Expr> get_bool_binding(const std::string&);
    std::optional<Arrays<Arith>::Expr> get_array_binding(const std::string&);
    void add_refinement(const Bools::Expr&);
    Bools::Expr refinement() const;

    std::optional<theory::Type> get_type(const std::string&) const;
    void add_binding(const std::string&, const Expr&);

};

Expr parseExpr(sexpresso::Sexp &exp, SMTLibParsingState &state);

Bools::Expr parseBoolExpr(sexpresso::Sexp &exp, SMTLibParsingState &state);

Arith::Expr parseArithExpr(sexpresso::Sexp &exp, SMTLibParsingState &state);
