target_sources(${EXECUTABLE}
    PRIVATE
    nonlinear.hpp
    nonlinear.cpp
    clause.hpp
    clause.cpp
    linearsolver.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
