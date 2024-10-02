#pragma once

#include <vector>

#include "theory.hpp"
#include "subs.hpp"
#include "renaming.hpp"

class Rule;

using RulePtr = cpp::not_null<const Rule*>;

class Rule {
private:
    Bools::Expr guard;
    Subs update;
    unsigned id;

    static unsigned next_id;

    struct CacheEqual {
        bool operator()(const std::tuple<Bools::Expr, Subs> &args1, const std::tuple<Bools::Expr, Subs> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<Bools::Expr, Subs> &args) const noexcept;
    };

    static ConsHash<Rule, Rule, CacheHash, CacheEqual, Bools::Expr, Subs> cache;

public:

    Rule(const Bools::Expr guard, const Subs &update);

    static RulePtr mk(const Bools::Expr guard, const Subs up);

    const Bools::Expr getGuard() const;

    template <ITheory Th>
    const typename Th::Subs& getUpdate() const {
        return update.get<Th>();
    }

    const Subs& getUpdate() const;

    RulePtr subs(const Subs &subs) const;

    RulePtr renameVars(const Renaming &subs) const;

    RulePtr withGuard(const Bools::Expr guard) const;

    RulePtr withUpdate(const Subs &up) const;

    VarSet vars() const;

    void collectVars(VarSet &vars) const;

    RulePtr chain(const RulePtr &that) const;

    bool isPoly() const;

    unsigned getId() const;

    bool isDeterministic() const;

    RulePtr renameTmpVars() const;

    size_t hash() const;

};

std::ostream& operator<<(std::ostream &s, const Rule &rule);

using Implicant = std::pair<RulePtr, Bools::Expr>;

std::ostream& operator<<(std::ostream &s, const RulePtr &idx);
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
