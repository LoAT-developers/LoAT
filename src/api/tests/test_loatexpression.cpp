#include <gtest/gtest.h>
#include <sstream>
#include "loatexpression.hpp"

using namespace LoatExpression;

// CONST
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

// ADD
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

TEST(LoatMultTest, CreateSimpleMultiplication)
{
    auto a = mkConst(4);
    auto b = mkConst(5);
    auto product = mkTimes(a, b);

    EXPECT_EQ(product->getKind(), Kind::Times);

    std::stringstream ss;
    ss << product;
    EXPECT_EQ(ss.str(), "(4 * 5)");
}

// MULT
TEST(LoatMultTest, MultiplyMultiple)
{
    auto x = mkConst(2);
    auto y = mkConst(3);
    auto z = mkConst(4);

    auto prod = mkTimes({x, y, z});

    std::stringstream ss;
    ss << prod;
    EXPECT_EQ(ss.str(), "(2 * 3 * 4)");
}

// MOD
TEST(LoatModTest, SimpleMod)
{
    auto x = mkConst(10);
    auto y = mkConst(3);
    auto mod = mkMod(x, y);

    EXPECT_EQ(mod->getKind(), Kind::Mod);

    std::stringstream ss;
    ss << mod;
    EXPECT_EQ(ss.str(), "(10 % 3)");
}

// EXP
TEST(LoatExpTest, PowerExpression)
{
    auto base = mkConst(2);
    auto exp = mkConst(3);
    auto result = mkExp(base, exp);

    std::stringstream ss;
    ss << result;
    EXPECT_EQ(ss.str(), "(2 ^ 3)");
}

// VAR
TEST(LoatVarTest, MkVarCreatesValidVariable)
{
    auto v = mkVar(5);
    EXPECT_EQ(v->getKind(), Kind::Variable);
}

TEST(LoatVarTest, MkVarThrowsOnNegativeIndex)
{
    EXPECT_THROW({ mkVar(-3); }, std::invalid_argument);
}

TEST(LoatVarTest, VarOutputsCorrectly)
{
    auto v = mkVar(2);

    EXPECT_EQ(v->getKind(), Kind::Variable);

    std::stringstream ss;
    ss << v;
    EXPECT_EQ(ss.str(), "b2");
}

TEST(LoatExpressionTest, BuildExpressionWithConstAndVar)
{
    auto x = mkVar(1);
    auto c1 = mkConst(3);
    auto c2 = mkConst(7);

    auto mul = mkTimes(c1, x);
    auto sum = mkPlus(mul, c2);

    EXPECT_EQ(sum->getKind(), Kind::Plus);

    std::stringstream ss;
    ss << sum;

    EXPECT_EQ(ss.str(), "((3 * b1) + 7)");
}

// OPERATOR
TEST(LoatOperatorTest, PlusOperator)
{
    auto x = mkConst(3);
    auto y = mkConst(4);
    auto result = x + y;

    EXPECT_EQ(result->getKind(), Kind::Plus);
}

TEST(LoatOperatorTest, MinusOperator)
{
    auto x = mkConst(10);
    auto y = mkConst(3);
    auto result = x - y;

    std::stringstream ss;
    ss << result;
    EXPECT_EQ(ss.str(), "(10 + (-1 * 3))");
}

TEST(LoatOperatorTest, UnaryMinusOperator)
{
    auto x = mkConst(7);
    auto neg = -x;

    std::stringstream ss;
    ss << neg;
    EXPECT_EQ(ss.str(), "(-1 * 7)");
}

TEST(LoatOperatorTest, TimesOperator)
{
    auto x = mkConst(2);
    auto y = mkConst(3);
    auto result = x * y;

    std::stringstream ss;
    ss << result;
    EXPECT_EQ(ss.str(), "(2 * 3)");
}

TEST(LoatOperatorTest, PowerOperator)
{
    auto base = mkConst(2);
    auto exp = mkConst(5);
    auto result = base ^ exp;

    EXPECT_EQ(result->getKind(), Kind::Exp);

    std::stringstream ss;
    ss << result;
    EXPECT_EQ(ss.str(), "(2 ^ 5)");
}

TEST(LoatOperatorTest, DivideMethod)
{
    auto expr = mkConst(10);
    Rational r(5);
    auto div = expr->divide(r);

    std::stringstream ss;
    ss << div;
    EXPECT_EQ(ss.str(), "(1/5 * 10)");
}