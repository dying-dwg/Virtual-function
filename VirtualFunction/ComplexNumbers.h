#pragma once
#include "Math.h"

class ComplexNumbers : public Math
{
private:
	double a;
	double b;

public:
	ComplexNumbers(double a, double b);
	ComplexNumbers(const ComplexNumbers& other);
	~ComplexNumbers();
	void Count_Norm() override;
};