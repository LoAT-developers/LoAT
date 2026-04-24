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

    const LoatConfig config(createSampleInitialConfig(), dyn);
    LoatSolver solver(config);

    // Should be applied globally
    EXPECT_TRUE(Config::Analysis::log);
}

TEST(LoatSolverTest, SetParameterWorksCorrectly)
{
    const LoatConfig initial = createSampleInitialConfig();
    const LoatConfig config(initial);
    LoatSolver solver(config);

    // Default should be false
    const bool before = std::any_cast<bool>(
        solver.getConfig().getDynamic().get(DynamicParameterKey::BlockingClauses));
    EXPECT_FALSE(before);

    // Set via solver interface
    solver.setParameter(DynamicParameterKey::BlockingClauses, true);

    const bool after = std::any_cast<bool>(
        solver.getConfig().getDynamic().get(DynamicParameterKey::BlockingClauses));
    EXPECT_TRUE(after);
}

TEST(LoatSolverTest, SetParameterThrowsOnTypeMismatch)
{
    const LoatConfig initial = createSampleInitialConfig();
    const LoatConfig config(initial);
    LoatSolver solver(config);

    EXPECT_THROW(
        solver.setParameter(DynamicParameterKey::Log, 42), // wrong type
        std::invalid_argument);
}

// Termination / ADCL, ABMC, TRL Test cases
using Engine = LoatConfig::InitialConfig::Engine;

// TRL
TEST(TerminationEngineTest, TRL_DetectsTerminationCorrectly)
{
    // Create solver
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::TRL,
        LoatConfig::InitialConfig::Mode::Termination,
        LoatConfig::InitialConfig::SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setParameter(DynamicParameterKey::Log, true);

    // Create Locations
    const LoatLocation q0("q0");
    const LoatLocation q1("q1");

    // Set start location and add transition
    solver.setStartLocation(q0);
    solver.add(LoatTransition(q0, q1, LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));

    // Get Result and check it
    const LoatResult result = solver.check();
    EXPECT_EQ(result, LoatResult::SAT);
}

TEST(TerminationEngineTest, TRL_DetectsNonTerminationCorrectly)
{
    // Create solver
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::TRL,
        LoatConfig::InitialConfig::Mode::Termination,
        LoatConfig::InitialConfig::SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setParameter(DynamicParameterKey::Log, true);

    // Create Location
    const LoatLocation q_start("q_start");
    const LoatLocation q0("q0");

    // Set start location and add transitions
    solver.setStartLocation(q_start);
    const auto trueExpr = LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1);
    solver.add(LoatTransition(q_start, q0, trueExpr));
    solver.add(LoatTransition(q0, q0, trueExpr));

    // Get Result and check it
    const LoatResult result = solver.check();
    EXPECT_EQ(result, LoatResult::UNKNOWN);
}

// ADCL
TEST(TerminationEngineTest, ADCL_DetectsTerminationCorrectly)
{
    // Create solver
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::ADCL,
        LoatConfig::InitialConfig::Mode::Termination,
        LoatConfig::InitialConfig::SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setParameter(DynamicParameterKey::Log, true);

    // Create Locations
    const LoatLocation q0("q0");
    const LoatLocation q1("q1");

    // Set start location and add transition
    solver.setStartLocation(q0);
    solver.add(LoatTransition(q0, q1, LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));

    // Get Result and check it
    const LoatResult result = solver.check();
    EXPECT_NE(result, LoatResult::UNSAT);
}

TEST(TerminationEngineTest, ADCL_DetectsNonTerminationCorrectly)
{
    // Create solver
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::ADCL,
        LoatConfig::InitialConfig::Mode::Termination,
        LoatConfig::InitialConfig::SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setParameter(DynamicParameterKey::Log, true);

    // Create Location
    const LoatLocation q_start("q_start");
    const LoatLocation q0("q0");

    // Set start location and add transitions
    solver.setStartLocation(q_start);
    const auto trueExpr = LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1);
    solver.add(LoatTransition(q_start, q0, trueExpr));
    solver.add(LoatTransition(q0, q0, trueExpr));

    // Get Result and check it
    const LoatResult result = solver.check();
    EXPECT_EQ(result, LoatResult::UNSAT);
}

