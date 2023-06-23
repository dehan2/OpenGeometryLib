#include "Vector3.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace OpenGeometry;


Vector3& Vector3::operator+(const Vector3& rhs)
{
	operator+=(rhs);
	return *this;
}



Vector3& Vector3::operator-(const Vector3& rhs)
{
	operator-=(rhs);
	return *this;
}



Vector3& Vector3::operator*(const double& rhs)
{
	operator*=(rhs);
	return *this;
}



Vector3& Vector3::operator/(const double& rhs)
{
	operator/=(rhs);
	return *this;
}



Vector3 Vector3::unit() const
{
	double mag = magnitude();
	return Vector3(m_x / mag, m_y / mag, m_z / mag);
}



void Vector3::normalize()
{
	double mag = magnitude();
	m_x /= mag;
	m_y /= mag;
	m_z /= mag;
}



double angle_between_vectors(const Vector3& vector1, const Vector3& vector2)
{
	Vector3 vec1 = vector1.unit();
	Vector3 vec2 = vector2.unit();
	double distanceBetween = distance(vec1, vec2);

	double cosine = 1.0 - pow(distanceBetween, 2) / 2.0; // Law of cosines is used.

	//  The input parameter of acos function should be in the interval [-1, +1].
	if (cosine < -1.0) { cosine = -1.0; }
	if (cosine > 1.0) {	cosine = 1.0; }

	return acos(cosine);
}



Vector3 cross(const Vector3& vector1, const Vector3& vector2)
{
	return Vector3((vector1.y() * vector2.z() - vector1.z() * vector2.y()),
		(vector1.z() * vector2.x() - vector1.x() * vector2.z()),
		(vector1.x() * vector2.y() - vector1.y() * vector2.x()));
}
