target_sources(${EXECUTABLE}
    PRIVATE
    bmc.hpp
    bmc.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
