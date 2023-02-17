target_sources(${EXECUTABLE}
    PRIVATE
        chain.cpp
        chain.hpp
        chainstrategy.cpp
        chainstrategy.hpp
        guardtoolbox.hpp
        guardtoolbox.cpp
        preprocess.cpp
        preprocess.hpp
        reachability.hpp
        reachability.cpp
        satisfiability.cpp
        satisfiability.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
