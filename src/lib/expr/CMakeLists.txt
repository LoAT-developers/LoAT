cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)

project(loat_expr CXX)

add_library(${PROJECT_NAME} STATIC
  itheory.hpp
  thset.hpp
  subs.hpp
  boolvar.hpp
  boolvar.cpp
  boollit.hpp
  boollit.cpp
  literal.hpp
  numvar.cpp
  arithexpr.cpp
  arithexpr.hpp
  arithlit.cpp
  arithlit.hpp
  conjunction.hpp
  boolexpr.hpp
  arith.hpp
  arith.cpp
  bools.hpp
  bools.cpp
  boolsubs.hpp
  theories.hpp
  theories.cpp
  theory.hpp
  theory.cpp
  arithsubs.hpp
  arithsubs.cpp
  numconstant.cpp
  exp.cpp
  mult.cpp
  add.cpp
  arithutil.hpp
  arithutil.cpp
)

find_library(GINAC ginac)
message(STATUS "ginac: ${GINAC}")

target_link_libraries(${PROJECT_NAME} ${GINAC})

target_include_directories(${PROJECT_NAME} PRIVATE
  ${loat_util_INCLUDE_DIRS}
)

target_include_directories(${PROJECT_NAME} INTERFACE
  ${loat_util_INCLUDE_DIRS}
  "."
)

# Expose public includes to other
# subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
