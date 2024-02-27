/*  This file is part of LoAT.
 *  Copyright (c) 2015-2016 Matthias Naaf, RWTH Aachen University, Germany
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses>.
 */

#include "arithexpr.hpp"
#include "optional.hpp"
#include "map.hpp"

#include <purrs.hh>

ArithExpr::ArithExpr(const arith::Kind kind): kind(kind) {}

linked_hash_set<NumVarPtr> ArithExpr::vars() const {
    linked_hash_set<NumVarPtr> res;
    collectVars(res);
    return res;
}

bool ArithExpr::isUnivariate() const {
    std::optional<NumVarPtr> var;
    return isUnivariate(var);
}

bool ArithExpr::isMultivariate() const {
    std::optional<NumVarPtr> var;
    return isMultivariate(var);
}

bool ArithExpr::is(const Rational &val) const {
    const auto c {isRational()};
    return c && ***c == val;
}

std::optional<Int> ArithExpr::maxDegree() const {
    Int max {0};
    for (const auto &x: vars()) {
        const auto deg {degree(x)};
        if (deg) {
            max = mp::max(max, *deg);
        } else {
            return {};
        }
    }
    return max;
}

bool ArithExpr::has(const NumVarPtr x) const {
    return hasVarWith([&x](const auto &y) {
        return x == y;
    });
}

ExprPtr operator-(const ExprPtr x) {
    return arith::mkTimes({arith::mkConst(-1),x});
}

ExprPtr operator-(const ExprPtr x, const ExprPtr y) {
    return arith::mkPlus({x,-y});
}

ExprPtr operator+(const ExprPtr x, const ExprPtr y) {
    return arith::mkPlus({x,y});
}

ExprPtr operator*(const ExprPtr x, const ExprPtr y) {
    return arith::mkTimes({x,y});
}

ExprPtr ArithExpr::divide(const Rational &y) const {
    return arith::mkTimes({arith::mkConst(Rational(mp::denominator(y), mp::numerator(y))), shared_from_this()});
}

ExprPtr operator^(const ExprPtr x, const ExprPtr y) {
    return arith::mkExp(x, y);
}

std::optional<NumConstantPtr> ArithExpr::isRational() const {
    if (kind == arith::Kind::Constant) {
        return static_cast<const ArithVal*>(this)->std::enable_shared_from_this<ArithVal>::shared_from_this();;
    } else {
        return {};
    }
}

std::optional<Int> ArithExpr::isInt() const {
    return flat_map<NumConstantPtr, Int>(isRational(), [](const auto &r){
        return r->intValue();
    });
}

std::optional<NumVarPtr> ArithExpr::isVar() const {
    if (kind == arith::Kind::Variable) {
        return static_cast<const ArithVar*>(this)->std::enable_shared_from_this<ArithVar>::shared_from_this();
    } else {
        return {};
    }
}

std::optional<ExpPtr> ArithExpr::isPow() const {
    if (kind == arith::Kind::Exp) {
        return static_cast<const ArithExp*>(this)->std::enable_shared_from_this<ArithExp>::shared_from_this();
    } else {
        return {};
    }
}

const std::optional<MultPtr> ArithExpr::isMult() const {
    if (kind == arith::Kind::Times) {
        return static_cast<const ArithMult*>(this)->std::enable_shared_from_this<ArithMult>::shared_from_this();
    } else {
        return {};
    }
}

const std::optional<AddPtr> ArithExpr::isAdd() const {
    if (kind == arith::Kind::Plus) {
        return static_cast<const ArithAdd*>(this)->std::enable_shared_from_this<ArithAdd>::shared_from_this();
    } else {
        return {};
    }
}

bool ArithExpr::isLinear(const std::optional<linked_hash_set<NumVarPtr>> &vars) const {
    const auto is_linear {[&vars](const auto &arg) -> bool {
        return arg->isLinear(vars);
    }};
    return map<bool>(
        [](const NumConstantPtr) {
            return true;
        },
        [](const NumVarPtr) {
            return true;
        },
        [&is_linear](const AddPtr a) {
            const auto &args {a->getArgs()};
            return std::all_of(args.begin(), args.end(), is_linear);
        },
        [&is_linear, &vars](const MultPtr m) {
            const auto is_constant {[&vars](const auto &arg) -> bool {
                return !arg->hasVarWith([&vars](const auto &x) {
                    return vars->contains(x);
                });
            }};
            const auto &args {m->getArgs()};
            return args.size() == 2 && std::all_of(args.begin(), args.end(), is_linear) && std::any_of(args.begin(), args.end(), is_constant);
        },
        [&vars](const ExpPtr e) {
            return e->getBase()->isLinear(vars) && e->getExponent()->isLinear(vars);
        });
}

