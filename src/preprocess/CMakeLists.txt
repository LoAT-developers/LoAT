target_sources(${EXECUTABLE}
    PRIVATE
        preprocessing.cpp
        preprocessing.hpp
        chain.cpp
        chain.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
