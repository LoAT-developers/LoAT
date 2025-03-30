#include <gtest/gtest.h>
#include "loatsolver.hpp"
#include "loatconfig.hpp"
#include "config.hpp"
#include "test_util.hpp"
#include "loatexpression.hpp"

// === Tests ===

TEST(LoatSolverTest, AppliesConfigOnConstruction)
{
    LoatConfig::DynamicConfig dyn;
    dyn.set(DynamicParameterKey::Log, true);

    LoatConfig config(createSampleInitialConfig(), dyn);
    LoatSolver solver(config);

    // Should be applied globally
    EXPECT_TRUE(Config::Analysis::log);
}

TEST(LoatSolverTest, SetParameterWorksCorrectly)
{
    LoatConfig initial = createSampleInitialConfig();
    LoatConfig config(initial);
    LoatSolver solver(config);

    // Default should be false
    bool before = std::any_cast<bool>(
        solver.getConfig().getDynamic().get(DynamicParameterKey::BlockingClauses));
    EXPECT_FALSE(before);

    // Set via solver interface
    solver.setParameter(DynamicParameterKey::BlockingClauses, true);

    bool after = std::any_cast<bool>(
        solver.getConfig().getDynamic().get(DynamicParameterKey::BlockingClauses));
    EXPECT_TRUE(after);
}

TEST(LoatSolverTest, SetParameterThrowsOnTypeMismatch)
{
    LoatConfig initial = createSampleInitialConfig();
    LoatConfig config(initial);
    LoatSolver solver(config);

    EXPECT_THROW(
        solver.setParameter(DynamicParameterKey::Log, 42), // wrong type
        std::invalid_argument);
}

TEST(LoatSolverTest, RefreshConfigUpdatesGlobalConfig)
{
    LoatConfig initial = createSampleInitialConfig();
    LoatConfig config(initial);
    LoatSolver solver(config);

    solver.setParameter(DynamicParameterKey::LogAccel, true);
    solver.refreshConfig();

    EXPECT_TRUE(Config::Analysis::logAccel);
}

TEST(LoatSolverTest, AddExpressionStoresCorrectly)
{
    LoatConfig config(createSampleInitialConfig());
    LoatSolver solver(config);

    auto five = makeConst(5);
    auto ten = makeConst(10);
    auto sum = makePlus(five, ten);

    solver.add(sum);

    const auto &exprs = solver.getExpressions();
    ASSERT_EQ(exprs.size(), 1);
    EXPECT_EQ(exprs[0]->toString(), "(5 + 10)");
}

TEST(LoatSolverTest, AddMultipleExpressions)
{
    LoatSolver solver(createSampleInitialConfig());

    auto a = makeConst(1);
    auto b = makeConst(2);
    auto c = makeConst(3);

    solver.add(a);
    solver.add(makePlus(b, c));

    const auto &exprs = solver.getExpressions();
    ASSERT_EQ(exprs.size(), 2);
    EXPECT_EQ(exprs[0]->toString(), "1");
    EXPECT_EQ(exprs[1]->toString(), "(2 + 3)");
}