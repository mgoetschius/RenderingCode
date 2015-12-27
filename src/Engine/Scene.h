#pragma once

class SceneManager;


class Scene
{
public:
	Scene(void);
	virtual void Init() = 0;
	virtual void Update(SceneManager *manager) = 0;
	virtual void Render() = 0;
	~Scene(void);
};

