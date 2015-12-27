#pragma once
#include <map>
#include "../Engine/Mesh.h"
#include "../Engine/Texture.h"
class ResourceManager
{
public:
	ResourceManager(void);
	static Mesh* LoadMesh(const char *filename);
	static Texture* LoadTexture(const char *filename);
	static void ClearMeshes();
	static void ClearTextures();
	~ResourceManager(void);
private:
	static std::map<const char*, Mesh*> meshes;
	static std::map<const char*, Texture*> textures;
};

