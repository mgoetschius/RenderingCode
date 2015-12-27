#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "../Engine/Shader.h"
#include "../Engine/Mesh.h"

#include <string>

class Model
{
public:
	Model(void);
	void Init(const char *meshPath);
	void Update();
	void Render(Shader *shader);
	void LoadMeshes(const char *meshPath);
	glm::mat4 GetModelMatrix() { return modelMatrix; };
	~Model(void);
private:
	std::vector<Mesh> meshes;
	glm::vec3 translation;
	glm::vec3 rotation;
	glm::vec3 scale;
	glm::mat4 modelMatrix;
};

