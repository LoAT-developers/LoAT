set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

cmake_minimum_required(VERSION 3.13)

project(LoAT_Integration)

set(CMAKE_CXX_STANDARD 20)

#Set custom prefix to serach for packages
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${CMAKE_SOURCE_DIR}/../../build/install")

add_compile_options(-Wall -Wextra -pedantic -Wno-unused-parameter)

# Find the installed RechnerAPI package
find_package(LoATAPI REQUIRED)

# Create an executable
add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE LoATAPI)