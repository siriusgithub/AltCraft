#pragma once

#include <GL/glew.h>
#include <glm/detail/type_mat.hpp>
#include <glm/vec2.hpp>
#include <glm/detail/type_mat4x4.hpp>
#include <glm/gtx/transform.hpp>
#include <easylogging++.h>

#include <AssetManager.hpp>
#include <world/Section.hpp>
#include <world/World.hpp>

class RenderState {
	GLuint ActiveVao;
	GLuint ActiveShader;
public:
	void SetActiveVao(GLuint Vao);
	void SetActiveShader(GLuint Shader);
};

class RenderSection {
	Vector sectionPosition;
	World *world;
	GLuint Vao, VboTextures, VboModels, VboColors;

	static GLuint VboVertices, VboUvs;
	static std::map<GLuint, int> refCounterVbo;
	static std::map<GLuint, int> refCounterVao;

	size_t numOfFaces;

public:
	RenderSection(World *world, Vector position);
	RenderSection(const RenderSection &other);
	~RenderSection();

	void UpdateState(const std::map<BlockTextureId, glm::vec4> &textureAtlas);
	void Render(RenderState &state);

	Section *GetSection();
};