#include "loattransitiontoitsconverter.hpp"

RulePtr LoatTransitionToITSConverter::convert(const LoatTransition &transition)
{
    // Save refrence to formula
    const LoatBoolExprPtr &formula = transition.getFormula();

    // Convert Formula
    Bools::Expr guard = convertBool(formula);

    // Create subs (x = x' etc.)
    Subs subs;
    for (const auto &[name, var] : m_arithVarMap)
    {
        // Check if we have a pre Var
        if (!name.empty() && name.back() != '\'')
        {
            // Get corrosponding post var
            Arith::Var tempVar = getArithVar(name + "\'");
            subs.put<Arith>(var, Arith::varToExpr(tempVar));
        }
    }
    for (const auto &[name, var] : m_boolVarMap)
    {
        // Check if we have a pre Var
        if (!name.empty() && name.back() != '\'')
        {
            // Get corrosponding post var
            Bools::Var tempVar = getBoolVar(name + "\'");
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
        result = arith::toExpr(getArithVar(v->getName()));
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
        result = Bools::varToExpr(getBoolVar(v->getName()));
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

Arith::Var LoatTransitionToITSConverter::getArithVar(const std::string &name)
{

    // Search for the variable in the map and return it if found
    auto it = m_arithVarMap.find(name);
    if (it != m_arithVarMap.end())
    {
        return it->second;
    }

    // If not found create Prog var or temp var depending on if we have a pre or post var
    if (!name.empty() && name.back() == '\'')
    {
        // Post var -> Temp Var
        Arith::Var var = ArithVar::next();
        m_arithVarMap.emplace(name, var);
        return var;
    }
    else
    {
        // Pre var -> Prog Var
        Arith::Var var = ArithVar::nextProgVar();
        m_arithVarMap.emplace(name, var);
        return var;
    }
}

Bools::Var LoatTransitionToITSConverter::getBoolVar(const std::string &name)
{
    // Search for the variable in the map and return it if found
    auto it = m_boolVarMap.find(name);
    if (it != m_boolVarMap.end())
    {
        return it->second;
    }

    // If not found create Prog var or temp var depending on if we have a pre or post var
    if (!name.empty() && name.back() == '\'')
    {
        // Post var -> Temp Var
        Bools::Var var = BoolVar::next();
        m_boolVarMap.emplace(name, var);
        return var;
    }
    else
    {
        // Pre var -> Prog Var
        Bools::Var var = BoolVar::nextProgVar();
        m_boolVarMap.emplace(name, var);
        return var;
    }
}
