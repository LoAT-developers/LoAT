target_sources(${EXECUTABLE}
    PRIVATE
    sabmc.hpp
    sabmc.cpp
    safetyproblem.cpp
    safetyproblem.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
