#include <gtest/gtest.h>
#include <sstream>
#include "loatboolexpr.hpp"
#include "loatexpression.hpp"

using namespace LoatBoolExpression;

TEST(LoatBoolExprTest, CreateVariableAndOutput)
{
    auto x = mkVar("flag");
    EXPECT_EQ(x->getKind(), Kind::Variable);

    std::stringstream ss;
    ss << x;
    EXPECT_EQ(ss.str(), "flag");
}

TEST(LoatBoolExprTest, CreateComparisonExpressions)
{
    auto x = LoatExpression::mkVar("x");
    auto y = LoatExpression::mkVar("y");
    auto three = LoatExpression::mkConst(3);
    auto five = LoatExpression::mkConst(5);

    auto cmp1 = x < y;
    auto cmp2 = three >= five;

    EXPECT_EQ(cmp1->getKind(), Kind::Compare);
    EXPECT_EQ(cmp2->getKind(), Kind::Compare);

    std::stringstream ss;
    ss << cmp1;
    EXPECT_EQ(ss.str(), "(x < y)");
}

TEST(LoatBoolExprTest, BuildAndOrNotExpressions)
{
    auto x = LoatExpression::mkVar("x");
    auto y = LoatExpression::mkVar("y");
    auto z = LoatExpression::mkVar("z");

    auto c1 = x == y;
    auto c2 = y <= z;

    auto andExpr = mkAnd({c1, c2});
    auto orExpr = mkOr({andExpr, mkNot(c1)});

    EXPECT_EQ(andExpr->getKind(), Kind::And);
    EXPECT_EQ(orExpr->getKind(), Kind::Or);

    std::stringstream ss;
    ss << orExpr;
    EXPECT_EQ(ss.str(), "(((x == y) && (y <= z)) || (!(x == y)))");
}

TEST(LoatBoolExprTest, OperatorOverloadsWork)
{
    auto a = LoatExpression::mkVar("a");
    auto b = LoatExpression::mkVar("b");
    auto c = LoatExpression::mkVar("c");

    auto expr = (a < b) && (b != c) || !(a >= c);

    std::stringstream ss;
    ss << expr;
    EXPECT_EQ(ss.str(), "(((a < b) && (b != c)) || (!(a >= c)))");
}

TEST(LoatBoolExprTest, CachingAndEquality)
{
    auto x = LoatExpression::mkVar("x");
    auto y = LoatExpression::mkVar("y");

    auto expr1 = x < y;
    auto expr2 = mkLt(x, y);

    EXPECT_EQ(expr1, expr2);
}