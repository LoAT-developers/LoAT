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
#include "linkedhashmap.hpp"

#include <purrs.hh>
#include <sstream>

ArithExpr::ArithExpr(const arith::Kind kind): kind(kind) {}

linked_hash_set<ArithVarPtr> ArithExpr::vars() const {
    linked_hash_set<ArithVarPtr> res;
    collectVars(res);
    return res;
}

std::optional<ArithVarPtr> ArithExpr::isUnivariate() const {
    std::optional<ArithVarPtr> var;
    if (isUnivariate(var)) {
        return var;
    } else {
        return {};
    }
}

bool ArithExpr::isMultivariate() const {
    std::optional<ArithVarPtr> var;
    return isMultivariate(var);
}

bool ArithExpr::is(const Rational &val) const {
    const auto c {isRational()};
    return c && ***c == val;
}

std::optional<Int> ArithExpr::maxDegree() const {
    Int max {0};
    for (const auto &x: vars()) {
        const auto deg {isPoly(x)};
        if (deg) {
            max = mp::max(max, *deg);
        } else {
            return {};
        }
    }
    return max;
}

bool ArithExpr::has(const ArithVarPtr x) const {
    return hasVarWith([&](const auto &y) {
        return x == y;
    });
}

ArithExprPtr operator-(const ArithExprPtr x) {
    return arith::mkTimes({arith::mkConst(-1),x});
}

ArithExprPtr operator-(const ArithExprPtr x, const ArithExprPtr y) {
    return arith::mkPlus({x,-y});
}

ArithExprPtr operator+(const ArithExprPtr x, const ArithExprPtr y) {
    return arith::mkPlus({x,y});
}

ArithExprPtr operator*(const ArithExprPtr x, const ArithExprPtr y) {
    return arith::mkTimes({x,y});
}

ArithExprPtr ArithExpr::divide(const Rational &y) const {
    return arith::mkTimes({arith::mkConst(Rational(mp::denominator(y), mp::numerator(y))), cpp::assume_not_null(shared_from_this())});
}

ArithExprPtr operator^(const ArithExprPtr x, const ArithExprPtr y) {
    return arith::mkExp(x, y);
}

std::optional<ArithConstPtr> ArithExpr::isRational() const {
    if (kind == arith::Kind::Constant) {
        return cpp::assume_not_null(static_pointer_cast<const ArithConst>(shared_from_this()));
    } else {
        return {};
    }
}

std::optional<Int> ArithExpr::isInt() const {
    return flat_map<ArithConstPtr, Int>(isRational(), [](const auto &r){
        return r->intValue();
    });
}

std::optional<ArithVarPtr> ArithExpr::isVar() const {
    if (kind == arith::Kind::Variable) {
        return cpp::assume_not_null(static_pointer_cast<const ArithVar>(shared_from_this()));
    } else {
        return {};
    }
}

std::optional<ArithExpPtr> ArithExpr::isPow() const {
    if (kind == arith::Kind::Exp) {
        return cpp::assume_not_null(static_pointer_cast<const ArithExp>(shared_from_this()));
    } else {
        return {};
    }
}

const std::optional<ArithMultPtr> ArithExpr::isMult() const {
    if (kind == arith::Kind::Times) {
        return cpp::assume_not_null(static_pointer_cast<const ArithMult>(shared_from_this()));
    } else {
        return {};
    }
}

const std::optional<ArithAddPtr> ArithExpr::isAdd() const {
    if (kind == arith::Kind::Plus) {
        return cpp::assume_not_null(static_pointer_cast<const ArithAdd>(shared_from_this()));
    } else {
        return {};
    }
}

bool ArithExpr::isLinear(const std::optional<linked_hash_set<ArithVarPtr>> &vars) const {
    const auto is_linear {[&](const auto &arg) -> bool {
        return arg->isLinear(vars);
    }};
    const auto is_constant {[&](const auto &arg) -> bool {
        return !arg->hasVarWith([&](const auto &x) {
            return vars ? vars->contains(x) : true;
        });
    }};
    return apply<bool>(
        [](const ArithConstPtr) {
            return true;
        },
        [](const ArithVarPtr) {
            return true;
        },
        [&](const ArithAddPtr a) {
            const auto &args {a->getArgs()};
            return std::all_of(args.begin(), args.end(), is_linear);
        },
        [&](const ArithMultPtr m) {
            const auto &args {m->getArgs()};
            auto found {false};
            for (const auto &arg: args) {
                if (!arg->isLinear(vars)) {
                    return false;
                }
                if (!is_constant(arg)) {
                    if (found) {
                        return false;
                    } else {
                        found = true;
                    }
                }
            }
            return true;
        },
        [&](const ArithExpPtr e) {
            return is_constant(e);
        });
}

