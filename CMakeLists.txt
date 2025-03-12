cmake_minimum_required(VERSION 3.28.3)

project(
    zblock
    VERSION 1.0
    DESCRIPTION "Simple block game. Written in C++ with GLFW/OpenGL."
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(zblock src/main.cpp)

target_include_directories(
    zblock PRIVATE include
)

set_target_properties(
    zblock
    PROPERTIES
    CMAKE_CXX_STANDARD 17
    ARCHIVE_OUTPUT_DIRECTORY "bin"
    LIBRARY_OUTPUT_DIRECTORY "bin"
    RUNTIME_OUTPUT_DIRECTORY "bin"
)

find_package(OpenGL REQUIRED)
target_link_libraries(zblock OpenGL::GL)
target_include_directories(
    zblock PRIVATE glfw/include
)

add_subdirectory(glfw)
target_link_libraries(zblock glfw)