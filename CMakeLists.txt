cmake_minimum_required(VERSION 3.13)

project(LoAT)

set(CMAKE_CXX_STANDARD 20)

# non-static build by default
option(STATIC "static" ON)
option(SANITIZE "sanitize" OFF)

set(CMAKE_FIND_LIBRARY_SUFFIXES .a)
set(CMAKE_LIBRARY_PATH $ENV{LD_LIBRARY_PATH})

add_link_options(-pthread)

if(${STATIC})
    message(STATUS "Configuring static build")
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
    set(BUILD_SHARED_LIBS OFF)
    add_link_options(-ldl -static)
    set(EXECUTABLE loat-static)
else()
  set(CMAKE_FIND_LIBRARY_SUFFIXES ".so" ".a")
  message(STATUS "Configuring non-static build")
  set(EXECUTABLE loat)
endif()

if(${SANITIZE})
    message(STATUS "Sanitizer enabled")
    add_link_options(-fsanitize=undefined)
    add_compile_options(-fsanitize=undefined)
endif()

add_compile_options(-Wall -Wextra -pedantic -Wno-unused-parameter -fconcepts-diagnostics-depth=100)

set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELEASE} -g")

message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})
message(STATUS "Compiler flags:" ${CMAKE_CXX_COMPILE_FLAGS})
message(STATUS "Compiler cxx debug flags:" ${CMAKE_CXX_FLAGS_DEBUG})
message(STATUS "Compiler cxx release flags:" ${CMAKE_CXX_FLAGS_RELEASE})
message(STATUS "Compiler cxx relwithdebinfo flags:" ${CMAKE_CXX_FLAGS_RELWITHDEBINFO})
message(STATUS "Compiler cxx min size flags:" ${CMAKE_CXX_FLAGS_MINSIZEREL})
message(STATUS "Compiler cxx flags:" ${CMAKE_CXX_FLAGS})

find_library(ANTLR4 antlr4-runtime)
message(STATUS "antlr4: ${ANTLR4}")
find_library(FAUDES faudes)
message(STATUS "faudes: ${FAUDES}")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC SHA)
git_local_changes(DIRTY)

# generate version.cc
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/version.cpp.in" "${CMAKE_CURRENT_SOURCE_DIR}/src/version.cpp" @ONLY)

add_executable(${EXECUTABLE} "")
add_subdirectory(src)

target_include_directories(${EXECUTABLE} PRIVATE
  ${loat_util_INCLUDE_DIRS}
  ${loat_container_INCLUDE_DIRS}
  ${loat_expr_INCLUDE_DIRS}
  # ${loat_crab_INCLUDE_DIRS}
  ${loat_rule_simplification_INCLUDE_DIRS}
  ${loat_smt_INCLUDE_DIRS}
  ${loat_formula_simplification_INCLUDE_DIRS}
  ${loat_recurrence_INCLUDE_DIRS}
  ${loat_acceleration_INCLUDE_DIRS}
  ${loat_its_INCLUDE_DIRS}
)

message(STATUS "Searching libraries")
find_library(Z3 z3)
message(STATUS "z3: ${Z3}")
find_library(YICES yices)
message(STATUS "yices: ${YICES}")
find_library(POLY poly)
message(STATUS "poly: ${POLY}")
find_library(POLYXX polyxx)
message(STATUS "polyxx: ${POLYXX}")
find_library(CUDD cudd)
message(STATUS "cudd: ${CUDD}")
find_library(CVC5 cvc5)
message(STATUS "cvc5: ${CVC5}")
find_library(CADICAL cadical)
message(STATUS "cadical: ${CADICAL}")
find_library(SWINE swine-z3)
message(STATUS "swine: ${SWINE}")
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
# find_library(CRAB Crab)
# message(STATUS "crab: ${CRAB}")
# find_library(OPTPOLY optpoly)
# message(STATUS "otppoly: ${OPTPOLY}")
# find_library(OPTOCT optoct)
# message(STATUS "otpoct: ${OPTOCT}")
# find_library(ELINAUX elinaux)
# message(STATUS "elinaux: ${ELINAUX}")
# find_library(ELINALINEARIZE elinalinearize)
# message(STATUS "elinalinearize: ${ELINALINEARIZE}")
# find_library(PARTITIONS partitions)
# message(STATUS "partitions: ${PARTITIONS}")
# find_library(APRONXX apronxx)
# message(STATUS "apronxx: ${APRONXX}")
# find_library(APRON apron)
# message(STATUS "apron: ${APRON}")
# find_library(POLKAMPQ polkaMPQ)
# message(STATUS "polkaMPQ: ${POLKAMPQ}")
# find_library(GMPXX gmpxx)
# message(STATUS "gmpxx: ${GMPXX}")
# find_library(MPFR mpfr)
# message(STATUS "mpfr: ${MPFR}")

target_link_libraries(${EXECUTABLE}
  $<TARGET_OBJECTS:loat_util>
  $<TARGET_OBJECTS:loat_expr>
  # $<TARGET_OBJECTS:loat_crab>
  $<TARGET_OBJECTS:loat_rule_simplification>
  $<TARGET_OBJECTS:loat_smt>
  $<TARGET_OBJECTS:loat_formula_simplification>
  $<TARGET_OBJECTS:loat_recurrence>
  $<TARGET_OBJECTS:loat_acceleration>
  $<TARGET_OBJECTS:loat_its>
  # ${CRAB}
  # ${OPTPOLY}
  # ${OPTOCT}
  # ${PARTITIONS}
  # ${ELINALINEARIZE}
  # ${ELINAUX}
  # ${APRONXX}
  # ${GMPXX}
  # ${POLKAMPQ}
  # ${APRON}
  # ${MPFR}
  ${ANTLR4}
  ${FAUDES}
  ${SWINE}
  ${Z3}
  ${CVC5}
  ${CADICAL}
  ${YICES}
  ${POLYXX}
  ${POLY}
  ${CUDD}
  ${PURRS}
  ${GINAC}
  ${NTL}
  ${CLN}
  ${GMP}
  ${LINKER_OPTIONS}
)
