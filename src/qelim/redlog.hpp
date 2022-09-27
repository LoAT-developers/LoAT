#ifndef REDLOG_HPP
#define REDLOG_HPP

extern "C" {
    #include <reduce.h>
}
#include "boolexpr.hpp"
#include "variablemanager.hpp"
#include "qelim.hpp"

class Redlog: Qelim {

    static RedProc process();
    VariableManager &varMan;

public:

    Redlog(VariableManager &varMan): varMan(varMan){}

    option<Qelim::Result> qe(const QuantifiedFormula &qf) override;
    static void init();
    static void exit();

};

#endif
