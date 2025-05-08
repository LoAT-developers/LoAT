#include "loattransitiontoitsconverter.hpp"

ITSPtr LoatTransitionToITSConverter::convertTransitionsToITS(const std::vector<LoatTransition> &transitions, const LoatLocation &start, const LoatLocation &sink)
{
    // Check if we got at least one transition, a start location and at least one sink location
    if (transitions.empty())
    {
        throw std::invalid_argument("No transitions provided.");
    }

    if (start.getName().empty())
    {
        throw std::invalid_argument("Start location is not set.");
    }

    if (sink.getName().empty())
    {
        throw std::invalid_argument("No sink locations provided.");
    }

    // Create empty ITS
    ITSPtr its = std::make_shared<ITSProblem>();

    // Transfer start location
    LocationIdx startIdx = its->getOrAddLocation(start.getName());
    its->setInitialLocation(startIdx);

    // Transfer sink location
    LocationIdx sinkIdx = its->getOrAddLocation(sink.getName());
    its->setSinkLocation(sinkIdx);

    // Get location var
    Arith::Var locVar = its->getLocVar();

    // Loop through all transitions
    for (const LoatTransition &transition : transitions)
    {
        // Extract start, target and the formula
        const LoatLocation &source = transition.getSourceLocation();
        const LoatLocation &target = transition.getTargetLocation();

        // Convert Rule
        RulePtr rule = convert(transition);

        // Get the index values to the source and target locations
        LocationIdx sourceIdx = its->getOrAddLocation(source.getName());
        LocationIdx targetIdx = its->getOrAddLocation(target.getName());

        // New Guard: locVar == srcIdx && old Guard
        Arith::Expr curLoc = arith::toExpr(locVar);
        Bools::Expr locGuard = bools::mkLit(arith::mkEq(curLoc, arith::mkConst(sourceIdx)));
        BoolExprSet conjuncts;
        conjuncts.insert(rule->getGuard());
        conjuncts.insert(locGuard);
        Bools::Expr combinedGuard = bools::mkAnd(conjuncts);

        // Update loc var after transition
        Subs update = rule->getUpdate();
        update.put<Arith>(locVar, arith::mkConst(targetIdx));

        // Create new rule and insert this into the its
        RulePtr ruleWithLoc = Rule::mk(combinedGuard, update);
        its->addRule(ruleWithLoc, sourceIdx);
    }

    return its;
}

RulePtr LoatTransitionToITSConverter::convert(const LoatTransition &transition)
{
    // Save refrence to formula
    const LoatBoolExprPtr &formula = transition.getFormula();

    // Convert Formula
    Bools::Expr guard = convertBool(formula);

    // Create subs (x = x' etc.)
    Subs subs;
    for (const auto &[key, var] : m_arithVarMap)
    {
        // Check if we have a pre Var
        if (!key.second)
        {
            // Get corrosponding post var
            Arith::Var tempVar = getArithVar(key.first, true);
            subs.put<Arith>(var, Arith::varToExpr(tempVar));
        }
    }
    for (const auto &[key, var] : m_boolVarMap)
    {
        // Check if we have a pre Var
        if (!key.second)
        {
            // Get corrosponding post var
            Bools::Var tempVar = getBoolVar(key.first, true);
            subs.put<Bools>(var, Bools::varToExpr(tempVar));
        }
    }

    // Create the internal its transition/rule
    return Rule::mk(guard, subs);
}

Arith::Expr LoatTransitionToITSConverter::convertArith(const LoatIntExprPtr &expr)
{
    // Search for expression in cache and use it if possible
    auto it = m_arithExprCache.find(expr);
    if (it != m_arithExprCache.end())
    {
        return it->second;
    }

    // Declare result and use it as return variable
    using Kind = LoatIntExpression::Kind;
    Arith::Expr result = arith::mkConst(0);

    // Switch over expr kind
    switch (expr->getKind())
    {
    case Kind::Constant:
    {
        // Cast to subclass
        const auto *c = static_cast<const LoatIntConst *>(expr.get());
        // Set result as internal const expr
        result = arith::mkConst(c->getValue());
        break;
    }
    case Kind::Variable:
    {
        // Cast to subclass
        const auto *v = static_cast<const LoatIntVar *>(expr.get());
        // Set result as internal var expr
        result = arith::toExpr(getArithVar(v->getName(), v->isPost()));
        break;
    }
    case Kind::Plus:
    {

        // Cast to subclass
        const auto *plus = static_cast<const LoatIntAdd *>(expr.get());
        // Local variable to store args
        ArithExprVec args;
        // Iterate over all args
        for (const auto &arg : plus->getArgs())
            // Use caching for all sub expressions directly
            args.push_back(convertArith(arg));
        // Set result as internal plus expr
        result = arith::mkPlus(std::move(args));
        break;
    }
    case Kind::Times:
    {
        // Cast to subclass
        const auto *mult = static_cast<const LoatIntMult *>(expr.get());
        // Local variable to store args
        ArithExprVec args;
        // Iterate over all args
        for (const auto &arg : mult->getArgs())
            // Use caching for all sub expressions directly
            args.push_back(convertArith(arg));
        // Set result as internal times expr
        result = arith::mkTimes(std::move(args));
        break;
    }
    case Kind::Mod:
    {
        // Cast to subclass
        const auto *mod = static_cast<const LoatIntMod *>(expr.get());
        // Set result as internal mod expr
        result = arith::mkMod(convertArith(mod->getLhs()), convertArith(mod->getRhs()));
        break;
    }
    case Kind::Exp:
    {
        // Cast to subclass
        const auto *exp = static_cast<const LoatIntExp *>(expr.get());
        // Set result as internal exp expr
        result = arith::mkExp(convertArith(exp->getBase()), convertArith(exp->getExponent()));
        break;
    }
    default:
    {
        // Default case for unkown kind
        throw std::logic_error("Unknown kind of expression");
    }
    }

    // Store in cache
    m_arithExprCache.emplace(expr, result);
    // Return result
    return result;
}

