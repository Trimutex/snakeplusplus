cmake_minimum_required(VERSION 3.10)

project(
    snakeplusplus
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11 CACHE STRING "The C++ standard to use")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

include_directories(${snakeplusplus_SOURCE_DIR}/src)

add_subdirectory(src)

