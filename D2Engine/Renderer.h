#pragma once

#include "../Utils/DLLExport.h"

#include <vector>

namespace sf
{
	class RenderWindow;
	class Texture;
}

namespace Engine
{
	class RenderComponent;
	class IOEvent;
}

namespace Engine
{
	class DllExport	Renderer
	{
	private:
		sf::RenderWindow*		_window;

		RenderComponent*		_renderComponentPool;
		size_t					_maxComponents;
		size_t					_aliveComponents;

		//Debug
		sf::Texture*			_textureDebug;

	public:
		Renderer();
		~Renderer();

		bool	Init(int width = 800, int height = 600);
		bool	PollEvent(std::vector<IOEvent>& events);
		bool	Render();

		RenderComponent*	AddRenderComponent();
		bool				RemoveRenderComponent(size_t idx);
	};
}
