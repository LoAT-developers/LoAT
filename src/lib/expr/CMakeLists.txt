cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)

project(loat_expr CXX)

add_library(${PROJECT_NAME} OBJECT
  itheory.hpp
  subs.hpp
  subs.cpp
  boollit.hpp
  boollit.cpp
  arithexpr.cpp
  arithexpr.hpp
  arithlit.cpp
  arithlit.hpp
  conjunction.hpp
  conjunction.cpp
  boolexpr.hpp
  boolexpr.cpp
  booltheorylit.cpp
  booljunction.cpp
  arith.hpp
  arith.cpp
  bools.hpp
  bools.cpp
  boolsubs.hpp
  boolsubs.cpp
  theory.hpp
  theory.cpp
  arithsubs.hpp
  arithsubs.cpp
  arithconstant.cpp
  exp.cpp
  mult.cpp
  add.cpp
  mod.cpp
  model.hpp
  model.cpp
  exprconverter.hpp
  exprconversioncontext.hpp
  renaming.hpp
  renaming.cpp
  var.hpp
  exprfwd.hpp
  arraytype.hpp
  arraytype.cpp
  type.hpp
  type.cpp
  visit.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${sexpresso_INCLUDE_DIRS}
  ${loat_util_INCLUDE_DIRS}
  ${loat_container_INCLUDE_DIRS}
)

target_include_directories(${PROJECT_NAME} INTERFACE
  ${sexpresso_INCLUDE_DIRS}
  ${loat_util_INCLUDE_DIRS}
  ${loat_container_INCLUDE_DIRS}
  "."
)

# Expose public includes to other
# subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR} ${sexpresso_INCLUDE_DIRS}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
