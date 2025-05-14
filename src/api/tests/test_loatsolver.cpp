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

// Termination / ADCL, ABMC, TRL Test cases
using Engine = LoatConfig::InitialConfig::Engine;

// TRL
TEST(TerminationEngineTest, TRL_DetectsTerminationCorrectly)
{
    // Create solver
    LoatConfig config(LoatConfig::InitialConfig(
        Engine::TRL,
        LoatConfig::InitialConfig::Mode::Termination,
        LoatConfig::InitialConfig::SmtSolver::Z3,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setParameter(DynamicParameterKey::Log, true);

    // Create Locations
    LoatLocation q0("q0");
    LoatLocation q1("q1");

    // Set start location and add transition
    solver.setStartLocation(q0);
    solver.add(LoatTransition(q0, q1, LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));

    // Get Result and check it
    LoatResult result = solver.check();
    EXPECT_EQ(result, LoatResult::SAT);
}

TEST(TerminationEngineTest, TRL_DetectsNonTerminationCorrectly)
{
    // Create solver
    LoatConfig config(LoatConfig::InitialConfig(
        Engine::TRL,
        LoatConfig::InitialConfig::Mode::Termination,
        LoatConfig::InitialConfig::SmtSolver::Z3,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setParameter(DynamicParameterKey::Log, true);

    // Create Location
    LoatLocation q_start("q_start");
    LoatLocation q0("q0");

    // Set start location and add transitions
    solver.setStartLocation(q_start);
    auto trueExpr = LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1);
    solver.add(LoatTransition(q_start, q0, trueExpr));
    solver.add(LoatTransition(q0, q0, trueExpr));

    // Get Result and check it
    LoatResult result = solver.check();
    EXPECT_EQ(result, LoatResult::UNKNOWN);
}

// ADCL
TEST(TerminationEngineTest, ADCL_DetectsTerminationCorrectly)
{
    // Create solver
    LoatConfig config(LoatConfig::InitialConfig(
        Engine::ADCL,
        LoatConfig::InitialConfig::Mode::Termination,
        LoatConfig::InitialConfig::SmtSolver::Z3,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setParameter(DynamicParameterKey::Log, true);

    // Create Locations
    LoatLocation q0("q0");
    LoatLocation q1("q1");

    // Set start location and add transition
    solver.setStartLocation(q0);
    solver.add(LoatTransition(q0, q1, LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));

    // Get Result and check it
    LoatResult result = solver.check();
    EXPECT_NE(result, LoatResult::UNSAT);
}

TEST(TerminationEngineTest, ADCL_DetectsNonTerminationCorrectly)
{
    // Create solver
    LoatConfig config(LoatConfig::InitialConfig(
        Engine::ADCL,
        LoatConfig::InitialConfig::Mode::Termination,
        LoatConfig::InitialConfig::SmtSolver::Z3,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setParameter(DynamicParameterKey::Log, true);

    // Create Location
    LoatLocation q_start("q_start");
    LoatLocation q0("q0");

    // Set start location and add transitions
    solver.setStartLocation(q_start);
    auto trueExpr = LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1);
    solver.add(LoatTransition(q_start, q0, trueExpr));
    solver.add(LoatTransition(q0, q0, trueExpr));

    // Get Result and check it
    LoatResult result = solver.check();
    EXPECT_EQ(result, LoatResult::UNSAT);
}

// ABMC
TEST(TerminationEngineTest, ABMC_DetectsTerminationCorrectly)
{
    // Create solver
    LoatConfig config(LoatConfig::InitialConfig(
        Engine::ABMC,
        LoatConfig::InitialConfig::Mode::Termination,
        LoatConfig::InitialConfig::SmtSolver::Z3,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setParameter(DynamicParameterKey::Log, true);

    // Create Locations
    LoatLocation q0("q0");
    LoatLocation q1("q1");

    // Set start location and add transition
    solver.setStartLocation(q0);
    solver.add(LoatTransition(q0, q1, LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));

    // Get Result and check it
    LoatResult result = solver.check();
    EXPECT_NE(result, LoatResult::UNSAT);
}

TEST(TerminationEngineTest, ABMC_DetectsNonTerminationCorrectly)
{
    // Create solver
    LoatConfig config(LoatConfig::InitialConfig(
        Engine::ABMC,
        LoatConfig::InitialConfig::Mode::Termination,
        LoatConfig::InitialConfig::SmtSolver::Z3,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));
    LoatSolver solver(config);
    solver.setParameter(DynamicParameterKey::Log, true);

    // Create Location
    LoatLocation q_start("q_start");
    LoatLocation q0("q0");

    // Set start location and add transitions
    solver.setStartLocation(q_start);
    auto trueExpr = LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1);
    solver.add(LoatTransition(q_start, q0, trueExpr));
    solver.add(LoatTransition(q0, q0, trueExpr));

    // Get Result and check it
    LoatResult result = solver.check();
    EXPECT_EQ(result, LoatResult::UNSAT);
}

// Different SMT Solver
using SmtSolver = LoatConfig::InitialConfig::SmtSolver;

// Helper function for a non-terminating loop test
void RunAdclNonTerminationWithSolver(SmtSolver solver, const std::string &solverName)
{
    LoatConfig config(LoatConfig::InitialConfig(
        Engine::ADCL,
        LoatConfig::InitialConfig::Mode::Termination,
        solver,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false));

    LoatSolver loat(config);
    loat.setParameter(DynamicParameterKey::Log, true);

    LoatLocation q0("q0");
    LoatLocation q_start("q_start");

    loat.setStartLocation(q_start);
    loat.add(LoatTransition(q_start, q0, LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));
    loat.add(LoatTransition(q0, q0, LoatIntExpression::mkConst(1) == LoatIntExpression::mkConst(1)));

    LoatResult result = loat.check();
    EXPECT_EQ(result, LoatResult::UNSAT);
}

TEST(AdclNonTerminationTest, WithZ3)
{
    RunAdclNonTerminationWithSolver(SmtSolver::Z3, "Z3");
}

TEST(AdclNonTerminationTest, WithCvc5)
{
    RunAdclNonTerminationWithSolver(SmtSolver::CVC5, "CVC5");
}

TEST(AdclNonTerminationTest, WithYices)
{
    RunAdclNonTerminationWithSolver(SmtSolver::Yices, "Yices");
}

TEST(AdclNonTerminationTest, WithSwine)
{
    RunAdclNonTerminationWithSolver(SmtSolver::Swine, "SwInE");
}

TEST(AdclNonTerminationTest, WithHeuristic)
{
    RunAdclNonTerminationWithSolver(SmtSolver::Heuristic, "Heuristic");
}