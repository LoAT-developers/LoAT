target_sources(${EXECUTABLE}
    PRIVATE
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
        boolvar.cpp
        boolvar.hpp
        boollit.cpp
        boollit.hpp
        subs.cpp
        subs.hpp
        boolsubs.cpp
        boolsubs.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
