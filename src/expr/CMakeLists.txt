target_sources(${EXECUTABLE}
    PRIVATE
        complexity.cpp
        complexity.hpp
        numvar.hpp
        numvar.cpp
        expression.cpp
        expression.hpp
        rel.cpp
        rel.hpp
        guardtoolbox.cpp
        guardtoolbox.hpp
        boolexpr.cpp
        boolexpr.hpp
        boolvar.cpp
        boolvar.hpp
        boollit.cpp
        boollit.hpp
        boolsubs.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