std::optional<Int> ArithExpr::isPoly() const {
    using opt = std::optional<Int>;
    return apply<opt>(
        [](const ArithConstPtr) {
            return opt{0};
        },
        [](const ArithVarPtr) {
            return opt{1};
        },
        [](const ArithAddPtr a) {
            Int res {0};
            for (const auto &arg: a->getArgs()) {
                const auto arg_degree {arg->isPoly()};
                if (!arg_degree) {
                    return opt{};
                }
                res = mp::max(res, *arg_degree);
            }
            return opt{res};
        },
        [](const ArithMultPtr m) {
            Int res {0};
            for (const auto &arg: m->getArgs()) {
                const auto arg_degree {arg->isPoly()};
                if (!arg_degree) {
                    return opt{};
                }
                res = res + *arg_degree;
            }
            return opt{res};
        },
        [](const ArithExpPtr e) {
            const auto exp {e->getExponent()->isInt()};
            if (exp) {
                const auto base_degree {e->getBase()->isPoly()};
                if (base_degree) {
                    return opt{*base_degree * *exp};
                }
            }
            return opt{};
        });
}

void ArithExpr::collectVars(linked_hash_set<ArithVarPtr> &res) const {
    apply<void>(
        [](const ArithConstPtr&) {},
        [&](const ArithVarPtr x) {
            res.emplace(x);
        },
        [&](const ArithAddPtr a) {
            for (const auto &arg: a->getArgs()) {
                arg->collectVars(res);
            }
        },
        [&](const ArithMultPtr m) {
            for (const auto &arg: m->getArgs()) {
                arg->collectVars(res);
            }
        },
        [&](const ArithExpPtr e) {
            e->getBase()->collectVars(res);
            e->getExponent()->collectVars(res);
        });
}

bool ArithExpr::hasVarWith(const std::function<bool(const ArithVarPtr)> predicate) const {
    return apply<bool>(
        [](const ArithConstPtr) {
            return false;
        },
        [&](const ArithVarPtr x) {
            return predicate(x);
        },
        [&](const ArithAddPtr a) {
            const auto &args {a->getArgs()};
            return std::any_of(args.begin(), args.end(), [&](const auto &arg) -> bool {
                return arg->hasVarWith(predicate);
            });
        },
        [&](const ArithMultPtr m) {
            const auto &args {m->getArgs()};
            return std::any_of(args.begin(), args.end(), [&](const auto &arg) -> bool {
                return arg->hasVarWith(predicate);
            });
        },
        [&](const ArithExpPtr e) {
            return e->getBase()->hasVarWith(predicate) || e->getExponent()->hasVarWith(predicate);
        });
}

std::optional<Int> ArithExpr::isPoly(const ArithVarPtr var) const {
    using opt = std::optional<Int>;
    return apply<opt>(
        [](const ArithConstPtr) {
            return opt{0};
        },
        [&](const ArithVarPtr x) {
            return opt{x == var ? 1 : 0};
        },
        [&](const ArithAddPtr a) {
            Int res {0};
            for (const auto &arg: a->getArgs()) {
                const auto arg_degree {arg->isPoly(var)};
                if (!arg_degree) {
                    return opt{};
                }
                res = mp::max(res, *arg_degree);
            }
            return opt{res};
        },
        [&](const ArithMultPtr m) {
            Int res {0};
            for (const auto &arg: m->getArgs()) {
                const auto arg_degree {arg->isPoly(var)};
                if (!arg_degree) {
                    return opt{};
                }
                res = res + *arg_degree;
            }
            return opt{res};
        },
        [&](const ArithExpPtr e) {
            if (!e->has(var)) {
                return opt{0};
            }
            const auto exp {e->getExponent()->isInt()};
            if (exp) {
                const auto base_degree {e->getBase()->isPoly(var)};
                if (base_degree) {
                    return opt{*base_degree * *exp};
                }
            }
            return opt{};
        });
}

