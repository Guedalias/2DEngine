#include "FlyController.h"

#include "GameObject.h"

#include "../D2Engine/Vector2D.hpp"
#include "../D2Engine/RenderComponent.h"

#include "InputManager.h"

Test::FlyController::FlyController() : GameEngine::Script()
{
}


Test::FlyController::~FlyController()
{
}

bool
Test::FlyController::Update(float dt, GameEngine::GameObject* go)
{
	Engine::RenderComponent* rc = go->GetRenderComponent(0);
	GameEngine::InputManager* im = GameEngine::InputManager::GetInstance();

	if (im->IsKeyDown('D'))
		x += xvel * dt; 
	if (im->IsKeyDown('A'))
		x -= xvel * dt;
	if (im->IsKeyDown('W'))
		y -= yvel * dt;
	if (im->IsKeyDown('S'))
		y += yvel * dt;

	rc->SetPosition(Engine::Vector2D<float>{ x, y });
	return true;
}
