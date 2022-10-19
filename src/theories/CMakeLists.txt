target_sources(${EXECUTABLE}
    PRIVATE
        theory.hpp
        theory.cpp
        inttheory.hpp
        booltheory.hpp
        thset.hpp
        subs.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
