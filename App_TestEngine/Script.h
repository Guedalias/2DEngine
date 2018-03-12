#pragma once

namespace GameEngine
{
	class GameObject;
}

namespace GameEngine
{
	class Script
	{
	public:
		Script();
		virtual ~Script();

		virtual bool Update(float dt, GameObject* go) = 0;
	};
}

