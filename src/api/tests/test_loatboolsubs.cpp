#include <gtest/gtest.h>
#include "loatboolexpr.hpp"
#include "loatboolsubs.hpp"

TEST(LoatBoolSubsTest, PutAndGet)
{
    auto a = LoatBoolExpression::mkVar("a");
    auto notA = !a;

    LoatBoolSubs subs;
    subs.put(a, notA);

    auto map = subs.getSubsMap();
    ASSERT_EQ(map.size(), 1);
    ASSERT_EQ(map.at(a).get(), notA.get());
}

TEST(LoatBoolSubsTest, StreamOutput)
{
    auto a = LoatBoolExpression::mkVar("a");
    auto notA = !a;

    LoatBoolSubs subs;
    subs.put(a, notA);

    std::stringstream ss;
    ss << subs;

    std::string output = ss.str();
    EXPECT_EQ(output, "{a := (!a)}");
}

TEST(LoatBoolSubsTest, MultipleSubstitutions)
{
    auto a = LoatBoolExpression::mkVar("a");
    auto b = LoatBoolExpression::mkVar("b");
    auto orExpr = a || b;

    LoatBoolSubs subs;
    subs.put(a, b);
    subs.put(b, orExpr);

    std::stringstream ss;
    ss << subs;
    std::string output = ss.str();

    EXPECT_NE(output.find("a := b"), std::string::npos);
    EXPECT_NE(output.find("b := (a || b)"), std::string::npos);
}
TEST(LoatBoolSubsTest, PutThrowsOnNonVariableLHS)
{
    auto a = LoatBoolExpression::mkVar("a");
    auto notA = !a;

    LoatBoolSubs subs;

    EXPECT_THROW(subs.put(notA, a), std::invalid_argument);
}