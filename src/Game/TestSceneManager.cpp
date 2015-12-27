#include "TestSceneManager.h"


TestSceneManager::TestSceneManager(void)
{
}

void TestSceneManager::Init()
{
	scene = new BaseScene();
	scene->Init();
}

void TestSceneManager::ChangeScene()
{
	// to be done
}


TestSceneManager::~TestSceneManager(void)
{
	delete scene;
}
