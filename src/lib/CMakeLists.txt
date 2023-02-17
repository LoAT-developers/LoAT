if (DEFINED ENV{ANTLR4_INCLUDE_PATH})
  # ANTLR4 is available and we know where to find the headers
  find_library(ANTLR4 antlr4-runtime)
  message(STATUS "antlr4: ${ANTLR4}")
  set(ANTLR4_INCLUDE_DIRS $ENV{ANTLR4_INCLUDE_PATH}
    CACHE INTERNAL "ANTLR4: Include Directories" FORCE)
  set(ANTLR4 ${ANTLR4}
    CACHE INTERNAL "ANTLR4: " FORCE)
else()
  # ANTLR4 is not available, build it
  set(ANTLR4_TAG 4.11.1)
  LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../cmake)
  if (${STATIC})
    add_definitions(-DANTLR4CPP_STATIC)
  endif()
  include(ExternalAntlr4Cpp)
  set(ANTLR4_INCLUDE_DIRS ${ANTLR4_INCLUDE_DIRS}
    CACHE INTERNAL "ANTLR4: Include Directories" FORCE)
  if (${STATIC})
    set(ANTLR4 ${ANTLR4_STATIC_LIBRARIES}
      CACHE INTERNAL "ANTLR4: " FORCE)
  else()
    set(ANTLR4 ${ANTLR4_RUNTIME_LIBRARIES}
      CACHE INTERNAL "ANTLR4: " FORCE)
  endif()
endif()

add_subdirectory(util)
add_subdirectory(expr)
add_subdirectory(smt)
add_subdirectory(qe)
