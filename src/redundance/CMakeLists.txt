target_sources(${EXECUTABLE}
    PRIVATE
        redundanceviaautomata.hpp
        redundanceviaautomata.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
