target_sources(${EXECUTABLE}
    PRIVATE
        limitsmt.cpp
        limitsmt.hpp
        complexity.cpp
        complexity.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
