#include "arithexpr.hpp"
#include "linkedhashmap.hpp"

#include <purrs.hh>

ConsHash<ArithExpr, ArithAdd, ArithAdd::CacheHash, ArithAdd::CacheEqual, ArithExprSet> ArithAdd::cache;

ArithAdd::ArithAdd(const ArithExprSet &args): ArithExpr(arith::Kind::Plus), args(args) {}

bool ArithAdd::CacheEqual::operator()(const std::tuple<ArithExprSet> &args1, const std::tuple<ArithExprSet> &args2) const noexcept {
    return args1 == args2;
}

size_t ArithAdd::CacheHash::operator()(const std::tuple<ArithExprSet> &args) const noexcept {
    size_t hash {0};
    const auto &children {std::get<0>(args)};
    boost::hash_combine(hash, boost::hash_unordered_range(children.begin(), children.end()));
    return hash;
}

ArithExprPtr arith::mkPlus(std::vector<ArithExprPtr> args) {
    // remove neutral element
    std::remove(args.begin(), args.end(), mkConst(0));
    if (args.empty()) {
        return mkConst(0);
    }
    if (args.size() == 1) {
        return args[0];
    }
    // pull up nested additions
    std::vector<ArithExprPtr> insert;
    for (auto it = args.begin(); it != args.end();) {
        const auto add {(*it)->isAdd()};
        if (add) {
            for (const auto &c: (*add)->getArgs()) {
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
    // transform c*t + d*t to (c+d)*t
    linked_hash_map<std::optional<ArithExprPtr>, Rational> map;
    auto changed {false};
    for (const auto &arg: args) {
        const auto [x,y] {arg->decompose()};
        const auto val {map.get(y)};
        changed = changed || val;
        map.put(y, val.value_or(0) + x);
    }
    if (changed) {
        args.clear();
        for (const auto &[x,y]: map) {
            if (!x) {
                args.emplace_back(mkConst(y));
            } else {
                args.emplace_back(*x * mkConst(y));
            }
        }
    }
    if (args.size() == 1) {
        return args[0];
    }
    ArithExprSet arg_set {args.begin(), args.end()};
    return ArithAdd::cache.from_cache(arg_set);
}

const ArithExprSet& ArithAdd::getArgs() const {
    return args;
}
