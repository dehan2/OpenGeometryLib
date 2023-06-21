#include "Vector2.h"

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
