#pragma once

#include <vector>

#include "theory.hpp"
#include "subs.hpp"
#include "renaming.hpp"

class Rule {
private:
    Bools::Expr guard;
    Subs update;
    unsigned id;

    static unsigned next_id;

public:

    Rule(const Bools::Expr guard, const Subs &update);

    const Bools::Expr getGuard() const;

    template <ITheory Th>
    const typename Th::Subs& getUpdate() const {
        return update.get<Th>();
    }

    const Subs& getUpdate() const;

    Rule subs(const Subs &subs) const;

    Rule renameVars(const Renaming &subs) const;

    Rule withGuard(const Bools::Expr guard) const;

    Rule withUpdate(const Subs &up) const;

    VarSet vars() const;

    void collectVars(VarSet &vars) const;

    Rule chain(const Rule &that) const;

    bool isPoly() const;

    unsigned getId() const;

    bool isDeterministic() const;

    Rule renameTmpVars() const;

    size_t hash() const;

    bool operator==(const Rule &that) const = default;

};

/**
 * For debugging output (not very readable)
 */
std::ostream& operator<<(std::ostream &s, const Rule &rule);

template<>
struct std::hash<Rule> {
    std::size_t operator()(const Rule& x) const noexcept {
        return x.hash();
    }
};

size_t hash_value(const Rule &r);

using TransIdx = const Rule*;
using Implicant = std::pair<TransIdx, Bools::Expr>;

std::ostream& operator<<(std::ostream &s, const TransIdx &idx);
std::ostream& operator<<(std::ostream &s, const Implicant &imp);

template<>
struct std::hash<Implicant> {
    std::size_t operator()(const Implicant& x) const noexcept {
        std::size_t seed {0};
        boost::hash_combine(seed, x.first);
        boost::hash_combine(seed, x.second);
        return seed;
    }
};
