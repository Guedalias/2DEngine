#include "RenderComponent.h"

#include <SFML/Graphics.hpp>

Engine::RenderComponent::RenderComponent()
{
}


Engine::RenderComponent::~RenderComponent()
{
}

bool Engine::RenderComponent::Init(const sf::Texture& text)
{
	_sprite = new sf::Sprite{};
	_sprite->setTexture(text, true);
	return true;
}

bool
Engine::RenderComponent::Render(sf::RenderWindow* window)
{
	window->draw(*_sprite);
	return true;
}

bool
Engine::RenderComponent::SetPosition(Vector2D& pos)
{
	_sprite->setPosition(pos.x, pos.y);
	return true;
}
