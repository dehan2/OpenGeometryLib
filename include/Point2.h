#pragma once

//////////////////////////////
// Point2 Class by Chacha at Jun. 21, 2023
// This class is for 2D point.
//////////////////////////////


namespace OpenGeometry
{
	class Point2
	{
	private:
		double m_x = 0.0f;
		double m_y = 0.0f;

	public:
		// Constructor and destructor

		Point2() = default;
		virtual ~Point2() = default;
		Point2(const double& x, const double& y) { copy(x, y); }
		Point2(const Point2& rhs) { copy(rhs.x(), rhs.y()); }
		
		virtual void copy(const double& x, const double& y);

		inline double x() const { return m_x; }
		inline double y() const { return m_y; }

		inline void set_x(const double& x) { m_x = x; }
		inline void set_y(const double& y) { m_y = y; }

		// Operator overloading

		virtual Point2& operator=(const Point2& rhs);

		void operator+=(const Point2& rhs);
		Point2& operator+(const Point2& rhs);
		void operator-=(const Point2& rhs);
		Point2& operator-(const Point2& rhs);
		void operator*=(const double& rhs);
		Point2& operator*(const double& rhs);
		void operator/=(const double& rhs);
		Point2& operator/(const double& rhs);
		friend Point2 operator*(const double& lhs, const Point2& rhs) { return Point2(lhs * rhs.x(), lhs * rhs.y()); }
		friend Point2 operator-(const Point2& point) { return Point2(-point.x(), -point.y()); }

		bool operator == (const Point2& rhs) const;
		bool operator != (const Point2& rhs) const { return operator ==(rhs); }


		// Utility functions

		inline void move(const double& dx, const double& dy) { operator+=(Point2(dx, dy)); }
		inline void move(const Point2& point) { operator+=(point); }
	};
}