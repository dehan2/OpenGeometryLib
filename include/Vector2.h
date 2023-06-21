#pragma once

#include "Point2.h"

//////////////////////////////
// Vector2 Class by Chacha at Jun. 21, 2023
// This class is for 2D vector.
//////////////////////////////


namespace OpenGeometry
{
	class Vector2 : public Point2
	{
	private:
		// No private members

	public:
		// Constructors and Destructor

		Vector2() : Point2() {}
		virtual ~Vector2() = default;
		Vector2(const double& x, const double& y) : Point2(x, y) {}
		Vector2(const Vector2& rhs) : Point2(rhs) {}

		// Operator overloading

		virtual Vector2& operator=(const Vector2& rhs) { return *static_cast<Vector2*>(&Point2::operator=(rhs)); }

		inline void operator+=(const Vector2& rhs) { Point2::operator+=(rhs); }
		Vector2& operator+(const Vector2& rhs);
		inline void operator-=(const Vector2& rhs) { Point2::operator-=(rhs); }
		Vector2& operator-(const Vector2& rhs);
		void operator*=(const double& rhs) { Point2::operator*=(rhs); }
		Vector2& operator*(const double& rhs);
		void operator/=(const double& rhs) { Point2::operator/=(rhs); }
		Vector2& operator/(const double& rhs);
		friend Vector2 operator*(const double& lhs, const Vector2& rhs) { return Vector2(lhs * rhs.x(), lhs * rhs.y()); }
		friend Vector2 operator-(const Vector2& point) { return Vector2(-point.x(), -point.y()); }
	};
}
