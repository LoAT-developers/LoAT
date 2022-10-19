#include "variable.hpp"

namespace variable {

std::string getName(const Var &var) {
    return std::visit([](const auto &var){return var.getName();}, var);
}

}

std::ostream& operator<<(std::ostream &s, const Var &e) {
    std::visit([&s](const auto &e){s << variable::getName(e);}, e);
    return s;
}
