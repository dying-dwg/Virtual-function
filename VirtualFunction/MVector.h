#pragma once
#include "cmath"
#include "Math.h"

class MVector : public Math
{
private:
	double arr[10];

public:
	MVector(double arr[10]);
	MVector(const MVector& other);
	~MVector();
	void Count_Norm() override;
};