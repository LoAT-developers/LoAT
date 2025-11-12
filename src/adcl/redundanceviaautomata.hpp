#pragma once

#include "theory.hpp"
#include "rule.hpp"

#include <faudes/libfaudes.h>

class Automaton {

    friend class RedundanceViaAutomata;

    static long next_char;
    static Automaton covered;
    static Automaton accelerated;
    faudes::Generator t {};
    std::string str {};

public:

    static Automaton singleton();

    void concat(const Automaton &that);
    void prepend(const Automaton &that);
    void kleene_plus();
    void unite(const Automaton &that);

    bool subset(const Automaton &that) const;
    bool empty() const;

    faudes::EventSet get_alphabet() const;

    std::string to_string() const;

    friend std::ostream& operator<<(std::ostream &s, const Automaton &a);

};

class RedundanceViaAutomata {

public:

    Automaton get_singleton_language(const RulePtr& idx, const Bools::Expr &guard);
    std::optional<Automaton> get_language(const RulePtr& idx);
    void set_language(const RulePtr& idx, const Automaton &t);
    void delete_language(const RulePtr& idx);
    static bool is_redundant(const Automaton &t);
    static bool is_accelerated(const Automaton &t);
    static void mark_as_redundant(const Automaton &t);
    static void mark_as_accelerated(const Automaton &t);
    static void concat(Automaton &t1, const Automaton &t2);
    static void prepend(const Automaton &t1, Automaton &t2);
    static void transitive_closure(Automaton &t);

private:

    std::unordered_map<std::pair<RulePtr, Bools::Expr>, Automaton> alphabet {};
    std::unordered_map<RulePtr, Automaton> regexes {};

};

template<>
struct std::hash<Automaton> {
    std::size_t operator()(const Automaton& x) const noexcept {
        return std::hash<std::string>()(x.to_string());
    }
};

bool operator==(const Automaton &x, const Automaton &y);
