#pragma once

#include "DLLExport.h"

#include <map>

namespace sf {
	class Event;
}

namespace Engine {
	class sfmlEventAdapter
	{
	public:
		const static char Keyboard[];
	};

	class DllExport IOEvent
	{
	public:
		enum Type
		{
			MOUSECLICK,
			MOUVEMOVE,
			KEYPRESSED,
			KEYRELEASED
		};
	private:
		//static sfmlEventAdapter sfmlEventAdapter;
	public:
		int		code;
		Type	type;
	public:
		IOEvent();
		~IOEvent();

		IOEvent(const sf::Event& ev);
	};
}

