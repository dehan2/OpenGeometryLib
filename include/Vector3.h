#pragma once
#include "Point3.h"

//////////////////////////////
// Vector3 Class by Chacha at Jun. 22, 2023
// This class is for 3D vector.
//////////////////////////////

namespace OpenGeometry
{
	class Vector3 : public Point3
	{
	private:
		// No private members

	public:
		// Constructors and Destructor

		Vector3() : Point3() {}
		virtual ~Vector3() = default;
		Vector3(const double& x, const double& y, const double& z) : Point3(x, y, z) {}
		Vector3(const Vector3& rhs) : Point3(rhs) {}

		// Operator overloading

		virtual Vector3& operator=(const Vector3& rhs) { return *static_cast<Vector3*>(&Point3::operator=(rhs)); }

		inline void operator+=(const Vector3& rhs) { Point3::operator+=(rhs); }
		Vector3& operator+(const Vector3& rhs);
		inline void operator-=(const Vector3& rhs) { Point3::operator-=(rhs); }
		Vector3& operator-(const Vector3& rhs);
		void operator*=(const double& rhs) { Point3::operator*=(rhs); }
		Vector3& operator*(const double& rhs);
		void operator/=(const double& rhs) { Point3::operator/=(rhs); }
		Vector3& operator/(const double& rhs);
		friend Vector3 operator*(const double& lhs, const Vector3& rhs) { return Vector3(lhs * rhs.x(), lhs * rhs.y(), lhs * rhs.z()); }
		friend Vector3 operator-(const Vector3& vector) { return Vector3(-vector.x(), -vector.y() - vector.z()); }

		// Utility functions
		Vector3 unit() const;
		void normalize();

		inline double magnitude() const { return sqrt(magnitude_square()); }
		inline double magnitude_square() const { return pow(x(), 2) + pow(y(), 2) + pow(z(), 2); }

		friend double angle_between_vectors(const Vector3& vector1, const Vector3& vector2);
		
		inline friend double dot(const Vector3& vector1, const Vector3& vector2) { return vector1.x() * vector2.x() + vector1.y() * vector2.y() + vector1.z() * vector2.z(); }
		friend Vector3 cross(const Vector3& vector1, const Vector3& vector2);
	};
}