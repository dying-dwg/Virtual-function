#include "MVector.h"

MVector::MVector(double arr[10])
{
	for (int i = 0; i < 10; i++)
		this->arr[i] = arr[i];
}

MVector::MVector(const MVector& other)
{
	for (int i = 0; i < 10; i++)
		this->arr[i] = other.arr[i];
}

MVector::~MVector() {}

void MVector::Count_Norm()
{
	for (int i = 0; i < 10; i++)
		Norm += abs(arr[i]);
	Norm = sqrt(Norm);
}
