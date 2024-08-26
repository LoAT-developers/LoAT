#include "rule.hpp"

using namespace std;

unsigned Rule::next_id {0};

Rule::Rule(const Bools::Expr guard, const Subs &update): guard(guard), update(update), id(next_id++) {}

void Rule::collectVars(VarSet &vars) const {
    guard->collectVars(vars);
    update.collectVars(vars);
}

VarSet Rule::vars() const {
    VarSet res;
    collectVars(res);
    return res;
}

Rule Rule::subs(const Subs &subs) const {
    return Rule(subs(guard), update.concat(subs));
}

Rule Rule::withGuard(const Bools::Expr guard) const {
    return Rule(guard, update);
}

Rule Rule::withUpdate(const Subs &update) const {
    return Rule(guard, update);
}

Rule Rule::chain(const Rule &that) const {
    return Rule(guard && update(that.getGuard()), that.getUpdate().compose(update));
}

const Bools::Expr Rule::getGuard() const {
    return guard;
}

const Subs& Rule::getUpdate() const {
    return update;
}

unsigned Rule::getId() const {
    return id;
}

ostream& operator<<(ostream &s, const Rule &rule) {
    return s << rule.getId() << ": " << rule.getGuard() << " /\\ " << rule.getUpdate();
}

bool Rule::isPoly() const {
    return guard->isPoly() && update.isPoly();
}

std::ostream& operator<<(std::ostream &s, const TransIdx &idx) {
    return s << idx->getId();
}

std::ostream& operator<<(std::ostream &s, const Implicant &imp) {
    s << imp.first->getId() << ": ";
    const auto &up {imp.first->getUpdate()};
    if (imp.second != top()) {
        s << imp.second;
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
    for (const auto &x: vars()) {
        if (theory::isTempVar(x)) {
            return false;
        }
    }
    return true;
}

size_t Rule::hash() const {
    size_t hash {0};
    boost::hash_combine(hash, std::hash<Bools::Expr>{}(guard));
    boost::hash_combine(hash, update.hash());
    return hash;
}

size_t hash_value(const Rule &r) {
    return r.hash();
}
