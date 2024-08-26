#include "chcproblem.hpp"

Lhs::Lhs(const std::string &pred, const std::vector<Var> &args): pred(pred), args(args) {}

bool Lhs::is_linear() const {
    linked_hash_set<Var> set {args.begin(), args.end()};
    return set.size() == args.size();
}

sexpresso::Sexp Lhs::to_smtlib(const var_map &vars) const {
    sexpresso::Sexp res {pred};
    for (const auto &arg: args) {
        res.addChild(vars.right.at(arg));
    }
    return res;
}

Lhs Lhs::subs(const Subs &subs) const {
    std::vector<Var> new_args;
    for (const auto &arg: args) {
        new_args.push_back(*theory::vars(subs.get(arg)).begin());
    }
    return Lhs(pred, new_args);
}

std::ostream& operator<<(std::ostream &s, const Lhs &f) {
    s << f.pred << " ::";
    for (const auto &x: f.args) {
        s << " " << theory::to_type(theory::toExpr(x));
    }
    return s;
}

std::ostream& operator<<(std::ostream &s, const Clause &c) {
    if (c.premise) {
        s << "( " << c.premise->get_pred();
        for (const auto &arg: c.premise->get_args()) {
            s << arg << " ";
        }
        s << ") /\\ ";
    }
    s << c.constraint << " ==> ";
    if (c.conclusion) {
        s << "( " << c.conclusion->get_pred();
        for (const auto &arg: c.conclusion->get_args()) {
            s << arg << " ";
        }
        s << ")";
    } else {
        s << "_|_";
    }
    return s;
}

std::size_t hash_value(const Lhs &f) {
    size_t seed {42};
    boost::hash_combine(seed, f.pred);
    boost::hash_combine(seed, boost::hash_range(f.args.begin(), f.args.end()));
    return seed;
}

const std::string& Lhs::get_pred() const {
    return pred;
}

const std::vector<Var>& Lhs::get_args() const {
    return args;
}

FunApp::FunApp(const std::string &pred, const std::vector<Expr> &args): pred(pred), args(args) {}

sexpresso::Sexp FunApp::to_smtlib(const var_map &vars) const {
    sexpresso::Sexp res {pred};
    for (const auto &arg: args) {
        res.addChild(theory::to_smtlib(arg, [&](const auto &x) {return vars.right.at(x);}));
    }
    return res;
}

FunApp FunApp::subs(const Subs &subs) const {
    std::vector<Expr> new_args;
    for (const auto &arg: args) {
        new_args.push_back(subs(arg));
    }
    return FunApp(pred, new_args);
}

