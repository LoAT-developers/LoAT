add_subdirectory(lib)
add_subdirectory(its)
add_subdirectory(analysis)
add_subdirectory(asymptotic)
add_subdirectory(parser)
add_subdirectory(util)
add_subdirectory(redundance)
add_subdirectory(abmc)
add_subdirectory(bmc)

target_sources(${EXECUTABLE}
    PRIVATE
        main.cpp
        main.hpp
        version.cpp
        version.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
