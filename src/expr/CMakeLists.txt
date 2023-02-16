target_sources(${EXECUTABLE}
    PRIVATE
        complexity.cpp
        complexity.hpp
        guardtoolbox.cpp
        guardtoolbox.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
