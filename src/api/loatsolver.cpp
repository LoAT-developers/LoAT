#include "loatsolver.hpp"
#include "abmc.hpp"
#include "bmc.hpp"
#include "trl.hpp"
#include "adcl.hpp"
#include "adclsat.hpp"
#include "config.hpp"
#include "preprocessing.hpp"
#include "optional.hpp"
#include "itsproblem.hpp"

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

    // Dispatch selected function
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
        // if (Config::Analysis::dir == Config::Analysis::Direction::Interleaved)
        // {
        //     // We dont have chc so no reverse???
        //     reverse = Reverse(*chcs);
        // }
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
                        if (Config::Analysis::complexity())
                        {
                            std::cout << preprocessor->transform_cex(cex);
                        }
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
                        its_model = adcl.get_model();
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
    // unsat means nonterm, so we also print it in complexity mode
    if (!Config::Analysis::complexity())
    {
        // What should we do here?
        // print_result(res);
    }

    if (its_model)
    {
        // TODO
    }
    else if (its_cex)
    {
        // TODO
    }
    // yices::exit();
    return LoatResult::UKNOWN;
}