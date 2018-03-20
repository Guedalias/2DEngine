#pragma once

#include <vector>

namespace Engine
{
	class RenderComponent;
	class Renderer;
}

namespace GameEngine
{
	class GameObject;
}

namespace GameEngine
{
	class Level
	{
	private:
		std::vector<GameObject*>				_entities;
		std::vector<Engine::RenderComponent*>	_tiles;
	public:
		Level();
		virtual ~Level();

		bool	Init(Engine::Renderer* rdr);

		bool	Update(float dt);

		bool	Load(const std::string& filename);
		bool	Save(const std::string& filename);
	};
}
