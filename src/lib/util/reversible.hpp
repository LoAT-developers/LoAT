#pragma once

template <class Result, class From, class To>
class Reversible {

protected:

    Result res;

public:

    Reversible(const Result &res): res(res) {};

    virtual To revert_model(const From&) const = 0;

    const Result& operator*() const {
        return res;
    }

};
