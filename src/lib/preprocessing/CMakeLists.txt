cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)

project(loat_preprocessing CXX)

add_library(${PROJECT_NAME} OBJECT
  formulapreprocessing.hpp
  formulapreprocessing.cpp
  vareliminator.hpp
  vareliminator.cpp
  redundantinequations.hpp
  redundantinequations.cpp
  impliedequivalences.hpp
  impliedequivalences.cpp
  realmbp.hpp
  realmbp.cpp
  intmbp.hpp
  intmbp.cpp
  mbputil.hpp
  mbputil.cpp
  intfm.hpp
  intfm.cpp
  realqe.hpp
  realqe.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${loat_util_INCLUDE_DIRS}
  ${loat_container_INCLUDE_DIRS}
  ${loat_expr_INCLUDE_DIRS}
  ${loat_smt_INCLUDE_DIRS}
  ${loat_fmplex_INCLUDE_DIRS}
)

target_include_directories(${PROJECT_NAME} INTERFACE ".")

# Expose public includes to other
# subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
