#include "arithexpr.hpp"
#include "linkedhashmap.hpp"
#include "vector.hpp"

ConsHash<ArithExpr, ArithAdd, ArithAdd::CacheHash, ArithAdd::CacheEqual, ArithExprSet> ArithAdd::cache{16384};

ArithAdd::ArithAdd(const ArithExprSet &args): ArithExpr(arith::Kind::Plus), args(args) {}

ArithAdd::~ArithAdd() {
    cache.erase(args);
}

bool ArithAdd::CacheEqual::operator()(const std::tuple<ArithExprSet> &args1, const std::tuple<ArithExprSet> &args2) const noexcept {
    return args1 == args2;
}

size_t ArithAdd::CacheHash::operator()(const std::tuple<ArithExprSet> &args) const noexcept {
    size_t hash {42};
    const auto &children {std::get<0>(args)};
    boost::hash_combine(hash, boost::hash_unordered_range(children.begin(), children.end()));
    return hash;
}

ArithExprPtr arith::mkPlusImpl(std::vector<ArithExprPtr> &&args) {
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
                    args.emplace_back(*x * arith::mkConst(y));
                } else {
                    args.emplace_back(arith::mkConst(y));
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
            args.push_back(arith::mkConst(*constant));
        }
    }
    if (args.empty()) {
        return arith::mkConst(0);
    }
    if (args.size() == 1) {
        return args[0];
    }
    const ArithExprSet arg_set {args.begin(), args.end()};
    // std::cout << "+ " << args << " --> + " << arg_set << std::endl;
    return ArithAdd::cache.from_cache(std::move(arg_set));
}

ArithExprPtr arith::mkPlus(ArithExprPtr fst, ArithExprPtr snd) {
    if (const auto f {fst->isRational()}) {
        if (const auto s {snd->isRational()}) {
            return arith::mkConst(***f + ***s);
        }
        std::swap(fst, snd);
    }
    if (const auto s {snd->isRational()}) {
        const auto c {***s};
        if (c == 0) {
            return fst;
        }
        if (const auto a {fst->isAdd()}) {
            auto args {(*a)->getArgs()};
            const auto it {std::find_if(args.begin(), args.end(), [](const auto &x) {
                return x->isRational();
            })};
            if (it == args.end()) {

                args.insert(snd);
            } else {
                const auto new_c {arith::mkConst(c + ***(*it)->isRational())};
                args.erase(it);
                if (new_c->is(0)) {
                    if (args.size() == 1) {
                        return *args.begin();
                    }
                } else {
                    args.insert(new_c);
                }
            }
            return ArithAdd::cache.from_cache(args);
        } else {
            return ArithAdd::cache.from_cache(ArithExprSet{fst, snd});
        }
    } else {
        return mkPlusImpl({fst, snd});
    }
}

ArithExprPtr arith::mkPlus(std::vector<ArithExprPtr> &&args) {
    if (args.size() == 2) {
        return mkPlus(args.front(), args.back());
    } else {
        return mkPlusImpl(std::move(args));
    }
}

const ArithExprSet& ArithAdd::getArgs() const {
    return args;
}
