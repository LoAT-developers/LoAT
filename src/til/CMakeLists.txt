target_sources(${EXECUTABLE}
    PRIVATE
    til.hpp
    til.cpp
    safetyproblem.cpp
    safetyproblem.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
