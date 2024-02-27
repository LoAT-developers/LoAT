#include "transition.hpp"

std::unordered_map<BoolExpr, Transition> Transition::cache {};

unsigned Transition::next_id {0};

Transition::Transition(const BoolExpr formula, std::shared_ptr<const linked_hash_map<Var, Var>> vm): formula(formula), vm(vm), id(next_id) {
    ++next_id;
}

Transition Transition::build(const BoolExpr formula, std::shared_ptr<const linked_hash_map<Var, Var>> vm) {
    const auto it {cache.find(formula)};
    if (it == cache.end()) {
        const Transition res {formula, vm};
        cache.emplace(formula, res);
        return res;
    } else {
        return it->second;
    }
}

Transition Transition::subs(const Subs &subs) const {
    return build(formula->subs(subs), vm);
}

VarSet Transition::vars() const {
    return formula->vars();
}

void Transition::collectVars(VarSet &vars) const {
    formula->collectVars(vars);
}

// std::strong_ordering Transition::operator<=>(const Transition &that) const {
//     return formula <=> that.formula;
// }

unsigned Transition::getId() const {
    return id;
}

size_t Transition::hash() const {
    return std::hash<BoolExpr>{}(formula);
}

size_t hash_value(const Transition &x) {
    return x.hash();
}

bool Transition::operator==(const Transition &that) const {
    return formula == that.formula;
}

BoolExpr Transition::toBoolExpr() const {
    return formula;
}

Transition Transition::syntacticImplicant(const Subs &subs) const {
    return build(formula->syntacticImplicant(subs), vm);
}

Transition Transition::linearize(const ArithVarPtr x) const {
    return build(formula->linearize(x), vm);
}

Transition Transition::toMinusInfinity(const ArithVarPtr x) const {
    return build(formula->toMinusInfinity(x), vm);
}

Transition Transition::toInfinity(const ArithVarPtr x) const {
    return build(formula->toInfinity(x), vm);
}

std::shared_ptr<const linked_hash_map<Var, Var>> Transition::var_map() const {
    return vm;
}

std::ostream& operator<<(std::ostream &s, const Transition &t) {
    return s << t.getId() << ": " << t.toBoolExpr();
}
