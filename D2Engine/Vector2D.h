#pragma once

#include "DLLExport.h"

namespace Engine
{
	class DllExport Vector2D
	{
	public:
		float x;
		float y;
	public:
		Vector2D(float x = 0.0f, float y = 0.0f);
		~Vector2D();
	};
}