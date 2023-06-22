#include "Point3.h"
#include "ConstForOpenGeometryLib.h"
#include <random>

using namespace OpenGeometry;

void Point3::copy(const Point3& rhs)
{
	Point2::copy(rhs);
	m_z = rhs.z();
}



Point3& Point3::operator=(const Point3& rhs)
{
	if (this != &rhs)
		copy(rhs);

	return *this;
}




void Point3::operator+=(const Point3& rhs)
{
	Point2::operator+=(rhs);
	m_z += rhs.z();
}



Point3& Point3::operator+(const Point3& rhs)
{
	operator+=(rhs);
	return *this;
}




void Point3::operator-=(const Point3& rhs)
{
	Point2::operator-=(rhs);
	m_z -= rhs.z();
}



Point3& Point3::operator-(const Point3& rhs)
{
	operator-=(rhs);
	return *this;
}



void Point3::operator*=(const double& rhs)
{
	Point2::operator*=(rhs);
	m_z *= rhs;
}



Point3& Point3::operator*(const double& rhs)
{
	operator*=(rhs);
	return *this;
}



void Point3::operator/=(const double& rhs)
{
	Point2::operator/=(rhs);
	m_z /= rhs;
}



Point3& Point3::operator/(const double& rhs)
{
	operator/=(rhs);
	return *this;
}



Point3 operator*(const double& lhs, const Point3& rhs)
{
	Point3 result(rhs);
	result *= lhs;
	return result;
}



bool Point3::operator==(const Point3& rhs) const
{
	if (Point2::operator==(rhs)
		&& (abs(m_z - rhs.m_z) < BASIC_COMPUTATIONAL_TOLERANCE))
		return true;
	else
		return false;
}



void Point3::perturb(const double& stdDev)
{
	Point2::perturb(stdDev);
	
	std::random_device rd;
	std::default_random_engine gen(rd());

	std::normal_distribution<double> dis(0, stdDev);
	m_z += dis(gen);
}
