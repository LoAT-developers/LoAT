#include "add.hpp"
#include "map.hpp"
#include "numconstant.hpp"

#include <purrs.hh>

Add::Add(const linked_hash_set<ExprPtr> &args): ACApplication(args) {}

bool Add::isLinear(const std::optional<linked_hash_set<NumVarPtr>> &vars) const {
    const auto is_linear {[&vars](const auto &arg) -> bool {
        return arg->isLinear(vars);
    }};
    return std::all_of(args.begin(), args.end(), is_linear);
}

std::optional<Int> Add::totalDegree() const {
    Int res {0};
    for (const auto &arg: args) {
        const auto arg_degree {arg->totalDegree()};
        if (!arg_degree) {
            return {};
        }
        res = mp::max(res, *arg_degree);
    }
    return res;
}

std::optional<Int> Add::degree(const NumVarPtr var) const {
    Int res {0};
    for (const auto &arg: args) {
        const auto arg_degree {arg->degree(var)};
        if (!arg_degree) {
            return {};
        }
        res = mp::max(res, *arg_degree);
    }
    return res;
}

const linked_hash_set<ExprPtr>* Add::isMul() const {
    return nullptr;
}

const linked_hash_set<ExprPtr>* Add::isAdd() const {
    return &args;
}

std::pair<Rational, std::optional<ExprPtr>> Add::decompose() const {
    return {1, {shared_from_this()}};
}

bool Add::isIntegral() const {
    std::vector<ExprPtr> nonInt;
    for (const auto &arg: args) {
        if (!arg->isIntegral()) {
            if (arg->isPow()) {
                return false;
            }
            nonInt.emplace_back(arg);
        }
    }
    const auto e {num_expression::buildTimes(nonInt)};
    unsigned i {0};
    linked_hash_map<NumVarPtr, unsigned> vars;
    // degrees, subs share indices with vars
    std::vector<Int> degrees;
    std::vector<Int> subs;
    for (const auto &x: e->vars()) {
        vars.emplace(x, i);
        degrees.push_back(*e->degree(x));
        subs.push_back(0);
        ++i;
    }

    while (true) {
        // substitute every variable x_i by the integer subs[i] and check if the result is an integer
        const auto res {this->eval([&vars, &subs](const auto x){
            return subs[vars.at(x)];
        })};
        if (mp::denominator(res) != 1) {
            return false;
        }

        // increase subs (lexicographically) if possible
        // (the idea is that subs takes all possible combinations of 0,...,degree[i]+1 for every entry i)
        bool foundNext = false;
        for (unsigned int i = 0; i < degrees.size(); i++) {
            if (subs[i] >= degrees[i]+1) {
                subs[i] = 0;
            } else {
                subs[i] += 1;
                foundNext = true;
                break;
            }
        }

        if (!foundNext) {
            return true;
        }
    }
}

Rational Add::eval(const std::function<Rational(const NumVarPtr)> &valuation) const {
    Rational res {0};
    for (const auto &arg: args) {
        res += arg->eval(valuation);
    }
    return res;
}

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
        const auto children {(*it)->isAdd()};
        if (children) {
            for (const auto &c: *children) {
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

std::optional<ExprPtr> Add::coeff(const NumVarPtr var, const Int &degree) const {
    for (const auto &arg: args) {
        const auto res {arg->coeff(var, degree)};
        if (res) {
            return res;
        }
    }
    return {};
}

std::optional<ExprPtr> Add::lcoeff(const NumVarPtr var) const {
    std::optional<Int> degree;
    std::optional<ExprPtr> res;
    for (const auto &arg: args) {
        const auto r {arg->lcoeff(var)};
        if (res) {
            const auto d {arg->degree(var)};
            if (!degree || d < *degree) {
                res = r;
                degree = d;
            }
        }
    }
    return res;
}

Purrs::Expr Add::toPurrs(purrs_var_map &map) const {
    return std::accumulate(args.begin(), args.end(), Purrs::Expr(0), [&map](const auto &x, const auto &y){
        return x + y->toPurrs(map);
    });
}
