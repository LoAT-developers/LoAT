#pragma once

#include <chrono>

class Profile {
    std::chrono::time_point<std::chrono::steady_clock> m_start;
    const std::string m_what;

public:

    explicit Profile(const std::string& what);

    void end() const;

};
