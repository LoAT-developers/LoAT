cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)

project(loat_smt CXX)

add_library(${PROJECT_NAME} OBJECT
  smt.hpp
  smt.cpp
  yices.hpp
  yices.cpp
  yicescontext.cpp
  yicescontext.hpp
  swine.hpp
  swine.cpp
  swinecontext.hpp
  swinecontext.cpp
  smtfactory.hpp
  smtfactory.cpp
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
