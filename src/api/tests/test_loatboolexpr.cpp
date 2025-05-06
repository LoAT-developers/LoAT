#include <gtest/gtest.h>
#include <sstream>
#include "loatboolexpr.hpp"
#include "loatintexpr.hpp"

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
    auto x = LoatIntExpression::mkPreVar("x");
    auto y = LoatIntExpression::mkPreVar("y");
    auto three = LoatIntExpression::mkConst(3);
    auto five = LoatIntExpression::mkConst(5);

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
    auto x = LoatIntExpression::mkPreVar("x");
    auto y = LoatIntExpression::mkPreVar("y");
    auto z = LoatIntExpression::mkPreVar("z");

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
    auto a = LoatIntExpression::mkPreVar("a");
    auto b = LoatIntExpression::mkPreVar("b");
    auto c = LoatIntExpression::mkPreVar("c");

    auto expr = (a < b) && (b != c) || !(a >= c);

    std::stringstream ss;
    ss << expr;
    EXPECT_EQ(ss.str(), "(((a < b) && (b != c)) || (!(a >= c)))");
}

TEST(LoatBoolExprTest, CachingAndEquality)
{
    auto x = LoatIntExpression::mkPreVar("x");
    auto y = LoatIntExpression::mkPreVar("y");

    auto expr1 = x < y;
    auto expr2 = mkLt(x, y);

    EXPECT_EQ(expr1, expr2);
}

TEST(LoatBoolExprTest, SimpleJuction)
{
    auto x = mkVar("x");
    auto y = mkVar("y");

    auto expr1 = x && x;
    auto expr2 = x && y;

    std::stringstream s1;
    s1 << expr1;
    EXPECT_EQ(s1.str(), "(x && x)");

    std::stringstream s2;
    s2 << expr2;
    EXPECT_EQ(s2.str(), "(x && y)");

    auto expr3 = x || x;
    auto expr4 = x || y;

    std::stringstream s3;
    s3 << expr3;
    EXPECT_EQ(s3.str(), "(x || x)");

    std::stringstream s4;
    s4 << expr4;
    EXPECT_EQ(s4.str(), "(x || y)");
}

TEST(LoatBoolExprTest, ChainJunctions)
{
    auto x = mkVar("x");
    auto y = mkVar("y");
    auto z = mkVar("z");

    auto andExpr = x && y && z;
    std::stringstream s1;
    s1 << andExpr;
    EXPECT_EQ(s1.str(), "((x && y) && z)");

    auto orExpr = x || y || z;
    std::stringstream s2;
    s2 << orExpr;
    EXPECT_EQ(s2.str(), "((x || y) || z)");

    auto mixedExpr1 = (x && y) || z;
    auto mixedExpr2 = x && (y || z);

    std::stringstream s3;
    s3 << mixedExpr1;
    EXPECT_EQ(s3.str(), "((x && y) || z)");

    std::stringstream s4;
    s4 << mixedExpr2;
    EXPECT_EQ(s4.str(), "(x && (y || z))");
}