#pragma once


class Math
{
protected:
	double Norm;
public:
	Math();
	Math(const Math& other);
	virtual ~Math();
	virtual void Count_Norm() = 0;
	double Get_Norm();
};