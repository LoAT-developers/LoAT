target_sources(${EXECUTABLE}
    PRIVATE
        metering.cpp
        metering.hpp
        metertools.cpp
        metertools.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
