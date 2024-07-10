target_sources(${EXECUTABLE}
    PRIVATE
    til.hpp
    til.cpp
    safetyproblem.cpp
    safetyproblem.hpp
    forwardbackwarddriver.hpp
    forwardbackwarddriver.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
