target_sources(${EXECUTABLE}
    PRIVATE
        chainstrategy.cpp
        chainstrategy.hpp
        guardtoolbox.hpp
        guardtoolbox.cpp
        preprocess.cpp
        preprocess.hpp
        reachability.hpp
        reachability.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
