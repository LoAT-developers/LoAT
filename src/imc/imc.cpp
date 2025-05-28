#include "imc.hpp"
#include "config.hpp"
#include "smtfactory.hpp"
#include "opensmt.hpp"

#include <stdexcept>

IMC::IMC(const ITSPtr its) : its2safety(its), imc(its2safety.transform()) {}

std::optional<SmtResult> IMC::do_step() {
    return imc.do_step();
}

ITSModel IMC::get_model() {
    throw std::runtime_error("not yet implemented");
}

ITSSafetyCex IMC::get_cex() {
    throw std::runtime_error("not yet implemented");
}
