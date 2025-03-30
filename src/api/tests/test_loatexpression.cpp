#include <gtest/gtest.h>
#include "loatexpression.hpp"

// === Test: makeConst ===
TEST(LoatExpressionTest, CreateConstant)
{
    auto five = makeConst(5);
    EXPECT_EQ(five->getKind(), LoatKind::Constant);
    EXPECT_EQ(five->toString(), "5");
}

// === Test: makePlus ===
TEST(LoatExpressionTest, CreatePlus)
{
    auto a = makeConst(2);
    auto b = makeConst(3);
    auto sum = makePlus(a, b);

    EXPECT_EQ(sum->getKind(), LoatKind::Plus);
    EXPECT_EQ(sum->toString(), "(2 + 3)");
}

// === Test: Caching (Structural Sharing) ===
TEST(LoatExpressionTest, ReusesCachedExpressions)
{
    auto c1 = makeConst(42);
    auto c2 = makeConst(42);

    // Expect same pointer (ConsHash used)
    EXPECT_EQ(c1.get(), c2.get());

    auto a = makeConst(1);
    auto b = makeConst(2);
    auto plus1 = makePlus(a, b);
    auto plus2 = makePlus(a, b);

    EXPECT_EQ(plus1.get(), plus2.get()); // same instance via ConsHash
}

// === Test: To string ===
TEST(LoatExpressionTest, NestedExpressionToString)
{
    auto a = makeConst(1);
    auto b = makeConst(2);
    auto sum = makePlus(a, b);    // (1 + 2)
    auto expr = makePlus(sum, a); // ((1 + 2) + 1)

    EXPECT_EQ(expr->toString(), "((1 + 2) + 1)");
}