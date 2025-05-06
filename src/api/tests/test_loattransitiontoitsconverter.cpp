#include <gtest/gtest.h>
#include "loattransitiontoitsconverter.hpp"
#include "loatboolexpr.hpp"
#include "loatintexpr.hpp"
#include "bools.hpp"
#include "arith.hpp"

TEST(LoatTransitionToITSConverterTest, FullConversionTest)
{
    LoatTransitionToITSConverter converter;

    auto x = LoatIntExpression::mkPreVar("x");
    auto y = LoatIntExpression::mkPreVar("y");

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

    EXPECT_EQ(std::get<ArithExprPtr>(subs.get(x_pre)), arith::toExpr(x_post));
    EXPECT_EQ(std::get<ArithExprPtr>(subs.get(y_pre)), arith::toExpr(y_post));
}

TEST(LoatTransitionToITSConverterTest, GuardOnlyTest)
{
    LoatTransitionToITSConverter converter;

    auto x = LoatIntExpression::mkPreVar("x");
    auto y = LoatIntExpression::mkPreVar("y");

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

    EXPECT_EQ(std::get<ArithExprPtr>(subs.get(x_pre)), arith::toExpr(x_post));
    EXPECT_EQ(std::get<ArithExprPtr>(subs.get(y_pre)), arith::toExpr(y_post));
}

TEST(LoatTransitionToITSConverterTest, ComplexGuardTest)
{
    LoatTransitionToITSConverter converter;

    auto x = LoatIntExpression::mkPreVar("x");
    auto y = LoatIntExpression::mkPreVar("y");
    auto z = LoatIntExpression::mkPreVar("z");

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
}

TEST(LoatTransitionToITSConverterTest, MultipleTransitionsTest)
{
    LoatTransitionToITSConverter converter;

    auto x = LoatIntExpression::mkPreVar("x");
    auto y = LoatIntExpression::mkPreVar("y");

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
}

TEST(LoatTransitionToITSConverterTest, BoolVarConversionTest)
{
    LoatTransitionToITSConverter converter;

    auto x = LoatBoolExpression::mkPreVar("x");
    auto y = LoatBoolExpression::mkPreVar("y");

    auto formula = LoatBoolExpression::mkAnd({x, LoatBoolExpression::mkNot(y)});
    LoatTransition transition(LoatLocation("q0"), LoatLocation("q1"), formula);

    auto rule = converter.convert(transition);
    const auto &subs = rule->getUpdate();

    auto x_pre = converter.getBoolVar("x");
    auto x_post = converter.getBoolVar("x'");
    auto y_pre = converter.getBoolVar("y");
    auto y_post = converter.getBoolVar("y'");

    EXPECT_EQ(std::get<Bools::Expr>(subs.get(x_pre)), Bools::varToExpr(x_post));
    EXPECT_EQ(std::get<Bools::Expr>(subs.get(y_pre)), Bools::varToExpr(y_post));
}