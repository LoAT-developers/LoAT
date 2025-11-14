#include "arithexpr.hpp"
#include "optional.hpp"
#include "sexpresso.hpp"

#include <sstream>
#include <numeric>

#include "model.hpp"

std::size_t hash_value(const ArithExprPtr &x) {
    return std::hash<std::shared_ptr<const ArithExpr>>{}(x.as_nullable());
}

std::size_t hash_value(const ArithVarPtr &x) {
    return std::hash<std::shared_ptr<const ArrayRead<Arith>>>{}(x.as_nullable());
}

ArithExpr::ArithExpr(): kind(arith::Kind::Variable) {}

ArithExpr::ArithExpr(const arith::Kind kind): kind(kind) {}

VarSet ArithExpr::vars() const {
    VarSet res;
    collectVars(res);
    return res;
}

void ArithExpr::collectCells(CellSet& res) const {
    collectCells(res.get<ArithVarPtr>());
}

void ArithExpr::collectCells(linked_hash_set<ArithVarPtr>& res) const {
    apply<void>(
        [](const ArithConstPtr&) {},
        [&](const ArithVarPtr& x) {
            res.emplace(x);
        },
        [&](const ArithAddPtr& a) {
            for (const auto &arg: a->getArgs()) {
                arg->collectCells(res);
            }
        },
        [&](const ArithMultPtr& m) {
            for (const auto &arg: m->getArgs()) {
                arg->collectCells(res);
            }
        },
        [&](const ArithModPtr& m) {
            m->getLhs()->collectCells(res);
            m->getRhs()->collectCells(res);
        },
        [&](const ArithExpPtr& e) {
            e->getBase()->collectCells(res);
            e->getExponent()->collectCells(res);
        });
}

linked_hash_set<ArithVarPtr> ArithExpr::cells() const {
    linked_hash_set<ArithVarPtr> res;
    collectCells(res);
    return res;
}

bool ArithExpr::is(const Rational &val) const {
    const auto c {isRational()};
    return c && ***c == val;
}

std::optional<Int> ArithExpr::maxDegree() const {
    Int max {0};
    for (const auto &x: cells()) {
        if (const auto deg {isPoly(x)}) {
            max = mp::max(max, *deg);
        } else {
            return {};
        }
    }
    return max;
}

bool ArithExpr::has(const ArithVarPtr& x) const {
    return hasCellWith([&](const auto &y) {
        return x == y;
    });
}

ArithExprPtr operator-(const ArithExprPtr& x) {
    return arith::mkTimes(x, arith::mkConst(-1));
}

ArithExprPtr operator-(const ArithExprPtr& x, const ArithExprPtr& y) {
    return arith::mkPlus(x,-y);
}

ArithExprPtr operator+(const ArithExprPtr& x, const ArithExprPtr& y) {
    return arith::mkPlus(x, y);
}

ArithExprPtr operator*(const ArithExprPtr& x, const ArithExprPtr& y) {
    return arith::mkTimes(x,y);
}

ArithExprPtr ArithExpr::divide(const Rational &d) const {
    return arith::mkTimes(arith::mkConst(Rational(mp::denominator(d), mp::numerator(d))), toPtr());
}

ArithExprPtr operator^(const ArithExprPtr& x, const ArithExprPtr& y) {
    return arith::mkExp(x, y);
}

std::optional<ArithConstPtr> ArithExpr::isRational() const {
    if (kind == arith::Kind::Constant) {
        return cpp::assume_not_null(static_pointer_cast<const ArithConst>(shared_from_this()));
    }
    return {};
}

std::optional<Int> ArithExpr::isInt() const {
    return flat_map<ArithConstPtr, Int>(isRational(), [](const auto &r){
        return r->intValue();
    });
}

std::optional<ArithVarPtr> ArithExpr::isVar() const {
    if (kind == arith::Kind::Variable) {
        return cpp::assume_not_null(static_pointer_cast<const ArrayRead<Arith>>(shared_from_this()));
    }
    return {};
}

std::optional<ArithExpPtr> ArithExpr::isPow() const {
    if (kind == arith::Kind::Exp) {
        return cpp::assume_not_null(static_pointer_cast<const ArithExp>(shared_from_this()));
    }
    return {};
}

