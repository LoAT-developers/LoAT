file(GLOB LOAT_API_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
if(LOAT_API_SOURCES)
    target_sources(${Loat_API} PRIVATE ${LOAT_API_SOURCES})
endif()
target_include_directories(${Loat_API} PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
target_include_directories(${EXECUTABLE} PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)

if(${BUILD_TESTS})
  target_include_directories(${Loat_API_Tests} PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
endif()

