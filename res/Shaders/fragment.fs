#version 330

in vec4 Color;
in vec2 TexCoords;

uniform sampler2D Texture;

out vec4 outputColor;

void main()
{
	//outputColor = Color;
	outputColor = texture(Texture, TexCoords);
}