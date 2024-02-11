target_sources(${EXECUTABLE}
    PRIVATE
        preprocessing.cpp
        preprocessing.hpp
        reachability.hpp
        reachability.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
