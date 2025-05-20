#include "loatsolver.hpp"
#include "abmc.hpp"
#include "bmc.hpp"
#include "trl.hpp"
#include "adcl.hpp"
#include "adclsat.hpp"
#include "config.hpp"
#include "preprocessing.hpp"
#include "yices.hpp"

#include <stdexcept>

void LoatSolver::setParameter(DynamicParameterKey key, const std::any &value)
{
    // Try setting the option
    try
    {
        m_config.getDynamic().set(key, value);
    }
    // Pass the exception through the layer
    catch (const std::exception &e)
    {
        throw;
    }
}

void LoatSolver::refreshConfig()
{
    // Apply the current config into the internal global config
    m_config.applyToGlobalConfig();
}

void LoatSolver::add(const LoatTransition &transition)
{
    // Add a transition to the vector
    m_transitions.push_back(transition);
}

void LoatSolver::setStartLocation(const LoatLocation &location)
{
    // Set start location
    m_start = location;
}

void LoatSolver::addSinkLocation(const LoatLocation &location)
{
    // Set sink location
    m_sink = location;
}

void LoatSolver::produceITS()
{
    // Check if start location is set, throw exception if not
    if (!m_start.has_value())
    {
        throw std::invalid_argument("Start location must be defined (use setStartLocation(location))");
    }
    // Check if sink location is set (if mode is safety), throw exception if not
    if (std::any_cast<LoatConfig::InitialConfig::Mode>(m_config.getInitial().get(InitialParameterKey::Mode)) == LoatConfig::InitialConfig::Safety && !m_sink.has_value())
    {
        throw std::invalid_argument("Sink location must be defined in safety mode (use setSinkLocation(location))");
    }
    // Convert values to its
    m_its = m_converter.convertTransitionsToITS(m_transitions, m_start.value(), m_sink);
}

