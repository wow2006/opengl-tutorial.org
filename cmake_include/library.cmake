# add C++11
if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
endif()
# add new module directory to cmake default
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules")

# find GLEW library
find_package(GLEW REQUIRED)
# find GLFW library
find_package(GLFW REQUIRED)
# find GLM library
find_package(GLM REQUIRED)

include_directories(${GLEW_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS})
# Libraries needed on all platforms for this project
set( LIBRARIES
    ${GLEW_LIBRARIES}
    ${GLFW_LIBRARIES}
    -lGL
    -lX11
    -lXi
    -lXrandr
    -lXxf86vm
    -lXinerama
    -lXcursor
    -lrt
    -lm
    -pthread
    -ldl
)
