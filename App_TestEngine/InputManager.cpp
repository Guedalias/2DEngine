#include "InputManager.h"

#include "../D2Engine/IOEvent.h"
#include "../D2Engine/Renderer.h"

#include <iostream>

static GameEngine::InputManager* instance = nullptr;

GameEngine::InputManager::InputManager()
{
}


GameEngine::InputManager::~InputManager()
{
}

GameEngine::InputManager*
GameEngine::InputManager::GetInstance()
{
	if (instance == nullptr)
		instance = new InputManager();
	return instance;
}

bool GameEngine::InputManager::Update(Engine::Renderer * rdr)
{
	std::vector<Engine::IOEvent> events;

	if (rdr->PollEvent(events) == false)
		return false;

	size_t count = events.size();
	for (int i = 0; i < count; ++i)
	{
		std::cout << events[i].code << std::endl;
		if (events[i].type == Engine::IOEvent::Type::KEYPRESSED)
			keyboard[events[i].code] = true;
		else if (events[i].type == Engine::IOEvent::Type::KEYRELEASED)
			keyboard[events[i].code] = false;
	}

	return true;
}

bool
GameEngine::InputManager::IsKeyDown(int keyCode)
{
	if (keyboard.count(keyCode) == 0)
		return false;
	return keyboard[keyCode];
	return false;
}
