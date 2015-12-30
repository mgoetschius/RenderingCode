#pragma once
#include "../Engine/Scene.h"
#include "../Engine/SceneManager.h"
#include "../Engine/Shader.h"
#include "../Engine/Model.h"
#include "../Engine/Camera.h"

#include <vector>

class BaseScene :
	public Scene
{
public:
	BaseScene(void);
	void Init();
	void Update(SceneManager *manager);
	void Render();
	~BaseScene(void);
private:
	Shader shader;
	std::vector<Model> models;
	Camera camera;
	Model c;
};

