#include "limitsmt.hpp"

#include "inftyexpression.hpp"
#include "smt.hpp"
#include "smtfactory.hpp"

#include <map>

using namespace std;

/**
 * Given the (abstract) coefficients of a univariate polynomial p in n (where the key is the
 * degree of the respective monomial), builds an expression which implies that
 * lim_{n->\infty} p is a positive constant
 */
static Bools::Expr posConstraint(const map<Int, Arith::Expr> &coefficients) {
    std::vector<Arith::Lit> conjunction;
    for (auto &[degree, c] : coefficients) {
        if (degree > 0) {
            conjunction.push_back(arith::mkEq(c, arith::mkConst(0)));
        } else {
            conjunction.push_back(arith::mkGt(c, arith::mkConst(0)));
        }
    }
    return bools::mkAndFromLits(conjunction);
}

static Bools::Expr constConstraint(const map<Int, Arith::Expr> &coefficients) {
    std::vector<Arith::Lit> conjunction;
    for (auto &[degree, c] : coefficients) {
        if (degree > 0) {
            conjunction.push_back(arith::mkEq(c, arith::mkConst(0)));
        }
    }
    return bools::mkAndFromLits(conjunction);
}

static Bools::Expr zeroConstraint(const map<Int, Arith::Expr> &coefficients) {
    std::vector<Arith::Lit> conjunction;
    for (auto &[degree, c] : coefficients) {
        conjunction.push_back(arith::mkEq(c, arith::mkConst(0)));
    }
    return bools::mkAndFromLits(conjunction);
}

/**
 * Given the (abstract) coefficients of a univariate polynomial p in n (where the key is the
 * degree of the respective monomial), builds an expression which implies that
 * lim_{n->\infty} p is a negative constant
 */
static Bools::Expr negConstraint(const map<Int, Arith::Expr> &coefficients) {
    std::vector<Arith::Lit> conjunction;
    for (const auto &[degree, c] : coefficients) {
        if (degree > 0) {
            conjunction.push_back(arith::mkEq(c, arith::mkConst(0)));
        } else {
            conjunction.push_back(arith::mkLt(c, arith::mkConst(0)));
        }
    }
    return bools::mkAndFromLits(conjunction);
}

/**
 * Given the (abstract) coefficients of a univariate polynomial p in n (where the key is the
 * degree of the respective monomial), builds an expression which implies
 * lim_{n->\infty} p = -\infty
 */
static Bools::Expr negInfConstraint(const map<Int, Arith::Expr> &coefficients) {
    Int maxDegree{0};
    for (const auto &[degree, _] : coefficients) {
        maxDegree = degree > maxDegree ? degree : maxDegree;
    }
    std::vector<Bools::Expr> disjunction;
    for (int i = 1; i <= maxDegree; i++) {
        std::vector<Arith::Lit> conjunction;
        for (const auto &[degree, c] : coefficients) {
            if (degree > i) {
                conjunction.push_back(arith::mkEq(c, arith::mkConst(0)));
            } else if (degree == i) {
                conjunction.push_back(arith::mkLt(c, arith::mkConst(0)));
            }
        }
        disjunction.push_back(bools::mkAndFromLits(conjunction));
    }
    return bools::mkOr(disjunction);
}

/**
 * Given the (abstract) coefficients of a univariate polynomial p in n (where the key is the
 * degree of the respective monomial), builds an expression which implies
 * lim_{n->\infty} p = \infty
 */
static Bools::Expr posInfConstraint(const map<Int, Arith::Expr> &coefficients) {
    Int maxDegree{0};
    for (const auto &[degree, _] : coefficients) {
        maxDegree = degree > maxDegree ? degree : maxDegree;
    }
    std::vector<Bools::Expr> disjunction;
    for (int i = 1; i <= maxDegree; i++) {
        std::vector<Arith::Lit> conjunction;
        for (const auto &[degree, c] : coefficients) {
            if (degree > i) {
                conjunction.push_back(arith::mkEq(c, arith::mkConst(0)));
            } else if (degree == i) {
                conjunction.push_back(arith::mkGt(c, arith::mkConst(0)));
            }
        }
        disjunction.push_back(bools::mkAndFromLits(conjunction));
    }
    return bools::mkOr(disjunction);
}

/**
 * @return the (abstract) coefficients of 'n' in 'ex', where the key is the degree of the respective monomial
 */
static map<Int, Arith::Expr> getCoefficients(const Arith::Expr ex, const Arith::Var n) {
    const auto maxDegree{*ex->isPoly(n)};
    map<Int, Arith::Expr> coefficients;
    for (int i = 0; i <= maxDegree; ++i) {
        coefficients.emplace(i, *ex->coeff(n, i));
    }
    return coefficients;
}

