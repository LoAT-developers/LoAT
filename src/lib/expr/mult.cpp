#include "mult.hpp"
#include "numconstant.hpp"
#include "map.hpp"
#include "numvar.hpp"

#include <purrs.hh>

Mult::Mult(const linked_hash_set<ExprPtr> &args): ACApplication(args) {}

bool Mult::isLinear(const std::optional<linked_hash_set<NumVarPtr>> &vars) const {
    const auto is_linear {[&vars](const auto &arg) -> bool {
        return arg->isLinear(vars);
    }};
    const auto is_constant {[&vars](const auto &arg) -> bool {
        return !arg->hasVarWith([&vars](const auto &x) {
            return vars->contains(x);
        });
    }};
    return args.size() == 2 && std::all_of(args.begin(), args.end(), is_linear) && std::any_of(args.begin(), args.end(), is_constant);
}

std::optional<Int> Mult::totalDegree() const {
    Int res {0};
    for (const auto &arg: args) {
        const auto arg_degree {arg->totalDegree()};
        if (!arg_degree) {
            return {};
        }
        res = res + *arg_degree;
    }
    return res;
}

std::optional<Int> Mult::degree(const NumVarPtr var) const {
    Int res {0};
    for (const auto &arg: args) {
        const auto arg_degree {arg->degree(var)};
        if (!arg_degree) {
            return {};
        }
        res = res + *arg_degree;
    }
    return res;
}

const linked_hash_set<ExprPtr>* Mult::isMul() const {
    return &args;
}

const linked_hash_set<ExprPtr>* Mult::isAdd() const {
    return nullptr;
}

std::pair<Rational, std::optional<ExprPtr>> Mult::decompose() const {
    std::vector<ExprPtr> non_const {args.begin(), args.end()};
    for (const auto &arg: args) {
        const auto val {arg->isRational()};
        if (val) {
            std::erase(non_const, arg);
            return {*val, {num_expression::buildTimes(non_const)}};
        }
    }
    return {1, {shared_from_this()}};
}

bool Mult::isIntegral() const {
    return std::all_of(args.begin(), args.end(), [](const auto &arg) {
        return arg->isIntegral();
    });
}

Rational Mult::eval(const std::function<Rational(const NumVarPtr)> &valuation) const {
    Rational res {1};
    for (const auto &arg: args) {
        res *= arg->eval(valuation);
    }
    return res;
}

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
        const auto children {(*it)->isMul()};
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
    // transform t^p * t^q to t^{p+q}
    linked_hash_map<ExprPtr, ExprPtr> map;
    auto changed {false};
    for (const auto &arg: args) {
        const auto exp {arg->isPow()};
        if (exp) {
            const auto [base, exponent] {*exp};
            const auto val {map.get(base)};
            changed = changed || val;
            map.put(base, val.value_or(buildConstant(0)) + exponent);
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
            const auto addends {x->isAdd()};
            if (addends) {
                changed = true;
                for (const auto &y: *addends) {
                    res.emplace_back();
                    res.back().emplace_back(y);
                }
            } else {
                res.back().emplace_back(x);
            }
        } else {
            std::vector<std::vector<ExprPtr>> next;
            const auto addends {x->isAdd()};
            if (addends) {
                changed = true;
                for (const auto &z: res) {
                    for (const auto &y: *addends) {
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

std::optional<ExprPtr> Mult::coeff(const NumVarPtr var, const Int &degree) const {
    const auto e {num_expression::buildExp(var->toExpr(), num_expression::buildConstant(degree))};
    if (args.contains(e)) {
        std::vector<ExprPtr> new_args;
        for (const auto &arg: args) {
            if (arg != e) {
                new_args.emplace_back(arg);
            }
        }
        return num_expression::buildTimes(new_args);
    }
    return {};
}

std::optional<ExprPtr> Mult::lcoeff(const NumVarPtr var) const {
    std::optional<ExprPtr> lcoeff;
    std::vector<ExprPtr> new_args;
    for (const auto &arg: args) {
        if (lcoeff) {
            new_args.emplace_back(arg);
        } else {
            lcoeff = arg->lcoeff(var);
            if (lcoeff) {
                new_args.emplace_back(*lcoeff);
            } else {
                new_args.emplace_back(arg);
            }
        }
    }
    if (lcoeff) {
        return num_expression::buildTimes(new_args);
    } else {
        return {};
    }
}


Purrs::Expr Mult::toPurrs(purrs_var_map &map) const {
    return std::accumulate(args.begin(), args.end(), Purrs::Expr(1), [&map](const auto &x, const auto &y){
        return x * y->toPurrs(map);
    });
}
