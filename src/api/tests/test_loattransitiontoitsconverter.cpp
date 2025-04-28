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
    auto x_post = LoatIntExpression::mkVar("x'");
    auto y_post = LoatIntExpression::mkVar("y'");

    auto cmp1 = LoatBoolExpression::mkLt(x, LoatIntExpression::mkConst(5));
    auto cmp2 = LoatBoolExpression::mkGe(y, x);

    auto eq_x = LoatBoolExpression::mkEq(x_post, x);
    auto eq_y = LoatBoolExpression::mkEq(y_post, y);

    auto formula = LoatBoolExpression::mkAnd({cmp1, cmp2, eq_x, eq_y});

    LoatLocation source("q1");
    LoatLocation target("q2");

    LoatTransition transition(source, target, formula);

    auto rule = converter.convert(transition);

    ASSERT_FALSE(rule->getGuard() == BoolExpr::top());
    ASSERT_FALSE(rule->getGuard() == BoolExpr::bot());

    const auto &subs1 = rule->getUpdate();
    EXPECT_EQ(subs1.size(), 2);

    const auto &domain = subs1.domain();
    EXPECT_TRUE(domain.contains(converter.getArithVar("x'")));
    EXPECT_TRUE(domain.contains(converter.getArithVar("y'")));

    auto lhs_x_post = converter.getArithVar("x'");
    auto expected_x_expr = arith::toExpr(converter.getArithVar("x"));

    auto variant_expr_x = subs1.get(lhs_x_post);
    ASSERT_TRUE(std::holds_alternative<ArithExprPtr>(variant_expr_x));
    EXPECT_EQ(std::get<ArithExprPtr>(variant_expr_x), expected_x_expr);

    auto lhs_y_post = converter.getArithVar("y'");
    auto expected_y_expr = arith::toExpr(converter.getArithVar("y"));

    auto variant_expr_y = subs1.get(lhs_y_post);
    ASSERT_TRUE(std::holds_alternative<ArithExprPtr>(variant_expr_y));
    EXPECT_EQ(std::get<ArithExprPtr>(variant_expr_y), expected_y_expr);

    auto rule2 = converter.convert(transition);

    EXPECT_EQ(rule->getGuard(), rule2->getGuard());

    EXPECT_EQ(rule->getUpdate(), rule2->getUpdate());
}

TEST(LoatTransitionToITSConverterTest, GuardOnlyNoUpdates)
{
    LoatTransitionToITSConverter converter;

    auto x = LoatIntExpression::mkVar("x");
    auto y = LoatIntExpression::mkVar("y");

    auto cmp = LoatBoolExpression::mkLt(x, y);

    LoatLocation source("q1");
    LoatLocation target("q2");

    LoatTransition transition(source, target, cmp);

    auto rule = converter.convert(transition);

    ASSERT_FALSE(rule->getGuard() == BoolExpr::top());
    ASSERT_FALSE(rule->getGuard() == BoolExpr::bot());

    const auto &subs = rule->getUpdate();
    EXPECT_EQ(subs.size(), 0);

    EXPECT_TRUE(subs.domain().empty());
}

TEST(LoatTransitionToITSConverterTest, ComplexArithUpdate)
{
    LoatTransitionToITSConverter converter;

    auto x = LoatIntExpression::mkVar("x");
    auto y = LoatIntExpression::mkVar("y");
    auto z = LoatIntExpression::mkVar("z");
    auto x_post = LoatIntExpression::mkVar("x'");

    auto new_expr = LoatIntExpression::mkPlus({x, LoatIntExpression::mkTimes({y, LoatIntExpression::mkConst(3)})});

    auto eq_x = LoatBoolExpression::mkEq(x_post, new_expr);

    LoatLocation source("q0");
    LoatLocation target("q1");
    LoatTransition transition(source, target, eq_x);

    auto rule = converter.convert(transition);

    ASSERT_TRUE(rule->getGuard() == BoolExpr::top());

    const auto &subs = rule->getUpdate();
    EXPECT_EQ(subs.size(), 1);

    auto lhs = converter.getArithVar("x'");
    auto variant_expr = subs.get(lhs);
    ASSERT_TRUE(std::holds_alternative<ArithExprPtr>(variant_expr));

    auto expr = std::get<ArithExprPtr>(variant_expr);

    auto expected = arith::mkPlus({arith::toExpr(converter.getArithVar("x")),
                                   arith::mkTimes({arith::toExpr(converter.getArithVar("y")),
                                                   arith::mkConst(3)})});

    EXPECT_EQ(expr, expected);
}

