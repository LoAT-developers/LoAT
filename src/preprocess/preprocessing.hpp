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
    virtual bool process() = 0;
    virtual ITSModel transform_model(const ITSModel &) const = 0;
    virtual std::shared_ptr<ITSCex> transform_cex(const std::shared_ptr<ITSCex> &cex) const = 0;

};

class ITSPreprocessor : public AbstractITSPreprocessor {

    std::vector<std::unique_ptr<AbstractITSPreprocessor>> procs;

public:

    explicit ITSPreprocessor(const ITSPtr& its);
    bool process() override;
    ITSModel transform_model(const ITSModel &m) const override;
    std::shared_ptr<ITSCex> transform_cex(const std::shared_ptr<ITSCex> &cex) const override;
};
