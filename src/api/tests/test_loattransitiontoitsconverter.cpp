#include "gtest/gtest.h"

#include "loattransitiontoitsconverter.hpp"
#include "loatboolexpr.hpp"
#include "loatintexpr.hpp"
#include "bools.hpp"
#include "arith.hpp"

TEST(LoatTransitionToITSConverterTest, FullConversionTest)
{
    LoatTransitionToITSConverter converter;

    auto x = LoatIntExpression::mkVar("x");
    auto y = LoatIntExpression::mkVar("y");

    auto cmp1 = LoatBoolExpression::mkLt(x, LoatIntExpression::mkConst(5));
    auto cmp2 = LoatBoolExpression::mkGe(y, x);

    auto formula = LoatBoolExpression::mkAnd({cmp1, cmp2});
    LoatTransition transition(LoatLocation("q0"), LoatLocation("q1"), formula);

    auto rule = converter.convert(transition);

    ASSERT_FALSE(rule->getGuard() == BoolExpr::top());
    ASSERT_FALSE(rule->getGuard() == BoolExpr::bot());

    const auto &subs = rule->getUpdate();
    EXPECT_EQ(subs.size(), 2);

    auto x_pre = converter.getArithVar("x");
    auto x_post = converter.getArithVar("x'");
    auto y_pre = converter.getArithVar("y");
    auto y_post = converter.getArithVar("y'");

    EXPECT_EQ(std::get<ArithExprPtr>(subs.get(x_post)), arith::toExpr(x_pre));
    EXPECT_EQ(std::get<ArithExprPtr>(subs.get(y_post)), arith::toExpr(y_pre));
}

TEST(LoatTransitionToITSConverterTest, GuardOnlyTest)
{
    LoatTransitionToITSConverter converter;

    auto x = LoatIntExpression::mkVar("x");
    auto y = LoatIntExpression::mkVar("y");

    auto cmp = LoatBoolExpression::mkLt(x, y);
    LoatTransition transition(LoatLocation("q0"), LoatLocation("q1"), cmp);

    auto rule = converter.convert(transition);

    ASSERT_FALSE(rule->getGuard() == BoolExpr::top());
    ASSERT_FALSE(rule->getGuard() == BoolExpr::bot());

    const auto &subs = rule->getUpdate();
    EXPECT_EQ(subs.size(), 2);

    auto x_pre = converter.getArithVar("x");
    auto x_post = converter.getArithVar("x'");
    auto y_pre = converter.getArithVar("y");
    auto y_post = converter.getArithVar("y'");

    EXPECT_EQ(std::get<ArithExprPtr>(subs.get(x_post)), arith::toExpr(x_pre));
    EXPECT_EQ(std::get<ArithExprPtr>(subs.get(y_post)), arith::toExpr(y_pre));
}

TEST(LoatTransitionToITSConverterTest, ComplexGuardTest)
{
    LoatTransitionToITSConverter converter;

    auto x = LoatIntExpression::mkVar("x");
    auto y = LoatIntExpression::mkVar("y");
    auto z = LoatIntExpression::mkVar("z");

    auto cmp1 = LoatBoolExpression::mkLt(x, LoatIntExpression::mkConst(5));
    auto cmp2 = LoatBoolExpression::mkGt(y, LoatIntExpression::mkConst(3));
    auto cmp3 = LoatBoolExpression::mkEq(z, LoatIntExpression::mkConst(0));

    auto and_part = LoatBoolExpression::mkAnd({cmp1, cmp2});
    auto or_guard = LoatBoolExpression::mkOr({and_part, cmp3});

    LoatTransition transition(LoatLocation("q0"), LoatLocation("q1"), or_guard);

    auto rule = converter.convert(transition);

    ASSERT_FALSE(rule->getGuard() == BoolExpr::top());
    ASSERT_FALSE(rule->getGuard() == BoolExpr::bot());

    const auto &subs = rule->getUpdate();
    EXPECT_EQ(subs.size(), 3);

    auto x_post = converter.getArithVar("x'");
    auto y_post = converter.getArithVar("y'");
    auto z_post = converter.getArithVar("z'");

    EXPECT_TRUE(subs.domain().contains(x_post));
    EXPECT_TRUE(subs.domain().contains(y_post));
    EXPECT_TRUE(subs.domain().contains(z_post));
}

TEST(LoatTransitionToITSConverterTest, MultipleTransitionsTest)
{
    LoatTransitionToITSConverter converter;

    auto x = LoatIntExpression::mkVar("x");
    auto y = LoatIntExpression::mkVar("y");

    auto guard1 = LoatBoolExpression::mkLt(x, LoatIntExpression::mkConst(5));
    LoatTransition transition1(LoatLocation("q0"), LoatLocation("q1"), guard1);

    auto guard2 = LoatBoolExpression::mkGe(y, LoatIntExpression::mkConst(2));
    LoatTransition transition2(LoatLocation("q1"), LoatLocation("q2"), guard2);

    auto rule1 = converter.convert(transition1);
    auto rule2 = converter.convert(transition2);

    ASSERT_FALSE(rule1->getGuard() == BoolExpr::top());
    ASSERT_FALSE(rule2->getGuard() == BoolExpr::top());

    const auto &subs1 = rule1->getUpdate();
    const auto &subs2 = rule2->getUpdate();

    EXPECT_TRUE(subs1.domain().contains(converter.getArithVar("x'")));
    EXPECT_TRUE(subs2.domain().contains(converter.getArithVar("y'")));
}