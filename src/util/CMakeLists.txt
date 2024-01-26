target_sources(${EXECUTABLE}
    PRIVATE
        itsproof.hpp
        itsproof.cpp
        itsresult.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
