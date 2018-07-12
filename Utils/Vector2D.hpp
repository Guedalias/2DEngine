#pragma once

#include "DLLExport.h"

// CODE REVIEW VECTOR2D
// https://codereview.stackexchange.com/questions/26608/review-of-2d-vector-class
//

namespace Engine
{
	template<class T>
	class DllExport Vector2D
	{
	public:
		T x;
		T y;
	public:
		Vector2D(T X = 0.0f, T Y = 0.0f) : x(X), y(Y) { }
		Vector2D(const Vector2D& other) : x(other.x), y(other.y) { }
		virtual ~Vector2D() { }
		// Move constructor.
		Vector2D(Vector2D&& rhs) : x(rhs.x), y(rhs.y) { }
		// Move assignment operator.
		Vector2D& operator=(Vector2D&& rhs)
		{
			if (this != &rhs)
			{
				x = rhs.x;
				y = rhs.y;
			}
			return *this;
		}


		/*==========================================================
						Vector To Vector
		==========================================================*/

		Vector2D& operator+=(const Vector2D& rhs) // compound assignment (does not need to be a member,
		{										  // but often is, to modify the private members)
			x += rhs.x;
			y += rhs.y;
			return *this; // return the result by reference
		}
		Vector2D& operator-=(const Vector2D& rhs) { x -= rhs.x; y -= rhs.y; return *this; }
		Vector2D& operator*=(const Vector2D& rhs) { x *= rhs.x; y *= rhs.y; return *this; }
		Vector2D& operator/=(const Vector2D& rhs) { x /= rhs.x; y /= rhs.y; return *this; }


		// friends defined inside class body are inline and are hidden from non-ADL lookup
		friend Vector2D operator+(Vector2D lhs,			// passing lhs by value helps optimize chained a+b+c
								  const Vector2D& rhs)	// otherwise, both parameters may be const references
		{
			lhs += rhs; // reuse compound assignment
			return lhs; // return the result by value (uses move constructor)
		}
		friend Vector2D operator-(Vector2D lhs, const Vector2D& rhs) { lhs -= rhs; return lhs; }
		friend Vector2D operator*(Vector2D lhs, const Vector2D& rhs) { lhs *= rhs; return lhs; }
		friend Vector2D operator/(Vector2D lhs, const Vector2D& rhs) { lhs /= rhs; return lhs; }
		
		friend bool operator==(const Vector2D& lhs, const Vector2D& rhs) { return std::tie(lhs.x, lhs.y) == std::tie(rhs.x, rhs.y); }
		friend bool operator!=(const Vector2D& lhs, const Vector2D& rhs) { return !(lhs == rhs); }

		Vector2D operator-() const { return Vector2D(-x, -y); }
		
		/*==========================================================
							int/float/double To Vector
		==========================================================*/
		Vector2D& operator+=(const T& s) { x += s; y += s; return *this; }
		Vector2D& operator-=(const T& s) { x -= s; y -= s; return *this; }
		Vector2D& operator*=(const T& s) { x *= s; y *= s; return *this; }
		Vector2D& operator/=(const T& s) { x /= s; y /= s; return *this; }

		friend Vector2D operator+(Vector2D lhs, const T& rhs) { lhs += rhs; return lhs; }
		friend Vector2D operator+(const T& lhs, Vector2D rhs) { rhs += lhs; return rhs; }
		
		friend Vector2D operator-(Vector2D lhs, const T& rhs) { lhs -= rhs; return lhs; }
		friend Vector2D operator-(const T& lhs, Vector2D rhs) { rhs -= lhs; return rhs; }
		
		friend Vector2D operator*(Vector2D lhs, const T& rhs) { lhs *= rhs; return lhs; }
		friend Vector2D operator*(const T& lhs, Vector2D rhs) { rhs *= lhs; return rhs; }
		
		friend Vector2D operator/(Vector2D lhs, const T& rhs) { lhs /= rhs; return lhs; }
		friend Vector2D operator/(const T& lhs, Vector2D rhs) { rhs /= lhs; return rhs; }
	};


	//Product functions
	template<class T> T DotProduct(const Vector2D<T>& lhs, const Vector2D<T>& rhs)
	{
		return lhs.x*rhs.x + lhs.y*rhs.y
	}

	template<class T> T CrossProduct(const Vector2D<T>&, const Vector2D<T>&)
	{
		return lhs.x*rhs.y - lhs.y*rhs.x;
	}
	
	//Returns the length of the vector from the origin.
	template<class T> T EuclideanNorm(const Vector2D<T>& lhs)
	{
		return sqrt(lhs.x*lhs.x + lhs.y*lhs.y);
	}
	
	//Return the unit vector of the input
	template<class T> Vector2D<T> Normalize(const Vector2D<T>& lhs)
	{
		T sum = lhs.x + lhs.y;
		return Vector2D<T>{lhs.x / sum, lhs.y / sum};
	}
	
	//Return a vector perpendicular to the left.
	template<class T> Vector2D<T> Perpendicular(const Vector2D<T>& lhs)
	{
		return Vector2D<T>{-lhs.y, lhs.x};
	}
	
	//Return true if two line segments intersect.
	template<class T> bool Intersect(const Vector2D<T>& s1, const Vector2D<T>& e1, const Vector2D<T>& o2, const Vector2D<T>& e2)
	{
		return false;
	}
	
	//Return the point where two lines intersect.
	template<class T> Vector2D<T> GetIntersect(const Vector2D<T>& lhs, const Vector2D<T>&, const Vector2D<T>&, const Vector2D<T>&)
	{
	
	}
}