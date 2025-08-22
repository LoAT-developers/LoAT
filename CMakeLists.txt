set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

cmake_minimum_required(VERSION 3.13)

project(LoAT)

set(CMAKE_CXX_STANDARD 20)

# non-static build by default
option(STATIC "static" ON)
option(SANITIZE "sanitize" OFF)
option(BUILD_TESTS "tests" ON)

set(CMAKE_FIND_LIBRARY_SUFFIXES .a)
set(CMAKE_LIBRARY_PATH $ENV{LD_LIBRARY_PATH})
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install")

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

    # run "ulimit -n 2048", otherwise the resulting binary will hang

    add_link_options(-fsanitize=undefined,address -fsanitize-recover=undefined,address)
    add_compile_options(-fsanitize=undefined,address -fsanitize-recover=undefined,address)

    # MemorySanitizer is currently useless due to false positives
    # add_link_options(-fsanitize=memory -fsanitize-recover=memory -fsanitize-memory-track-origins)
    # add_compile_options(-fsanitize=memory -fsanitize-recover=memory -fsanitize-memory-track-origins)
    # add_compile_options(-fPIE -pie -fno-omit-frame-pointer)
endif()

add_compile_options(-Wall -Wextra -pedantic -Wno-unused-parameter) # for GCC: -fconcepts-diagnostics-depth=100

set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELEASE} -g")

message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})
message(STATUS "Compiler flags:" ${CMAKE_CXX_COMPILE_FLAGS})
message(STATUS "Compiler cxx debug flags:" ${CMAKE_CXX_FLAGS_DEBUG})
message(STATUS "Compiler cxx release flags:" ${CMAKE_CXX_FLAGS_RELEASE})
message(STATUS "Compiler cxx relwithdebinfo flags:" ${CMAKE_CXX_FLAGS_RELWITHDEBINFO})
message(STATUS "Compiler cxx min size flags:" ${CMAKE_CXX_FLAGS_MINSIZEREL})
message(STATUS "Compiler cxx flags:" ${CMAKE_CXX_FLAGS})

# ------------------------------------------------------------------------------
# Find external libraries required by the project.
# ------------------------------------------------------------------------------

message(STATUS "Searching external libraries")

function(find_required_library var libname displayname)
  find_library(${var} ${libname})
  if(NOT ${var})
    message(FATAL_ERROR "${displayname} not found. Please install ${displayname}.")
  else()
    message(STATUS "${displayname}: ${${var}}")
  endif()
endfunction()

function(find_required_package pkg_name displayname)
  find_package(${pkg_name} REQUIRED)
  if(NOT ${pkg_name}_FOUND)
    message(FATAL_ERROR "${displayname} not found. Please install ${displayname}.")
  else()
    message(STATUS "${displayname} found.")
  endif()
endfunction()

find_required_library(FAUDES faudes "Faudes")
find_required_library(Z3 z3 "Z3")
find_required_library(OPENSMT opensmt "OpenSMT")
find_required_library(YICES yices "Yices")
find_required_library(POLY poly "Poly")
find_required_library(POLYXX polyxx "PolyXX")
find_required_library(CUDD cudd "CUDD")
find_required_library(CVC5 cvc5 "CVC5")
find_required_library(CADICAL cadical "Cadical")
find_required_library(SWINE swine-z3 "Swine Z3")
find_required_library(CLN cln "CLN")
find_required_library(GMP gmp "GMP")
find_required_library(GMPXX gmpxx "GMPXX")

find_required_package(Boost "Boost")


# find_library(FAUDES faudes)
# find_library(Z3 z3)
# find_library(YICES yices)
# find_library(POLY poly)
# find_library(POLYXX polyxx)
# find_library(CUDD cudd)
# find_library(CVC5 cvc5)
# find_library(CADICAL cadical)
# find_library(SWINE swine-z3)
# find_library(CLN cln)
# find_library(GMP gmp)

