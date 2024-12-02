cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)

project(sexpresso CXX)

add_library(${PROJECT_NAME} OBJECT
    sexpresso.hpp
    sexpresso.cpp
)

target_include_directories(${PROJECT_NAME} INTERFACE ".")

# Expose public includes to other
# subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
