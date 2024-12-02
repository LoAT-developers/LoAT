add_subdirectory(lib)
add_subdirectory(preprocess)
add_subdirectory(interleaved)
add_subdirectory(adcl)
add_subdirectory(asymptotic)
add_subdirectory(parser)
add_subdirectory(abmc)
add_subdirectory(trl)
add_subdirectory(bmc)

target_sources(${EXECUTABLE}
    PRIVATE
        main.cpp
        main.hpp
        version.cpp
        version.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
