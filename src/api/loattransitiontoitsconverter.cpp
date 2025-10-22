#include "loattransitiontoitsconverter.hpp"

ITSPtr LoatTransitionToITSConverter::convertTransitionsToITS(const std::vector<LoatTransition> &transitions, const LoatLocation &start, const std::optional<LoatLocation> &sink)
{
    // Create empty ITS
    auto its = std::make_shared<ITSProblem>();

    // Transfer start location
    LocationIdx startIdx = its->getOrAddLocation(start.getName());
    its->setInitialLocation(startIdx);

    // Transfer sink location
    if (sink)
    {
        LocationIdx sinkIdx = its->getOrAddLocation(sink.value().getName());
        its->setSinkLocation(sinkIdx);
    }

    // Get location var
    ArithVarPtr locVar = its->getLocVar();

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
        Arith::Expr curLoc = locVar;
        Bools::Expr locGuard = bools::mkLit(arith::mkEq(curLoc, arith::mkConst(sourceIdx)));
        BoolExprSet conjuncts;
        conjuncts.insert(rule->getGuard());
        conjuncts.insert(locGuard);
        Bools::Expr combinedGuard = bools::mkAnd(conjuncts);

        // Update loc var after transition
        Subs update = rule->getUpdate();
        update.update(locVar, arith::mkConst(targetIdx));

        // Create new rule and insert this into the ITS
        RulePtr ruleWithLoc = Rule::mk(combinedGuard, update);
        its->addRule(ruleWithLoc, sourceIdx);
    }

    return its;
}

RulePtr LoatTransitionToITSConverter::convert(const LoatTransition &transition)
{
    // Clear used variables of last transitions
    m_arithVarsUsed.clear();
    m_boolVarsUsed.clear();

    // Save refrence to formula
    const LoatBoolExprPtr &formula = transition.getFormula();

    // Convert Formula
    const Bools::Expr guard = convertBool(formula);

    // Create subs (x = x' etc.)
    Subs subs;
    for (const auto& name : m_arithVarsUsed)
    {
        const ArithVarPtr pre = getArithVar(name, false);
        const ArithVarPtr post = getArithVar(name, true);
        subs.update(pre, post);
    }
    for (const auto& name : m_boolVarsUsed)
    {
        Bools::Var pre = getBoolVar(name, false);
        Bools::Var post = getBoolVar(name, true);
        subs.put(pre, Bools::varToExpr(post));
    }

    // Create the internal its transition/rule
    return Rule::mk(guard, subs);
}

Arith::Expr LoatTransitionToITSConverter::convertArith(const LoatIntExprPtr &expr)
{
    // Search for expression in cache and use it if possible
    if (const auto it = m_arithExprCache.find(expr); it != m_arithExprCache.end()) {
        return it->second;
    }

    // Declare result and use it as return variable
    using Kind = LoatIntExpression::Kind;
    Arith::Expr result = arith::zero;

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

        // Get Var
        const ArithVarPtr var = getArithVar(v->getName(), v->isPost());

        // Add Var to used map
        m_arithVarsUsed.emplace(v->getName());

        // Set result as internal var expr
        result = var;
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
    if (const auto it = m_boolExprCache.find(expr); it != m_boolExprCache.end()) {
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

        // Get Var
        const Bools::Var var = getBoolVar(v->getName(), v->isPost());

        // Add Var to used map
        m_boolVarsUsed.emplace(v->getName());

        // Set result as internal var expr
        result = Bools::varToExpr(var);
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

ArithVarPtr LoatTransitionToITSConverter::getArithVar(const std::string &name, const bool isPost)
{
    if (isPost) {
        if (const auto it = m_arithVarPostMap.find(name); it != m_arithVarPostMap.end()) {
            return it->second;
        }
        ArithVarPtr postVar = arrays::nextConst<Arith>();
        m_arithVarPostMap.emplace(name, postVar);
        return postVar;
    }
    if (const auto it = m_arithVarPreMap.find(name); it != m_arithVarPreMap.end()) {
        return it->second;
    }
    ArithVarPtr preVar = arrays::nextProgConst<Arith>();
    m_arithVarPreMap.emplace(name, preVar);
    return preVar;
}

Bools::Var LoatTransitionToITSConverter::getBoolVar(const std::string &name, const bool isPost)
{
    if (isPost) {
        if (const auto it = m_boolVarPostMap.find(name); it != m_boolVarPostMap.end()) {
            return it->second;
        }
        Bools::Var postVar = BoolVar::next();
        m_boolVarPostMap.emplace(name, postVar);
        return postVar;
    }
    if (const auto it = m_boolVarPreMap.find(name); it != m_boolVarPreMap.end()) {
        return it->second;
    }
    Bools::Var preVar = BoolVar::nextProgVar();
    m_boolVarPreMap.emplace(name, preVar);
    return preVar;
}
