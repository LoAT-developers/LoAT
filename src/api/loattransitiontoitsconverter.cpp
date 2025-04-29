#include "loattransitiontoitsconverter.hpp"

RulePtr LoatTransitionToITSConverter::convert(const LoatTransition &transition)
{
    // Save refrence to formula
    const LoatBoolExprPtr &formula = transition.getFormula();

    // Convert Formula
    Bools::Expr guard = convertBool(formula);

    // Create arith subs (x = x' etc.)
    Arith::Subs arithSubs;
    for (const auto &[name, preVar] : m_preVarMap)
    {

        auto it = m_postVarMap.find(name);
        if (it != m_postVarMap.end())
        {
            arithSubs.put(it->second, Arith::varToExpr(preVar));
        }
    }

    // Create bool subs (x = x' etc.)
    Bools::Subs boolSubs;
    for (const auto &[name, preVar] : m_boolPreVarMap)
    {
        auto it = m_boolPostVarMap.find(name);
        if (it != m_boolPostVarMap.end())
        {
            boolSubs.put(it->second, Bools::varToExpr(preVar));
        }
    }

    // Create the internal its transition/rule
    return Rule::mk(guard, Subs::build<Arith>(arithSubs).unite(Subs::build<Bools>(boolSubs)));
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

    // Store name of var
    std::string base = name;

    // Check if variable is a post var
    bool isPost = false;
    if (!name.empty() && name.back() == '\'')
    {
        base.pop_back();
        isPost = true;
    }

    // Get the correct map refrences
    auto &map = isPost ? m_postVarMap : m_preVarMap;
    auto &otherMap = isPost ? m_preVarMap : m_postVarMap;

    // Search for the variable in the map and return it if found
    auto it = map.find(base);
    if (it != map.end())
    {
        return it->second;
    }

    // Create next Prog Var and add variable base name (without ') to the correct map
    Arith::Var var = ArithVar::nextProgVar();
    map.emplace(base, var);

    // Add to other map if not present
    if (otherMap.find(base) == otherMap.end())
    {
        otherMap.emplace(base, ArithVar::nextProgVar());
    }

    return var;
}

Bools::Var LoatTransitionToITSConverter::getBoolVar(const std::string &name)
{
    // Store name of var
    std::string base = name;

    // Check if variable is a post var
    bool isPost = false;
    if (!name.empty() && name.back() == '\'')
    {
        base.pop_back();
        isPost = true;
    }

    // Get the correct map refrences
    auto &map = isPost ? m_boolPostVarMap : m_boolPreVarMap;
    auto &otherMap = isPost ? m_boolPreVarMap : m_boolPostVarMap;

    // Search for the variable in the map and return it if found
    auto it = map.find(base);
    if (it != map.end())
    {
        return it->second;
    }

    // Create next Prog Var and add variable base name (without ') to the correct map
    Bools::Var var = BoolVar::nextProgVar();
    map.emplace(base, var);

    // Add to other map if not present
    if (otherMap.find(base) == otherMap.end())
    {
        otherMap.emplace(base, BoolVar::nextProgVar());
    }

    return var;
}
