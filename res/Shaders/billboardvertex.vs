#version 330

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoords;

out vec4 Color;
out vec2 TexCoords;

uniform mat4 mvpMatrix;

void main()
{
	gl_Position = mvpMatrix * vec4(position, 1.0f);
	Color = vec4(1.0, 1.0, 0.0, 1.0);
	TexCoords = texCoords;
}