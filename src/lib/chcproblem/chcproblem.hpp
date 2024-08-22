#pragma once

#include <optional>
#include <string>

#include "sexpresso.hpp"
#include "theory.hpp"
#include "subs.hpp"

class FunApp {
    std::string pred;
    std::vector<Var> args;

public:

    FunApp(const std::string &pred, const std::vector<Var> &args);

    bool is_linear() const;
    sexpresso::Sexp to_smtlib(const var_map &vars) const;
    const std::string& get_pred() const;
    const std::vector<Var>& get_args() const;

    friend auto operator<=>(const FunApp &, const FunApp&) = default;
    friend std::ostream& operator<<(std::ostream &s, const FunApp &f);
    friend std::size_t hash_value(const FunApp &f);
    friend bool operator==(const FunApp&, const FunApp&) = default;
    FunApp subs(const Subs &subs) const;

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
    var_map m_vars {};
    std::optional<FunApp> premise {};
    Bools::Expr constraint {top()};
    std::optional<FunApp> conclusion {};

    friend size_t hash_value(const Clause &);
    friend bool operator==(const Clause&, const Clause&);

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
    void add_constraint(const Bools::Expr e);
    Bools::Expr get_constraint() const;
    const var_map &get_vars() const;
    VarSet vars() const;
    Clause subs(const Subs &subs) const;

    template <ITheory T>
    unsigned max_arity() const {
        const auto p_arity = premise ? premise->max_arity<T>() : 0;
        const auto c_arity = conclusion ? conclusion->max_arity<T>() : 0;
        return std::max(p_arity, c_arity);
    }
};

class CHCProblem {

    linked_hash_set<Clause> clauses;
    bool produce_model {false};

public:
    const Clause* add_clause(const Clause &c);
    void remove_clause(const Clause &c);
    const linked_hash_set<Clause> &get_clauses() const;
    bool is_left_linear() const;
    bool is_right_linear() const;
    bool is_left_and_right_linear() const;
    sexpresso::Sexp to_smtlib() const;
    CHCProblem reverse() const;
    linked_hash_map<std::string, std::vector<Var>> get_signature() const;
    void do_produce_model();
    bool get_produce_model() const;

    template <ITheory T>
    unsigned max_arity() const {
        unsigned res{0};
        for (const auto &c : clauses) {
            res = std::max(res, c.max_arity<T>());
        }
        return res;
    }
};
