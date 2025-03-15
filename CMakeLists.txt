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
    lib/glad/src/glad.c
)

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
    zblock PRIVATE lib/glfw/include
)
add_subdirectory(lib/glfw)
target_link_libraries(zblock glfw)

target_include_directories(
    zblock PRIVATE lib/glad/include
)

add_subdirectory(lib/glm)
target_include_directories(
    zblock PRIVATE lib/glm
)

target_include_directories(
    zblock PRIVATE lib/stb
)