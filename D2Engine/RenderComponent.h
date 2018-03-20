#pragma once

#include "DLLExport.h"
#include "Vector2D.hpp"

#include <iostream>

namespace sf
{
	class Sprite;
	class Texture;
	class RenderWindow;
}

namespace Engine
{
	class DllExport RenderComponent
	{
	private:
		sf::Sprite*	_sprite;

	public:
		RenderComponent();
		~RenderComponent();

		bool Init(const sf::Texture& texture);
		bool Render(sf::RenderWindow* window);
		
		bool SetPosition(Vector2D<float>& pos);

		friend std::ostream& operator<<(std::ostream &out, const RenderComponent &go);
	};

}
