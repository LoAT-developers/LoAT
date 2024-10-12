target_sources(${EXECUTABLE}
    PRIVATE
    til.hpp
    til.cpp
    interleaved.hpp
    interleaved.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
