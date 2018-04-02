#include "GameObject.h"
#include "Script.h"

#include "../D2Engine/RenderComponent.h"

GameEngine::GameObject::GameObject()
{
}


GameEngine::GameObject::~GameObject()
{
	for (size_t i = _scripts.size(); i > 0; --i)
	{
		delete _scripts[i - 1];
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

std::ostream&
GameEngine::GameObject::Write(std::ostream & out)
{
	out.write("GO", 2 * sizeof(char));

	size_t size = _scripts.size();
	out.write((char*)&size, sizeof(size_t));
	
	for (size_t i = _scripts.size(); i > 0; --i)
	{
		_scripts[i - 1]->Write(out);
	}

	size = _rcs.size();
	out.write((char*)&size, sizeof(size_t));
	for (size_t i = _rcs.size(); i > 0; --i)
	{
		_rcs[i - 1]->Write(out);
	}
	return out;
}

bool GameEngine::GameObject::ReadConstruct(std::ifstream & in)
{
	return false;
}
