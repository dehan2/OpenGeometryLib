#include "Point2.h"
#include "ConstForOpenGeometryLib.h"
#include <cmath>

using namespace OpenGeometry;


inline void Point2::copy(const double& x, const double& y)
{
	m_x = x;
	m_y = y;
}



Point2& Point2::operator=(const Point2& rhs)
{
	if (this != &rhs)
		copy(rhs.x(), rhs.y());

	return *this;
}



void Point2::operator+=(const Point2& rhs)
{
	m_x += rhs.x();
	m_y += rhs.y();
}



Point2& Point2::operator+(const Point2& rhs)
{
	operator+=(rhs);
	return *this;
}




void Point2::operator-=(const Point2& rhs)
{
	m_x -= rhs.x();
	m_y -= rhs.y();
}



Point2& Point2::operator-(const Point2& rhs)
{
	operator-=(rhs);
	return *this;
}



void Point2::operator*=(const double& rhs)
{
	m_x *= rhs;
	m_y *= rhs;
}



Point2& Point2::operator*(const double& rhs)
{
	operator*=(rhs);
	return *this;
}



void Point2::operator/=(const double& rhs)
{
	m_x /= rhs;
	m_y /= rhs;
}



Point2& Point2::operator/(const double& rhs)
{
	operator/=(rhs);
	return *this;
}



Point2 operator*(const double& lhs, const Point2& rhs)
{
	Point2 result(rhs);
	result *= lhs;
	return result;
}



bool Point2::operator==(const Point2& rhs) const
{
	if (abs(m_x - rhs.m_x) < BASIC_COMPUTATIONAL_TOLERANCE
		&& abs(m_y - rhs.m_y) < BASIC_COMPUTATIONAL_TOLERANCE)
		return true;
	else
		return false;
}
