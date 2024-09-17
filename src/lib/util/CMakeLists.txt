cmake_minimum_required(VERSION 3.13)

project(loat_util CXX)

add_library(${PROJECT_NAME} OBJECT
    vector.hpp
    variant.hpp
    conshash.hpp
    config.cpp
    config.hpp
    pair.hpp
    optional.hpp
    string.hpp
    notnull.hpp
)

target_include_directories(${PROJECT_NAME} INTERFACE ".")

# Expose public includes to other
# subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
