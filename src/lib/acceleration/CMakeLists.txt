cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)

project(loat_acceleration CXX)

add_library(${PROJECT_NAME} STATIC
  rule.hpp
  rule.cpp
  accelerationtechnique.hpp
  accelerationfactory.hpp
  accelerationfactory.cpp
  accelconfig.hpp
  accelerationproblem.cpp
  accelerationproblem.hpp
  approx.hpp
  loopacceleration.cpp
  loopacceleration.hpp
  accelerationresult.hpp
  accelerationresult.cpp
  chain.hpp
  chain.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${loat_util_INCLUDE_DIRS}
  ${loat_expr_INCLUDE_DIRS}
  ${loat_smt_INCLUDE_DIRS}
  ${loat_recurrence_INCLUDE_DIRS}
)

target_include_directories(${PROJECT_NAME} INTERFACE ".")

target_link_libraries(${PROJECT_NAME}
  loat_expr
  loat_smt
  loat_recurrence)

# Expose public includes to other
# subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
