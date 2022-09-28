#include "limitsmt.hpp"

#include "smt.hpp"
#include "smtfactory.hpp"
#include "inftyexpression.hpp"
#include "config.hpp"

using namespace std;


/**
 * Given the (abstract) coefficients of a univariate polynomial p in n (where the key is the
 * degree of the respective monomial), builds an expression which implies that
 * lim_{n->\infty} p is a positive constant
 */
static BoolExpr posConstraint(const map<int, Expr>& coefficients) {
    std::vector<Rel> conjunction;
    for (pair<int, Expr> p : coefficients) {
        int degree = p.first;
        Expr c = p.second;
        if (degree > 0) {
            conjunction.push_back(Rel::buildEq(c, 0));
        } else {
            conjunction.push_back(c > 0);
        }
    }
    return buildAnd(conjunction);
}

/**
 * Given the (abstract) coefficients of a univariate polynomial p in n (where the key is the
 * degree of the respective monomial), builds an expression which implies that
 * lim_{n->\infty} p is a negative constant
 */
static BoolExpr negConstraint(const map<int, Expr>& coefficients) {
    std::vector<Rel> conjunction;
    for (pair<int, Expr> p : coefficients) {
        int degree = p.first;
        Expr c = p.second;
        if (degree > 0) {
            conjunction.push_back(Rel::buildEq(c, 0));
        } else {
            conjunction.push_back(c < 0);
        }
    }
    return buildAnd(conjunction);
}

/**
 * Given the (abstract) coefficients of a univariate polynomial p in n (where the key is the
 * degree of the respective monomial), builds an expression which implies
 * lim_{n->\infty} p = -\infty
 */
static BoolExpr negInfConstraint(const map<int, Expr>& coefficients) {
    int maxDegree = 0;
    for (pair<int, Expr> p: coefficients) {
        maxDegree = p.first > maxDegree ? p.first : maxDegree;
    }
    std::vector<BoolExpr> disjunction;
    for (int i = 1; i <= maxDegree; i++) {
        std::vector<Rel> conjunction;
        for (pair<int, Expr> p: coefficients) {
            int degree = p.first;
            Expr c = p.second;
            if (degree > i) {
                conjunction.push_back(Rel::buildEq(c, 0));
            } else if (degree == i) {
                conjunction.push_back(c < 0);
            }
        }
        disjunction.push_back(buildAnd(conjunction));
    }
    return buildOr(disjunction);
}

/**
 * Given the (abstract) coefficients of a univariate polynomial p in n (where the key is the
 * degree of the respective monomial), builds an expression which implies
 * lim_{n->\infty} p = \infty
 */
static BoolExpr posInfConstraint(const map<int, Expr>& coefficients) {
    int maxDegree = 0;
    for (pair<int, Expr> p: coefficients) {
        maxDegree = p.first > maxDegree ? p.first : maxDegree;
    }
    std::vector<BoolExpr> disjunction;
    for (int i = 1; i <= maxDegree; i++) {
        std::vector<Rel> conjunction;
        for (pair<int, Expr> p: coefficients) {
            int degree = p.first;
            Expr c = p.second;
            if (degree > i) {
                conjunction.push_back(Rel::buildEq(c, 0));
            } else if (degree == i) {
                conjunction.push_back(c > 0);
            }
        }
        disjunction.push_back(buildAnd(conjunction));
    }
    return buildOr(disjunction);
}

/**
 * @return the (abstract) coefficients of 'n' in 'ex', where the key is the degree of the respective monomial
 */
static map<int, Expr> getCoefficients(const Expr &ex, const Var &n) {
    int maxDegree = ex.degree(n);
    map<int, Expr> coefficients;
    for (int i = 0; i <= maxDegree; i++) {
        coefficients.emplace(i, ex.coeff(n, i));
    }
    return coefficients;
}

