#include <gtest/gtest.h>
#include <sstream>
#include "loatexpression.hpp"

using namespace LoatExpression;

TEST(LoatConstTest, CreateAndCompare)
{
    auto c1 = mkConst(5);
    auto c2 = mkConst(Rational(5));
    auto c3 = mkConst(Rational(3));

    EXPECT_EQ(c1, c2);
    EXPECT_NE(c1, c3);
    EXPECT_EQ(c1->getKind(), Kind::Constant);
}

TEST(LoatConstTest, PrintConst)
{
    auto c = mkConst(42);
    std::stringstream ss;
    ss << c;
    EXPECT_EQ(ss.str(), "42");
}

TEST(LoatAddTest, CreateSimpleAddition)
{
    auto a = mkConst(1);
    auto b = mkConst(2);
    auto sum = mkPlus(a, b);

    EXPECT_EQ(sum->getKind(), Kind::Plus);

    std::stringstream ss;
    ss << sum;
    EXPECT_EQ(ss.str(), "(1 + 2)");
}

TEST(LoatAddTest, NestedAddition)
{
    auto a = mkConst(1);
    auto b = mkConst(2);
    auto inner = mkPlus(a, b);
    auto c = mkConst(3);
    auto outer = mkPlus(inner, c);

    std::stringstream ss;
    ss << outer;
    EXPECT_EQ(ss.str(), "((1 + 2) + 3)");
}

TEST(LoatAddTest, AddMultiple)
{
    auto x = mkConst(1);
    auto y = mkConst(2);
    auto z = mkConst(3);

    auto sum = mkPlus({x, y, z});

    std::stringstream ss;
    ss << sum;
    EXPECT_EQ(ss.str(), "(1 + 2 + 3)");
}