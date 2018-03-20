#pragma once

#include <string>

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

		friend std::ostream& operator<<(std::ostream& out, const Script& go);
	};
}

