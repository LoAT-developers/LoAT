target_sources(${EXECUTABLE}
    PRIVATE
        yices.hpp
        yices.cpp
        yicescontext.cpp
        yicescontext.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
