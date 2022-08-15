target_sources(${EXECUTABLE}
    PRIVATE
        boundextractor.hpp
        boundextractor.cpp
        vareliminator.cpp
        vareliminator.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
