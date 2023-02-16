#pragma once

#include <string>
#include <set>
#include <map>

class BoolVar
{

    std::string name;

public:

    BoolVar(const std::string &name);
    std::string getName() const;
    std::string get_name() const;
    size_t hash() const;
    bool equals(const BoolVar &that) const;
    int compare(const BoolVar &that) const;

};

bool operator ==(const BoolVar &v1, const BoolVar &v2);

bool operator <(const BoolVar &v1, const BoolVar &v2);

std::ostream& operator<<(std::ostream &s, const BoolVar &e);
