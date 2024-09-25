target_sources(${EXECUTABLE}
    PRIVATE
        preprocessing.cpp
        preprocessing.hpp
        chain.cpp
        chain.hpp
        rulepreprocessor.hpp
        rulepreprocessor.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
