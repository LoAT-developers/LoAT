#pragma once

#include "itsproblem.hpp"
#include "til.hpp"

class Interleaved {

private:

TIL f;
TIL b;
TIL *active;
TIL *passive;

public:

    Interleaved(const ITSPtr f, const ITSPtr b, const Config::TILConfig &f_conf, const Config::TILConfig &b_conf);

    SmtResult analyze();

    ITSModel get_model();

    ITSSafetyCex get_cex();

    bool is_forward() const;

};
