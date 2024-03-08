#version 460 core

layout(location = 0) in vec2 inTexCoords;
layout(location = 1) in vec4 inColor;

layout(location = 0) out vec4 outFragColor;

layout(binding = 0) uniform sampler2D glyphAtlasMap;

void main()
{
	vec3 fragRGB = inColor.rgb;
	float alpha = inColor.a * texture(glyphAtlasMap, inTexCoords).r;
	outFragColor = vec4(fragRGB, alpha);
}