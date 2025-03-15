cmake_minimum_required(VERSION 3.28.3)

project(
    zblock
    VERSION 1.0
    DESCRIPTION "Simple block game. Written in C++ with GLFW/OpenGL."
    LANGUAGES C CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# recursively find source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(
    zblock 
    ${SOURCES}
)

target_include_directories(
    zblock PRIVATE include
)

set_target_properties(
    zblock
    PROPERTIES
    CMAKE_CXX_STANDARD 17
)

add_subdirectory(zgl)
target_link_libraries(zblock zgl)