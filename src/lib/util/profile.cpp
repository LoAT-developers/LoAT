#include "profile.hpp"
#include "config.hpp"

#include <iostream>

Profile::Profile(const std::string& what): m_start(std::chrono::steady_clock::now()), m_what(what) {}

void Profile::end() const {
    if (Config::Analysis::profile) {
        std::cout << m_what << ": " << std::chrono::duration_cast<std::chrono::milliseconds> (std::chrono::steady_clock::now() - m_start).count() << "[ms]" << std::endl;
    }
}