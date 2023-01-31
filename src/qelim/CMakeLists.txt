add_subdirectory(qeCalculus)

target_sources(${EXECUTABLE}
    PRIVATE
        redlog.cpp
        redlog.hpp
        qelim.hpp
        qelimfactory.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
