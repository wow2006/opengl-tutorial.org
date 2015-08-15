project(Tutorial_6)

set(
    shaders
    "${CMAKE_CURRENT_SOURCE_DIR}/shaders/SimpleFragmentShader.glsl"
    "${CMAKE_CURRENT_SOURCE_DIR}/shaders/SimpleVertexShader.glsl"
)

set(
    commonFiles
    "${common}/shader.hpp"
    "${common}/Camera.hpp"
    "${common}/Camera.cpp"
)

add_executable(${PROJECT_NAME} main.cpp ${shaders} ${commonFiles})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

cpy_dir(
    "${CMAKE_CURRENT_SOURCE_DIR}/shaders"
    "${CMAKE_CURRENT_BINARY_DIR}/shaders"
)

cpy_dir(
    "${CMAKE_CURRENT_SOURCE_DIR}/media"
    "${CMAKE_CURRENT_BINARY_DIR}/media"
)