static Bools::Expr constConstraint(const Arith::Expr e, const Arith::Var n) {
    if (e->isPoly(n)) {
        return constConstraint(getCoefficients(e, n));
    } else if (const auto exp {e->isPow()}) {
        const auto base_const {constConstraint((*exp)->getBase(), n)};
        const auto exponent_const {constConstraint((*exp)->getExponent(), n)};
        return base_const && exponent_const;
    } else if (const auto mult {e->isMult()}) {
        std::vector<Arith::Expr> poly_args;
        std::vector<Bools::Expr> non_poly_const_args;
        for (const auto &arg: (*mult)->getArgs()) {
            if (arg->isPoly(n)) {
                poly_args.push_back(arg);
            } else {
                non_poly_const_args.push_back(constConstraint(arg, n));
            }
        }
        const auto poly {arith::mkTimes(std::move(poly_args))};
        const auto non_poly_const {bools::mkAnd(non_poly_const_args)};
        const auto poly_const {constConstraint(getCoefficients(poly, n))};
        return non_poly_const && poly_const;
    } else if (const auto add {e->isAdd()}) {
        std::vector<Arith::Expr> poly_args;
        std::vector<Bools::Expr> non_poly_const_args;
        for (const auto &arg: (*add)->getArgs()) {
            if (arg->isPoly(n)) {
                poly_args.push_back(arg);
            } else {
                non_poly_const_args.push_back(constConstraint(arg, n));
            }
        }
        const auto poly {arith::mkPlus(std::move(poly_args))};
        const auto non_poly_const {bools::mkAnd(non_poly_const_args)};
        const auto poly_const {constConstraint(getCoefficients(poly, n))};
        return non_poly_const && poly_const;
    }
    throw std::logic_error(toString(e) + "is neither a polynoimal, nor an exponential, a product, or a sum");
}

static Bools::Expr negConstraint(const Arith::Expr e, const Arith::Var n) {
    if (e->isPoly(n)) {
        return negConstraint(getCoefficients(e, n));
    } else {
        return bot();
    }
    throw std::logic_error(toString(e) + "is neither a polynoimal, nor an exponential, a product, or a sum");
}

static Bools::Expr posConstraint(const Arith::Expr e, const Arith::Var n) {
    if (e->isPoly(n)) {
        return posConstraint(getCoefficients(e, n));
    } else if (const auto exp {e->isPow()}) {
        const auto base_pos {posConstraint((*exp)->getBase(), n)};
        const auto exponent_pos {posConstraint((*exp)->getExponent(), n)};
        return base_pos && exponent_pos;
    } else if (const auto mult {e->isMult()}) {
        std::vector<Arith::Expr> poly_args;
        std::vector<Bools::Expr> non_poly_pos_args;
        for (const auto &arg: (*mult)->getArgs()) {
            if (arg->isPoly(n)) {
                poly_args.push_back(arg);
            } else {
                non_poly_pos_args.push_back(posConstraint(arg, n));
            }
        }
        const auto poly {arith::mkTimes(std::move(poly_args))};
        const auto non_poly_pos {bools::mkAnd(non_poly_pos_args)};
        const auto poly_pos {posConstraint(getCoefficients(poly, n))};
        return non_poly_pos && poly_pos;
    } else if (const auto add {e->isAdd()}) {
        std::vector<Arith::Expr> poly_args;
        std::vector<Bools::Expr> non_poly_pos_args;
        for (const auto &arg: (*add)->getArgs()) {
            if (arg->isPoly(n)) {
                poly_args.push_back(arg);
            } else {
                non_poly_pos_args.push_back(posConstraint(arg, n));
            }
        }
        const auto poly {arith::mkPlus(std::move(poly_args))};
        const auto non_poly_pos {bools::mkAnd(non_poly_pos_args)};
        const auto coeffs {getCoefficients(poly, n)};
        const auto poly_pos {posConstraint(coeffs)};
        const auto poly_zero {zeroConstraint(coeffs)};
        return non_poly_pos && (poly_pos || poly_zero);
    }
    throw std::logic_error(toString(e) + "is neither a polynoimal, nor an exponential, a product, or a sum");
}

