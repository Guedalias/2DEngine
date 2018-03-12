#pragma once

#include "Script.h"

namespace Test
{
	class PingPongBall : public GameEngine::Script
	{
	public:
		float x = 0.0f;
		float y = 0.0f;
		float xvel = 1.0f;
		float yvel = 1.0f;

	public:
		PingPongBall();
		virtual ~PingPongBall();

		virtual bool Update(float dt, GameEngine::GameObject* go) override;
	};

}

