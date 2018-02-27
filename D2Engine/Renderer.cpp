#include "Renderer.h"
#include "RenderComponent.h"

#include <SFML/Graphics.hpp>

using namespace Engine;

Renderer::Renderer() :
	_window(nullptr),
	_renderComponentPool(nullptr)
{

}

Renderer::~Renderer()
{
	delete		_window;
	delete[]	_renderComponentPool;
}

bool
Engine::Renderer::Init()
{
	_window = new sf::RenderWindow{ sf::VideoMode(200, 200), "SFML works!" };

	_renderComponentPool = new RenderComponent[64]; // should be allocated via custom aligned allocator
	// To do Track max size and size of alive components

	return true;
}

bool
Engine::Renderer::PollEvent()
{
	sf::Event event;
	while (_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			_window->close();
			return false;
		}
			
	}
	return true;
}

bool
Engine::Renderer::Render()
{
	_window->clear();
	//Iterate over all renderComponent and render them;
	for (int i = 0; i < 64; ++i)
	{
		_renderComponentPool[i].Render();
	}
	_window->display();

	return true;
}