static Bools::Expr negInfConstraint(const Arith::Expr e, const Arith::Var n) {
    if (e->isPoly(n)) {
        return negInfConstraint(getCoefficients(e, n));
    } else if (e->isPow()) {
        return bot();
    } else if (const auto mult {e->isMult()}) {
        // exp * poly: require that exp is a positive constant and poly is decreasing
        std::vector<Arith::Expr> poly_args;
        std::vector<Bools::Expr> non_poly_pos_args;
        for (const auto &arg: (*mult)->getArgs()) {
            if (arg->isPoly(n)) {
                poly_args.push_back(arg);
            } else {
                non_poly_pos_args.push_back(posConstraint(arg, n));
            }
        }
        const auto poly {arith::mkTimes(std::move(poly_args))};
        const auto non_poly_pos {bools::mkAnd(non_poly_pos_args)};
        const auto poly_neg_inf {negInfConstraint(getCoefficients(poly, n))};
        return non_poly_pos && poly_neg_inf;
    } else if (const auto add {e->isAdd()}) {
        // exp + poly: require that exp is a constant and poly is decreasing
        std::vector<Arith::Expr> poly_args;
        std::vector<Bools::Expr> non_poly_const_args;
        for (const auto &arg: (*add)->getArgs()) {
            if (arg->isPoly(n)) {
                poly_args.push_back(arg);
            } else {
                non_poly_const_args.push_back(constConstraint(arg, n));
            }
        }
        const auto poly {arith::mkPlus(std::move(poly_args))};
        const auto non_poly_const {bools::mkAnd(non_poly_const_args)};
        const auto poly_neg_inf {negInfConstraint(getCoefficients(poly, n))};
        return non_poly_const && poly_neg_inf;
    }
    throw std::logic_error(toString(e) + "is neither a polynoimal, nor an exponential, a product, or a sum");
}

static Bools::Expr posInfConstraint(const Arith::Expr e, const Arith::Var n) {
    if (e->isPoly(n)) {
        return posInfConstraint(getCoefficients(e, n));
    } else if (const auto exp {e->isPow()}) {
        // b^e: require that b-1 and e are positive and one of them is increasing
        const auto b {(*exp)->getBase() - arith::mkConst(1)};
        const auto base_pos {posConstraint(b, n)};
        const auto base_pos_inf {posInfConstraint(b, n)};
        const auto exponent_pos {posConstraint((*exp)->getExponent(), n)};
        const auto exponent_pos_inf {posInfConstraint((*exp)->getExponent(), n)};
        return (base_pos || base_pos_inf) && (exponent_pos || exponent_pos_inf) && (base_pos_inf || exponent_pos_inf);
    } else if (const auto mult {e->isMult()}) {
        // exp * poly: require that exp and poly are positive and one of them is increasing
        std::vector<Arith::Expr> poly_args;
        std::vector<Bools::Expr> non_poly_pos_or_inf_args;
        std::vector<Bools::Expr> non_poly_pos_inf_args;
        for (const auto &arg: (*mult)->getArgs()) {
            if (arg->isPoly(n)) {
                poly_args.push_back(arg);
            } else {
                const auto pos {posConstraint(arg, n)};
                const auto pos_inf {posConstraint(arg, n)};
                non_poly_pos_or_inf_args.push_back(pos || pos_inf);
                non_poly_pos_inf_args.push_back(pos_inf);
            }
        }
        const auto poly {arith::mkTimes(std::move(poly_args))};
        const auto coeffs {getCoefficients(poly, n)};
        const auto non_poly_pos_or_inf {bools::mkAnd(non_poly_pos_or_inf_args)};
        const auto non_poly_pos_inf {non_poly_pos_or_inf && bools::mkOr(non_poly_pos_inf_args)};
        const auto poly_pos {posConstraint(coeffs)};
        const auto poly_pos_inf {posInfConstraint(coeffs)};
        return non_poly_pos_or_inf && (poly_pos || poly_pos_inf) && (non_poly_pos_inf || poly_pos_inf);
    } else if (const auto add {e->isAdd()}) {
        // exp + poly: require that exp is increasing, or exp is positive and poly is increasing
        std::vector<Arith::Expr> poly_args;
        std::vector<Bools::Expr> non_poly_const_or_inf_args;
        std::vector<Bools::Expr> non_poly_pos_inf_args;
        for (const auto &arg: (*add)->getArgs()) {
            if (arg->isPoly(n)) {
                poly_args.push_back(arg);
            } else {
                const auto constant {constConstraint(arg, n)};
                const auto pos_inf {posConstraint(arg, n)};
                non_poly_const_or_inf_args.push_back(constant || pos_inf);
                non_poly_pos_inf_args.push_back(pos_inf);
            }
        }
        const auto poly {arith::mkPlus(std::move(poly_args))};
        const auto non_poly_const_or_inf {bools::mkAnd(non_poly_const_or_inf_args)};
        const auto non_poly_pos_inf {non_poly_const_or_inf && bools::mkOr(non_poly_pos_inf_args)};
        const auto poly_pos_inf {posInfConstraint(getCoefficients(poly, n))};
        return (non_poly_const_or_inf && non_poly_pos_inf) || (non_poly_const_or_inf && poly_pos_inf);
    }
    throw std::logic_error(toString(e) + "is neither a polynoimal, nor an exponential, a product, or a sum");
}

