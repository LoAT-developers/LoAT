#include "redundanceviaautomata.hpp"

Automaton Automaton::covered;
Automaton Automaton::accelerated;
long Automaton::next_char;

Automaton Automaton::singleton() {
    Automaton res;
    res.t.StateNamesEnabled(false);
    faudes::EventSet events;
    res.str = std::to_string(next_char);
    events.Insert(covered.t.InsEvent(std::to_string(next_char)));
    faudes::AlphabetLanguage(events, res.t);
    next_char++;
    return res;
}

void Automaton::concat(const Automaton &that) {
    if (this->empty()) {
        return;
    }
    if (that.empty()) {
        faudes::EmptyLanguage(t.Alphabet(), t);
        return;
    }
    faudes::LanguageConcatenate(t, that.t, t);
    str = str + "." + that.str;
}

void Automaton::prepend(const Automaton &that) {
    if (this->empty()) {
        return;
    }
    if (that.empty()) {
        faudes::EmptyLanguage(t.Alphabet(), t);
        return;
    }
    faudes::LanguageConcatenate(that.t, t, t);
    str = that.str + "." + str;
}

void Automaton::unite(const Automaton &that) {
    if (this->empty()) {
        this->t = that.t;
        this->str = that.str;
    } else if (!that.empty()) {
        faudes::LanguageUnion(t, that.t, t);
        faudes::StateMin(t, t);
        str = "(" + str + ") u (" + that.str + ")";
    }
}

void Automaton::kleene_plus() {
    if (this->empty()) {
        return;
    }
    faudes::Generator one_step = t;
    faudes::KleeneClosure(t, t);
    faudes::LanguageConcatenate(t, one_step, t);
    faudes::StateMin(t, t);
    str = "(" + str + ")+";
}

bool Automaton::subset(const Automaton &that) const {
    return faudes::LanguageInclusion(t, that.t);
}

bool Automaton::empty() const {
    return faudes::IsEmptyLanguage(t);
}

faudes::EventSet Automaton::get_alphabet() const {
    faudes::EventSet res;
    faudes::AlphabetExtract(t, res);
    return res;
}

std::string Automaton::to_string() const {
    return str;
}

std::ostream& operator<<(std::ostream &s, const Automaton &a) {
    return s << a.str;
}

bool operator==(const Automaton &x, const Automaton &y) {
    return x.to_string() == y.to_string();
}

Automaton RedundanceViaAutomata::get_singleton_language(const RulePtr idx, const Conjunction &g) {
    const auto it = alphabet.find({idx, g});
    if (it == alphabet.end()) {
        const auto res = Automaton::singleton();
        alphabet.emplace(std::pair<RulePtr, Conjunction>(idx, g), res);
        return res;
    } else {
        return it->second;
    }
}

std::optional<Automaton> RedundanceViaAutomata::get_language(const RulePtr idx) {
    const auto it {regexes.find(idx)};
    return it == regexes.end() ? std::optional<Automaton>() : it->second;
}

void RedundanceViaAutomata::set_language(const RulePtr idx, const Automaton &t) {
    regexes.emplace(idx, t);
}

void RedundanceViaAutomata::delete_language(const RulePtr idx) {
    regexes.erase(idx);
}

bool RedundanceViaAutomata::is_redundant(const Automaton &t) const {
    return t.subset(Automaton::covered);
}

bool RedundanceViaAutomata::is_accelerated(const Automaton &t) const {
    return t.subset(Automaton::accelerated);
}

void RedundanceViaAutomata::mark_as_redundant(const Automaton &t) {
    Automaton::covered.unite(t);
}

void RedundanceViaAutomata::mark_as_accelerated(const Automaton &t) {
    Automaton::accelerated.unite(t);
}

void RedundanceViaAutomata::concat(Automaton &t1, const Automaton &t2) const {
    t1.concat(t2);
}

void RedundanceViaAutomata::prepend(const Automaton &t1, Automaton &t2) const {
    t2.prepend(t1);
}

void RedundanceViaAutomata::transitive_closure(Automaton &t) const {
    t.kleene_plus();
}
