target_sources(${EXECUTABLE}
    PRIVATE
        preprocessing.cpp
        preprocessing.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
