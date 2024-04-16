#pragma once

#include "theory.hpp"
#include "model.hpp"

class Transition {

private:

    static std::unordered_map<Bools::Expr, Transition> cache;
    Bools::Expr formula;
    std::shared_ptr<const linked_hash_map<Var, Var>> vm;
    unsigned id;

    static unsigned next_id;

    explicit Transition(const Bools::Expr formula, std::shared_ptr<const linked_hash_map<Var, Var>> var_map);

public:

    static Transition build(const Bools::Expr formula, std::shared_ptr<const linked_hash_map<Var, Var>> var_map);

    Transition subs(const Subs &subs) const;

    VarSet vars() const;

    void collectVars(VarSet &vars) const;

    std::shared_ptr<const linked_hash_map<Var, Var>> var_map() const;

    // std::strong_ordering operator<=>(const Transition &that) const;

    unsigned getId() const;

    size_t hash() const;

    bool operator==(const Transition &that) const;

    Bools::Expr toBoolExpr() const;

    Transition syntacticImplicant(const Model &model) const;

    Transition linearize(const Arith::Var x) const;

    Transition toMinusInfinity(const Arith::Var x) const;

    Transition toInfinity(const Arith::Var x) const;

};

std::ostream& operator<<(std::ostream &s, const Transition &rule);

template<>
struct std::hash<Transition> {
    std::size_t operator()(const Transition& x) const noexcept {
        return x.hash();
    }
};

size_t hash_value(const Transition &rel);
