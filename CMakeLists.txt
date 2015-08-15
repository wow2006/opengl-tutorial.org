project(OpenGL_Tutorials)
cmake_minimum_required(VERSION 2.8)

# Just for youCompleteMe
set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )
# To add c++11 and include GLEW GLFW GLM to project
include("${CMAKE_SOURCE_DIR}/cmake_include/library.cmake")
# some helping macros
include("${CMAKE_SOURCE_DIR}/cmake_include/utility.cmake")

add_subdirectory(Tutorial_1)
add_subdirectory(Tutorial_2)
add_subdirectory(Tutorial_3)
add_subdirectory(Tutorial_4)

set(CMAKE_BUILD_TYPE Debug)
