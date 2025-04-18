#include <gtest/gtest.h>
#include "loatintexpr.hpp"
#include "loatintsubs.hpp"

TEST(LoatIntSubsTest, PutAndGet)
{
    auto x = LoatIntExpression::mkVar("x");
    auto y = LoatIntExpression::mkVar("y");
    auto expr = x + LoatIntExpression::mkConst(1);

    LoatIntSubs subs;
    subs.put(x, expr);

    auto map = subs.getSubsMap();
    ASSERT_EQ(map.size(), 1);
    ASSERT_EQ(map.at(x), expr);
}

TEST(LoatIntSubsTest, StreamOutput)
{
    auto x = LoatIntExpression::mkVar("x");
    auto expr = x + LoatIntExpression::mkConst(3);

    LoatIntSubs subs;
    subs.put(x, expr);

    std::stringstream ss;
    ss << subs;

    std::string output = ss.str();
    EXPECT_EQ(output, "{x := (x + 3)}");
}

TEST(LoatIntSubsTest, MultipleSubstitutions)
{
    auto x = LoatIntExpression::mkVar("x");
    auto y = LoatIntExpression::mkVar("y");
    auto z = LoatIntExpression::mkVar("z");

    auto expr1 = x + LoatIntExpression::mkConst(1);
    auto expr2 = y * LoatIntExpression::mkConst(2);

    LoatIntSubs subs;
    subs.put(x, expr1);
    subs.put(y, expr2);

    auto map = subs.getSubsMap();
    ASSERT_EQ(map.size(), 2);
    ASSERT_EQ(map.at(x), expr1);
    ASSERT_EQ(map.at(y), expr2);

    std::stringstream ss;
    ss << subs;

    std::string output = ss.str();
    EXPECT_NE(output.find("x := (x + 1)"), std::string::npos);
    EXPECT_NE(output.find("y := (y * 2)"), std::string::npos);
}

TEST(LoatIntSubsTest, PutThrowsOnNonVariableLHS)
{
    auto x = LoatIntExpression::mkVar("x");
    auto expr = x + LoatIntExpression::mkConst(1);

    LoatIntSubs subs;

    EXPECT_THROW(subs.put(expr, x), std::invalid_argument);
}