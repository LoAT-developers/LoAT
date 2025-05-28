target_sources(${EXECUTABLE}
    PRIVATE
    imc.hpp
    imc.cpp
    imcsafety.hpp
    imcsafety.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
