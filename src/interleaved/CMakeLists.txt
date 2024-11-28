target_sources(${EXECUTABLE}
    PRIVATE
    interleaved.hpp
    interleaved.cpp
    stepwise.hpp
    stepwise.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
