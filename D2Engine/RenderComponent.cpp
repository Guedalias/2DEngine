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
Engine::RenderComponent::Write(std::ostream & out)
{
	out.write("RC", 2 * sizeof(char));

	const sf::Vector2f pos = _sprite->getPosition();
	out.write((char*)&pos.x, sizeof(float));
	out.write((char*)&pos.y, sizeof(float));

	//Texture ref should be something like that :
	//sf::Texture* t = go._sprite->getTexture();
	//std::string filePath = RessourceManager->GetInstance()->GetFileFromTexture();
	// out << filePath.size() << filePath;
	int a = 11;
	out.write((char*)&a, sizeof(int));
	out.write("./debug.png", 11 * sizeof(char));

	return out;
}
