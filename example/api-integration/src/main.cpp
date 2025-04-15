#include <iostream>
#include "loatconfig.hpp"
#include "loatsolver.hpp"
#include "loatintexpr.hpp"
#include <any>
#include <stdexcept>

int main()
{
    LoatConfig::InitialConfig initialConfig1(
        LoatConfig::InitialConfig::Format::Koat,
        LoatConfig::InitialConfig::Engine::ADCL,
        LoatConfig::InitialConfig::Mode::Complexity,
        LoatConfig::InitialConfig::SmtSolver::Z3,
        LoatConfig::InitialConfig::Direction::Forward,
        LoatConfig::InitialConfig::MbpKind::IntMbp,
        false);

    LoatConfig config1(initialConfig1);

    LoatSolver solver1(config1);

    solver1.setParameter(DynamicParameterKey::Log, true);
    solver1.refreshConfig();

    LoatIntExprPtr five = LoatIntExpression::mkConst(Rational(5));
    LoatIntExprPtr x = LoatIntExpression::mkVar("x");
    LoatIntExprPtr ten = LoatIntExpression::mkConst(Rational(10));

    LoatIntExprPtr fivex = LoatIntExpression::mkTimes({five, x});
    LoatIntExprPtr fivexplusten = LoatIntExpression::mkPlus(fivex, ten);

    std::cout << fivexplusten << std::endl;

    solver1.add(fivexplusten);

    return 0;
}