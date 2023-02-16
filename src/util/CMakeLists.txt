target_sources(${EXECUTABLE}
    PRIVATE
        approx.hpp
        proof.hpp
        proof.cpp
        status.hpp
        relevantvariables.hpp
        result.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