LoatResult LoatSolver::check()
{
    std::cout << "[LoAT] Starting solver check()"
              << std::endl;

    if (Config::Analysis::log)
    {
        std::cout << "[LoAT] Refreshing config..."
                  << std::endl;
    }

    // Refresh the config to be up to date
    refreshConfig();

    if (Config::Analysis::log)
    {
        std::cout << "[LoAT] Producing ITS..." << std::endl;
    }

    // Produce the its
    produceITS();

    if (Config::Analysis::log)
    {
        std::cout << "Initial ITS" << std::endl
                  << m_its << std::endl;
    }

    // Init yices
    if (Config::Analysis::log)
    {
        std::cout << "[LoAT] Init yices" << std::endl;
    }
    yices::init();

    // Variables to store model or cex
    std::optional<ITSModel> its_model;
    std::optional<ITSSafetyCex> its_cex;

    // Create and apply preprocessor
    auto preprocessor = std::make_shared<Preprocessor>(m_its);
    std::cout << "[LoAT] Running preprocessor..." << std::endl;
    auto res = preprocessor->preprocess();
    std::cout << "[LoAT] Preprocessor result: "
              << (res == SmtResult::Sat ? "SAT" : res == SmtResult::Unsat ? "UNSAT"
                                                                          : "UNKNOWN")
              << std::endl;

    // Check if preprocessor already solved the problem
    if (res != SmtResult::Unknown)
    {

        std::cout << "[LoAT] Solved by preprocessing" << std::endl;

        // If we user wanted a proof, save it
        if (Config::Analysis::model)
        {
            if (res == SmtResult::Sat)
            {
                if (Config::Analysis::log)
                {
                    std::cout << "[LoAT] Transforming ITS model" << std::endl;
                }
                its_model = preprocessor->get_model();
            }
            else
            {
                if (Config::Analysis::log)
                {
                    std::cout << "[LoAT] Transforming ITS cex" << std::endl;
                }
                its_cex = preprocessor->get_cex();
            }
        }
    }

    // Dispatch requested method, if preprocessor did not solve the problem
    else
    {
        if (preprocessor->successful() && Config::Analysis::log)
        {
            std::cout << "[LoAT] Simplified ITS:\n"
                      << m_its << "\n";
        }

        std::cout << "[LoAT] Dispatching engine: ";
        switch (Config::Analysis::engine)
        {

        // ADCL
        case Config::Analysis::ADCL:
            std::cout << "ADCL\n";
            {
                adcl::ADCL r(m_its, [&](const ITSCpxCex &) {});
                res = r.analyze();
                std::cout << "[LoAT] ADCL result: " << (int)res << "\n";

                if (Config::Analysis::model && !Config::Analysis::complexity() && res == SmtResult::Unsat)
                {
                    std::cout << "[LoAT] Getting CEX from ADCL\n";
                    its_cex = r.get_cex();
                }
            }
            break;

        // BMC and KIND
        case Config::Analysis::BMC:
        case Config::Analysis::KIND:
            std::cout << (Config::Analysis::engine == Config::Analysis::KIND ? "KIND\n" : "BMC\n");
            {
                BMC bmc(m_its, Config::Analysis::engine == Config::Analysis::KIND);
                res = bmc.analyze();
                std::cout << "[LoAT] BMC/KIND result: " << (int)res << "\n";

                if (Config::Analysis::model)
                {
                    if (res == SmtResult::Sat)
                    {
                        std::cout << "[LoAT] Getting model from BMC/KIND\n";
                        its_model = bmc.get_model();
                    }
                    else if (res == SmtResult::Unsat)
                    {
                        std::cout << "[LoAT] Getting CEX from BMC/KIND\n";
                        its_cex = bmc.get_cex();
                    }
                }
            }
            break;

        // ABMC
        case Config::Analysis::ABMC:
            std::cout << "ABMC\n";
            {
                ABMC abmc(m_its);
                res = abmc.analyze();
                std::cout << "[LoAT] ABMC result: " << (int)res << "\n";

                if (Config::Analysis::model)
                {
                    if (res == SmtResult::Sat)
                    {
                        std::cout << "[LoAT] Getting model from ABMC\n";
                        its_model = abmc.get_model();
                    }
                    else if (res == SmtResult::Unsat)
                    {
                        std::cout << "[LoAT] Getting CEX from ABMC\n";
                        its_cex = abmc.get_cex();
                    }
                }
            }
            break;

        // TRL
        case Config::Analysis::TRL:
            std::cout << "TRL\n";
            {
                TRL trl(m_its, Config::trp);
                res = trl.analyze();
                std::cout << "[LoAT] TRL result: " << (int)res << "\n";

                if (Config::Analysis::model)
                {
                    if (res == SmtResult::Sat)
                    {
                        std::cout << "[LoAT] Getting model from TRL\n";
                        its_model = trl.get_model();
                    }
                    else if (res == SmtResult::Unsat)
                    {
                        std::cout << "[LoAT] Getting CEX from TRL\n";
                        its_cex = trl.get_cex();
                    }
                }
            }
            break;

        // ADCLSAT
        case Config::Analysis::ADCLSAT:
            std::cout << "ADCLSAT\n";
            {
                ADCLSat adcl(m_its, Config::trp);
                res = adcl.analyze();
                std::cout << "[LoAT] ADCLSAT result: " << (int)res << "\n";

                if (Config::Analysis::model)
                {
                    if (res == SmtResult::Sat)
                    {
                        std::cout << "[LoAT] ERROR: Model requested from ADCLSAT (not supported)\n";
                        throw std::logic_error("Model is not supported for ADCLSAT");
                    }
                    else if (res == SmtResult::Unsat)
                    {
                        std::cout << "[LoAT] Getting CEX from ADCLSAT\n";
                        its_cex = adcl.get_cex();
                    }
                }
            }
            break;
        }
    }

    // Check if we have a model
    if (its_model.has_value())
    {
        if (Config::Analysis::log)
        {
            std::cout << "[LoAT] Transforming ITS model" << std::endl;
        }

        m_its_model = preprocessor->transform_model(*its_model);
    }
    // Check if we have a cex
    else if (its_cex.has_value())
    {
        if (Config::Analysis::log)
        {
            std::cout << "[LoAT] Transforming ITS cex" << std::endl;
        }
        m_its_cex = preprocessor->transform_cex(*its_cex);
    }

    // Exit yices
    yices::exit();

    if (Config::Analysis::log)
    {
        std::cout << "[LoAT] Yices exited, preparing result" << std::endl;
    }

    switch (res)
    {
    case SmtResult::Sat:
        std::cout << "[LoAT] Final result: " << (Config::Analysis::safety() ? "sat" : "YES") << std::endl;
        return LoatResult::SAT;
    case SmtResult::Unsat:
        std::cout << "[LoAT] Final result: " << (Config::Analysis::safety() ? "unsat" : "NO") << std::endl;
        return LoatResult::UNSAT;
    case SmtResult::Unknown:
        std::cout << "[LoAT] Final result: " << (Config::Analysis::safety() ? "unknown" : "MAYBE") << std::endl;
        return LoatResult::UNKNOWN;
    default:
        throw std::invalid_argument("[LoAT] Unexpected type of the result");
    }
}

#include <stdexcept>

ITSModel LoatSolver::getModel()
{
    if (!std::any_cast<bool>(m_config.getInitial().get(InitialParameterKey::Model)))
    {
        throw std::logic_error("Model requested, but proof generation is not enabled in the config.");
    }

    if (!m_its_model.has_value())
    {
        throw std::logic_error("No model available. Make sure check() has been called and the selected engine supports model generation.");
    }

    return m_its_model.value();
}

ITSSafetyCex LoatSolver::getCex()
{
    if (!!std::any_cast<bool>(m_config.getInitial().get(InitialParameterKey::Model)))
    {
        throw std::logic_error("Counterexample requested, but proof generation is not enabled in the config.");
    }

    if (!m_its_cex.has_value())
    {
        throw std::logic_error("No counterexample available. Make sure check() has been called and the selected engine supports counterexamples.");
    }

    return m_its_cex.value();
}