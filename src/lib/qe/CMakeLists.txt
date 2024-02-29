cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)

project(loat_qe CXX)

add_library(${PROJECT_NAME} STATIC
  vareliminator.hpp
  vareliminator.cpp
  impliedequalities.cpp
  impliedequalities.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${loat_expr_INCLUDE_DIRS}
)

target_include_directories(${PROJECT_NAME} INTERFACE ".")

target_link_libraries(${PROJECT_NAME}
  loat_expr)

# Expose public includes to other
# subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