std::ostream& operator<<(std::ostream &s, const FunApp &f) {
    s << f.pred << " ::";
    for (const auto &x: f.args) {
        s << " " << theory::to_type(x);
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

const std::vector<Expr>& FunApp::get_args() const {
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

void Clause::add_var(const std::string &name, const Var &x) {
    m_vars.left.insert(var_map::left_value_type(name, x));
}

void Clause::set_premise(const std::optional<Lhs> &premise) {
    this->premise = premise;
}

void Clause::set_conclusion(const std::optional<FunApp> &conclusion) {
    this->conclusion = conclusion;
}

void Clause::set_constraint(const Bools::Expr e) {
    this->constraint = e;
}

void Clause::add_constraint(const Bools::Expr e) {
    this->constraint = this->constraint && e;
}

const std::optional<Lhs>& Clause::get_premise() const {
    return premise;
}

const std::optional<FunApp>& Clause::get_conclusion() const {
    return conclusion;
}

Bools::Expr Clause::get_constraint() const {
    return constraint;
}

const var_map& Clause::get_vars() const {
    return m_vars;
}

Clause Clause::subs(const Subs &subs) const {
    Clause res;
    if (premise) {
        res.set_premise(premise->subs(subs));
    }
    if (conclusion) {
        res.set_conclusion(conclusion->subs(subs));
    }
    res.set_constraint(subs(constraint));
    return res;
}

VarSet Clause::vars() const {
    VarSet res;
    if (premise) {
        for (const auto &x: premise->get_args()) {
            res.insert(x);
        }
    }
    if (conclusion) {
        for (const auto &x: conclusion->get_args()) {
            theory::collectVars(x, res);
        }
    }
    constraint->collectVars(res);
    return res;
}

sexpresso::Sexp Clause::to_smtlib() const {
    sexpresso::Sexp assertion{"assert"};
    sexpresso::Sexp forall{"forall"};
    sexpresso::Sexp variables;
    std::map<std::string, sexpresso::Sexp> var_map;
    for (const auto &[_,x]: m_vars) {
        const auto var {m_vars.right.at(x)};
        const auto type {toString(theory::to_type(x))};
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
        const auto it{m_vars.right.find(x)};
        return it == m_vars.right.end() ? theory::getName(x) : it->second;
    })};
    if (premise) {
        sexpresso::Sexp band{"and"};
        band.addChild(premise->to_smtlib(m_vars));
        band.addChild(constr);
        imp.addChild(band);
    } else {
        imp.addChild(constr);
    }
    if (conclusion) {
        imp.addChild(conclusion->to_smtlib(m_vars));
    } else {
        imp.addChild("false");
    }
    forall.addChild(imp);
    assertion.addChild(forall);
    return assertion;
}

std::size_t hash_value(const Clause &c) {
    size_t seed {42};
    boost::hash_combine(seed, c.premise);
    boost::hash_combine(seed, c.constraint);
    boost::hash_combine(seed, c.conclusion);
    return seed;
}

bool operator==(const Clause& c1, const Clause& c2) {
    return c1.premise == c2.premise && c1.constraint == c2.constraint && c1.conclusion == c2.conclusion;
}

const Clause* CHCProblem::add_clause(const Clause &c) {
    return &*clauses.insert(c).first;
}

void CHCProblem::remove_clause(const Clause &c) {
    clauses.erase(c);
}

const linked_hash_set<Clause>& CHCProblem::get_clauses() const {
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
            types.addChild(toString(x));
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
        std::vector<Bools::Expr> constr {c.get_constraint()};
        Clause reversed;
        if (const auto conc {c.get_conclusion()}) {
            std::vector<Var> lhs_args;
            for (const auto &arg: conc->get_args()) {
                if (const auto &x {theory::is_var(arg)}) {
                    lhs_args.emplace_back(*x);
                } else {
                    const auto y {theory::next(arg)};
                    lhs_args.emplace_back(y);
                    constr.push_back(theory::mkEq(theory::toExpr(y), arg));
                }
            }
            reversed.set_premise(Lhs(conc->get_pred(), lhs_args));
        }
        if (const auto prem {c.get_premise()}) {
            std::vector<Expr> rhs_args;
            for (const auto &x: prem->get_args()) {
                rhs_args.emplace_back(theory::toExpr(x));
            }
            reversed.set_conclusion(FunApp(prem->get_pred(), rhs_args));
        }
        reversed.set_constraint(bools::mkAnd(constr));
        res.add_clause(reversed);
    }
    return res;
}

linked_hash_map<std::string, std::vector<theory::Types>> CHCProblem::get_signature() const {
    linked_hash_map<std::string, std::vector<theory::Types>> preds;
    for (const auto &c: clauses) {
        if (c.get_premise()) {
            std::vector<theory::Types> types;
            for (const auto &x: c.get_premise()->get_args()) {
                types.emplace_back(theory::to_type(x));
            }
            preds.put(c.get_premise()->get_pred(), types);
        }
        if (c.get_conclusion()) {
            std::vector<theory::Types> types;
            for (const auto &x: c.get_conclusion()->get_args()) {
                types.emplace_back(theory::to_type(x));
            }
            preds.put(c.get_conclusion()->get_pred(), types);
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
