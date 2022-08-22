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
        accelerationviaqe.cpp
        accelerationviaqe.hpp
        accelerationviacalculus.cpp
        accelerationviacalculus.hpp
        accelerationtechnique.hpp
        accelerationtechnique.cpp
        accelerationfactory.hpp
        accelerationfactory.cpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