std::optional<ArithMultPtr> ArithExpr::isMult() const {
    if (kind == arith::Kind::Times) {
        return cpp::assume_not_null(static_pointer_cast<const ArithMult>(shared_from_this()));
    }
    return {};
}

std::optional<ArithModPtr> ArithExpr::isMod() const {
    if (kind == arith::Kind::Mod) {
        return cpp::assume_not_null(static_pointer_cast<const ArithMod>(shared_from_this()));
    }
    return {};
}

std::optional<ArithAddPtr> ArithExpr::isAdd() const {
    if (kind == arith::Kind::Plus) {
        return cpp::assume_not_null(static_pointer_cast<const ArithAdd>(shared_from_this()));
    }
    return {};
}

bool ArithExpr::isLinear(const std::optional<linked_hash_set<ArithVarPtr>> &vars) const {
    const auto is_linear {[&](const auto &arg) -> bool {
        return arg->isLinear(vars);
    }};
    const auto is_constant {[&](const auto &arg) -> bool {
        return !arg->hasCellWith([&](const auto &x) {
            return vars ? vars->contains(x) : true;
        });
    }};
    return apply<bool>(
        [](const ArithConstPtr&) {
            return true;
        },
        [](const ArithVarPtr& x) {
            return x->arr()->isLinear();
        },
        [&](const ArithAddPtr& a) {
            const auto &args {a->getArgs()};
            return std::ranges::all_of(args, is_linear);
        },
        [&](const ArithMultPtr& m) {
            const auto &args {m->getArgs()};
            auto found {false};
            for (const auto &arg: args) {
                if (!arg->isLinear(vars)) {
                    return false;
                }
                if (!is_constant(arg)) {
                    if (found) {
                        return false;
                    }
                    found = true;
                }
            }
            return true;
        },
        [](const ArithModPtr&) {
            return false;
        },
        [&](const ArithExpPtr& e) {
            return is_constant(e);
        });
}

