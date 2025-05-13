#include <gtest/gtest.h>
#include "loatconfig.hpp"
#include "config.hpp"
#include "test_util.hpp"

// === InitialConfig Tests ===

TEST(InitialConfigTest, CanRetrieveValuesViaGet)
{
    auto init = createSampleInitialConfig();

    EXPECT_EQ(
        std::any_cast<LoatConfig::InitialConfig::Engine>(
            init.get(InitialParameterKey::Engine)),
        LoatConfig::InitialConfig::Engine::ADCL);

    EXPECT_EQ(
        std::any_cast<LoatConfig::InitialConfig::Mode>(
            init.get(InitialParameterKey::Mode)),
        LoatConfig::InitialConfig::Mode::Termination);

    EXPECT_EQ(
        std::any_cast<LoatConfig::InitialConfig::SmtSolver>(
            init.get(InitialParameterKey::SmtSolver)),
        LoatConfig::InitialConfig::SmtSolver::Z3);

    EXPECT_EQ(
        std::any_cast<LoatConfig::InitialConfig::Direction>(
            init.get(InitialParameterKey::Direction)),
        LoatConfig::InitialConfig::Direction::Forward);

    EXPECT_EQ(
        std::any_cast<LoatConfig::InitialConfig::MbpKind>(
            init.get(InitialParameterKey::MbpKind)),
        LoatConfig::InitialConfig::MbpKind::IntMbp);

    EXPECT_TRUE(std::any_cast<bool>(init.get(InitialParameterKey::Model)));
}

TEST(InitialConfigTest, ThrowsOnInvalidKey)
{
    auto init = createSampleInitialConfig();

    EXPECT_THROW(
        init.get(static_cast<InitialParameterKey>(999)),
        std::invalid_argument);
}

// === DynamicConfig Tests ===

TEST(DynamicConfigTest, SetAndRetrieveViaGet)
{
    LoatConfig::DynamicConfig dyn;

    dyn.set(DynamicParameterKey::Log, true);
    dyn.set(DynamicParameterKey::TRP_RecurrentPseudoDivs, false);

    EXPECT_TRUE(std::any_cast<bool>(dyn.get(DynamicParameterKey::Log)));
    EXPECT_FALSE(std::any_cast<bool>(dyn.get(DynamicParameterKey::TRP_RecurrentPseudoDivs)));
}

TEST(DynamicConfigTest, ThrowsOnInvalidKey)
{
    LoatConfig::DynamicConfig dyn;

    EXPECT_THROW(
        dyn.get(static_cast<DynamicParameterKey>(999)),
        std::invalid_argument);

    EXPECT_THROW(
        dyn.set(static_cast<DynamicParameterKey>(999), true),
        std::invalid_argument);
}

TEST(DynamicConfigTest, ThrowsOnBadAnyCast)
{
    LoatConfig::DynamicConfig dyn;

    EXPECT_THROW(
        dyn.set(DynamicParameterKey::Log, 42), // wrong type
        std::invalid_argument);

    EXPECT_THROW(
        dyn.set(DynamicParameterKey::BlockingClauses, std::string("true")),
        std::invalid_argument);
}

// === LoatConfig API Tests ===

TEST(LoatConfigTest, CanConstructAndAccessInitial)
{
    LoatConfig config(createSampleInitialConfig());

    EXPECT_EQ(
        std::any_cast<LoatConfig::InitialConfig::Engine>(
            config.getInitial().get(InitialParameterKey::Engine)),
        LoatConfig::InitialConfig::Engine::ADCL);
}

TEST(LoatConfigTest, CanConstructWithDynamicConfig)
{
    LoatConfig::DynamicConfig dyn;
    dyn.set(DynamicParameterKey::Log, true);

    LoatConfig config(createSampleInitialConfig(), dyn);

    EXPECT_TRUE(std::any_cast<bool>(config.getDynamic().get(DynamicParameterKey::Log)));
}

TEST(LoatConfigTest, ModifyDynamicAfterConstruction)
{
    LoatConfig config(createSampleInitialConfig());
    config.getDynamic().set(DynamicParameterKey::LogAccel, true);

    EXPECT_TRUE(std::any_cast<bool>(config.getDynamic().get(DynamicParameterKey::LogAccel)));
}

TEST(LoatConfigTest, ApplyToGlobalConfigSetsGlobalsCorrectly)
{
    // Setup
    LoatConfig::DynamicConfig dyn;
    dyn.set(DynamicParameterKey::Log, true);
    dyn.set(DynamicParameterKey::TRP_RecurrentBounds, true);
    dyn.set(DynamicParameterKey::BlockingClauses, true);

    LoatConfig config(createSampleInitialConfig(), dyn);

    // Act
    config.applyToGlobalConfig();

    // Assert - verify the global Config:: namespace was set properly
    EXPECT_EQ(Config::Analysis::engine, Config::Analysis::Engine::ADCL);
    EXPECT_EQ(Config::Analysis::mode, Config::Analysis::Mode::Termination);
    EXPECT_EQ(Config::Analysis::smtSolver, Config::Analysis::SmtSolver::Z3);
    EXPECT_EQ(Config::Analysis::dir, Config::Analysis::Direction::Forward);
    EXPECT_EQ(Config::Analysis::model, true);

    EXPECT_EQ(Config::Analysis::log, true);
    EXPECT_EQ(Config::ABMC::blocking_clauses, true);
    EXPECT_EQ(Config::trp.recurrent_bounds, true);
}