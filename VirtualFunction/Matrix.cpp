#include "Matrix.h"

Matrix::Matrix(double M[2][2])
{
	this->M[0][0] = M[0][0];
	this->M[0][1] = M[0][1];
	this->M[1][0] = M[1][0];
	this->M[1][1] = M[1][1];
}

Matrix::Matrix(const Matrix& other)
{
	M[0][0] = other.M[0][0];
	M[0][1] = other.M[0][1];
	M[1][0] = other.M[1][0];
	M[1][1] = other.M[1][1];
}

Matrix::~Matrix() {}

void Matrix::Count_Norm()
{
	Norm = abs(M[0][0]);
	Norm = Norm > abs(M[0][1]) ? Norm : abs(M[0][1]);
	Norm = Norm > abs(M[1][0]) ? Norm : abs(M[1][0]);
	Norm = Norm > abs(M[1][1]) ? Norm : abs(M[1][1]);
}
