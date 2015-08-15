#version 330 core

// Values that stay constant for the whole mesh.
uniform sampler2D myTextureSampler;
in vec2 UV;
// Ouput data
out vec3 color;

void main()
{
    // Output color = color of the texture at the specified UV
    color = texture( myTextureSampler, UV ).rgb;
}
