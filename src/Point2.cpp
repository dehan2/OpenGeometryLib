#include "Point2.h"
#include "ConstForOpenGeometryLib.h"
#include <random>


using namespace OpenGeometry;


void Point2::copy(const Point2& rhs)
{
	m_x = rhs.x();
	m_y = rhs.y();
}



Point2& Point2::operator=(const Point2& rhs)
{
	if (this != &rhs)
		copy(rhs);

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



void Point2::perturb(const double& stdDev)
{
	std::random_device rd;
	std::default_random_engine gen(rd());

	std::normal_distribution<double> dis(0, stdDev);
	m_x += dis(gen);
	m_y += dis(gen);
}
