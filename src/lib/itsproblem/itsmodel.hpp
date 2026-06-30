#pragma once

#include "itsproblem.hpp"

class ITSModel {

    friend std::ostream& operator<<(std::ostream &, const ITSModel &);

    ITSPtr m_its;
    unsigned m_k;

public:

    ITSModel(ITSPtr, unsigned);

};
