#include "arithexpr.hpp"
#include "optional.hpp"
#include "linkedhashmap.hpp"

#include <sstream>
#include <numeric>

std::size_t hash_value(const ArithExprPtr &x) {
    return std::hash<std::shared_ptr<const ArithExpr>>{}(x.as_nullable());
}

std::size_t hash_value(const ArithVarPtr &x) {
    return std::hash<std::shared_ptr<const ArithVar>>{}(x.as_nullable());
}

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
    return arith::mkTimes(x, arith::mkConst(-1));
}

ArithExprPtr operator-(const ArithExprPtr x, const ArithExprPtr y) {
    return arith::mkPlus(x,-y);
}

ArithExprPtr operator+(const ArithExprPtr x, const ArithExprPtr y) {
    return arith::mkPlus(x, y);
}

ArithExprPtr operator*(const ArithExprPtr x, const ArithExprPtr y) {
    return arith::mkTimes(x,y);
}

ArithExprPtr ArithExpr::divide(const Rational &y) const {
    return arith::mkTimes(arith::mkConst(Rational(mp::denominator(y), mp::numerator(y))), toPtr());
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

const std::optional<ArithModPtr> ArithExpr::isMod() const {
    if (kind == arith::Kind::Mod) {
        return cpp::assume_not_null(static_pointer_cast<const ArithMod>(shared_from_this()));
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
        [](const ArithModPtr) {
            return false;
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
        [](const ArithModPtr) {
            return false;
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
        [&](const ArithModPtr m) {
            m->getLhs()->collectVars(res);
            m->getRhs()->collectVars(res);
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
        [&](const ArithModPtr m) {
            return m->getLhs()->hasVarWith(predicate) || m->getRhs()->hasVarWith(predicate);
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
        [&](const ArithModPtr m) {
            return !m->getLhs()->has(var) && !m->getRhs()->has(var);
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
        [](const ArithModPtr m) {
            return m->getLhs()->denomLcm() * m->getRhs()->denomLcm();
        },
        [](const ArithExpPtr) {
            return 1;
        });
}

Rational ArithExpr::getConstantFactor() const {
    return apply<Rational>(
        [](const ArithConstPtr t) {
            return t->getValue();
        },
        [](const ArithVarPtr) {
            return 1;
        },
        [](const ArithAddPtr a) {
            const auto &args{a->getArgs()};
            auto it{args.begin()};
            Rational res{(*it)->getConstantFactor()};
            for (++it; it != args.end(); ++it) {
                const auto factor {(*it)->getConstantFactor()};
                const auto num {mp::gcd(mp::numerator(factor), mp::numerator(res))};
                const auto denom {mp::lcm(mp::denominator(factor), mp::denominator(res))};
                res = Rational(num, denom);
            }
            return res;
        },
        [](const ArithMultPtr m) {
            const auto &args{m->getArgs()};
            const auto it{std::find_if(args.begin(), args.end(), [](const auto arg) {
                return arg->isRational();
            })};
            return it == args.end() ? Rational(1) : (*(*it)->isRational())->getValue();
        },
        [](const ArithModPtr m) {
            return 1;
        },
        [](const ArithExprPtr) {
            return 1;
        });
}

Rational ArithExpr::getConstantAddend() const {
    return apply<Rational>(
        [](const ArithConstPtr t) {
            return t->getValue();
        },
        [](const ArithVarPtr) {
            return 0;
        },
        [](const ArithAddPtr a) {
            Rational res {0};
            for (const auto &arg: a->getArgs()) {
                res += arg->getConstantAddend();
            }
            return res;
        },
        [](const ArithMultPtr m) {
            return 0;
        },
        [](const ArithModPtr m) {
            return 0;
        },
        [](const ArithExprPtr) {
            return 0;
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
        [](const ArithModPtr m) {
            const auto res {m->getLhs()->someVar()};
            return res ? res : m->getRhs()->someVar();
        },
        [](const ArithExpPtr e) {
            const auto res {e->getBase()->someVar()};
            return res ? res : e->getExponent()->someVar();
        });
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
            if (degree == 0) {
                return opt{m->has(var) ? arith::mkConst(0) : toPtr()};
            }
            const auto e {arith::mkExp(var->toExpr(), arith::mkConst(degree))};
            auto args {m->getArgs()};
            if (args.erase(e) > 0) {
                ArithExprVec arg_vec {args.begin(), args.end()};
                return opt{arith::mkTimes(std::move(arg_vec))};
            }
            return opt{arith::mkConst(0)};
        },
        [&](const ArithModPtr m) {
            if (has(var)) {
                return opt{};
            } else {
                return opt{arith::mkConst(0)};
            }
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
            Int degree {0};
            opt res;
            for (const auto &arg: a->getArgs()) {
                if (const auto r {arg->lcoeff(var)}) {
                    const auto d {arg->isPoly(var)};
                    if (d && *d > degree) {
                        res = *r;
                        degree = *d;
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
        [&](const ArithModPtr m) {
            if (has(var)) {
                return opt{};
            } else {
                return opt{arith::mkConst(0)};
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
            const auto e {arith::mkPlus(std::move(nonInt))};
            linked_hash_map<ArithVarPtr, Int> valuation;
            // degrees, subs share indices with vars
            std::vector<Int> degrees;
            std::vector<ArithVarPtr> vars;
            for (const auto &x: e->vars()) {
                vars.emplace_back(x);
                degrees.emplace_back(*e->isPoly(x));
                valuation.emplace(x, 0);
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
        [](const ArithModPtr m) {
            return m->getLhs()->isIntegral() && m->getRhs()->isIntegral();
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
        [&](const ArithModPtr m) {
            const Int x {m->getLhs()->eval(valuation)};
            const Int y {m->getRhs()->eval(valuation)};
            const Int x_abs {mp::abs(x)};
            const Int y_abs {mp::abs(y)};
            const Rational mod {x_abs % y_abs};
            if (mod == 0 || x >= 0) {
                return mod;
            } else {
                return Rational(y_abs) - mod;
            }
        },
        [&](const ArithExpPtr e) {
            return mp::pow(mp::numerator(e->getBase()->evalToRational(valuation)), e->getExponent()->evalToRational(valuation).convert_to<long>());
        });
}

Int ArithExpr::eval(const linked_hash_map<ArithVarPtr, Int> &valuation) const {
    #if DEBUG
    assert(isIntegral());
    #endif
    const auto res {evalToRational(valuation)};
    if (mp::denominator(res) != 1) {
        throw std::invalid_argument(toString(toPtr()) + " is not integral");
    }
    return mp::numerator(res);
}

std::optional<ArithExprPtr> ArithExpr::solve(const ArithVarPtr var) const {
    // we can only solve linear expressions with rational coefficients
    if (!isLinear({{var}})) {
        return {};
    }
    const auto c {coeff(var)};
    if (!c || (*c)->is(0)) {
        return {};
    }
    const auto r {(*c)->isRational()};
    if (!r) {
        return {};
    }
    const auto monomial {(*c) * var->toExpr()};
    const auto not_normalized {toPtr() - monomial};
    const auto normalized {not_normalized->divide(-(***r))};
    return normalized;
}

ArithExprPtr ArithExpr::toPtr() const {
    return cpp::assume_not_null(shared_from_this());
}

sexpresso::Sexp ArithExpr::to_smtlib() const {
    return apply<sexpresso::Sexp>(
        [](const ArithConstPtr t) {
            if (const auto val {t->isInt()}) {
                if (*val < 0) {
                    sexpresso::Sexp res{"-"};
                    const Int neg {-*val};
                    res.addChild(neg.str());
                    return res;
                } else {
                    return sexpresso::Sexp(val->str());
                }
            } else {
                sexpresso::Sexp div{"/"};
                const Int num {mp::abs(mp::numerator(**t))};
                const Int denom {mp::abs(mp::denominator(**t))};
                div.addChild(num.str());
                div.addChild(denom.str());
                if (**t >= 0) {
                    return div;
                } else {
                    sexpresso::Sexp res{"-"};
                    res.addChild(div);
                    return res;
                }
            }
        },
        [&](const ArithVarPtr x) {
            return sexpresso::Sexp(x->getName());
        },
        [&](const ArithAddPtr a) {
            sexpresso::Sexp res{"+"};
            for (const auto &arg: a->getArgs()) {
                res.addChild(arg->to_smtlib());
            }
            return res;
        },
        [&](const ArithMultPtr m) {
            sexpresso::Sexp res{"*"};
            for (const auto &arg: m->getArgs()) {
                res.addChild(arg->to_smtlib());
            }
            return res;
        },
        [&](const ArithModPtr m) {
            sexpresso::Sexp res{"mod"};
            res.addChild(m->getLhs()->to_smtlib());
            res.addChild(m->getRhs()->to_smtlib());
            return res;
        },
        [&](const ArithExpPtr e) {
            sexpresso::Sexp res{"exp"};
            res.addChild(e->getBase()->to_smtlib());
            res.addChild(e->getExponent()->to_smtlib());
            return res;
        }
    );
}

ArithExprPtr ArithExpr::renameVars(const arith_var_map &map) const {
    return apply<ArithExprPtr>(
        [&](const ArithConstPtr t) {
            return toPtr();
        },
        [&](const ArithVarPtr x) {
            const auto it {map.left.find(x)};
            if (it == map.left.end()) {
                return toPtr();
            } else {
                return it->second->toPtr();
            }
        },
        [&](const ArithAddPtr a) {
            ArithExprSet args;
            for (const auto &arg: a->getArgs()) {
                args.insert(arg->renameVars(map));
            }
            return ArithAdd::cache.from_cache(args);
        },
        [&](const ArithMultPtr m) {
            ArithExprSet args;
            for (const auto &arg: m->getArgs()) {
                args.insert(arg->renameVars(map));
            }
            return ArithMult::cache.from_cache(args);
        },
        [&](const ArithModPtr m) {
            return ArithMod::cache.from_cache(m->getLhs()->renameVars(map), m->getRhs()->renameVars(map));
        },
        [&](const ArithExpPtr e) {
            return ArithExp::cache.from_cache(e->getBase()->renameVars(map), e->getExponent()->renameVars(map));
        }
    );
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
        [](const ArithModPtr m) {
            return pair {1, {m}};
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
        [&](const ArithModPtr m) {
            return !m->getLhs()->isMultivariate(acc) && !m->getRhs()->isMultivariate(acc) && acc;
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
        [](const ArithModPtr m) {
            return false;
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
        [&](const ArithModPtr m) {
            return m->getLhs()->isMultivariate(acc) || m->getRhs()->isMultivariate(acc);
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
        [&](const ArithModPtr m) {
            const auto lhs {m->getLhs()};
            const auto rhs {m->getRhs()};
            if (lhs->isRational() || lhs->isVar()) {
                s << m->getLhs();
            } else {
                s << "(" << m->getLhs() << ")";
            }
            s << " % ";
            if (rhs->isRational() || rhs->isVar()) {
                s << m->getRhs();
            } else {
                s << "(" << m->getRhs() << ")";
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
