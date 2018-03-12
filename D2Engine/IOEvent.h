#pragma once

#include "DLLExport.h"

namespace sf {
	class Event;
}

namespace Engine {

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
	public:
		int		code;
		Type	type;
	public:
		IOEvent();
		~IOEvent();

		IOEvent(const sf::Event& ev);
	};
}

