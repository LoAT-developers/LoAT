add_subdirectory(z3)
add_subdirectory(yices)

target_sources(${EXECUTABLE}
    PRIVATE
        smt.hpp
        smt.cpp
        smtcontext.hpp
        exprtosmt.hpp
        smtfactory.cpp
        smtfactory.hpp
        model.cpp
        model.hpp
        combined_solver.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
