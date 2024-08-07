#include "chcproblem.hpp"

FunApp::FunApp(const std::string &pred, const std::vector<Var> &args): pred(pred), args(args) {}

bool FunApp::is_linear() const {
    linked_hash_set<Var> set {args.begin(), args.end()};
    return set.size() == args.size();
}

sexpresso::Sexp FunApp::to_smtlib() const {
    sexpresso::Sexp res {pred};
    for (const auto &arg: args) {
        res.addChild(theory::to_smtlib(arg));
    }
    return res;
}

bool Clause::is_fact() const {
    return !premise.has_value();
}

bool Clause::is_query() const {
    return !conclusion.has_value();
}

bool Clause::is_left_linear() const {
    return !premise || premise->is_linear();
}

bool Clause::is_right_linear() const {
    return !conclusion || conclusion->is_linear();
}

sexpresso::Sexp var_to_type(const Var &x) {
    return sexpresso::Sexp{
        std::visit(
            Overload{
                [&](const Arith::Var &) {
                    return "Int";
                },
                [&](const Bools::Var &) {
                    return "Bool";
                }},
            x)};
}

sexpresso::Sexp Clause::to_smtlib() const {
    sexpresso::Sexp assertion{"assert"};
    sexpresso::Sexp forall{"forall"};
    sexpresso::Sexp variables;
    for (const auto &[_,x]: vars) {
        sexpresso::Sexp var {theory::getName(x)};
        sexpresso::Sexp type {var_to_type(x)};
        variables.addChild(sexpresso::Sexp(std::vector{var, type}));
    }
    forall.addChild(variables);
    sexpresso::Sexp imp{"=>"};
    if (premise) {
        sexpresso::Sexp band{"and"};
        band.addChild(premise->to_smtlib());
        band.addChild(constraint->to_smtlib());
        imp.addChild(band);
    } else {
        imp.addChild(constraint->to_smtlib());
    }
    if (conclusion) {
        imp.addChild(conclusion->to_smtlib());
    } else {
        imp.addChild("false");
    }
    forall.addChild(imp);
    assertion.addChild(forall);
    return assertion;
}

void CHCProblem::add_clause(const Clause &c) {
    clauses.push_back(c);
}

const std::vector<Clause>& CHCProblem::get_clauses() const {
    return clauses;
}

bool CHCProblem::is_left_linear() const {
    for (const auto &c: clauses) {
        if (!c.is_left_linear()) {
            return false;
        }
    }
    return true;
}

bool CHCProblem::is_right_linear() const {
    for (const auto &c: clauses) {
        if (!c.is_right_linear()) {
            return false;
        }
    }
    return true;
}

bool CHCProblem::is_left_and_right_linear() const {
    for (const auto &c: clauses) {
        if (!c.is_right_linear() || !c.is_right_linear()) {
            return false;
        }
    }
    return true;
}

sexpresso::Sexp CHCProblem::to_smtlib() const {
    linked_hash_map<std::string, std::vector<Var>> preds;
    for (const auto &c: clauses) {
        if (c.premise) {
            preds.put(c.premise->pred, c.premise->args);
        }
        if (c.conclusion) {
            preds.put(c.conclusion->pred, c.conclusion->args);
        }
    }
    sexpresso::Sexp res;
    sexpresso::Sexp set_logic {"set-logic"};
    set_logic.addChild("HORN");
    res.addChild(set_logic);
    for (const auto &[f,args]: preds) {
        sexpresso::Sexp decl {"declare-fun"};
        decl.addChild(f);
        sexpresso::Sexp types;
        for (const auto &x: args) {
            types.addChild(var_to_type(x));
        }
        decl.addChild(types);
        decl.addChild("Bool");
        res.addChild(decl);
    }
    for (const auto &c: clauses) {
        res.addChild(c.to_smtlib());
    }
    return res;
}