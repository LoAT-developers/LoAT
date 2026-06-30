#pragma once

#include "theory.hpp"
#include "chcproblem.hpp"
#include "sexpresso.hpp"

class CHCModel {

    friend std::ostream& operator<<(std::ostream&, const CHCModel&);

    CHCPtr m_chcs;
    unsigned m_k;

public:

    CHCModel(CHCPtr, unsigned);

};