// ABMC
TEST(TerminationEngineTest, ABMC_DetectsTerminationCorrectly)
{
    // Create solver
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::ABMC,
        LoatConfig::InitialConfig::Mode::Termination,
        LoatConfig::InitialConfig::SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setParameter(DynamicParameterKey::Log, true);

    // Create Locations
    const LoatLocation q0("q0");
    const LoatLocation q1("q1");

    // Set start location and add transition
    solver.setStartLocation(q0);
    solver.add(LoatTransition(q0, q1, LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));

    // Get Result and check it
    const LoatResult result = solver.check();
    EXPECT_NE(result, LoatResult::UNSAT);
}

TEST(TerminationEngineTest, ABMC_DetectsNonTerminationCorrectly)
{
    // Create solver
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::ABMC,
        LoatConfig::InitialConfig::Mode::Termination,
        LoatConfig::InitialConfig::SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setParameter(DynamicParameterKey::Log, true);

    // Create Location
    const LoatLocation q_start("q_start");
    const LoatLocation q0("q0");

    // Set start location and add transitions
    solver.setStartLocation(q_start);
    const auto trueExpr = LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1);
    solver.add(LoatTransition(q_start, q0, trueExpr));
    solver.add(LoatTransition(q0, q0, trueExpr));

    // Get Result and check it
    const LoatResult result = solver.check();
    EXPECT_EQ(result, LoatResult::UNSAT);
}

// regression test for GitHub issue #9
TEST(TerminationEngineTest, ABMC_TerminationInitialLocationWithLoop)
{
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::ABMC,
        LoatConfig::InitialConfig::Mode::Termination,
        LoatConfig::InitialConfig::SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setStartLocation(LoatLocation("q0"));
    solver.add(LoatTransition(LoatLocation("q0"), LoatLocation("q0"), LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));
    EXPECT_EQ(solver.check(), LoatResult::UNSAT);
}

// Different SMT Solver
using SmtSolver = LoatConfig::InitialConfig::SmtSolver;

// Helper function for a non-terminating loop test
void RunAdclNonTerminationWithSolver(const SmtSolver solver)
{
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::ADCL,
        LoatConfig::InitialConfig::Mode::Termination,
        solver,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));

    LoatSolver loat(config);
    loat.setParameter(DynamicParameterKey::Log, true);

    const LoatLocation q0("q0");
    const LoatLocation q_start("q_start");

    loat.setStartLocation(q_start);
    loat.add(LoatTransition(q_start, q0, LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));
    loat.add(LoatTransition(q0, q0, LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));

    const LoatResult result = loat.check();
    EXPECT_EQ(result, LoatResult::UNSAT);
}

TEST(AdclNonTerminationTest, WithYices)
{
    RunAdclNonTerminationWithSolver(SmtSolver::Yices);
}

TEST(AdclNonTerminationTest, WithSwine)
{
    RunAdclNonTerminationWithSolver(SmtSolver::Swine);
}

TEST(AdclNonTerminationTest, WithHeuristic)
{
    RunAdclNonTerminationWithSolver(SmtSolver::Heuristic);
}

// Safety Test cases

TEST(SafetyEngineTest, TRL_DetectsSafetyCorrectly)
{
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::TRL,
        LoatConfig::InitialConfig::Mode::Safety,
        SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));

    LoatSolver solver(config);
    solver.setStartLocation(LoatLocation("q0"));
    solver.addSinkLocation(LoatLocation("sink"));
    solver.add(LoatTransition(LoatLocation("q0"), LoatLocation("sink"), LoatIntExpression::mkConst(0) == LoatIntExpression::mkConst(1)));

    EXPECT_EQ(solver.check(), LoatResult::SAT);
}

TEST(SafetyEngineTest, TRL_DetectsUnsafetyCorrectly)
{
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::TRL,
        LoatConfig::InitialConfig::Mode::Safety,
        SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setStartLocation(LoatLocation("q0"));
    solver.addSinkLocation(LoatLocation("sink"));
    solver.add(LoatTransition(LoatLocation("q0"), LoatLocation("sink"), LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));

    EXPECT_EQ(solver.check(), LoatResult::UNSAT);
}

TEST(SafetyEngineTest, ABMC_DetectsSafetyCorrectly)
{
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::ABMC,
        LoatConfig::InitialConfig::Mode::Safety,
        SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setStartLocation(LoatLocation("q0"));
    solver.addSinkLocation(LoatLocation("sink"));
    solver.add(LoatTransition(LoatLocation("q0"), LoatLocation("sink"), LoatIntExpression::mkConst(0) == LoatIntExpression::mkConst(1)));

    EXPECT_EQ(solver.check(), LoatResult::SAT);
}

