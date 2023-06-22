#include "Vector2.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <limits>
#include "Matrix.h"

using namespace OpenGeometry;

Vector2& Vector2::operator+(const Vector2& rhs)
{
	operator+=(rhs);
	return *this;
}



Vector2& Vector2::operator-(const Vector2& rhs)
{
	operator-=(rhs);
	return *this;
}



Vector2& Vector2::operator*(const double& rhs)
{
	operator*=(rhs);
	return *this;
}



Vector2& Vector2::operator/(const double& rhs)
{
	operator/=(rhs);
	return *this;
}



Vector2 Vector2::unit() const
{
	double mag = magnitude();
	return Vector2(m_x / mag, m_y / mag);
}



void Vector2::normalize()
{
	double mag = magnitude();
	m_x /= mag;
	m_y /= mag;
}



double angle_between_vectors(const Vector2& vector1, const Vector2& vector2)
{
	Vector2 vec1 = vector1.unit();
	Vector2 vec2 = vector2.unit();
	double distanceFrom1To2 = distance(vec1, vec2);

	double cosine = 1.0 - pow(distanceFrom1To2, 2) / 2.0; // Law of cosines is used.

	//  The input parameter of acos function should be in the interval [-1, +1].
	if (cosine < -1.0) {
		cosine = -1.0;
	}

	if (cosine > 1.0) {
		cosine = 1.0;
	}

	if (cross(vec1, vec2) >= 0.0)  //less than PI (cross product)
		return acos(cosine);
	else
		return 2. * M_PI - acos(cosine);
}



std::pair<double, double> span_point(const Vector2& vector, const Vector2& basis1, const Vector2& basis2)
{
	Matrix basisMat(2, 2);
	basisMat.set_element(0, 0, basis1.x());
	basisMat.set_element(0, 1, basis2.x());
	basisMat.set_element(1, 0, basis1.y());
	basisMat.set_element(1, 1, basis2.y());

	Matrix pointMat(2, 1);
	pointMat.set_element(0, 0, vector.x());
	pointMat.set_element(1, 0, vector.y());

	auto invMat = basisMat.inverse();
	if (invMat.row() == 2 && invMat.col() == 2)
	{
		auto spanMat = invMat * pointMat;
		return std::make_pair(spanMat(0, 0), spanMat(1, 0));
	}
	else
		return std::make_pair(std::numeric_limits<double>::max(), std::numeric_limits<double>::max());
}