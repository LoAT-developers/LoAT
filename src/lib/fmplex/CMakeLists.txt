cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)

project(loat_fmplex CXX)

add_library(${PROJECT_NAME} OBJECT
  eliminate.h
  eliminate.cpp
  fmplex.h
  fmplex.cpp
  Matrix.h
  Node.h
)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${loat_expr_INCLUDE_DIRS}
  ${loat_container_INCLUDE_DIRS}
  ${loat_util_INCLUDE_DIRS}
)

# Expose public includes to other
# subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
