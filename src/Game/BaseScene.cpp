#include "BaseScene.h"
#include <iostream>


BaseScene::BaseScene(void)
{
}

GLuint vao, vbo, ibo;

void BaseScene::Init()
{
	shader.AddShader(GL_VERTEX_SHADER, "./res/Shaders/vertex.vs");
	shader.AddShader(GL_FRAGMENT_SHADER, "./res/Shaders/fragment.fs");
	shader.CreateProgram();
	shader.AddUniform("mvMatrix");
	shader.AddUniform("pMatrix");

	camera.Init(45.0, GameEngine::windowWidth, GameEngine::windowHeight, 0.1, 1000);

	Model m;
	m.Init("./res/Models/groundplane.dae");
	models.push_back(m);
	m.Init("./res/Models/cube.dae");
	models.push_back(m);
}

void BaseScene::Update(SceneManager *manager)
{
	camera.Update();
}

void BaseScene::Render()
{
	
	glm::mat4 p = camera.getProjectionMatrix();
	
	shader.UpdateUniform("pMatrix", p);

	for(Model model : models)
	{
		glm::mat4 mv = camera.getViewMatrix() * model.GetModelMatrix();
		shader.UpdateUniform("mvMatrix", mv);
		model.Render(&shader);
	}
}


BaseScene::~BaseScene(void)
{
}
