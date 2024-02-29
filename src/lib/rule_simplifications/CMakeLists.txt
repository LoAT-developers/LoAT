cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)

project(loat_rule_simplifications CXX)

add_library(${PROJECT_NAME} STATIC
  rule.hpp
  rule.cpp
  chain.hpp
  chain.cpp
  ruleproof.hpp
  ruleproof.cpp
  ruleresult.hpp
  ruleresult.cpp
  ruleexport.hpp
  ruleexport.cpp
  guardtoolbox.hpp
  guardtoolbox.cpp
  rulepreprocessing.cpp
  rulepreprocessing.hpp
  transition.hpp
  transition.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${loat_util_INCLUDE_DIRS}
  ${loat_expr_INCLUDE_DIRS}
  ${loat_qe_INCLUDE_DIRS}
)

target_include_directories(${PROJECT_NAME} INTERFACE ".")

target_link_libraries(${PROJECT_NAME}
  loat_expr
  loat_qe)

# Expose public includes to other
# subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
