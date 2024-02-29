#pragma once

#include "theory.hpp"
#include "model.hpp"

class Transition {

private:

    static std::unordered_map<BoolExprPtr, Transition> cache;
    BoolExprPtr formula;
    std::shared_ptr<const linked_hash_map<Var, Var>> vm;
    unsigned id;

    static unsigned next_id;

    explicit Transition(const BoolExprPtr formula, std::shared_ptr<const linked_hash_map<Var, Var>> var_map);

public:

    static Transition build(const BoolExprPtr formula, std::shared_ptr<const linked_hash_map<Var, Var>> var_map);

    Transition subs(const Subs &subs) const;

    VarSet vars() const;

    void collectVars(VarSet &vars) const;

    std::shared_ptr<const linked_hash_map<Var, Var>> var_map() const;

    // std::strong_ordering operator<=>(const Transition &that) const;

    unsigned getId() const;

    size_t hash() const;

    bool operator==(const Transition &that) const;

    BoolExprPtr toBoolExpr() const;

    Transition syntacticImplicant(const Model &model) const;

    Transition linearize(const ArithVarPtr x) const;

    Transition toMinusInfinity(const ArithVarPtr x) const;

    Transition toInfinity(const ArithVarPtr x) const;

};

std::ostream& operator<<(std::ostream &s, const Transition &rule);

template<>
struct std::hash<Transition> {
    std::size_t operator()(const Transition& x) const noexcept {
        return x.hash();
    }
};

size_t hash_value(const Transition &rel);
