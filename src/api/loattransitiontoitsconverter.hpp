#pragma once

#include <unordered_map>
#include <string>
#include <stdexcept>

#include "loattransition.hpp"
#include "loatboolexpr.hpp"
#include "loatintexpr.hpp"

#include "rule.hpp"
#include "arith.hpp"
#include "bools.hpp"

class LoatTransitionToITSConverter
{
private:
    // Cache (api bool expr to internal bool Expr)
    std::unordered_map<LoatBoolExprPtr, Bools::Expr> m_boolExprCache;

    // Cache (api int expr to internal int Expr)
    std::unordered_map<LoatIntExprPtr, ArithExprPtr> m_arithExprCache;

    // Cache LoAT -> ITS (Pre- and Post-Vars)
    std::unordered_map<std::string, ArithVarPtr> m_preVarMap;
    std::unordered_map<std::string, ArithVarPtr> m_postVarMap;

    // Cache LoAT -> ITS (Bool vars)
    std::unordered_map<std::string, BoolVarPtr> m_boolVarMap;

    std::vector<std::pair<ArithVarPtr, ArithExprPtr>> m_extractedSubstitutions;

public:
    LoatTransitionToITSConverter() = default;

    // Converts a LoatTransition to internal Rule
    RulePtr convert(const LoatTransition &transition);

    ArithExprPtr convertArith(const LoatIntExprPtr &expr);
    Bools::Expr convertBool(const LoatBoolExprPtr &expr);

    ArithVarPtr getArithVar(const std::string &name);
    BoolVarPtr getBoolVar(const std::string &name);
};