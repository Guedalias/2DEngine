#pragma once

#include "DLLExport.h"

namespace sf {
	class Event;
}

namespace Engine {

	class DllExport IOEvent
	{
	private:
		int size;
	public:
		IOEvent();
		~IOEvent();

		IOEvent(const sf::Event& ev);
	public:
		enum Type
		{
			MOUSECLICK_RIGHT,
			MOUSECLICK_LEFT,
			MOUSECLICK_MIDDLE,
			MOUVEMOVE,
		};
	};
}

