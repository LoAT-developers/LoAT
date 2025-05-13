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
    try
    {
        m_config.getDynamic().set(key, value);
    }
    catch (const std::exception &e)
    {
        throw;
    }
}

void LoatSolver::refreshConfig()
{
    m_config.applyToGlobalConfig();
}

void LoatSolver::add(const LoatTransition &transition)
{
    m_transitions.push_back(transition);
}

void LoatSolver::setStartLocation(const LoatLocation &location)
{
    m_start = location;
}

void LoatSolver::addSinkLocation(const LoatLocation &location)
{
    m_sink = location;
}

void LoatSolver::produceITS()
{
    m_its = m_converter.convertTransitionsToITS(m_transitions, m_start, m_sink);
}

LoatResult LoatSolver::check()
{
    // Refresh the config to be up to date
    refreshConfig();

    // Produce the required its
    produceITS();

    if (Config::Analysis::log)
    {
        std::cout << "Initial ITS\n"
                  << m_its << std::endl;
    }

    // Dispatch selected function
    yices::init();
    std::optional<ITSModel> its_model;
    std::optional<ITSSafetyCex> its_cex;
    auto preprocessor{std::make_shared<Preprocessor>(m_its)};
    auto res{preprocessor->preprocess()};
    if (res != SmtResult::Unknown)
    {
        if (Config::Analysis::log)
        {
            std::cout << "solved by preprocessing" << std::endl;
        }
        if (Config::Analysis::model)
        {
            if (res == SmtResult::Sat)
            {
                its_model = preprocessor->get_model();
            }
            else
            {
                its_cex = preprocessor->get_cex();
            }
        }
    }
    else
    {
        if (preprocessor->successful() && Config::Analysis::log)
        {
            std::cout << "Simplified ITS\n"
                      << m_its << std::endl;
        }
        else
        {
            switch (Config::Analysis::engine)
            {
            case Config::Analysis::ADCL:
            {
                adcl::ADCL r{
                    m_its,
                    [&](const ITSCpxCex &cex)
                    {
                        // TODO if you want to add complexity
                    }};
                res = r.analyze();
                if (Config::Analysis::model && !Config::Analysis::complexity() && res == SmtResult::Unsat)
                {
                    its_cex = r.get_cex();
                }
                break;
            }
            case Config::Analysis::BMC:
            case Config::Analysis::KIND:
            {
                BMC bmc{m_its, Config::Analysis::engine == Config::Analysis::KIND};
                res = bmc.analyze();
                if (Config::Analysis::model)
                {
                    if (res == SmtResult::Sat)
                    {
                        its_model = bmc.get_model();
                    }
                    else if (res == SmtResult::Unsat)
                    {
                        its_cex = bmc.get_cex();
                    }
                }
                break;
            }
            case Config::Analysis::ABMC:
            {
                ABMC abmc{m_its};
                res = abmc.analyze();
                if (Config::Analysis::model)
                {
                    if (res == SmtResult::Sat)
                    {
                        its_model = abmc.get_model();
                    }
                    else if (res == SmtResult::Unsat)
                    {
                        its_cex = abmc.get_cex();
                    }
                }
                break;
            }
            case Config::Analysis::TRL:
            {
                TRL trl(m_its, Config::trp);
                res = trl.analyze();
                if (Config::Analysis::model)
                {
                    if (res == SmtResult::Sat)
                    {
                        its_model = trl.get_model();
                    }
                    else if (res == SmtResult::Unsat)
                    {
                        its_cex = trl.get_cex();
                    }
                }
                break;
            }
            case Config::Analysis::ADCLSAT:
            {
                ADCLSat adcl(m_its, Config::trp);
                res = adcl.analyze();
                if (Config::Analysis::model)
                {
                    if (res == SmtResult::Sat)
                    {
                        throw std::logic_error("Model is not supported for ADCLSAT");
                    }
                    else if (res == SmtResult::Unsat)
                    {
                        its_cex = adcl.get_cex();
                    }
                }
                break;
            }
            }
        }
    }

    if (its_model)
    {
        m_its_model = preprocessor->transform_model(*its_model);
    }
    else if (its_cex)
    {
        m_its_cex = preprocessor->transform_cex(*its_cex);
    }
    yices::exit();

    switch (res)
    {
    case SmtResult::Sat:
        return LoatResult::SAT;
    case SmtResult::Unsat:
        return LoatResult::UNSAT;
    case SmtResult::Unknown:
        return LoatResult::UNKNOWN;
    // Just in case that we add new types in the inner layer, we should get an error here
    default:
        throw std::invalid_argument("Unexpected type of the result");
    }
}