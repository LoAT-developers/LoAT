target_sources(${EXECUTABLE}
    PRIVATE
        yices.cpp
        yices.hpp
        yicescontext.cpp
        yicescontext.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
