#version 330

in vec2 TexCoords;
in vec3 ViewSpaceNormal;
in vec3 ViewSpacePosition;

struct DirectionalLight
{
	vec3 direction;
	vec3 intensity;
	vec3 ambient;
};

uniform sampler2D Texture;
uniform mat4 mvMatrix;
uniform DirectionalLight directionalLight;

out vec4 outputColor;

DirectionalLight dLight;

vec4 CalculateDirectional()
{
	vec3 dirToLightViewSpace = normalize(mat3(mvMatrix) * dLight.direction);
	vec3 Normal = normalize(ViewSpaceNormal);
	float cosAngIncidence = dot(Normal, dirToLightViewSpace);
	cosAngIncidence = clamp(cosAngIncidence, 0, 1);
	return texture(Texture, TexCoords) * dLight.intensity * cosAngIncidence + texture(Texture, TexCoords)* vec4(dLight.ambient, 1.0);
}

void main()
{
	
	dLight.direction = vec3(1, .5, .5);
	dLight.intensity = vec3(0.6, 0.6, 0.6);
	dLight.ambient = vec3(0.2, 0.2, 0.2);

	outputColor = CalculateDirectional();
}