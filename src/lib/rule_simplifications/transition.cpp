#include "transition.hpp"

unsigned Transition::next_id {0};

Transition::Transition(const BoolExpr formula, std::shared_ptr<const linked_hash_map<Var, Var>> vm): formula(formula), vm(vm), id(next_id) {
    ++next_id;
}

Transition Transition::subs(const Subs &subs) const {
    return Transition(formula->subs(subs), vm);
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
    return Transition(formula->syntacticImplicant(subs), vm);
}

Transition Transition::linearize(const NumVar &x) const {
    return Transition(formula->linearize(x), vm);
}

Transition Transition::toMinusInfinity(const NumVar &x) const {
    return Transition(formula->toMinusInfinity(x), vm);
}

Transition Transition::toInfinity(const NumVar &x) const {
    return Transition(formula->toInfinity(x), vm);
}

std::shared_ptr<const linked_hash_map<Var, Var>> Transition::var_map() const {
    return vm;
}

std::ostream& operator<<(std::ostream &s, const Transition &t) {
    return s << t.getId() << ": " << t.toBoolExpr() << std::endl;
}
