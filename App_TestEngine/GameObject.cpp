#include "GameObject.h"
#include "Script.h"

#include "../D2Engine/RenderComponent.h"

GameEngine::GameObject::GameObject()
{
}


GameEngine::GameObject::~GameObject()
{
	for (int i = _scripts.size() - 1; i >= 0; --i)
	{
		delete _scripts[i];
	}
	_scripts.clear();
}

bool GameEngine::GameObject::AddScript(GameEngine::Script* script)
{
	_scripts.push_back(script);
	return true;
}

bool GameEngine::GameObject::AddRenderComponent(Engine::RenderComponent* rc)
{
	_rcs.push_back(rc);
	return true;
}

Engine::RenderComponent*
GameEngine::GameObject::GetRenderComponent(size_t idx) const
{
	return _rcs[idx];
}

bool GameEngine::GameObject::Update(float dt)
{
	size_t count = _scripts.size();
	for (int i = 0; i < count; ++i)
	{
		_scripts[i]->Update(dt, this);
	}
	return true;
}
