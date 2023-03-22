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

    faudes::EventSet get_alphabet() const;

    friend std::ostream& operator<<(std::ostream &s, const Automaton &a);

};

class RedundanceViaAutomata: public Redundance<Automaton> {

public:

    using T = Automaton;

    virtual T get_singleton_language(const TransIdx idx, const Guard &guard) override;
    virtual T get_language(const TransIdx idx) override;
    virtual void set_language(const TransIdx idx, const T &t) override;
    virtual void delete_language(const TransIdx idx);
    virtual bool is_redundant(const T &t) const override;
    virtual void mark_as_redundant(const T &t) override;
    virtual void concat(T &t1, const T &t2) const override;
    virtual void transitive_closure(T &t) const override;

    // TODO could be used to compute unsat cores
    std::set<std::pair<TransIdx, Guard>> get_alphabet(const T &t) const;

private:

    long next_char;
    std::map<std::pair<TransIdx, Guard>, T> alphabet;
    std::map<TransIdx, T> regexes;

};
