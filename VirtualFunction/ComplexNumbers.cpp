#include "ComplexNumbers.h"

ComplexNumbers::ComplexNumbers(double a, double b) : a(a), b(b) {}

ComplexNumbers::ComplexNumbers(const ComplexNumbers& other) : a(other.a), b(other.b) {}

ComplexNumbers::~ComplexNumbers() {}

void ComplexNumbers::Count_Norm()
{
	Norm = a * a + b * b; // |z|^2 = sqrt(a^2 + b^2)^2 = a^2 + b^2
}