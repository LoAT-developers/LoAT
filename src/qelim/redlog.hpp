#pragma once

extern "C" {
    #include <reduce.h>
}
#include "inttheory.hpp"
#include "variablemanager.hpp"
#include "qelim.hpp"

class Redlog: Qelim<IntTheory> {

    static RedProc process();
    VariableManager &varMan;

public:

    Redlog(VariableManager &varMan): varMan(varMan){}

    std::optional<typename Qelim<IntTheory>::Result> qe(const QuantifiedFormula<IntTheory> &qf) override;
    static void init();
    static void exit();

};
