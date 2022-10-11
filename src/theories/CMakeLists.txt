target_sources(${EXECUTABLE}
    PRIVATE
        theory.hpp
        inttheory.hpp
        booltheory.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
