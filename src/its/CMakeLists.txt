target_sources(${EXECUTABLE}
    PRIVATE
        export.cpp
        export.hpp
        itsproblem.cpp
        itsproblem.hpp
        rule.cpp
        rule.hpp
        types.hpp
        dependencygraph.hpp
        dependencygraph.cpp
        chain.hpp
        chain.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
