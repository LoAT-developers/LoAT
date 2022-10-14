target_sources(${EXECUTABLE}
    PRIVATE
        z3.hpp
        z3context.cpp
        z3context.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
