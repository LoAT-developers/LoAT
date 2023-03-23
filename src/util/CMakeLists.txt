target_sources(${EXECUTABLE}
    PRIVATE
        result.hpp
        itsproof.hpp
        itsproof.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
