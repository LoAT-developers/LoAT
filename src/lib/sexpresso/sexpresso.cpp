/* This file is part of LoAT.
 *
 * adapted version of https://github.com/BitPuffin/sexpresso
 *
 * Author: Isak Andersson 2016 bitpuffin dot com
 *
 * adapted by: Florian Frohn, 2019
 */

#include "sexpresso.hpp"

#include <vector>
#include <string>
#include <cstdint>
#include <cctype>
#include <stack>
#include <algorithm>
#include <sstream>
#include <array>
#include <assert.h>

namespace sexpresso {
    Sexp::Sexp() {
        this->kind = SexpValueKind::SEXP;
        this->count = 2; // for parantheses
    }
    Sexp::Sexp(std::string const& strval) {
        this->kind = SexpValueKind::STRING;
        this->value.str = escape(strval);
        this->count = strval.size();
    }
    Sexp::Sexp(std::vector<Sexp> const& sexpval) {
        this->kind = SexpValueKind::SEXP;
        this->value.sexp = sexpval;
        for (const auto &x: sexpval) {
            count += x.count;
        }
        count += sexpval.size() - 1; // for whitespace
        count += 2; // for parantheses
    }

    auto Sexp::addChild(Sexp sexp) -> void {
        if(this->kind == SexpValueKind::STRING) {
            this->kind = SexpValueKind::SEXP;
            this->value.sexp.emplace_back(Sexp{this->value.str});
        }
        this->value.sexp.push_back(std::move(sexp));
        count += sexp.count;
        ++count; // for whitespace
    }

    auto Sexp::addChild(std::string str) -> void {
        this->addChild(Sexp{str});
    }

    auto Sexp::addChildUnescaped(std::string str) -> void {
        this->addChild(Sexp::unescaped(std::move(str)));
    }

    auto Sexp::addExpression(std::string const& str) -> void {
        auto err = std::string{};
        auto sexp = parse(str, err);
        if(!err.empty()) return;
        for(auto&& c : sexp.value.sexp) this->addChild(std::move(c));
    }

    auto Sexp::childCount() const -> size_t {
        switch(this->kind) {
            case SexpValueKind::SEXP:
                return this->value.sexp.size();
            case SexpValueKind::STRING:
                return 1;
        }
        throw std::invalid_argument("unknown SexpValueKind");
    }

    static auto splitPathString(std::string const& path) -> std::vector<std::string> {
        auto paths = std::vector<std::string>{};
        if(path.empty()) return paths;
        auto start = path.begin();
        for(auto i = path.begin()+1; i != path.end(); ++i) {
            if(*i == '/') {
                paths.emplace_back(std::string{start, i});
                start = i + 1;
            }
        }
        paths.emplace_back(std::string{start, path.end()});
        return paths;
    }

    auto Sexp::getChildByPath(std::string const& path) -> Sexp* {
        if(this->kind == SexpValueKind::STRING) return nullptr;

        auto paths = splitPathString(path);

        auto* cur = this;
        for(auto i = paths.begin(); i != paths.end();) {
            auto start = i;
            for(auto& child : cur->value.sexp) {
                auto brk = false;
                switch(child.kind) {
                    case SexpValueKind::STRING:
                        if(i == paths.end() - 1 && child.value.str == *i) return &child;
                        else continue;
                    case SexpValueKind::SEXP:
                        if(child.value.sexp.empty()) continue;
                        auto& fst = child.value.sexp[0];
                        switch(fst.kind) {
                            case SexpValueKind::STRING:
                                if(fst.value.str == *i) {
                                    cur = &child;
                                    ++i;
                                    brk = true;
                                }
                                break;
                            case SexpValueKind::SEXP: continue;
                        }
                }
                if(brk) break;
            }
            if(i == start) return nullptr;
            if(i == paths.end()) return cur;
        }
        return nullptr;
    }

    static auto findChild(Sexp& sexp, std::string name) -> Sexp* {
        auto findPred = [&name](Sexp& s) {
            switch(s.kind) {
                case SexpValueKind::SEXP: {
                    if(s.childCount() == 0) return false;
                    auto& hd = s.getChild(0);
                    switch(hd.kind) {
                        case SexpValueKind::SEXP:
                            return false;
                        case SexpValueKind::STRING:
                            return hd.str() == name;
                    }
                    break;
                }
                case SexpValueKind::STRING:
                    return s.str() == name;
            }
            throw std::invalid_argument("unknown SexpValueKind");
        };
        auto loc = std::find_if(sexp.value.sexp.begin(), sexp.value.sexp.end(), findPred);
        if(loc == sexp.value.sexp.end()) return nullptr;
        else return &(*loc);
    }