Bools::Expr LoatTransitionToITSConverter::convertBool(const LoatBoolExprPtr &expr)
{
    // Search for expression in cache and use it if possible
    auto it = m_boolExprCache.find(expr);
    if (it != m_boolExprCache.end())
    {
        return it->second;
    }

    // Declare result and use it as return variable
    using Kind = LoatBoolExpression::Kind;
    Bools::Expr result = Bools::anyValue();

    // Switch over expr kind
    switch (expr->getKind())
    {
    case Kind::Variable:
    {
        // Cast to subclass
        const auto *v = static_cast<const LoatBoolVar *>(expr.get());
        // Set result as internal var expr
        result = Bools::varToExpr(getBoolVar(v->getName(), v->isPost()));
        break;
    }
    case Kind::Not:
    {
        // Cast to subclass
        const auto *n = static_cast<const LoatBoolNot *>(expr.get());
        // Set result !(expr) and use cache for sub expr
        result = !convertBool(n->getArg());
        break;
    }
    case Kind::And:
    {
        // Cast to subclass
        const auto *a = static_cast<const LoatBoolAnd *>(expr.get());
        // Local variable to store args
        BoolExprSet args;
        // Iterate over all args
        for (const auto &arg : a->getArgs())
        {
            // Use caching for all sub expressions directly
            args.insert(convertBool(arg));
        }
        // Set result as internal and junction
        result = bools::mkAnd(args);
        break;
    }
    case Kind::Or:
    {
        // Cast to subclass
        const auto *o = static_cast<const LoatBoolOr *>(expr.get());
        // Local variable to store args
        BoolExprSet args;
        // Iterate over all args
        for (const auto &arg : o->getArgs())
        {
            // Use caching for all sub expressions directly
            args.insert(convertBool(arg));
        }
        // Set result as internal or junction
        result = bools::mkOr(args);
        break;
    }
    case Kind::Compare:
    {
        // Cast to subclass
        const auto *cmp = static_cast<const LoatBoolCmp *>(expr.get());

        // Get both sides of expression
        const auto lhs = convertArith(cmp->getLhs());
        const auto rhs = convertArith(cmp->getRhs());

        // Switch over compare operator ==, !=, >, >=, <, <=
        using Op = LoatBoolExpression::CmpOp;
        switch (cmp->getOp())
        {
        case Op::Eq:
        {
            // Set result as Lit
            result = bools::mkLit(arith::mkEq(lhs, rhs));
            break;
        }
        case Op::Ge:
        {
            // Set result as Lit
            result = bools::mkLit(arith::mkGeq(lhs, rhs));
            break;
        }
        case Op::Gt:
        {
            // Set result as Lit
            result = bools::mkLit(arith::mkGt(lhs, rhs));
            break;
        }
        case Op::Le:
        {
            // Set result as Lit
            result = bools::mkLit(arith::mkLeq(lhs, rhs));
            break;
        }
        case Op::Lt:
        {
            // Set result as Lit
            result = bools::mkLit(arith::mkLt(lhs, rhs));
            break;
        }
        case Op::Neq:
        {
            // Set result as Lit
            result = bools::mkLit(arith::mkNeq(lhs, rhs));
            break;
        }
        default:
        {
            // Default case for unkown operator
            throw std::logic_error("Unknown comparison operator");
        }
        }
        break;
    }
    default:
    {
        // Default case for unkown kind
        throw std::logic_error("Unknown kind of expression");
    }
    }

    // Store in cache
    m_boolExprCache.emplace(expr, result);
    // Return result
    return result;
}

Arith::Var LoatTransitionToITSConverter::getArithVar(const std::string &name, bool isTemp)
{
    // Search for the variable in the map and return it if found
    std::pair<std::string, bool> key = std::make_pair(name, isTemp);
    auto it = m_arithVarMap.find(key);
    if (it != m_arithVarMap.end())
    {
        return it->second;
    }

    Arith::Var var = isTemp ? ArithVar::next() : ArithVar::nextProgVar();
    m_arithVarMap.emplace(key, var);
    return var;
}

Bools::Var LoatTransitionToITSConverter::getBoolVar(const std::string &name, bool isTemp)
{
    // Search for the variable in the map and return it if found
    std::pair<std::string, bool> key = std::make_pair(name, isTemp);
    auto it = m_boolVarMap.find(key);
    if (it != m_boolVarMap.end())
    {
        return it->second;
    }

    Bools::Var var = isTemp ? BoolVar::next() : BoolVar::nextProgVar();
    m_boolVarMap.emplace(key, var);
    return var;
}
