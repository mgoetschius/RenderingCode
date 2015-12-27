#include "Model.h"

inline float DegToRad(float angDeg)
{
	return angDeg * 3.14159 * 2.0 / 360.0;
}


Model::Model(void)
{
}

void Model::Init(const char *meshPath)
{
	LoadMeshes(meshPath);

	translation = glm::vec3(0.0);
	rotation = glm::vec3(0.0);
	scale = glm::vec3(1.0);

	Update();
}

void Model::Update()
{
	modelMatrix = glm::mat4(1.0);
    modelMatrix = glm::translate(modelMatrix, translation);
    modelMatrix = glm::rotate(modelMatrix, DegToRad(rotation.x), glm::vec3(1,0,0));
    modelMatrix = glm::rotate(modelMatrix, DegToRad(rotation.y), glm::vec3(0,1,0));
    modelMatrix = glm::rotate(modelMatrix, DegToRad(rotation.z), glm::vec3(0,0,-1));
    modelMatrix = glm::scale(modelMatrix, scale);
}

void Model::Render(Shader *shader)
{
		//glEnable(GL_BLEND);
        //glBlendFunc(GL_ONE, GL_ONE);
        //glDepthMask(GL_FALSE);
        //glDepthFunc(GL_EQUAL);
	
	shader->Bind();
	for(unsigned int i = 0; i < meshes.size(); i++)
		meshes[i].Render();
}

void Model::LoadMeshes(const char *meshPath)
{
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	Assimp::Importer importer;
	const aiScene *scene = importer.ReadFile(meshPath, aiProcess_Triangulate | aiProcess_FlipUVs);

	if(!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) 
    {
        std::cout << "Error: " << importer.GetErrorString() << std::endl;
        return;
    }

	aiNode *node = scene->mRootNode;

	for(int k = 0; k < scene->mNumMeshes; k++)
	{
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		aiMesh *mesh = scene->mMeshes[k];

		for(unsigned int i = 0; i < mesh->mNumVertices; i++)
		{
			glm::vec3 v;
			v.x = mesh->mVertices[i].x;
			v.y = mesh->mVertices[i].y;
			v.z = mesh->mVertices[i].z;
			glm::vec2 t;
			t.x = mesh->mTextureCoords[0][i].x;
			t.y = mesh->mTextureCoords[0][i].y;
			glm::vec3 n;
			n.x = mesh->mNormals[i].x;
			n.y = mesh->mNormals[i].y;
			n.z = mesh->mNormals[i].z;

			Vertex vertex(v, t, n);
			vertices.push_back(vertex);
		}
	
		for(unsigned int i = 0; i < mesh->mNumFaces; i++)
		{
			aiFace face = mesh ->mFaces[i];
			for(unsigned int j = 0; j < face.mNumIndices; j++)
				indices.push_back(face.mIndices[j]);
		}

		aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];

		aiString str;
		material->GetTexture(aiTextureType_DIFFUSE, 0, &str);

		Mesh m;
		m.Init(vertices, &indices[0], indices.size(), str.C_Str());
		meshes.push_back(m);
	}
}


Model::~Model(void)
{
}
