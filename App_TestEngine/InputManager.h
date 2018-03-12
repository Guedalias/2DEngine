#pragma once

#include <map>

namespace Engine
{
	class Renderer;
}

namespace GameEngine
{
	class InputManager
	{
	/* Singleton Impl */
	public:
		static InputManager* GetInstance();
	private:
		InputManager();
	/* End Singleton */
	private:
		std::map<int, bool>	keyboard;
	public:
		virtual ~InputManager();

		bool Update(Engine::Renderer* rdr);
		bool IsKeyDown(int keyCode);
	};
}

