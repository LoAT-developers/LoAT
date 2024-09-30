#include "chcproblem.hpp"
#include "optional.hpp"

std::ostream& operator<<(std::ostream &s, const ClausePtr c) {
    if (c->premise) {
        s << (*c->premise)->get_pred() << "(";
        auto first {true};
        for (const auto &arg: (*c->premise)->get_args()) {
            if (first) {
                first = false;
            } else {
                s << ", ";
            }
            s << arg;
        }
        s << ") /\\ ";
    }
    s << c->get_constraint() << " ==> ";
    if (c->conclusion) {
        s << (*c->conclusion)->get_pred() << "(";
        auto first {true};
        for (const auto &arg: (*c->conclusion)->get_args()) {
            if (first) {
                first = false;
            } else {
                s << ", ";
            }
            s << arg;
        }
        s << ")";
    } else {
        s << "_|_";
    }
    return s;
}

bool FunApp::CacheEqual::operator()(const std::tuple<std::string, std::vector<Expr>> &args1, const std::tuple<std::string, std::vector<Expr>> &args2) const noexcept {
    return args1 == args2;
}

size_t FunApp::CacheHash::operator()(const std::tuple<std::string, std::vector<Expr>> &args) const noexcept {
    size_t seed {0};
    boost::hash_combine(seed, std::get<0>(args));
    boost::hash_combine(seed, std::get<1>(args));
    return seed;
}

ConsHash<FunApp, FunApp, FunApp::CacheHash, FunApp::CacheEqual, std::string, std::vector<Expr>> FunApp::cache(512);

FunApp::FunApp(const std::string &pred, const std::vector<Expr> &args): pred(pred), args(args) {}

FunApp::~FunApp() {
    cache.erase(pred, args);
}

FunAppPtr FunApp::mk(const std::string &pred, const std::vector<Expr> &args) {
    return cache.from_cache(pred, args);
}

sexpresso::Sexp FunApp::to_smtlib() const {
    sexpresso::Sexp res {pred};
    for (const auto &arg: args) {
        res.addChild(theory::to_smtlib(arg));
    }
    return res;
}

FunAppPtr FunApp::subs(const Subs &subs) const {
    std::vector<Expr> new_args;
    for (const auto &arg: args) {
        new_args.push_back(subs(arg));
    }
    return FunApp::mk(pred, new_args);
}

FunAppPtr FunApp::rename_vars(const Renaming &subs) const {
    std::vector<Expr> new_args;
    for (const auto &arg: args) {
        new_args.push_back(subs(arg));
    }
    return FunApp::mk(pred, new_args);
}

std::ostream& operator<<(std::ostream &s, const FunAppPtr f) {
    s << f->pred << " ::";
    for (const auto &x: f->args) {
        s << " " << theory::to_type(x);
    }
    return s;
}

const std::string& FunApp::get_pred() const {
    return pred;
}

const std::vector<Expr>& FunApp::get_args() const {
    return args;
}

bool Clause::CacheEqual::operator()(const Clause::Args &args1, const Clause::Args &args2) const noexcept {
    return args1 == args2;
}

size_t Clause::CacheHash::operator()(const Clause::Args &args) const noexcept {
    size_t seed {0};
    boost::hash_combine(seed, std::get<0>(args));
    boost::hash_combine(seed, std::get<1>(args));
    boost::hash_combine(seed, std::get<2>(args));
    return seed;
}

ConsHash<Clause, Clause, Clause::CacheHash, Clause::CacheEqual, std::optional<FunAppPtr>, Bools::Expr, std::optional<FunAppPtr>> Clause::cache(256);

Clause::Clause(const std::optional<FunAppPtr> premise, const Bools::Expr constraint, const std::optional<FunAppPtr> conclusion): premise(premise), constraint(constraint), conclusion(conclusion) {}

Clause::~Clause() {
    cache.erase(premise, constraint, conclusion);
}

ClausePtr Clause::mk(const std::optional<FunAppPtr> premise, const Bools::Expr constraint, const std::optional<FunAppPtr> conclusion) {
    return cache.from_cache(premise, constraint, conclusion);
}

