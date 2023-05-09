target_sources(${EXECUTABLE}
    PRIVATE
        guardtoolbox.hpp
        guardtoolbox.cpp
        preprocessing.cpp
        preprocessing.hpp
        rulepreprocessing.cpp
        rulepreprocessing.hpp
        reachability.hpp
        reachability.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
