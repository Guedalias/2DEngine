#include "IOEvent.h"

#include <SFML/Graphics.hpp>

Engine::IOEvent::IOEvent()
{
}

Engine::IOEvent::IOEvent(const sf::Event& ev)
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		type = Type::KEYPRESSED;
		code = ev.key.code;
		break;
	case sf::Event::KeyReleased:
		type = Type::KEYRELEASED;
		code = ev.key.code;
		break;
	default:
		break;
	}
}


Engine::IOEvent::~IOEvent()
{
}
