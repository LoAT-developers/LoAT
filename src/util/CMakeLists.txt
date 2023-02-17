target_sources(${EXECUTABLE}
    PRIVATE
        approx.hpp
        relevantvariables.hpp
        result.hpp
        smtfactory.hpp
        qelimfactory.hpp
        itsproof.hpp
        itsproof.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
