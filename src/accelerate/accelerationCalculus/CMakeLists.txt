target_sources(${EXECUTABLE}
    PRIVATE
        accelerationproblem.cpp
        accelerationproblem.hpp
        rankingfunctionproblem.cpp
        rankingfunctionproblem.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
