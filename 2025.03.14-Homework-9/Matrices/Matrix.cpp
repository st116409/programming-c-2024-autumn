#include "Matrix.h"

double** Matrix::createData(int rows, int cols)
{
	double** res = new double* [rows] { nullptr };
	for (int i = 0; i < rows; ++i)
	{
		res[i] = new double[cols] { 0 };
	}
	return res;
}

void Matrix::freeData(double** data, int rows)
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] data[i];
	}
	delete[] data;
}

Matrix::Matrix(int dim = 1)
{
	this->rows = dim;
	this->cols = dim;
	this->data = createData(dim, dim);
}

Matrix::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	this->data = createData(rows, cols);
}

Matrix::Matrix(const Matrix& matr)
{
	this->rows = matr.rows;
	this->cols = matr.cols;
	this->data = createData(matr.rows, matr.cols);
	for (int i = 0; i < matr.rows; ++i)
	{
		for (int j = 0; j < matr.cols; ++j)
		{
			this->data[i][j] = matr.data[i][j];
		}
	}
}

Matrix::~Matrix() {
	if (this->data != nullptr)
	{
		freeData(this->data, this->rows);
		this->data = nullptr;
		this->rows = 0;
		this->cols = 0;
	}
}

void Matrix::set(int row, int col, double val)
{
	if (0 <= row && row <= this->rows &&
		0 <= col && col <= this->cols)
	{
		this->data[row][col] = val;
	}
}

int Matrix::getR()
{
	return this->rows;
}

int Matrix::getC()
{
	return this->cols;
}

void Matrix::print(std::ostream& stream)
{
	stream << "[" << this->rows << "; " << this->cols << "]\n";
	for (int i = 0; i < this->rows; ++i)
	{
		stream << "\t";
		for (int j = 0; j < this->cols; ++j)
		{
			stream << this->data[i][j] << " ";
		}
		stream << "\n";
	}
}


Matrix add(Matrix m1, Matrix m2) {
	if (m1.cols == m2.cols && m1.rows == m2.rows) {
		Matrix m3(m1.rows, m1.cols);
		for (int i = 0; i < m1.rows; ++i) {
			for (int j = 0; j < m1.cols; ++j) {
				m3.data[i][j] = m1.data[i][j] + m2.data[i][j];
			}
		}
		return m3;
	}
	return Matrix();
}

Matrix transpose(Matrix m) {
	Matrix mt(m.cols, m.rows);
	for (int i = 0; i < mt.rows; ++i) {
		for (int j = 0; j < mt.cols; ++j) {
			mt.data[i][j] = m.data[j][i];
		}
	}
	return mt;
}

Matrix subtr(Matrix m1, Matrix m2) {
	if (m1.cols == m2.cols && m1.rows == m2.rows) {
		Matrix m3(m1.rows, m1.cols);
		for (int i = 0; i < m1.rows; ++i) {
			for (int j = 0; j < m1.cols; ++j) {
				m3.data[i][j] = m1.data[i][j] - m2.data[i][j];
			}
		}
		return m3;
	}
	return Matrix();
}

Matrix mult(Matrix m1, Matrix m2) {
	if (m1.cols == m2.rows) {
		Matrix m3(m1.rows, m2.cols);
		for (int i = 0; i < m1.rows; ++i) {
			for (int j = 0; j < m2.cols; ++j) {
				for (int k = 0; k < m1.cols; ++k) {
					m3.data[i][j] += m1.data[i][k] * m2.data[k][j];
				}
				 
			}
		}
		return m3;
	}
	return Matrix();
}

double Matrix::det()
{
	if (this->rows > 0 && this->rows == this->cols)
	{
		int dim = this->rows;
		if (dim == 1)
		{
			return this->data[0][0];
		}
		double res = 0;
		for (int i = 0, mult = 1; i < dim; ++i, mult *= -1)
		{
			res += mult * this->data[0][i] * submatr(0, i).det();
		}
		return res;
	}
	return 0.0;
}

Matrix Matrix::submatr(int row, int col)
{
	if (this->rows > 1 &&
		this->rows == this->cols &&
		row < this->rows && col < this->cols)
	{
		int dim = this->rows - 1;
		Matrix res(dim);
		for (int i = 0, ii = 0; i < dim; ++i, ++ii)
		{
			if (ii == row)
			{
				++ii;
			}
			for (int j = 0, jj = 0; j < dim; ++j, ++jj)
			{
				if (jj == col)
				{
					++jj;
				}
				res.data[i][j] = this->data[ii][jj];
			}
		}
		return res;
	}
	return Matrix();
}

Matrix reverse(Matrix m) {
	if (m.cols == m.rows && m.det() != 0) {
		Matrix m2(m.cols);
		double k = m.det();
		for (int i = 0; i < m.rows; ++i) {
			for (int j = 0; j < m.rows; ++j) {
				Matrix im = m.submatr(i, j);
				m2.data[j][i] = im.det() * (1 - 2 * ((i + j) % 2)) / k;
			}
		}
		return m2;
	}
	else {
		std::cout << "Cannot be reversed\n";
		return Matrix();
	}
}

Matrix solve(Matrix a, Matrix b) {
	if (a.rows == b.rows) {
		return mult(reverse(a), b);
	}
	return Matrix();
}