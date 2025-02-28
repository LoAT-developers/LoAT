add_subdirectory(lib)
add_subdirectory(preprocess)
add_subdirectory(interleaved)
add_subdirectory(adcl)
add_subdirectory(asymptotic)
add_subdirectory(parser)
add_subdirectory(abmc)
add_subdirectory(trl)
add_subdirectory(adclsat)
add_subdirectory(bmc)


target_sources(${Loat_API} PRIVATE trputil.cpp)
target_include_directories(${Loat_API} PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

target_sources(${EXECUTABLE}
    PRIVATE
        main.cpp
        version.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

