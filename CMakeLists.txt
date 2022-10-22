CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
project(ray_tracing_demo)

macro(add_demo_executable executable headers sources)
    if(NOT ENABLE_TESTING)
        add_executable(${executable} ${headers} ${sources})
    endif()
endmacro()

if(ENABLE_TESTING)
    message("-- C++ Test Config - Enabled")

    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()
    include(GoogleTest)
else()
    message("-- C++ Test Config - Disabled")
endif()

macro(add_demo_test_dir dir)
    if(ENABLE_TESTING)
        add_subdirectory(${dir})
    endif()
endmacro()

macro(add_demo_test executable sources)
    enable_testing()
    
    add_executable(${executable}.test ${sources})
    include(GoogleTest)
    gtest_discover_tests(${executable}.test)
endmacro()

set(INCLUDE ${CMAKE_SOURCE_DIR}/include)
set(HEADERS 
    ${INCLUDE}/EasyFileWriter.hpp
    ${INCLUDE}/RenderAlgorithms.hpp
    ${INCLUDE}/geometry/Ray.hpp
    ${INCLUDE}/geometry/Sphere.hpp
    ${INCLUDE}/geometry/Vec3.hpp)

set(SRC ${CMAKE_SOURCE_DIR}/src)
set(SOURCES
    ${CMAKE_SOURCE_DIR}/main.cpp
    ${SRC}/geometry/Camera.cpp
    ${SRC}/geometry/Ray.cpp)

add_demo_executable(${PROJECT_NAME} "${HEADERS}" "${SOURCES}")

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE})

add_subdirectory(${CMAKE_SOURCE_DIR}/include)