std::optional<ArithSubs> LimitSmtEncoding::applyEncoding(const LimitProblem &currentLP, const Arith::Expr cost, Complexity currentRes) {
    // initialize z3
    const auto solver{SmtFactory::modelBuildingSolver(Smt::chooseLogic<std::vector<Arith::Lit>, ArithSubs>({currentLP.getQuery(), {arith::mkGt(cost, arith::mkConst(0))}}, {}))};
    // the parameter of the desired family of solutions
    const auto n{currentLP.getN()};
    // get all relevant variables
    const auto vars{currentLP.getVariables()};
    // create linear templates for all variables
    ArithSubs templateSubs;
    std::map<Arith::Var, Arith::Var> varCoeff, varCoeff0;
    for (const auto &var : vars) {
        const auto c0{ArithVar::next()};
        const auto c{ArithVar::next()};
        varCoeff.emplace(var, c);
        varCoeff0.emplace(var, c0);
        templateSubs.put(var, c0 + (n->toExpr() * c));
    }
    // replace variables in the cost function with their linear templates
    const auto templateCost{templateSubs(cost)};
    // if the cost function is a constant, then we are bound to fail
    if (!templateCost->has(n)) {
        return {};
    }
    // encode every entry of the limit problem
    for (auto it = currentLP.cbegin(); it != currentLP.cend(); ++it) {
        // replace variables with their linear templates
        const auto ex{templateSubs(it->first)};
        const auto direction{it->second};
        // add the required constraints (depending on the direction-label from the limit problem)
        if (direction == POS) {
            solver->add(posConstraint(ex, n) || posInfConstraint(ex, n));
        } else if (direction == POS_CONS) {
            solver->add(posConstraint(ex, n));
        } else if (direction == POS_INF) {
            solver->add(posInfConstraint(ex, n));
        } else if (direction == NEG_CONS) {
            solver->add(negConstraint(ex, n));
        } else if (direction == NEG_INF) {
            solver->add(negInfConstraint(ex, n));
        }
    }
    // remember the current state for backtracking before trying several variations
    solver->push();
    // first fix that all program variables have to be constants
    // a model witnesses unbounded complexity
    for (const auto &var : vars) {
        if (!var->isTempVar()) {
            solver->add(arith::mkEq(varCoeff.at(var), arith::mkConst(0)));
        }
    }
    if (solver->check() != Sat) {
        solver->pop();
        if (const auto d {templateCost->isPoly(n)}) {
            if (Complexity::Poly(*d) <= currentRes) {
                return {};
            }
            // try to find a witness for polynomial complexity with degree maxDeg,...,1
            const auto coefficients{getCoefficients(templateCost, n)};
            for (auto i = *d; i > 0 && Complexity::Poly(i) > currentRes; --i) {
                const auto c{coefficients.at(i)};
                // remember the current state for backtracking
                solver->push();
                solver->add(arith::mkGt(c, arith::mkConst(0)));
                if (solver->check() == Sat) {
                    break;
                } else if (i == 1 || Complexity::Poly(i - 1) <= currentRes) {
                    // we even failed to prove the minimal requested bound -- give up
                    return {};
                } else {
                    // remove all non-mandatory constraints and retry with degree i-1
                    solver->pop();
                }
            }
        } else if (solver->check() != Sat) {
            return {};
        }
    }
    // we found a model -- create the corresponding solution of the limit problem
    ArithSubs smtSubs;
    const auto model{solver->model()};
    for (const auto &var : vars) {
        const auto c0{varCoeff0.at(var)};
        const auto c{model.get<Arith>(varCoeff.at(var))};
        smtSubs.put(var, model.contains<Arith>(c0) ? arith::mkConst(model.get<Arith>(c0) + c) * n : arith::mkConst(c) * n);
    }
    return {smtSubs};
}

