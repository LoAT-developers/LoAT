#include "rule.hpp"

#include <utility>

#include "model.hpp"

ConsHash<Rule, Bools::Expr, Subs> Rule::cache;

unsigned Rule::next_id {0};

Rule::Rule(Bools::Expr  guard, Subs update): guard(std::move(guard)), update(std::move(update)), id(next_id++) {}

size_t Rule::CacheHash::operator()(const std::tuple<Bools::Expr, Subs> &args) const noexcept {
    size_t seed {42};
    boost::hash_combine(seed, std::get<0>(args));
    boost::hash_combine(seed, std::get<1>(args));
    return seed;
}

bool Rule::CacheEqual::operator()(const std::tuple<Bools::Expr, Subs> &args1, const std::tuple<Bools::Expr, Subs> &args2) const noexcept {
    return args1 == args2;
}

Rule::~Rule() {
    cache.erase(guard, update);
}

CellSet Rule::cells() const {
    CellSet res;
    guard->collectCells(res);
    update.collectCoDomainCells(res);
    return res;
}

RulePtr Rule::mk(const Bools::Expr& guard, const Subs& up) {
    return cache.from_cache(guard, up);
}

void Rule::collectVars(VarSet &vars) const {
    guard->collectVars(vars);
    update.collectVars(vars);
}

void Rule::collectCells(CellSet& cells) const {
    guard->collectCells(cells);
    for (const auto& [k,v]: update) {
        theory::apply(
            v,
            [&](const auto& v) {
                v->collectCells(cells);
            });
    }
}

VarSet Rule::vars() const {
    VarSet res;
    collectVars(res);
    return res;
}

RulePtr Rule::subs(const Subs& subs) const {
    return mk(guard->subs(subs), update.concat(subs));
}

RulePtr Rule::renameVars(const Renaming &subs) const {
    return mk(guard->renameVars(subs), update.concat(subs));
}

RulePtr Rule::withGuard(const Bools::Expr& guard) const {
    return mk(guard, update);
}

RulePtr Rule::withUpdate(const Subs &up) const {
    return mk(guard, up);
}

RulePtr Rule::chain(const RulePtr &that) const {
    return mk(guard && that->getGuard()->subs(update), that->getUpdate().compose(update));
}

Bools::Expr Rule::getGuard() const {
    return guard;
}

const Subs& Rule::getUpdate() const {
    return update;
}

unsigned Rule::getId() const {
    return id;
}

std::ostream& operator<<(std::ostream &s, const Rule &rule) {
    s << rule.getId() << ": ";
    s << rule.getGuard();
    if (rule.getUpdate().empty()) {
        return s;
    }
    s << " /\\ ";
    return s << rule.getUpdate();
}

bool Rule::isPoly() const {
    return guard->isPoly() && update.isPoly();
}

bool Rule::isLinear() const {
    return guard->isLinear() && update.isLinear();
}

std::ostream& operator<<(std::ostream &s, const RulePtr &idx) {
    return s << idx->getId();
}

std::ostream& operator<<(std::ostream &s, const Implicant &imp) {
    s << imp.first->getId() << ": ";
    const auto &up {imp.second->getUpdate()};
    if (imp.second->getGuard() != top()) {
        s << imp.second->getGuard();
        if (!up.empty()) {
            s << " /\\ " << up;
        }
    } else if (!up.empty()) {
        s << up;
    } else {
        s << top();
    }
    return s;
}

bool Rule::isDeterministic() const {
    return !std::ranges::any_of(vars(), theory::isTempVar);
}

bool Rule::hasNonTrivialNondeterminism() const {
    const auto gvars = guard->vars();
    if (std::ranges::any_of(gvars, theory::isTempVar)) {
        return true;
    }
    for (const auto &[k,v]: update) {
        if (gvars.contains(k) && theory::apply(v, [&](const auto v) {
            return std::ranges::any_of(v->vars(), theory::isTempVar);
        })) {
            return true;
        }
        if (theory::apply(v, [&](const Arrays<Arith>::Expr& v) {
            return v->hasNonTrivialNondeterminism();
        }, [&](const Bools::Expr& v) {
            if (std::ranges::any_of(v->vars(), theory::isTempVar)) {
                return !v->isVar() || !v->isVar().value()->isTempVar() || v->isVar().value()->dim() > 0;
            }
            return false;
        })) {
            return true;
        }
    }
    return false;
}

size_t Rule::hash() const {
    size_t hash {0};
    boost::hash_combine(hash, std::hash<Bools::Expr>{}(guard));
    boost::hash_combine(hash, update.hash());
    return hash;
}

RulePtr Rule::syntacticImplicant(ModelPtr m) const {
    LitSet lits;
    const auto sat = m->syntacticImplicant(guard, lits);
    assert(sat);
    Subs u;
    for (const auto& p: update) {
        theory::apply(
            p,
            [&](const std::pair<Bools::Var, Bools::Expr>& p) {
                u.put(p);
            },
            [&](const auto& p) {
                const auto& [k,v] = p;
                u.put(k, v->syntacticImplicant(m, lits));
            });
    }
    return mk(bools::mkAnd(lits), u);
}

size_t hash_value(const Rule &r) {
    return r.hash();
}

RulePtr Rule::renameTmpVars() const {
    Renaming s;
    for (const auto &x: vars()) {
        theory::apply(
            x,
            [&](const auto& x) {
                using T = decltype(theory::theory(x));
                if (x->isTempVar()) {
                    s.insert(x, T::next(x->dim()));
                }
            });
    }
    return renameVars(s);
}

bool Rule::isHavoced(const Var& x) const {
    return theory::apply(
        x,
        [&](const auto& x) {
            const auto updated = update.get(x);
            if (const auto y = updated->isVar()) {
                return (*y)->isTempVar() && !guard->vars().contains(*y) && std::ranges::all_of(
                    update, [&](const auto& p) {
                        return Subs::first(p) == Var(x) || theory::apply(Subs::second(p), [&](const auto& p) {
                            return !p->vars().contains(*y);
                        });
                    });
            }
            return false;
        }
    );
}