TEST(LoatTransitionToITSConverterTest, MultiplePostVarSubstitutions)
{
    auto x = LoatIntExpression::mkVar("x");
    auto y = LoatIntExpression::mkVar("y");
    auto z = LoatIntExpression::mkVar("z");

    auto x_post = LoatIntExpression::mkVar("x'");
    auto y_post = LoatIntExpression::mkVar("y'");
    auto z_post = LoatIntExpression::mkVar("z'");

    auto update_x = LoatBoolExpression::mkEq(x_post, LoatIntExpression::mkPlus({x, LoatIntExpression::mkConst(1)}));
    auto update_y = LoatBoolExpression::mkEq(y_post, LoatIntExpression::mkTimes({y, LoatIntExpression::mkConst(2)}));
    auto update_z = LoatBoolExpression::mkEq(z_post, LoatIntExpression::mkPlus({z, LoatIntExpression::mkConst(-3)}));

    auto formula = LoatBoolExpression::mkAnd({update_x, update_y, update_z});

    LoatLocation source("q0");
    LoatLocation target("q1");

    LoatTransition transition(source, target, formula);

    LoatTransitionToITSConverter converter;

    auto rule = converter.convert(transition);

    EXPECT_EQ(rule->getGuard(), BoolExpr::top());

    auto subs = rule->getUpdate();
    EXPECT_EQ(subs.size(), 3);

    auto lhs_x = converter.getArithVar("x'");
    auto lhs_y = converter.getArithVar("y'");
    auto lhs_z = converter.getArithVar("z'");

    auto var_x = converter.getArithVar("x");
    auto var_y = converter.getArithVar("y");
    auto var_z = converter.getArithVar("z");

    {
        auto variant_expr = subs.get(lhs_x);
        ASSERT_TRUE(std::holds_alternative<ArithExprPtr>(variant_expr));
        auto expr = std::get<ArithExprPtr>(variant_expr);

        auto expected = arith::mkPlus({arith::toExpr(var_x), arith::mkConst(1)});
        EXPECT_EQ(expr, expected);
    }

    {
        auto variant_expr = subs.get(lhs_y);
        ASSERT_TRUE(std::holds_alternative<ArithExprPtr>(variant_expr));
        auto expr = std::get<ArithExprPtr>(variant_expr);

        auto expected = arith::mkTimes({arith::toExpr(var_y), arith::mkConst(2)});
        EXPECT_EQ(expr, expected);
    }
    {
        auto variant_expr = subs.get(lhs_z);
        ASSERT_TRUE(std::holds_alternative<ArithExprPtr>(variant_expr));
        auto expr = std::get<ArithExprPtr>(variant_expr);

        auto expected = arith::mkPlus({arith::toExpr(var_z), arith::mkConst(-3)});
        EXPECT_EQ(expr, expected);
    }
}

TEST(LoatTransitionToITSConverterTest, ComplexUpdateWithGuard)
{
    LoatTransitionToITSConverter converter;

    auto x = LoatIntExpression::mkVar("x");
    auto y = LoatIntExpression::mkVar("y");
    auto x_post = LoatIntExpression::mkVar("x'");

    auto update_expr = LoatIntExpression::mkPlus({x,
                                                  LoatIntExpression::mkTimes({y, LoatIntExpression::mkConst(2)})});
    auto update_x = LoatBoolExpression::mkEq(x_post, update_expr);

    auto guard_expr = LoatBoolExpression::mkLt(x, LoatIntExpression::mkConst(10));

    auto formula = LoatBoolExpression::mkAnd({guard_expr, update_x});

    LoatLocation source("q0");
    LoatLocation target("q1");
    LoatTransition transition(source, target, formula);

    auto rule = converter.convert(transition);

    ASSERT_FALSE(rule->getGuard() == BoolExpr::top());
    ASSERT_FALSE(rule->getGuard() == BoolExpr::bot());

    auto subs = rule->getUpdate();
    EXPECT_EQ(subs.size(), 1);

    auto lhs_x = converter.getArithVar("x'");
    auto var_x = converter.getArithVar("x");
    auto var_y = converter.getArithVar("y");

    {
        auto variant_expr = subs.get(lhs_x);
        ASSERT_TRUE(std::holds_alternative<ArithExprPtr>(variant_expr));
        auto expr = std::get<ArithExprPtr>(variant_expr);

        auto expected = arith::mkPlus({arith::toExpr(var_x),
                                       arith::mkTimes({arith::toExpr(var_y), arith::mkConst(2)})});
        EXPECT_EQ(expr, expected);
    }
}

