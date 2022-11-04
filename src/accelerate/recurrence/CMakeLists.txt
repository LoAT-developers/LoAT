target_sources(${EXECUTABLE}
    PRIVATE
        dependencyorder.hpp
        dependencyorder.cpp
        recurrence.cpp
        recurrence.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