bool ArithExpr::isPoly() const {
    return map<bool>(
        [](const NumConstantPtr) {
            return true;
        },
        [](const NumVarPtr) {
            return true;
        },
        [](const AddPtr a) {
            const auto &args {a->getArgs()};
            return std::all_of(args.begin(), args.end(), [](const auto &arg) -> bool {
                return arg->isPoly();
            });
        },
        [](const MultPtr m) {
            const auto &args {m->getArgs()};
            return std::all_of(args.begin(), args.end(), [](const auto &arg) -> bool {
                return arg->isPoly();
            });
        },
        [](const ExpPtr e) {
            return e->getExponent()->isInt().has_value();
        });
}

std::optional<Int> ArithExpr::totalDegree() const {
    using opt = std::optional<Int>;
    return map<opt>(
        [](const NumConstantPtr) {
            return opt{0};
        },
        [](const NumVarPtr) {
            return opt{1};
        },
        [](const AddPtr a) {
            Int res {0};
            for (const auto &arg: a->getArgs()) {
                const auto arg_degree {arg->totalDegree()};
                if (!arg_degree) {
                    return opt{};
                }
                res = mp::max(res, *arg_degree);
            }
            return opt{res};
        },
        [](const MultPtr m) {
            Int res {0};
            for (const auto &arg: m->getArgs()) {
                const auto arg_degree {arg->totalDegree()};
                if (!arg_degree) {
                    return opt{};
                }
                res = res + *arg_degree;
            }
            return opt{res};
        },
        [](const ExpPtr e) {
            const auto exp {e->getExponent()->isInt()};
            if (exp) {
                const auto base_degree {e->getBase()->totalDegree()};
                if (base_degree) {
                    return opt{*base_degree * *exp};
                }
            }
            return opt{};
        });
}

void ArithExpr::collectVars(linked_hash_set<NumVarPtr> &res) const {
    map<void>(
        [](const NumConstantPtr&) {},
        [&res](const NumVarPtr x) {
            res.emplace(x);
        },
        [&res](const AddPtr a) {
            for (const auto &arg: a->getArgs()) {
                arg->collectVars(res);
            }
        },
        [&res](const MultPtr m) {
            for (const auto &arg: m->getArgs()) {
                arg->collectVars(res);
            }
        },
        [&res](const ExpPtr e) {
            e->getBase()->collectVars(res);
            e->getExponent()->collectVars(res);
        });
}

bool ArithExpr::hasVarWith(const std::function<bool(const NumVarPtr)> predicate) const {
    return map<bool>(
        [](const NumConstantPtr) {
            return false;
        },
        [&predicate](const NumVarPtr x) {
            return predicate(x);
        },
        [&predicate](const AddPtr a) {
            const auto &args {a->getArgs()};
            return std::any_of(args.begin(), args.end(), [&predicate](const auto &arg) -> bool {
                return arg->hasVarWith(predicate);
            });
        },
        [&predicate](const MultPtr m) {
            const auto &args {m->getArgs()};
            return std::any_of(args.begin(), args.end(), [&predicate](const auto &arg) -> bool {
                return arg->hasVarWith(predicate);
            });
        },
        [&predicate](const ExpPtr e) {
            return e->getBase()->hasVarWith(predicate) || e->getExponent()->hasVarWith(predicate);
        });
}