# ------------------------------------------------------------------------------
# Output the found paths to the libraries for debugging purposes.
# ------------------------------------------------------------------------------
# message(STATUS "faudes: ${FAUDES}")
# message(STATUS "z3: ${Z3}")
# message(STATUS "yices: ${YICES}")
# message(STATUS "poly: ${POLY}")
# message(STATUS "polyxx: ${POLYXX}")
# message(STATUS "cudd: ${CUDD}")
# message(STATUS "cvc5: ${CVC5}")
# message(STATUS "cadical: ${CADICAL}")
# message(STATUS "swine: ${SWINE}")
# message(STATUS "cln: ${CLN}")
# message(STATUS "gmp: ${GMP}")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC SHA)
git_local_changes(DIRTY)

# generate version.cc
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/version.cpp.in" "${CMAKE_CURRENT_SOURCE_DIR}/src/version.cpp" @ONLY)

# ===============================
# Executable
# ===============================
add_executable(${EXECUTABLE} "")

# ===============================
# Test Executable
# ===============================
if(${BUILD_TESTS})
  enable_testing()
  set(Loat_API_Tests "LoATAPITests")
  add_executable(${Loat_API_Tests} "")
endif()

set(Loat_API LoATAPI)

add_library(${Loat_API} STATIC)

add_subdirectory(src)

if(NOT TARGET Boost::boost)
  add_library(Boost::boost INTERFACE IMPORTED)
  set_target_properties(Boost::boost PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${Boost_INCLUDE_DIRS}"
  )
endif()

if(${BUILD_TESTS})
  target_include_directories(${Loat_API_Tests} PRIVATE
  $<BUILD_INTERFACE:
    ${Boost_INCLUDE_DIRS}
    ${sexpresso_INCLUDE_DIRS}
    ${loat_util_INCLUDE_DIRS}
    ${loat_container_INCLUDE_DIRS}
    ${loat_expr_INCLUDE_DIRS}
    ${loat_fmplex_INCLUDE_DIRS}
    ${loat_preprocessing_INCLUDE_DIRS}
    ${loat_smt_INCLUDE_DIRS}
    ${loat_recurrence_INCLUDE_DIRS}
    ${loat_acceleration_INCLUDE_DIRS}
    ${loat_trp_INCLUDE_DIRS}
    ${loat_itsproblem_INCLUDE_DIRS}
    ${loat_chcproblem_INCLUDE_DIRS}
    ${loat_safetyproblem_INCLUDE_DIRS}
    ${loat_transformations_INCLUDE_DIRS}
  >
)
endif()

target_include_directories(${EXECUTABLE} PRIVATE
  $<BUILD_INTERFACE:
    ${Boost_INCLUDE_DIRS}
    ${sexpresso_INCLUDE_DIRS}
    ${loat_util_INCLUDE_DIRS}
    ${loat_container_INCLUDE_DIRS}
    ${loat_expr_INCLUDE_DIRS}
    ${loat_fmplex_INCLUDE_DIRS}
    ${loat_preprocessing_INCLUDE_DIRS}
    ${loat_smt_INCLUDE_DIRS}
    ${loat_recurrence_INCLUDE_DIRS}
    ${loat_acceleration_INCLUDE_DIRS}
    ${loat_trp_INCLUDE_DIRS}
    ${loat_itsproblem_INCLUDE_DIRS}
    ${loat_chcproblem_INCLUDE_DIRS}
    ${loat_safetyproblem_INCLUDE_DIRS}
    ${loat_transformations_INCLUDE_DIRS}
  >
)

target_include_directories(${EXECUTABLE} PRIVATE
  $<BUILD_INTERFACE:
    ${Boost_INCLUDE_DIRS}
    ${sexpresso_INCLUDE_DIRS}
    ${loat_util_INCLUDE_DIRS}
    ${loat_container_INCLUDE_DIRS}
    ${loat_expr_INCLUDE_DIRS}
    ${loat_fmplex_INCLUDE_DIRS}
    ${loat_preprocessing_INCLUDE_DIRS}
    ${loat_smt_INCLUDE_DIRS}
    ${loat_recurrence_INCLUDE_DIRS}
    ${loat_acceleration_INCLUDE_DIRS}
    ${loat_trp_INCLUDE_DIRS}
    ${loat_itsproblem_INCLUDE_DIRS}
    ${loat_chcproblem_INCLUDE_DIRS}
    ${loat_safetyproblem_INCLUDE_DIRS}
    ${loat_transformations_INCLUDE_DIRS}
  >
)

