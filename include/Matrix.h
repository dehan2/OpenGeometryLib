#pragma once
#include <memory>

/// <summary>
/// Matrix class by Chacha at Jun. 22, 2023
/// Matrix elements are managed in dynamic array.
/// </summary>


namespace OpenGeometry
{
	class Matrix
	{
	protected:
		std::unique_ptr<double[]> m_elements = nullptr;
		int m_row = 0;
		int m_col = 0;

	public:
		// Constructor and destructor

		Matrix() = default;
		virtual ~Matrix() = default;
		Matrix(const int& row, const int& col) { construct(row, col); }
		Matrix(const Matrix& rhs) { copy(rhs); }

		virtual void copy(const Matrix& rhs);

		inline int row() const { return m_row; }
		inline int col() const { return m_col; }

		// Set functions for row and column is not allowed.
		// User should use construct function to change the size of matrix.
		/*inline void set_row(const int& row) { m_row = row; }
		inline void set_col(const int& col) { m_col = col; }*/

		inline void set_element(const int& row, const int& col, const double& value) { m_elements[row * m_col + col] = value; }

		// Operator overloading

		virtual Matrix& operator=(const Matrix& rhs);

		void operator+=(const Matrix& rhs);
		Matrix& operator+(const Matrix& rhs);
		void operator-=(const Matrix& rhs);
		Matrix& operator-(const Matrix& rhs);
		void operator*=(const double& rhs);
		Matrix& operator*(const double& rhs);
		void operator/=(const double& rhs);
		Matrix& operator/(const double& rhs);
		friend Matrix operator*(const double& lhs, const Matrix& rhs) { return Matrix(lhs * rhs.row(), lhs * rhs.col()); }
		friend Matrix operator-(const Matrix& matrix);

		Matrix operator*(const Matrix& rhs);
		
		bool operator == (const Matrix& rhs) const;
		bool operator != (const Matrix& rhs) const { return operator ==(rhs); }

		inline const double& operator()(const int& row, const int& col) const { return m_elements[row * m_col + col]; }

		// Utility functions
		void construct(const double& value = 0.0);
		void construct(const int& row, const int& col, const double& value = 0.0);

		double determinant() const; // Calculate the determinant.
		Matrix transpose() const; // Calculate the transpose matrix.
		Matrix inverse() const; // Calculate the inverse matrix. Return empty matrix represents the matrix is unable to be inversed.

		friend Matrix identity(const int& row); // Make current matrix as identity matrix.
	};
}