std::optional<Int> ArithExpr::degree(const NumVarPtr var) const {
    using opt = std::optional<Int>;
    return map<opt>(
        [](const NumConstantPtr) {
            return opt{0};
        },
        [&var](const NumVarPtr x) {
            return opt{x == var ? 1 : 0};
        },
        [&var](const AddPtr a) {
            Int res {0};
            for (const auto &arg: a->getArgs()) {
                const auto arg_degree {arg->degree(var)};
                if (!arg_degree) {
                    return opt{};
                }
                res = mp::max(res, *arg_degree);
            }
            return opt{res};
        },
        [&var](const MultPtr m) {
            Int res {0};
            for (const auto &arg: m->getArgs()) {
                const auto arg_degree {arg->degree(var)};
                if (!arg_degree) {
                    return opt{};
                }
                res = res + *arg_degree;
            }
            return opt{res};
        },
        [&var](const ExpPtr e) {
            if (!e->has(var)) {
                return opt{0};
            }
            const auto exp {e->getExponent()->isInt()};
            if (exp) {
                const auto base_degree {e->getBase()->degree(var)};
                if (base_degree) {
                    return opt{*base_degree * *exp};
                }
            }
            return opt{};
        });
}

Int ArithExpr::denomLcm() const {
    return map<Int>(
        [](const NumConstantPtr t) {
            return *t->denominator()->intValue();
        },
        [](const NumVarPtr) {
            return 1;
        },
        [](const AddPtr a) {
            const auto &args {a->getArgs()};
            return std::accumulate(args.begin(), args.end(), Int{1}, [](const auto &x, const auto &y) {
                return x * y->denomLcm();
            });
        },
        [](const MultPtr m) {
            const auto &args {m->getArgs()};
            return std::accumulate(args.begin(), args.end(), Int{1}, [](const auto &x, const auto &y) {
                return x * y->denomLcm();
            });
        },
        [](const ExpPtr) {
            return 1;
        });
}

bool ArithExpr::isPoly(const NumVarPtr n) const {
    return map<bool>(
        [](const NumConstantPtr) {
            return true;
        },
        [](const NumVarPtr) {
            return true;
        },
        [&n](const AddPtr a) {
            const auto &args {a->getArgs()};
            return std::all_of(args.begin(), args.end(), [&n](const auto &arg) -> bool {
                return arg->isPoly(n);
            });
        },
        [&n](const MultPtr m) {
            const auto &args {m->getArgs()};
            return std::all_of(args.begin(), args.end(), [&n](const auto &arg) -> bool {
                return arg->isPoly(n);
            });
        },
        [&n](const ExpPtr e) {
            return e->getExponent()->isInt() || !e->getBase()->has(n);
        });
}

std::optional<NumVarPtr> ArithExpr::someVar() const {
    using opt = std::optional<NumVarPtr>;
    return map<opt>(
        [](const NumConstantPtr) {
            return opt{};
        },
        [](const NumVarPtr x) {
            return opt{x};
        },
        [](const AddPtr a) {
            for (const auto &arg: a->getArgs()) {
                const auto res {arg->someVar()};
                if (res) {
                    return opt{res};
                }
            }
            return opt{};
        },
        [](const MultPtr m) {
            for (const auto &arg: m->getArgs()) {
                const auto res {arg->someVar()};
                if (res) {
                    return opt{res};
                }
            }
            return opt{};
        },
        [](const ExpPtr e) {
            auto res {e->getBase()->someVar()};
            return res ? res : e->getExponent()->someVar();
        });
}

void ArithExpr::exps(linked_hash_set<ExpPtr> &acc) const {
    return map<void>(
        [](const NumConstantPtr) {},
        [](const NumVarPtr) {},
        [&acc](const AddPtr a) {
            for (const auto &arg: a->getArgs()) {
                arg->exps(acc);
            }
        },
        [&acc](const MultPtr m) {
            for (const auto &arg: m->getArgs()) {
                arg->exps(acc);
            }
        },
        [&acc](const ExpPtr e) {
            e->getBase()->exps(acc);
            e->getExponent()->exps(acc);
            acc.emplace(e);
        });
}

linked_hash_set<ExpPtr> ArithExpr::exps() const {
    linked_hash_set<ExpPtr> acc;
    exps(acc);
    return acc;
}

