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

add_compile_options(-Wall -Wextra -pedantic -Wno-unused-parameter)

set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELEASE} -g")

message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})
message(STATUS "Compiler flags:" ${CMAKE_CXX_COMPILE_FLAGS})
message(STATUS "Compiler cxx debug flags:" ${CMAKE_CXX_FLAGS_DEBUG})
message(STATUS "Compiler cxx release flags:" ${CMAKE_CXX_FLAGS_RELEASE})
message(STATUS "Compiler cxx relwithdebinfo flags:" ${CMAKE_CXX_FLAGS_RELWITHDEBINFO})
message(STATUS "Compiler cxx min size flags:" ${CMAKE_CXX_FLAGS_MINSIZEREL})
message(STATUS "Compiler cxx flags:" ${CMAKE_CXX_FLAGS})

if (DEFINED ENV{ANTLR4_INCLUDE_PATH})
  # ANTLR4 is available and we know where to find the headers
  find_library(ANTLR4 antlr4-runtime)
  set(ANTLR4_INCLUDE_DIRS $ENV{ANTLR4_INCLUDE_PATH})
else()
  # ANTLR4 is not available, build it
  set(ANTLR4_TAG 4.11.1)
  LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
  if (${STATIC})
    add_definitions(-DANTLR4CPP_STATIC)
  endif()
  include(ExternalAntlr4Cpp)
  if (${STATIC})
    set(ANTLR4 antlr4_static)
  else()
    set(ANTLR4 antlr4_shared)
  endif()
endif()

# generate version.cc
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/version.cpp.in" "${CMAKE_CURRENT_SOURCE_DIR}/src/version.cpp" @ONLY)

add_executable(${EXECUTABLE} "")
add_subdirectory(src)

set(FAUDES ${CMAKE_CURRENT_SOURCE_DIR}/lib/libfaudes.a)
message(STATUS "faudes: ${FAUDES}")

target_include_directories(${EXECUTABLE} PRIVATE
  ${loat_util_INCLUDE_DIRS}
  ${loat_expr_INCLUDE_DIRS}
  ${loat_smt_INCLUDE_DIRS}
  ${loat_qe_INCLUDE_DIRS}
  ${loat_recurrence_INCLUDE_DIRS}
  ${loat_acceleration_INCLUDE_DIRS}
  ${ANTLR4_INCLUDE_DIRS}
)

target_include_directories(${EXECUTABLE} SYSTEM PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../libfaudes-2_30b/include/")

message(STATUS "antlr4: ${ANTLR4}")

target_link_libraries(${EXECUTABLE}
  loat_util
  loat_expr
  loat_smt
  loat_qe
  loat_recurrence
  loat_acceleration
  ${ANTLR4}
  ${FAUDES}
  ${LINKER_OPTIONS})
