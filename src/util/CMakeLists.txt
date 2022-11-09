target_sources(${EXECUTABLE}
    PRIVATE
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
        relevantvariables.hpp
        result.hpp
        map.hpp
        vector.hpp
        variant.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
