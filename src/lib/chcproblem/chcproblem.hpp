#pragma once

#include <optional>
#include <string>

#include "sexpresso.hpp"
#include "theory.hpp"

struct FunApp {
    std::string pred;
    std::vector<Var> args;

    FunApp(const std::string &pred, const std::vector<Var> &args);

    bool is_linear() const;
    sexpresso::Sexp to_smtlib(const var_map &vars) const;

    template <ITheory T>
    unsigned max_arity() const {
        unsigned res{0};
        for (const auto &x : args) {
            if (std::holds_alternative<typename T::Var>(x)) {
                ++res;
            }
        }
        return res;
    }
};

class Clause {

private:
    var_map vars {};
    std::optional<FunApp> premise {};
    Bools::Expr constraint {top()};
    std::optional<FunApp> conclusion {};

public:

    bool is_fact() const;
    bool is_query() const;
    bool is_left_linear() const;
    bool is_right_linear() const;
    sexpresso::Sexp to_smtlib() const;
    void add_var(const std::string &name, const Var &x);
    const std::optional<FunApp> &get_premise() const;
    const std::optional<FunApp> &get_conclusion() const;
    void set_premise(const std::optional<FunApp> &premise);
    void set_conclusion(const std::optional<FunApp> &conclusion);
    void set_constraint(const Bools::Expr e);
    Bools::Expr get_constraint() const;
    const var_map &get_vars() const;

    template <ITheory T>
    unsigned max_arity() const {
        const auto p_arity = premise ? premise->max_arity<T>() : 0;
        const auto c_arity = conclusion ? conclusion->max_arity<T>() : 0;
        return std::max(p_arity, c_arity);
    }
};

class CHCProblem {

    std::vector<Clause> clauses;

public:
    void add_clause(const Clause &c);
    const std::vector<Clause> &get_clauses() const;
    bool is_left_linear() const;
    bool is_right_linear() const;
    bool is_left_and_right_linear() const;
    sexpresso::Sexp to_smtlib() const;

    template <ITheory T>
    unsigned max_arity() const {
        unsigned res{0};
        for (const auto &c : clauses) {
            res = std::max(res, c.max_arity<T>());
        }
        return res;
    }
};
