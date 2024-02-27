#include "numexpression.hpp"
#include "map.hpp"

#include <purrs.hh>

ConsHash<Expr, Add, Add::CacheHash, Add::CacheEqual, linked_hash_set<ExprPtr>> Add::cache;

Add::Add(const linked_hash_set<ExprPtr> &args): Expr(ne::Kind::Plus), args(args) {}

bool Add::CacheEqual::operator()(const std::tuple<linked_hash_set<ExprPtr>> &args1, const std::tuple<linked_hash_set<ExprPtr>> &args2) const noexcept {
    return args1 == args2;
}

size_t Add::CacheHash::operator()(const std::tuple<linked_hash_set<ExprPtr>> &args) const noexcept {
    size_t hash {0};
    const auto &children {std::get<0>(args)};
    boost::hash_combine(hash, boost::hash_unordered_range(children.begin(), children.end()));
    return hash;
}

ExprPtr num_expression::buildPlus(std::vector<ExprPtr> args) {
    // remove neutral element
    std::remove(args.begin(), args.end(), buildConstant(0));
    if (args.empty()) {
        return buildConstant(0);
    }
    if (args.size() == 1) {
        return args[0];
    }
    // pull up nested additions
    std::vector<ExprPtr> insert;
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
    linked_hash_map<std::optional<ExprPtr>, Rational> map;
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
                args.emplace_back(buildConstant(y));
            } else {
                args.emplace_back(*x * buildConstant(y));
            }
        }
    }
    if (args.size() == 1) {
        return args[0];
    }
    linked_hash_set<ExprPtr> arg_set {args.begin(), args.end()};
    return Add::cache.from_cache(arg_set);
}

const linked_hash_set<ExprPtr>& Add::getArgs() const {
    return args;
}
