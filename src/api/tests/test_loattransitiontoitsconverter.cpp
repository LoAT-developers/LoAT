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

    EXPECT_EQ(subs.size(), 2);
}

TEST(LoatTransitionToITSConverterTest, SingleTransitionToITS)
{
    // Construct a transition q0(x) -> q1(x')[x < 5]
    LoatLocation q0("q0"), q1("q1");
    auto x = LoatIntExpression::mkPreVar("x");
    auto five = LoatIntExpression::mkConst(5);
    auto guard = LoatBoolExpression::mkLt(x, five);
    LoatTransition transition(q0, q1, guard);

    // Convert the transition into an ITS with start = q0, sink = q1
    LoatTransitionToITSConverter converter;
    ITSPtr its = converter.convertTransitionsToITS({transition}, q0, q1);

    // Verify that initial location and sink are set correctly
    auto initialIdx = its->getLocationIdx("q0");
    auto sinkIdx = its->getLocationIdx("q1");
    ASSERT_TRUE(initialIdx.has_value());
    ASSERT_TRUE(sinkIdx.has_value());
    EXPECT_EQ(its->getInitialLocation(), initialIdx.value());
    EXPECT_EQ(its->getSink(), sinkIdx.value());

    // There is exactly one Rule in the ITS
    const auto &all = its->getAllTransitions();
    ASSERT_EQ(all.size(), 1u);

    // Get iterator and extract first element of it as my rule ptr
    RulePtr rule = *all.begin();

    // Guard is not bot or top
    Bools::Expr g = rule->getGuard();
    EXPECT_FALSE(g == BoolExpr::top());
    EXPECT_FALSE(g == BoolExpr::bot());

    // Update must contain two substitutions: x := x' and locVar := startIdx
    const auto &update = rule->getUpdate();
    EXPECT_EQ(update.size(), 2u);

    // Check that the location variable appears in the update
    Arith::Var locVar = its->getLocVar();
    EXPECT_TRUE(update.contains(locVar));
}