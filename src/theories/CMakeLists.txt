target_sources(${EXECUTABLE}
    PRIVATE
        theory.hpp
        inttheory.hpp
        booltheory.hpp
        theoryutils.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
