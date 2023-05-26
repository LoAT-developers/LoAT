cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)

project(loat_recurrence CXX)

add_library(${PROJECT_NAME} STATIC
  recurrence.hpp
  recurrence.cpp
  dependencyorder.hpp
  dependencyorder.cpp
)

find_library(GINAC ginac)
message(STATUS "ginac: ${GINAC}")
find_library(PURRS purrs)
message(STATUS "purrs: ${PURRS}")
find_library(NTL ntl)
message(STATUS "ntl: ${NTL}")
find_library(CLN cln)
message(STATUS "cln: ${CLN}")
find_library(GMP gmp)
message(STATUS "gmp: ${GMP}")

target_include_directories(${PROJECT_NAME} PRIVATE ${loat_expr_INCLUDE_DIRS})

target_include_directories(${PROJECT_NAME} INTERFACE ".")

target_link_libraries(${PROJECT_NAME}
  ${PURRS}
  ${GINAC}
  ${NTL}
  ${CLN}
  ${GMP}
  loat_expr
)

# Expose public includes to other
# subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
