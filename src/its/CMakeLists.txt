target_sources(${EXECUTABLE}
    PRIVATE
        export.cpp
        export.hpp
        hypergraph.hpp
        itsproblem.cpp
        itsproblem.hpp
        rule.cpp
        rule.hpp
        types.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
