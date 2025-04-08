#include <iostream>
#include "loatconfig.hpp"
#include "loatsolver.hpp"
#include "loatexpression.hpp"
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

    LoatExprPtr five = LoatExpression::mkConst(Rational(5));
    LoatExprPtr x = LoatExpression::mkVar(1);
    LoatExprPtr ten = LoatExpression::mkConst(Rational(10));

    LoatExprPtr fivex = LoatExpression::mkTimes({five, x});
    LoatExprPtr fivexplusten = LoatExpression::mkPlus(fivex, ten);

    std::cout << fivexplusten << std::endl;

    solver1.add(fivexplusten);

    return 0;
}