#pragma once

#include <string>

class BoolVar
{

    std::string name;

public:

    BoolVar(const std::string &name);
    std::string toString() const;
    size_t hash() const;

};
