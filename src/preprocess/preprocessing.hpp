#pragma once

#include "itsproblem.hpp"
#include "itsmodel.hpp"
#include "itscex.hpp"
#include "smt.hpp"
#include "chain.hpp"

class Preprocessor {

private:
    bool success{false};

    SmtResult status{SmtResult::Unknown};

    ITSPtr its;

    Chain chain;

public:
    Preprocessor(ITSPtr its);

    ITSModel transform_model(const ITSModel &) const;

    ITSCex transform_cex(const ITSCex &) const;

    SmtResult preprocess();

    bool successful() const;

    ITSModel get_model() const;

};
