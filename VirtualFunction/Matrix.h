#pragma once
#include "cmath"
#include "Math.h"

class Matrix : public Math
{
private:
	double M[2][2];

public:
	Matrix(double M[2][2]);
	Matrix(const Matrix& other);
	~Matrix();
	void Count_Norm() override;
};