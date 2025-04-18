#include <gtest/gtest.h>
#include "loatsubs.hpp"

TEST(LoatSubsTest, PutAndRetrieve)
{
    LoatSubs subs;

    auto x = LoatIntExpression::mkVar("x");
    auto y = LoatIntExpression::mkVar("y");
    auto one = LoatIntExpression::mkConst(1);
    auto expr1 = x + one;

    auto a = LoatBoolExpression::mkVar("a");
    auto b = LoatBoolExpression::mkVar("b");
    auto expr2 = !(a || b);

    subs.put(x, expr1);
    subs.put(a, expr2);

    auto intMap = subs.getIntSubs().getSubsMap();
    auto boolMap = subs.getBoolSubs().getSubsMap();

    ASSERT_EQ(intMap.size(), 1);
    ASSERT_EQ(boolMap.size(), 1);
    EXPECT_EQ(intMap.at(x).get(), expr1.get());
    EXPECT_EQ(boolMap.at(a).get(), expr2.get());
}

TEST(LoatSubsTest, StreamOutput)
{
    LoatSubs subs;

    auto x = LoatIntExpression::mkVar("x");
    auto expr = x + LoatIntExpression::mkConst(3);

    auto a = LoatBoolExpression::mkVar("a");
    auto bexpr = !a;

    subs.put(x, expr);
    subs.put(a, bexpr);

    std::stringstream ss;
    ss << subs;
    std::string out = ss.str();

    EXPECT_NE(out.find("x := (x + 3)"), std::string::npos);
    EXPECT_NE(out.find("a := (!a)"), std::string::npos);
}

TEST(LoatSubsTest, EmptySubstitution)
{
    LoatSubs subs;
    EXPECT_TRUE(subs.getIntSubs().getSubsMap().empty());
    EXPECT_TRUE(subs.getBoolSubs().getSubsMap().empty());
}

TEST(LoatSubsTest, MultipleInsertions)
{
    LoatSubs subs;

    for (int i = 0; i < 10; ++i)
    {
        auto name = "x" + std::to_string(i);
        auto var = LoatIntExpression::mkVar(name);
        auto expr = var + LoatIntExpression::mkConst(i);
        subs.put(var, expr);
    }

    for (int i = 0; i < 5; ++i)
    {
        auto name = "b" + std::to_string(i);
        auto var = LoatBoolExpression::mkVar(name);
        auto expr = !var;
        subs.put(var, expr);
    }

    EXPECT_EQ(subs.getIntSubs().getSubsMap().size(), 10);
    EXPECT_EQ(subs.getBoolSubs().getSubsMap().size(), 5);
}