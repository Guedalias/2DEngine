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
Engine::Renderer::Init(int width, int height)
{
	_window = new sf::RenderWindow{ sf::VideoMode(width, height), "test" };

	_maxComponents = 64;
	_aliveComponents = 0;
	_renderComponentPool = new RenderComponent[_maxComponents]; // should be allocated via custom aligned allocator

	// To do Track max size and size of alive components
	// https://www.gamedev.net/articles/programming/general-and-gameplay-programming/c-custom-memory-allocation-r3010/
	// Allocators stuff

	_textureDebug = new sf::Texture{};
	_textureDebug->loadFromFile("./debug.png");
	//Need for a Ressource Manager;
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
	for (int i = 0; i < _aliveComponents; ++i)
	{
		_renderComponentPool[i].Render(_window);
	}
	_window->display();

	return true;
}

RenderComponent*
Engine::Renderer::AddRenderComponent()
{
	if (_aliveComponents >= _maxComponents)
	{
		return nullptr;
	}
	_renderComponentPool[_aliveComponents].Init(*_textureDebug);
	RenderComponent* ret = &_renderComponentPool[_aliveComponents];
	++_aliveComponents;

	return ret;
}

bool
Engine::Renderer::RemoveRenderComponent(size_t idx)
{
	if (_aliveComponents == 0)
	{
		return false;
	}
	--_aliveComponents;
	//do remove right idx;
	//do reordering on array;
	return true;
}