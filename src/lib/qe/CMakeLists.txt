cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)

project(loat_qe CXX)

add_library(${PROJECT_NAME} STATIC
  redlog.cpp
  redlog.hpp
  qelim.hpp
  qecalculus.hpp
  redlogLexer.cpp
  redlogLexer.h
  redlogListener.cpp
  redlogListener.h
  redlogParser.cpp
  redlogParser.h
  redlogparsevisitor.cpp
  redlogparsevisitor.h
  redlogVisitor.cpp
  redlogVisitor.h
  qelimfactory.hpp
  vareliminator.hpp
  vareliminator.cpp
)

set(REDUCE ${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/libreduce.a)
message(STATUS "reduce: ${REDUCE}")

target_include_directories(${PROJECT_NAME} PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/../../../../reduce-algebra/generic/libreduce/src/"
  ${loat_util_INCLUDE_DIRS}
  ${loat_expr_INCLUDE_DIRS}
  ${loat_smt_INCLUDE_DIRS}
  ${ANTLR4_INCLUDE_DIRS}
)

target_include_directories(${PROJECT_NAME} INTERFACE ".")

target_link_libraries(${PROJECT_NAME}
  loat_expr
  loat_smt
  ${REDUCE}
  ${ANTLR4})

# Expose public includes to other
# subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