TEST(LoatTransitionToITSConverterTest, ComplexGuardWithOrAnd)
{
    LoatTransitionToITSConverter converter;

    auto x = LoatIntExpression::mkVar("x");
    auto y = LoatIntExpression::mkVar("y");
    auto z = LoatIntExpression::mkVar("z");

    auto cmp1 = LoatBoolExpression::mkLt(x, LoatIntExpression::mkConst(5));
    auto cmp2 = LoatBoolExpression::mkGt(y, LoatIntExpression::mkConst(2));
    auto cmp3 = LoatBoolExpression::mkEq(z, LoatIntExpression::mkConst(0));

    auto and_part = LoatBoolExpression::mkAnd({cmp1, cmp2});
    auto or_guard = LoatBoolExpression::mkOr({and_part, cmp3});

    LoatLocation source("q0");
    LoatLocation target("q1");

    LoatTransition transition(source, target, or_guard);

    auto rule = converter.convert(transition);

    ASSERT_FALSE(rule->getGuard() == BoolExpr::top());
    ASSERT_FALSE(rule->getGuard() == BoolExpr::bot());

    const auto &subs = rule->getUpdate();
    EXPECT_EQ(subs.size(), 0);
    EXPECT_TRUE(subs.domain().empty());
}

TEST(LoatTransitionToITSConverterTest, MultiplePostUpdatesWithGuard)
{
    LoatTransitionToITSConverter converter;

    auto x = LoatIntExpression::mkVar("x");
    auto y = LoatIntExpression::mkVar("y");
    auto z = LoatIntExpression::mkVar("z");

    auto x_post = LoatIntExpression::mkVar("x'");
    auto y_post = LoatIntExpression::mkVar("y'");

    auto update_x = LoatBoolExpression::mkEq(x_post, LoatIntExpression::mkPlus({x, LoatIntExpression::mkConst(1)}));
    auto update_y = LoatBoolExpression::mkEq(y_post, LoatIntExpression::mkTimes({y, LoatIntExpression::mkConst(2)}));

    auto guard_cmp = LoatBoolExpression::mkLt(z, LoatIntExpression::mkConst(10));

    auto formula = LoatBoolExpression::mkAnd({update_x, update_y, guard_cmp});

    LoatLocation source("q0");
    LoatLocation target("q1");
    LoatTransition transition(source, target, formula);

    auto rule = converter.convert(transition);

    ASSERT_FALSE(rule->getGuard() == BoolExpr::top());
    ASSERT_FALSE(rule->getGuard() == BoolExpr::bot());

    auto subs = rule->getUpdate();
    EXPECT_EQ(subs.size(), 2);

    auto lhs_x = converter.getArithVar("x'");
    auto lhs_y = converter.getArithVar("y'");

    auto variant_x = subs.get(lhs_x);
    auto variant_y = subs.get(lhs_y);

    ASSERT_TRUE(std::holds_alternative<ArithExprPtr>(variant_x));
    ASSERT_TRUE(std::holds_alternative<ArithExprPtr>(variant_y));

    auto expected_x = arith::mkPlus({arith::toExpr(converter.getArithVar("x")),
                                     arith::mkConst(1)});
    auto expected_y = arith::mkTimes({arith::toExpr(converter.getArithVar("y")),
                                      arith::mkConst(2)});

    EXPECT_EQ(std::get<ArithExprPtr>(variant_x), expected_x);
    EXPECT_EQ(std::get<ArithExprPtr>(variant_y), expected_y);
}

TEST(LoatTransitionToITSConverterTest, RedundantIdentityUpdate)
{
    LoatTransitionToITSConverter converter;

    auto x = LoatIntExpression::mkVar("x");
    auto x_post = LoatIntExpression::mkVar("x'");

    auto identity_update = LoatBoolExpression::mkEq(x_post, x);

    LoatLocation source("q0");
    LoatLocation target("q1");
    LoatTransition transition(source, target, identity_update);

    auto rule = converter.convert(transition);

    EXPECT_EQ(rule->getGuard(), BoolExpr::top());

    auto subs = rule->getUpdate();
    EXPECT_EQ(subs.size(), 1);

    auto lhs = converter.getArithVar("x'");
    auto variant = subs.get(lhs);

    ASSERT_TRUE(std::holds_alternative<ArithExprPtr>(variant));

    auto expected_expr = arith::toExpr(converter.getArithVar("x"));
    EXPECT_EQ(std::get<ArithExprPtr>(variant), expected_expr);
}