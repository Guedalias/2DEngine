#pragma once

#include "DLLExport.h"

#include "Vector2D.hpp"

namespace Engine
{
	template<class T>
	class DllExport Rect2D
	{
	public:
		Vector2D<T> pos;
		Vector2D<T> dim;
	public:
		Rect2D(float x = 0.0f, float y = 0.0f, float w = 0.0f, float h = 0.0f) : pos(Vector2D{ x, y }), dim(Vector2D{ w, h }) { }
		Rect2D(Vector2D& position, Vector2D& dimension) : pos(position), dim(dimension) { }
		Rect2D(Rect2D& rhs) : pos(rhs.pos), dim(rhs.dim) { }
		~Rect2D();
	};
}