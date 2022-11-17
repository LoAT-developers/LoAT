target_sources(${EXECUTABLE}
    PRIVATE
        cvc.hpp
        cvccontext.cpp
        cvccontext.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
