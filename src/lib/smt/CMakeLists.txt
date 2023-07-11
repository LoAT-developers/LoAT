cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)

project(loat_smt CXX)

message(STATUS "loat_expr includes: ${loat_expr_INCLUDE_DIRS}")

add_library(${PROJECT_NAME} STATIC
  smt.hpp
  smtcontext.hpp
  exprtosmt.hpp
  model.hpp
  linearizingsolver.hpp
  z3.hpp
  z3_opt.hpp
  z3context.cpp
  z3context.hpp
  yices.hpp
  yices.cpp
  yicescontext.cpp
  yicescontext.hpp
  smtfactory.hpp
  smtfactory.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${loat_expr_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} INTERFACE ".")

target_link_libraries(${PROJECT_NAME} loat_expr)

message(STATUS "Searching libraries")
find_library(Z3 z3)
message(STATUS "z3: ${Z3}")
find_library(YICES yices)
message(STATUS "yices: ${YICES}")
find_library(POLY poly)
message(STATUS "poly: ${POLY}")
find_library(CUDD cudd)
message(STATUS "cudd: ${CUDD}")

target_link_libraries(
    ${PROJECT_NAME}
    ${Z3}
    ${YICES}
    ${POLY}
    ${CUDD}
)

# Expose public includes to other
# subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
