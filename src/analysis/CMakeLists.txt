target_sources(${EXECUTABLE}
    PRIVATE
        analysis.cpp
        analysis.hpp
        chain.cpp
        chain.hpp
        chainstrategy.cpp
        chainstrategy.hpp
        preprocess.cpp
        preprocess.hpp
        prune.cpp
        prune.hpp
)

target_include_directories(${EXECUTABLE} PRIVATE ".")
