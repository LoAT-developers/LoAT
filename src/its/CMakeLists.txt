target_sources(${EXECUTABLE}
    PRIVATE
        cintegerexport.cpp
        cintegerexport.hpp
        export.cpp
        export.hpp
        hypergraph.hpp
        itsproblem.cpp
        itsproblem.hpp
        rule.cpp
        rule.hpp
        types.hpp
        guard.cpp
        guard.hpp
        variablemanager.cpp
        variablemanager.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
