#include "SceneManager.h"
#include <iostream>



SceneManager::SceneManager()
{
}

void SceneManager::Init()
{
	
}

void SceneManager::Update()
{
	scene->Update(this);
}

void SceneManager::Render()
{
	scene->Render();
}


SceneManager::~SceneManager()
{
	
}
