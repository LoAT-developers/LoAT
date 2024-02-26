#include "numexpression.hpp"
#include "map.hpp"

#include <purrs.hh>

Mult::Mult(const linked_hash_set<ExprPtr> &args): Expr(ne::Kind::Times), args(args) {}

bool Mult::CacheEqual::operator()(const std::tuple<linked_hash_set<ExprPtr>> &args1, const std::tuple<linked_hash_set<ExprPtr>> &args2) const noexcept {
    return args1 == args2;
}

size_t Mult::CacheHash::operator()(const std::tuple<linked_hash_set<ExprPtr>> &args) const noexcept {
    size_t hash {0};
    const auto &children {std::get<0>(args)};
    boost::hash_combine(hash, boost::hash_unordered_range(children.begin(), children.end()));
    return hash;
}

ExprPtr num_expression::buildTimes(std::vector<ExprPtr> args) {
    // remove neutral element
    std::remove(args.begin(), args.end(), buildConstant(1));
    if (args.empty()) {
        return buildConstant(1);
    }
    if (args.size() == 1) {
        return args[0];
    }
    // pull up nested multiplications
    std::vector<ExprPtr> insert;
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
    linked_hash_map<ExprPtr, ExprPtr> map;
    auto changed {false};
    for (const auto &arg: args) {
        const auto exp {arg->isPow()};
        if (exp) {
            const auto base {(*exp)->getBase()};
            const auto val {map.get(base)};
            changed = changed || val;
            map.put(base, val.value_or(buildConstant(0)) + (*exp)->getExponent());
        } else {
            map.put(arg, buildConstant(1));
        }
    }
    if (changed) {
        args.clear();
        for (const auto &[x,y]: map) {
            args.emplace_back(buildExp(x, y));
        }
    }
    // distribute
    changed = false;
    std::vector<ExprPtr> todo {args.begin(), args.end()};
    std::vector<std::vector<ExprPtr>> res;
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
            std::vector<std::vector<ExprPtr>> next;
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
            args.emplace_back(buildTimes(x));
        }
        return buildPlus(args);
    }
    if (args.size() == 1) {
        return args[0];
    }
    linked_hash_set<ExprPtr> arg_set {args.begin(), args.end()};
    return Mult::cache.from_cache(arg_set);
}

const linked_hash_set<ExprPtr>& Mult::getArgs() const {
    return args;
}