set(OBJECT_LIBRARIES
  sexpresso
  loat_util
  loat_expr
  loat_fmplex
  loat_preprocessing
  loat_smt
  loat_recurrence
  loat_acceleration
  loat_trp
  loat_itsproblem
  loat_chcproblem
  loat_safetyproblem
  loat_transformations
)

foreach(LIB ${OBJECT_LIBRARIES})
  target_sources(${Loat_API} PRIVATE $<TARGET_OBJECTS:${LIB}>)
endforeach()

target_include_directories(${Loat_API} PUBLIC $<INSTALL_INTERFACE:include/LoAT>)

target_include_directories(${Loat_API} PRIVATE
  $<BUILD_INTERFACE:
    ${Boost_INCLUDE_DIRS}
    ${sexpresso_INCLUDE_DIRS}
    ${loat_util_INCLUDE_DIRS}
    ${loat_container_INCLUDE_DIRS}
    ${loat_expr_INCLUDE_DIRS}
    ${loat_fmplex_INCLUDE_DIRS}
    ${loat_preprocessing_INCLUDE_DIRS}
    ${loat_smt_INCLUDE_DIRS}
    ${loat_recurrence_INCLUDE_DIRS}
    ${loat_acceleration_INCLUDE_DIRS}
    ${loat_trp_INCLUDE_DIRS}
    ${loat_itsproblem_INCLUDE_DIRS}
    ${loat_chcproblem_INCLUDE_DIRS}
    ${loat_safetyproblem_INCLUDE_DIRS}
    ${loat_transformations_INCLUDE_DIRS}
  >
)

target_link_libraries(${Loat_API} PUBLIC Boost::boost
  ${FAUDES}
  ${SWINE}
  ${Z3}
  ${CVC5}
  ${CADICAL}
  ${OPENSMT}
  ${YICES}
  ${POLYXX}
  ${POLY}
  ${CUDD}
  ${CLN}
  ${GMPXX}
  ${GMP}
  ${LINKER_OPTIONS}
)

target_link_libraries(${EXECUTABLE} PRIVATE ${Loat_API})

include(GNUInstallDirs)
install(TARGETS ${Loat_API}
  EXPORT ${Loat_API}Targets
  ARCHIVE DESTINATION lib
)
install(EXPORT ${Loat_API}Targets
  FILE ${Loat_API}Targets.cmake
  DESTINATION lib/cmake/${Loat_API}
)

file(GLOB_RECURSE ALL_HEADERS "${CMAKE_SOURCE_DIR}/src/*.hpp" "${CMAKE_SOURCE_DIR}/src/*.h")
install(FILES ${ALL_HEADERS} DESTINATION include/LoAT)

include(CMakePackageConfigHelpers)

configure_package_config_file(
  "${CMAKE_SOURCE_DIR}/cmake/${Loat_API}Config.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/${Loat_API}Config.cmake"
    INSTALL_DESTINATION lib/cmake/${Loat_API}
)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/${Loat_API}Config.cmake"
  DESTINATION lib/cmake/${Loat_API}
)

if(${BUILD_TESTS})
  # ===============================
  # GoogleTest via FetchContent
  # ===============================
  include(FetchContent)

  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
  )

  FetchContent_MakeAvailable(googletest)

  add_subdirectory(src/api/tests)

  # Link against LoATAPI and GTest
  target_link_libraries(${Loat_API_Tests} PRIVATE
    LoATAPI
    gtest
    gtest_main
  )

  # Include GoogleTest functions
  include(GoogleTest)

  # Automatically register tests with CTest
  gtest_discover_tests(${Loat_API_Tests})
endif()

