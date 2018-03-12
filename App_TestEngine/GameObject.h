#pragma once

#include <vector>

namespace GameEngine
{
	class Script;
}

namespace Engine
{
	class RenderComponent;
}

namespace GameEngine
{
	class GameObject
	{
	private:
		std::vector<Script*>					_scripts;
		std::vector<Engine::RenderComponent*>	_rcs;
	public:
		GameObject();
		virtual ~GameObject();

		bool AddScript(Script * script);

		bool						AddRenderComponent(Engine::RenderComponent * rc);
		Engine::RenderComponent*	GetRenderComponent(size_t idx = 0) const;

		bool Update(float dt);
	};
}