    auto Sexp::createPath(std::vector<std::string> const& path) -> Sexp& {
        auto el = this;
        Sexp *nxt;
        auto pc = path.begin();
        for(; pc != path.end(); ++pc) {
            nxt = findChild(*el, *pc);
            if(nxt == nullptr) break;
            else el = nxt;
        }
        for(; pc != path.end(); ++pc) {
            el->addChild(Sexp{std::vector<Sexp>{Sexp{*pc}}});
            el = &(el->getChild(el->childCount()-1));
        }
        return *el;
    }

    auto Sexp::createPath(std::string const& path) -> Sexp& {
        return this->createPath(splitPathString(path));
    }

    auto Sexp::getChild(size_t idx) -> Sexp& {
        return this->value.sexp[idx];
    }

    auto Sexp::operator[](size_t idx) -> Sexp& {
        return getChild(idx);
    }

    auto Sexp::str() -> std::string& {
        return this->value.str;
    }

    static const std::array<char, 11> escape_chars = { '\'', '"',  '?', '\\',  'a',  'b',  'f',  'n',  'r',  't',  'v' };
    static const std::array<char, 11> escape_vals  = { '\'', '"', '\?', '\\', '\a', '\b', '\f', '\n', '\r', '\t', '\v' };

    static auto isEscapeValue(char c) -> bool {
        return std::find(escape_vals.begin(), escape_vals.end(), c) != escape_vals.end();
    }

    static auto countEscapeValues(std::string const& str) -> long {
        return std::count_if(str.begin(), str.end(), isEscapeValue);
    }

    static auto stringValToString(std::string const& s) -> std::string {
        if(s.empty()) return std::string{"\"\""};
        if((std::find(s.begin(), s.end(), ' ') == s.end()) && countEscapeValues(s) == 0) return s;
        return ('"' + escape(s) + '"');
    }

    static auto toStringImpl(Sexp const &sexp, std::ostringstream &ostream, unsigned indent, bool freshline) -> bool {
        switch (sexp.kind) {
        case SexpValueKind::STRING:
            ostream << stringValToString(sexp.value.str);
            return false;
        case SexpValueKind::SEXP:
            if (sexp.count > 80) {
                if (!freshline) {
                    ostream << '\n';
                    for (unsigned i = 0; i < indent; ++i) {
                        ostream << ' ';
                    }
                }
                indent += 2;
                ostream << '(';
                auto i = sexp.value.sexp.begin();
                freshline = toStringImpl(*i, ostream, indent, false);
                for (++i; i != sexp.value.sexp.end(); ++i) {
                    if (!freshline) {
                        ostream << '\n';
                        for (unsigned i = 0; i < indent; ++i) {
                            ostream << ' ';
                        }
                    }
                    freshline = toStringImpl(*i, ostream, indent, true);
                }
                ostream << ')';
                indent -= 2;
                ostream << '\n';
                for (unsigned i = 0; i < indent; ++i) {
                    ostream << ' ';
                }
                return true;
            } else {
                ostream << '(';
                auto freshline = false;
                for (auto i = sexp.value.sexp.begin(); i != sexp.value.sexp.end(); ++i) {
                    freshline = toStringImpl(*i, ostream, indent + 2, freshline);
                    if (!freshline && i != sexp.value.sexp.end() - 1) {
                        ostream << ' ';
                    }
                }
                ostream << ')';
                return false;
            }
        }
        return false;
    }

    auto Sexp::toString() const -> std::string {
        auto ostream = std::ostringstream{};
        toStringImpl(*this, ostream, 0, true);
        return ostream.str();
    }

    auto Sexp::isString() const -> bool {
        return this->kind == SexpValueKind::STRING;
    }

    auto Sexp::isSexp() const -> bool {
        return this->kind == SexpValueKind::SEXP;
    }

    auto Sexp::isNil() const -> bool {
        return this->kind == SexpValueKind::SEXP && this->childCount() == 0;
    }

    static auto childrenEqual(std::vector<Sexp> const& a, std::vector<Sexp> const& b) -> bool {
        if(a.size() != b.size()) return false;

        for(unsigned int i = 0; i < a.size(); ++i) {
            if(!a[i].equal(b[i])) return false;
        }
        return true;
    }

    auto Sexp::equal(Sexp const& other) const -> bool {
        if(this->kind != other.kind) return false;
        switch(this->kind) {
            case SexpValueKind::SEXP:
                return childrenEqual(this->value.sexp, other.value.sexp);
            case SexpValueKind::STRING:
                return this->value.str == other.value.str;
        }
        throw std::invalid_argument("unknown SexpValueKind");
    }

    auto Sexp::arguments() -> SexpArgumentIterator {
        return SexpArgumentIterator{*this};
    }

