#pragma once

#include "itsproblem.hpp"
#include "itsmodel.hpp"
#include "itscex.hpp"

class AbstractITSPreprocessor {

protected:

    ITSPtr its;

public:
    explicit AbstractITSPreprocessor(ITSPtr);
    virtual ~AbstractITSPreprocessor() = default;
    virtual ITSPtr process() = 0;
    virtual ITSModel transform_model(const ITSModel&) const = 0;
    virtual std::shared_ptr<ITSCex> transform_cex(std::shared_ptr<ITSCex>) const = 0;

};

class ITSPreprocessor : public AbstractITSPreprocessor {

    std::vector<std::unique_ptr<AbstractITSPreprocessor>> procs;

public:

    explicit ITSPreprocessor(const ITSPtr& its);
    ITSPtr process() override;
    ITSModel transform_model(const ITSModel&) const override;
    std::shared_ptr<ITSCex> transform_cex(std::shared_ptr<ITSCex>) const override;
};
