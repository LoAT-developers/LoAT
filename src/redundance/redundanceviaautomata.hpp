#pragma once

#include <libfaudes.h>

#include "redundance.hpp"

class Automaton {

    friend class RedundanceViaAutomata;

    static long next_char;
    static Automaton covered;
    faudes::Generator t;
    std::string str;

public:

    static Automaton singleton();

    void concat(const Automaton &that);
    void kleene_plus();
    void unite(const Automaton &that);

    bool subset(const Automaton &that) const;
    bool empty() const;

    friend std::ostream& operator<<(std::ostream &s, const Automaton &a);

};

class RedundanceViaAutomata: public Redundance<Automaton> {

    long next_char;
    std::map<std::pair<TransIdx, Guard>, Automaton> alphabet;
    std::map<TransIdx, Automaton> regexes;

public:

    virtual Automaton get_singleton_language(const TransIdx idx, const Guard &guard) override;
    virtual Automaton get_language(const TransIdx idx) override;
    virtual void set_language(const TransIdx idx, const Automaton &t) override;
    virtual bool is_redundant(const Automaton &t) const override;
    virtual void mark_as_redundant(const Automaton &t) override;
    virtual void concat(Automaton &t1, const Automaton &t2) const override;
    virtual void transitive_closure(Automaton &t) const override;

};
