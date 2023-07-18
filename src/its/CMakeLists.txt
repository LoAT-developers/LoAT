target_sources(${EXECUTABLE}
    PRIVATE
        export.cpp
        export.hpp
        itsproblem.cpp
        itsproblem.hpp
        types.hpp
        dependencygraph.hpp
        dependencygraph.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
