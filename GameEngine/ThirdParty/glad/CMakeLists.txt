# CMake의 최소 버전을 명시합니다.
cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(GLAD_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(GLAD_INCLUDE "${GLAD_PATH}/include")
set(GLAD_SOURCE "${GLAD_PATH}/src")

file(GLOB_RECURSE GLAD_INCLUDE_FILE "${GLAD_INCLUDE}/*")
file(GLOB_RECURSE GLAD_SOURCE_FILE "${GLAD_SOURCE}/*")

add_library(glad STATIC ${GLAD_INCLUDE_FILE} ${GLAD_SOURCE_FILE})

target_include_directories(glad PUBLIC ${GLAD_INCLUDE})

set_property(TARGET glad PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

source_group(include FILES ${GLAD_INCLUDE_FILE})
source_group(src FILES ${GLAD_SOURCE_FILE})