target_sources(${EXECUTABLE}
    PRIVATE
        theory.hpp
        theory.cpp
        inttheory.hpp
        booltheory.hpp
        theoryutils.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
