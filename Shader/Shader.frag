#version 460 core

layout(location = 0) in vec2 inTexCoords;

layout(location = 0) out vec4 outFragColor;

layout(binding = 0) uniform sampler2D albedoMap;

void main()
{
	vec2 texCoords = vec2(inTexCoords.x, 1.0f - inTexCoords.y);
	outFragColor = texture(albedoMap, texCoords);
}