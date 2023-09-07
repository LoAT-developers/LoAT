target_sources(${EXECUTABLE}
    PRIVATE
        export.cpp
        export.hpp
        itsproblem.cpp
        itsproblem.hpp
        types.hpp
        dependencygraph.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
