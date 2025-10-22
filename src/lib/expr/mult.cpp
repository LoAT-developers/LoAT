#include <utility>

#include "arithexpr.hpp"
#include "linkedhashmap.hpp"
#include "vector.hpp"

ConsHash<ArithExpr, ArithMult, ArithMult::CacheHash, ArithMult::CacheEqual, ArithExprSet> ArithMult::cache;

ArithMult::ArithMult(ArithExprSet args): ArithExpr(arith::Kind::Times), args(std::move(args)) {}

ArithMult::~ArithMult() {
    cache.erase(args);
}

bool ArithMult::CacheEqual::operator()(const std::tuple<ArithExprSet> &args1, const std::tuple<ArithExprSet> &args2) const noexcept {
    return args1 == args2;
}

size_t ArithMult::CacheHash::operator()(const std::tuple<ArithExprSet> &args) const noexcept {
    const auto &children {std::get<0>(args)};
    return boost::hash_unordered_range(children.begin(), children.end());
}

ArithExprPtr arith::mkTimesImpl(std::vector<ArithExprPtr> &&args) {
    {
        // pull up nested multiplications
        std::vector<ArithExprPtr> insert;
        for (auto it = args.begin(); it != args.end();) {
            if (const auto mult {(*it)->isMult()}) {
                for (const auto &c: (*mult)->getArgs()) {
                    insert.emplace_back(c);
                }
                it = args.erase(it);
            } else {
                ++it;
            }
        }
        for (const auto &x: insert) {
            args.push_back(x);
        }
    }
    {
        // multiply constants
        std::optional<ArithConstPtr> constant;
        for (auto it = args.begin(); it != args.end();) {
            if (const auto r {(*it)->isRational()}) {
                if (!constant) {
                    constant = *r;
                } else {
                    constant = *mkConst(***constant * ***r)->isRational();
                }
                it = args.erase(it);
            } else {
                ++it;
            }
        }
        if (constant) {
            if ((*constant)->is(0)) {
                return zero;
            }
            if (!(*constant)->is(1)) {
                args.emplace_back(*constant);
            }
        }
    }
    {
        // emtpy product
        if (args.empty()) {
            return one;
        }
    }
    {
        // distribute
        auto changed{false};
        std::vector<ArithExprPtr> todo{args.begin(), args.end()};
        std::vector<std::vector<ArithExprPtr>> res;
        for (const auto &x : todo) {
            if (res.empty()) {
                if (const auto add {x->isAdd()}) {
                    changed = true;
                    for (const auto &y : (*add)->getArgs()) {
                        res.emplace_back();
                        res.back().emplace_back(y);
                    }
                } else {
                    res.emplace_back();
                    res.back().emplace_back(x);
                }
            } else {
                std::vector<std::vector<ArithExprPtr>> next;
                if (const auto add{x->isAdd()}) {
                    changed = true;
                    for (const auto &z : res) {
                        for (const auto &y : (*add)->getArgs()) {
                            next.emplace_back(z);
                            next.back().emplace_back(y);
                        }
                    }
                } else {
                    for (const auto &z : res) {
                        next.emplace_back(z);
                        next.back().emplace_back(x);
                    }
                }
                res = next;
            }
        }
        if (changed) {
            args.clear();
            for (auto &x : res) {
                args.emplace_back(mkTimesImpl(std::move(x)));
            }
            return mkPlus(std::move(args));
        }
    }
    {
        // transform t^p * t^q to t^{p+q}
        linked_hash_map<ArithExprPtr, ArithExprPtr> map;
        auto changed{false};
        for (const auto &arg : args) {
            const auto exp {arg->isPow()};
            const auto base {exp ? (*exp)->getBase() : arg};
            const auto exponent {exp ? (*exp)->getExponent() : one};
            const auto val {map.get(base)};
            changed = changed || val;
            map.put(base, val.value_or(zero) + exponent);
        }
        if (changed) {
            args.clear();
            for (const auto &[x, y] : map) {
                args.emplace_back(mkExp(x, y));
            }
        }
    }
    {
        // singleton
        if (args.size() == 1) {
            return args[0];
        }
    }
    ArithExprSet arg_set {args.begin(), args.end()};
    return ArithMult::cache.from_cache(std::move(arg_set));
}

ArithExprPtr arith::mkTimes(ArithExprPtr fst, ArithExprPtr snd) {
    if (const auto f {fst->isRational()}) {
        if (const auto s {snd->isRational()}) {
            return mkConst(***f * ***s);
        }
        std::swap(fst, snd);
    }
    if (const auto s {snd->isRational()}) {
        const auto c {***s};
        if (c == 0) {
            return snd;
        }
        if (c == 1) {
            return fst;
        }
        if (const auto m {fst->isMult()}) {
            auto args {(*m)->getArgs()};
            const auto it {std::find_if(args.begin(), args.end(), [](const auto &x) {
                return x->isRational();
            })};
            if (it == args.end()) {
                args.insert(snd);
            } else {
                const auto new_c {mkConst(c * ***(*it)->isRational())};
                args.erase(it);
                if (new_c->is(1)) {
                    if (args.size() == 1) {
                        return *args.begin();
                    }
                } else {
                    args.insert(new_c);
                }
            }
            return ArithMult::cache.from_cache(args);
        }
        if (const auto a {fst->isAdd()}) {
            const auto args {(*a)->getArgs()};
            ArithExprSet new_args;
            for (const auto &x: args) {
                new_args.insert(mkTimes(x, snd));
            }
            return ArithAdd::cache.from_cache(std::move(new_args));
        }
        return ArithMult::cache.from_cache(ArithExprSet{fst, snd});
    }
    return mkTimesImpl({fst, snd});
}

ArithExprPtr arith::mkTimes(std::vector<ArithExprPtr> &&args) {
    if (args.size() == 2) {
        return mkTimes(args.front(), args.back());
    }
    return mkTimesImpl(std::move(args));
}

const ArithExprSet& ArithMult::getArgs() const {
    return args;
}