Int ArithExpr::denomLcm() const {
    return apply<Int>(
        [](const ArithConstPtr t) {
            return *t->denominator()->intValue();
        },
        [](const ArithVarPtr) {
            return 1;
        },
        [](const ArithAddPtr a) {
            const auto &args {a->getArgs()};
            return std::accumulate(args.begin(), args.end(), Int{1}, [](const auto &x, const auto &y) {
                return x * y->denomLcm();
            });
        },
        [](const ArithMultPtr m) {
            const auto &args {m->getArgs()};
            return std::accumulate(args.begin(), args.end(), Int{1}, [](const auto &x, const auto &y) {
                return x * y->denomLcm();
            });
        },
        [](const ArithExpPtr) {
            return 1;
        });
}

std::optional<ArithVarPtr> ArithExpr::someVar() const {
    using opt = std::optional<ArithVarPtr>;
    return apply<opt>(
        [](const ArithConstPtr) {
            return opt{};
        },
        [](const ArithVarPtr x) {
            return opt{x};
        },
        [](const ArithAddPtr a) {
            for (const auto &arg: a->getArgs()) {
                const auto res {arg->someVar()};
                if (res) {
                    return opt{res};
                }
            }
            return opt{};
        },
        [](const ArithMultPtr m) {
            for (const auto &arg: m->getArgs()) {
                const auto res {arg->someVar()};
                if (res) {
                    return opt{res};
                }
            }
            return opt{};
        },
        [](const ArithExpPtr e) {
            auto res {e->getBase()->someVar()};
            return res ? res : e->getExponent()->someVar();
        });
}

void ArithExpr::exps(linked_hash_set<ArithExpPtr> &acc) const {
    return apply<void>(
        [](const ArithConstPtr) {},
        [](const ArithVarPtr) {},
        [&](const ArithAddPtr a) {
            for (const auto &arg: a->getArgs()) {
                arg->exps(acc);
            }
        },
        [&](const ArithMultPtr m) {
            for (const auto &arg: m->getArgs()) {
                arg->exps(acc);
            }
        },
        [&](const ArithExpPtr e) {
            e->getBase()->exps(acc);
            e->getExponent()->exps(acc);
            acc.emplace(e);
        });
}

linked_hash_set<ArithExpPtr> ArithExpr::exps() const {
    linked_hash_set<ArithExpPtr> acc;
    exps(acc);
    return acc;
}

std::optional<ArithExprPtr> ArithExpr::coeff(const ArithVarPtr var, const Int &degree) const {
    using opt = std::optional<ArithExprPtr>;
    return apply<opt>(
        [&](const ArithConstPtr c) {
            return opt{degree == 0 ? c : arith::mkConst(0)};
        },
        [&](const ArithVarPtr x) {
            if (var == x && degree == 1) {
                return opt{arith::mkConst(1)};
            } else if (var != x && degree == 0) {
                return opt{x};
            } else {
                return opt{arith::mkConst(0)};
            }
        },
        [&](const ArithAddPtr a) {
            ArithExprVec args;
            for (const auto &arg: a->getArgs()) {
                if (const auto c {arg->coeff(var, degree)}) {
                    args.emplace_back(*c);
                }
            }
            return opt{arith::mkPlus(std::move(args))};
        },
        [&](const ArithMultPtr m) {
            const auto e {arith::mkExp(var->toExpr(), arith::mkConst(degree))};
            auto args {m->getArgs()};
            if (std::erase(args, e) > 0) {
                return opt{arith::mkTimes(std::move(args))};
            }
            return opt{arith::mkConst(0)};
        },
        [&](const ArithExpPtr e) {
            if (e->getBase()->isVar() == std::optional{var} && e->getExponent()->isInt() == std::optional{degree}) {
                return opt{arith::mkConst(1)};
            }
            if (e->isPoly(var)) {
                return opt{arith::mkConst(0)};
            }
            return opt{};
        });
}

std::optional<ArithExprPtr> ArithExpr::lcoeff(const ArithVarPtr var) const {
    using opt = std::optional<ArithExprPtr>;
    return apply<opt>(
        [](const ArithConstPtr) {
            return opt{arith::mkConst(0)};
        },
        [&](const ArithVarPtr x) {
            return x->coeff(var);
        },
        [&](const ArithAddPtr a) {
            std::optional<Int> degree;
            opt res;
            for (const auto &arg: a->getArgs()) {
                const auto r {arg->lcoeff(var)};
                if (res) {
                    const auto d {arg->isPoly(var)};
                    if (!degree || d < *degree) {
                        res = r;
                        degree = d;
                    }
                }
            }
            return res;
        },
        [&](const ArithMultPtr m) {
            opt lcoeff;
            std::vector<ArithExprPtr> new_args;
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
                return opt{arith::mkTimes(std::move(new_args))};
            } else {
                return opt{};
            }
        },
        [&](const ArithExpPtr e) {
            if (e->isPoly(var)) {
                return opt{arith::mkConst(1)};
            }
            return opt{};
        });
}

