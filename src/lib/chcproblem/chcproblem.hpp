#pragma once

#include <optional>
#include <string>

#include "theory.hpp"
#include "sexpresso.hpp"
#include "subs.hpp"
#include "conshash.hpp"

class FunApp;

using FunAppPtr = cpp::not_null<std::shared_ptr<const FunApp>>;

class FunApp {
    std::string pred;
    std::vector<Expr> args;

    struct CacheEqual {
        bool operator()(const std::tuple<std::string, std::vector<Expr>> &args1, const std::tuple<std::string, std::vector<Expr>> &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const std::tuple<std::string, std::vector<Expr>> &args) const noexcept;
    };
    static ConsHash<FunApp, FunApp, CacheHash, CacheEqual, std::string, std::vector<Expr>> cache;

public:

    FunApp(const std::string &pred, const std::vector<Expr> &args);
    ~FunApp();

    static FunAppPtr mk(const std::string &pred, const std::vector<Expr> &args);

    sexpresso::Sexp to_smtlib() const;
    const std::string& get_pred() const;
    const std::vector<Expr>& get_args() const;

    friend std::ostream& operator<<(std::ostream &s, const FunAppPtr);
    FunAppPtr subs(const Subs &subs) const;
    FunAppPtr rename_vars(const Renaming &) const;

    template <ITheory T>
    unsigned max_arity() const {
        unsigned res{0};
        for (const auto &x : args) {
            if (std::holds_alternative<typename T::Expr>(x)) {
                ++res;
            }
        }
        return res;
    }
};

class Clause;

using ClausePtr = cpp::not_null<std::shared_ptr<const Clause>>;

class Clause {

private:

    std::optional<FunAppPtr> premise {};
    Bools::Expr constraint;
    std::optional<FunAppPtr> conclusion {};

    friend std::ostream& operator<<(std::ostream &s, const ClausePtr f);

    using Args = std::tuple<std::optional<FunAppPtr>, Bools::Expr, std::optional<FunAppPtr>>;

    struct CacheEqual {
        bool operator()(const Args &args1, const Args &args2) const noexcept;
    };
    struct CacheHash {
        size_t operator()(const Args &args) const noexcept;
    };
    static ConsHash<Clause, Clause, CacheHash, CacheEqual, std::optional<FunAppPtr>, Bools::Expr, std::optional<FunAppPtr>> cache;

public:

    Clause(const std::optional<FunAppPtr> premise, const Bools::Expr constraint, const std::optional<FunAppPtr> conclusion);
    ~Clause();

    static ClausePtr mk(const std::optional<FunAppPtr> premise, const Bools::Expr constraint, const std::optional<FunAppPtr> conclusion);

    bool is_fact() const;
    bool is_query() const;
    bool is_left_linear() const;
    std::optional<FunAppPtr> get_premise() const;
    std::optional<FunAppPtr> get_conclusion() const;
    Bools::Expr get_constraint() const;
    VarSet vars() const;
    ClausePtr subs(const Subs &subs) const;
    ClausePtr rename_vars(const Renaming &) const;
    sexpresso::Sexp to_smtlib() const;

    template <ITheory T>
    unsigned max_arity() const {
        const auto p_arity = premise ? (*premise)->max_arity<T>() : 0;
        const auto c_arity = conclusion ? (*conclusion)->max_arity<T>() : 0;
        return std::max(p_arity, c_arity);
    }
};

class CHCProblem {

    linked_hash_set<ClausePtr> clauses;
    friend std::ostream& operator<<(std::ostream &s, const CHCProblem&);

    CHCProblem(const CHCProblem&) = delete;
    CHCProblem& operator=(const CHCProblem&) = delete;

public:

    CHCProblem() = default;

    void add_clause(const ClausePtr c);
    void remove_clause(const ClausePtr c);
    const linked_hash_set<ClausePtr> &get_clauses() const;
    sexpresso::Sexp to_smtlib() const;
    CHCProblem reverse() const;
    linked_hash_map<std::string, std::vector<theory::Type>> get_signature() const;

    template <ITheory T>
    unsigned max_arity() const {
        unsigned res{0};
        for (const auto &c : clauses) {
            res = std::max(res, c->max_arity<T>());
        }
        return res;
    }
};

using CHCPtr = std::shared_ptr<CHCProblem>;