option<ExprSubs> LimitSmtEncoding::applyEncoding(const LimitProblem &currentLP, const Expr &cost,
                                                     VarMan &varMan, Complexity currentRes, unsigned int timeout)
{
    // initialize z3
    unique_ptr<Smt> solver = SmtFactory::modelBuildingSolver(Smt::chooseLogic<std::vector<Rel>, ExprSubs>({currentLP.getQuery(), {cost > 0}}, {}), varMan, timeout);

    // the parameter of the desired family of solutions
    Var n = currentLP.getN();

    // get all relevant variables
    VarSet vars = currentLP.getVariables();

    // create linear templates for all variables
    Subs templateSubs;
    VarMap<Var> varCoeff, varCoeff0;
    for (const Var &var : vars) {
        Var c0 = varMan.getFreshUntrackedSymbol(var.get_name() + "_0", Expr::Int);
        Var c = varMan.getFreshUntrackedSymbol(var.get_name() + "_c", Expr::Int);
        varCoeff.emplace(var, c);
        varCoeff0.emplace(var, c0);
        templateSubs.put(var, c0 + (n * c));
    }

    // replace variables in the cost function with their linear templates
    Expr templateCost = templateSubs(cost).expand();

    // if the cost function is a constant, then we are bound to fail
    Complexity maxPossibleFiniteRes = templateCost.isPoly() ?
            Complexity::Poly(templateCost.degree(n)) :
            Complexity::NestedExp;
    if (maxPossibleFiniteRes == Complexity::Const) {
        return {};
    }

    // encode every entry of the limit problem
    for (auto it = currentLP.cbegin(); it != currentLP.cend(); ++it) {
        // replace variables with their linear templates
        Expr ex = templateSubs(*it).expand();
        map<int, Expr> coefficients = getCoefficients(ex, n);
        Direction direction = it->getDirection();
        // add the required constraints (depending on the direction-label from the limit problem)
        if (direction == POS) {
            BoolExpr disjunction = posConstraint(coefficients) | posInfConstraint(coefficients);
            solver->add(disjunction);
        } else if (direction == POS_CONS) {
            solver->add(posConstraint(coefficients));
        } else if (direction == POS_INF) {
            solver->add(posInfConstraint(coefficients));
        } else if (direction == NEG_CONS) {
            solver->add(negConstraint(coefficients));
        } else if (direction == NEG_INF) {
            solver->add(negInfConstraint(coefficients));
        }
    }

    // auxiliary function that checks satisfiability wrt. the current state of the solver
    auto checkSolver = [&]() -> bool {
        Smt::Result res = solver->check();
        return res == Smt::Sat;
    };

    // remember the current state for backtracking before trying several variations
    solver->push();

    // first fix that all program variables have to be constants
    // a model witnesses unbounded complexity
    for (const Var &var : vars) {
        if (!varMan.isTempVar(var)) {
            solver->add(Rel::buildEq(varCoeff.at(var), 0));
        }
    }

    if (!checkSolver()) {
        if (maxPossibleFiniteRes <= currentRes) {
            return {};
        }
        // we failed to find a model -- drop all non-mandatory constraints
        solver->pop();
        if (maxPossibleFiniteRes.getType() == Complexity::CpxPolynomial && maxPossibleFiniteRes.getPolynomialDegree().isInteger()) {
            int maxPossibleDegree = maxPossibleFiniteRes.getPolynomialDegree().asInteger();
            // try to find a witness for polynomial complexity with degree maxDeg,...,1
            map<int, Expr> coefficients = getCoefficients(templateCost, n);
            for (int i = maxPossibleDegree; i > 0 && Complexity::Poly(i) > currentRes; i--) {
                Expr c = coefficients.find(i)->second;
                // remember the current state for backtracking
                solver->push();
                solver->add(c > 0);
                if (checkSolver()) {
                    break;
                } else if (i == 1 || Complexity::Poly(i - 1) <= currentRes) {
                    // we even failed to prove the minimal requested bound -- give up
                    return {};
                } else {
                    // remove all non-mandatory constraints and retry with degree i-1
                    solver->pop();
                }
            }
        } else if (!checkSolver()) {
            return {};
        }
    }

    // we found a model -- create the corresponding solution of the limit problem
    ExprSubs smtSubs;
    Model model = solver->model();
    for (const Var &var : vars) {
        Var c0 = varCoeff0.at(var);
        Expr c = model.get(varCoeff.at(var));
        smtSubs.put(var, c0 == model.contains(c0) ? (model.get(c0) + c * n) : (c * n));
    }

    return {smtSubs};
}

