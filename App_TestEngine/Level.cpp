#include "Level.h"

#include "../D2Engine/RenderComponent.h"
#include "../D2Engine/Renderer.h"

#include "GameObject.h"

GameEngine::Level::Level()
{
}


GameEngine::Level::~Level()
{

}

bool
GameEngine::Level::Update(float dt)
{
	size_t count = _entities.size();
	for (size_t i = 0; i < count; ++i)
	{
		_entities[i]->Update(dt);
	}
	return true;
}

bool GameEngine::Level::Load(const std::string & filename)
{
	return false;
}

bool GameEngine::Level::Save(const std::string & filename)
{
	return false;
}
