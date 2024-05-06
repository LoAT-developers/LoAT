cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)

project(loat_smt CXX)

message(STATUS "loat_expr includes: ${loat_expr_INCLUDE_DIRS}")

add_library(${PROJECT_NAME} OBJECT
  smt.hpp
  z3.hpp
  z3.cpp
  z3context.cpp
  z3context.hpp
  yices.hpp
  yices.cpp
  yicescontext.cpp
  yicescontext.hpp
  cvc5.hpp
  cvc5.cpp
  cvc5context.hpp
  cvc5context.cpp
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
