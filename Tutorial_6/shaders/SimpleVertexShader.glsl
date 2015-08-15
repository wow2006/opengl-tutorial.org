#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
// Notice that the "1" here equals the "1" in glVertexAttribPointer
layout(location = 1) in vec2 vertexUV;
//
uniform mat4 MVP;
// Output data ; will be interpolated for each fragment.
out vec2 UV;

void main(){
    // Output position of the vertex, in clip space : MVP * position
    vec4 v = vec4(vertexPosition_modelspace,1); // Transform an homogeneous 4D vector, remember ?
    gl_Position = MVP * v;

    // The color of each vertex will be interpolated
    // to produce the color of each fragment
    UV = vertexUV;
}

