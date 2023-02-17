target_sources(${EXECUTABLE}
    PRIVATE
        approx.hpp
        relevantvariables.hpp
        result.hpp
        itsproof.hpp
        itsproof.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