bool ArithExpr::isIntegral() const {
    return apply<bool>(
        [](const ArithConstPtr x) {
            return x->intValue().has_value();
        },
        [](const ArithVarPtr) {
            return true;
        },
        [](const ArithAddPtr a) {
            std::vector<ArithExprPtr> nonInt;
            for (const auto &arg: a->getArgs()) {
                if (!arg->isIntegral()) {
                    if (arg->isPow()) {
                        return false;
                    }
                    nonInt.emplace_back(arg);
                }
            }
            const auto e {arith::mkTimes(std::move(nonInt))};
            unsigned i {0};
            linked_hash_map<ArithVarPtr, Int> valuation;
            // degrees, subs share indices with vars
            std::vector<Int> degrees;
            std::vector<ArithVarPtr> vars;
            for (const auto &x: e->vars()) {
                vars.emplace_back(x);
                degrees.emplace_back(*e->isPoly(x));
                valuation.emplace(x, 0);
                ++i;
            }
            while (true) {
                // substitute every variable x_i by the integer subs[i] and check if the result is an integer
                const auto res {e->evalToRational(valuation)};
                if (mp::denominator(res) != 1) {
                    return false;
                }
                // increase subs (lexicographically) if possible
                // (the idea is that subs takes all possible combinations of 0,...,degree[i]+1 for every entry i)
                bool foundNext = false;
                for (unsigned int i = 0; i < degrees.size(); i++) {
                    const auto x {vars[i]};
                    const auto val {valuation[x]};
                    if (val >= degrees[i]+1) {
                        valuation.put(x, 0);
                    } else {
                        valuation.put(x, val + 1);
                        foundNext = true;
                        break;
                    }
                }
                if (!foundNext) {
                    return true;
                }
            }
        },
        [](const ArithMultPtr m) {
            const auto &args {m->getArgs()};
            return std::all_of(args.begin(), args.end(), [](const auto &arg) {
                return arg->isIntegral();
            });
        },
        [](const ArithExpPtr e) {
            return true;
        });
}

Rational ArithExpr::evalToRational(const linked_hash_map<ArithVarPtr, Int> &valuation) const {
    return apply<Rational>(
        [](const ArithConstPtr t) {
            return **t;
        },
        [&](const ArithVarPtr x) {
            return valuation.get(x).value_or(0);
        },
        [&](const ArithAddPtr a) {
            const auto &args {a->getArgs()};
            return std::accumulate(args.begin(), args.end(), Rational{0}, [&](const auto &x, const auto y) {
                return x + y->evalToRational(valuation);
            });
        },
        [&](const ArithMultPtr m) {
            const auto &args {m->getArgs()};
            return std::accumulate(args.begin(), args.end(), Rational{1}, [&](const auto &x, const auto y) {
                return x * y->evalToRational(valuation);
            });
        },
        [&](const ArithExpPtr e) {
            return mp::pow(mp::numerator(e->getBase()->evalToRational(valuation)), e->getExponent()->evalToRational(valuation).convert_to<long>());
        });
}

Int ArithExpr::eval(const linked_hash_map<ArithVarPtr, Int> &valuation) const {
    assert(isIntegral());
    const auto res {evalToRational(valuation)};
    if (mp::denominator(res) != 1) {
        throw std::invalid_argument(toString(shared_from_this()) + " is not integral");
    }
    return mp::numerator(res);
}

std::pair<Rational, std::optional<ArithExprPtr>> ArithExpr::decompose() const {
    using pair = std::pair<Rational, std::optional<ArithExprPtr>>;
    return apply<pair>(
        [](const ArithConstPtr t) {
            return pair{**t, {}};
        },
        [](const ArithVarPtr x) {
            return pair{1, {x->toExpr()}};
        },
        [](const ArithAddPtr a) {
            return pair{1, {a}};
        },
        [](const ArithMultPtr m) {
            const auto &args {m->getArgs()};
            std::vector<ArithExprPtr> non_const {args.begin(), args.end()};
            for (const auto &arg: args) {
                const auto val {arg->isRational()};
                if (val) {
                    std::erase(non_const, arg);
                    return pair{***val, {arith::mkTimes(std::move(non_const))}};
                }
            }
            return pair{1, {m}};
        },
        [](const ArithExpPtr e) {
            return pair {1, {e}};
        });
}

