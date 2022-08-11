cmake_minimum_required(VERSION 3.7)

project(LoAT)

set(CMAKE_CXX_STANDARD 17)

# non-static build by default
option(STATIC "static" OFF)
option(SANITIZE "sanitize" OFF)

if(${STATIC})
    message(STATUS "Configuring static build")
    set(CMAKE_FIND_LIBRARY_SUFFIXES .a)
    set(BUILD_SHARED_LIBS OFF)
    add_link_options(-ldl -lpthread -static)
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

add_executable(${EXECUTABLE}
        src/accelerate/meter/metering.cpp
        src/accelerate/meter/metering.hpp
        src/accelerate/meter/metertools.cpp
        src/accelerate/meter/metertools.hpp
        src/accelerate/recurrence/dependencyorder.cpp
        src/accelerate/recurrence/dependencyorder.hpp
        src/accelerate/recurrence/recurrence.cpp
        src/accelerate/recurrence/recurrence.hpp
        src/accelerate/accelerator.cpp
        src/accelerate/accelerator.hpp
        src/accelerate/loopacceleration.cpp
        src/accelerate/loopacceleration.hpp
        src/accelerate/recursionacceleration.cpp
        src/accelerate/recursionacceleration.hpp
        src/accelerate/result.hpp
        src/accelerate/iterationCounterElimination/boundextractor.hpp
        src/accelerate/iterationCounterElimination/boundextractor.cpp
        src/accelerate/iterationCounterElimination/vareliminator.cpp
        src/accelerate/iterationCounterElimination/vareliminator.hpp
        src/accelerate/accelerationviaqe.cpp
        src/accelerate/accelerationviaqe.hpp
        src/accelerate/accelerationCalculus/accelerationproblem.cpp
        src/accelerate/accelerationCalculus/accelerationproblem.hpp
        src/accelerate/accelerationCalculus/rankingfunctionproblem.cpp
        src/accelerate/accelerationCalculus/rankingfunctionproblem.hpp
        src/analysis/analysis.cpp
        src/analysis/analysis.hpp
        src/analysis/chain.cpp
        src/analysis/chain.hpp
        src/analysis/chainstrategy.cpp
        src/analysis/chainstrategy.hpp
        src/analysis/preprocess.cpp
        src/analysis/preprocess.hpp
        src/analysis/prune.cpp
        src/analysis/prune.hpp
        src/analysis/rankingfunctionfinder.cpp
        src/analysis/rankingfunctionfinder.hpp
        src/analysis/recurrentsetfinder.cpp
        src/analysis/recurrentsetfinder.hpp
        src/asymptotic/asymptoticbound.cpp
        src/asymptotic/asymptoticbound.hpp
        src/asymptotic/inftyexpression.cpp
        src/asymptotic/inftyexpression.hpp
        src/asymptotic/limitproblem.cpp
        src/asymptotic/limitproblem.hpp
        src/asymptotic/limitsmt.cpp
        src/asymptotic/limitsmt.hpp
        src/asymptotic/limitvector.cpp
        src/asymptotic/limitvector.hpp
        src/expr/complexity.cpp
        src/expr/complexity.hpp
        src/expr/expression.cpp
        src/expr/expression.hpp
        src/expr/rel.cpp
        src/expr/rel.hpp
        src/expr/guardtoolbox.cpp
        src/expr/guardtoolbox.hpp
        src/expr/boolexpr.cpp
        src/expr/boolexpr.hpp
        src/its/cintegerexport.cpp
        src/its/cintegerexport.hpp
        src/parser/koatParser/itsparser.cpp
        src/parser/koatParser/itsparser.hpp
        src/its/export.cpp
        src/its/export.hpp
        src/its/smt2export.cpp
        src/its/smt2export.hpp
        src/its/hypergraph.hpp
        src/its/itsproblem.cpp
        src/its/itsproblem.hpp
        src/its/rule.cpp
        src/its/rule.hpp
        src/its/types.hpp
        src/its/guard.cpp
        src/its/guard.hpp
        src/its/variablemanager.cpp
        src/its/variablemanager.hpp
        src/util/exceptions.hpp
        src/util/option.hpp
        src/util/proof.hpp
        src/util/proof.cpp
        src/util/timeout.cpp
        src/util/timeout.hpp
        src/util/status.hpp
        src/util/farkas.cpp
        src/util/farkas.hpp
        src/util/templates.cpp
        src/util/templates.hpp
        src/util/relevantvariables.cpp
        src/util/relevantvariables.hpp
        src/util/result.hpp
        src/config.cpp
        src/config.hpp
        src/main.cpp
        src/main.hpp
        src/parser/smt2Parser/sexpresso/sexpresso.cpp
        src/parser/smt2Parser/sexpresso/sexpresso.hpp
        src/parser/smt2Parser/parser.cpp
        src/parser/smt2Parser/parser.hpp
        src/parser/t2Parser/t2parser.cpp
        src/parser/t2Parser/t2parser.hpp
        src/smt/smt.hpp
        src/smt/smt.cpp
        src/smt/smtcontext.hpp
        src/smt/exprtosmt.hpp
        src/smt/smttoexpr.hpp
        src/smt/z3/z3.cpp
        src/smt/z3/z3.hpp
        src/smt/z3/z3context.cpp
        src/smt/z3/z3context.hpp
        src/smt/yices/yices.cpp
        src/smt/yices/yices.hpp
        src/smt/yices/yicescontext.cpp
        src/smt/yices/yicescontext.hpp
        src/smt/smtfactory.cpp
        src/smt/smtfactory.hpp
        src/smt/model.cpp
        src/smt/model.hpp
        src/smt/combined_solver.hpp
        src/merging/merger.cpp
        src/merging/merger.hpp
        src/version.cpp
        src/version.hpp
        src/parser/koatParser/KoatParseVisitor.h
        src/parser/koatParser/KoatParseVisitor.cpp
        src/parser/koatParser/KoatVisitor.h
        src/parser/koatParser/KoatVisitor.cpp
        src/parser/koatParser/KoatListener.h
        src/parser/koatParser/KoatListener.cpp
        src/parser/koatParser/KoatLexer.cpp
        src/parser/koatParser/KoatLexer.h
        src/parser/koatParser/KoatParser.cpp
        src/parser/koatParser/KoatParser.h
        src/qelim/redlog.cpp
        src/qelim/redlog.hpp
        src/qelim/redlog.cpp
        src/qelim/redlog.hpp
        src/parser/redlog/redlogVisitor.h
        src/parser/redlog/redlogVisitor.cpp
        src/parser/redlog/redlogListener.h
        src/parser/redlog/redlogListener.cpp
        src/parser/redlog/redlogparsevisitor.h
        src/parser/redlog/redlogparsevisitor.cpp
        src/parser/redlog/redlogLexer.h
        src/parser/redlog/redlogLexer.cpp
        src/parser/redlog/redlogParser.h
        src/parser/redlog/redlogParser.cpp
        src/qelim/qelim.hpp
        src/qelim/qelim.cpp
        src/qelim/qeCalculus/qecalculus.hpp
        src/qelim/qeCalculus/qecalculus.cpp
        src/nonterm/nontermproblem.hpp
        src/nonterm/nontermproblem.cpp
        src/parser/chc/CHCParseVisitor.cpp
        src/parser/chc/CHCParseVisitor.h
        src/parser/chc/CHCLexer.cpp
        src/parser/chc/CHCLexer.h
        src/parser/chc/CHCListener.cpp
        src/parser/chc/CHCListener.h
        src/parser/chc/CHCParser.cpp
        src/parser/chc/CHCParser.h
        src/parser/chc/CHCVisitor.cpp
        src/parser/chc/CHCVisitor.h
        src/parser/chc/chcparser.cpp
        src/parser/chc/chcparser.hpp
    )

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

if (DEFINED ENV{ANTLR4_INCLUDE_PATH})
    # ANTLR4 is available and we know where to find the headers
    find_library(ANTLR4 antlr4-runtime)
    message(STATUS "antlr4: ${ANTLR4}")
    target_include_directories(${EXECUTABLE} PRIVATE $ENV{ANTLR4_INCLUDE_PATH})
    target_link_libraries(${EXECUTABLE} ${ANTLR4})
else()
    # ANTLR4 is not available, build it
    set(ANTLR4_TAG 4.7.2)
    LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
    if (${STATIC})
        add_definitions(-DANTLR4CPP_STATIC)
    endif()
    include(ExternalAntlr4Cpp)
    include_directories(${ANTLR4_INCLUDE_DIRS})
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

if (NOT ${STATIC})
    find_library(PTHREAD pthread)
    message(STATUS "pthread: ${PTHREAD}")
    target_link_libraries(${EXECUTABLE} ${PTHREAD})
endif()

target_include_directories(${EXECUTABLE} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../reduce-algebra/generic/libreduce/src/")

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
    ${LINKER_OPTIONS})