std::optional<ExprPtr> ArithExpr::coeff(const NumVarPtr var, const Int &degree) const {
    using opt = std::optional<ExprPtr>;
    return map<opt>(
        [](const NumConstantPtr) {
            return opt{arith::mkConst(0)};
        },
        [&var, &degree](const NumVarPtr x) {
            return opt{arith::mkConst(degree == 1 && var == x ? 1 : 0)};
        },
        [&var, &degree](const AddPtr a) {
            for (const auto &arg: a->getArgs()) {
                const auto res {arg->coeff(var, degree)};
                if (res) {
                    return opt{res};
                }
            }
            return opt{};
        },
        [&var, &degree](const MultPtr m) {
            const auto e {arith::mkExp(var->toExpr(), arith::mkConst(degree))};
            const auto &args {m->getArgs()};
            if (args.contains(e)) {
                std::vector<ExprPtr> new_args;
                for (const auto &arg: args) {
                    if (arg != e) {
                        new_args.emplace_back(arg);
                    }
                }
                return opt{arith::mkTimes(new_args)};
            }
            return opt{};
        },
        [&var, &degree](const ExpPtr e) {
            if (e->getBase()->isVar() == var && e->getExponent()->isInt() == degree) {
                return opt{arith::mkConst(1)};
            }
            if (e->isPoly(var)) {
                return opt{arith::mkConst(0)};
            }
            return opt{};
        });
}

