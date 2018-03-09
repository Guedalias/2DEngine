#include "RenderComponent.h"

#include <SFML/Graphics.hpp>

Engine::RenderComponent::RenderComponent() :
	_sprite(nullptr)
{
}


Engine::RenderComponent::~RenderComponent()
{
	delete _sprite;
}

bool Engine::RenderComponent::Init(const sf::Texture& text)
{
	delete _sprite;

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
Engine::RenderComponent::SetPosition(Vector2D<float>& pos)
{
	_sprite->setPosition(pos.x, pos.y);
	return true;
}
