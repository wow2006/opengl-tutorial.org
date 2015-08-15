project(Tutorial_4)

set(
    shaders
    "${CMAKE_CURRENT_SOURCE_DIR}/shaders/SimpleFragmentShader.glsl"
    "${CMAKE_CURRENT_SOURCE_DIR}/shaders/SimpleVertexShader.glsl"
)

add_executable(${PROJECT_NAME} main.cpp ${shaders})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

cpy_dir(
    "${CMAKE_CURRENT_SOURCE_DIR}/shaders"
    "${CMAKE_CURRENT_BINARY_DIR}/shaders"
)