BoolExpr encodeBoolExpr(const BoolExpr expr, const Subs &templateSubs, const Var &n) {
    BoolExprSet newChildren;
    for (const BoolExpr &c: expr->getChildren()) {
        newChildren.insert(encodeBoolExpr(c, templateSubs, n));
    }
    if (expr->isAnd()) {
        return buildAnd(newChildren);
    } else if (expr->isOr()) {
        return buildOr(newChildren);
    } else {
        option<Rel> lit = expr->getTheoryLit();
        assert(lit);
        assert(lit->isGZeroConstraint());
        const auto &lhs = lit->isStrict() ? lit->lhs() : lit->lhs() + 1;
        Expr ex = templateSubs(lhs).expand();
        map<int, Expr> coefficients = getCoefficients(ex, n);
        return posConstraint(coefficients) | posInfConstraint(coefficients);
    }
}

std::pair<ExprSubs, Complexity> LimitSmtEncoding::applyEncoding(const BoolExpr expr, const Expr &cost,
                                                     VarMan &varMan, Complexity currentRes, unsigned int timeout)
{
    // initialize z3
    unique_ptr<Smt> solver = SmtFactory::modelBuildingSolver(Smt::chooseLogic(BoolExprSet{expr, buildTheoryLit(cost > 0)}), varMan, timeout);

    // the parameter of the desired family of solutions
    Var n = varMan.getFreshUntrackedSymbol("n", Expr::Int);

    // get all relevant variables
    VarSet vars;
    expr->collectVars(vars);
    cost.collectVars(vars);
    bool hasTmpVars = false;

    // create linear templates for all variables
    Subs templateSubs;
    VarMap<Var> varCoeff, varCoeff0;
    for (const Var &var : vars) {
        hasTmpVars |= varMan.isTempVar(var);
        Var c0 = varMan.getFreshUntrackedSymbol(var.get_name() + "_0", Expr::Int);
        Var c = varMan.getFreshUntrackedSymbol(var.get_name() + "_c", Expr::Int);
        varCoeff.emplace(var, c);
        varCoeff0.emplace(var, c0);
        templateSubs.put(var, c0 + (n * c));
    }

    // replace variables in the cost function with their linear templates
    Expr templateCost = templateSubs(cost).expand();

    // if the cost function is a constant, then we are bound to fail
    Complexity maxPossibleFiniteRes = templateCost.isPoly() ?
            Complexity::Poly(templateCost.degree(n)) :
            Complexity::NestedExp;
    if (maxPossibleFiniteRes == Complexity::Const) {
        return {{}, Complexity::Unknown};
    }

    const BoolExpr normalized = expr->toG();
    const BoolExpr encoding = encodeBoolExpr(normalized, templateSubs, n);
    solver->add(encoding);

    // auxiliary function that checks satisfiability wrt. the current state of the solver
    auto checkSolver = [&]() -> bool {
        Smt::Result res = solver->check();
        return res == Smt::Sat;
    };

    auto model = [&]() {
        ExprSubs smtSubs;
        Model model = solver->model();
        for (const Var &var : vars) {
            Var c0 = varCoeff0.at(var);
            Expr c = model.get(varCoeff.at(var));
            smtSubs.put(var, model.contains(c0) ? (model.get(c0) + c * n) : (c * n));
        }
        return smtSubs;
    };

    if (hasTmpVars) {
        solver->push();
        solver->add(posInfConstraint(getCoefficients(templateCost, n)));
        // first fix that all program variables have to be constants
        // a model witnesses unbounded complexity
        for (const Var &var : vars) {
            if (!varMan.isTempVar(var)) {
                solver->add(Rel::buildEq(varCoeff.at(var), 0));
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
    if (maxPossibleFiniteRes.getType() == Complexity::CpxPolynomial && maxPossibleFiniteRes.getPolynomialDegree().isInteger()) {
        int maxPossibleDegree = maxPossibleFiniteRes.getPolynomialDegree().asInteger();
        // try to find a witness for polynomial complexity with degree maxDeg,...,1
        map<int, Expr> coefficients = getCoefficients(templateCost, n);
        for (int i = maxPossibleDegree; i > 0 && Complexity::Poly(i) > currentRes; i--) {
            Expr c = coefficients.find(i)->second;
            // remember the current state for backtracking
            solver->push();
            solver->add(c > 0);
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
