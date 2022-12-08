# build project process:
# cmake -DCMAKE_BUILD_TYPE=Debug -G "Visual Studio 15 2017 Win64" "source_dir"
# cmake --build . --config Debug
# cmake -DCMAKE_BUILD_TYPE=Release -G "Visual Studio 15 2017 Win64" "source_dir"
# cmake --build . --config Release

cmake_minimum_required(VERSION 3.0)

project(curves)

if(NOT CMAKE_BUILD_TYPE) 
    set(CMAKE_BUILD_TYPE Release)
endif()
message("cmake_build_type: " ${CMAKE_BUILD_TYPE})

include_directories(${PROJECT_SOURCE_DIR}/..)
message("include_directories: " ${PROJECT_SOURCE_DIR})

set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/Curve/Circle.cpp
)

set(TEST_SOURCES
    ${PROJECT_SOURCE_DIR}/test/test_curve.cpp 
)

set(TARGET_EXE_NAME test_curve)
add_executable(
	${TARGET_EXE_NAME} 
	${TEST_SOURCES} 
	${SOURCES}
)
