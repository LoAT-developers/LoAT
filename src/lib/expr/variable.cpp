#include "variable.hpp"

namespace variable {

std::string getName(const Var &var) {
    return std::visit([](const auto &var){return var.getName();}, var);
}

bool isTempVar(const Var &var) {
    return std::visit([](const auto &var){return var.isTempVar();}, var);
}

bool isProgVar(const Var &var) {
    return !isTempVar(var);
}

Var next(const Var &var) {
    return std::visit(Overload{
                          [](const NumVar&) {
                              return Var(NumVar::next());
                          },
                          [](const BoolVar&) {
                              return Var(BoolVar::next());
                          }
                      }, var);
}

}

std::ostream& operator<<(std::ostream &s, const Var &e) {
    std::visit([&s](const auto &e){s << variable::getName(e);}, e);
    return s;
}