TEST(SafetyEngineTest, ABMC_DetectsUnsafetyCorrectly)
{
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::ABMC,
        LoatConfig::InitialConfig::Mode::Safety,
        SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setStartLocation(LoatLocation("q0"));
    solver.addSinkLocation(LoatLocation("sink"));
    solver.add(LoatTransition(LoatLocation("q0"), LoatLocation("sink"), LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));

    EXPECT_EQ(solver.check(), LoatResult::UNSAT);
}

TEST(SafetyEngineTest, KIND_DetectsSafetyCorrectly)
{
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::KIND,
        LoatConfig::InitialConfig::Mode::Safety,
        SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setStartLocation(LoatLocation("q0"));
    solver.addSinkLocation(LoatLocation("sink"));
    solver.add(LoatTransition(LoatLocation("q0"), LoatLocation("sink"), LoatIntExpression::mkConst(0) == LoatIntExpression::mkConst(1)));

    EXPECT_EQ(solver.check(), LoatResult::SAT);
}

TEST(SafetyEngineTest, KIND_DetectsUnsafetyCorrectly)
{
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::KIND,
        LoatConfig::InitialConfig::Mode::Safety,
        SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setStartLocation(LoatLocation("q0"));
    solver.addSinkLocation(LoatLocation("sink"));
    solver.add(LoatTransition(LoatLocation("q0"), LoatLocation("sink"), LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));

    EXPECT_EQ(solver.check(), LoatResult::UNSAT);
}

TEST(SafetyEngineTest, ADCLSAT_DetectsSafetyCorrectly)
{
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::ADCLSAT,
        LoatConfig::InitialConfig::Mode::Safety,
        SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setStartLocation(LoatLocation("q0"));
    solver.addSinkLocation(LoatLocation("sink"));
    solver.add(LoatTransition(LoatLocation("q0"), LoatLocation("sink"), LoatIntExpression::mkConst(0) == LoatIntExpression::mkConst(1)));

    EXPECT_EQ(solver.check(), LoatResult::SAT);
}

TEST(SafetyEngineTest, ADCLSAT_UnsafetyNotSupported)
{
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::ADCLSAT,
        LoatConfig::InitialConfig::Mode::Safety,
        SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setStartLocation(LoatLocation("q0"));
    solver.addSinkLocation(LoatLocation("sink"));
    solver.add(LoatTransition(LoatLocation("q0"), LoatLocation("sink"), LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));

    EXPECT_NE(solver.check(), LoatResult::SAT);
}

TEST(SafetyEngineTest, ADCL_SafetyNotSupported)
{
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::ADCL,
        LoatConfig::InitialConfig::Mode::Safety,
        SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setStartLocation(LoatLocation("q0"));
    solver.addSinkLocation(LoatLocation("sink"));
    solver.add(LoatTransition(LoatLocation("q0"), LoatLocation("sink"), LoatIntExpression::mkConst(0) == LoatIntExpression::mkConst(1)));

    EXPECT_NE(solver.check(), LoatResult::UNSAT);
}

TEST(SafetyEngineTest, ADCL_DetectsUnsafetyCorrectly)
{
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::ADCL,
        LoatConfig::InitialConfig::Mode::Safety,
        SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setStartLocation(LoatLocation("q0"));
    solver.addSinkLocation(LoatLocation("sink"));
    solver.add(LoatTransition(LoatLocation("q0"), LoatLocation("sink"), LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));

    EXPECT_EQ(solver.check(), LoatResult::UNSAT);
}

TEST(SafetyEngineTest, BMC_SafetyNotSupported)
{
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::BMC,
        LoatConfig::InitialConfig::Mode::Safety,
        SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setStartLocation(LoatLocation("q0"));
    solver.addSinkLocation(LoatLocation("sink"));
    solver.add(LoatTransition(LoatLocation("q0"), LoatLocation("sink"), LoatIntExpression::mkConst(0) == LoatIntExpression::mkConst(1)));

    EXPECT_NE(solver.check(), LoatResult::UNSAT);
}

TEST(SafetyEngineTest, BMC_DetectsUnsafetyCorrectly)
{
    const LoatConfig config(LoatConfig::InitialConfig(
        Engine::BMC,
        LoatConfig::InitialConfig::Mode::Safety,
        SmtSolver::Swine,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setStartLocation(LoatLocation("q0"));
    solver.addSinkLocation(LoatLocation("sink"));
    solver.add(LoatTransition(LoatLocation("q0"), LoatLocation("sink"), LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));

    EXPECT_EQ(solver.check(), LoatResult::UNSAT);
}
