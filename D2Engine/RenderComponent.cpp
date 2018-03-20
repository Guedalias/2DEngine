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

bool Engine::RenderComponent::Init(const sf::Texture& texture)
{
	delete _sprite;

	_sprite = new sf::Sprite{};
	_sprite->setTexture(texture, true);
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

std::ostream&
Engine::operator<<(std::ostream & out, const Engine::RenderComponent& rc)
{
	out << "RC";

	const sf::Vector2f pos = rc._sprite->getPosition();
	out << pos.x;
	out << pos.y;

	//Texture ref should be something like that :
	//sf::Texture* t = go._sprite->getTexture();
	//std::string filePath = RessourceManager->GetInstance()->GetFileFromTexture();
	// out << filePath.size() << filePath;
	out << 11;
	out << "./debug.png";
	return out;
}
