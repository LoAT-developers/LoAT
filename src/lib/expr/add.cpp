#include "arithexpr.hpp"
#include "linkedhashmap.hpp"
#include "vector.hpp"

#include <purrs.hh>

ConsHash<ArithExpr, ArithAdd, ArithAdd::CacheHash, ArithAdd::CacheEqual, ArithExprVec> ArithAdd::cache;

ArithAdd::ArithAdd(const ArithExprVec &args): ArithExpr(arith::Kind::Plus), args(args) {}

bool ArithAdd::CacheEqual::operator()(const std::tuple<ArithExprVec> &args1, const std::tuple<ArithExprVec> &args2) const noexcept {
    return args1 == args2;
}

size_t ArithAdd::CacheHash::operator()(const std::tuple<ArithExprVec> &args) const noexcept {
    size_t hash {0};
    const auto &children {std::get<0>(args)};
    boost::hash_combine(hash, boost::hash_unordered_range(children.begin(), children.end()));
    return hash;
}

ArithExprPtr arith::mkPlus(std::vector<ArithExprPtr> &&args) {
    {
        // pull up nested additions
        std::vector<ArithExprPtr> insert;
        for (auto it = args.begin(); it != args.end();) {
            if (const auto add {(*it)->isAdd()}) {
                for (const auto &c: (*add)->getArgs()) {
                    insert.emplace_back(c);
                }
                it = args.erase(it);
            } else {
                ++it;
            }
        }
        args.insert(args.end(), insert.begin(), insert.end());
    }
    {
        // transform c*t + d*t to (c+d)*t
        linked_hash_map<std::optional<ArithExprPtr>, Rational> map;
        auto changed {false};
        for (const auto &arg: args) {
            const auto [x,y] {arg->decompose()};
            if (const auto val{map.get(y)}) {
                changed = true;
                map.put(y, *val + x);
            } else {
                map.put(y, x);
            }
        }
        if (changed) {
            args.clear();
            for (const auto &[x,y]: map) {
                if (x) {
                    args.emplace_back(*x * mkConst(y));
                } else {
                    args.emplace_back(mkConst(y));
                }
            }
        }
    }
    {
        // add constants
        std::optional<Rational> constant;
        for (auto it = args.begin(); it != args.end();) {
            if (const auto r {(*it)->isRational()}) {
                if (!constant) {
                    constant = ***r;
                } else {
                    constant = *constant + ***r;
                }
                it = args.erase(it);
            } else {
                ++it;
            }
        }
        if (constant && *constant != 0) {
            args.push_back(mkConst(*constant));
        }
    }
    if (args.empty()) {
        return mkConst(0);
    }
    if (args.size() == 1) {
        return args[0];
    }
    std::sort(args.begin(), args.end());
    // std::cout << "+ " << args << " --> + " << arg_set << std::endl;
    return ArithAdd::cache.from_cache(std::move(args));
}

const ArithExprVec& ArithAdd::getArgs() const {
    return args;
}
