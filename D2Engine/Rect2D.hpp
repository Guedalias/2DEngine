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
		bool collision(Rect2D& other_rect);
		~Rect2D();
	};
	template<class T>
	// if border or corner are touching each other the method return also true !
	inline bool Rect2D<T>::collision(Rect2D & other_rect)
	{
		// check if outside
		if (pos.x > (other_rect.pos.x + other_rect.dim.x) ||
			(pos.x + dim.x) < (other_rect.pos.x) ||
			pos.y > (other_rect.pos.y + other_rect.dim.y) ||
			(pos.y + dim.y) < (other_rect.pos.y))
			return false;
		return true;
	}
}