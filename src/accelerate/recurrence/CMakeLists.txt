target_sources(${EXECUTABLE}
    PRIVATE
        dependencyorder.cpp
        dependencyorder.hpp
        recurrence.cpp
        recurrence.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
