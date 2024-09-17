#pragma once

#include "itsproblem.hpp"
#include "itsmodel.hpp"
#include "smt.hpp"
#include "chain.hpp"

class Preprocessor {

private:
    bool success{false};

    SmtResult status{SmtResult::Unknown};

    ITSProblem &its;

    Chain chain;

public:
    Preprocessor(ITSProblem &its);

    ITSModel transform_model(const ITSModel &) const;

    SmtResult preprocess();

    bool successful() const;

    ITSModel get_model() const;

};
