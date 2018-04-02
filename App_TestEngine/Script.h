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

		std::ostream& Write(std::ostream& out);
		bool	ReadConstruct(std::ifstream& in);
	};
}

