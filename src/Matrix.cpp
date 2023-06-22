#include "Matrix.h"
#include <stdexcept>

using namespace OpenGeometry;

void Matrix::copy(const Matrix& rhs)
{
	m_row = rhs.m_row;
	m_col = rhs.m_col;
	m_elements = std::make_unique<double[]>(m_row * m_col);
	for (int i = 0; i < m_row * m_col; i++)
		m_elements[i] = rhs.m_elements[i];
}



Matrix& Matrix::operator=(const Matrix& rhs)
{
	if(this != &rhs)
		copy(rhs);
	
	return *this;
}




void Matrix::operator+=(const Matrix& rhs)
{
	if (m_row != rhs.m_row || m_col != rhs.m_col)
		throw std::invalid_argument("Matrix::operator+=: Matrix size mismatch.");

	for (int i = 0; i < m_row * m_col; i++)
		m_elements[i] += rhs.m_elements[i];
}



Matrix& Matrix::operator+(const Matrix& rhs)
{
	operator+=(rhs);
	return *this;
}



void Matrix::operator-=(const Matrix& rhs)
{
	if (m_row != rhs.m_row || m_col != rhs.m_col)
		throw std::invalid_argument("Matrix::operator-=: Matrix size mismatch.");

	for (int i = 0; i < m_row * m_col; i++)
		m_elements[i] -= rhs.m_elements[i];
}



Matrix& Matrix::operator-(const Matrix& rhs)
{
	operator-=(rhs);
	return *this;
}




void Matrix::operator*=(const double& rhs)
{
	for (int i = 0; i < m_row * m_col; i++)
		m_elements[i] *= rhs;
}



Matrix& Matrix::operator*(const double& rhs)
{
	operator*=(rhs);
	return *this;
}



void Matrix::operator/=(const double& rhs)
{
	for (int i = 0; i < m_row * m_col; i++)
		m_elements[i] /= rhs;
}



Matrix& Matrix::operator/(const double& rhs)
{
	operator/=(rhs);
	return *this;
}




bool Matrix::operator == (const Matrix& rhs) const
{
	if (m_row != rhs.m_row || m_col != rhs.m_col)
		return false;

	for (int i = 0; i < m_row * m_col; i++)
		if (m_elements[i] != rhs.m_elements[i])
			return false;

	return true;
}



void Matrix::construct(const double& value)
{
	if (m_row <= 0 || m_col <= 0)
		throw std::invalid_argument("Matrix::construct: Matrix size must be positive.");

	m_elements = std::make_unique<double[]>(m_row * m_col);
	for (int i = 0; i < m_row * m_col; i++)
		m_elements[i] = value;
}



void Matrix::construct(const int& row, const int& col, const double& value)
{
	m_row = row;
	m_col = col;
	construct(value);
}



Matrix operator-(const Matrix& matrix)
{
	Matrix result(matrix.row(), matrix.col());
	for(int i=0; i<matrix.row(); i++)
		for (int j = 0; j < matrix.col(); j++)
			result.set_element(i, j, -matrix(i, j));

	return result;
}



Matrix Matrix::operator*(const Matrix& rhs)
{
	if (m_col != rhs.m_row)
		throw std::invalid_argument("Matrix::operator*: Matrix size mismatch.");

	Matrix result(m_row, rhs.m_col);
	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < rhs.m_col; j++)
			for (int k = 0; k < m_col; k++)
				result.set_element(i, j, result(i, j) + m_elements[i * m_col + k] * rhs(k, j));

	return result;
}



double Matrix::determinant() const
{
	if (m_row != m_col)
		throw std::invalid_argument("Matrix::determinant: Matrix must be square.");

	if (m_row == 1)
		return m_elements[0];

	double result = 0;
	for (int i = 0; i < m_col; i++)
	{
		Matrix sub_matrix(m_row - 1, m_col - 1);
		for (int j = 1; j < m_row; j++)
			for (int k = 0; k < m_col; k++)
				if (k < i)
					sub_matrix.set_element(j - 1, k, m_elements[j * m_col + k]);
				else if (k > i)
					sub_matrix.set_element(j - 1, k - 1, m_elements[j * m_col + k]);

		result += m_elements[i] * sub_matrix.determinant() * ((i % 2 == 0) ? 1 : -1);
	}

	return result;
}



Matrix Matrix::transpose() const
{
	Matrix result(m_col, m_row);
	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_col; j++)
			result.set_element(j, i, m_elements[i * m_col + j]);

	return result;
}



Matrix Matrix::inverse() const
{
	if (m_row != m_col)
		throw std::invalid_argument("Matrix::inverse: Matrix must be square.");

	double det = determinant();
	if (det == 0)
		throw std::invalid_argument("Matrix::inverse: Matrix is singular.");

	Matrix result(m_row, m_col);
	for (int i = 0; i < m_row; i++)
		for (int j = 0; j < m_col; j++)
		{
			Matrix sub_matrix(m_row - 1, m_col - 1);
			for (int k = 0; k < m_row; k++)
				for (int l = 0; l < m_col; l++)
					if (k < i && l < j)
						sub_matrix.set_element(k, l, m_elements[k * m_col + l]);
					else if (k < i && l > j)
						sub_matrix.set_element(k, l - 1, m_elements[k * m_col + l]);
					else if (k > i && l < j)
						sub_matrix.set_element(k - 1, l, m_elements[k * m_col + l]);
					else if (k > i && l > j)
						sub_matrix.set_element(k - 1, l - 1, m_elements[k * m_col + l]);

			result.set_element(i, j, sub_matrix.determinant() * ((i + j) % 2 == 0 ? 1 : -1) / det);
		}

	return result.transpose();
}



Matrix identity(const int& row)
{
	Matrix result(row, row);
	for (int i = 0; i < row; i++)
		result.set_element(i, i, 1);

	return result;
}