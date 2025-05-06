#pragma once

#include <unordered_map>
#include <string>
#include <stdexcept>
#include <utility>
#include <functional>

#include "loattransition.hpp"
#include "loatboolexpr.hpp"
#include "loatintexpr.hpp"

#include "rule.hpp"
#include "arith.hpp"
#include "bools.hpp"

namespace std
{
    template <>
    struct hash<std::pair<std::string, bool>>
    {
        std::size_t operator()(const std::pair<std::string, bool> &p) const
        {
            return std::hash<std::string>{}(p.first) ^ (std::hash<bool>{}(p.second) << 1);
        }
    };
}

class LoatTransitionToITSConverter
{
private:
    // Cache (api bool expr to internal bool Expr)
    std::unordered_map<LoatBoolExprPtr, Bools::Expr> m_boolExprCache;

    // Cache (api int expr to internal int Expr)
    std::unordered_map<LoatIntExprPtr, Arith::Expr> m_arithExprCache;

    // Cache LoAT -> ITS (Pre- and Post-Vars)
    std::unordered_map<std::pair<std::string, bool>, Arith::Var> m_arithVarMap;

    // Cache LoAT -> ITS (Bool Pre- and Post-Vars)
    std::unordered_map<std::pair<std::string, bool>, Bools::Var> m_boolVarMap;

public:
    LoatTransitionToITSConverter() = default;

    // Converts a LoatTransition to internal Rule
    RulePtr convert(const LoatTransition &transition);

    // Converts a LoatExpression into internal Expression
    Arith::Expr convertArith(const LoatIntExprPtr &expr);
    Bools::Expr convertBool(const LoatBoolExprPtr &expr);

    Arith::Var getArithVar(const std::string &name, bool isTemp);
    Bools::Var getBoolVar(const std::string &name, bool isTemp);
};