    auto Sexp::unescaped(std::string strval) -> Sexp {
        auto s = Sexp{};
        s.kind = SexpValueKind::STRING;
        s.value.str = std::move(strval);
        return s;
    }

    auto parse(std::string const& str, std::string& err) -> Sexp {
        auto sexprstack = std::stack<Sexp>{};
        sexprstack.push(Sexp{}); // root
        auto nextiter = str.begin();
        for(auto iter = nextiter; iter != str.end(); iter = nextiter) {
            nextiter = iter + 1;
            if(std::isspace(*iter)) continue;
            switch(*iter) {
                case '(':
                    sexprstack.push(Sexp{});
                    break;
                case ')': {
                    auto topsexp = std::move(sexprstack.top());
                    sexprstack.pop();
                    if(sexprstack.empty()) {
                        err = std::string{"too many ')' characters detected, closing sexprs that don't exist, no good."};
                        return Sexp{};
                    }
                    auto& top = sexprstack.top();
                    top.addChild(std::move(topsexp));
                    break;
                }
                case '"': {
                    auto i = iter+1;
                    auto start = i;
                    for(; i != str.end(); ++i) {
                        if(*i == '\\') { ++i; continue; }
                        if(*i == '"') break;
                        if(*i == '\n') {
                            err = std::string{"Unexpected newline in string literal"};
                            return Sexp{};
                        }
                    }
                    if(i == str.end()) {
                        err = std::string{"Unterminated string literal"};
                        return Sexp{};
                    }
                    auto resultstr = std::string{};
                    resultstr.reserve(i - start);
                    for(auto it = start; it != i; ++it) {
                        switch(*it) {
                            case '\\': {
                                ++it;
                                if(it == i) {
                                    err = std::string{"Unfinished escape sequence at the end of the string"};
                                    return Sexp{};
                                }
                                auto pos = std::find(escape_chars.begin(), escape_chars.end(), *it);
                                if(pos == escape_chars.end()) {
                                    err = std::string{"invalid escape char '"} + *it + '\'';
                                    return Sexp{};
                                }
                                resultstr.push_back(escape_vals[pos - escape_chars.begin()]);
                                break;
                            }
                            default:
                                resultstr.push_back(*it);
                        }
                    }
                    sexprstack.top().addChildUnescaped(std::move(resultstr));
                    nextiter = i + 1;
                    break;
                }
                case ';':
                    for(; nextiter != str.end() && *nextiter != '\n' && *nextiter != '\r'; ++nextiter) {}
                    for(; nextiter != str.end() && (*nextiter == '\n' || *nextiter == '\r'); ++nextiter) {}
                    break;
                default:
                    auto symend = std::find_if(iter, str.end(), [](char const& c) { return std::isspace(c) || c == ')'; });
                    auto& top = sexprstack.top();
                    top.addChild(Sexp{std::string{iter, symend}});
                    nextiter = symend;
            }
        }
        if(sexprstack.size() != 1) {
            err = std::string{"not enough s-expressions were closed by the end of parsing"};
            return Sexp{};
        }
        return std::move(sexprstack.top());
    }

    auto parse(std::string const& str) -> Sexp {
        auto ignored_error = std::string{};
        return parse(str, ignored_error);
    }

    auto escape(std::string const& str) -> std::string {
        auto escape_count = countEscapeValues(str);
        if(escape_count == 0) return str;
        auto result_str = std::string{};
        result_str.reserve(str.size() + escape_count);
        for(auto c : str) {
            auto loc = std::find(escape_vals.begin(), escape_vals.end(), c);
            if(loc == escape_vals.end()) result_str.push_back(c);
            else {
                result_str.push_back('\\');
                result_str.push_back(escape_chars[loc - escape_vals.begin()]);
            }
        }
        return result_str;
    }

    SexpArgumentIterator::SexpArgumentIterator(Sexp& sexp) : sexp(sexp) {}

    auto SexpArgumentIterator::begin() -> iterator {
        if(this->size() == 0) return this->end(); else return ++(this->sexp.value.sexp.begin());
    }

    auto SexpArgumentIterator::end() -> iterator { return this->sexp.value.sexp.end(); }

    auto SexpArgumentIterator::begin() const -> const_iterator {
        if(this->size() == 0) return this->end(); else return ++(this->sexp.value.sexp.begin());
    }

    auto SexpArgumentIterator::end() const -> const_iterator { return this->sexp.value.sexp.end(); }

    auto SexpArgumentIterator::empty() const -> bool { return this->size() == 0;}

    auto SexpArgumentIterator::size() const -> size_t {
        auto sz = this->sexp.value.sexp.size();
        if(sz == 0) return 0; else return sz-1;
    }
}
