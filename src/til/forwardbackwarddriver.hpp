#pragma once

#include "itsproblem.hpp"
#include "til.hpp"

class ForwardBackwardDriver {

private:

TIL f;
TIL b;
TIL *active;
TIL *passive;

public:

    ForwardBackwardDriver(const ITSPtr forward, const ITSPtr backward);

    SmtResult analyze();

    ITSModel get_model();

    ITSSafetyCex get_cex();

    bool is_forward() const;

};
