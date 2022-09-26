cmake_minimum_required(VERSION 3.13)

project(LoAT)

set(CMAKE_CXX_STANDARD 20)

# non-static build by default
option(STATIC "static" OFF)
option(SANITIZE "sanitize" OFF)

set(CMAKE_FIND_LIBRARY_SUFFIXES .a)

add_link_options(-pthread)

if(${STATIC})
    message(STATUS "Configuring static build")
    set(CMAKE_FIND_LIBRARY_SUFFIXES .a)
    set(BUILD_SHARED_LIBS OFF)
    add_link_options(-ldl -static)
    set(EXECUTABLE loat-static)
else()
    message(STATUS "Configuring non-static build")
    set(EXECUTABLE loat)
endif()

if(${SANITIZE})
    message(STATUS "Sanitizer enabled")
    add_link_options(-fsanitize=undefined)
    add_compile_options(-fsanitize=undefined)
endif()

add_compile_options(-Wall -Wextra -pedantic -Wno-unused-parameter)

message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})
message(STATUS "Compiler flags:" ${CMAKE_CXX_COMPILE_FLAGS})
message(STATUS "Compiler cxx debug flags:" ${CMAKE_CXX_FLAGS_DEBUG})
message(STATUS "Compiler cxx release flags:" ${CMAKE_CXX_FLAGS_RELEASE})
message(STATUS "Compiler cxx min size flags:" ${CMAKE_CXX_FLAGS_MINSIZEREL})
message(STATUS "Compiler cxx flags:" ${CMAKE_CXX_FLAGS})


# generate version.cc
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/version.cpp.in" "${CMAKE_CURRENT_SOURCE_DIR}/src/version.cpp" @ONLY)

add_executable(${EXECUTABLE} "")
add_subdirectory(src)

message(STATUS "Searching libraries")
find_library(Z3 z3)
message(STATUS "z3: ${Z3}")
find_library(YICES yices)
message(STATUS "yices: ${YICES}")
find_library(PURRS purrs)
message(STATUS "purrs: ${PURRS}")
find_library(GINAC ginac)
message(STATUS "ginac: ${GINAC}")
find_library(CLN cln)
message(STATUS "cln: ${CLN}")
find_library(GMP gmp)
message(STATUS "gmp: ${GMP}")
find_library(NTL ntl)
message(STATUS "ntl: ${NTL}")
find_library(POLY poly)
message(STATUS "poly: ${POLY}")
find_library(CUDD cudd)
message(STATUS "cudd: ${CUDD}")

set(REDUCE ${CMAKE_CURRENT_SOURCE_DIR}/lib/libreduce.a)
message(STATUS "reduce: ${REDUCE}")
set(FAUDES ${CMAKE_CURRENT_SOURCE_DIR}/lib/libfaudes.a)
message(STATUS "faudes: ${FAUDES}")

if (DEFINED ENV{ANTLR4_INCLUDE_PATH})
    # ANTLR4 is available and we know where to find the headers
    find_library(ANTLR4 antlr4-runtime)
    message(STATUS "antlr4: ${ANTLR4}")
    target_include_directories(${EXECUTABLE} SYSTEM PRIVATE $ENV{ANTLR4_INCLUDE_PATH})
    target_link_libraries(${EXECUTABLE} ${ANTLR4})
else()
    # ANTLR4 is not available, build it
    set(ANTLR4_TAG 4.11.1)
    LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
    if (${STATIC})
        add_definitions(-DANTLR4CPP_STATIC)
    endif()
    include(ExternalAntlr4Cpp)
    include_directories(SYSTEM ${ANTLR4_INCLUDE_DIRS})
    if (${STATIC})
        target_link_libraries(${EXECUTABLE} antlr4_static)
    else()
        target_link_libraries(${EXECUTABLE} antlr4_shared)
    endif()
endif()

if (NOT YICES)
    message(STATUS "Yices not found.")
    return()
endif()

if (NOT POLY OR NOT CUDD)
    message(STATUS "Yices has missing dependencies.")
    return()
endif()

if (NOT Z3)
    message(STATUS "Z3 not found.")
    return()
endif() 

target_include_directories(${EXECUTABLE} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../reduce-algebra/generic/libreduce/src/")
target_include_directories(${EXECUTABLE} SYSTEM PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../libfaudes-2_29d/include/")

target_link_libraries(
    ${EXECUTABLE}
    ${PURRS}
    ${GINAC}
    ${Z3}
    ${NTL}
    ${CLN}
    ${YICES}
    ${POLY}
    ${CUDD}
    ${GMP}
    ${REDUCE}
    ${FAUDES}
    ${LINKER_OPTIONS})
