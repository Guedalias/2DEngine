#include "RenderComponent.h"



Engine::RenderComponent::RenderComponent()
{
}


Engine::RenderComponent::~RenderComponent()
{
}

bool Engine::RenderComponent::Init(const sf::Texture& text)
{
	_sprite = sf::Sprite{};
	_sprite.setTexture(text, true);
	return true;
}

bool
Engine::RenderComponent::Render(sf::RenderWindow* window)
{
	window->draw(_sprite);
	return false;
}
