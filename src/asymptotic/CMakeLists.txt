target_sources(${EXECUTABLE}
    PRIVATE
        asymptoticbound.cpp
        asymptoticbound.hpp
        inftyexpression.cpp
        inftyexpression.hpp
        limitproblem.cpp
        limitproblem.hpp
        limitsmt.cpp
        limitsmt.hpp
        limitvector.cpp
        limitvector.hpp
        complexity.cpp
        complexity.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
