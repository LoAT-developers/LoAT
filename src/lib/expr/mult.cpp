#include "arithexpr.hpp"
#include "map.hpp"

#include <purrs.hh>

ConsHash<ArithExpr, ArithMult, ArithMult::CacheHash, ArithMult::CacheEqual, linked_hash_set<ArithExprPtr>> ArithMult::cache;

ArithMult::ArithMult(const linked_hash_set<ArithExprPtr> &args): ArithExpr(arith::Kind::Times), args(args) {}

bool ArithMult::CacheEqual::operator()(const std::tuple<linked_hash_set<ArithExprPtr>> &args1, const std::tuple<linked_hash_set<ArithExprPtr>> &args2) const noexcept {
    return args1 == args2;
}

size_t ArithMult::CacheHash::operator()(const std::tuple<linked_hash_set<ArithExprPtr>> &args) const noexcept {
    size_t hash {0};
    const auto &children {std::get<0>(args)};
    boost::hash_combine(hash, boost::hash_unordered_range(children.begin(), children.end()));
    return hash;
}

ArithExprPtr arith::mkTimes(std::vector<ArithExprPtr> args) {
    // remove neutral element
    std::remove(args.begin(), args.end(), mkConst(1));
    if (args.empty()) {
        return mkConst(1);
    }
    if (args.size() == 1) {
        return args[0];
    }
    // pull up nested multiplications
    std::vector<ArithExprPtr> insert;
    for (auto it = args.begin(); it != args.end();) {
        const auto mult {(*it)->isMult()};
        if (mult) {
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
    // transform t^p * t^q to t^{p+q}
    linked_hash_map<ArithExprPtr, ArithExprPtr> map;
    auto changed {false};
    for (const auto &arg: args) {
        const auto exp {arg->isPow()};
        if (exp) {
            const auto base {(*exp)->getBase()};
            const auto val {map.get(base)};
            changed = changed || val;
            map.put(base, val.value_or(mkConst(0)) + (*exp)->getExponent());
        } else {
            map.put(arg, mkConst(1));
        }
    }
    if (changed) {
        args.clear();
        for (const auto &[x,y]: map) {
            args.emplace_back(mkExp(x, y));
        }
    }
    // distribute
    changed = false;
    std::vector<ArithExprPtr> todo {args.begin(), args.end()};
    std::vector<std::vector<ArithExprPtr>> res;
    for (const auto &x: todo) {
        if (res.empty()) {
            const auto add {x->isAdd()};
            if (add) {
                changed = true;
                for (const auto &y: (*add)->getArgs()) {
                    res.emplace_back();
                    res.back().emplace_back(y);
                }
            } else {
                res.back().emplace_back(x);
            }
        } else {
            std::vector<std::vector<ArithExprPtr>> next;
            const auto add {x->isAdd()};
            if (add) {
                changed = true;
                for (const auto &z: res) {
                    for (const auto &y: (*add)->getArgs()) {
                        next.emplace_back(z);
                        next.back().emplace_back(y);
                    }
                }
            } else {
                for (const auto &z: res) {
                    next.emplace_back(z);
                    next.back().emplace_back(x);
                }
            }
            res = next;
        }
    }
    if (changed) {
        args.clear();
        for (const auto &x: res) {
            args.emplace_back(mkTimes(x));
        }
        return mkPlus(args);
    }
    if (args.size() == 1) {
        return args[0];
    }
    linked_hash_set<ArithExprPtr> arg_set {args.begin(), args.end()};
    return ArithMult::cache.from_cache(arg_set);
}

const linked_hash_set<ArithExprPtr>& ArithMult::getArgs() const {
    return args;
}