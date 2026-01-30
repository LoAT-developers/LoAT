#include "chcproblem.hpp"
#include "optional.hpp"
#include "theory.hpp"

#include <map>
#include <utility>

std::ostream& operator<<(std::ostream &s, const ClausePtr& c) {
    if (!c->premise.empty()) {
        auto first = true;
        for (const auto& p: c->premise) {
            if (first) {
                first = false;
            } else {
                s << " /\\ ";
            }
            s << p->get_pred() << "(";
            auto first {true};
            for (const auto &arg: p->get_args()) {
                if (first) {
                    first = false;
                } else {
                    s << ", ";
                }
                s << arg;
            }
            s << ")";
        }
        if (c->get_constraint() != top()) {
            s << " /\\ " << c->get_constraint();
        }
    } else {
        s << c->get_constraint();
    }
    s << " ==> ";
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

ConsHash<FunApp, std::string, std::vector<Expr>> FunApp::cache;

FunApp::FunApp(std::string pred, const std::vector<Expr> &args): pred(std::move(pred)), args(args) {}

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
    return mk(pred, new_args);
}

FunAppPtr FunApp::rename_vars(const Renaming &subs) const {
    std::vector<Expr> new_args;
    for (const auto &arg: args) {
        new_args.push_back(subs(arg));
    }
    return mk(pred, new_args);
}

size_t FunApp::max_arity(const theory::Type& type) const {
    unsigned res{0};
    for (const auto &x : args) {
        if (theory::to_type(x) == type) {
            ++res;
        }
    }
    return res;
}

size_t FunApp::max_dim(const theory::BaseType type) const {
    size_t res{0};
    for (const auto &x : args) {
        const auto t = theory::to_type(x);
        if (t.base == type) {
            res = std::max(res, t.dim);
        }
    }
    return res;
}

std::ostream& operator<<(std::ostream &s, const FunAppPtr& f) {
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

bool Clause::CacheEqual::operator()(const Args &args1, const Args &args2) const noexcept {
    return args1 == args2;
}

size_t Clause::CacheHash::operator()(const Args &args) const noexcept {
    size_t seed {0};
    boost::hash_combine(seed, std::get<0>(args));
    boost::hash_combine(seed, std::get<1>(args));
    boost::hash_combine(seed, std::get<2>(args));
    return seed;
}

ConsHash<Clause, std::vector<FunAppPtr>, Bools::Expr, std::optional<FunAppPtr>> Clause::cache;

Clause::Clause(const std::vector<FunAppPtr>& premise, Bools::Expr  constraint, const std::optional<FunAppPtr>& conclusion): premise(premise), constraint(std::move(constraint)), conclusion(conclusion) {}

Clause::~Clause() {
    cache.erase(premise, constraint, conclusion);
}

ClausePtr Clause::mk(const std::vector<FunAppPtr>& premise, const Bools::Expr& constraint, const std::optional<FunAppPtr>& conclusion) {
    return cache.from_cache(premise, constraint, conclusion);
}

bool Clause::is_fact() const {
    return premise.empty();
}

bool Clause::is_query() const {
    return !conclusion.has_value();
}

bool Clause::is_linear() const {
    return premise.size() <= 1;
}

std::vector<FunAppPtr> Clause::get_premise() const {
    return premise;
}

std::optional<FunAppPtr> Clause::get_conclusion() const {
    return conclusion;
}

Bools::Expr Clause::get_constraint() const {
    return constraint;
}

ClausePtr Clause::subs(const Subs &subs) const {
    std::vector<FunAppPtr> prem;
    for (const auto& p: premise) {
        prem.emplace_back(p->subs(subs));
    }
    const auto concl {map<FunAppPtr, FunAppPtr>(conclusion, [&](const auto& c) {
        return c->subs(subs);
    })};
    return mk(prem, constraint->subs(subs), concl);
}

ClausePtr Clause::rename_vars(const Renaming &subs) const {
    std::vector<FunAppPtr> prem;
    for (const auto& p: premise) {
        prem.emplace_back(p->rename_vars(subs));
    }
    const auto concl {map<FunAppPtr, FunAppPtr>(conclusion, [&](const auto& c) {
        return c->rename_vars(subs);
    })};
    return mk(prem, constraint->renameVars(subs), concl);
}

VarSet Clause::vars() const {
    VarSet res;
    for (const auto& p: premise) {
        for (const auto &x: p->get_args()) {
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

void CHCProblem::add_clause(const ClausePtr& c) {
    clauses.insert(c);
}

void CHCProblem::remove_clause(const ClausePtr& c) {
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
    if (!premise.empty()) {
        sexpresso::Sexp band{"and"};
        for (const auto& p: premise) {
            band.addChild(p->to_smtlib());
        }
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

size_t Clause::max_arity(const theory::Type& type) const {
    size_t p_arity = 0;
    for (const auto& p: premise) {
        p_arity = std::max(p_arity, p->max_arity(type));
    }
    const auto c_arity = conclusion ? (*conclusion)->max_arity(type) : 0;
    return std::max(p_arity, c_arity);
}

size_t Clause::max_dim(const theory::BaseType type) const {
    size_t p_dim = 0;
    for (const auto& p: premise) {
        p_dim = std::max(p_dim, p->max_dim(type));
    }
    const auto c_dim = conclusion ? (*conclusion)->max_dim(type) : 0;
    return std::max(p_dim, c_dim);
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

linked_hash_map<std::string, std::vector<theory::Type>> CHCProblem::get_signature() const {
    linked_hash_map<std::string, std::vector<theory::Type>> preds;
    for (const auto &c: clauses) {
        for (const auto& p: c->get_premise()) {
            std::vector<theory::Type> types;
            for (const auto &x: p->get_args()) {
                types.emplace_back(theory::to_type(x));
            }
            preds.put(p->get_pred(), types);
        }
        if (const auto conc {c->get_conclusion()}) {
            std::vector<theory::Type> types;
            for (const auto &x: (*conc)->get_args()) {
                types.emplace_back(theory::to_type(x));
            }
            preds.put((*conc)->get_pred(), types);
        }
    }
    return preds;
}

bool CHCProblem::is_linear() const {
    return std::ranges::all_of(clauses, [](const auto& c) {
        return c->is_linear();
    });
}

size_t CHCProblem::max_arity(const theory::Type& type) const {
    size_t res{0};
    for (const auto &c : clauses) {
        res = std::max(res, c->max_arity(type));
    }
    return res;
}

size_t CHCProblem::max_dim(const theory::BaseType type) const {
    size_t res{0};
    for (const auto &c : clauses) {
        res = std::max(res, c->max_dim(type));
    }
    return res;
}

std::ostream& operator<<(std::ostream &s, const CHCPtr& t) {
    for (const auto &c: t->get_clauses()) {
        s << c << std::endl;
    }
    return s;
}
