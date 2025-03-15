#pragma once

#include <iostream>

class Matrix {
private:
	double** data;
	int rows;
	int cols;
	double** createData(int rows, int cols);
	void freeData(double** data, int rows);

public:
	Matrix(int dim);
	Matrix(int rows, int cols);
	Matrix(const Matrix& matr);
	~Matrix();
	void set(int row, int col, double val);
	int getR();
	int getC();
	void print(std::ostream& stream);
	Matrix submatr(int row, int col);
	double det();

	friend Matrix add(Matrix m1, Matrix m2);
	friend Matrix transpose(Matrix m);
	friend Matrix subtr(Matrix m1, Matrix m2);
	friend Matrix mult(Matrix m1, Matrix m2);
	friend Matrix reverse(Matrix m);
	friend Matrix solve(Matrix A, Matrix B);


};
