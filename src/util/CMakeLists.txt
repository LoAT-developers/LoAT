target_sources(${EXECUTABLE}
    PRIVATE
        approx.hpp
        proof.hpp
        proof.cpp
        relevantvariables.hpp
        result.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
