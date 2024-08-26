target_sources(${EXECUTABLE}
    PRIVATE
        redundanceviaautomata.hpp
        redundanceviaautomata.cpp
        reachability.hpp
        reachability.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
