#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <utility>
#include <functional>

#include "loattransition.hpp"
#include "loatboolexpr.hpp"
#include "loatintexpr.hpp"

#include "itsproblem.hpp"
#include "rule.hpp"
#include "arith.hpp"
#include "bools.hpp"
#include "optional.hpp"

template <>
struct std::hash<std::pair<std::string, bool>> {
    std::size_t operator()(const std::pair<std::string, bool> &p) const noexcept {
        return std::hash<std::string>{}(p.first) ^ (std::hash<bool>{}(p.second) << 1);
    }
};

class LoatTransitionToITSConverter {
    // Cache (api bool expr to internal bool Expr)
    std::unordered_map<LoatBoolExprPtr, Bools::Expr> m_boolExprCache;

    // Cache (api int expr to internal int Expr)
    std::unordered_map<LoatIntExprPtr, Arith::Expr> m_arithExprCache;

    // Cache LoAT -> ITS (Pre- and Post-Vars)
    std::unordered_map<std::string, ArithVarPtr> m_arithVarPreMap;
    std::unordered_map<std::string, ArithVarPtr> m_arithVarPostMap;
    std::unordered_set<std::string> m_arithVarsUsed;

    // Cache LoAT -> ITS (Bool Pre- and Post-Vars)
    std::unordered_map<std::string, Bools::Var> m_boolVarPreMap;
    std::unordered_map<std::string, Bools::Var> m_boolVarPostMap;
    std::unordered_set<std::string> m_boolVarsUsed;

public:
    LoatTransitionToITSConverter() = default;

    // Convert transitions to its
    ITSPtr convertTransitionsToITS(const std::vector<LoatTransition> &transitions, const LoatLocation &start, const std::optional<LoatLocation> &sink);

    // Converts a LoatTransition to internal Rule
    RulePtr convert(const LoatTransition &transition);

    // Converts a LoatExpression into internal Expression
    Arith::Expr convertArith(const LoatIntExprPtr &expr);
    Bools::Expr convertBool(const LoatBoolExprPtr &expr);

private:
    ArithVarPtr getArithVar(const std::string &name, bool isPost);
    Bools::Var getBoolVar(const std::string &name, bool isPost);
};