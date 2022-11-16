add_subdirectory(z3)
add_subdirectory(yices)
add_subdirectory(cvc)

target_sources(${EXECUTABLE}
    PRIVATE
        smt.hpp
        smtcontext.hpp
        exprtosmt.hpp
        smtfactory.hpp
        model.hpp
        combined_solver.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
