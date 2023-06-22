#pragma once
#include "Point2.h"

//////////////////////////////
// Point3 Class by Chacha at Jun. 21, 2023
// This class is for 3D point.
//////////////////////////////

namespace OpenGeometry 
{
	class Point3 : public Point2
	{
	protected:
		double m_z = 0.0;

	public:
		// Constructor and destructor

		Point3() = default;
		virtual ~Point3() = default;
		Point3(const double& x, const double& y, const double& z) { set(x, y, z); }
		Point3(const Point3& rhs) { copy(rhs); }

		virtual void copy(const Point3& rhs);

		inline double z() const { return m_z; }
		inline void set_z(const double& z) { m_z = z; }
		inline void set(const double& x, const double& y, const double& z) { Point2::set(x, y); m_z = z; }

		// Operator overloading

		virtual Point3& operator=(const Point3& rhs);

		void operator+=(const Point3& rhs);
		Point3& operator+(const Point3& rhs);
		void operator-=(const Point3& rhs);
		Point3& operator-(const Point3& rhs);
		void operator*=(const double& rhs);
		Point3& operator*(const double& rhs);
		void operator/=(const double& rhs);
		Point3& operator/(const double& rhs);
		friend Point3 operator*(const double& lhs, const Point3& rhs) { return Point3(lhs * rhs.x(), lhs * rhs.y(), lhs * rhs.z()); }
		friend Point3 operator-(const Point3& point) { return Point3(-point.x(), -point.y(), -point.z()); }

		bool operator == (const Point3& rhs) const;
		bool operator != (const Point3& rhs) const { return operator ==(rhs); }


		// Utility functions

		inline void move(const double& dx, const double& dy, const double& dz) { operator+=(Point3(dx, dy, dz)); }
		inline void move(const Point3& point) { operator+=(point); }

		inline double distance(const Point3& rhs) const { return sqrt(pow(x() - rhs.x(), 2) + pow(y() - rhs.y(), 2) + pow(z() - rhs.z(), 2)); }
		friend inline double distance(const Point3& lhs, const Point3& rhs) { return lhs.distance(rhs); }

		virtual void perturb(const double& stdDev = 1.0);
	};
}



