#pragma once

#include "Script.h"

namespace Test
{
	class FlyController : public GameEngine::Script
	{
	public:
		float x = 0.0f;
		float y = 0.0f;
		float xvel = 40.0f;
		float yvel = 40.0f;

	public:
		FlyController();
		virtual ~FlyController();

		virtual bool Update(float dt, GameEngine::GameObject* go) override;
	};


}