std::optional<ExprPtr> ArithExpr::lcoeff(const NumVarPtr var) const {
    using opt = std::optional<ExprPtr>;
    return map<opt>(
        [](const NumConstantPtr) {
            return opt{arith::mkConst(0)};
        },
        [&var](const NumVarPtr x) {
            return x->coeff(var);
        },
        [&var](const AddPtr a) {
            std::optional<Int> degree;
            opt res;
            for (const auto &arg: a->getArgs()) {
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
        },
        [&var](const MultPtr m) {
            opt lcoeff;
            std::vector<ExprPtr> new_args;
            for (const auto &arg: m->getArgs()) {
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
                return opt{arith::mkTimes(new_args)};
            } else {
                return opt{};
            }
        },
        [&var](const ExpPtr e) {
            if (e->isPoly(var)) {
                return opt{arith::mkConst(1)};
            }
            return opt{};
        });
}

bool ArithExpr::isIntegral() const {
    return map<bool>(
        [](const NumConstantPtr x) {
            return x->intValue().has_value();
        },
        [](const NumVarPtr) {
            return true;
        },
        [](const AddPtr a) {
            std::vector<ExprPtr> nonInt;
            for (const auto &arg: a->getArgs()) {
                if (!arg->isIntegral()) {
                    if (arg->isPow()) {
                        return false;
                    }
                    nonInt.emplace_back(arg);
                }
            }
            const auto e {arith::mkTimes(nonInt)};
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
                const auto res {a->eval([&vars, &subs](const auto x){
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
        },
        [](const MultPtr m) {
            const auto &args {m->getArgs()};
            return std::all_of(args.begin(), args.end(), [](const auto &arg) {
                return arg->isIntegral();
            });
        },
        [](const ExpPtr e) {
            return true;
        });
}

Rational ArithExpr::eval(const std::function<Rational(const NumVarPtr)> &valuation) const {
    return map<Rational>(
        [](const NumConstantPtr t) {
            return **t;
        },
        [&valuation](const NumVarPtr x) {
            return valuation(x);
        },
        [&valuation](const AddPtr a) {
            const auto &args {a->getArgs()};
            return std::accumulate(args.begin(), args.end(), Rational{0}, [&valuation](const auto &x, const auto y) {
                return x + y->eval(valuation);
            });
        },
        [&valuation](const MultPtr m) {
            const auto &args {m->getArgs()};
            return std::accumulate(args.begin(), args.end(), Rational{1}, [&valuation](const auto &x, const auto y) {
                return x * y->eval(valuation);
            });
        },
        [&valuation](const ExpPtr e) {
            return mp::pow(mp::numerator(e->getBase()->eval(valuation)), e->getExponent()->eval(valuation).convert_to<long>());
        });
}

std::pair<Purrs::Expr, purrs_var_map> ArithExpr::toPurrs() const {
    purrs_var_map m;
    const auto res {toPurrs(m)};
    return {res, m};
}

Purrs::Expr ArithExpr::toPurrs(purrs_var_map &m) const {
    return map<Purrs::Expr>(
        [](const NumConstantPtr t) {
            return Purrs::Number(t->numerator()->getValue().str().c_str()) / Purrs::Number(t->denominator()->getValue().str().c_str());
        },
        [&m](const NumVarPtr x) {
            const auto res {m.left.find(x)};
            if (res == m.left.end()) {
                Purrs::Symbol s {x->getName()};
                m.left.insert(purrs_var_map::left_value_type(x, s));
                return s;
            }
            return res->second;
        },
        [&m](const AddPtr a) {
            const auto &args {a->getArgs()};
            return std::accumulate(args.begin(), args.end(), Purrs::Expr(0), [&m](const auto &x, const auto &y){
                return x + y->toPurrs(m);
            });
        },
        [&m](const MultPtr mult) {
            const auto &args {mult->getArgs()};
            return std::accumulate(args.begin(), args.end(), Purrs::Expr(1), [&m](const auto &x, const auto &y){
                return x * y->toPurrs(m);
            });
        },
        [&m](const ExpPtr e) {
            return Purrs::pwr(e->getBase()->toPurrs(m), e->getExponent()->toPurrs(m));
        });
}

std::pair<Rational, std::optional<ExprPtr>> ArithExpr::decompose() const {
    using pair = std::pair<Rational, std::optional<ExprPtr>>;
    return map<pair>(
        [](const NumConstantPtr t) {
            return pair{**t, {}};
        },
        [](const NumVarPtr x) {
            return pair{1, {x->toExpr()}};
        },
        [](const AddPtr a) {
            return pair{1, {a}};
        },
        [](const MultPtr m) {
            const auto &args {m->getArgs()};
            std::vector<ExprPtr> non_const {args.begin(), args.end()};
            for (const auto &arg: args) {
                const auto val {arg->isRational()};
                if (val) {
                    std::erase(non_const, arg);
                    return pair{***val, {arith::mkTimes(non_const)}};
                }
            }
            return pair{1, {m}};
        },
        [](const ExpPtr e) {
            return pair {1, {e}};
        });
}

bool ArithExpr::isUnivariate(std::optional<NumVarPtr> &acc) const {
    return map<bool>(
        [](const NumConstantPtr) {
            return false;
        },
        [&acc](const NumVarPtr x) {
            if (!acc) {
                acc = x;
            }
            return acc == x;
        },
        [&acc](const AddPtr a) {
            const auto &args {a->getArgs()};
            return std::all_of(args.begin(), args.end(), [&acc](const auto &arg) -> bool {
                return arg->isUnivariate(acc);
            });
        },
        [&acc](const MultPtr m) {
            const auto &args {m->getArgs()};
            return std::all_of(args.begin(), args.end(), [&acc](const auto &arg) -> bool {
                return arg->isUnivariate(acc);
            });
        },
        [&acc](const ExpPtr e) {
            return e->getBase()->isUnivariate(acc) && e->getExponent()->isUnivariate(acc);
        });
}

bool ArithExpr::isMultivariate(std::optional<NumVarPtr> &acc) const {
    return map<bool>(
        [](const NumConstantPtr) {
            return false;
        },
        [&acc](const NumVarPtr x) {
            return !x->isUnivariate(acc);
        },
        [&acc](const AddPtr a) {
            const auto &args {a->getArgs()};
            return std::any_of(args.begin(), args.end(), [&acc](const auto &arg) -> bool {
                return arg->isMultivariate(acc);
            });
        },
        [&acc](const MultPtr m) {
            const auto &args {m->getArgs()};
            return std::any_of(args.begin(), args.end(), [&acc](const auto &arg) -> bool {
                return arg->isMultivariate(acc);
            });
        },
        [&acc](const ExpPtr e) {
            return e->getBase()->isMultivariate(acc) || e->getExponent()->isMultivariate(acc);
        });
}

std::ostream& operator<<(std::ostream &s, const ExprPtr e) {
    e->map<void>(
        [&](const NumConstantPtr c) {
            s << c->getValue();
        },
        [&](const NumVarPtr x) {
            s << x->getName();
        },
        [&](const AddPtr a) {
            auto fst {true};
            for (const auto &arg: a->getArgs()) {
                if (fst) {
                    fst = false;
                    s << arg;
                } else {
                    s << " + " << arg;
                }
            }
        },
        [&](const MultPtr a) {
            auto fst {true};
            for (const auto &arg: a->getArgs()) {
                if (fst) {
                    fst = false;
                    s << arg;
                } else {
                    s << " * " << arg;
                }
            }
        },
        [&](const ExpPtr a) {
            s << a->getBase() << " ^ " << a->getExponent();
        });
    return s;
}

std::ostream& operator<<(std::ostream &s, const NumVarPtr e) {
    return s << e->getName();
}
