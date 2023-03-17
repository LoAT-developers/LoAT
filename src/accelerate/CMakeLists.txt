add_subdirectory(iterationCounterElimination)
add_subdirectory(accelerationCalculus)

target_sources(${EXECUTABLE}
    PRIVATE
        loopacceleration.cpp
        loopacceleration.hpp
        accelerationresult.hpp
        accelerationresult.cpp
        accelerationviacalculus.cpp
        accelerationviacalculus.hpp
        accelerationtechnique.hpp
        accelerationfactory.hpp
        accelerationfactory.cpp
        accelconfig.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
