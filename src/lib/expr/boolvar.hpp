#pragma once

#include <string>
#include <set>
#include <map>

class BoolVar
{

    std::string name;

    friend auto operator<=>(const BoolVar &x, const BoolVar &y) = default;

public:

    BoolVar(const std::string &name);
    std::string getName() const;

};

std::ostream& operator<<(std::ostream &s, const BoolVar &e);
