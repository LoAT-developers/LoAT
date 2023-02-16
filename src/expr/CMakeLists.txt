target_sources(${EXECUTABLE}
    PRIVATE
        complexity.cpp
        complexity.hpp
        guardtoolbox.cpp
        guardtoolbox.hpp
        boolsubs.hpp
        literal.cpp
        literal.hpp
        expression.hpp
        expression.cpp
        substitution.hpp
        substitution.cpp
        boolexpression.hpp
        boolexpression.cpp
        variable.hpp
        variable.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
