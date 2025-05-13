#include <gtest/gtest.h>
#include "loatsolver.hpp"
#include "loatconfig.hpp"
#include "config.hpp"
#include "test_util.hpp"
#include "loatintexpr.hpp"

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

TEST(LoatSolverTest, DetectsTerminationInOneStep)
{
    // Create solver
    LoatConfig config(LoatConfig::InitialConfig(
        LoatConfig::InitialConfig::Engine::BMC,
        LoatConfig::InitialConfig::Mode::Termination,
        LoatConfig::InitialConfig::SmtSolver::Z3,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        true));
    LoatSolver solver(config);

    // start at q0, sink is q1
    solver.setStartLocation(LoatLocation("q0"));
    solver.addSinkLocation(LoatLocation("q1"));

    // a expression that is true (1==1)
    auto trueExpression = LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1);
    solver.add(LoatTransition(LoatLocation("q0"),
                              LoatLocation("q1"),
                              trueExpression));

    // Apply solving
    LoatResult result = solver.check();

    // In termination mode, this should return sat
    EXPECT_EQ(result, LoatResult::SAT);
}

TEST(LoatSolverTest, DetectsNonTerminationInSimpleLoop)
{
    // Create solver
    LoatConfig::DynamicConfig dyn;
    LoatConfig config(LoatConfig::InitialConfig(
        LoatConfig::InitialConfig::Engine::BMC,
        LoatConfig::InitialConfig::Mode::Termination,
        LoatConfig::InitialConfig::SmtSolver::Z3,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        true));
    LoatSolver solver(config);

    // start at q0, sink is q_sink (unreachable)
    solver.setStartLocation(LoatLocation("q0"));
    solver.addSinkLocation(LoatLocation("q_sink"));

    // Infinite Self Loop
    auto trueExpression = LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1);
    solver.add(LoatTransition(LoatLocation("q0"),
                              LoatLocation("q0"),
                              trueExpression));

    // Apply solving
    LoatResult result = solver.check();

    // In termination mode, this should return unsat
    EXPECT_EQ(result, LoatResult::UNSAT);
}
