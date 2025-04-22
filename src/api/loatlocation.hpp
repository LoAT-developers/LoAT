#pragma once

#include <string>

class LoatLocation
{
private:
    std::string m_name;

public:
    explicit LoatLocation(const std::string &name) : m_name(name) {}

    const std::string &getName() const { return m_name; }

    bool operator==(const LoatLocation &other) const
    {
        return m_name == other.m_name;
    }

    friend std::ostream &operator<<(std::ostream &os, const LoatLocation &loc)
    {
        os << loc.m_name;
        return os;
    }
};