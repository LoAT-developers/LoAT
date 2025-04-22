#include <gtest/gtest.h>
#include "loatsolver.hpp"
#include "loattransition.hpp"
#include "loatboolexpr.hpp"
#include "loatintexpr.hpp"

TEST(LoatTransitionTest, ValidTransitionWithPreAndPostVars)
{
    auto x = LoatIntExpression::mkVar("x");
    auto y = LoatIntExpression::mkVar("y");
    auto x_post = LoatIntExpression::mkVar("x'");
    auto y_post = LoatIntExpression::mkVar("y'");

    auto formula = (x_post == x + LoatIntExpression::mkConst(1)) &&
                   (y_post == y - LoatIntExpression::mkConst(1));

    LoatLocation source("q1");
    LoatLocation target("q2");

    LoatTransition t(source, target, formula);

    EXPECT_EQ(t.getSourceLocation(), source);
    EXPECT_EQ(t.getTargetLocation(), target);
    EXPECT_EQ(t.getFormula(), formula);

    std::stringstream ss;
    ss << t;
    std::string output = ss.str();

    EXPECT_NE(output.find("q1 -> q2"), std::string::npos);
    EXPECT_NE(output.find("x'"), std::string::npos);
    EXPECT_NE(output.find("y'"), std::string::npos);
}