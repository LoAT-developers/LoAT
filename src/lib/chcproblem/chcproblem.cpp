#include "chcproblem.hpp"

FunApp::FunApp(const std::string &pred, const std::vector<Var> &args): pred(pred), args(args) {}

bool FunApp::is_linear() const {
    linked_hash_set<Var> set {args.begin(), args.end()};
    return set.size() == args.size();
}

sexpresso::Sexp FunApp::to_smtlib(const var_map &vars) const {
    sexpresso::Sexp res {pred};
    for (const auto &arg: args) {
        res.addChild(vars.right.at(arg));
    }
    return res;
}

std::ostream& operator<<(std::ostream &s, const FunApp &f) {
    s << f.pred << " ::";
    for (const auto &x: f.args) {
        s << " " << theory::var_to_type(x);
    }
    return s;
}

std::size_t hash_value(const FunApp &f) {
    size_t seed {42};
    boost::hash_combine(seed, f.pred);
    boost::hash_combine(seed, boost::hash_range(f.args.begin(), f.args.end()));
    return seed;
}

const std::string& FunApp::get_pred() const {
    return pred;
}

const std::vector<Var>& FunApp::get_args() const {
    return args;
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

void Clause::add_var(const std::string &name, const Var &x) {
    vars.left.insert(var_map::left_value_type(name, x));
}

void Clause::set_premise(const std::optional<FunApp> &premise) {
    this->premise = premise;
}

void Clause::set_conclusion(const std::optional<FunApp> &conclusion) {
    this->conclusion = conclusion;
}

void Clause::set_constraint(const Bools::Expr e) {
    this->constraint = e;
}

const std::optional<FunApp>& Clause::get_premise() const {
    return premise;
}

const std::optional<FunApp>& Clause::get_conclusion() const {
    return conclusion;
}

Bools::Expr Clause::get_constraint() const {
    return constraint;
}

const var_map& Clause::get_vars() const {
    return vars;
}

sexpresso::Sexp Clause::to_smtlib() const {
    sexpresso::Sexp assertion{"assert"};
    sexpresso::Sexp forall{"forall"};
    sexpresso::Sexp variables;
    std::map<std::string, sexpresso::Sexp> var_map;
    for (const auto &[_,x]: vars) {
        const auto var {vars.right.at(x)};
        const auto type {theory::var_to_type(x)};
        var_map.emplace(var, type);
    }
    for (const auto &[name, type]: var_map) {
        sexpresso::Sexp var {name};
        var.addChild(type);
        variables.addChild(var);
    }
    forall.addChild(variables);
    sexpresso::Sexp imp{"=>"};
    const auto constr{constraint->to_smtlib([&](const auto &x) {
        const auto it{vars.right.find(x)};
        return it == vars.right.end() ? theory::getName(x) : it->second;
    })};
    if (premise) {
        sexpresso::Sexp band{"and"};
        band.addChild(premise->to_smtlib(vars));
        band.addChild(constr);
        imp.addChild(band);
    } else {
        imp.addChild(constr);
    }
    if (conclusion) {
        imp.addChild(conclusion->to_smtlib(vars));
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
    const auto preds {get_signature()};
    sexpresso::Sexp res;
    sexpresso::Sexp set_logic {"set-logic"};
    set_logic.addChild("HORN");
    res.addChild(set_logic);
    for (const auto &[f,args]: preds) {
        sexpresso::Sexp decl {"declare-fun"};
        decl.addChild(f);
        sexpresso::Sexp types;
        for (const auto &x: args) {
            types.addChild(theory::var_to_type(x));
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

CHCProblem CHCProblem::reverse() const {
    CHCProblem res;
    for (const auto &c: clauses) {
        auto reversed {c};
        reversed.set_conclusion(c.get_premise());
        reversed.set_premise(c.get_conclusion());
        res.add_clause(reversed);
    }
    return res;
}

linked_hash_map<std::string, std::vector<Var>> CHCProblem::get_signature() const {
    linked_hash_map<std::string, std::vector<Var>> preds;
    for (const auto &c: clauses) {
        if (c.get_premise()) {
            preds.put(c.get_premise()->get_pred(), c.get_premise()->get_args());
        }
        if (c.get_conclusion()) {
            preds.put(c.get_conclusion()->get_pred(), c.get_conclusion()->get_args());
        }
    }
    return preds;
}

void CHCProblem::do_produce_model() {
    produce_model = true;
}

bool CHCProblem::get_produce_model() const {
    return produce_model;
}