Bools::Expr encodeBoolExpr(const Bools::Expr expr, const ArithSubs &templateSubs, const Arith::Var n) {
    BoolExprSet newChildren;
    for (const auto &c : expr->getChildren()) {
        newChildren.insert(encodeBoolExpr(c, templateSubs, n));
    }
    if (expr->isAnd()) {
        return bools::mkAnd(newChildren);
    } else if (expr->isOr()) {
        return bools::mkOr(newChildren);
    } else {
        const auto lit{std::get<ArithLit>(*expr->getTheoryLit())};
        const auto lhs{lit.lhs()};
        const auto ex{templateSubs(lhs)};
        const auto coefficients{getCoefficients(ex, n)};
        if (lit.isGt()) {
            return posConstraint(coefficients) || posInfConstraint(coefficients);
        } else if (lit.isEq()) {
            return zeroConstraint(coefficients);
        } else if (lit.isNeq()) {
            return posConstraint(coefficients) ||
                   posInfConstraint(coefficients) ||
                   negConstraint(coefficients) ||
                   negInfConstraint(coefficients);
        } else {
            throw std::invalid_argument("unexpected relation");
        }
    }
}

std::pair<ArithSubs, Complexity> LimitSmtEncoding::applyEncoding(const Bools::Expr expr, const Arith::Expr cost, Complexity currentRes) {
    // initialize z3
    auto solver{SmtFactory::modelBuildingSolver(Smt::chooseLogic(BoolExprSet{expr, bools::mkLit(arith::mkGt(cost, arith::mkConst(0)))}))};
    // the parameter of the desired family of solutions
    const auto n{ArithVar::next()};
    // get all relevant variables
    auto vars{expr->vars().get<Arith::Var>()};
    cost->collectVars(vars);
    auto hasTmpVars{false};
    // create linear templates for all variables
    ArithSubs templateSubs;
    std::map<Arith::Var, Arith::Var> varCoeff, varCoeff0;
    for (const auto &var : vars) {
        hasTmpVars |= var->isTempVar();
        const auto c0{ArithVar::next()};
        const auto c{ArithVar::next()};
        varCoeff.emplace(var, c);
        varCoeff0.emplace(var, c0);
        templateSubs.put(var, c0 + (n->toExpr() * c));
    }
    // replace variables in the cost function with their linear templates
    const auto templateCost{templateSubs(cost)};
    // if the cost function is a constant, then we are bound to fail
    const auto d{templateCost->isPoly(n)};
    const auto maxPossibleFiniteRes = d ? Complexity::Poly(*d) : Complexity::NestedExp;
    if (maxPossibleFiniteRes == Complexity::Const) {
        return {{}, Complexity::Unknown};
    }
    const auto encoding{encodeBoolExpr(expr, templateSubs, n)};
    solver->add(encoding);
    // auxiliary function that checks satisfiability wrt. the current state of the solver
    auto checkSolver = [&solver] {
        return solver->check() == Sat;
    };
    auto model = [&] {
        ArithSubs smtSubs;
        const auto model{solver->model()};
        for (const auto &var : vars) {
            const auto c0{varCoeff0.at(var)};
            const auto c{model.get<Arith>(varCoeff.at(var))};
            smtSubs.put(var, model.contains<Arith>(c0) ? arith::mkConst(model.get<Arith>(c0) + c) * n : arith::mkConst(c) * n);
        }
        return smtSubs;
    };
    if (hasTmpVars) {
        solver->push();
        solver->add(posInfConstraint(getCoefficients(templateCost, n)));
        // first fix that all program variables have to be constants
        // a model witnesses unbounded complexity
        for (const auto &var : vars) {
            if (!var->isTempVar()) {
                solver->add(arith::mkEq(varCoeff.at(var), arith::mkConst(0)));
            }
        }
        if (checkSolver()) {
            return {model(), Complexity::Unbounded};
        }
        solver->pop();
    }
    if (maxPossibleFiniteRes <= currentRes) {
        return {{}, Complexity::Unknown};
    }
    // we failed to find a model -- drop all non-mandatory constraints
    if (maxPossibleFiniteRes.getType() == Complexity::CpxPolynomial && mp::denominator(maxPossibleFiniteRes.getPolynomialDegree()) == 1) {
        const auto maxPossibleDegree{mp::denominator(maxPossibleFiniteRes.getPolynomialDegree())};
        // try to find a witness for polynomial complexity with degree maxDeg,...,1
        const auto coefficients{getCoefficients(templateCost, n)};
        for (auto i = maxPossibleDegree; i > 0 && Complexity::Poly(i) > currentRes; --i) {
            const auto c{coefficients.find(i)->second};
            // remember the current state for backtracking
            solver->push();
            solver->add(arith::mkGt(c, arith::mkConst(0)));
            if (checkSolver()) {
                return {model(), Complexity::Poly(i)};
            } else {
                // remove all non-mandatory constraints and retry with degree i-1
                solver->pop();
            }
        }
    }
    return {{}, Complexity::Unknown};
}
