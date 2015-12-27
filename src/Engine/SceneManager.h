#pragma once
#include "Scene.h"

class SceneManager
{
public:
	SceneManager();
	virtual void Init();
	void Update();
	void Render();
	~SceneManager();

protected:
	Scene *scene;

private:
	
	
};
