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

    ASSERT_FALSE(rule->getGuard() == BoolExpr::top());
    ASSERT_FALSE(rule->getGuard() == BoolExpr::bot());

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