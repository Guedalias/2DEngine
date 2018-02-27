#pragma once

#include "DLLExport.h"

namespace sf
{
	class RenderWindow;
	class Texture;
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
		size_t					_maxComponents;
		size_t					_aliveComponents;

		//Debug
		sf::Texture*			_textureDebug;

	public:
		Renderer();
		~Renderer();

		bool	Init();
		bool	PollEvent();
		bool	Render();

		bool AddRenderComponent();
		bool RemoveRenderComponent(size_t idx);
	};
}
