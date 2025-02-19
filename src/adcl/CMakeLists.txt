target_sources(${EXECUTABLE}
    PRIVATE
        redundanceviaautomata.hpp
        redundanceviaautomata.cpp
        adcl.hpp
        adcl.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