bool Clause::is_fact() const {
    return !premise.has_value();
}

bool Clause::is_query() const {
    return !conclusion.has_value();
}

std::optional<FunAppPtr> Clause::get_premise() const {
    return premise;
}

std::optional<FunAppPtr> Clause::get_conclusion() const {
    return conclusion;
}

Bools::Expr Clause::get_constraint() const {
    return constraint;
}

ClausePtr Clause::subs(const Subs &subs) const {
    const auto prem {map<FunAppPtr, FunAppPtr>(premise, [&](const auto p) {
        return p->subs(subs);
    })};
    const auto concl {map<FunAppPtr, FunAppPtr>(conclusion, [&](const auto c) {
        return c->subs(subs);
    })};
    return Clause::mk(prem, subs(constraint), concl);
}

ClausePtr Clause::rename_vars(const Renaming &subs) const {
    const auto prem {map<FunAppPtr, FunAppPtr>(premise, [&](const auto p) {
        return p->rename_vars(subs);
    })};
    const auto concl {map<FunAppPtr, FunAppPtr>(conclusion, [&](const auto c) {
        return c->rename_vars(subs);
    })};
    return Clause::mk(prem, subs(constraint), concl);
}

VarSet Clause::vars() const {
    VarSet res;
    if (premise) {
        for (const auto &x: (*premise)->get_args()) {
            theory::collectVars(x, res);
        }
    }
    if (conclusion) {
        for (const auto &x: (*conclusion)->get_args()) {
            theory::collectVars(x, res);
        }
    }
    get_constraint()->collectVars(res);
    return res;
}

void CHCProblem::add_clause(const ClausePtr c) {
    clauses.insert(c);
}

void CHCProblem::remove_clause(const ClausePtr c) {
    clauses.erase(c);
}

const linked_hash_set<ClausePtr>& CHCProblem::get_clauses() const {
    return clauses;
}

sexpresso::Sexp Clause::to_smtlib() const {
    sexpresso::Sexp assertion{"assert"};
    sexpresso::Sexp forall{"forall"};
    sexpresso::Sexp variables;
    std::map<std::string, sexpresso::Sexp> var_map;
    for (const auto &x: vars()) {
        const auto type {toString(theory::to_type(x))};
        var_map.emplace(theory::getName(x), type);
    }
    for (const auto &[name, type]: var_map) {
        sexpresso::Sexp var {name};
        var.addChild(type);
        variables.addChild(var);
    }
    forall.addChild(variables);
    sexpresso::Sexp imp{"=>"};
    const auto constr{constraint->to_smtlib()};
    if (premise) {
        sexpresso::Sexp band{"and"};
        band.addChild((*premise)->to_smtlib());
        band.addChild(constr);
        imp.addChild(band);
    } else {
        imp.addChild(constr);
    }
    if (conclusion) {
        imp.addChild((*conclusion)->to_smtlib());
    } else {
        imp.addChild("false");
    }
    forall.addChild(imp);
    assertion.addChild(forall);
    return assertion;
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
        res.addChild(c->to_smtlib());
    }
    return res;
}

linked_hash_map<std::string, std::vector<theory::Types>> CHCProblem::get_signature() const {
    linked_hash_map<std::string, std::vector<theory::Types>> preds;
    for (const auto &c: clauses) {
        if (const auto prem {c->get_premise()}) {
            std::vector<theory::Types> types;
            for (const auto &x: (*prem)->get_args()) {
                types.emplace_back(theory::to_type(x));
            }
            preds.put((*prem)->get_pred(), types);
        }
        if (const auto conc {c->get_conclusion()}) {
            std::vector<theory::Types> types;
            for (const auto &x: (*conc)->get_args()) {
                types.emplace_back(theory::to_type(x));
            }
            preds.put((*conc)->get_pred(), types);
        }
    }
    return preds;
}

std::ostream& operator<<(std::ostream &s, const CHCPtr t) {
    for (const auto &c: t->get_clauses()) {
        s << c << std::endl;
    }
    return s;
}
