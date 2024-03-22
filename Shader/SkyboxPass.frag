#version 460 core

layout(location = 0) in vec3 inTexCoords;

layout(location = 0) out vec4 outFragColor;

layout(binding = 0) uniform samplerCube skybox;

void main()
{
	outFragColor = texture(skybox, inTexCoords);
}