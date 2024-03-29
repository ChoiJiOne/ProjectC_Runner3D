cmake_minimum_required(VERSION 3.27)

project(ProjectC)

set(PROJECT_NAME "Runner3D")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(GameEngine/ThirdParty/cgltf)
add_subdirectory(GameEngine/ThirdParty/glad)
add_subdirectory(GameEngine/ThirdParty/jsoncpp)
add_subdirectory(GameEngine/ThirdParty/miniaudio)
add_subdirectory(GameEngine/ThirdParty/SDL)
add_subdirectory(GameEngine/ThirdParty/stb)

add_subdirectory(GameEngine/CrashModule)
add_subdirectory(GameEngine/FileModule)
add_subdirectory(GameEngine/MathModule)

set_target_properties(cgltf glad jsoncpp miniaudio SDL2 SDL2main sdl_headers_copy stb PROPERTIES FOLDER "GameEngine/ThirdParty")
set_target_properties(CrashModule FileModule MathModule PROPERTIES FOLDER "GameEngine/Module")

set(WINDOW_TITLE "${PROJECT_NAME}")
set(WINDOW_POS_UNDEFINED 0)
set(WINDOW_POS_CENTERED 1)
set(WINDOW_X 100)
set(WINDOW_Y 100)
set(WINDOW_W 1000)
set(WINDOW_H 800)
set(GL_MAJOR_VERSION 4)
set(GL_MINOR_VERSION 6)
set(GL_RED_SIZE 8)
set(GL_GREEN_SIZE 8)
set(GL_BLUE_SIZE 8)
set(GL_ALPHA_SIZE 8)
set(GL_DEPTH_SIZE 24)
set(GL_STENCIL_SIZE 8)
set(GL_DOUBLEBUFFER 1)
set(GL_MULTISAMPLEBUFFERS 1)
set(GL_MULTISAMPLESAMPLES 16)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/Inc/SDLConfig.h.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/Inc/SDLConfig.h"
)

set(EXE_ICON_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Resource/Icon/Icon.ico")
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/Res/Resource.rc.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/Res/Resource.rc"
)

set(PROJECT_INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/Inc")
set(PROJECT_SOURCE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/Src")
set(PROJECT_RESOURCE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/Res")
set(SCRIPT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Script")
set(SHADER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Shader")

file(GLOB_RECURSE PROJECT_INCLUDE_FILE "${PROJECT_INCLUDE_PATH}/**")
file(GLOB_RECURSE PROJECT_SOURCE_FILE "${PROJECT_SOURCE_PATH}/**")
file(GLOB_RECURSE PROJECT_RESOURCE_FILE "${PROJECT_RESOURCE_PATH}/**")
file(GLOB_RECURSE SCRIPT_SOURCE_FILE "${SCRIPT_PATH}/*")
file(GLOB_RECURSE SHADER_SOURCE_FILE "${SHADER_PATH}/*")

add_executable(
    ${PROJECT_NAME} 
    WIN32 
    ${PROJECT_INCLUDE_FILE}
    ${PROJECT_SOURCE_FILE} 
    ${PROJECT_RESOURCE_FILE}
    ${SCRIPT_SOURCE_FILE} 
    ${SHADER_SOURCE_FILE}
)

target_include_directories(
    ${PROJECT_NAME} 
    PUBLIC 
    ${PROJECT_INCLUDE_PATH} 
    ${PROJECT_SOURCE_PATH}
    ${PROJECT_RESOURCE_PATH}
)

target_link_libraries(
    ${PROJECT_NAME} 
    PUBLIC 
    cgltf
    glad
    jsoncpp
    miniaudio
    SDL2
    stb 
    CrashModule
    FileModule
    MathModule
)

target_compile_definitions(
    ${PROJECT_NAME} 
    PUBLIC
    $<$<CONFIG:Debug>:DEBUG_MODE>
    $<$<CONFIG:Release>:RELEASE_MODE>
    $<$<CONFIG:RelWithDebInfo>:DEVELOPMENT_MODE>
    $<$<CONFIG:MinSizeRel>:SHIPPING_MODE>
)

set_property(TARGET ${PROJECT_NAME} PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

source_group(TREE "${PROJECT_INCLUDE_PATH}" PREFIX "${PROJECT_NAME}/Inc" FILES ${PROJECT_INCLUDE_FILE})
source_group(TREE "${PROJECT_SOURCE_PATH}" PREFIX "${PROJECT_NAME}/Src" FILES ${PROJECT_SOURCE_FILE})
source_group(TREE "${PROJECT_RESOURCE_PATH}" PREFIX "${PROJECT_NAME}/Res" FILES ${PROJECT_RESOURCE_FILE})
source_group(Script FILES ${SCRIPT_SOURCE_FILE})
source_group(Shader FILES ${SHADER_SOURCE_FILE})