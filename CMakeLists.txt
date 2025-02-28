set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

cmake_minimum_required(VERSION 3.13)

project(LoAT)

set(CMAKE_CXX_STANDARD 20)

# non-static build by default
option(STATIC "static" ON)
option(SANITIZE "sanitize" OFF)

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

find_library(ANTLR4 antlr4-runtime)
find_library(FAUDES faudes)
find_library(Z3 z3)
find_library(YICES yices)
find_library(POLY poly)
find_library(POLYXX polyxx)
find_library(CUDD cudd)
find_library(CVC5 cvc5)
find_library(CADICAL cadical)
find_library(SWINE swine-z3)
find_library(CLN cln)
find_library(GMP gmp)

# ------------------------------------------------------------------------------
# Output the found paths to the libraries for debugging purposes.
# ------------------------------------------------------------------------------
message(STATUS "antlr4: ${ANTLR4}")
message(STATUS "faudes: ${FAUDES}")
message(STATUS "z3: ${Z3}")
message(STATUS "yices: ${YICES}")
message(STATUS "poly: ${POLY}")
message(STATUS "polyxx: ${POLYXX}")
message(STATUS "cudd: ${CUDD}")
message(STATUS "cvc5: ${CVC5}")
message(STATUS "cadical: ${CADICAL}")
message(STATUS "swine: ${SWINE}")
message(STATUS "cln: ${CLN}")
message(STATUS "gmp: ${GMP}")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")
include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC SHA)
git_local_changes(DIRTY)

# generate version.cc
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/version.cpp.in" "${CMAKE_CURRENT_SOURCE_DIR}/src/version.cpp" @ONLY)

add_executable(${EXECUTABLE} "")

set(Loat_API LoATAPI)

add_library(${Loat_API} STATIC)

add_subdirectory(src)

target_include_directories(${Loat_API} PUBLIC
  $<BUILD_INTERFACE:
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

target_link_libraries(${Loat_API}
  $<TARGET_OBJECTS:sexpresso>
  $<TARGET_OBJECTS:loat_util>
  $<TARGET_OBJECTS:loat_expr>
  $<TARGET_OBJECTS:loat_fmplex>
  $<TARGET_OBJECTS:loat_preprocessing>
  $<TARGET_OBJECTS:loat_smt>
  $<TARGET_OBJECTS:loat_recurrence>
  $<TARGET_OBJECTS:loat_acceleration>
  $<TARGET_OBJECTS:loat_trp>
  $<TARGET_OBJECTS:loat_itsproblem>
  $<TARGET_OBJECTS:loat_chcproblem>
  $<TARGET_OBJECTS:loat_safetyproblem>
  $<TARGET_OBJECTS:loat_transformations>
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
  ${CLN}
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

target_include_directories(${Loat_API} PUBLIC $<INSTALL_INTERFACE:include/LoAT>)

