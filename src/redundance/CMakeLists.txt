target_sources(${EXECUTABLE}
    PRIVATE
        redundance.hpp
        redundanceviasquarefreewords.hpp
        redundanceviasquarefreewords.cpp
        redundanceviaautomata.hpp
        redundanceviaautomata.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