bool ArithExpr::isUnivariate(std::optional<ArithVarPtr> &acc) const {
    return apply<bool>(
        [](const ArithConstPtr) {
            return false;
        },
        [&](const ArithVarPtr x) {
            if (!acc) {
                acc = x;
            }
            return acc == std::optional{x};
        },
        [&](const ArithAddPtr a) {
            const auto &args {a->getArgs()};
            return std::all_of(args.begin(), args.end(), [&](const auto &arg) -> bool {
                return !arg->isMultivariate(acc);
            }) && acc;
        },
        [&](const ArithMultPtr m) {
            const auto &args {m->getArgs()};
            return std::all_of(args.begin(), args.end(), [&](const auto &arg) -> bool {
                return !arg->isMultivariate(acc);
            }) && acc;
        },
        [&](const ArithExpPtr e) {
            return !e->getBase()->isMultivariate(acc) && !e->getExponent()->isMultivariate(acc) && acc;
        });
}

bool ArithExpr::isNegated() const {
    return apply<bool>(
        [](const ArithConstPtr c) {
            return c->getValue() < 0;
        },
        [](const ArithVarPtr) {
            return false;
        },
        [](const ArithAddPtr) {
            return false;
        },
        [](const ArithMultPtr m) {
            return m->getConstantFactor() < 0;
        },
        [](const ArithExpPtr) {
            return false;
        }
    );
}

bool ArithExpr::isMultivariate(std::optional<ArithVarPtr> &acc) const {
    return apply<bool>(
        [](const ArithConstPtr) {
            return false;
        },
        [&](const ArithVarPtr x) {
            if (!acc) {
                acc = x;
            }
            return acc != std::optional{x};
        },
        [&](const ArithAddPtr a) {
            const auto &args {a->getArgs()};
            return std::any_of(args.begin(), args.end(), [&](const auto &arg) -> bool {
                return arg->isMultivariate(acc);
            });
        },
        [&](const ArithMultPtr m) {
            const auto &args {m->getArgs()};
            return std::any_of(args.begin(), args.end(), [&](const auto &arg) -> bool {
                return arg->isMultivariate(acc);
            });
        },
        [&](const ArithExpPtr e) {
            return e->getBase()->isMultivariate(acc) || e->getExponent()->isMultivariate(acc);
        });
}

std::ostream& operator<<(std::ostream &s, const ArithExprPtr e) {
    e->apply<void>(
        [&](const ArithConstPtr c) {
            s << c->getValue();
        },
        [&](const ArithVarPtr x) {
            s << x->getName();
        },
        [&](const ArithAddPtr a) {
            auto fst {true};
            for (const auto &arg: a->getArgs()) {
                if (fst) {
                    fst = false;
                    s << arg;
                } else {
                    if (arg->isNegated()) {
                        s << " - " << -arg;
                    } else {
                        s << " + " << arg;
                    }
                }
            }
        },
        [&](const ArithMultPtr a) {
            auto fst {true};
            auto negative {false};
            auto count {a->getArgs().size()};
            std::stringstream ss;
            for (auto arg: a->getArgs()) {
                std::stringstream as;
                if (arg->isNegated()) {
                    negative = !negative;
                    if (const auto r {arg->isRational()}) {
                        if (***r == -1) {
                            --count;
                            continue;
                        }
                    }
                    arg = -arg;
                }
                if (arg->isRational()) {
                    as << arg;
                } else if (arg->isAdd()) {
                    as << "(" << arg << ")";
                } else {
                    as << arg;
                }
                if (fst) {
                    fst = false;
                } else {
                    ss << " * ";
                }
                ss << as.str();
            }
            if (negative) {
                if (count == 1) {
                    s << "-" << ss.str();
                } else {
                    s << "-(" << ss.str() << ")";
                }
            } else {
                s << ss.str();
            }
        },
        [&](const ArithExpPtr a) {
            const auto b {a->getBase()};
            const auto e {a->getExponent()};
            if (!b->isRational() && !b->isVar()) {
                s << "(" << b << ")";
            } else {
                s << b;
            }
            s << " ^ ";
            if (!e->isRational() && !e->isVar()) {
                s << "(" << e << ")";
            } else {
                s << e;
            }
        });
    return s;
}

std::ostream& operator<<(std::ostream &s, const ArithVarPtr e) {
    return s << e->getName();
}
