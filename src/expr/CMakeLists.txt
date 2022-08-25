target_sources(${EXECUTABLE}
    PRIVATE
        boundedness.hpp
        boundedness.cpp
        complexity.cpp
        complexity.hpp
        expression.cpp
        expression.hpp
        rel.cpp
        rel.hpp
        guardtoolbox.cpp
        guardtoolbox.hpp
        boolexpr.cpp
        boolexpr.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
