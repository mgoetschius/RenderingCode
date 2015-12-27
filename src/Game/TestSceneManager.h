#pragma once
#include "../Engine/SceneManager.h"
#include "BaseScene.h"

class TestSceneManager :
	public SceneManager
{
public:
	TestSceneManager(void);
	void Init();
	void ChangeScene();
	~TestSceneManager(void);
};

