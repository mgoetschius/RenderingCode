#pragma once
#include "glew.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../Engine/Texture.h"
#include "../Engine/Shader.h"

class Billboard
{
public:
	Billboard(void);
	void Init(const char *texturePath);
	void Update();
	void Render(glm::mat4 &view, glm::mat4 &projection);
	~Billboard(void);
private:
	GLuint vao, vbo, ibo;
	Shader shader;
	Texture *texture;

	glm::mat4 modelMatrix;
	glm::vec3 translation, rotation, scale;
};

