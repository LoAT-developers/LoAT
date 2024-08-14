#include "arithsubs.hpp"
#include "arithexpr.hpp"

ArithSubs::ArithSubs() {}

ArithSubs::ArithSubs(std::initializer_list<std::pair<const ArithVarPtr, ArithExprPtr>> init): map(init) {}

ArithExprPtr ArithSubs::get(const ArithVarPtr key) const {
    const auto res {map.get(key)};
    return res ? *res : key->toExpr();
}

void ArithSubs::put(const ArithVarPtr key, const ArithExprPtr val) {
    map.put(key, val);
}

ArithSubs::const_iterator ArithSubs::begin() const {
    return map.begin();
}

ArithSubs::const_iterator ArithSubs::end() const {
    return map.end();
}

bool ArithSubs::contains(const ArithVarPtr e) const {
    return map.contains(e);
}

bool ArithSubs::empty() const {
    return map.empty();
}

unsigned int ArithSubs::size() const {
    return map.size();
}

size_t ArithSubs::erase(const ArithVarPtr key) {
    return map.erase(key);
}

ArithSubs ArithSubs::compose(const ArithSubs &that) const {
    ArithSubs res;
    for (const auto &p: *this) {
        res.put(p.first, that(p.second));
    }
    for (const auto &p: that) {
        if (!res.contains(p.first)) {
            res.put(p.first, p.second);
        }
    }
    return res;
}

ArithSubs ArithSubs::concat(const ArithSubs &that) const {
    ArithSubs res;
    for (const auto &p: *this) {
        res.put(p.first, that(p.second));
    }
    return res;
}

void ArithSubs::concatInPlace(const ArithSubs &that) {
    std::vector<std::pair<ArithVarPtr, ArithExprPtr>> changed;
    for (const auto &[key, val]: *this) {
        const auto new_val {that(val)};
        if (val != new_val) {
            changed.emplace_back(key, new_val);
        }
    }
    for (const auto &[key, val]: changed) {
        put(key, val);
    }
}

ArithSubs ArithSubs::unite(const ArithSubs &that) const {
    ArithSubs res;
    for (const auto &p: *this) {
        res.put(p.first, p.second);
    }
    for (const auto &p: that) {
        if (res.contains(p.first)) {
            throw std::invalid_argument("union of substitutions is only defined if their domain is disjoint");
        }
        res.put(p.first, p.second);
    }
    return res;
}

ArithSubs ArithSubs::project(const linked_hash_set<ArithVarPtr> &vars) const {
    ArithSubs res;
    if (size() < vars.size()) {
        for (const auto &p: *this) {
            if (vars.contains(p.first)) {
                res.put(p.first, p.second);
            }
        }
    } else {
        for (const auto &x: vars) {
            const auto val {map.get(x)};
            if (val) {
                res.put(x, *val);
            }
        }
    }
    return res;
}

ArithSubs ArithSubs::project(const std::function<bool(ArithVarPtr)> &keep) const {
    ArithSubs res;
    for (const auto &p : *this) {
        if (keep(p.first)) {
            res.put(p.first, p.second);
        }
    }
    return res;
}

bool ArithSubs::changes(const ArithVarPtr key) const {
    return contains(key) && get(key) != key;
}

bool ArithSubs::isLinear() const {
    return std::all_of(begin(), end(), [](const auto &p) {
        return p.second->isLinear();
    });
}

bool ArithSubs::isPoly() const {
    return std::all_of(begin(), end(), [](const auto &p) {
        return p.second->isPoly();
    });
}

void ArithSubs::collectDomain(linked_hash_set<ArithVarPtr> &vars) const {
    for (const auto &p: *this) {
        vars.insert(p.first);
    }
}

void ArithSubs::collectCoDomainVars(linked_hash_set<ArithVarPtr> &vars) const {
    for (const auto &p: *this) {
        p.second->collectVars(vars);
    }
}

void ArithSubs::collectVars(linked_hash_set<ArithVarPtr> &vars) const {
    collectCoDomainVars(vars);
    collectDomain(vars);
}

linked_hash_set<ArithVarPtr> ArithSubs::domain() const {
    linked_hash_set<ArithVarPtr> res;
    collectDomain(res);
    return res;
}

linked_hash_set<ArithVarPtr> ArithSubs::coDomainVars() const {
    linked_hash_set<ArithVarPtr> res;
    collectCoDomainVars(res);
    return res;
}

size_t ArithSubs::hash() const {
    return boost::hash_unordered_range(map.begin(), map.end());
}

size_t hash_value(const ArithSubs &x) {
    return x.hash();
}

bool operator==(const ArithSubs &m1, const ArithSubs &m2) {
    return m1.map == m2.map;
}

std::ostream& operator<<(std::ostream &s, const ArithSubs &map) {
    if (map.empty()) {
        return s << "{}";
    } else {
        s << "{";
        bool fst = true;
        for (const auto &p: map) {
            if (!fst) {
                s << ", ";
            } else {
                fst = false;
            }
            s << p.first << " <- " << p.second;
        }
        return s << "}";
    }
}

ArithExprPtr ArithSubs::operator()(const ArithExprPtr t) const {
    return t->apply<ArithExprPtr>(
        [&](const ArithConstPtr) {
            return t;
        },
        [&](const ArithVarPtr x) {
            return get(x);
        },
        [&](const ArithAddPtr a) {
            const auto &args {a->getArgs()};
            std::vector<ArithExprPtr> new_args;
            std::transform(args.begin(), args.end(), std::back_inserter(new_args), [&](const auto arg) {
                return (*this)(arg);
            });
            return arith::mkPlus(std::move(new_args));
        },
        [&](const ArithMultPtr m) {
            const auto &args {m->getArgs()};
            std::vector<ArithExprPtr> new_args;
            std::transform(args.begin(), args.end(), std::back_inserter(new_args), [&](const auto arg) {
                return (*this)(arg);
            });
            return arith::mkTimes(std::move(new_args));
        },
        [&](const ArithModPtr m) {
            return arith::mkMod((*this)(m->getLhs()), (*this)(m->getRhs()));
        },
        [&](const ArithExpPtr e) {
            return arith::mkExp((*this)(e->getBase()), (*this)(e->getExponent()));
        });
}
