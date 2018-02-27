#pragma once

#include <SFML/Graphics.hpp>

namespace Engine
{
	class RenderComponent
	{
	private:
		sf::Sprite	_sprite;

	public:
		RenderComponent();
		~RenderComponent();

		bool Init(const sf::Texture& texture);
		bool Render(sf::RenderWindow* window);
	};

}
