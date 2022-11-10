add_subdirectory(its)
add_subdirectory(expr)
add_subdirectory(accelerate)
add_subdirectory(analysis)
add_subdirectory(asymptotic)
add_subdirectory(parser)
add_subdirectory(util)
add_subdirectory(smt)
add_subdirectory(merging)
add_subdirectory(qelim)
add_subdirectory(concepts)
add_subdirectory(theories)
add_subdirectory(redundance)

target_sources(${EXECUTABLE}
    PRIVATE
        config.cpp
        config.hpp
        main.cpp
        main.hpp
        version.cpp
        version.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
