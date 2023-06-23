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
		friend Vector2 operator-(const Vector2& vector) { return Vector2(-vector.x(), -vector.y()); }

		// Utility functions
		Vector2 unit() const;
		void normalize();

		inline double magnitude() const { return sqrt(magnitude_square()); }
		inline double magnitude_square() const { return pow(x(), 2) + pow(y(), 2); }

		friend double angle_between_vectors(const Vector2& vector1, const Vector2& vector2);
		friend std::pair<double, double> span_point(const Vector2& vector, const Vector2& basis1, const Vector2& basis2);

		inline friend double dot(const Vector2& vector1, const Vector2& vector2) { return vector1.x() * vector2.x() + vector1.y() * vector2.y(); }
		inline friend double cross(const Vector2& vector1, const Vector2& vector2) { return vector1.x() * vector2.y() - vector1.y() * vector2.x(); }
	};
}
