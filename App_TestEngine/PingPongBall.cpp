#include "PingPongBall.h"

#include "GameObject.h"

#include "../D2Engine/Vector2D.hpp"
#include "../D2Engine/RenderComponent.h"

Test::PingPongBall::PingPongBall() : GameEngine::Script()
{
}


Test::PingPongBall::~PingPongBall()
{
}

bool Test::PingPongBall::Update(float dt, GameEngine::GameObject* go)
{
	Engine::RenderComponent* rc = go->GetRenderComponent(0);

	rc->SetPosition(Engine::Vector2D<float>{ x, y });
	x += xvel * dt;
	y += yvel * dt;
	if (x > 800)
		xvel = -10.0f;
	else if (x < 0)
		xvel = 10.0f;

	if (y > 600)
		yvel = -10.0f;
	else if (y < 0)
		yvel = 10.0f;
	return false;
}
