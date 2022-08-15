target_sources(${EXECUTABLE}
    PRIVATE
        exceptions.hpp
        option.hpp
        proof.hpp
        proof.cpp
        timeout.cpp
        timeout.hpp
        status.hpp
        farkas.cpp
        farkas.hpp
        templates.cpp
        templates.hpp
        relevantvariables.cpp
        relevantvariables.hpp
        result.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
