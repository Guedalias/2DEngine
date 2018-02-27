#pragma once

#include "DLLExport.h"

namespace sf
{
	class RenderWindow;
}

namespace Engine
{
	class RenderComponent;
}

namespace Engine
{
	class DllExport	Renderer
	{
	private:
		sf::RenderWindow*		_window;
		RenderComponent*		_renderComponentPool;

	public:
		Renderer();
		~Renderer();

		bool	Init();
		bool	PollEvent();
		bool	Render();
	};
}
