#include "redundanceviaautomata.hpp"

Automaton Automaton::covered;
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

void Automaton::unite(const Automaton &that) {
    if (this->empty()) {
        faudes::EmptyLanguage(t.Alphabet(), t);
        return;
    }
    if (that.empty()) {
        return;
    }
    faudes::LanguageUnion(t, that.t, t);
    faudes::StateMin(t, t);
    str = "(" + str + ") u (" + that.str + ")";
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

std::ostream& operator<<(std::ostream &s, const Automaton &a) {
    return s << a.str;
}

Automaton RedundanceViaAutomata::get_singleton_language(const TransIdx idx, const Guard &g) {
    const auto it = alphabet.find({idx, g});
    if (it == alphabet.end()) {
        const auto res = Automaton::singleton();
        alphabet.emplace(std::pair<TransIdx, Guard>(idx, g), res);
        return res;
    } else {
        return it->second;
    }
}

Automaton RedundanceViaAutomata::get_language(const TransIdx idx) {
    return regexes[idx];
}

void RedundanceViaAutomata::set_language(const TransIdx idx, const Automaton &t) {
    regexes.emplace(idx, t);
}

bool RedundanceViaAutomata::is_redundant(const Automaton &t) const {
    return t.subset(Automaton::covered);
}

void RedundanceViaAutomata::mark_as_redundant(const Automaton &t) {
    Automaton::covered.unite(t);
}

void RedundanceViaAutomata::concat(Automaton &t1, const Automaton &t2) const {
    t1.concat(t2);
}

void RedundanceViaAutomata::transitive_closure(Automaton &t) const {
    t.kleene_plus();
}