std::optional<Int> ArithExpr::isPoly() const {
    using opt = std::optional<Int>;
    return apply<opt>(
        [](const ArithConstPtr&) {
            return opt{0};
        },
        [](const ArithVarPtr& x) {
            return x->isPoly();
        },
        [](const ArithAddPtr& a) {
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
        [](const ArithMultPtr& m) {
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
        [](const ArithModPtr&) {
            return false;
        },
        [](const ArithExpPtr& e) {
            if (const auto exp {e->getExponent()->isInt()}) {
                if (const auto base_degree {e->getBase()->isPoly()}) {
                    return opt{*base_degree * *exp};
                }
            }
            return opt{};
        });
}

void ArithExpr::collectVars(VarSet &res) const {
    apply<void>(
        [](const ArithConstPtr&) {},
        [&](const ArithVarPtr& x) {
            x->collectVars(res);
        },
        [&](const ArithAddPtr& a) {
            for (const auto &arg: a->getArgs()) {
                arg->collectVars(res);
            }
        },
        [&](const ArithMultPtr& m) {
            for (const auto &arg: m->getArgs()) {
                arg->collectVars(res);
            }
        },
        [&](const ArithModPtr& m) {
            m->getLhs()->collectVars(res);
            m->getRhs()->collectVars(res);
        },
        [&](const ArithExpPtr& e) {
            e->getBase()->collectVars(res);
            e->getExponent()->collectVars(res);
        });
}

bool ArithExpr::hasCellWith(const std::function<bool(ArithVarPtr)>& predicate) const {
    return apply<bool>(
        [](const ArithConstPtr&) {
            return false;
        },
        [&](const ArithVarPtr& x) {
            return predicate(x);
        },
        [&](const ArithAddPtr& a) {
            const auto &args {a->getArgs()};
            return std::ranges::any_of(args, [&](const auto &arg) -> bool {
                return arg->hasCellWith(predicate);
            });
        },
        [&](const ArithMultPtr& m) {
            const auto &args {m->getArgs()};
            return std::ranges::any_of(args, [&](const auto &arg) -> bool {
                return arg->hasCellWith(predicate);
            });
        },
        [&](const ArithModPtr& m) {
            return m->getLhs()->hasCellWith(predicate) || m->getRhs()->hasCellWith(predicate);
        },
        [&](const ArithExpPtr& e) {
            return e->getBase()->hasCellWith(predicate) || e->getExponent()->hasCellWith(predicate);
        });
}

bool ArithExpr::hasVarWith(const std::function<bool(ArrayVarPtr<Arith>)>& predicate) const {
    return apply<bool>(
        [](const ArithConstPtr&) {
            return false;
        },
        [&](const ArithVarPtr& x) {
            return predicate(x->var()) || std::ranges::any_of(x->indices(), [&](const auto& i) {
                return i->hasVarWith(predicate);
            });
        },
        [&](const ArithAddPtr& a) {
            const auto &args {a->getArgs()};
            return std::ranges::any_of(args, [&](const auto &arg) -> bool {
                return arg->hasVarWith(predicate);
            });
        },
        [&](const ArithMultPtr& m) {
            const auto &args {m->getArgs()};
            return std::ranges::any_of(args, [&](const auto &arg) -> bool {
                return arg->hasVarWith(predicate);
            });
        },
        [&](const ArithModPtr& m) {
            return m->getLhs()->hasVarWith(predicate) || m->getRhs()->hasVarWith(predicate);
        },
        [&](const ArithExpPtr& e) {
            return e->getBase()->hasVarWith(predicate) || e->getExponent()->hasVarWith(predicate);
        });
}

std::optional<Int> ArithExpr::isPoly(const ArithVarPtr& n) const {
    using opt = std::optional<Int>;
    return apply<opt>(
        [](const ArithConstPtr&) {
            return opt{0};
        },
        [&](const ArithVarPtr& x) {
            return opt{x == n ? 1 : 0};
        },
        [&](const ArithAddPtr& a) {
            Int res {0};
            for (const auto &arg: a->getArgs()) {
                const auto arg_degree {arg->isPoly(n)};
                if (!arg_degree) {
                    return opt{};
                }
                res = mp::max(res, *arg_degree);
            }
            return opt{res};
        },
        [&](const ArithMultPtr& m) {
            Int res {0};
            for (const auto &arg: m->getArgs()) {
                const auto arg_degree {arg->isPoly(n)};
                if (!arg_degree) {
                    return opt{};
                }
                res = res + *arg_degree;
            }
            return opt{res};
        },
        [&](const ArithModPtr& m) {
            return !m->getLhs()->has(n) && !m->getRhs()->has(n);
        },
        [&](const ArithExpPtr& e) {
            if (!e->has(n)) {
                return opt{0};
            }
            if (const auto exp {e->getExponent()->isInt()}) {
                if (const auto base_degree {e->getBase()->isPoly(n)}) {
                    return opt{*base_degree * *exp};
                }
            }
            return opt{};
        });
}

Int ArithExpr::denomLcm() const {
    return apply<Int>(
        [](const ArithConstPtr& t) {
            return *t->denominator()->intValue();
        },
        [](const ArithVarPtr&) {
            return 1;
        },
        [](const ArithAddPtr& a) {
            const auto &args {a->getArgs()};
            return std::accumulate(args.begin(), args.end(), Int{1}, [](const auto &x, const auto &y) {
                return x * y->denomLcm();
            });
        },
        [](const ArithMultPtr& m) {
            const auto &args {m->getArgs()};
            return std::accumulate(args.begin(), args.end(), Int{1}, [](const auto &x, const auto &y) {
                return x * y->denomLcm();
            });
        },
        [](const ArithModPtr& m) {
            return m->getLhs()->denomLcm() * m->getRhs()->denomLcm();
        },
        [](const ArithExpPtr&) {
            return 1;
        });
}

Rational ArithExpr::getConstantFactor() const {
    return apply<Rational>(
        [](const ArithConstPtr& t) {
            return t->getValue();
        },
        [](const ArithVarPtr&) {
            return 1;
        },
        [](const ArithAddPtr& a) {
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
        [](const ArithMultPtr& m) {
            const auto &args{m->getArgs()};
            const auto it{std::find_if(args.begin(), args.end(), [](const auto& arg) {
                return arg->isRational();
            })};
            return it == args.end() ? Rational(1) : (*(*it)->isRational())->getValue();
        },
        [](const ArithModPtr&) {
            return 1;
        },
        [](const ArithExprPtr&) {
            return 1;
        });
}

Rational ArithExpr::getConstantAddend() const {
    return apply<Rational>(
        [](const ArithConstPtr& t) {
            return t->getValue();
        },
        [](const ArithVarPtr&) {
            return 0;
        },
        [](const ArithAddPtr& a) {
            Rational res {0};
            for (const auto &arg: a->getArgs()) {
                res += arg->getConstantAddend();
            }
            return res;
        },
        [](const ArithMultPtr&) {
            return 0;
        },
        [](const ArithModPtr&) {
            return 0;
        },
        [](const ArithExprPtr&) {
            return 0;
        });
}

std::optional<ArithVarPtr> ArithExpr::someVar() const {
    using opt = std::optional<ArithVarPtr>;
    return apply<opt>(
        [](const ArithConstPtr&) {
            return opt{};
        },
        [](const ArithVarPtr& x) {
            return opt{x};
        },
        [](const ArithAddPtr& a) {
            for (const auto &arg: a->getArgs()) {
                if (const auto res {arg->someVar()}) {
                    return opt{res};
                }
            }
            return opt{};
        },
        [](const ArithMultPtr& m) {
            for (const auto &arg: m->getArgs()) {
                if (const auto res {arg->someVar()}) {
                    return opt{res};
                }
            }
            return opt{};
        },
        [](const ArithModPtr& m) {
            const auto res {m->getLhs()->someVar()};
            return res ? res : m->getRhs()->someVar();
        },
        [](const ArithExpPtr& e) {
            const auto res {e->getBase()->someVar()};
            return res ? res : e->getExponent()->someVar();
        });
}

std::optional<ArithExprPtr> ArithExpr::coeff(const ArithVarPtr& var, const Int &degree) const {
    using opt = std::optional<ArithExprPtr>;
    return apply<opt>(
        [&](const ArithConstPtr& c) {
            return opt{degree == 0 ? c : arith::zero()};
        },
        [&](const ArithVarPtr& x) {
            if (var == x && degree == 1) {
                return opt{arith::one()};
            }
            if (var != x && degree == 0) {
                return opt{x};
            }
            return opt{arith::zero()};
        },
        [&](const ArithAddPtr& a) {
            ArithExprVec args;
            for (const auto &arg: a->getArgs()) {
                if (const auto c {arg->coeff(var, degree)}) {
                    args.emplace_back(*c);
                }
            }
            return opt{arith::mkPlus(std::move(args))};
        },
        [&](const ArithMultPtr& m) {
            if (degree == 0) {
                return opt{m->has(var) ? arith::zero() : toPtr()};
            }
            const auto e {arith::mkExp(var, arith::mkConst(degree))};
            if (auto args {m->getArgs()}; args.erase(e) > 0) {
                ArithExprVec arg_vec {args.begin(), args.end()};
                return opt{arith::mkTimes(std::move(arg_vec))};
            }
            return opt{arith::zero()};
        },
        [&](const ArithModPtr&) {
            if (has(var)) {
                return opt{};
            }
            return opt{arith::zero()};
        },
        [&](const ArithExpPtr& e) {
            if (e->getBase()->isVar() == std::optional{var} && e->getExponent()->isInt() == std::optional{degree}) {
                return opt{arith::one()};
            }
            if (e->isPoly(var)) {
                return opt{arith::zero()};
            }
            return opt{};
        });
}

std::optional<ArithExprPtr> ArithExpr::lcoeff(const ArithVarPtr& var) const {
    using opt = std::optional<ArithExprPtr>;
    return apply<opt>(
        [](const ArithConstPtr&) {
            return opt{arith::zero()};
        },
        [&](const ArithVarPtr& x) {
            return x->coeff(var);
        },
        [&](const ArithAddPtr& a) {
            Int degree {0};
            opt res;
            for (const auto &arg: a->getArgs()) {
                if (const auto r {arg->lcoeff(var)}) {
                    if (const auto d {arg->isPoly(var)}; d && *d > degree) {
                        res = *r;
                        degree = *d;
                    }
                }
            }
            return res;
        },
        [&](const ArithMultPtr& m) {
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
            }
            return opt{};
        },
        [&](const ArithModPtr&) {
            if (has(var)) {
                return opt{};
            }
            return opt{arith::zero()};
        },
        [&](const ArithExpPtr& e) {
            if (e->isPoly(var)) {
                return opt{arith::one()};
            }
            return opt{};
        });
}

Rational ArithExpr::eval(const std::unordered_map<ArithVarPtr, Int>& map) const {
    return apply<Rational>(
        [](const ArithConstPtr& c) {
            return **c;
        },
        [&](const ArithVarPtr& v) {
            return Rational(map.at(v));
        },
        [&](const ArithAddPtr& a) {
            Rational res{0};
            for (const auto& x : a->getArgs()) {
                res += x->eval(map);
            }
            return res;
        },
        [&](const ArithMultPtr& m) {
            Rational res{1};
            for (const auto& x : m->getArgs()) {
                res *= x->eval(map);
            }
            return res;
        },
        [&](const ArithModPtr& m) {
            const auto lhs{m->getLhs()->eval(map)};
            const auto rhs{m->getRhs()->eval(map)};
            assert(mp::denominator(lhs) == 1);
            assert(mp::denominator(rhs) == 1);
            return Rational(mp::numerator(lhs) % mp::numerator(rhs));
        },
        [&](const ArithExpPtr& e) {
            const auto base{e->getBase()->eval(map)};
            const auto exp{e->getExponent()->eval(map)};
            assert(mp::denominator(base) == 1);
            assert(mp::denominator(exp) == 1);
            return Rational(mp::pow(mp::numerator(base), mp::numerator(exp).convert_to<long long>()));
        }
    );
}

ArithExprPtr ArithExpr::eval(const ModelPtr& model, const ArithVarPtr &keep) const {
    return apply<ArithExprPtr>(
        [](const ArithConstPtr& c) -> ArithExprPtr {
            return c;
        },
        [&](const ArithVarPtr& v) -> ArithExprPtr {
            return keep == v ? v : arith::mkConst(model->eval(v));
        },
        [&](const ArithAddPtr& a) {
            std::vector<ArithExprPtr> args;
            for (const auto& x : a->getArgs()) {
                args.emplace_back(x->eval(model, keep));
            }
            return arith::mkPlus(std::move(args));
        },
        [&](const ArithMultPtr& m) {
            std::vector<ArithExprPtr> args;
            for (const auto& x : m->getArgs()) {
                args.emplace_back(x->eval(model, keep));
            }
            return arith::mkTimes(std::move(args));
        },
        [&](const ArithModPtr& m) {
            const auto lhs{m->getLhs()->eval(model, keep)};
            const auto rhs{m->getRhs()->eval(model, keep)};
            return arith::mkMod(lhs, rhs);
        },
        [&](const ArithExpPtr& e) {
            const auto base{e->getBase()->eval(model, keep)};
            const auto exp{e->getExponent()->eval(model, keep)};
            return arith::mkExp(base, exp);
        }
    );
}

bool ArithExpr::isIntegral() const {
    return apply<bool>(
        [](const ArithConstPtr& x) {
            return x->intValue().has_value();
        },
        [](const ArithVarPtr&) {
            return true;
        },
        [](const ArithAddPtr& a) {
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
            std::unordered_map<ArithVarPtr, Int> valuation;
            // degrees, subs share indices with vars
            std::vector<Int> degrees;
            std::vector<ArithVarPtr> vars;
            for (const auto &x: e->cells()) {
                vars.emplace_back(x);
                degrees.emplace_back(*e->isPoly(x));
                valuation.emplace(x, 0);
            }
            while (true) {
                // substitute every variable 'x_i' by the integer subs[i] and check if the result is an integer
                if (const auto res {e->eval(valuation)}; mp::denominator(res) != 1) {
                    return false;
                }
                // increase subs (lexicographically) if possible
                // (the idea is that subs takes all possible combinations of 0,...,degree[i]+1 for every entry i)
                bool foundNext = false;
                for (unsigned int i = 0; i < degrees.size(); i++) {
                    const auto& x {vars[i]};
                    if (const auto val {valuation.at(x)}; val >= degrees[i]+1) {
                        valuation.erase(x);
                        valuation.emplace(x, 0);
                    } else {
                        valuation.erase(x);
                        valuation.emplace(x, val + 1);
                        foundNext = true;
                        break;
                    }
                }
                if (!foundNext) {
                    return true;
                }
            }
        },
        [](const ArithMultPtr& m) {
            const auto &args {m->getArgs()};
            return std::ranges::all_of(args, [](const auto &arg) {
                return arg->isIntegral();
            });
        },
        [](const ArithModPtr& m) {
            return m->getLhs()->isIntegral() && m->getRhs()->isIntegral();
        },
        [](const ArithExpPtr&) {
            return true;
        });
}

std::optional<ArithExprPtr> ArithExpr::solve(const ArithVarPtr& var) const {
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
    const auto monomial {*c * var};
    const auto not_normalized {toPtr() - monomial};
    return not_normalized->divide(-***r);
}

ArithExprPtr ArithExpr::toPtr() const {
    return cpp::assume_not_null(shared_from_this());
}

sexpresso::Sexp ArithExpr::to_smtlib() const {
    return apply<sexpresso::Sexp>(
        [](const ArithConstPtr& t) {
            if (const auto val {t->isInt()}) {
                if (*val < 0) {
                    sexpresso::Sexp res{"-"};
                    const Int neg {-*val};
                    res.addChild(neg.str());
                    return res;
                }
                return sexpresso::Sexp(val->str());
            }
            sexpresso::Sexp div{"/"};
            const Int num {mp::abs(mp::numerator(**t))};
            const Int denom {mp::abs(mp::denominator(**t))};
            div.addChild(num.str());
            div.addChild(denom.str());
            if (**t >= 0) {
                return div;
            }
            sexpresso::Sexp res{"-"};
            res.addChild(div);
            return res;
        },
        [&](const ArithVarPtr& x) {
            return x->to_smtlib();
        },
        [&](const ArithAddPtr& a) {
            sexpresso::Sexp res{"+"};
            for (const auto &arg: a->getArgs()) {
                res.addChild(arg->to_smtlib());
            }
            return res;
        },
        [&](const ArithMultPtr& m) {
            sexpresso::Sexp res{"*"};
            for (const auto &arg: m->getArgs()) {
                res.addChild(arg->to_smtlib());
            }
            return res;
        },
        [&](const ArithModPtr& m) {
            sexpresso::Sexp res{"mod"};
            res.addChild(m->getLhs()->to_smtlib());
            res.addChild(m->getRhs()->to_smtlib());
            return res;
        },
        [&](const ArithExpPtr& e) {
            sexpresso::Sexp res{"exp"};
            res.addChild(e->getBase()->to_smtlib());
            res.addChild(e->getExponent()->to_smtlib());
            return res;
        }
    );
}

ArithExprPtr ArithExpr::renameVars(const Renaming &map) const {
    return apply<ArithExprPtr>(
        [&](const ArithConstPtr&) {
            return toPtr();
        },
        [&](const ArithVarPtr& x) {
            return x->renameVars(map);
        },
        [&](const ArithAddPtr& a) {
            ArithExprSet args;
            for (const auto &arg: a->getArgs()) {
                args.insert(arg->renameVars(map));
            }
            return ArithAdd::cache.from_cache(args);
        },
        [&](const ArithMultPtr& m) {
            ArithExprSet args;
            for (const auto &arg: m->getArgs()) {
                args.insert(arg->renameVars(map));
            }
            return ArithMult::cache.from_cache(args);
        },
        [&](const ArithModPtr& m) {
            return ArithMod::cache.from_cache(m->getLhs()->renameVars(map), m->getRhs()->renameVars(map));
        },
        [&](const ArithExpPtr& e) {
            return ArithExp::cache.from_cache(e->getBase()->renameVars(map), e->getExponent()->renameVars(map));
        }
    );
}

std::pair<Rational, std::optional<ArithExprPtr>> ArithExpr::decompose() const {
    using pair = std::pair<Rational, std::optional<ArithExprPtr>>;
    return apply<pair>(
        [](const ArithConstPtr& t) {
            return pair{**t, {}};
        },
        [](const ArithVarPtr& x) {
            return pair{1, {x}};
        },
        [](const ArithAddPtr& a) {
            return pair{1, {a}};
        },
        [](const ArithMultPtr& m) {
            const auto &args {m->getArgs()};
            std::vector<ArithExprPtr> non_const {args.begin(), args.end()};
            for (const auto &arg: args) {
                if (const auto val {arg->isRational()}) {
                    std::erase(non_const, arg);
                    return pair{***val, {arith::mkTimes(std::move(non_const))}};
                }
            }
            return pair{1, {m}};
        },
        [](const ArithModPtr& m) {
            return pair {1, {m}};
        },
        [](const ArithExpPtr& e) {
            return pair {1, {e}};
        });
}

bool ArithExpr::isNegated() const {
    return apply<bool>(
        [](const ArithConstPtr& c) {
            return c->getValue() < 0;
        },
        [](const ArithVarPtr&) {
            return false;
        },
        [](const ArithAddPtr&) {
            return false;
        },
        [](const ArithMultPtr& m) {
            return m->getConstantFactor() < 0;
        },
        [](const ArithModPtr&) {
            return false;
        },
        [](const ArithExpPtr&) {
            return false;
        }
    );
}

std::ostream& operator<<(std::ostream &s, const ArithExprPtr& e) {
    e->apply<void>(
        [&](const ArithConstPtr& c) {
            s << c->getValue();
        },
        [&](const ArithVarPtr& x) {
            s << x;
        },
        [&](const ArithAddPtr& a) {
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
        [&](const ArithMultPtr& a) {
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
                if (arg->isAdd()) {
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
        [&](const ArithModPtr& m) {
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
        [&](const ArithExpPtr& a) {
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

std::ostream& operator<<(std::ostream &s, const ArithVarPtr& x) {
    return s << x->arr();
}

ArithExprPtr ArithExpr::subs(const Subs& subs) const {
    return apply<ArithExprPtr>(
        [&](const ArithConstPtr&) {
            return this->toPtr();
        },
        [&](const ArithVarPtr& x) {
            const auto arr {x->arr()->subs(subs)};
            std::vector<ArithExprPtr> indices;
            for (const auto& i: x->indices()) {
                indices.emplace_back(i->subs(subs));
            }
            return arrays::mkArrayRead(arr, indices);
        },
        [&](const ArithAddPtr& a) {
            const auto &args {a->getArgs()};
            std::vector<ArithExprPtr> new_args;
            std::ranges::transform(args, std::back_inserter(new_args), [&](const auto& arg) {
                return arg->subs(subs);
            });
            return arith::mkPlus(std::move(new_args));
        },
        [&](const ArithMultPtr& m) {
            const auto &args {m->getArgs()};
            std::vector<ArithExprPtr> new_args;
            std::ranges::transform(args, std::back_inserter(new_args), [&](const auto& arg) {
                return arg->subs(subs);
            });
            return arith::mkTimes(std::move(new_args));
        },
        [&](const ArithModPtr& m) {
            return arith::mkMod(m->getLhs()->subs(subs), m->getRhs()->subs(subs));
        },
        [&](const ArithExpPtr& e) {
            return arith::mkExp(e->getBase()->subs(subs), e->getExponent()->subs(subs));
        });
}

ArithExprPtr ArithExpr::subs(const linked_hash_map<ArithVarPtr, ArithExprPtr>& subs) const {
    return apply<ArithExprPtr>(
        [&](const ArithConstPtr&) {
            return this->toPtr();
        },
        [&](const ArithVarPtr& x) {
            return subs.get(x).value_or(x);
        },
        [&](const ArithAddPtr& a) {
            const auto &args {a->getArgs()};
            std::vector<ArithExprPtr> new_args;
            std::ranges::transform(args, std::back_inserter(new_args), [&](const auto& arg) {
                return arg->subs(subs);
            });
            return arith::mkPlus(std::move(new_args));
        },
        [&](const ArithMultPtr& m) {
            const auto &args {m->getArgs()};
            std::vector<ArithExprPtr> new_args;
            std::ranges::transform(args, std::back_inserter(new_args), [&](const auto& arg) {
                return arg->subs(subs);
            });
            return arith::mkTimes(std::move(new_args));
        },
        [&](const ArithModPtr& m) {
            return arith::mkMod(m->getLhs()->subs(subs), m->getRhs()->subs(subs));
        },
        [&](const ArithExpPtr& e) {
            return arith::mkExp(e->getBase()->subs(subs), e->getExponent()->subs(subs));
        });
}

ArithExprPtr arith::zero() {
    static const auto zero {mkConst(0)};
    return zero;
}

ArithExprPtr arith::one() {
    static const auto one {mkConst(1)};
    return one;
}
