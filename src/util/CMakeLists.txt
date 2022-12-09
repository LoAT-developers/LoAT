target_sources(${EXECUTABLE}
    PRIVATE
        approx.hpp
        option.hpp
        proof.hpp
        proof.cpp
        status.hpp
        farkas.cpp
        farkas.hpp
        templates.cpp
        templates.hpp
        relevantvariables.hpp
        result.hpp
        map.hpp
        set.hpp
        vector.hpp
        variant.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
