add_subdirectory(meter)
add_subdirectory(recurrence)
add_subdirectory(iterationCounterElimination)
add_subdirectory(accelerationCalculus)

target_sources(${EXECUTABLE}
    PRIVATE
        accelerator.cpp
        accelerator.hpp
        loopacceleration.cpp
        loopacceleration.hpp
        recursionacceleration.cpp
        recursionacceleration.hpp
        accelerationresult.hpp
        accelerationresult.cpp
        accelerationviaqe.cpp
        accelerationviaqe.hpp
        accelerationviacalculus.cpp
        accelerationviacalculus.hpp
        accelerationtechnique.hpp
        accelerationfactory.hpp
        accelerationfactory.cpp
        accelconfig.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
