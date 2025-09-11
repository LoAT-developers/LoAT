#pragma once

#include <vector>

#include "theory.hpp"
#include "lvaluesubs.hpp"
#include "subs.hpp"

class Rule;

using RulePtr = cpp::not_null<std::shared_ptr<const Rule>>;

class Rule {

    Bools::Expr guard;
    LValueSubs update;
    unsigned id;

    static unsigned next_id;

    struct CacheEqual {
        bool operator()(const std::tuple<Bools::Expr, LValueSubs> &args1, const std::tuple<Bools::Expr, LValueSubs> &args2) const noexcept;
    };

    struct CacheHash {
        size_t operator()(const std::tuple<Bools::Expr, LValueSubs> &args) const noexcept;
    };

    static ConsHash<Rule, Rule, CacheHash, CacheEqual, Bools::Expr, LValueSubs> cache;

public:

    Rule(Bools::Expr  guard, LValueSubs update);

    ~Rule();

    static RulePtr mk(const Bools::Expr& guard, const LValueSubs& up);

    Bools::Expr getGuard() const;

    const LValueSubs& getUpdate() const;

    RulePtr subs(const Subs &subs) const;

    RulePtr renameVars(const Renaming &subs) const;

    RulePtr withGuard(const Bools::Expr& guard) const;

    RulePtr withUpdate(const LValueSubs &up) const;

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
