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
	public:
		enum Action
		{
			Left,
			Right,
			Up,
			Down,
			Slot1,
			Slot2
		};
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
		bool IsKeyDown(char key);
		bool IsKeyDown(Action action);
	};
}

